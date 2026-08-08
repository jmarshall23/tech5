
// ========================================================================
// ?UpdateOutgoingRate@idPacketProcessor@@QAAXHH@Z
// EA  : 0x8289AFF8
// RVA : 0x0089AFF8
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPacketProcessor::UpdateOutgoingRate(idPacketProcessor *this, int time, __int64 size)
{
  int outgoingRateTime; // r10
  int v4; // r8
  double v5; // fp7
  int v6; // r7
  double outgoingRateBytes; // fp0
  signed int v8; // r11
  int v9; // r9

  LODWORD(size) = 0;
  outgoingRateTime = this->outgoingRateTime;
  v4 = HIDWORD(size) + this->outgoingBytes;
  this->outgoingBytes = v4;
  if ( time > outgoingRateTime )
  {
    LODWORD(size) = time - outgoingRateTime;
    v5 = (float)-(float)((float)((float)((float)size * this->outgoingRateBytes) * (float)0.001) - this->outgoingRateBytes);
    this->outgoingRateBytes = -(float)((float)((float)((float)size * this->outgoingRateBytes) * (float)0.001)
                                     - this->outgoingRateBytes);
    if ( v5 < 0.0 )
      this->outgoingRateBytes = 0.0;
  }
  v6 = HIDWORD(size);
  outgoingRateBytes = this->outgoingRateBytes;
  this->outgoingRateTime = time;
  v8 = time - this->lastOutgoingRateTime;
  this->outgoingRateBytes = (float)*(__int64 *)((char *)&size - 4) + (float)outgoingRateBytes;
  if ( v8 > 250 )
  {
    this->lastOutgoingRateTime = time;
    __twllei(v8, 0);
    time = this->lastOutgoingBytes;
    this->lastOutgoingBytes = v4;
    v9 = 1000 * (v4 - time);
    this->currentOutgoingRate = v9 / v8;
    __twlgei(v8 & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
  }
  if ( HIDWORD(size) != 0 )
    idGaugeMetric::Log(this: &this->outgoingPacketSize, x: (float)*(__int64 *)((char *)&size - 4), skipPush: time);
}


// ========================================================================
// ?UpdateIncomingRate@idPacketProcessor@@QAAXHH@Z
// EA  : 0x8289B130
// RVA : 0x0089B130
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPacketProcessor::UpdateIncomingRate(idPacketProcessor *this, int time, __int64 size)
{
  int incomingRateTime; // r10
  int v4; // r8
  double v5; // fp7
  int v6; // r7
  double incomingRateBytes; // fp0
  signed int v8; // r11
  int v9; // r9

  LODWORD(size) = 0;
  incomingRateTime = this->incomingRateTime;
  v4 = HIDWORD(size) + this->incomingBytes;
  this->incomingBytes = v4;
  if ( time > incomingRateTime )
  {
    LODWORD(size) = time - incomingRateTime;
    v5 = (float)-(float)((float)((float)((float)size * this->incomingRateBytes) * (float)0.001) - this->incomingRateBytes);
    this->incomingRateBytes = -(float)((float)((float)((float)size * this->incomingRateBytes) * (float)0.001)
                                     - this->incomingRateBytes);
    if ( v5 < 0.0 )
      this->incomingRateBytes = 0.0;
  }
  v6 = HIDWORD(size);
  incomingRateBytes = this->incomingRateBytes;
  this->incomingRateTime = time;
  v8 = time - this->lastIncomingRateTime;
  this->incomingRateBytes = (float)*(__int64 *)((char *)&size - 4) + (float)incomingRateBytes;
  if ( v8 > 250 )
  {
    this->lastIncomingRateTime = time;
    __twllei(v8, 0);
    time = this->lastIncomingBytes;
    this->lastIncomingBytes = v4;
    v9 = 1000 * (v4 - time);
    this->currentIncomingRate = v9 / v8;
    __twlgei(v8 & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
  }
  if ( HIDWORD(size) != 0 )
    idGaugeMetric::Log(this: &this->incomingPacketSize, x: (float)*(__int64 *)((char *)&size - 4), skipPush: time);
}


// ========================================================================
// ?CanSendMoreData@idPacketProcessor@@QBA_NXZ
// EA  : 0x8289B380
// RVA : 0x0089B380
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

BOOL __fastcall idPacketProcessor::CanSendMoreData(idPacketProcessor *this)
{
  __int64 v2; // r9

  if ( net_maxRate.valueInteger == 0 )
    return true;
  LODWORD(v2) = net_maxRate.valueInteger << 10;
  HIDWORD(v2) = 33360;
  return this->outgoingRateBytes <= (double)(float)v2;
}


// ========================================================================
// ?GetSendFragment@idPacketProcessor@@QAA_NHGAAVidBitMsg@@_N@Z
// EA  : 0x8289B3D8
// RVA : 0x0089B3D8
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::GetSendFragment(
        idPacketProcessor *this,
        int time,
        unsigned __int16 sessionID,
        idBitMsg *outMsg,
        __int64 useBackend)
{
  idBitMsg *p_unsentMsg; // r29
  __int64 v11; // r26
  int curSize; // r11
  unsigned int maxSize; // r7
  __int64 v14; // r6
  int v15; // r11
  int v16; // r28
  unsigned int v17; // r27
  int fragmentSequence; // r11
  idPacketProcessor::idInnerPacketHeader v19; // [sp+50h] [-50h] BYREF

  p_unsentMsg = &this->unsentMsg;
  this->lastSendTime = time;
  if ( this->unsentMsg.curSize - this->unsentMsg.readCount <= 0 )
    return 0;
  v11 = useBackend & 0xFF00000000LL;
  outMsg->curSize = 0;
  outMsg->overflowed = false;
  outMsg->writeBit = 0;
  outMsg->tempValue = useBackend & 0xFF00000000LL;
  if ( BYTE3(useBackend) != 0 )
    idBitMsg::WriteBits(this: outMsg, value: 0, numBits: -16);
  idBitMsg::WriteBits(this: outMsg, value: sessionID, numBits: 16);
  curSize = p_unsentMsg->curSize;
  if ( this->fragmentedSend )
  {
    v15 = curSize - p_unsentMsg->readCount;
    if ( v15 >= 0 )
    {
      v16 = 1190;
      if ( v15 <= 1190 )
        v16 = v15;
    }
    else
    {
      v16 = v11;
    }
    v17 = ((v16 - v15) & (unsigned int)~(v15 - v16)) >> 31;
    if ( this->unsentMsg.readCount != 0 )
    {
      v19.type = 3;
      v19.userData = ((_cntlzw(((v16 - v15) & (unsigned int)~(v15 - v16)) >> 31) & 0x20) != 0) + 1;
    }
    else
    {
      v19.userData = v11;
      v19.type = 3;
    }
    idPacketProcessor::idInnerPacketHeader::WriteToMsg(this: &v19, msg: outMsg);
    idBitMsg::WriteBits(this: outMsg, value: this->fragmentSequence, numBits: 32);
    idBitMsg::WriteData(this: outMsg, data: &this->unsentMsg.readData[this->unsentMsg.readCount], length: v16);
    idBitMsg::ReadData(this: p_unsentMsg, data: nullptr, length: v16);
    fragmentSequence = this->fragmentSequence;
    this->fragmentedSend = v17;
    this->fragmentSequence = fragmentSequence + 1;
    ++this->fragmentAccumulator;
  }
  else
  {
    idBitMsg::WriteData(this: outMsg, data: this->unsentMsg.readData, length: (p_unsentMsg->writeBit != 0) + curSize);
    maxSize = p_unsentMsg->maxSize;
    LODWORD(v14) = maxSize - v11;
    p_unsentMsg->curSize = ((__PAIR64__((unsigned int)v11 >> 31, maxSize) - __PAIR64__(maxSize >> 31, v11)) >> 32)
                         & maxSize;
  }
  if ( HIDWORD(v11) != 0 )
    *(_WORD *)outMsg->writeData = (outMsg->writeBit != 0) + (unsigned __int16)outMsg->curSize - 2;
  HIDWORD(v14) = (outMsg->writeBit != 0) + outMsg->curSize;
  idPacketProcessor::UpdateOutgoingRate(this, time, size: v14);
  return 1;
}


// ========================================================================
// ?ProcessConnectionlessOutgoing@idPacketProcessor@@SA_NAAVidBitMsg@@0HHH_N@Z
// EA  : 0x8289B5E0
// RVA : 0x0089B5E0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::ProcessConnectionlessOutgoing(
        idBitMsg *msg,
        idBitMsg *out,
        __int16 lobbyType,
        int userData,
        __int16 unencryptedSize,
        bool useBackend)
{
  BOOL v6; // r29
  unsigned __int16 v11; // r27
  int result; // r3

  v6 = useBackend;
  v11 = lobbyType + 1;
  if ( useBackend )
    idBitMsg::WriteBits(this: out, value: 0, numBits: -16);
  idBitMsg::WriteBits(this: out, value: v11, numBits: 16);
  idBitMsg::WriteBits(this: out, value: 1, numBits: 2);
  idBitMsg::WriteBits(this: out, value: userData, numBits: 6);
  idBitMsg::WriteData(this: out, data: msg->readData, length: (msg->writeBit != 0) + msg->curSize);
  result = 1;
  if ( v6 )
    *(_WORD *)out->writeData = (out->writeBit != 0) + (unsigned __int16)out->curSize - unencryptedSize - 2;
  return result;
}


// ========================================================================
// ?ProcessConnectionlessIncoming@idPacketProcessor@@SA_NAAVidBitMsg@@0AAH_N@Z
// EA  : 0x8289B6B0
// RVA : 0x0089B6B0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::ProcessConnectionlessIncoming(
        idBitMsg *msg,
        idBitMsg *out,
        int *userData,
        bool useBackend)
{
  unsigned __int64 v6; // r29
  int Bits; // r11
  int v9; // r27
  int v10; // r3
  int maxSize; // r11
  int v12; // r10
  __int16 v13; // [sp+50h] [-40h] BYREF

  HIDWORD(v6) = userData;
  LODWORD(v6) = 0;
  if ( useBackend )
  {
    v13 = 0;
    idBitMsg::ReadData(this: msg, data: &v13, length: 2);
  }
  Bits = (unsigned __int16)idBitMsg::ReadBits(this: msg, numBits: 16);
  if ( Bits == 1 || Bits == 2 || Bits == 3 )
  {
    v9 = idBitMsg::ReadBits(this: msg, numBits: 2);
    v10 = idBitMsg::ReadBits(this: msg, numBits: 6);
    if ( v9 == 1 )
    {
      *(_DWORD *)HIDWORD(v6) = v10;
      out->overflowed = false;
      out->curSize = 0;
      out->writeBit = 0;
      out->tempValue = v6;
      idBitMsg::WriteData(this: out, data: &msg->readData[msg->readCount], length: msg->curSize - msg->readCount);
      maxSize = out->maxSize;
      v12 = msg->curSize - msg->readCount;
      if ( v12 <= maxSize )
        out->curSize = v12;
      else
        out->curSize = maxSize;
      return 1;
    }
    else
    {
      idLib::Printf(fmt: "ProcessConnectionlessIncoming: header.Type() != PACKET_TYPE_OOB\n");
      return 0;
    }
  }
  else
  {
    idLib::Printf(fmt: "ProcessConnectionlessIncoming: Invalid session ID - %d\n", Bits);
    return 0;
  }
}


