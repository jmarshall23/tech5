
// ========================================================================
// ?Decode@idBase64@@QBAHPAE@Z
// EA  : 0x82F86EC8
// RVA : 0x00F86EC8
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall idBase64::Decode(idBase64 *this, unsigned __int8 *to, __int64 a3)
{
  unsigned __int8 **v3; // r3
  int v4; // r11
  unsigned __int8 **v5; // r30
  __int64 v6; // r10
  int v8; // r28
  __int64 v9; // r8
  const char *v10; // r3
  unsigned int v11; // r31
  __int64 v12; // r10
  unsigned __int8 *v13; // r29
  int i; // r26
  unsigned int v15; // r11
  int v16; // r11
  const char *v17; // r3
  const char *v18; // r3
  unsigned __int8 *v20; // r11
  int v21; // [sp+8h] [-98h]
  int v22; // [sp+Ch] [-94h]
  int v23; // [sp+10h] [-90h]
  int v24; // [sp+14h] [-8Ch]

  v4 = (int)v3[1];
  v5 = v3;
  v8 = 0;
  LODWORD(v9) = 4 * (v4 / 4);
  HIDWORD(v9) = v4 % 4;
  if ( v4 % 4 != 0 )
  {
    v10 = "Non-Valid Base 64!";
    LODWORD(v6) = v4 >> 2;
    HIDWORD(v6) = v4 / 4;
    idLib::Warning(fmt: *(__int64 *)&to, a2: a3, a3: v9, a4: v6, a5: v21, a6: v22, a7: v23, a8: v24);
  }
  v11 = 0;
  HIDWORD(v12) = 0;
  v13 = *v5;
  if ( (int)v5[1] > 0 )
  {
    LODWORD(v12) = &unk_82390000;
    while ( 2 )
    {
      for ( i = 0; i < 4; ++i )
      {
        v15 = *v13;
        v11 <<= 6;
        if ( v15 < 0x41 || v15 > 0x5A )
        {
          if ( v15 < 0x61 || v15 > 0x7A )
          {
            if ( v15 < 0x30 || v15 > 0x39 )
            {
              if ( v15 == 43 )
              {
                v11 |= 0x3Eu;
              }
              else if ( v15 == 47 )
              {
                v11 |= 0x3Fu;
              }
              else
              {
                if ( v15 == 61 )
                {
                  LODWORD(v12) = v5[1];
                  v16 = *v5 - v13 + v12;
                  if ( v16 == 1 )
                  {
                    v20 = &to[v8 + 1];
                    to[v8] = BYTE1(v11);
                    *v20 = BYTE2(v11);
                    v20[1] = 0;
                    return v5[1];
                  }
                  if ( v16 == 2 )
                  {
                    to[v8] = v11 >> 10;
                    to[v8 + 1] = 0;
                    return v5[1];
                  }
                  v17 = "Invalid Padding in Base 64!";
                }
                else
                {
                  v18 = "Non-Valid Character in Base 64!";
                }
                idLib::Warning(fmt: *(__int64 *)&to, a2: a3, a3: v9, a4: v12, a5: v21, a6: v22, a7: v23, a8: v24);
              }
            }
            else
            {
              v11 |= v15 + 4;
            }
          }
          else
          {
            v11 |= v15 - 71;
          }
        }
        else
        {
          v11 |= v15 - 65;
        }
        ++v13;
      }
      LODWORD(v12) = BYTE1(v11);
      HIDWORD(v12) = BYTE2(v11);
      to[v8] = BYTE1(v11);
      LODWORD(v9) = (unsigned __int8)v11;
      to[v8 + 1] = BYTE2(v11);
      to[v8 + 2] = v11;
      v8 += 3;
      HIDWORD(v9) = v5[1];
      LODWORD(a3) = *v5;
      HIDWORD(a3) = v13 - *v5;
      if ( SHIDWORD(a3) < SHIDWORD(v9) )
        continue;
      break;
    }
  }
  to[v8] = 0;
  return v5[1];
}


