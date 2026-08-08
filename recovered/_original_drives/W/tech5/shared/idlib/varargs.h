
// ========================================================================
// ?Grow@?$idVarArgs@$05@@IAAXI@Z
// EA  : 0x8256F8A0
// RVA : 0x0056F8A0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::Grow(idVarArgs<6> *this, const unsigned int newArgSize)
{
  unsigned int buffSize; // r10
  unsigned int v4; // r11
  int v5; // r28
  unsigned __int8 *v6; // r3
  unsigned __int8 *args; // r4
  unsigned __int8 *v8; // r29

  if ( newArgSize != 0 )
  {
    buffSize = this->buffSize;
    v4 = this->argSize + newArgSize;
    if ( v4 > buffSize )
    {
      v5 = 2 * buffSize;
      if ( 2 * buffSize <= v4 )
        v5 = this->argSize + newArgSize;
      v6 = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v5,
                                tag: TAG_AI_FSM,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      args = this->args;
      v8 = v6;
      if ( args != nullptr )
      {
        memcpy(Dst: v6, Src: args, Size: this->argSize);
        idMem::Free(this: &mem, ptr: this->args, align: ALIGN_16);
      }
      this->args = v8;
      this->buffSize = v5;
    }
  }
}


// ========================================================================
// ?Free@?$idVarArgs@$05@@IAAXXZ
// EA  : 0x82582C28
// RVA : 0x00582C28
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::Free(idVarArgs<6> *this)
{
  unsigned __int8 *args; // r4

  args = this->args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    this->args = nullptr;
  }
  this->argSize = 0;
  this->buffSize = 0;
  this->numArgs = 0;
}


// ========================================================================
// ?Equal@?$idVarArgs@$01@@IBA_NABV1@@Z
// EA  : 0x8263CA20
// RVA : 0x0063CA20
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<2>::Equal(idVarArgs<2> *this, const idVarArgs<2> *other)
{
  int argSize; // r7
  idVarArgs<2> *argOffsets; // r11
  unsigned __int16 *v4; // r10
  int v5; // r6
  int v6; // r9
  unsigned __int8 *argTypes; // r11
  unsigned __int8 *v8; // r10
  int v9; // r6
  int v10; // r9
  unsigned __int8 *argExTypes; // r11
  unsigned __int8 *v12; // r10
  int v13; // r6
  int v14; // r9
  unsigned __int8 *args; // r10
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r8
  int v18; // r7
  unsigned __int8 v19; // r11

  if ( this->numArgs != other->numArgs )
    return 0;
  argSize = this->argSize;
  if ( argSize != other->argSize )
    return 0;
  argOffsets = (idVarArgs<2> *)this->argOffsets;
  v4 = other->argOffsets;
  do
  {
    v5 = *(unsigned __int8 *)v4;
    v6 = HIBYTE(argOffsets->numArgs) - v5;
    if ( HIBYTE(argOffsets->numArgs) != v5 )
      break;
    argOffsets = (idVarArgs<2> *)((char *)argOffsets + 1);
    v4 = (unsigned __int16 *)((char *)v4 + 1);
  }
  while ( argOffsets != (idVarArgs<2> *)this->argTypes );
  if ( v6 != 0 )
    return 0;
  argTypes = this->argTypes;
  v8 = other->argTypes;
  do
  {
    v9 = *v8;
    v10 = *argTypes - v9;
    if ( *argTypes != v9 )
      break;
    ++argTypes;
    ++v8;
  }
  while ( argTypes != this->argExTypes );
  if ( v10 != 0 )
    return 0;
  argExTypes = this->argExTypes;
  v12 = other->argExTypes;
  do
  {
    v13 = *v12;
    v14 = *argExTypes - v13;
    if ( *argExTypes != v13 )
      break;
    ++argExTypes;
    ++v12;
  }
  while ( argExTypes != &this->argExTypes[2] );
  if ( v14 != 0 )
    return 0;
  args = other->args;
  v16 = this->args;
  if ( this->argSize != 0 )
  {
    v17 = &v16[argSize];
    do
    {
      v18 = *args;
      v14 = *v16 - v18;
      if ( *v16 != v18 )
        break;
      ++v16;
      ++args;
    }
    while ( v16 != v17 );
  }
  v19 = 1;
  if ( v14 != 0 )
    return 0;
  return v19;
}