// ========================================================================
// ?GetSessionID@idPacketProcessor@@SAGAAVidBitMsg@@_N@Z
// EA  : 0x8289B7D0
// RVA : 0x0089B7D0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::GetSessionID(idBitMsg *msg, bool useBackend)
{
  int readCount; // r30
  int readBit; // r29
  int result; // r3
  __int16 v6; // [sp+50h] [-30h] BYREF

  readCount = msg->readCount;
  readBit = msg->readBit;
  if ( useBackend )
  {
    v6 = 0;
    idBitMsg::ReadData(this: msg, data: &v6, length: 2);
  }
  result = (unsigned __int16)idBitMsg::ReadBits(this: msg, numBits: 16);
  msg->readCount = readCount;
  msg->readBit = readBit & 7;
  return result;
}


// ========================================================================
// ?FinalizeRead@idPacketProcessor@@AAAHAAVidBitMsg@@0AAH@Z
// EA  : 0x8289B978
// RVA : 0x0089B978
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::FinalizeRead(
        idPacketProcessor *this,
        idBitMsg *inMsg,
        idBitMsg *outMsg,
        int *userValue,
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
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31)
{
  unsigned __int64 v31; // r25
  __int64 v32; // r4
  int v33; // r31
  int *v34; // r6
  idBitMsg *v35; // r28
  idBitMsg *v36; // r5
  idBitMsg *v37; // r19
  int *v38; // r30
  int Bits; // r16
  int v40; // r23
  int v42; // r3
  int v43; // r26
  __int16 v44; // r3
  const unsigned __int8 *readData; // r10
  int v46; // r20
  int v47; // r22
  int v48; // r17
  size_t v49; // r30
  int v50; // r5
  void *v51; // r29
  int v52; // r11
  int curSize; // r9
  int readCount; // r8
  int maxSize; // r11

  v32 = ((__int64 (*)(void))RtlCheckStack12)();
  LODWORD(v31) = 0;
  v33 = HIDWORD(v32);
  *v34 = 0;
  v35 = (idBitMsg *)v32;
  v37 = v36;
  v38 = v34;
  Bits = idBitMsg::ReadBits(this: (idBitMsg *)v32, numBits: 2);
  a27 = Bits;
  v40 = idBitMsg::ReadBits(this: v35, numBits: 6);
  a28 = v40;
  if ( Bits == 3 )
  {
    idLib::Printf(fmt: "Received invalid fragmented packet.\n");
    return 0;
  }
  if ( Bits == 2 )
  {
    v42 = idBitMsg::ReadBits(this: v35, numBits: 32);
    idDataQueue<63,8000>::RemoveOlderThan(this: (idDataQueue<63,8000> *)(v33 + 8016), sequence: v42 + 1);
    idPacketProcessor::idInnerPacketHeader::ReadFromMsg(this: (idPacketProcessor::idInnerPacketHeader *)&a27, msg: v35);
    v40 = a28;
    Bits = a27;
  }
  if ( Bits == 1 )
  {
    *v38 = v40;
  }
  else
  {
    if ( Bits != 0 )
    {
      idLib::Printf(fmt: "In-band packet expected, received type %i instead.\n", Bits);
      return 0;
    }
    v43 = 0;
    *(_DWORD *)(v33 + 16800) = 0;
    if ( v40 > 0 )
    {
      v35->readBit = 0;
      v44 = idBitMsg::ReadBits(this: v35, numBits: -16);
      readData = v35->readData;
      v46 = v44;
      STACK[0x14850] = (unsigned int)&STACK[0x11830];
      idLZWCompressor::Start(
        this: (idLZWCompressor *)&STACK[0x14850],
        data_: (unsigned __int8 *)&readData[v35->readCount],
        maxSize_: v44,
        append: false);
      a27 = 0;
      idLZWCompressor::ReadAgnostic<unsigned int>(
        this: (idLZWCompressor *)&STACK[0x14850],
        c: &a27,
        ignoreOverflow: false);
      v47 = 0;
      v48 = a27;
      HIDWORD(v31) = a27;
      do
      {
        HIWORD(a27) = 0;
        idLZWCompressor::ReadAgnostic<unsigned short>(
          this: (idLZWCompressor *)&STACK[0x14850],
          c: (unsigned __int16 *)&a27,
          ignoreOverflow: false);
        v49 = HIWORD(a27);
        idLZWCompressor::Read(
          this: (idLZWCompressor *)&STACK[0x14850],
          data: &a31,
          length: HIWORD(a27),
          ignoreOverflow: false);
        v50 = *(_DWORD *)(v33 + 16796);
        if ( SHIDWORD(v31) <= v50 )
        {
          if ( net_verboseReliable.valueInteger != 0 )
            idLib::Printf(fmt: "Ignoring reliable msg %i because %i was already acked\n", HIDWORD(v31), v50);
        }
        else
        {
          if ( v49 + v43 > 0x1F40 )
          {
            idLib::Printf(fmt: "Reliable msg size overflow.\n");
            return 0;
          }
          if ( (((*(_DWORD *)(v33 + 16800) >= 0) + (*(_DWORD *)(v33 + 16800) >= 0x3Fu)) & 1) == 0 )
          {
            idLib::Printf(fmt: "Reliable msg count overflow.\n");
            return 0;
          }
          v51 = (void *)(v43 + v33 + 16804);
          memcpy(Dst: v51, Src: &a31, Size: v49);
          v43 += v49;
          *(_DWORD *)(4 * (*(_DWORD *)(v33 + 16800) + 6264) + v33) = v49;
          *(_DWORD *)(4 * (*(_DWORD *)(v33 + 16800) + 6201) + v33) = v51;
          ++*(_DWORD *)(v33 + 16800);
        }
        if ( HIBYTE(STACK[0x17060]) != 0 )
        {
          idLib::Printf(fmt: "lzwCompressor.IsOverflowed() == true.\n");
          return 0;
        }
        ++v47;
        ++HIDWORD(v31);
      }
      while ( v47 < v40 );
      v52 = v40 + v48 - 1;
      v35->readCount += v46;
      if ( v52 >= *(_DWORD *)(v33 + 16796) )
      {
        *(_DWORD *)(v33 + 25308) = v52;
        *(_DWORD *)(v33 + 16796) = v52;
      }
    }
  }
  v37->writeBit = 0;
  v37->tempValue = v31;
  v37->overflowed = false;
  v37->curSize = 0;
  idBitMsg::WriteData(this: v37, data: &v35->readData[v35->readCount], length: v35->curSize - v35->readCount);
  curSize = v35->curSize;
  readCount = v35->readCount;
  maxSize = v37->maxSize;
  if ( curSize - readCount <= maxSize )
    v37->curSize = curSize - readCount;
  else
    v37->curSize = maxSize;
  return ((_cntlzw(Bits - 1) & 0x20) == 0) + 1;
}


