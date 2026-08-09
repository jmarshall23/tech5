#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\packetprocessor.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 10548; PDB kind: struct.
struct PACKET_PROCESSOR
{
  PACKET_QUEUE FreePacketContexts;
  PACKET_QUEUE InFlight;
  PACKET_CONTEXT *PacketContextAllocation;
};

// IDA Local Type ordinal 22294; PDB kind: class.
class idPacketProcessor
{
public:
  unsigned __int8 msgBuffer[8000];
  int msgWritePos;
  int fragmentSequence;
  int droppedFrags;
  bool fragmentedSend;
  idDataQueue<63,8000> reliable;
  int reliableSequenceSend;
  int reliableSequenceRecv;
  int numReliable;
  unsigned __int8 reliableBuffer[8000];
  const unsigned __int8 *reliableMsgPtrs[63];
  int reliableMsgSize[63];
  int queuedReliableAck;
  idBitMsg unsentMsg;
  unsigned __int8 unsentBuffer[8000];
  int lastSendTime;
  int outgoingRateTime;
  float outgoingRateBytes;
  int incomingRateTime;
  float incomingRateBytes;
  int outgoingBytes;
  int incomingBytes;
  int currentOutgoingRate;
  int lastOutgoingRateTime;
  int lastOutgoingBytes;
  int currentIncomingRate;
  int lastIncomingRateTime;
  int lastIncomingBytes;
  idGaugeMetric outgoingPacketSize;
  idGaugeMetric incomingPacketSize;
  idGaugeMetric handledReliableMsgSize;
  idGaugeMetric queuedReliableMsgSize;
  idGaugeMetric fragmentedPacketSize;
  idGaugeMetric sentSnapShotSize;
  int fragmentAccumulator;
};

// IDA Local Type ordinal 22295; PDB kind: class.
class idPacketProcessor::idOuterPacketHeader
{
public:
  unsigned __int16 sessionID;
};

// IDA Local Type ordinal 22296; PDB kind: class.
class idPacketProcessor::idInnerPacketHeader
{
public:
  int type;
  int userData;
};

// IDA Local Type ordinal 26638; PDB kind: typedef.
typedef PACKET_PROCESSOR *PPACKET_PROCESSOR;