// ========================================================================
// ?Free@?$idVarArgs@$01@@IAAXXZ
// EA  : 0x8263E460
// RVA : 0x0063E460
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<2>::Free(idVarArgs<2> *this)
{
  unsigned __int8 *args; // r4

  args = this->args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    this->args = nullptr;
  }
  this->argSize = 0;
  this->buffSize = 0;
  this->numArgs = 0;
}


// ========================================================================
// ?Grow@?$idVarArgs@$01@@IAAXI@Z
// EA  : 0x8263E4C0
// RVA : 0x0063E4C0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<2>::Grow(idVarArgs<2> *this, const unsigned int newArgSize)
{
  unsigned int buffSize; // r10
  unsigned int v4; // r11
  int v5; // r28
  unsigned __int8 *v6; // r3
  unsigned __int8 *args; // r4
  unsigned __int8 *v8; // r29

  if ( newArgSize != 0 )
  {
    buffSize = this->buffSize;
    v4 = this->argSize + newArgSize;
    if ( v4 > buffSize )
    {
      v5 = 2 * buffSize;
      if ( 2 * buffSize <= v4 )
        v5 = this->argSize + newArgSize;
      v6 = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v5,
                                tag: TAG_AI_FSM,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      args = this->args;
      v8 = v6;
      if ( args != nullptr )
      {
        memcpy(Dst: v6, Src: args, Size: this->argSize);
        idMem::Free(this: &mem, ptr: this->args, align: ALIGN_16);
      }
      this->args = v8;
      this->buffSize = v5;
    }
  }
}


