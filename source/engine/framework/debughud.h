#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\debughud.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3207; PDB kind: enum.
enum idDebugHUDLocal::debugTextFlags_t : __int32
{
  DTFL_COLOR = 0x1,
  DTFL_SCALE = 0x2,
  DTFL_XY = 0x4,
  DTFL_RIGHTALIGN = 0x8,
  DTFL_PERSIST = 0x10,
  DTFL_BACKGROUNDCOLOR = 0x20,
};

// IDA Local Type ordinal 17441; PDB kind: class.
class idDebugHUD
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17442.
  virtual ~idDebugHUD();
  virtual void Render(idRenderModelGui *);
  virtual void Frame();
  virtual void Clear(bool);
  virtual void Printf(const char *, ...);
  virtual void Printf_2(int, int, const char *, char *);
  virtual void Printf_3(int, int, const char *, ...);
  virtual void Printf_4(int, int, const idColor *, const idColor *, const char *, char *);
  virtual void Printf_5(int, int, const idColor *, const idColor *, const char *, ...);
  virtual void Printf_6(int, int, const idColor *, const char *, char *);
  virtual void Printf_7(int, int, const idColor *, const char *, ...);
  virtual void Printf_8(int, int, const idColor *, const float, const char *, ...);
  virtual void Printf_9(int, int, const idColor *, const float, const int, const char *, char *);
  virtual void Printf_10(int, int, const idColor *, const idColor *, const float, const char *, ...);
  virtual void Printf_11(int, int, const idColor *, const idColor *, const float, const int, const char *, char *);
  virtual void AddPersistentText(int, int, const idColor *, const float, const char *, ...);
  virtual void RemovePersistentText(int, int);
  virtual void SetLeftAlign();
  virtual void SetRightAlign();
  virtual void SetTextPosition(const int, const int);
  virtual void SetTextScale(const float);
  virtual void SetTextColor(const idColor *);

};

// IDA Local Type ordinal 23611; PDB kind: struct.
struct idDebugHUDLocal::debugText_t
{
  idStr text;
  int len;
  int x;
  int y;
  idColor color;
  int flags;
  float scale;
  idColor backgroundColor;
};

// IDA Local Type ordinal 23613; PDB kind: class.
class idDebugHUDLocal : public idDebugHUD
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23614.
  virtual ~idDebugHUDLocal();
  virtual void Render(idRenderModelGui *);
  virtual void Frame();
  virtual void Clear(bool);
  virtual void Printf(const char *, ...);
  virtual void Printf_2(int, int, const char *, char *);
  virtual void Printf_3(int, int, const char *, ...);
  virtual void Printf_4(int, int, const idColor *, const idColor *, const char *, char *);
  virtual void Printf_5(int, int, const idColor *, const idColor *, const char *, ...);
  virtual void Printf_6(int, int, const idColor *, const char *, char *);
  virtual void Printf_7(int, int, const idColor *, const char *, ...);
  virtual void Printf_8(int, int, const idColor *, const float, const char *, ...);
  virtual void Printf_9(int, int, const idColor *, const float, const int, const char *, char *);
  virtual void Printf_10(int, int, const idColor *, const idColor *, const float, const char *, ...);
  virtual void Printf_11(int, int, const idColor *, const idColor *, const float, const int, const char *, char *);
  virtual void AddPersistentText(int, int, const idColor *, const float, const char *, ...);
  virtual void RemovePersistentText(int, int);
  virtual void SetLeftAlign();
  virtual void SetRightAlign();
  virtual void SetTextPosition(const int, const int);
  virtual void SetTextScale(const float);
  virtual void SetTextColor(const idColor *);

  idList<idDebugHUDLocal::debugText_t,5> debugText;
  idList<idDebugHUDLocal::debugText_t,5> persistentText;
  idColor curColor;
  float curScale;
  int curX;
  int curY;
  int startX;
  bool alignRight;
  const idMaterial *white;
};