// ========================================================================
// ?ProcessOutgoing@idPacketProcessor@@QAA_NHABVidBitMsg@@_NH@Z
// EA  : 0x8289BCA0
// RVA : 0x0089BCA0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::ProcessOutgoing(
        idPacketProcessor *this,
        const int time,
        const idBitMsg *msg,
        bool isOOB,
        int userData,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        unsigned __int64 a18,
        __int64 a19,
        int a20)
{
  int v20; // r3
  __int64 v21; // r24
  int v22; // r5
  int v23; // r22
  unsigned __int8 v24; // r6
  unsigned __int8 v25; // r30
  int v26; // r7
  int v27; // r29
  _DWORD *v29; // r31
  int v30; // r21
  int v31; // r11
  BOOL v32; // r10
  int v33; // r10
  int v34; // r11
  _DWORD *v35; // r29
  int v36; // r25
  int v37; // r30
  char *v38; // r28
  int v39; // r27
  int v40; // r30
  int v41; // r28
  char *v42; // r26
  int v43; // r9
  unsigned int v44; // r7
  int v45; // r11
  int v46; // r10
  __int64 v47; // r6
  __int64 v48; // r11
  double v49; // fp2

  v20 = ((int (*)(void))RtlCheckStack12)();
  HIDWORD(v21) = v20;
  v23 = v22;
  v25 = v24;
  v27 = v26;
  if ( *(_BYTE *)(v20 + 8012) != 0 )
  {
    idLib::Warning(fmt: "ProcessOutgoing: fragmentedSend == true!");
    return 0;
  }
  v29 = (_DWORD *)(v20 + 25312);
  if ( *(_DWORD *)(v20 + 25324) != *(_DWORD *)(v20 + 25332) )
  {
    idLib::Warning(fmt: "ProcessOutgoing: unsentMsg.GetRemainingData() > 0!");
    return 0;
  }
  LODWORD(v21) = 0;
  *(_DWORD *)(v20 + 25324) = 0;
  *v29 = v20 + 25352;
  *(_DWORD *)(v20 + 25316) = v20 + 25352;
  *(_DWORD *)(v20 + 25320) = 8000;
  *(_DWORD *)(v20 + 25328) = 0;
  *(_DWORD *)(v20 + 25332) = 0;
  *(_DWORD *)(v20 + 25336) = 0;
  *(_BYTE *)(v20 + 25340) = 0;
  *(_BYTE *)(v20 + 25341) = 0;
  *(_QWORD *)(HIDWORD(v21) + 25344) = v21;
  *(_DWORD *)(v20 + 25324) = 0;
  *(_BYTE *)(v20 + 25341) = 0;
  *(_DWORD *)(v20 + 25328) = 0;
  *(_QWORD *)(HIDWORD(v21) + 25344) = v21;
  if ( *(int *)(v20 + 25308) >= 0 )
  {
    a18 = 0x200000000LL;
    idPacketProcessor::idInnerPacketHeader::WriteToMsg(
      this: (idPacketProcessor::idInnerPacketHeader *)&a18,
      msg: (idBitMsg *)(v20 + 25312));
    idBitMsg::WriteBits(this: (idBitMsg *)(HIDWORD(v21) + 25312), value: *(_DWORD *)(HIDWORD(v21) + 25308), numBits: 32);
    *(_DWORD *)(HIDWORD(v21) + 25308) = -1;
  }
  v30 = v25;
  if ( v25 != 0 )
  {
    v31 = *(_DWORD *)(HIDWORD(v21) + 25324);
    v32 = *(_DWORD *)(HIDWORD(v21) + 25328) != 0;
    if ( (*(_DWORD *)(v23 + 16) != 0) + *(_DWORD *)(v23 + 12) + v32 + v31 > 1189 )
    {
      idLib::Printf(fmt: "Out-of-band packet too large %i\n", v32 + v31);
      return 0;
    }
    LODWORD(a18) = v27;
    HIDWORD(a18) = 1;
    idPacketProcessor::idInnerPacketHeader::WriteToMsg(
      this: (idPacketProcessor::idInnerPacketHeader *)&a18,
      msg: (idBitMsg *)(HIDWORD(v21) + 25312));
  }
  else
  {
    HIDWORD(a18) = 0;
    LODWORD(a18) = *(_DWORD *)(HIDWORD(v21) + 8020);
    idPacketProcessor::idInnerPacketHeader::WriteToMsg(
      this: (idPacketProcessor::idInnerPacketHeader *)&a18,
      msg: (idBitMsg *)(HIDWORD(v21) + 25312));
    if ( *(int *)(HIDWORD(v21) + 8020) > 0 )
    {
      v33 = *(_DWORD *)(HIDWORD(v21) + 25328);
      v34 = *(_DWORD *)(HIDWORD(v21) + 25324);
      *(_DWORD *)(HIDWORD(v21) + 25328) = 0;
      *(_QWORD *)(HIDWORD(v21) + 25344) = v21;
      STACK[0x109B0] = (unsigned int)&a20;
      *(_DWORD *)(HIDWORD(v21) + 25324) = (v33 != 0) + v34;
      idLZWCompressor::Start(
        this: (idLZWCompressor *)&STACK[0x109B0],
        data_: (unsigned __int8 *)((v33 != 0) + v34 + *v29 + 2),
        maxSize_: *(_DWORD *)(HIDWORD(v21) + 25320) - ((v33 != 0) + v34) - 2,
        append: false);
      v35 = (_DWORD *)(HIDWORD(v21) + 8016);
      v36 = 4;
      v37 = 0;
      v38 = (char *)&a18 + 4;
      HIDWORD(a18) = **(_DWORD **)(HIDWORD(v21) + 8016);
      do
      {
        if ( HIBYTE(STACK[0x131C0]) != 0 )
          break;
        idLZWCompressor::WriteByte(this: (idLZWCompressor *)&STACK[0x109B0], value: *--v38);
        ++v37;
      }
      while ( v37 < 4 );
      v39 = 0;
      if ( *(int *)(HIDWORD(v21) + 8020) > 0 )
      {
        v40 = 0;
        do
        {
          v41 = 0;
          v42 = (char *)&a18 + 2;
          HIWORD(a18) = *(_DWORD *)(*v35 + v40 + 4);
          do
          {
            if ( HIBYTE(STACK[0x131C0]) != 0 )
              break;
            idLZWCompressor::WriteByte(this: (idLZWCompressor *)&STACK[0x109B0], value: *--v42);
            ++v41;
          }
          while ( v41 < 2 );
          idLZWCompressor::Write(
            this: (idLZWCompressor *)&STACK[0x109B0],
            data: (_BYTE *)v35 + *(_DWORD *)(*v35 + v40 + 8) + 776,
            length: *(_DWORD *)(*v35 + v40 + 4));
          ++v39;
          v43 = *v35 + v40;
          v40 += 12;
          v36 += *(_DWORD *)(v43 + 4) + 2;
        }
        while ( v39 < *(_DWORD *)(HIDWORD(v21) + 8020) );
      }
      idLZWCompressor::End(this: (idLZWCompressor *)&STACK[0x109B0]);
      if ( HIBYTE(STACK[0x131C0]) != 0 )
        idLib::Error(fmt: "reliable msg compressor overflow.");
      idBitMsg::WriteBits(
        this: (idBitMsg *)(HIDWORD(v21) + 25312),
        value: *(_DWORD *)(STACK[0x109B0] + 12316),
        numBits: -16);
      v44 = STACK[0x109B0];
      v45 = *(_DWORD *)(HIDWORD(v21) + 25320);
      v46 = (*(_DWORD *)(HIDWORD(v21) + 25328) != 0)
          + *(_DWORD *)(HIDWORD(v21) + 25324)
          + *(_DWORD *)(STACK[0x109B0] + 12316);
      if ( v46 <= v45 )
        *(_DWORD *)(HIDWORD(v21) + 25324) = v46;
      else
        *(_DWORD *)(HIDWORD(v21) + 25324) = v45;
      if ( net_showReliableCompression.valueInteger != 0 )
      {
        HIDWORD(v47) = *(_DWORD *)(v44 + 12316);
        LODWORD(v47) = v36;
        LODWORD(v48) = HIDWORD(v47) + totalCompressed;
        HIDWORD(v48) = totalUncompressed + v36;
        a19 = v48;
        a18 = __PAIR64__((idCVar *)&r_cuttablemodel_freecpudata.description, totalUncompressed + v36);
        totalCompressed += HIDWORD(v47);
        v49 = (float)((float)v48
                    / (float)__SPAIR64__((idCVar *)&r_cuttablemodel_freecpudata.description, totalUncompressed + v36));
        totalUncompressed += v36;
        idLib::Printf(
          fmt: "Uncompressed: %i, Compressed: %i, TotalUncompressed: %i, TotalCompressed: %i, (%2.2f / %2.2f )\n",
          v36,
          HIDWORD(v47),
          totalUncompressed,
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)__SPAIR64__(v36, HIDWORD(v47)) / (float)v47))),
          (float)((float)__SPAIR64__(v36, HIDWORD(v47)) / (float)v47),
          v49);
      }
    }
  }
  idBitMsg::WriteData(
    this: (idBitMsg *)(HIDWORD(v21) + 25312),
    data: *(const void **)(v23 + 4),
    length: (*(_DWORD *)(v23 + 16) != 0) + *(_DWORD *)(v23 + 12));
  if ( (*(_DWORD *)(HIDWORD(v21) + 25328) != 0) + *(_DWORD *)(HIDWORD(v21) + 25324) > 1190 )
  {
    if ( v30 != 0 )
      idLib::Error(fmt: "oob msg's cannot fragment");
    *(_BYTE *)(HIDWORD(v21) + 8012) = 1;
  }
  return 1;
}


