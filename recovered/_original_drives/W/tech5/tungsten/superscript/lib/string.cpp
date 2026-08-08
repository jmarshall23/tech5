
// ========================================================================
// ?Cmp@ssString@@QBAHPBD@Z
// EA  : 0x82EE7058
// RVA : 0x00EE7058
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

int __fastcall ssString::Cmp(ssString *this, const char *text)
{
  int result; // r3
  char *data; // r8
  int v4; // r11
  int v5; // r10
  int v6; // r9

  if ( text == nullptr )
    return 1;
  data = this->data;
  v4 = -1;
  while ( 1 )
  {
    v5 = data[++v4];
    v6 = text[v4];
    result = v5 - v6;
    if ( v5 != v6 )
      break;
    if ( data[v4] == 0 || text[v4] == 0 )
      return 0;
  }
  return result;
}


// ========================================================================
// ?Icmp@ssString@@SAHPBD0@Z
// EA  : 0x82EE70A8
// RVA : 0x00EE70A8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

int __fastcall ssString::Icmp(const char *text, const char *text2)
{
  const char *v2; // r9
  int v3; // r8
  int v4; // r11
  int v5; // r10
  int result; // r3

  if ( text == nullptr )
    return 0;
  v2 = text - 1;
  v3 = text2 - text;
  while ( 1 )
  {
    ++v2;
    v4 = v2[v3];
    v5 = *v2;
    if ( v4 >= 97 && v4 <= 122 )
      v4 -= 32;
    if ( v5 >= 97 && v5 <= 122 )
      v5 -= 32;
    result = v4 - v5;
    if ( v4 != v5 )
      break;
    if ( v4 == 0 || v5 == 0 )
      return 0;
  }
  return result;
}


// ========================================================================
// ?Find@ssString@@QBAHDH@Z
// EA  : 0x82EE7118
// RVA : 0x00EE7118
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

