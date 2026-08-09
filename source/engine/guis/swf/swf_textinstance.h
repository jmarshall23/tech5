#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_textinstance.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14796; PDB kind: class.
class idSWFTextInstance
{
public:
  idSWFEditText *editText;
  idSWF *swf;
  idSWFSpriteInstance *parent;
  int depth;
  idSWFScriptObject *scriptObject;
  idAtomicString name;
  idStr text;
  idStr randomtext;
  idStr variable;
  swfColorRGBA_t color;
  bool visible;
  bool tooltip;
  int bindset;
  int selectionStart;
  int selectionEnd;
  int scroll;
  int scrollTime;
  int maxscroll;
  bool shiftHeld;
  int lastInputTime;
  bool useDropShadow;
  bool useStroke;
  float strokeStrength;
  float strokeWeight;
  int textLength;
  bool lengthCalculated;
  swfTextRenderMode_t renderMode;
  bool generatingText;
  int rndSpotsVisible;
  int rndSpacesVisible;
  int charMultiplier;
  int textSpotsVisible;
  int rndTime;
  int startRndTime;
  int prevReplaceIndex;
  bool triggerGenerate;
  int renderDelay;
  bool scrollUpdate;
  idStr soundClip;
  bool needsSoundUpdate;
  idList<int,72> indexArray;
  idRandom2 rnd;
  bool isSubtitle;
  int subLength;
  int subCharDisplayTime;
  int subAlign;
  bool subUpdating;
  int subCharStartIndex;
  int subNextStartIndex;
  int subCharEndIndex;
  int subDisplayTime;
  int subStartTime;
  int subSourceID;
  idStr subtitleText;
  bool subNeedsSwitch;
  bool subForceKillQueued;
  bool subForceKill;
  int subKillTimeDelay;
  int subSwitchTime;
  int subLastWordIndex;
  int subPrevLastWordIndex;
  idStr subSpeaker;
  bool subWaitClear;
  bool subInitialLine;
  int inputTextStartChar;
  idList<subTimingWordData_t,72> subtitleTimingInfo;
};