// ========================================================================
// ?ProcessIncoming@idPacketProcessor@@QAAHHGAAVidBitMsg@@0AAHH_N@Z
// EA  : 0x8289C108
// RVA : 0x0089C108
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::ProcessIncoming(
        idPacketProcessor *this,
        int time,
        __int64 msg,
        idBitMsg *out,
        int *userData,
        const int peerNum,
        bool useBackend)
{
  unsigned __int16 v8; // r29
  idBitMsg *v10; // r31
  unsigned __int64 v13; // r27
  int Bits; // r11
  int v15; // r5
  char v16; // r11
  bool v17; // zf
  int readCount; // r29
  int readBit; // r28
  int v21; // r10
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r3
  int v26; // r29
  int fragmentSequence; // r5
  int curSize; // r10
  int msgWritePos; // r9
  int v30; // r11
  int v31; // r8
  int v32; // r7
  int v33; // r9
  int v34; // r11
  char v35; // r11
  int v36; // r7
  int v37; // [sp+8h] [-C8h]
  int v38; // [sp+Ch] [-C4h]
  int v39; // [sp+10h] [-C0h]
  int v40; // [sp+14h] [-BCh]
  int v41; // [sp+18h] [-B8h]
  int v42; // [sp+1Ch] [-B4h]
  int v43; // [sp+20h] [-B0h]
  int v44; // [sp+24h] [-ACh]
  int v45; // [sp+28h] [-A8h]
  int v46; // [sp+2Ch] [-A4h]
  int v47; // [sp+30h] [-A0h]
  int v48; // [sp+34h] [-9Ch]
  int v49; // [sp+38h] [-98h]
  int v50; // [sp+3Ch] [-94h]
  int v51; // [sp+40h] [-90h]
  int v52; // [sp+44h] [-8Ch]
  int v53; // [sp+48h] [-88h]
  int v54; // [sp+4Ch] [-84h]
  int v55; // [sp+50h] [-80h] BYREF
  int v56; // [sp+54h] [-7Ch]
  idPacketProcessor::idInnerPacketHeader v57; // [sp+58h] [-78h] BYREF
  idBitMsg v58[2]; // [sp+60h] [-70h] BYREF

  HIDWORD(v13) = peerNum;
  v8 = WORD1(msg);
  HIDWORD(msg) = (*(_DWORD *)(msg + 16) != 0) + *(_DWORD *)(msg + 12);
  v10 = (idBitMsg *)msg;
  idPacketProcessor::UpdateIncomingRate(this, time, size: msg);
  LODWORD(v13) = 0;
  if ( useBackend )
  {
    HIWORD(v55) = 0;
    idBitMsg::ReadData(this: v10, data: &v55, length: 2);
  }
  Bits = (unsigned __int16)idBitMsg::ReadBits(this: v10, numBits: 16);
  v15 = Bits;
  if ( Bits == 1 || Bits == 2 || (v17 = Bits != 3, v16 = 1, !v17) )
    v16 = 0;
  if ( v16 == 0 )
  {
    idLib::Printf(fmt: "Expected non connectionless ID, but got a connectionless one\n");
    return 0;
  }
  if ( v15 != v8 )
  {
    idLib::Printf(fmt: "Expected session id: %8x but got %8x instead\n", v8, v15);
    return 0;
  }
  readCount = v10->readCount;
  readBit = v10->readBit;
  v57.type = 0;
  v57.userData = 0;
  idPacketProcessor::idInnerPacketHeader::ReadFromMsg(this: &v57, msg: v10);
  if ( v57.type != 3 )
  {
    v10->readCount = readCount;
    v10->readBit = readBit & 7;
    return idPacketProcessor::FinalizeRead(
             this,
             inMsg: v10,
             outMsg: out,
             userValue: userData,
             a5: v24,
             a6: v23,
             a7: v22,
             a8: v21,
             a9: v37,
             a10: v38,
             a11: v39,
             a12: v40,
             a13: v41,
             a14: v42,
             a15: v43,
             a16: v44,
             a17: v45,
             a18: v46,
             a19: v47,
             a20: v48,
             a21: v49,
             a22: v50,
             a23: v51,
             a24: v52,
             a25: v53,
             a26: v54,
             a27: v55,
             a28: v56,
             a29: v57.type,
             a30: v57.userData,
             a31: (int)v58[0].writeData);
  }
  v25 = idBitMsg::ReadBits(this: v10, numBits: 32);
  v26 = v57.userData;
  if ( v57.userData != 0 )
  {
    fragmentSequence = this->fragmentSequence;
    if ( fragmentSequence == -1 || v25 != fragmentSequence + 1 )
    {
      v36 = this->droppedFrags + 1;
      this->droppedFrags = v36;
      idLib::Printf(
        fmt: "Dropped Fragments - PeerNum: %i FragmentSeq: %i, ReadSeq: %i, Total: %i\n",
        HIDWORD(v13),
        fragmentSequence,
        v25,
        v36);
      this->fragmentSequence = -1;
      return 0;
    }
  }
  else
  {
    this->msgWritePos = 0;
  }
  this->fragmentSequence = v25;
  curSize = v10->curSize;
  msgWritePos = this->msgWritePos;
  v30 = v10->readCount;
  if ( (unsigned int)(msgWritePos - v30 + curSize) >= 0x1F40 )
    idLib::Error(fmt: "ProcessIncoming: Fragmented msg buffer overflow.");
  memcpy(Dst: &this->msgBuffer[msgWritePos], Src: &v10->readData[v30], Size: curSize - v30);
  v33 = v10->readCount;
  v34 = this->msgWritePos - v33 + v10->curSize;
  this->msgWritePos = v34;
  if ( v26 != 2 )
  {
    if ( v26 == 0 || (v35 = 0, v26 == 1) )
      v35 = 1;
    if ( v35 == 0 )
    {
      idLib::Printf(fmt: "ProcessIncoming: Invalid packet.\n");
      return 0;
    }
    return 0;
  }
  v58[0].writeData = (unsigned __int8 *)this;
  v58[0].readData = (const unsigned __int8 *)this;
  v58[0].maxSize = 8000;
  memset(&v58[0].writeBit, 0, 14);
  v58[0].tempValue = v13;
  v58[0].curSize = 8000;
  if ( v34 <= 8000 )
    v58[0].curSize = v34;
  return idPacketProcessor::FinalizeRead(
           this,
           inMsg: v58,
           outMsg: out,
           userValue: userData,
           a5: v32,
           a6: v31,
           a7: v33,
           a8: 8000,
           a9: v37,
           a10: v38,
           a11: v39,
           a12: v40,
           a13: v41,
           a14: v42,
           a15: v43,
           a16: v44,
           a17: v45,
           a18: v46,
           a19: v47,
           a20: v48,
           a21: v49,
           a22: v50,
           a23: v51,
           a24: v52,
           a25: v53,
           a26: v54,
           a27: v55,
           a28: v56,
           a29: v57.type,
           a30: v57.userData,
           a31: (int)v58[0].writeData);
}


