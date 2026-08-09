#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventmanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13916; PDB kind: class.
class idVoiceEventManager
{
public:
  idList<idViseme_Simple,66> eventsVisemeSimple;
  idList<idVoiceGameEvent,66> eventsGame;
  idList<idVoiceTextEvent,66> eventsText;
  idList<idVoicePunctuationEvent,66> eventsPunc;
  idList<idVoiceAnimEvent,66> eventsAnim;
  idList<idVoiceMoodEvent,66> eventsMood;
};

// IDA Local Type ordinal 16535; PDB kind: class.
class idAIEventManager
{
public:
  idList<idAIEvent *,5> eventList;
  idHashIndex eventHash;
  idList<idEntityPtr<idEntity>,5> receivers;
  idList<idAIEventPool *,5> eventPools;
};