// ========================================================================
// ?Encode@idBase64@@QAAXPBEH@Z
// EA  : 0x82F87088
// RVA : 0x00F87088
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void __fastcall idBase64::Encode(idBase64 *this, const unsigned __int8 *from, int size)
{
  const unsigned __int8 *v6; // r11
  int v7; // ctr
  int v8; // r9
  unsigned __int8 *v9; // r11
  int v10; // r8
  unsigned int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r30
  unsigned __int8 *data; // r5
  int v16; // r9
  unsigned __int8 *v17; // r3
  int v18; // r9
  unsigned __int8 *v19; // r7
  int v20; // r9
  unsigned int v21; // r11
  int v22; // r3
  int v23; // r8
  unsigned __int8 *v24; // r9
  int v25; // r11
  unsigned __int8 *v26; // r5
  int v27; // r11
  unsigned __int8 *v28; // r3
  int v29; // r11
  unsigned int v30; // r7
  unsigned __int8 *v31; // r8
  int v32; // r11
  unsigned __int8 *v33; // r5
  int v34; // r11
  int v35; // r11
  unsigned __int8 *v36; // r4

  idBase64::EnsureAlloced(this, size: 4 * (size + 3) / 3 + 2);
  this->len = 0;
  v6 = from;
  if ( size / 3 > 0 )
  {
    v7 = size / 3;
    do
    {
      v8 = *v6;
      v9 = (unsigned __int8 *)(v6 + 1);
      v10 = __ROL4__(*v9++, 8);
      v11 = *v9 + v10 + __ROL4__(v8, 16);
      v6 = v9 + 1;
      v12 = (v11 >> 12) & 0x3F;
      v13 = (v11 >> 6) & 0x3F;
      v14 = v11 & 0x3F;
      this->data[this->len] = encodeLookup[(v11 >> 18) & 0x3F];
      data = this->data;
      v16 = this->len + 1;
      this->len = v16;
      data[v16] = encodeLookup[v12];
      v17 = this->data;
      v18 = this->len + 1;
      this->len = v18;
      v17[v18] = encodeLookup[v13];
      v19 = this->data;
      v20 = this->len + 1;
      this->len = v20;
      v19[v20] = encodeLookup[v14];
      ++this->len;
      --v7;
    }
    while ( v7 != 0 );
  }
  if ( size % 3 == 1 )
  {
    v30 = __ROL4__(*v6, 16);
    this->data[this->len] = encodeLookup[(v30 >> 18) & 0x3F];
    v31 = this->data;
    v32 = this->len + 1;
    this->len = v32;
    v31[v32] = encodeLookup[(v30 >> 12) & 0x3F];
    v33 = this->data;
    v34 = this->len + 1;
    this->len = v34;
    v33[v34] = 61;
    v35 = this->len + 1;
    v36 = this->data;
    this->len = v35;
    v36[v35] = 61;
    ++this->len;
  }
  else if ( size % 3 == 2 )
  {
    v21 = (__ROL4__(*v6, 8) + v6[1]) << 8;
    v22 = (v21 >> 6) & 0x3F;
    v23 = (v21 >> 12) & 0x3F;
    this->data[this->len] = encodeLookup[(v21 >> 18) & 0x3F];
    v24 = this->data;
    v25 = this->len + 1;
    this->len = v25;
    v24[v25] = encodeLookup[v23];
    v26 = this->data;
    v27 = this->len + 1;
    this->len = v27;
    v26[v27] = encodeLookup[v22];
    v28 = this->data;
    v29 = this->len + 1;
    this->len = v29;
    v28[v29] = 61;
    this->data[++this->len] = 0;
    return;
  }
  this->data[this->len] = 0;
}


