
// ========================================================================
// ?Timestamp@idFile_Memory@@UBAIXZ
// EA  : 0x825AF7E8
// RVA : 0x005AF7E8
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile_Memory::Timestamp(idFile_Memory *this)
{
  return this->timestamp;
}


// ========================================================================
// ??YidFile_String@@QAAPBDPBD@Z
// EA  : 0x825AF7F0
// RVA : 0x005AF7F0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

char *__fastcall idFile_String::operator+=(idFile_String *this, const char *str)
{
  int v3; // r5

  v3 = 0;
  if ( *str != 0 )
  {
    do
      ++v3;
    while ( str[v3] != 0 );
  }
  ((void (__fastcall *)(idFile_String *))this->Write)(a1: this);
  return this->filePtr;
}


// ========================================================================
// ??$ReadLittle@M@idFile@@QAAIAAM@Z
// EA  : 0x825B0148
// RVA : 0x005B0148
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::ReadLittle<float>(idFile *this, int *c)
{
  unsigned int result; // r3
  char v4; // r8
  char v5; // r7
  char v6; // r6

  result = this->Read(this, a2: c, a3: 4u);
  v4 = *((_BYTE *)c + 3);
  v5 = *((_BYTE *)c + 1);
  v6 = *((_BYTE *)c + 2);
  *((_BYTE *)c + 3) = *(_BYTE *)c;
  *(_BYTE *)c = v4;
  *((_BYTE *)c + 2) = v5;
  *((_BYTE *)c + 1) = v6;
  return result;
}


// ========================================================================
// ??$WriteLittle@H@idFile@@QAAIABH@Z
// EA  : 0x825B01A8
// RVA : 0x005B01A8
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::WriteLittle<int>(idFile *this, int *c)
{
  idFile_vtbl *v2; // r10
  char v3; // r7
  char v4; // r9
  int v6; // [sp+50h] [-10h] BYREF

  v2 = this->__vftable;
  v6 = *c;
  v3 = BYTE1(v6);
  v4 = HIBYTE(v6);
  BYTE1(v6) = BYTE2(v6);
  HIBYTE(v6) = v6;
  LOBYTE(v6) = v4;
  BYTE2(v6) = v3;
  return v2->Write(this, a2: &v6, a3: 4u);
}


// ========================================================================
// ?ReadString@idFile@@QAAIAAVidStr@@@Z
// EA  : 0x825B13F0
// RVA : 0x005B13F0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

int __fastcall idFile::ReadString(idFile *this, idStr *string)
{
  idFile_vtbl *v2; // r11
  int v5; // r28
  char v6; // r8
  char v7; // r7
  size_t v8; // r27
  char *data; // r3
  signed int v11; // [sp+50h] [-40h] BYREF

  v2 = this->__vftable;
  v11 = 0;
  v5 = v2->Read(this, a2: &v11, a3: 4u);
  v6 = BYTE1(v11);
  v7 = v11;
  BYTE1(v11) = BYTE2(v11);
  LOBYTE(v11) = HIBYTE(v11);
  BYTE2(v11) = v6;
  HIBYTE(v11) = v7;
  if ( v11 <= 0 )
  {
    idStr::EnsureAlloced(this: string, amount: 1, keepold: true, geometricGrowth: false);
    *string->data = 0;
    string->len = 0;
    return v5;
  }
  else
  {
    v8 = v11;
    idStr::EnsureAlloced(this: string, amount: v11 + 1, keepold: true, geometricGrowth: false);
    data = string->data;
    string->len = v8;
    memset(Dst: data, Val: 32, Size: v8);
    string->data[string->len] = 0;
    return this->Read(this, a2: string->data, a3: v11) + v5;
  }
}


// ========================================================================
// ?WriteString@idFile@@QAAIABVidStr@@@Z
// EA  : 0x825B14D8
// RVA : 0x005B14D8
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::WriteString(idFile *this, const idStr *string)
{
  idFile_vtbl *v3; // r10
  char v5; // r7
  char v6; // r9
  int v7; // r29
  int len; // [sp+50h] [-30h] BYREF

  v3 = this->__vftable;
  len = string->len;
  v5 = BYTE1(len);
  v6 = HIBYTE(len);
  BYTE1(len) = BYTE2(len);
  HIBYTE(len) = len;
  LOBYTE(len) = v6;
  BYTE2(len) = v5;
  v7 = v3->Write(this, a2: &len, a3: 4u);
  return this->Write(this, a2: string->data, a3: string->len) + v7;
}