int __fastcall ssString::Find(ssString *this, const char a, unsigned int i)
{
  signed int v3; // r11

  v3 = ((i >> 31) - 1) & i;
  if ( v3 >= this->len )
    return -1;
  while ( this->data[v3] != a )
  {
    if ( ++v3 >= this->len )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?ToLower@ssString@@QAAXXZ
// EA  : 0x82EE7168
// RVA : 0x00EE7168
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::ToLower(ssString *this)
{
  int i; // r11
  char v2; // r9

  for ( i = 0; i < this->len; ++i )
  {
    v2 = this->data[i];
    if ( v2 >= 65 && v2 <= 90 )
      this->data[i] += 32;
  }
}


// ========================================================================
// ?ToUpper@ssString@@QAAXXZ
// EA  : 0x82EE71B8
// RVA : 0x00EE71B8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::ToUpper(ssString *this)
{
  int i; // r11
  char v2; // r9

  for ( i = 0; i < this->len; ++i )
  {
    v2 = this->data[i];
    if ( v2 >= 97 && v2 <= 122 )
      this->data[i] -= 32;
  }
}


// ========================================================================
// ?Empty@ssString@@QAAXXZ
// EA  : 0x82EE7208
// RVA : 0x00EE7208
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Empty(ssString *this)
{
  char *data; // r4

  data = this->data;
  if ( data != nullptr )
    gameInterface->Free(this: gameInterface, a2: data, a3: this->threadId);
  this->data = nullptr;
  this->alloced = 0;
  this->len = 0;
}


// ========================================================================
// ?Reverse@ssString@@QAAXXZ
// EA  : 0x82EE7268
// RVA : 0x00EE7268
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Reverse(ssString *this)
{
  int len; // r10
  int i; // r11
  char *data; // r9
  int v4; // r10
  char v5; // r8

  len = this->len;
  for ( i = 0; i < this->len / 2; len = this->len )
  {
    data = this->data;
    v4 = len - i - 1;
    v5 = data[i];
    data[i++] = data[v4];
    this->data[v4] = v5;
  }
}


// ========================================================================
// ?Init@ssString@@AAAXXZ
// EA  : 0x82EE72B8
// RVA : 0x00EE72B8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Init(ssString *this)
{
  this->len = 0;
  this->alloced = 0;
  this->data = nullptr;
  if ( gameInterface != nullptr )
    this->threadId = gameInterface->GetAllocThread(this: gameInterface);
  else
    this->threadId = 0;
}


// ========================================================================
// ?Allocate@ssString@@AAAXH@Z
// EA  : 0x82EE7330
// RVA : 0x00EE7330
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Allocate(ssString *this, int n)
{
  char *data; // r4
  int threadId; // r5

  data = this->data;
  if ( data != nullptr )
    gameInterface->Free(this: gameInterface, a2: data, a3: this->threadId);
  this->alloced = n;
  threadId = this->threadId;
  this->data = nullptr;
  this->len = 0;
  this->data = (char *)gameInterface->Allocate(this: gameInterface, a2: n, a3: threadId);
}


// ========================================================================
// ??4ssString@@QAAXABV0@@Z
// EA  : 0x82EE73A8
// RVA : 0x00EE73A8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::operator=(ssString *this, const ssString *text)
{
  int len; // r10
  int i; // r11
  char *data; // r11

  ssString::Allocate(this, n: text->len + 1);
  len = text->len;
  for ( i = 0; i < text->len; len = text->len )
  {
    this->data[i] = text->data[i];
    ++i;
  }
  data = this->data;
  this->len = len;
  data[len] = 0;
}


// ========================================================================
// ??4ssString@@QAAXPBD@Z
// EA  : 0x82EE7428
// RVA : 0x00EE7428
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::operator=(ssString *this, char *text)
{
  int v4; // r11
  char *data; // r4
  int v6; // r29
  char v7; // r10
  int i; // r11

  this->len = 0;
  v4 = 0;
  if ( *text != 0 )
  {
    do
    {
      if ( this->len < this->alloced )
        this->data[v4] = text[v4];
      ++v4;
      ++this->len;
    }
    while ( text[v4] != 0 );
  }
  if ( this->len >= this->alloced )
  {
    data = this->data;
    v6 = this->len + 1;
    if ( data != nullptr )
      gameInterface->Free(this: gameInterface, a2: data, a3: this->threadId);
    this->data = nullptr;
    this->alloced = v6;
    this->len = 0;
    this->data = (char *)gameInterface->Allocate(this: gameInterface, a2: v6, a3: this->threadId);
    v7 = *text;
    for ( i = 0; v7 != 0; v7 = text[i] )
    {
      this->data[i++] = v7;
      ++this->len;
    }
  }
  this->data[this->len] = 0;
}


// ========================================================================
// ??4ssString@@QAAXD@Z
// EA  : 0x82EE7540
// RVA : 0x00EE7540
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::operator=(ssString *this, char c)
{
  char *data; // r9

  ssString::Allocate(this, n: 2);
  data = this->data;
  this->len = 1;
  *data = c;
  this->data[1] = 0;
}


// ========================================================================
// ??AssString@@QAAAADH@Z
// EA  : 0x82EE7598
// RVA : 0x00EE7598
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

char *__fastcall ssString::operator[](ssString *this, int index)
{
  if ( index < 0 || index >= this->len )
    AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < len )");
  return &this->data[index];
}


// ========================================================================
// ?Right@ssString@@QBA?AV1@H@Z
// EA  : 0x82EE75F8
// RVA : 0x00EE75F8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::Right(ssString *this, ssString *result, int num)
{
  char *v4; // r4
  char *data; // r30

  if ( num >= 0 )
  {
    if ( result->len >= num )
      data = &result->data[result->len - num];
    else
      data = result->data;
    ssString::Init(this);
    v4 = data;
  }
  else
  {
    ssString::Init(this);
    v4 = &byte_8200D768;
  }
  ssString::operator=(this, text: v4);
  return this;
}


// ========================================================================
// ?Skip@ssString@@QBA?AV1@H@Z
// EA  : 0x82EE7678
// RVA : 0x00EE7678
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::Skip(ssString *this, ssString *result, int num)
{
  char *v4; // r4
  char *data; // r30

  if ( num >= 0 )
  {
    if ( result->len >= num )
      data = &result->data[num];
    else
      data = result->data;
    ssString::Init(this);
    v4 = data;
  }
  else
  {
    ssString::Init(this);
    v4 = &byte_8200D768;
  }
  ssString::operator=(this, text: v4);
  return this;
}


// ========================================================================
// ?Find@ssString@@QBAHABV1@H@Z
// EA  : 0x82EE76F0
// RVA : 0x00EE76F0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

int __fastcall ssString::Find(ssString *this, const ssString *a, unsigned int i)
{
  int v4; // r27
  signed int j; // r29
  int len; // r11
  int v8; // r31

  v4 = this->len - a->len;
  for ( j = ((i >> 31) - 1) & i; j <= v4; ++j )
  {
    len = a->len;
    v8 = 0;
    while ( v8 < a->len )
    {
      if ( v8 < 0 || v8 >= len )
        AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < len )");
      if ( this->data[v8 + j] != a->data[v8] )
        break;
      len = a->len;
      if ( ++v8 == a->len )
        return j;
    }
  }
  return -1;
}


