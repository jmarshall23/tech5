
// ========================================================================
// ?Clear@?$ssList@VssEntity@@@@QAAXXZ
// EA  : 0x82EE1A68
// RVA : 0x00EE1A68
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<ssEntity>::Clear(ssList<float> *this)
{
  int size; // r10
  int i; // r11

  if ( this->data != nullptr )
  {
    size = this->size;
    for ( i = 0; i < size; ++i )
      ;
    ((void (__fastcall *)(idGameSuperInterface *))gameInterface->Free)(a1: gameInterface);
    this->data = nullptr;
  }
  this->num = 0;
  this->size = 0;
}


// ========================================================================
// ??1?$ssList@UlineInfo_t@util_debugMetaData@@@@QAA@XZ
// EA  : 0x82EE37A8
// RVA : 0x00EE37A8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

// attributes: thunk
void __fastcall ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(ssList<int> *this)
{
  ssList<ssEntity>::Clear((ssList<float> *)this);
}


// ========================================================================
// ?Clear@?$ssList@VssString@@@@QAAXXZ
// EA  : 0x82EE37B0
// RVA : 0x00EE37B0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<ssString>::Clear(ssList<ssString> *this)
{
  int v2; // r29
  int v3; // r30

  if ( this->data != nullptr )
  {
    v2 = 0;
    if ( this->size > 0 )
    {
      v3 = 0;
      do
      {
        ssString::Empty(this: &this->data[v3]);
        ++v2;
        ++v3;
      }
      while ( v2 < this->size );
    }
    gameInterface->Free(this: gameInterface, a2: this->data, a3: this->threadId);
    this->data = nullptr;
  }
  this->num = 0;
  this->size = 0;
}


// ========================================================================
// ??1?$ssList@VssString@@@@QAA@XZ
// EA  : 0x82EE4858
// RVA : 0x00EE4858
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

// attributes: thunk
void __fastcall ssList<ssString>::~ssList<ssString>(ssList<ssString> *this)
{
  ssList<ssString>::Clear(this);
}


// ========================================================================
// ?Clear@?$ssList@UcallFunction_t@util_entityFlag@@@@QAAXXZ
// EA  : 0x82EE4860
// RVA : 0x00EE4860
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<util_entityFlag::callFunction_t>::Clear(ssList<util_entityFlag::callFunction_t> *this)
{
  int v2; // r29
  int v3; // r30

  if ( this->data != nullptr )
  {
    v2 = 0;
    if ( this->size > 0 )
    {
      v3 = 0;
      do
      {
        ssString::Empty(this: &this->data[v3].function);
        ++v2;
        ++v3;
      }
      while ( v2 < this->size );
    }
    gameInterface->Free(this: gameInterface, a2: this->data, a3: this->threadId);
    this->data = nullptr;
  }
  this->num = 0;
  this->size = 0;
}


// ========================================================================
// ?Clear@?$ssList@UflagDef_t@util_entityFlag@@@@QAAXXZ
// EA  : 0x82EE5850
// RVA : 0x00EE5850
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<util_entityFlag::flagDef_t>::Clear(ssList<util_entityFlag::flagDef_t> *this)
{
  int v2; // r29
  int v3; // r30

  if ( this->data != nullptr )
  {
    v2 = 0;
    if ( this->size > 0 )
    {
      v3 = 0;
      do
      {
        util_entityFlag::flagDef_t::~flagDef_t(this: &this->data[v3]);
        ++v2;
        ++v3;
      }
      while ( v2 < this->size );
    }
    gameInterface->Free(this: gameInterface, a2: this->data, a3: this->threadId);
    this->data = nullptr;
  }
  this->num = 0;
  this->size = 0;
}


// ========================================================================
// ?Reverse@?$ssList@H@@QAAXXZ
// EA  : 0x82EE96B0
// RVA : 0x00EE96B0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<int>::Reverse(ssList<int> *this)
{
  int num; // r10
  int v2; // r9
  int v3; // r11
  int v4; // r8
  int v5; // r6

  num = this->num;
  v2 = 0;
  if ( num / 2 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = num - v2++ - 1;
      v5 = this->data[v4];
      this->data[v3++] = v5;
      this->data[v4] = v5;
      num = this->num;
    }
    while ( v2 < num / 2 );
  }
}