// ========================================================================
// ?Copy@?$idVarArgs@$01@@IAAXABV1@@Z
// EA  : 0x8263E560
// RVA : 0x0063E560
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<2>::Copy(idVarArgs<2> *this, const idVarArgs<2> *other)
{
  unsigned __int8 *v4; // r3

  if ( this != other )
  {
    idVarArgs<2>::Free(this);
    this->numArgs = other->numArgs;
    this->argSize = other->argSize;
    this->buffSize = other->buffSize;
    this->argOffsets[0] = other->argOffsets[0];
    this->argOffsets[1] = other->argOffsets[1];
    *(_WORD *)this->argTypes = *(_WORD *)other->argTypes;
    *(_WORD *)this->argExTypes = *(_WORD *)other->argExTypes;
    v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                              size: this->buffSize,
                              tag: TAG_AI_FSM,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    this->args = v4;
    memcpy(Dst: v4, Src: other->args, Size: this->argSize);
  }
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAVidStr@@@Z
// EA  : 0x8280D1F8
// RVA : 0x0080D1F8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, idStr *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 8 )
    return 0;
  idStr::operator=(this: val, text: (const char *)&this->args[this->argOffsets[index]]);
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAPAX@Z
// EA  : 0x8280D288
// RVA : 0x0080D288
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, void **ptr)
{
  char v3; // r11
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  unsigned __int8 *v8; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 )
    return 0;
  v5 = this->argTypes[index];
  if ( v5 == 9 || v5 == 10 || (v7 = v5 != 11, v6 = 0, !v7) )
    v6 = 1;
  if ( v6 == 0 )
    return 0;
  v8 = &this->args[this->argOffsets[index]];
  *(_BYTE *)ptr = *v8;
  *(_WORD *)((char *)ptr + 1) = *(_WORD *)(v8 + 1);
  *((_BYTE *)ptr + 3) = v8[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAVidStr@@@Z
// EA  : 0x8280D330
// RVA : 0x0080D330
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, idStr *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 8 )
    return 0;
  idStr::operator=(this: val, text: (const char *)&this->args[this->argOffsets[index]]);
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAVidAngles@@@Z
// EA  : 0x8280D3C0
// RVA : 0x0080D3C0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, idAngles *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 7 )
    return 0;
  *val = *(idAngles *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAVidQuat@@@Z
// EA  : 0x8280D450
// RVA : 0x0080D450
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, idQuat *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 6 )
    return 0;
  *val = *(idQuat *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAVidVec4@@@Z
// EA  : 0x8280D4E0
// RVA : 0x0080D4E0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, idVec4 *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 12 )
    return 0;
  *val = *(idVec4 *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAVidVec3@@@Z
// EA  : 0x8280D570
// RVA : 0x0080D570
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, idVec3 *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 5 )
    return 0;
  *val = *(idVec3 *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAM@Z
// EA  : 0x8280D600
// RVA : 0x0080D600
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, float *val)
{
  char v3; // r10
  unsigned __int8 *v5; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 4 )
    return 0;
  v5 = &this->args[this->argOffsets[index]];
  *(_BYTE *)val = *v5;
  *(_WORD *)((char *)val + 1) = *(_WORD *)(v5 + 1);
  *((_BYTE *)val + 3) = v5[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAH@Z
// EA  : 0x8280D680
// RVA : 0x0080D680
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, int *val)
{
  char v3; // r10
  unsigned __int8 *v5; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 3 )
    return 0;
  v5 = &this->args[this->argOffsets[index]];
  *(_BYTE *)val = *v5;
  *(_WORD *)((char *)val + 1) = *(_WORD *)(v5 + 1);
  *((_BYTE *)val + 3) = v5[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAAD@Z
// EA  : 0x8280D700
// RVA : 0x0080D700
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, char *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 2 )
    return 0;
  *val = this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$05@@QBA_NHAA_N@Z
// EA  : 0x8280D768
// RVA : 0x0080D768
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::GetArg(idVarArgs<6> *this, const int index, bool *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 1 )
    return 0;
  *val = this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?Equal@?$idVarArgs@$05@@IBA_NABV1@@Z
// EA  : 0x8280D7D0
// RVA : 0x0080D7D0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<6>::Equal(idVarArgs<6> *this, const idVarArgs<6> *other)
{
  int argSize; // r7
  idVarArgs<6> *argOffsets; // r11
  unsigned __int16 *v4; // r10
  int v5; // r6
  int v6; // r9
  unsigned __int8 *argTypes; // r11
  unsigned __int8 *v8; // r10
  int v9; // r6
  int v10; // r9
  unsigned __int8 *argExTypes; // r11
  unsigned __int8 *v12; // r10
  int v13; // r6
  int v14; // r9
  unsigned __int8 *args; // r10
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r8
  int v18; // r7
  unsigned __int8 v19; // r11

  if ( this->numArgs != other->numArgs )
    return 0;
  argSize = this->argSize;
  if ( argSize != other->argSize )
    return 0;
  argOffsets = (idVarArgs<6> *)this->argOffsets;
  v4 = other->argOffsets;
  do
  {
    v5 = *(unsigned __int8 *)v4;
    v6 = HIBYTE(argOffsets->numArgs) - v5;
    if ( HIBYTE(argOffsets->numArgs) != v5 )
      break;
    argOffsets = (idVarArgs<6> *)((char *)argOffsets + 1);
    v4 = (unsigned __int16 *)((char *)v4 + 1);
  }
  while ( argOffsets != (idVarArgs<6> *)this->argTypes );
  if ( v6 != 0 )
    return 0;
  argTypes = this->argTypes;
  v8 = other->argTypes;
  do
  {
    v9 = *v8;
    v10 = *argTypes - v9;
    if ( *argTypes != v9 )
      break;
    ++argTypes;
    ++v8;
  }
  while ( argTypes != this->argExTypes );
  if ( v10 != 0 )
    return 0;
  argExTypes = this->argExTypes;
  v12 = other->argExTypes;
  do
  {
    v13 = *v12;
    v14 = *argExTypes - v13;
    if ( *argExTypes != v13 )
      break;
    ++argExTypes;
    ++v12;
  }
  while ( argExTypes != &this->argExTypes[6] );
  if ( v14 != 0 )
    return 0;
  args = other->args;
  v16 = this->args;
  if ( this->argSize != 0 )
  {
    v17 = &v16[argSize];
    do
    {
      v18 = *args;
      v14 = *v16 - v18;
      if ( *v16 != v18 )
        break;
      ++v16;
      ++args;
    }
    while ( v16 != v17 );
  }
  v19 = 1;
  if ( v14 != 0 )
    return 0;
  return v19;
}


// ========================================================================
// ?Copy@?$idVarArgs@$05@@IAAXABV1@@Z
// EA  : 0x8280ED88
// RVA : 0x0080ED88
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::Copy(idVarArgs<6> *this, const idVarArgs<6> *other)
{
  unsigned __int16 *p_buffSize; // r11
  unsigned __int16 *v5; // r10
  int v6; // ctr
  unsigned __int8 *v7; // r3

  if ( this != other )
  {
    idVarArgs<6>::Free(this);
    p_buffSize = &other->buffSize;
    v5 = &this->buffSize;
    v6 = 6;
    this->numArgs = other->numArgs;
    this->argSize = other->argSize;
    this->buffSize = other->buffSize;
    do
    {
      *++v5 = *++p_buffSize;
      --v6;
    }
    while ( v6 != 0 );
    *(_WORD *)this->argTypes = *(_WORD *)other->argTypes;
    *(_WORD *)&this->argTypes[2] = *(_WORD *)&other->argTypes[2];
    *(_WORD *)&this->argTypes[4] = *(_WORD *)&other->argTypes[4];
    *(_DWORD *)this->argExTypes = *(_DWORD *)other->argExTypes;
    *(_WORD *)&this->argExTypes[4] = *(_WORD *)&other->argExTypes[4];
    v7 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                              size: this->buffSize,
                              tag: TAG_AI_FSM,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    this->args = v7;
    memcpy(Dst: v7, Src: other->args, Size: this->argSize);
  }
}


// ========================================================================
// ?ClearArgs@?$idVarArgs@$05@@QAAXXZ
// EA  : 0x8280F2F0
// RVA : 0x0080F2F0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::ClearArgs(idVarArgs<6> *this)
{
  unsigned __int8 *args; // r4
  unsigned __int16 *p_buffSize; // r11
  int i; // ctr

  args = this->args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    this->args = nullptr;
  }
  this->argSize = 0;
  this->buffSize = 0;
  p_buffSize = &this->buffSize;
  this->numArgs = 0;
  for ( i = 6; i != 0; --i )
    *++p_buffSize = 0;
  *(_WORD *)this->argTypes = 0;
  *(_WORD *)&this->argTypes[2] = 0;
  *(_WORD *)&this->argTypes[4] = 0;
  *(_DWORD *)this->argExTypes = 0;
  *(_WORD *)&this->argExTypes[4] = 0;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXPBDE@Z
// EA  : 0x8280F380
// RVA : 0x0080F380
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const char *val, unsigned __int8 exType)
{
  int v5; // r11
  size_t v6; // r30
  int v7; // r9

  v5 = 0;
  this->argTypes[this->numArgs] = 8;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  if ( *val != 0 )
  {
    do
      ++v5;
    while ( val[v5] != 0 );
  }
  v6 = v5 + 1;
  idVarArgs<6>::Grow(this, newArgSize: v5 + 1);
  v7 = this->numArgs + 3;
  this->argSize += v6;
  memcpy(Dst: &this->args[*(&this->numArgs + v7)], Src: val, Size: v6);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXABVidAngles@@E@Z
// EA  : 0x8280F438
// RVA : 0x0080F438
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const idAngles *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 7;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 0xCu);
  v5 = this->numArgs + 3;
  this->argSize += 12;
  memcpy(Dst: &this->args[*(&this->numArgs + v5)], Src: val, Size: 0xCu);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXABVidQuat@@E@Z