// ========================================================================
// ?ReadString@idFile@@QAAIAAVidAtomicString@@@Z
// EA  : 0x826377A8
// RVA : 0x006377A8
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

int __fastcall idFile::ReadString(idFile *this, idAtomicString *string)
{
  int v3; // r29
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  v5[0].len = 0;
  v5[0].allocedAndFlag = 20;
  v5[0].data = v5[0].baseBuffer;
  v5[0].baseBuffer[0] = 0;
  v3 = idFile::ReadString(this, string: v5);
  idAtomicString::Set(this: string, str_: v5[0].data);
  idStr::FreeData(this: v5);
  return v3;
}


// ========================================================================
// __unwind$225229
// EA  : 0x82637804
// RVA : 0x00637804
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

void _unwind_225229()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?WriteString@idFile@@QAAIPBD@Z
// EA  : 0x82637830
// RVA : 0x00637830
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

int __fastcall idFile::WriteString(idFile *this, const char *string)
{
  idFile_vtbl *v4; // r10
  int v6; // r11
  unsigned int v7; // r31
  idFile_vtbl *v8; // r8
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  int v10; // r28
  unsigned int v11; // [sp+50h] [-30h] BYREF
  unsigned int v12; // [sp+54h] [-2Ch] BYREF

  if ( string != nullptr )
  {
    v6 = *(unsigned __int8 *)string;
    v7 = 0;
    v11 = 0;
    if ( v6 != 0 )
    {
      do
        ++v7;
      while ( string[v7] != 0 );
      v11 = v7;
    }
    v12 = v7;
    v8 = this->__vftable;
    HIBYTE(v12) = v11;
    LOBYTE(v12) = HIBYTE(v11);
    Write = v8->Write;
    BYTE2(v12) = BYTE1(v7);
    BYTE1(v12) = BYTE2(v7);
    v10 = Write(this, a2: &v12, a3: 4u);
    return this->Write(this, a2: string, a3: v7) + v10;
  }
  else
  {
    v4 = this->__vftable;
    v11 = 0;
    return v4->Write(this, a2: &v11, a3: 4u);
  }
}


// ========================================================================
// ??1idFile@@UAA@XZ
// EA  : 0x82697FB0
// RVA : 0x00697FB0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

void __fastcall idFile::~idFile(idFile *this)
{
  this->__vftable = (idFile_vtbl *)&idFile::`vftable';
}


// ========================================================================
// ??0idFile_Stat@@QAA@PBD_JI@Z
// EA  : 0x826986F0
// RVA : 0x006986F0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

idFile_Stat *__fastcall idFile_Stat::idFile_Stat(
        idFile_Stat *this,
        const char *name,
        __int64 size,
        unsigned int timeStamp)
{
  __int64 v6; // r28

  v6 = __PAIR64__(size, HIDWORD(size));
  idFile::idFile(this);
  this->__vftable = (idFile_Stat_vtbl *)&idFile_Stat::`vftable';
  idStr::idStr(this: &this->fileName, text: name);
  this->fileSize = v6;
  this->fileTimestamp = HIDWORD(v6);
  return this;
}


// ========================================================================
// __unwind$246619
// EA  : 0x82698744
// RVA : 0x00698744
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

void _unwind_246619()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 128 + 148));
}


// ========================================================================
// ?Length@idFile_Stat@@UBA_JXZ
// EA  : 0x82698770
// RVA : 0x00698770
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_Stat::Length(idFile_Stat *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->fileSize;
  return result;
}


// ========================================================================
// ??$WriteLittle@VidBounds@@@idFile@@QAAIABVidBounds@@@Z
// EA  : 0x826BBD60
// RVA : 0x006BBD60
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::WriteLittle<idBounds>(idFile *this, const idBounds *c)
{
  char *v2; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  char *v5; // r11
  int j; // ctr
  char v7; // r9
  char v8; // r8
  char v9; // r7
  char v11; // [sp+4Ch] [-24h] BYREF
  char v12; // [sp+4Eh] [-22h] BYREF
  _BYTE v13[24]; // [sp+50h] [-20h] BYREF

  v2 = &v11;
  p_z = (_DWORD *)&c[-1].b[1].z;
  for ( i = 6; i != 0; --i )
  {
    ++p_z;
    v2 += 4;
    *(_DWORD *)v2 = *p_z;
  }
  v5 = &v12;
  for ( j = 6; j != 0; --j )
  {
    v7 = v5[5];
    v8 = v5[4];
    v9 = v5[3];
    v5[5] = v5[2];
    v5[2] = v7;
    v5[3] = v8;
    v5 += 4;
    *v5 = v9;
  }
  return this->Write(this, a2: v13, a3: 24u);
}