// ========================================================================
// ?Remove@?$ssList@H@@QAAXH@Z
// EA  : 0x82EE9710
// RVA : 0x00EE9710
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<int>::Remove(ssList<int> *this, int index)
{
  int num; // r11
  int v5; // r10
  int v6; // r11
  int *v7; // r9

  if ( index < 0 || index >= this->num )
    AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
  if ( index >= 0 )
  {
    num = this->num;
    if ( index < num )
    {
      v5 = index;
      if ( index < num - 1 )
      {
        v6 = index;
        do
        {
          ++v5;
          v7 = &this->data[v6++];
          *v7 = v7[1];
        }
        while ( v5 < this->num - 1 );
      }
      --this->num;
    }
  }
}


// ========================================================================
// ?RemoveFast@?$ssList@H@@QAAXH@Z
// EA  : 0x82EE97C0
// RVA : 0x00EE97C0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<int>::RemoveFast(ssList<int> *this, int index)
{
  int num; // r10

  if ( index < 0 || index >= this->num )
    AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
  if ( index >= 0 )
  {
    num = this->num;
    if ( index < num )
    {
      if ( index < num - 1 )
        this->data[index] = this->data[num - 1];
      --this->num;
    }
  }
}


// ========================================================================
// ?RemoveElement@?$ssList@H@@QAA_NABH@Z
// EA  : 0x82EE9858
// RVA : 0x00EE9858
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<int>::RemoveElement(ssList<int> *this, const int *element)
{
  int num; // r7
  int v3; // r10
  int i; // r11

  num = this->num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->data[i] != *element; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  if ( v3 < 0 )
    return 0;
  ssList<int>::Remove(this, index: v3);
  return 1;
}


// ========================================================================
// ?RemoveElementFast@?$ssList@H@@QAA_NABH@Z
// EA  : 0x82EE98E8
// RVA : 0x00EE98E8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<int>::RemoveElementFast(ssList<int> *this, const int *element)
{
  int num; // r7
  int v3; // r10
  int i; // r11

  num = this->num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->data[i] != *element; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  if ( v3 < 0 )
    return 0;
  ssList<int>::RemoveFast(this, index: v3);
  return 1;
}


// ========================================================================
// ?Resize@?$ssList@H@@AAAXH@Z
// EA  : 0x82EE9978
// RVA : 0x00EE9978
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<int>::Resize(ssList<int> *this, int newSize)
{
  int num; // r29
  unsigned int v4; // r28
  int v5; // r26
  int *v6; // r3
  int *v7; // r27
  int v8; // r10
  int v9; // ctr
  int *v10; // r11

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = (int *)gameInterface->Allocate(this: gameInterface, a2: 4 * v4, a3: this->threadId);
    v7 = v6;
    if ( num > 0 )
    {
      v8 = 0;
      v9 = num;
      v10 = v6;
      do
      {
        if ( v10 != nullptr )
          *v10 = this->data[v8];
        ++v8;
        ++v10;
        --v9;
      }
      while ( v9 != 0 );
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<ssEntity>::Clear((ssList<float> *)this);
    this->data = v7;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<ssEntity>::Clear((ssList<float> *)this);
  }
}


// ========================================================================
// ?Insert@?$ssList@H@@QAAHABHH@Z
// EA  : 0x82EE9A68
// RVA : 0x00EE9A68
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<int>::Insert(ssList<int> *this, int *element, unsigned int index)
{
  int num; // r11
  int v7; // r11
  int result; // r3
  int v9; // r11
  int v10; // ctr
  int *v11; // r10

  num = this->num;
  if ( num == this->size )
    ssList<int>::Resize(this, newSize: num + 1);
  v7 = this->num;
  result = ((index >> 31) - 1) & index;
  if ( result > v7 )
    result = this->num;
  this->num = v7 + 1;
  if ( v7 > result )
  {
    v10 = v7 - result;
    v9 = v7;
    do
    {
      v11 = &this->data[v9--];
      *v11 = *(v11 - 1);
      --v10;
    }
    while ( v10 != 0 );
  }
  this->data[result] = *element;
  return result;
}