// EA  : 0x8280F4E0
// RVA : 0x0080F4E0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const idQuat *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 6;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 0x10u);
  v5 = this->numArgs + 3;
  this->argSize += 16;
  *(idQuat *)&this->args[*(&this->numArgs + v5)] = *val;
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXABVidVec4@@E@Z
// EA  : 0x8280F588
// RVA : 0x0080F588
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const idVec4 *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 12;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 0x10u);
  v5 = this->numArgs + 3;
  this->argSize += 16;
  *(idVec4 *)&this->args[*(&this->numArgs + v5)] = *val;
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXABVidVec3@@E@Z
// EA  : 0x8280F630
// RVA : 0x0080F630
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const idVec3 *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 5;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 0xCu);
  v5 = this->numArgs + 3;
  this->argSize += 12;
  memcpy(Dst: &this->args[*(&this->numArgs + v5)], Src: val, Size: 0xCu);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAXHE@Z
// EA  : 0x8280F6D8
// RVA : 0x0080F6D8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, const int val, unsigned __int8 exType)
{
  int v5; // r4

  this->argTypes[this->numArgs] = 3;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 4u);
  v5 = this->numArgs + 3;
  this->argSize += 4;
  *(_DWORD *)&this->args[*(&this->numArgs + v5)] = val;
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$05@@QAAX_NE@Z
// EA  : 0x8280F778
// RVA : 0x0080F778
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<6>::AddArg(idVarArgs<6> *this, unsigned __int8 val, unsigned __int8 exType)
{
  int v5; // r4

  this->argTypes[this->numArgs] = 1;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<6>::Grow(this, newArgSize: 1u);
  v5 = this->numArgs + 3;
  ++this->argSize;
  this->args[*(&this->numArgs + v5)] = val;
  ++this->numArgs;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAPAX@Z
// EA  : 0x82839408
// RVA : 0x00839408
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, void **ptr)
{
  char v3; // r11
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  unsigned __int8 *v8; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 )
    return 0;
  v5 = this->argTypes[index];
  if ( v5 == 9 || v5 == 10 || (v7 = v5 != 11, v6 = 0, !v7) )
    v6 = 1;
  if ( v6 == 0 )
    return 0;
  v8 = &this->args[this->argOffsets[index]];
  *(_BYTE *)ptr = *v8;
  *(_WORD *)((char *)ptr + 1) = *(_WORD *)(v8 + 1);
  *((_BYTE *)ptr + 3) = v8[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAVidAngles@@@Z
// EA  : 0x828394B0
// RVA : 0x008394B0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, idAngles *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 7 )
    return 0;
  *val = *(idAngles *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAVidVec3@@@Z
// EA  : 0x82839540
// RVA : 0x00839540
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, idVec3 *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 5 )
    return 0;
  *val = *(idVec3 *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAM@Z
// EA  : 0x828395D0
// RVA : 0x008395D0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, float *val)
{
  char v3; // r10
  unsigned __int8 *v5; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 4 )
    return 0;
  v5 = &this->args[this->argOffsets[index]];
  *(_BYTE *)val = *v5;
  *(_WORD *)((char *)val + 1) = *(_WORD *)(v5 + 1);
  *((_BYTE *)val + 3) = v5[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAH@Z
// EA  : 0x82839650
// RVA : 0x00839650
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, int *val)
{
  char v3; // r10
  unsigned __int8 *v5; // r7

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 3 )
    return 0;
  v5 = &this->args[this->argOffsets[index]];
  *(_BYTE *)val = *v5;
  *(_WORD *)((char *)val + 1) = *(_WORD *)(v5 + 1);
  *((_BYTE *)val + 3) = v5[3];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAA_N@Z
// EA  : 0x828396D0
// RVA : 0x008396D0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, bool *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 1 )
    return 0;
  *val = this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetHandleArg@?$idVarArgs@$03@@QBA_NHAAHE@Z
// EA  : 0x82839738
// RVA : 0x00839738
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetHandleArg(idVarArgs<4> *this, const int index, int *val, unsigned __int8 type)
{
  char v4; // r10
  unsigned __int8 *v6; // r7

  if ( index < 0 || (v4 = 1, index >= this->numArgs) )
    v4 = 0;
  if ( v4 == 0 || this->argTypes[index] != type )
    return 0;
  v6 = &this->args[this->argOffsets[index]];
  *(_BYTE *)val = *v6;
  *(_WORD *)((char *)val + 1) = *(_WORD *)(v6 + 1);
  *((_BYTE *)val + 3) = v6[3];
  return 1;
}


// ========================================================================
// ?Equal@?$idVarArgs@$03@@IBA_NABV1@@Z
// EA  : 0x828397C0
// RVA : 0x008397C0
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::Equal(idVarArgs<4> *this, const idVarArgs<4> *other)
{
  int argSize; // r7
  idVarArgs<4> *argOffsets; // r11
  unsigned __int16 *v4; // r10
  int v5; // r6
  int v6; // r9
  unsigned __int8 *argTypes; // r11
  unsigned __int8 *v8; // r10
  int v9; // r6
  int v10; // r9
  unsigned __int8 *argExTypes; // r11
  unsigned __int8 *v12; // r10
  int v13; // r6
  int v14; // r9
  unsigned __int8 *args; // r10
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r8
  int v18; // r7
  unsigned __int8 v19; // r11

  if ( this->numArgs != other->numArgs )
    return 0;
  argSize = this->argSize;
  if ( argSize != other->argSize )
    return 0;
  argOffsets = (idVarArgs<4> *)this->argOffsets;
  v4 = other->argOffsets;
  do
  {
    v5 = *(unsigned __int8 *)v4;
    v6 = HIBYTE(argOffsets->numArgs) - v5;
    if ( HIBYTE(argOffsets->numArgs) != v5 )
      break;
    argOffsets = (idVarArgs<4> *)((char *)argOffsets + 1);
    v4 = (unsigned __int16 *)((char *)v4 + 1);
  }
  while ( argOffsets != (idVarArgs<4> *)this->argTypes );
  if ( v6 != 0 )
    return 0;
  argTypes = this->argTypes;
  v8 = other->argTypes;
  do
  {
    v9 = *v8;
    v10 = *argTypes - v9;
    if ( *argTypes != v9 )
      break;
    ++argTypes;
    ++v8;
  }
  while ( argTypes != this->argExTypes );
  if ( v10 != 0 )
    return 0;
  argExTypes = this->argExTypes;
  v12 = other->argExTypes;
  do
  {
    v13 = *v12;
    v14 = *argExTypes - v13;
    if ( *argExTypes != v13 )
      break;
    ++argExTypes;
    ++v12;
  }
  while ( argExTypes != &this->argExTypes[4] );
  if ( v14 != 0 )
    return 0;
  args = other->args;
  v16 = this->args;
  if ( this->argSize != 0 )
  {
    v17 = &v16[argSize];
    do
    {
      v18 = *args;
      v14 = *v16 - v18;
      if ( *v16 != v18 )
        break;
      ++v16;
      ++args;
    }
    while ( v16 != v17 );
  }
  v19 = 1;
  if ( v14 != 0 )
    return 0;
  return v19;
}


// ========================================================================
// ??1?$idVarArgs@$03@@QAA@XZ
// EA  : 0x82839AD8
// RVA : 0x00839AD8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::~idVarArgs<4>(idVarArgs<4> *this)
{
  unsigned __int8 *args; // r4

  args = this->args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    this->args = nullptr;
  }
  this->argSize = 0;
  this->buffSize = 0;
  this->numArgs = 0;
}


// ========================================================================
// ?Grow@?$idVarArgs@$03@@IAAXI@Z
// EA  : 0x82839B38
// RVA : 0x00839B38
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::Grow(idVarArgs<4> *this, const unsigned int newArgSize)
{
  unsigned int buffSize; // r10
  unsigned int v4; // r11
  int v5; // r28
  unsigned __int8 *v6; // r3
  unsigned __int8 *args; // r4
  unsigned __int8 *v8; // r29

  if ( newArgSize != 0 )
  {
    buffSize = this->buffSize;
    v4 = this->argSize + newArgSize;
    if ( v4 > buffSize )
    {
      v5 = 2 * buffSize;
      if ( 2 * buffSize <= v4 )
        v5 = this->argSize + newArgSize;
      v6 = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v5,
                                tag: TAG_AI_FSM,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      args = this->args;
      v8 = v6;
      if ( args != nullptr )
      {
        memcpy(Dst: v6, Src: args, Size: this->argSize);
        idMem::Free(this: &mem, ptr: this->args, align: ALIGN_16);
      }
      this->args = v8;
      this->buffSize = v5;
    }
  }
}


// ========================================================================
// ?Copy@?$idVarArgs@$03@@IAAXABV1@@Z
// EA  : 0x82839BD8
// RVA : 0x00839BD8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::Copy(idVarArgs<4> *this, const idVarArgs<4> *other)
{
  unsigned __int8 *v4; // r3

  if ( this != other )
  {
    idVarArgs<4>::~idVarArgs<4>(this);
    this->numArgs = other->numArgs;
    this->argSize = other->argSize;
    this->buffSize = other->buffSize;
    this->argOffsets[0] = other->argOffsets[0];
    this->argOffsets[1] = other->argOffsets[1];
    this->argOffsets[2] = other->argOffsets[2];
    this->argOffsets[3] = other->argOffsets[3];
    *(_WORD *)this->argTypes = *(_WORD *)other->argTypes;
    *(_WORD *)&this->argTypes[2] = *(_WORD *)&other->argTypes[2];
    *(_WORD *)this->argExTypes = *(_WORD *)other->argExTypes;
    *(_WORD *)&this->argExTypes[2] = *(_WORD *)&other->argExTypes[2];
    v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                              size: this->buffSize,
                              tag: TAG_AI_FSM,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    this->args = v4;
    memcpy(Dst: v4, Src: other->args, Size: this->argSize);
  }
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAXPBDE@Z
// EA  : 0x8283A588
// RVA : 0x0083A588
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, const char *val, unsigned __int8 exType)
{
  int v5; // r11
  size_t v6; // r30
  int v7; // r9

  v5 = 0;
  this->argTypes[this->numArgs] = 8;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  if ( *val != 0 )
  {
    do
      ++v5;
    while ( val[v5] != 0 );
  }
  v6 = v5 + 1;
  idVarArgs<4>::Grow(this, newArgSize: v5 + 1);
  v7 = this->numArgs + 3;
  this->argSize += v6;
  memcpy(Dst: &this->args[*(&this->numArgs + v7)], Src: val, Size: v6);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAXABVidAngles@@E@Z
// EA  : 0x8283A640
// RVA : 0x0083A640
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, const idAngles *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 7;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 0xCu);
  v5 = this->numArgs + 3;
  this->argSize += 12;
  memcpy(Dst: &this->args[*(&this->numArgs + v5)], Src: val, Size: 0xCu);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAXABVidVec3@@E@Z
// EA  : 0x8283A6E8
// RVA : 0x0083A6E8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, const idVec3 *val, unsigned __int8 exType)
{
  int v5; // r3

  this->argTypes[this->numArgs] = 5;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 0xCu);
  v5 = this->numArgs + 3;
  this->argSize += 12;
  memcpy(Dst: &this->args[*(&this->numArgs + v5)], Src: val, Size: 0xCu);
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAXME@Z
// EA  : 0x8283A790
// RVA : 0x0083A790
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, double val, unsigned __int8 exType, unsigned __int8 a4)
{
  int v5; // r4
  float v6; // [sp+7Ch] [+1Ch]

  v6 = val;
  this->argTypes[this->numArgs] = 4;
  this->argExTypes[this->numArgs] = a4;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 4u);
  v5 = this->numArgs + 3;
  this->argSize += 4;
  *(float *)&this->args[*(&this->numArgs + v5)] = v6;
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAXHE@Z
// EA  : 0x8283A828
// RVA : 0x0083A828
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, const int val, unsigned __int8 exType)
{
  int v5; // r4

  this->argTypes[this->numArgs] = 3;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 4u);
  v5 = this->numArgs + 3;
  this->argSize += 4;
  *(_DWORD *)&this->args[*(&this->numArgs + v5)] = val;
  ++this->numArgs;
}


