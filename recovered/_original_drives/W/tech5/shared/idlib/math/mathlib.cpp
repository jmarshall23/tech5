
// ========================================================================
// ?InterleaveBits@@YAHHH@Z
// EA  : 0x82F36620
// RVA : 0x00F36620
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

int __fastcall InterleaveBits(__int16 x, __int16 y)
{
  return (2
        * ((2
          * ((2
            * ((2
              * ((2
                * ((2
                  * ((2
                    * ((2
                      * ((2
                        * ((2
                          * ((2
                            * ((2
                              * ((2
                                * ((2 * (y & 0x2000 | (2 * (x & 0x8000 | y & 0x7FFF)) & 0x18000 | x & 0x5FFF)) & 0x3C000
                                 | x & 0x2000
                                 | y & 0x1000))
                               | x & 0x1000
                               | y & 0x800))
                             | x & 0x800
                             | y & 0x400))
                           | x & 0x400
                           | y & 0x200))
                         | x & 0x200
                         | y & 0x100))
                       | x & 0x100
                       | y & 0x80))
                     | x & 0x80
                     | y & 0x40))
                   | x & 0x40
                   | y & 0x20))
                 | x & 0x20
                 | y & 0x10))
               | x & 0x10
               | y & 8))
             | x & 8
             | y & 4))
           | x & 4
           | y & 2))
         | x & 2
         | y & 1))
       | x & 1;
}


// ========================================================================
// ?DeInterleaveBits@@YAXHAAH0@Z
// EA  : 0x82F36750
// RVA : 0x00F36750
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

void __fastcall DeInterleaveBits(const int bits, int *x, int *y)
{
  int v3; // r11
  int v4; // r10
  int i; // ctr
  int v6; // r11

  v3 = 1;
  *x = 0;
  v4 = 1;
  *y = 0;
  for ( i = 15; i != 0; --i )
  {
    if ( (v3 & bits) != 0 )
      *x |= v4;
    v6 = 2 * v3;
    if ( (v6 & bits) != 0 )
      *y |= v4;
    v3 = 2 * v6;
    v4 *= 2;
  }
}


// ========================================================================
// ?TestDeInterleaveBits_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F367B0
// RVA : 0x00F367B0
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

void __fastcall TestDeInterleaveBits_f(const idCmdArgs *args)
{
  int i; // r31
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // [sp+8h] [-78h]
  int v6; // [sp+Ch] [-74h]
  int v7; // [sp+10h] [-70h]
  int v8; // [sp+14h] [-6Ch]
  int v9; // [sp+50h] [-30h] BYREF
  int v10; // [sp+54h] [-2Ch] BYREF

  for ( i = 0; i < 0x10000; ++i )
  {
    DeInterleaveBits(bits: i, x: &v10, y: &v9);
    if ( InterleaveBits(x: v10, y: v9) != i )
      idLib::Printf(fmt: __SPAIR64__("Testnum %i failed\n", i), a2: v4, a3: v3, a4: v2, a5: v5, a6: v6, a7: v7, a8: v8);
  }
}


// ========================================================================
// ?TestSignBit_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F36810
// RVA : 0x00F36810
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

void __fastcall TestSignBit_f(const idCmdArgs *args, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // r31
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+14h] [-5Ch]

  LODWORD(a5) = &unk_82390000;
  v5 = -1;
  do
  {
    HIDWORD(a3) = (unsigned int)v5 >> 31;
    idLib::Printf(
      fmt: __SPAIR64__("INT32_SIGNBITSET( %i ) = %i\n", v5),
      a2: a3,
      a3: a4,
      a4: a5,
      a5: v9,
      a6: v11,
      a7: v13,
      a8: v15);
    HIDWORD(v6) = v5 >= 0;
    idLib::Printf(
      fmt: __SPAIR64__("INT32_SIGNBITNOTSET( %i ) = %i\n", v5++),
      a2: v6,
      a3: v8,
      a4: v7,
      a5: v10,
      a6: v12,
      a7: v14,
      a8: v16);
  }
  while ( v5 <= 0 );
}


// ========================================================================
// `dynamic initializer for 'idMath::ONE_OVER_TWO_PI''
// EA  : 0x83395898
// RVA : 0x01395898
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

void _dynamic_initializer_for__idMath::ONE_OVER_TWO_PI__()
{
  idMath::ONE_OVER_TWO_PI = (float)1.0 / idMath::TWO_PI;
}


// ========================================================================
// `dynamic initializer for 'TestSignBit_v''
// EA  : 0x833958B8
// RVA : 0x013958B8
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestSignBit_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestSignBit_v,
           cmdName: "TestSignBit",
           function: (void (__fastcall *)(const idCmdArgs *))TestSignBit_f,
           description: "Test the INT32_SIGNBIT functions",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestDeInterleaveBits_v''
// EA  : 0x833958E0
// RVA : 0x013958E0
// PDB : w:\tech5\shared\idlib\math\mathlib.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestDeInterleaveBits_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestDeInterleaveBits_v,
           cmdName: "TestDeInterleaveBits",
           function: TestDeInterleaveBits_f,
           description: "test bit extract",
           argCompletion: nullptr);
}

