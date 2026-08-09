#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\voiceovers\annosofterrorcodes.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1307; PDB kind: enum.
enum annosoftError_t : __int32
{
  ANNOSOFT_ERROR_SUCCESS = 0x0,
  ANNOSOFT_ERROR_CMDLINE_SYNC = 0x3E8,
  ANNOSOFT_ERROR_NO_PHONEME_FILE = 0x3E9,
  ANNOSOFT_ERROR_PHONEME_GEN_FAILED = 0x3EA,
  ANNOSOFT_ERROR_INTERNAL = 0x1388,
  ANNOSOFT_ERROR_NO_TEXT = 0x1389,
  ANNOSOFT_ERROR_NO_SAMPLE_NAME = 0x138A,
  ANNOSOFT_ERROR_INTERMEDIATE_PATH_FAILED = 0x138B,
  ANNOSOFT_ERROR_WRITING_TEXT = 0x138C,
  ANNOSOFT_ERROR_REGENED_AS_TEXTLESS = 0x138D,
};
