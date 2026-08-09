#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\regressiontest.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18726; PDB kind: class.
class idRegressionTest
{
public:
  idTestReport *testReport;
  recordState_t recordState;
  idStr testPath;
  idStr testName;
  bool fastExit;
  bool testFailed;
  int imageNum;
  char imageNumStr[5];
  int testCount;
};
