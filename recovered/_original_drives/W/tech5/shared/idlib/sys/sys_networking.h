
// ========================================================================
// ?Serialize@idSimpleSerializer@@QAA_NAAE@Z
// EA  : 0x829C0EB0
// RVA : 0x009C0EB0
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

int __fastcall idSimpleSerializer::Serialize(idSimpleSerializer *this, unsigned __int8 *value)
{
  int pos; // r11

  pos = this->pos;
  if ( pos + 1 > this->size )
    return 0;
  if ( this->writing )
    this->data[pos] = *value;
  else
    *value = this->data[pos];
  ++this->pos;
  return 1;
}


// ========================================================================
// ?Serialize@idSimpleSerializer@@QAA_NAAH@Z
// EA  : 0x829C0F18
// RVA : 0x009C0F18
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

int __fastcall idSimpleSerializer::Serialize(idSimpleSerializer *this, unsigned int *value)
{
  int pos; // r11
  unsigned __int8 v4; // r7
  unsigned __int8 v5; // r6
  unsigned int v6; // r5
  unsigned __int8 *data; // r4
  int v8; // r11
  unsigned __int8 *v9; // r10
  int v10; // r11
  unsigned __int8 *v11; // r9
  int v12; // r11
  int v13; // r11
  int v14; // r11
  int v15; // r11
  unsigned __int8 *v16; // r5

  pos = this->pos;
  if ( pos + 4 > this->size )
    return 0;
  if ( this->writing )
  {
    v4 = BYTE2(*value);
    v5 = BYTE1(*value);
    v6 = HIBYTE(*value);
    this->data[pos] = *value;
    data = this->data;
    v8 = this->pos + 1;
    this->pos = v8;
    data[v8] = v4;
    v9 = this->data;
    v10 = this->pos + 1;
    this->pos = v10;
    v9[v10] = v5;
    v11 = this->data;
    v12 = this->pos + 1;
    this->pos = v12;
    v11[v12] = v6;
  }
  else
  {
    *value = this->data[pos];
    v13 = this->pos + 1;
    this->pos = v13;
    *value |= __ROL4__(this->data[v13], 8);
    v14 = this->pos + 1;
    this->pos = v14;
    *value |= __ROL4__(this->data[v14], 16);
    v15 = this->pos + 1;
    v16 = this->data;
    this->pos = v15;
    *value |= __ROR4__(v16[v15], 8);
  }
  ++this->pos;
  return 1;
}


// ========================================================================
// ?SerializeBytes@idSimpleSerializer@@QAA_NPADAAH@Z
// EA  : 0x829C1038
// RVA : 0x009C1038
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

int __fastcall idSimpleSerializer::SerializeBytes(idSimpleSerializer *this, char *data, unsigned int *numBytes)
{
  int v4; // r30
  int v8; // r10
  int pos; // r11
  char v10; // r11

  v4 = *numBytes;
  idSimpleSerializer::Serialize(this, value: numBytes);
  if ( this->writing || (int)(*numBytes + 1) <= v4 )
  {
    v8 = 0;
    if ( (int)*numBytes <= 0 )
    {
      return 1;
    }
    else
    {
      while ( 1 )
      {
        pos = this->pos;
        if ( pos + 1 <= this->size )
        {
          if ( this->writing )
            this->data[pos] = data[v8];
          else
            data[v8] = this->data[pos];
          v10 = 1;
          ++this->pos;
        }
        else
        {
          v10 = 0;
        }
        if ( v10 == 0 )
          break;
        if ( ++v8 >= (int)*numBytes )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    *numBytes = 0;
    return 0;
  }
}


// ========================================================================
// ?SerializeString@idSimpleSerializer@@QAA_NPADH@Z
// EA  : 0x829C1128
// RVA : 0x009C1128
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

int __fastcall idSimpleSerializer::SerializeString(
        idSimpleSerializer *this,
        char *data,
        int maxSize,
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
        int a14,
        int a15,
        int a16)
{
  BOOL writing; // r11
  char *v19; // r11
  int v20; // r10

  writing = this->writing;
  a16 = maxSize;
  if ( writing )
  {
    v19 = data;
    do
      v20 = (unsigned __int8)*v19++;
    while ( v20 != 0 );
    a16 = v19 - data - 1;
  }
  if ( (unsigned __int8)idSimpleSerializer::SerializeBytes(this, data, numBytes: (unsigned int *)&a16) == 0 )
    return 0;
  if ( !this->writing )
    data[a16] = 0;
  return 1;
}


// ========================================================================
// ?WriteDataBlock@idTCP@@QAA_NPADHH@Z
// EA  : 0x829C11D0
// RVA : 0x009C11D0
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

BOOL __fastcall idTCP::WriteDataBlock(
        idTCP *this,
        char *buffer,
        int size,
        int timeoutMS,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16)
{
  int pos; // r31
  int v20; // r5
  _BYTE v22[16]; // [sp+50h] [-50h] BYREF
  idSimpleSerializer v23; // [sp+60h] [-40h] BYREF

  a16 = size;
  v23.data = v22;
  v23.size = 4;
  v23.writing = true;
  v23.pos = 0;
  idSimpleSerializer::Serialize(this: &v23, value: (unsigned int *)&a16);
  pos = v23.pos;
  v20 = v23.pos;
  if ( !v23.writing )
  {
    v20 = v23.size;
    pos = v23.size;
  }
  return idTCP::WriteBlocking(this, data: v22, size: v20, timeoutMS) == pos
      && (_cntlzw(a16 - idTCP::WriteBlocking(this, data: buffer, size: a16, timeoutMS)) & 0x20) != 0;
}


// ========================================================================
// ?ReadDataBlock@idTCP@@QAAHPADHH@Z
// EA  : 0x829C1288
// RVA : 0x009C1288
// PDB : w:\tech5\shared\idlib\sys\sys_networking.h
// ========================================================================

int __fastcall idTCP::ReadDataBlock(idTCP *this, char *buffer, int bufferSize, int timeoutMS)
{
  int v9; // r31
  int v10; // [sp+50h] [-50h] BYREF
  _BYTE v11[12]; // [sp+54h] [-4Ch] BYREF
  idSimpleSerializer v12; // [sp+60h] [-40h] BYREF

  if ( idTCP::ReadBlocking(this, data: v11, size: 4, timeoutMS) == 4 )
  {
    v12.writing = false;
    v12.data = v11;
    v12.size = 4;
    v12.pos = 0;
    v10 = 0;
    idSimpleSerializer::Serialize(this: &v12, value: (unsigned int *)&v10);
    v9 = v10;
    if ( v10 <= bufferSize )
    {
      if ( idTCP::ReadBlocking(this, data: buffer, size: v10, timeoutMS) == v9 )
      {
        return v9;
      }
      else
      {
        printf(format: "ReadDataBlock: bytesRead != msgSize\n");
        return -1;
      }
    }
    else
    {
      printf(format: "ReadDataBlock: buffer not large enough %i/%i\n", v10, bufferSize);
      return -1;
    }
  }
  else
  {
    printf(format: "ReadDataBlock: Failed to read packet size\n");
    return -1;
  }
}