// ========================================================================
// ?Append@?$ssList@H@@QAAHABV1@@Z
// EA  : 0x82EE9B10
// RVA : 0x00EE9B10
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<int>::Append(ssList<int> *this, const ssList<int> *src)
{
  int result; // r3
  int num; // r11
  int v6; // r30
  int v7; // r29
  ssString v8[5]; // [sp+60h] [-50h] BYREF

  if ( this == src )
  {
    AssertionFailed(msg: "Assertion failed: this != &src");
    return -1;
  }
  else
  {
    ssList<int>::Resize(this, newSize: src->num + this->num);
    result = -1;
    v6 = 0;
    num = src->num;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        if ( v6 < 0 || v6 >= num )
        {
          ssString::Init(this: v8);
          ssString::operator=(this: v8, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
          Error(msg: v8);
          ssString::Empty(this: v8);
        }
        result = ssList<int>::Insert(this, element: &src->data[v7], index: this->num);
        num = src->num;
        ++v6;
        ++v7;
      }
      while ( v6 < num );
    }
  }
  return result;
}


// ========================================================================
// __unwind$19880
// EA  : 0x82EE9BE0
// RVA : 0x00EE9BE0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_19880()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ??0?$ssList@H@@QAA@ABV0@@Z
// EA  : 0x82EE9D80
// RVA : 0x00EE9D80
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

ssList<int> *__fastcall ssList<int>::ssList<int>(ssList<int> *this, const ssList<int> *src)
{
  int v2; // r11

  v2 = 0;
  this->data = nullptr;
  this->num = 0;
  this->size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->threadId = v2;
  ssList<int>::Append(this, src);
  return this;
}


// ========================================================================
// ?AppendUnique@?$ssList@H@@QAAHABV1@@Z
// EA  : 0x82EE9E08
// RVA : 0x00EE9E08
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<int>::AppendUnique(ssList<int> *this, const ssList<int> *src)
{
  int num; // r11
  int result; // r3
  int v6; // r27
  int v7; // r28
  signed int v8; // r10
  signed int v9; // r5
  int *v10; // r4
  int v11; // r11
  ssString v12[5]; // [sp+60h] [-50h] BYREF

  result = -1;
  v6 = 0;
  num = src->num;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      if ( v6 < 0 || v6 >= num )
      {
        ssString::Init(this: v12);
        ssString::operator=(this: v12, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: v12);
        ssString::Empty(this: v12);
      }
      v8 = 0;
      v9 = this->num;
      v10 = &src->data[v7];
      if ( v9 <= 0 )
        goto LABEL_10;
      v11 = 0;
      while ( this->data[v11] != *v10 )
      {
        ++v8;
        ++v11;
        if ( v8 >= v9 )
          goto LABEL_10;
      }
      if ( v8 == -1 )
LABEL_10:
        result = ssList<int>::Insert(this, element: v10, index: v9);
      else
        result = -1;
      num = src->num;
      ++v6;
      ++v7;
    }
    while ( v6 < num );
  }
  return result;
}


// ========================================================================
// __unwind$20090
// EA  : 0x82EE9EF8
// RVA : 0x00EE9EF8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_20090()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Resize@?$ssList@VssString@@@@AAAXH@Z
// EA  : 0x82EEAFF8
// RVA : 0x00EEAFF8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<ssString>::Resize(ssList<ssString> *this, int newSize)
{
  int num; // r25
  signed int v4; // r24
  int v5; // r22
  int v6; // r28
  ssString *i; // r26
  const ssString *v8; // r27
  signed int j; // r30

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = 0;
    for ( i = (ssString *)gameInterface->Allocate(this: gameInterface, a2: 16 * v4, a3: this->threadId); v6 < num; ++v6 )
    {
      if ( &i[v6] != nullptr )
      {
        v8 = &this->data[v6];
        ssString::Init(this: &i[v6]);
        ssString::operator=(this: &i[v6], text: v8);
      }
    }
    for ( j = num; j < v4; ++j )
    {
      if ( &i[j] != nullptr )
        ssString::Init(this: &i[j]);
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<ssString>::Clear(this);
    this->data = i;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<ssString>::Clear(this);
  }
}


// ========================================================================
// __unwind$19891
// EA  : 0x82EEB134
// RVA : 0x00EEB134
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_19891()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$19892
// EA  : 0x82EEB16C
// RVA : 0x00EEB16C
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_19892()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 88));
}