// ========================================================================
// ?QueueReliableMessage@idPacketProcessor@@QAA_NEPBEH@Z
// EA  : 0x8289C650
// RVA : 0x0089C650
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

int __fastcall idPacketProcessor::QueueReliableMessage(
        idPacketProcessor *this,
        unsigned __int8 type,
        const unsigned __int8 *data,
        size_t dataLen,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        unsigned __int8 a14)
{
  const char *reliableSequenceSend; // r4

  a14 = type;
  reliableSequenceSend = (const char *)this->reliableSequenceSend;
  this->reliableSequenceSend = (int)(reliableSequenceSend + 1);
  return idDataQueue<63,8000>::Append(
           this: &this->reliable,
           sequence: reliableSequenceSend,
           b1: &a14,
           b1Len: 1u,
           b2: data,
           b2Len: dataLen);
}


// ========================================================================
// ?VerifyEmptyReliableQueue@idPacketProcessor@@QAAXEE@Z
// EA  : 0x8289C6A0
// RVA : 0x0089C6A0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

void __fastcall idPacketProcessor::VerifyEmptyReliableQueue(
        idPacketProcessor *this,
        unsigned __int8 keepMsgBelowThis,
        unsigned __int8 replaceWithThisMsg,
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
        unsigned __int8 a16)
{
  int valueInteger; // r11
  const char *reliableSequenceSend; // r4
  const unsigned __int8 *str; // r7
  const char *v22; // r4
  int v23; // r4
  const char *v24; // r3
  int v25; // r29
  int v26; // r24
  unsigned int v27; // r26
  idDataQueue<63,8000> *p_reliable; // r30
  unsigned int v29; // r28
  unsigned __int8 v30[4]; // [sp+50h] [-22B0h] BYREF
  idAtomicString v31; // [sp+54h] [-22ACh] BYREF
  int num; // [sp+58h] [-22A8h]
  idDataQueue<63,8000> v33; // [sp+60h] [-22A0h] BYREF

  a16 = replaceWithThisMsg;
  valueInteger = net_verifyReliableQueue.valueInteger;
  if ( net_verifyReliableQueue.valueInteger == 4 )
  {
    idLib::Printf(fmt: "pushing a fake game reliable\n");
    idAtomicString::Set(this: &v31, str_: "garbage");
    reliableSequenceSend = (const char *)this->reliableSequenceSend;
    str = (const unsigned __int8 *)v31.str;
    this->reliableSequenceSend = (int)(reliableSequenceSend + 1);
    v30[0] = keepMsgBelowThis + 4;
    idDataQueue<63,8000>::Append(
      this: &this->reliable,
      sequence: reliableSequenceSend,
      b1: v30,
      b1Len: 1u,
      b2: str,
      b2Len: 8u);
    v22 = (const char *)this->reliableSequenceSend;
    v30[0] = replaceWithThisMsg;
    this->reliableSequenceSend = (int)(v22 + 1);
    idDataQueue<63,8000>::Append(this: &this->reliable, sequence: v22, b1: v30, b1Len: 1u, b2: nullptr, b2Len: 0);
    valueInteger = net_verifyReliableQueue.valueInteger;
  }
  num = this->reliable.items.num;
  v23 = num;
  if ( num != 0 )
  {
    v24 = "reliable queue is not empty: %d messages";
    if ( valueInteger == 1 )
      idLib::Error(fmt: "reliable queue is not empty: %d messages", num);
    num = v23;
    idLib::Warning(fmt: v24);
    if ( net_verifyReliableQueue.valueInteger != 0 )
    {
      v25 = 0;
      v33.items.num = 0;
      v33.items.granularity = 1;
      v33.items.size = 63;
      v33.items.list = v33.items.staticList;
      v33.items.memTag = 5;
      v33.items.listStatic = 1;
      v33.dataLength = 0;
      if ( net_verifyReliableQueue.valueInteger >= 3 )
        idLib::Printf(
          fmt: "rollback send sequence from %d to %d\n",
          this->reliableSequenceSend,
          this->reliable.items.list->sequence);
      v26 = 0;
      if ( this->reliable.items.num > 0 )
      {
        v27 = keepMsgBelowThis;
        p_reliable = &this->reliable;
        do
        {
          v29 = p_reliable->data[p_reliable->items.list[v25].dataOffset];
          if ( v29 >= v27 )
          {
            idDataQueue<63,8000>::Append(
              this: &v33,
              sequence: (const char *)p_reliable->items.list[v25].sequence,
              b1: &a16,
              b1Len: 1u,
              b2: nullptr,
              b2Len: 0);
            if ( net_verifyReliableQueue.valueInteger >= 3 )
              idLib::Printf(fmt: "dropping %d\n", v29);
          }
          else
          {
            if ( net_verifyReliableQueue.valueInteger >= 3 )
              idLib::Printf(fmt: "keeping %d\n", v29);
            idDataQueue<63,8000>::Append(
              this: &v33,
              sequence: (const char *)p_reliable->items.list[v25].sequence,
              b1: &p_reliable->data[p_reliable->items.list[v25].dataOffset],
              b1Len: p_reliable->items.list[v25].length,
              b2: nullptr,
              b2Len: 0);
          }
          ++v26;
          ++v25;
        }
        while ( v26 < this->reliable.items.num );
      }
      idDataQueue<63,8000>::operator=(this: &this->reliable, __that: (const idList<navSplineSegment_t,5> *)&v33);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33);
    }
  }
}