// ========================================================================
// ?EnsureAllocated@ssString@@AAAXH@Z
// EA  : 0x82EE77B0
// RVA : 0x00EE77B0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::EnsureAllocated(ssString *this, int n)
{
  int v4; // r3
  char *v5; // r29
  int i; // r11
  ssString v7[4]; // [sp+50h] [-40h] BYREF

  if ( this->alloced < n )
  {
    v4 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->Allocate)(a1: gameInterface);
    v5 = (char *)v4;
    if ( v4 != 0 )
    {
      if ( this->data != nullptr )
      {
        for ( i = 0; i < this->len + 1; ++i )
          *(_BYTE *)(i + v4) = this->data[i];
        gameInterface->Free(this: gameInterface, a2: this->data, a3: this->threadId);
      }
      this->data = v5;
      this->alloced = n;
    }
    else
    {
      ssString::Init(this: v7);
      ssString::operator=(this: v7, text: "ssString Allocation failed");
      Error(msg: v7);
      ssString::~ssString(this: v7);
    }
  }
}


// ========================================================================
// __unwind$18695
// EA  : 0x82EE7890
// RVA : 0x00EE7890
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18695()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 80));
}


// ========================================================================
// ?Left@ssString@@QBA?AV1@H@Z
// EA  : 0x82EE78C0
// RVA : 0x00EE78C0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::Left(ssString *this, ssString *result, int num)
{
  char *v7; // r30
  int v8; // r11
  char *data; // r27
  int i; // ctr
  int v11; // r3
  ssString v12[5]; // [sp+60h] [-50h] BYREF

  if ( num >= 0 )
  {
    if ( result->len >= num )
    {
      ssString::Init(this: v12);
      ssString::EnsureAllocated(this: v12, n: num + 1);
      v8 = 0;
      data = v12[0].data;
      if ( num > 0 )
      {
        for ( i = num; i != 0; --i )
        {
          data[v8] = result->data[v8];
          ++v8;
        }
      }
      data[v8] = 0;
      this->len = 0;
      this->alloced = 0;
      this->data = nullptr;
      v12[0].len = num;
      if ( gameInterface != nullptr )
        v11 = gameInterface->GetAllocThread(this: gameInterface);
      else
        v11 = 0;
      this->threadId = v11;
      ssString::operator=(this, text: v12);
      if ( data != nullptr )
        gameInterface->Free(this: gameInterface, a2: data, a3: v12[0].threadId);
      return this;
    }
    else
    {
      v7 = result->data;
      ssString::Init(this);
      ssString::operator=(this, text: v7);
      return this;
    }
  }
  else
  {
    ssString::Init(this);
    ssString::operator=(this, text: &byte_8200D768);
    return this;
  }
}


