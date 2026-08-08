
// ========================================================================
// ?AssertionFailed@@YAXPBD@Z
// EA  : 0x82EE06E0
// RVA : 0x00EE06E0
// PDB : w:\tech5\tungsten\superscript\lib\sys.h
// ========================================================================

void __fastcall AssertionFailed(const char *msg)
{
  ssString v2; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v2);
  ssString::operator=(this: &v2, text: msg);
  Error(msg: &v2);
  ssString::Empty(this: &v2);
}


// ========================================================================
// __unwind$20437
// EA  : 0x82EE0738
// RVA : 0x00EE0738
// PDB : w:\tech5\tungsten\superscript\lib\sys.h
// ========================================================================

void _unwind_20437()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetTime@@YAMXZ
// EA  : 0x82EE8BF8
// RVA : 0x00EE8BF8
// PDB : w:\tech5\tungsten\superscript\lib\sys.h
// ========================================================================

float __fastcall GetTime()
{
  double v0; // fp1

  v0 = (float)((float)__SPAIR64__(&off_82040000, gameInterface->GetTime(this: gameInterface)) * (float)0.001);
  return *((float *)&v0 + 1);
}

