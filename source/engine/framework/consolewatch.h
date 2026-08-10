#pragma once

#include "idlib/text/str.h"


// IDA Local Type ordinal 21980; PDB kind: class.
class idConsoleWatch {
public:
  idConsoleWatch() : _drawX(-1), _drawY(-1) {}
  idConsoleWatch(const char* expression, int x = -1, int y = -1)
      : _watchString(expression), _drawX(x), _drawY(y) {}

  idStr _watchString;
  int _drawX;
  int _drawY;
};