// ========================================================================
// __unwind$18718
// EA  : 0x82EE79F8
// RVA : 0x00EE79F8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18718()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$18721
// EA  : 0x82EE7A3C
// RVA : 0x00EE7A3C
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18721()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Mid@ssString@@QBA?AV1@HH@Z
// EA  : 0x82EE7A70
// RVA : 0x00EE7A70
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::Mid(ssString *this, ssString *result, unsigned int start, int num)
{
  int v5; // r28
  int len; // r11
  int v9; // r30
  int v10; // r11
  char *data; // r29
  int i; // ctr
  int v13; // r3
  ssString v14[5]; // [sp+60h] [-50h] BYREF

  v5 = num;
  if ( num >= 0 )
  {
    len = result->len;
    v9 = ((start >> 31) - 1) & start;
    if ( v9 > result->len )
      v9 = result->len;
    if ( v9 + num > len )
      v5 = len - v9;
    ssString::Init(this: v14);
    ssString::EnsureAllocated(this: v14, n: v5 + 1);
    v10 = 0;
    data = v14[0].data;
    if ( v5 > 0 )
    {
      for ( i = v5; i != 0; --i )
      {
        data[v10] = result->data[v10 + v9];
        ++v10;
      }
    }
    data[v10] = 0;
    this->len = 0;
    this->alloced = 0;
    this->data = nullptr;
    v14[0].len = v5;
    if ( gameInterface != nullptr )
      v13 = gameInterface->GetAllocThread(this: gameInterface);
    else
      v13 = 0;
    this->threadId = v13;
    ssString::operator=(this, text: v14);
    if ( data != nullptr )
      gameInterface->Free(this: gameInterface, a2: data, a3: v14[0].threadId);
    return this;
  }
  else
  {
    ssString::Init(this);
    ssString::operator=(this, text: &byte_8200D768);
    return this;
  }
}


// ========================================================================
// __unwind$18781
// EA  : 0x82EE7BAC
// RVA : 0x00EE7BAC
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18781()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$18784
// EA  : 0x82EE7BF0
// RVA : 0x00EE7BF0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18784()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Append@ssString@@QAAXD@Z
// EA  : 0x82EE7C18
// RVA : 0x00EE7C18
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Append(ssString *this, char a)
{
  char *data; // r7
  int v5; // r11

  if ( a != 0 )
  {
    ssString::EnsureAllocated(this, n: this->len + 2);
    this->data[this->len] = a;
    data = this->data;
    v5 = this->len + 1;
    this->len = v5;
    data[v5] = 0;
  }
}


// ========================================================================
// ?Append@ssString@@QAAXABV1@@Z
// EA  : 0x82EE7C88
// RVA : 0x00EE7C88
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Append(ssString *this, const ssString *a)
{
  int len; // r10
  int i; // r11
  int v6; // r7
  char v7; // r6
  char *data; // r8
  int v9; // r11

  if ( a->len != 0 )
  {
    ssString::EnsureAllocated(this, n: a->len + this->len + 1);
    len = a->len;
    for ( i = 0; i < a->len; len = a->len )
    {
      v6 = this->len + i;
      v7 = a->data[i++];
      this->data[v6] = v7;
    }
    data = this->data;
    v9 = len + this->len;
    this->len = v9;
    data[v9] = 0;
  }
}