// ========================================================================
// ?AddArg@?$idVarArgs@$03@@QAAX_NE@Z
// EA  : 0x8283A8C8
// RVA : 0x0083A8C8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddArg(idVarArgs<4> *this, unsigned __int8 val, unsigned __int8 exType)
{
  int v5; // r4

  this->argTypes[this->numArgs] = 1;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 1u);
  v5 = this->numArgs + 3;
  ++this->argSize;
  this->args[*(&this->numArgs + v5)] = val;
  ++this->numArgs;
}


// ========================================================================
// ?AddHandleArg@?$idVarArgs@$03@@QAAXHEE@Z
// EA  : 0x8283A968
// RVA : 0x0083A968
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

void __fastcall idVarArgs<4>::AddHandleArg(
        idVarArgs<4> *this,
        const int val,
        unsigned __int8 type,
        unsigned __int8 exType)
{
  int v6; // r4

  this->argTypes[this->numArgs] = type;
  this->argExTypes[this->numArgs] = exType;
  this->argOffsets[this->numArgs] = this->argSize;
  idVarArgs<4>::Grow(this, newArgSize: 4u);
  v6 = 2 * (this->numArgs + 3);
  this->argSize += 4;
  *(_DWORD *)&this->args[*(unsigned __int16 *)((char *)&this->numArgs + v6)] = val;
  ++this->numArgs;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAPBD@Z
// EA  : 0x82D60060
// RVA : 0x00D60060
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, const char **val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 8 )
    return 0;
  *val = (const char *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAVidQuat@@@Z
// EA  : 0x82D600C8
// RVA : 0x00D600C8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, idQuat *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 6 )
    return 0;
  *val = *(idQuat *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAVidVec4@@@Z
// EA  : 0x82D60158
// RVA : 0x00D60158
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, idVec4 *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 12 )
    return 0;
  *val = *(idVec4 *)&this->args[this->argOffsets[index]];
  return 1;
}


// ========================================================================
// ?GetArg@?$idVarArgs@$03@@QBA_NHAAD@Z
// EA  : 0x82D601E8
// RVA : 0x00D601E8
// PDB : w:\tech5\shared\idlib\varargs.h
// ========================================================================

int __fastcall idVarArgs<4>::GetArg(idVarArgs<4> *this, const int index, char *val)
{
  char v3; // r10

  if ( index < 0 || (v3 = 1, index >= this->numArgs) )
    v3 = 0;
  if ( v3 == 0 || this->argTypes[index] != 2 )
    return 0;
  *val = this->args[this->argOffsets[index]];
  return 1;
}

