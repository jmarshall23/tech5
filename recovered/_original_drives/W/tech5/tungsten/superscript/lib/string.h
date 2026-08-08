
// ========================================================================
// ??1ssString@@QAA@XZ
// EA  : 0x82EDE870
// RVA : 0x00EDE870
// PDB : w:\tech5\tungsten\superscript\lib\string.h
// ========================================================================

// attributes: thunk
void __fastcall ssString::~ssString(ssString *this)
{
  ssString::Empty(this);
}


// ========================================================================
// ??$?0H@ssString@@QAA@ABV?$ssList@H@@PBD@Z
// EA  : 0x82EE9C10
// RVA : 0x00EE9C10
// PDB : w:\tech5\tungsten\superscript\lib\string.h
// ========================================================================

ssString *__fastcall ssString::ssString(ssString *this, const ssList<int> *list, const char *seperator)
{
  const ssString *v6; // r3
  int v7; // r30
  int v8; // r27
  const ssString *v9; // r3
  ssString v11; // [sp+60h] [-70h] BYREF
  ssString v12; // [sp+70h] [-60h] BYREF
  ssString v13[5]; // [sp+80h] [-50h] BYREF

  ssString::Init(this);
  if ( list->num > 0 )
  {
    ssString::ssString(this: &v12, i: *list->data);
    ssString::Append(this, a: v6);
    ssString::Empty(this: &v12);
  }
  v7 = 1;
  if ( list->num > 1 )
  {
    v8 = 1;
    do
    {
      ssString::Append(this, a: seperator);
      if ( v7 < 0 || v7 >= list->num )
      {
        ssString::Init(this: &v11);
        ssString::operator=(this: &v11, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v11);
        ssString::Empty(this: &v11);
      }
      ssString::ssString(this: v13, i: list->data[v8]);
      ssString::Append(this, a: v9);
      ssString::Empty(this: v13);
      ++v7;
      ++v8;
    }
    while ( v7 < list->num );
  }
  return this;
}


// ========================================================================
// __unwind$19962
// EA  : 0x82EE9D08
// RVA : 0x00EE9D08
// PDB : w:\tech5\tungsten\superscript\lib\string.h
// ========================================================================

void _unwind_19962()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$19992
// EA  : 0x82EE9D30
// RVA : 0x00EE9D30
// PDB : w:\tech5\tungsten\superscript\lib\string.h
// ========================================================================

void _unwind_19992()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$19963
// EA  : 0x82EE9D58
// RVA : 0x00EE9D58
// PDB : w:\tech5\tungsten\superscript\lib\string.h
// ========================================================================

void _unwind_19963()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 128));
}