// ========================================================================
// ??$WriteLittle@VidVec3@@@idFile@@QAAIABVidVec3@@@Z
// EA  : 0x826BBDE0
// RVA : 0x006BBDE0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::WriteLittle<idVec3>(idFile *this, const idVec3 *c)
{
  float y; // r8
  char *v3; // r11
  float z; // r7
  int v5; // ctr
  char v6; // r9
  char v7; // r8
  char v8; // r7
  char v10; // [sp+4Eh] [-22h] BYREF
  _DWORD v11[6]; // [sp+50h] [-20h] BYREF

  y = c->y;
  v3 = &v10;
  z = c->z;
  v11[0] = LODWORD(c->x);
  v5 = 3;
  *(float *)&v11[1] = y;
  *(float *)&v11[2] = z;
  do
  {
    v6 = v3[5];
    v7 = v3[4];
    v8 = v3[3];
    v3[5] = v3[2];
    v3[2] = v6;
    v3[3] = v7;
    v3 += 4;
    *v3 = v8;
    --v5;
  }
  while ( v5 != 0 );
  return this->Write(this, a2: v11, a3: 12u);
}


// ========================================================================
// ??$ReadLittle@VidBounds@@@idFile@@QAAIAAVidBounds@@@Z
// EA  : 0x826BBE60
// RVA : 0x006BBE60
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::ReadLittle<idBounds>(idFile *this, idBounds *c)
{
  unsigned int result; // r3
  char *v4; // r11
  int i; // ctr
  char v6; // r9
  char v7; // r8
  char v8; // r7

  result = this->Read(this, a2: c, a3: 24u);
  v4 = (char *)&c[-1].b[1].z + 2;
  for ( i = 6; i != 0; --i )
  {
    v6 = v4[5];
    v7 = v4[4];
    v8 = v4[3];
    v4[5] = v4[2];
    v4[2] = v6;
    v4[3] = v7;
    v4 += 4;
    *v4 = v8;
  }
  return result;
}


// ========================================================================
// ??$ReadLittle@VidVec3@@@idFile@@QAAIAAVidVec3@@@Z
// EA  : 0x826BBED0
// RVA : 0x006BBED0
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::ReadLittle<idVec3>(idFile *this, idVec3 *c)
{
  unsigned int result; // r3
  char *v4; // r11
  int i; // ctr
  char v6; // r9
  char v7; // r8
  char v8; // r7

  result = this->Read(this, a2: c, a3: 12u);
  v4 = (char *)&c[-1].z + 2;
  for ( i = 3; i != 0; --i )
  {
    v6 = v4[5];
    v7 = v4[4];
    v8 = v4[3];
    v4[5] = v4[2];
    v4[2] = v6;
    v4[3] = v7;
    v4 += 4;
    *v4 = v8;
  }
  return result;
}


// ========================================================================
// ??1idFile_BitMsg@@UAA@XZ
// EA  : 0x827F2A28
// RVA : 0x007F2A28
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

void __fastcall idFile_BitMsg::~idFile_BitMsg(idFile_BitMsg *this)
{
  this->__vftable = (idFile_BitMsg_vtbl *)&idFile_BitMsg::`vftable';
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_BitMsg_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$235292_0
// EA  : 0x827F2A80
// RVA : 0x007F2A80
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

void _unwind_235292_0()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// ??$ReadLittle@G@idFile@@QAAIAAG@Z
// EA  : 0x828C71E8
// RVA : 0x008C71E8
// PDB : w:\tech5\shared\idlib\filesystem\file.h
// ========================================================================

unsigned int __fastcall idFile::ReadLittle<unsigned short>(idFile *this, unsigned __int16 *c)
{
  unsigned int result; // r3
  char v4; // r8

  result = this->Read(this, a2: c, a3: 2u);
  v4 = *((_BYTE *)c + 1);
  *((_BYTE *)c + 1) = *(_BYTE *)c;
  *(_BYTE *)c = v4;
  return result;
}