// ========================================================================
// ?Insert@?$ssList@VssString@@@@QAAHABVssString@@H@Z
// EA  : 0x82EEB1A8
// RVA : 0x00EEB1A8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<ssString>::Insert(ssList<ssString> *this, const ssString *element, unsigned int index)
{
  int num; // r11
  int v7; // r11
  signed int v8; // r28
  int v9; // r30
  int v10; // r31

  num = this->num;
  if ( num == this->size )
    ssList<ssString>::Resize(this, newSize: num + 1);
  v7 = this->num;
  v8 = ((index >> 31) - 1) & index;
  if ( v8 > v7 )
    v8 = this->num;
  this->num = v7 + 1;
  if ( v7 > v8 )
  {
    v9 = v7;
    v10 = v7 - v8;
    do
    {
      ssString::operator=(this: &this->data[v9], text: &this->data[v9 - 1]);
      --v10;
      --v9;
    }
    while ( v10 != 0 );
  }
  ssString::operator=(this: &this->data[v8], text: element);
  return v8;
}


// ========================================================================
// ?Resize@?$ssList@VssEntity@@@@AAAXH@Z
// EA  : 0x82EEBE48
// RVA : 0x00EEBE48
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<ssEntity>::Resize(ssList<ssEntity> *this, int newSize)
{
  int num; // r27
  signed int v4; // r26
  int v5; // r24
  int v6; // r29
  ssEntity *i; // r28
  signed int j; // r29

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = 0;
    for ( i = (ssEntity *)gameInterface->Allocate(this: gameInterface, a2: 4 * v4, a3: this->threadId); v6 < num; ++v6 )
    {
      if ( &i[v6] != nullptr )
        ssEntity::ssEntity(this: &i[v6], e: &this->data[v6]);
    }
    for ( j = num; j < v4; ++j )
    {
      if ( &i[j] != nullptr )
        idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&i[j]);
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<ssEntity>::Clear((ssList<float> *)this);
    this->data = i;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<ssEntity>::Clear((ssList<float> *)this);
  }
}


// ========================================================================
// __unwind$20540_0
// EA  : 0x82EEBF74
// RVA : 0x00EEBF74
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_20540_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$20541
// EA  : 0x82EEBFAC
// RVA : 0x00EEBFAC
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_20541()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?Insert@?$ssList@VssEntity@@@@QAAHABVssEntity@@H@Z
// EA  : 0x82EEC728
// RVA : 0x00EEC728
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<ssEntity>::Insert(ssList<ssEntity> *this, const ssEntity *element, unsigned int index)
{
  int num; // r11
  int v7; // r11
  signed int v8; // r28
  int v9; // r30
  int v10; // r31

  num = this->num;
  if ( num == this->size )
    ssList<ssEntity>::Resize(this, newSize: num + 1);
  v7 = this->num;
  v8 = ((index >> 31) - 1) & index;
  if ( v8 > v7 )
    v8 = this->num;
  this->num = v7 + 1;
  if ( v7 > v8 )
  {
    v9 = v7;
    v10 = v7 - v8;
    do
    {
      ssEntity::ssEntity(this: &this->data[v9], e: &this->data[v9 - 1]);
      --v10;
      --v9;
    }
    while ( v10 != 0 );
  }
  ssEntity::ssEntity(this: &this->data[v8], e: element);
  return v8;
}


// ========================================================================
// ?Get@?$ssList@UflagDef_t@util_entityFlag@@@@QAAAAUflagDef_t@util_entityFlag@@H@Z
// EA  : 0x82EEE630
// RVA : 0x00EEE630
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

util_entityFlag::flagDef_t *__fastcall ssList<util_entityFlag::flagDef_t>::Get(
        ssList<util_entityFlag::flagDef_t> *this,
        int index)
{
  if ( index < 0 || index >= this->num )
    AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
  return &this->data[index];
}


// ========================================================================
// ?Resize@?$ssList@UcallFunction_t@util_entityFlag@@@@AAAXH@Z
// EA  : 0x82EEEF20
// RVA : 0x00EEEF20
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<util_entityFlag::callFunction_t>::Resize(
        ssList<util_entityFlag::callFunction_t> *this,
        int newSize)
{
  int num; // r24
  signed int v4; // r25
  int v5; // r22
  int v6; // r28
  util_entityFlag::callFunction_t *i; // r26
  util_entityFlag::callFunction_t *v8; // r29
  ssString *p_function; // r30
  signed int j; // r30

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = 0;
    for ( i = (util_entityFlag::callFunction_t *)gameInterface->Allocate(
                                                   this: gameInterface,
                                                   a2: 20 * v4,
                                                   a3: this->threadId); v6 < num; ++v6 )
    {
      if ( &i[v6] != nullptr )
      {
        v8 = &this->data[v6];
        ssEntity::ssEntity(this: &i[v6].target, e: &v8->target);
        p_function = &i[v6].function;
        ssString::Init(this: p_function);
        ssString::operator=(this: p_function, text: &v8->function);
      }
    }
    for ( j = num; j < v4; ++j )
    {
      if ( &i[j] != nullptr )
      {
        idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&i[j]);
        ssString::Init(this: &i[j].function);
      }
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<util_entityFlag::callFunction_t>::Clear(this);
    this->data = i;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<util_entityFlag::callFunction_t>::Clear(this);
  }
}


