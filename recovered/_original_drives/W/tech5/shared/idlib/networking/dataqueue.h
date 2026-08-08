
// ========================================================================
// ?RemoveOlderThan@?$idDataQueue@$0DP@$0BPEA@@@QAAXH@Z
// EA  : 0x8289B830
// RVA : 0x0089B830
// PDB : w:\tech5\shared\idlib\networking\dataqueue.h
// ========================================================================

void __fastcall idDataQueue<63,8000>::RemoveOlderThan(idDataQueue<63,8000> *this, int sequence)
{
  int v3; // r30
  int num; // r11
  int v5; // r11
  int v6; // r10
  int v7; // r9
  idDataQueue<63,8000>::msgItem_t *v8; // r11
  int dataLength; // r11
  int v10; // r8
  int v11; // r9
  idDataQueue<63,8000>::msgItem_t *list; // r10
  int v13; // r11
  idDataQueue<63,8000>::msgItem_t *v14; // r5

  v3 = 0;
  while ( this->items.num > 0 )
  {
    if ( this->items.list->sequence >= sequence )
      break;
    num = this->items.num;
    v3 += this->items.list->length;
    if ( num > 0 )
    {
      v5 = num - 1;
      v6 = 0;
      this->items.num = v5;
      if ( v5 > 0 )
      {
        v7 = 0;
        do
        {
          ++v6;
          v8 = &this->items.list[v7++];
          v8->sequence = v8[1].sequence;
          v8->length = v8[1].length;
          v8->dataOffset = v8[1].dataOffset;
        }
        while ( v6 < this->items.num );
      }
    }
  }
  dataLength = this->dataLength;
  if ( v3 < dataLength )
  {
    if ( v3 > 0 )
    {
      memmove(Dst: this->data, Src: &this->data[v3], Size: dataLength - v3);
      this->dataLength -= v3;
    }
  }
  else
  {
    this->dataLength = 0;
  }
  v10 = 0;
  v11 = 0;
  if ( this->items.num > 0 )
  {
    list = this->items.list;
    v13 = 0;
    do
    {
      list->dataOffset = v10;
      ++v11;
      v14 = &this->items.list[v13++];
      list = &this->items.list[v13];
      v10 += v14->length;
    }
    while ( v11 < this->items.num );
  }
}


// ========================================================================
// ?Append@?$idDataQueue@$0DP@$0BPEA@@@QAA_NHPBEH0H@Z
// EA  : 0x8289C590
// RVA : 0x0089C590
// PDB : w:\tech5\shared\idlib\networking\dataqueue.h
// ========================================================================

int __fastcall idDataQueue<63,8000>::Append(
        idDataQueue<63,8000> *this,
        const char *sequence,
        const unsigned __int8 *b1,
        size_t b1Len,
        const unsigned __int8 *b2,
        size_t b2Len)
{
  presentableObject_t *v13; // r3
  int v14; // r11

  if ( this->items.num == this->items.size || (int)(this->dataLength + b1Len + b2Len) >= 8000 )
    return 0;
  v13 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc((idList<presentableObject_t,5> *)this);
  v13->name = sequence;
  v13->presentableIndex = b1Len + b2Len;
  *(_DWORD *)&v13->skipReplication = this->dataLength;
  memcpy(Dst: &this->data[this->dataLength], Src: b1, Size: b1Len);
  v14 = this->dataLength + b1Len;
  this->dataLength = v14;
  memcpy(Dst: &this->data[v14], Src: b2, Size: b2Len);
  this->dataLength += b2Len;
  return 1;
}


// ========================================================================
// ?RemoveOlderThan@?$idDataQueue@$0EA@$0BAAAA@@@QAAXH@Z
// EA  : 0x828A1D30
// RVA : 0x008A1D30
// PDB : w:\tech5\shared\idlib\networking\dataqueue.h
// ========================================================================

void __fastcall idDataQueue<64,65536>::RemoveOlderThan(idDataQueue<64,65536> *this, int sequence)
{
  int v3; // r30
  int num; // r11
  int v5; // r11
  int v6; // r10
  int v7; // r9
  idDataQueue<64,65536>::msgItem_t *v8; // r11
  int dataLength; // r11
  int v10; // r8
  int v11; // r9
  idDataQueue<64,65536>::msgItem_t *list; // r10
  int v13; // r11
  idDataQueue<64,65536>::msgItem_t *v14; // r5

  v3 = 0;
  while ( this->items.num > 0 )
  {
    if ( this->items.list->sequence >= sequence )
      break;
    num = this->items.num;
    v3 += this->items.list->length;
    if ( num > 0 )
    {
      v5 = num - 1;
      v6 = 0;
      this->items.num = v5;
      if ( v5 > 0 )
      {
        v7 = 0;
        do
        {
          ++v6;
          v8 = &this->items.list[v7++];
          v8->sequence = v8[1].sequence;
          v8->length = v8[1].length;
          v8->dataOffset = v8[1].dataOffset;
        }
        while ( v6 < this->items.num );
      }
    }
  }
  dataLength = this->dataLength;
  if ( v3 < dataLength )
  {
    if ( v3 > 0 )
    {
      memmove(Dst: this->data, Src: &this->data[v3], Size: dataLength - v3);
      this->dataLength -= v3;
    }
  }
  else
  {
    this->dataLength = 0;
  }
  v10 = 0;
  v11 = 0;
  if ( this->items.num > 0 )
  {
    list = this->items.list;
    v13 = 0;
    do
    {
      list->dataOffset = v10;
      ++v11;
      v14 = &this->items.list[v13++];
      list = &this->items.list[v13];
      v10 += v14->length;
    }
    while ( v11 < this->items.num );
  }
}


// ========================================================================
// ?Append@?$idDataQueue@$0EA@$0BAAAA@@@QAA_NHPBEH0H@Z
// EA  : 0x828A2790
// RVA : 0x008A2790
// PDB : w:\tech5\shared\idlib\networking\dataqueue.h
// ========================================================================

int __fastcall idDataQueue<64,65536>::Append(
        idDataQueue<64,65536> *this,
        const char *sequence,
        const unsigned __int8 *b1,
        size_t b1Len,
        const unsigned __int8 *b2,
        size_t b2Len)
{
  presentableObject_t *v13; // r3
  int v14; // r11

  if ( this->items.num == this->items.size || (int)(this->dataLength + b1Len + b2Len) >= 0x10000 )
    return 0;
  v13 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc((idList<presentableObject_t,5> *)this);
  v13->name = sequence;
  v13->presentableIndex = b1Len + b2Len;
  *(_DWORD *)&v13->skipReplication = this->dataLength;
  memcpy(Dst: &this->data[this->dataLength], Src: b1, Size: b1Len);
  v14 = this->dataLength + b1Len;
  this->dataLength = v14;
  memcpy(Dst: &this->data[v14], Src: b2, Size: b2Len);
  this->dataLength += b2Len;
  return 1;
}

