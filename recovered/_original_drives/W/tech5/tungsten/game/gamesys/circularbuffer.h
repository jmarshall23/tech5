
// ========================================================================
// ?Add@?$idCircularBuffer@VidVec3@@$04@@QAAHABVidVec3@@@Z
// EA  : 0x82C46FF8
// RVA : 0x00C46FF8
// PDB : w:\tech5\tungsten\game\gamesys\circularbuffer.h
// ========================================================================

int __fastcall idCircularBuffer<idVec3,5>::Add(idCircularBuffer<idVec3,5> *this, const idVec3 *obj)
{
  int result; // r3
  int v4; // r10
  int v5; // r10

  result = (this->num + this->head) % 5;
  this->buffer[result] = *obj;
  v4 = this->num + 1;
  this->num = v4;
  if ( v4 >= 5 )
  {
    v5 = this->head + 1;
    this->num = 5;
    this->head = v5 % 5;
  }
  return result;
}


// ========================================================================
// ?Add@?$idCircularBuffer@VCommand@idSpawnManager@@$0IA@@@QAAHABVCommand@idSpawnManager@@@Z
// EA  : 0x82EA60A8
// RVA : 0x00EA60A8
// PDB : w:\tech5\tungsten\game\gamesys\circularbuffer.h
// ========================================================================

int __fastcall idCircularBuffer<idSpawnManager::Command,128>::Add(
        idCircularBuffer<idSpawnManager::Command,128> *this,
        const idSpawnManager::Command *obj)
{
  int v3; // r10
  int result; // r3
  idSpawnManager::Command *v5; // r9
  int v6; // r10
  int v7; // r10

  v3 = this->num + this->head;
  v5 = &this->buffer[v3 % 128];
  result = v3 % 128;
  *v5 = *obj;
  v6 = this->num + 1;
  this->num = v6;
  if ( v6 >= 128 )
  {
    v7 = this->head + 1;
    this->num = 128;
    this->head = v7 % 128;
  }
  return result;
}


// ========================================================================
// ??0?$idCircularBuffer@VCommand@idSpawnManager@@$0IA@@@QAA@XZ
// EA  : 0x82EA6260
// RVA : 0x00EA6260
// PDB : w:\tech5\tungsten\game\gamesys\circularbuffer.h
// ========================================================================

idCircularBuffer<idSpawnManager::Command,128> *__fastcall idCircularBuffer<idSpawnManager::Command,128>::idCircularBuffer<idSpawnManager::Command,128>(
        idCircularBuffer<idSpawnManager::Command,128> *this)
{
  _DWORD *v2; // r11
  int i; // ctr

  v2 = (_DWORD *)((char *)this - 4);
  for ( i = 128; i != 0; --i )
  {
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    v2 += 4;
    *v2 = 0;
  }
  this->num = 0;
  this->head = 0;
  memset(Dst: this, Val: 0, Size: 0x800u);
  return this;
}