// ========================================================================
// __unwind$21172
// EA  : 0x82EEF090
// RVA : 0x00EEF090
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_21172()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$21173
// EA  : 0x82EEF0C8
// RVA : 0x00EEF0C8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_21173()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 88));
}


// ========================================================================
// ?Insert@?$ssList@UcallFunction_t@util_entityFlag@@@@QAAHABUcallFunction_t@util_entityFlag@@H@Z
// EA  : 0x82EF0438
// RVA : 0x00EF0438
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<util_entityFlag::callFunction_t>::Insert(
        ssList<util_entityFlag::callFunction_t> *this,
        const util_entityFlag::callFunction_t *element,
        unsigned int index)
{
  int num; // r11
  int v7; // r11
  signed int v8; // r26
  int v9; // r30
  int v10; // r29
  util_entityFlag::callFunction_t *v11; // r31
  util_entityFlag::callFunction_t *v12; // r31

  num = this->num;
  if ( num == this->size )
    ssList<util_entityFlag::callFunction_t>::Resize(this, newSize: num + 1);
  v7 = this->num;
  v8 = ((index >> 31) - 1) & index;
  if ( v8 > v7 )
    v8 = this->num;
  this->num = v7 + 1;
  if ( v7 > v8 )
  {
    v9 = v7 - v8;
    v10 = v7;
    do
    {
      v11 = &this->data[v10];
      ssEntity::ssEntity(this: &v11->target, e: &v11[-1].target);
      ssString::operator=(this: &v11->function, text: &v11[-1].function);
      --v9;
      --v10;
    }
    while ( v9 != 0 );
  }
  v12 = &this->data[v8];
  ssEntity::ssEntity(this: &v12->target, e: &element->target);
  ssString::operator=(this: &v12->function, text: &element->function);
  return v8;
}


// ========================================================================
// ?Append@?$ssList@UcallFunction_t@util_entityFlag@@@@QAAHABV1@@Z
// EA  : 0x82EF0900
// RVA : 0x00EF0900
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<util_entityFlag::callFunction_t>::Append(
        ssList<util_entityFlag::callFunction_t> *this,
        const ssList<util_entityFlag::callFunction_t> *src)
{
  int result; // r3
  int num; // r11
  int v6; // r30
  int v7; // r29
  ssString v8[5]; // [sp+60h] [-50h] BYREF

  if ( this == src )
  {
    AssertionFailed(msg: "Assertion failed: this != &src");
    return -1;
  }
  else
  {
    ssList<util_entityFlag::callFunction_t>::Resize(this, newSize: src->num + this->num);
    result = -1;
    v6 = 0;
    num = src->num;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        if ( v6 < 0 || v6 >= num )
        {
          ssString::Init(this: v8);
          ssString::operator=(this: v8, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
          Error(msg: v8);
          ssString::Empty(this: v8);
        }
        result = ssList<util_entityFlag::callFunction_t>::Insert(this, element: &src->data[v7], index: this->num);
        num = src->num;
        ++v6;
        ++v7;
      }
      while ( v6 < num );
    }
  }
  return result;
}


// ========================================================================
// __unwind$22859
// EA  : 0x82EF09D0
// RVA : 0x00EF09D0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_22859()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ??0?$ssList@UcallFunction_t@util_entityFlag@@@@QAA@ABV0@@Z
// EA  : 0x82EF09F8
// RVA : 0x00EF09F8
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

