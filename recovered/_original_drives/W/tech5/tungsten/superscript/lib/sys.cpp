
// ========================================================================
// ?Warning@@YAXABVssString@@@Z
// EA  : 0x82EE8758
// RVA : 0x00EE8758
// PDB : w:\tech5\tungsten\superscript\lib\sys.cpp
// ========================================================================

void __fastcall Warning(const ssString *msg)
{
  ssObjectBase *v2; // r3
  ssString v3; // [sp+50h] [-50h] BYREF
  int v4; // [sp+60h] [-40h]
  ssString v5[3]; // [sp+70h] [-30h] BYREF

  if ( gameInterface->ThreadInfo(this: gameInterface, a2: -1, a3: (ssThreadInfo_t *)&v3.alloced) )
  {
    v3.len = v3.alloced;
    v3.data = (char *)v3.threadId;
    v2 = ssObjectBase::FullName(this: (ssObjectBase *)v5, result: &v3);
    gameInterface->Printf(
      this: gameInterface,
      a2: "^1SuperScript Warning:^3 %s.%s: %s^0\n",
      v2->objectId,
      v4,
      msg->data);
    ssString::Empty(this: v5);
    gameInterface->WaitFrame(this: gameInterface);
  }
  else
  {
    gameInterface->Printf(this: gameInterface, a2: "^1SuperScript Warning:^3 %s^0\n", msg->data);
  }
}


// ========================================================================
// __unwind$18162
// EA  : 0x82EE8828
// RVA : 0x00EE8828
// PDB : w:\tech5\tungsten\superscript\lib\sys.cpp
// ========================================================================

void _unwind_18162()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// ?Error@@YAXABVssString@@@Z
// EA  : 0x82EE8858
// RVA : 0x00EE8858
// PDB : w:\tech5\tungsten\superscript\lib\sys.cpp
// ========================================================================

void __fastcall Error(const ssString *msg)
{
  ssObjectBase *v2; // r3
  ssString v3; // [sp+50h] [-50h] BYREF
  int v4; // [sp+60h] [-40h]
  ssString v5[3]; // [sp+70h] [-30h] BYREF

  if ( gameInterface->ThreadInfo(this: gameInterface, a2: -1, a3: (ssThreadInfo_t *)&v3.alloced) )
  {
    v3.len = v3.alloced;
    v3.data = (char *)v3.threadId;
    v2 = ssObjectBase::FullName(this: (ssObjectBase *)v5, result: &v3);
    gameInterface->Printf(this: gameInterface, a2: "^1SuperScript Error:^3 %s.%s: %s^0\n", v2->objectId, v4, msg->data);
    ssString::Empty(this: v5);
    gameInterface->TerminateThread_2(this: gameInterface, a2: -1);
  }
  else
  {
    gameInterface->Printf(this: gameInterface, a2: "^1SuperScript Error:^3 %s^0\n", msg->data);
  }
}


// ========================================================================
// __unwind$18209
// EA  : 0x82EE892C
// RVA : 0x00EE892C
// PDB : w:\tech5\tungsten\superscript\lib\sys.cpp
// ========================================================================

void _unwind_18209()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}

