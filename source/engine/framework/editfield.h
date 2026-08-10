#pragma once

#include "idlib/csystems/autocomplete.h"

class idRenderModelGui;


// IDA Local Type ordinal 23604; PDB kind: class.
class idEditField {
public:
  idEditField();
  ~idEditField();

  void Draw(idRenderModelGui* gui, int x, int y, int width,
      bool showCursor) const;
  void Clear();
  void ClearAutoComplete();
  bool AcceptAutoComplete();
  void AutoComplete(bool reverse);
  void CharEvent(int character);
  void Paste();
  void SetBuffer(const char* text);
  bool KeyDownEvent(int key);
  const char* GetBuffer() const { return buffer.c_str(); }

  bool overstrikeMode;
  int cursor;
  int scroll;
  int widthInChars;
  idStr buffer;
  idAutoComplete autoComplete;
};