ssList<util_entityFlag::callFunction_t> *__fastcall ssList<util_entityFlag::callFunction_t>::ssList<util_entityFlag::callFunction_t>(
        ssList<util_entityFlag::callFunction_t> *this,
        const ssList<util_entityFlag::callFunction_t> *src)
{
  int v2; // r11

  v2 = 0;
  this->data = nullptr;
  this->num = 0;
  this->size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->threadId = v2;
  ssList<util_entityFlag::callFunction_t>::Append(this, src);
  return this;
}


// ========================================================================
// ?Resize@?$ssList@UflagDef_t@util_entityFlag@@@@AAAXH@Z
// EA  : 0x82EF0B50
// RVA : 0x00EF0B50
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<util_entityFlag::flagDef_t>::Resize(ssList<util_entityFlag::flagDef_t> *this, int newSize)
{
  int num; // r27
  signed int v4; // r26
  int v5; // r24
  int v6; // r29
  util_entityFlag::flagDef_t *i; // r28
  signed int j; // r29

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = 0;
    for ( i = (util_entityFlag::flagDef_t *)gameInterface->Allocate(
                                              this: gameInterface,
                                              a2: 60 * v4,
                                              a3: this->threadId); v6 < num; ++v6 )
    {
      if ( &i[v6] != nullptr )
        util_entityFlag::flagDef_t::flagDef_t(this: &i[v6], __that: &this->data[v6]);
    }
    for ( j = num; j < v4; ++j )
    {
      if ( &i[j] != nullptr )
        util_entityFlag::flagDef_t::flagDef_t(this: &i[j]);
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<util_entityFlag::flagDef_t>::Clear(this);
    this->data = i;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<util_entityFlag::flagDef_t>::Clear(this);
  }
}


// ========================================================================
// __unwind$23463
// EA  : 0x82EF0C7C
// RVA : 0x00EF0C7C
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_23463()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$23464
// EA  : 0x82EF0CB4
// RVA : 0x00EF0CB4
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void _unwind_23464()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?Insert@?$ssList@UflagDef_t@util_entityFlag@@@@QAAHABUflagDef_t@util_entityFlag@@H@Z
// EA  : 0x82EF0CF0
// RVA : 0x00EF0CF0
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<util_entityFlag::flagDef_t>::Insert(
        ssList<util_entityFlag::flagDef_t> *this,
        const util_entityFlag::flagDef_t *element,
        unsigned int index)
{
  int num; // r11
  int v7; // r11
  signed int v8; // r24
  int v9; // r28
  int v10; // r29
  util_entityFlag::flagDef_t *v11; // r31
  util_entityFlag::flagDef_t *v12; // r30
  util_entityFlag::flagDef_t *v13; // r31

  num = this->num;
  if ( num == this->size )
    ssList<util_entityFlag::flagDef_t>::Resize(this, newSize: num + 1);
  v7 = this->num;
  v8 = ((index >> 31) - 1) & index;
  if ( v8 > v7 )
    v8 = this->num;
  this->num = v7 + 1;
  if ( v7 > v8 )
  {
    v9 = v7;
    v10 = v7 - v8;
    do
    {
      v11 = &this->data[v9];
      v12 = v11 - 1;
      ssString::operator=(this: &v11->name, text: &v11[-1].name);
      v11->animNotify = v11[-1].animNotify;
      v11->state = v11[-1].state;
      v11->count = v11[-1].count;
      v11->lastTime = v11[-1].lastTime;
      ssList<ssEntity>::Clear(this: (ssList<float> *)&v11->terminateThreads);
      ssList<int>::Append(this: &v11->terminateThreads, src: &v11[-1].terminateThreads);
      v11 = (util_entityFlag::flagDef_t *)((char *)v11 + 44);
      ssList<util_entityFlag::callFunction_t>::Clear(this: (ssList<util_entityFlag::callFunction_t> *)v11);
      ssList<util_entityFlag::callFunction_t>::Append(
        this: (ssList<util_entityFlag::callFunction_t> *)v11,
        src: &v12->callFunctions);
      --v10;
      --v9;
    }
    while ( v10 != 0 );
  }
  v13 = &this->data[v8];
  ssString::operator=(this: &v13->name, text: &element->name);
  v13->animNotify = element->animNotify;
  v13->state = element->state;
  v13->count = element->count;
  v13->lastTime = element->lastTime;
  ssList<ssEntity>::Clear(this: (ssList<float> *)&v13->terminateThreads);
  ssList<int>::Append(this: &v13->terminateThreads, src: &element->terminateThreads);
  v13 = (util_entityFlag::flagDef_t *)((char *)v13 + 44);
  ssList<util_entityFlag::callFunction_t>::Clear(this: (ssList<util_entityFlag::callFunction_t> *)v13);
  ssList<util_entityFlag::callFunction_t>::Append(
    this: (ssList<util_entityFlag::callFunction_t> *)v13,
    src: &element->callFunctions);
  return v8;
}


