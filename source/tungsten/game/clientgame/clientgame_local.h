#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\clientgame_local.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15600; PDB kind: class.
class idClientGame
{
public:
  idRandom2 random;
  idRenderWorld *renderWorld;
  idSoundWorld *soundWorld;
  int firstRenderFrame;
  int lastRenderFrame;
  idStr mapName;
  idVec3 gravity;
  bool vehicleRaceMap;
  __declspec(align(8)) idGameLibEffects gameLibEffects;
  idTraceModelCache traceModelCache;
  idTraceModelRecycler traceModelRecycler;
  idClip clip;
  idPush push;
  idPVS pvs;
  idEventSystem eventSystem;
  idList<idClass *,5> objectList;
  idHashIndex objectHash;
  idList<idPresentableAnimatedEntity *,5> aimAssistTargets;
  int entityToPresentableLUT[8192];
  idList<presentableThink_t,5> presentableThinks;
  int previousServerTime;
  int serverTime;
  idGameTimeManager gameTimeManager;
  int playerTime;
  int ssEndTime;
  int ssStartTime;
  idList<idPresentable *,5> presentables;
  idList<idPresentable *,5> activePresentables;
  idList<idPresentable *,5> pusherPresentables;
  idList<idPresentable *,5> vehiclePresentables;
  idList<idPresentable *,5> serializedPresentables;
  idArray<int,3> firstFreePresentable;
  bool serialized;
  unsigned int presentableSpawnId;
  idArray<lobbyUserID_t,6> lobbyUserIDs;
  idArray<idReplicatedSound,32> replicatedSounds;
  idList<idReplicatedSound,5> startSoundOverRun;
  unsigned __int8 overrideSoundPeerMask;
  idArray<int,4> inputToPlayerIndexRouting;
  idArray<idRenderModelGui *,6> localGuiModels;
  idRenderModelGui *guiModel;
  idList<idViewCallbacks *,5> activeViewCallbacks;
  idInfluenceTrailManager influenceTrailManager;
  idRageMetrics *rageMetrics;
  challengeGameMode_t serializedChallengeMode;
  idDeferredFireManager deferredFireManager;
  const idDeclVoiceOver *impressive;
  const idDeclVoiceOver *doubleKill;
  const idDeclVoiceOver *tripleKill;
  const idDeclVoiceOver *quadKill;
  const idDeclVoiceOver *slaughter;
  const idDeclVoiceOver *revenge;
  const idDeclVoiceOver *airMail;
  const idDeclVoiceOver *pull;
  const idDeclVoiceOver *afterLife;
  const idDeclVoiceOver *maxChain;
  const idDeclVoiceOver *chainBreaker;
  const idDeclVoiceOver *closeCall;
  const idDeclVoiceOver *airRally;
  const idDeclVoiceOver *denial;
  unsigned __int8 reliableMsgBuffer[8000];
  idList<idClientGameMsg *,5> queuedReliableMsgs;
};
