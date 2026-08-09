#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\subtitles.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1223; PDB kind: unknown.
enum idSubtitles::<unnamed_tag> : __int32
{
  LANGUAGE_UNDEF = 0x0,
  LANGUAGE_ENGLISH = 0x1,
  LANGUAGE_GERMAN = 0x2,
  LANGUAGE_FRENCH = 0x3,
  LANGUAGE_SPANISH = 0x4,
  LANGUAGE_ITALIAN = 0x5,
  LANGUAGE_POLISH = 0x6,
  LANGUAGE_RUSSIAN = 0x7,
  LANGUAGE_JAPANESE = 0x8,
  LANGUAGE_HEBREW = 0x9,
  NUM_LANGUAGES = 0xA,
  MASK_ALL = 0xFFFFFFFF,
};

// IDA Local Type ordinal 15385; PDB kind: class.
class idSubtitles::idPart
{
public:
  int flags;
  int language;
  float startTime;
  idStr phrase;
};

// IDA Local Type ordinal 21811; PDB kind: class.
class idSubtitles
{
public:
};

// IDA Local Type ordinal 29407; PDB kind: typedef.
typedef idList<idVoiceTrack::idSubtitleText,5> subtitleList_t;