// ========================================================================
// ?Resize@?$ssList@M@@AAAXH@Z
// EA  : 0x82EF3240
// RVA : 0x00EF3240
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

void __fastcall ssList<float>::Resize(ssList<float> *this, int newSize)
{
  int num; // r29
  unsigned int v4; // r27
  int v5; // r26
  float *v6; // r3
  float *v7; // r30
  int v8; // r8
  int v9; // r7
  float *v10; // r11
  int v11; // r6
  int v12; // r10
  float *v13; // r11
  int v14; // ctr

  if ( newSize > 0 )
  {
    num = this->num;
    if ( newSize < num )
      num = newSize;
    v4 = (newSize + 7) & 0xFFFFFFF8;
    v5 = gameInterface->SetAllocThread(this: gameInterface, a2: this->threadId);
    v6 = (float *)gameInterface->Allocate(this: gameInterface, a2: 4 * v4, a3: this->threadId);
    v7 = v6;
    v8 = 0;
    if ( num >= 4 )
    {
      v9 = 2;
      v10 = v6 + 2;
      v11 = -8 - (_DWORD)v6;
      do
      {
        if ( v10 != (float *)8 )
          *(v10 - 2) = *(float *)((char *)v10 + v11 + (unsigned int)this->data);
        if ( v10 != (float *)4 )
          *(v10 - 1) = *(float *)((char *)v10 + v11 + (unsigned int)this->data + 4);
        if ( v10 != nullptr )
          *v10 = this->data[v9];
        if ( v10 != (float *)-4 )
          v10[1] = *(float *)((char *)v10 + 4 - (_DWORD)v6 + (unsigned int)this->data);
        v8 += 4;
        v9 += 4;
        v10 += 4;
      }
      while ( v8 < num - 3 );
    }
    if ( v8 < num )
    {
      v12 = v8;
      v13 = &v6[v8];
      v14 = num - v8;
      do
      {
        if ( v13 != nullptr )
          *v13 = this->data[v12];
        ++v12;
        ++v13;
        --v14;
      }
      while ( v14 != 0 );
    }
    gameInterface->SetAllocThread(this: gameInterface, a2: v5);
    ssList<ssEntity>::Clear(this);
    this->data = v7;
    this->num = num;
    this->size = v4;
  }
  else
  {
    ssList<ssEntity>::Clear(this);
  }
}


// ========================================================================
// ?Insert@?$ssList@M@@QAAHABMH@Z
// EA  : 0x82EF3980
// RVA : 0x00EF3980
// PDB : w:\tech5\tungsten\superscript\lib\list.h
// ========================================================================

int __fastcall ssList<float>::Insert(ssList<float> *this, float *element, unsigned int index)
{
  int num; // r11
  int v7; // r11
  int result; // r3
  int v9; // r11
  int v10; // r10
  int v11; // r11
  int v12; // r11
  int v13; // ctr
  float *v14; // r10

  num = this->num;
  if ( num == this->size )
    ssList<float>::Resize(this, newSize: num + 1);
  v7 = this->num;
  result = ((index >> 31) - 1) & index;
  if ( result > v7 )
    result = this->num;
  v9 = v7 + 1;
  v10 = v9 - 1;
  this->num = v9;
  if ( v9 - 1 > result )
  {
    if ( v10 - result >= 4 )
    {
      v11 = v9 - 3;
      do
      {
        v10 -= 4;
        this->data[v11 + 2] = this->data[v11 + 1];
        this->data[v11 + 1] = this->data[v11];
        this->data[v11] = this->data[v11 - 1];
        this->data[v11 - 1] = this->data[v11 - 2];
        v11 -= 4;
      }
      while ( v10 > result + 3 );
    }
    if ( v10 > result )
    {
      v12 = v10;
      v13 = v10 - result;
      do
      {
        v14 = &this->data[v12--];
        *v14 = *(v14 - 1);
        --v13;
      }
      while ( v13 != 0 );
    }
  }
  this->data[result] = *element;
  return result;
}