// ========================================================================
// ?Append@ssString@@QAAXPBD@Z
// EA  : 0x82EE7D30
// RVA : 0x00EE7D30
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::Append(ssString *this, const char *a)
{
  int v4; // r26
  const char *v5; // r11
  int v6; // r11
  int v7; // r28
  char *v8; // r3
  char *v9; // r29
  int i; // r11
  int v11; // r11
  int j; // ctr
  char *data; // r9
  int v14; // r11
  ssString v15[5]; // [sp+50h] [-50h] BYREF

  if ( a != nullptr )
  {
    v4 = 0;
    if ( *a != 0 )
    {
      v5 = a;
      do
      {
        ++v5;
        ++v4;
      }
      while ( *v5 != 0 );
    }
    v6 = this->len + v4;
    v7 = v6 + 1;
    if ( this->alloced < v6 + 1 )
    {
      v8 = (char *)gameInterface->Allocate(this: gameInterface, a2: v6 + 1, a3: this->threadId);
      v9 = v8;
      if ( v8 != nullptr )
      {
        if ( this->data != nullptr )
        {
          for ( i = 0; i < this->len + 1; ++i )
            v8[i] = this->data[i];
          gameInterface->Free(this: gameInterface, a2: this->data, a3: this->threadId);
        }
        this->data = v9;
        this->alloced = v7;
      }
      else
      {
        ssString::Init(this: v15);
        ssString::operator=(this: v15, text: "ssString Allocation failed");
        Error(msg: v15);
        if ( v15[0].data != nullptr )
          gameInterface->Free(this: gameInterface, a2: v15[0].data, a3: v15[0].threadId);
      }
    }
    v11 = 0;
    if ( v4 > 0 )
    {
      for ( j = v4; j != 0; --j )
      {
        this->data[this->len + v11] = a[v11];
        ++v11;
      }
    }
    data = this->data;
    v14 = this->len + v4;
    this->len = v14;
    data[v14] = 0;
  }
}


// ========================================================================
// __unwind$18859
// EA  : 0x82EE7EAC
// RVA : 0x00EE7EAC
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18859()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// ??0ssString@@QAA@H@Z
// EA  : 0x82EE7ED8
// RVA : 0x00EE7ED8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void __fastcall ssString::ssString(ssString *this, int i)
{
  bool v4; // cr57
  char v5; // r25
  char *data; // r9
  int v7; // r11

  ssString::Init(this);
  if ( i != 0 )
  {
    v4 = i > 0;
    v5 = 0;
    if ( i < 0 )
    {
      i = -i;
      v5 = 1;
      v4 = i > 0;
    }
    if ( v4 )
    {
      do
      {
        if ( (unsigned __int8)(i % 10) != 0xD0 )
        {
          ssString::EnsureAllocated(this, n: this->len + 2);
          this->data[this->len] = i % 10 + 48;
          data = this->data;
          v7 = this->len + 1;
          this->len = v7;
          data[v7] = 0;
        }
        i /= 10;
      }
      while ( i > 0 );
    }
    if ( v5 != 0 )
      ssString::Append(this, a: 45);
    ssString::Reverse(this);
  }
  else
  {
    ssString::Append(this, a: 48);
  }
}


// ========================================================================
// ??0ssString@@QAA@MH@Z
// EA  : 0x82EE7FD8
// RVA : 0x00EE7FD8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::ssString(ssString *this, double f, int precision, int a4)
{
  int v7; // r29
  const ssString *v8; // r3
  __int64 v9; // r11
  double v10; // fp31
  int i; // r26
  int v12; // r11
  char v13; // r29
  char *data; // r9
  int v15; // r11
  ssString v17; // [sp+60h] [-70h] BYREF

  v7 = (int)f;
  ssString::Init(this);
  if ( f < 0.0 )
    ssString::Append(this, a: 45);
  ssString::ssString(this: &v17, i: abs32(v7));
  ssString::Append(this, a: v8);
  if ( v17.data != nullptr )
    gameInterface->Free(this: gameInterface, a2: v17.data, a3: v17.threadId);
  LODWORD(v9) = v7;
  memset(&v17, 0, 12);
  v10 = (float)((float)f - (float)v9);
  if ( v10 < 0.0 )
    v10 = (float)((float)v10 * (float)-1.0);
  if ( v10 > 0.0 )
    ssString::Append(this, a: 46);
  for ( i = 0; i < a4; ++i )
  {
    v10 = (float)((float)v10 * (float)10.0);
    if ( v10 <= 0.0 )
      break;
    v12 = (int)v10 % 10;
    v13 = v12 + 48;
    if ( (_BYTE)v12 != 0xD0 )
    {
      ssString::EnsureAllocated(this, n: this->len + 2);
      this->data[this->len] = v13;
      data = this->data;
      v15 = this->len + 1;
      this->len = v15;
      data[v15] = 0;
    }
  }
  return this;
}