// ========================================================================
// $LN93_1
// EA  : 0x8289C8E0
// RVA : 0x0089C8E0
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

void _LN93_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8960 + 96));
}


// ========================================================================
// `dynamic initializer for 'net_maxRate''
// EA  : 0x83345838
// RVA : 0x01345838
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxRate__()
{
  idCVar::idCVar(
    this: &net_maxRate,
    name: "net_maxRate",
    value: "50",
    flags: 2,
    description: "max send rate in kilobytes per second",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxRate__);
}


// ========================================================================
// `dynamic initializer for 'net_showReliableCompression''
// EA  : 0x83345890
// RVA : 0x01345890
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_showReliableCompression__()
{
  idCVar::idCVar(
    this: &net_showReliableCompression,
    name: "net_showReliableCompression",
    value: "0",
    flags: 1,
    description: "Show reliable compression ratio.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_showReliableCompression__);
}


// ========================================================================
// `dynamic initializer for 'net_verifyReliableQueue''
// EA  : 0x833458E8
// RVA : 0x013458E8
// PDB : w:\tech5\engine\network\packetprocessor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_verifyReliableQueue__()
{
  idCVar::idCVar(
    this: &net_verifyReliableQueue,
    name: "net_verifyReliableQueue",
    value: "2",
    flags: 2,
    description: "0: warn only, 1: error, 2: fixup, 3: fixup and verbose, 4: force test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_verifyReliableQueue__);
}