// ========================================================================
// ?testBase64_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F872C8
// RVA : 0x00F872C8
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void __fastcall testBase64_f(const idCmdArgs *args)
{
  unsigned __int8 *data; // r28
  unsigned __int8 *v2; // r30
  __int64 v3; // r6
  __int64 v4; // r8
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r4
  int v17; // [sp+8h] [-128h]
  int v18; // [sp+8h] [-128h]
  int v19; // [sp+8h] [-128h]
  int v20; // [sp+8h] [-128h]
  int v21; // [sp+Ch] [-124h]
  int v22; // [sp+Ch] [-124h]
  int v23; // [sp+Ch] [-124h]
  int v24; // [sp+Ch] [-124h]
  int v25; // [sp+10h] [-120h]
  int v26; // [sp+10h] [-120h]
  int v27; // [sp+10h] [-120h]
  int v28; // [sp+10h] [-120h]
  int v29; // [sp+14h] [-11Ch]
  int v30; // [sp+14h] [-11Ch]
  int v31; // [sp+14h] [-11Ch]
  int v32; // [sp+14h] [-11Ch]
  idBase64 v33; // [sp+50h] [-E0h] BYREF
  idBase64 v34; // [sp+60h] [-D0h] BYREF
  unsigned __int8 *v35; // [sp+70h] [-C0h]
  unsigned int v36; // [sp+74h] [-BCh]
  idStr v37; // [sp+80h] [-B0h] BYREF
  idStr v38; // [sp+A0h] [-90h] BYREF
  idStr v39; // [sp+C0h] [-70h] BYREF
  idStr v40[2]; // [sp+E0h] [-50h] BYREF

  idStr::idStr(this: &v37, text: testBase64Str.valueString.data);
  memset(&v34, 0, sizeof(v34));
  idBase64::Encode(this: &v34, from: (const unsigned __int8 *)v37.data, size: v37.len);
  data = v34.data;
  idStr::idStr(this: &v38, text: (const char *)v34.data);
  idStr::idStr(this: v40, text: v38.data);
  memset(&v33, 0, sizeof(v33));
  idBase64::operator=(this: &v33, s: v40);
  idStr::FreeData(this: v40);
  v36 = 3 * v33.len / 4;
  v2 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                            size: v36,
                            tag: TAG_TEMP,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v35 = v2;
  idBase64::Decode(this: &v33, to: v2, a3: v3);
  idStr::idStr(this: &v39, text: (const char *)v2);
  HIDWORD(v4) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("Input: [%s]\n", (unsigned int)testBase64Str.valueString.data),
    a2: v6,
    a3: v4,
    a4: v5,
    a5: v17,
    a6: v21,
    a7: v25,
    a8: v29);
  LODWORD(v7) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("Encoded: [%s]\n", (unsigned int)v38.data),
    a2: v7,
    a3: v9,
    a4: v8,
    a5: v18,
    a6: v22,
    a7: v26,
    a8: v30);
  HIDWORD(v10) = &unk_82390000;
  idLib::Printf(
    fmt: __SPAIR64__("Decoded: [%s]\n", (unsigned int)v39.data),
    a2: v10,
    a3: v12,
    a4: v11,
    a5: v19,
    a6: v23,
    a7: v27,
    a8: v31);
  if ( idStr::Cmp(s1: v39.data, s2: v37.data) != 0 )
    LODWORD(v16) = "^1FAILED";
  else
    LODWORD(v16) = "^2PASSED";
  HIDWORD(v16) = "^0[%s^0]\n";
  idLib::Printf(fmt: v16, a2: v15, a3: v14, a4: v13, a5: v20, a6: v24, a7: v28, a8: v32);
  idStr::FreeData(this: &v39);
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  if ( v33.data != nullptr )
    idMem::Free(this: &mem, ptr: v33.data, align: ALIGN_16);
  idStr::FreeData(this: &v38);
  if ( data != nullptr )
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
  idStr::FreeData(this: &v37);
}


// ========================================================================
// __unwind$111497
// EA  : 0x82F87474
// RVA : 0x00F87474
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111497()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$111498
// EA  : 0x82F8749C
// RVA : 0x00F8749C
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111498()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$111499
// EA  : 0x82F874C4
// RVA : 0x00F874C4
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111499()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$111500
// EA  : 0x82F874EC
// RVA : 0x00F874EC
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 224));
}


// ========================================================================
// __unwind$111501
// EA  : 0x82F87514
// RVA : 0x00F87514
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111501()
{
  int v0; // r12

  idBase64::~idBase64(this: (idBase64 *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$111502
// EA  : 0x82F8753C
// RVA : 0x00F8753C
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111502()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$111503
// EA  : 0x82F87564
// RVA : 0x00F87564
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void _unwind_111503()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 192));
}


// ========================================================================
// `dynamic initializer for 'testBase64Str''
// EA  : 0x833973B0
// RVA : 0x013973B0
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__testBase64Str__()
{
  idCVar::idCVar(
    this: &testBase64Str,
    name: "testBase64Str",
    value: "user/shawn/level_transition_b",
    flags: 0,
    description: "sample base64 string used by testBase64",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__testBase64Str__);
}


// ========================================================================
// `dynamic initializer for 'testBase64_v''
// EA  : 0x83397408
// RVA : 0x01397408
// PDB : w:\tech5\shared\idlib\text\base64.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testBase64_v__()
{
  return idCommandLink::idCommandLink(
           this: &testBase64_v,
           cmdName: "testBase64",
           function: testBase64_f,
           description: "Tests base64 encode/decode with testBase64Str cvar",
           argCompletion: nullptr);
}