// ========================================================================
// __unwind$18947
// EA  : 0x82EE817C
// RVA : 0x00EE817C
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18947()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 96));
}


// ========================================================================
// ??H@YA?AVssString@@ABV0@0@Z
// EA  : 0x82EE81B0
// RVA : 0x00EE81B0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall operator+(ssString *result, const ssString *a, const ssString *b)
{
  ssString::Init(this: result);
  ssString::operator=(this: result, text: a);
  ssString::Append(this: result, a: b);
  return result;
}


// ========================================================================
// __unwind$18991
// EA  : 0x82EE8208
// RVA : 0x00EE8208
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_18991()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 148));
  }
}


// ========================================================================
// ??H@YA?AVssString@@ABV0@PBD@Z
// EA  : 0x82EE8258
// RVA : 0x00EE8258
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall operator+(ssString *result, const ssString *a, const char *b)
{
  ssString::Init(this: result);
  ssString::operator=(this: result, text: a);
  ssString::Append(this: result, a: b);
  return result;
}


// ========================================================================
// __unwind$19014
// EA  : 0x82EE82B0
// RVA : 0x00EE82B0
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_19014()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 148));
  }
}


// ========================================================================
// ??H@YA?AVssString@@PBDABV0@@Z
// EA  : 0x82EE8300
// RVA : 0x00EE8300
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall operator+(ssString *result, char *a, const ssString *b)
{
  ssString::Init(this: result);
  ssString::operator=(this: result, text: a);
  ssString::Append(this: result, a: b);
  return result;
}


// ========================================================================
// __unwind$19035
// EA  : 0x82EE8358
// RVA : 0x00EE8358
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_19035()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 148));
  }
}


// ========================================================================
// ??0ssString@@QAA@ABVssVector@@PBD@Z
// EA  : 0x82EE83A8
// RVA : 0x00EE83A8
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

ssString *__fastcall ssString::ssString(ssString *this, const ssVector *v, const char *format)
{
  int v6; // r4
  ssString *v7; // r3
  ssString *v8; // r3
  ssString *v9; // r3
  ssString v11; // [sp+50h] [-70h] BYREF
  ssString v12; // [sp+60h] [-60h] BYREF
  ssString v13; // [sp+70h] [-50h] BYREF

  ssString::Init(this);
  for ( ; *format != 0; ++format )
  {
    v6 = *(unsigned __int8 *)format;
    switch ( v6 )
    {
      case 'x':
        v9 = ssString::ssString(this: &v13, f: v->x, precision: 120, a4: 3);
        ssString::Append(this, a: v9);
        if ( v13.data != nullptr )
          gameInterface->Free(this: gameInterface, a2: v13.data, a3: v13.threadId);
        memset(&v13, 0, 12);
        break;
      case 'y':
        v8 = ssString::ssString(this: &v12, f: v->y, precision: 121, a4: 3);
        ssString::Append(this, a: v8);
        if ( v12.data != nullptr )
          gameInterface->Free(this: gameInterface, a2: v12.data, a3: v12.threadId);
        memset(&v12, 0, 12);
        break;
      case 'z':
        v7 = ssString::ssString(this: &v11, f: v->z, precision: 122, a4: 3);
        ssString::Append(this, a: v7);
        if ( v11.data != nullptr )
          gameInterface->Free(this: gameInterface, a2: v11.data, a3: v11.threadId);
        memset(&v11, 0, 12);
        break;
      default:
        ssString::Append(this, a: v6);
        break;
    }
  }
  return this;
}


// ========================================================================
// __unwind$19061
// EA  : 0x82EE850C
// RVA : 0x00EE850C
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_19061()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$19060
// EA  : 0x82EE8534
// RVA : 0x00EE8534
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_19060()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$19059
// EA  : 0x82EE855C
// RVA : 0x00EE855C
// PDB : w:\tech5\tungsten\superscript\lib\string.cpp
// ========================================================================

void _unwind_19059()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}

