
// ========================================================================
// ??0idMD6PhaseTrack@@QAA@XZ
// EA  : 0x828507B0
// RVA : 0x008507B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void __fastcall idMD6PhaseTrack::idMD6PhaseTrack(idStreamFileLog *this)
{
  this->numEntries = 0;
}


// ========================================================================
// ??1idMD6PhaseTrack@@QAA@XZ
// EA  : 0x828507C0
// RVA : 0x008507C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void __fastcall idMD6PhaseTrack::~idMD6PhaseTrack(idMD6PhaseTrack *this)
{
  if ( this->data != nullptr )
  {
    idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
    this->data = nullptr;
  }
}


// ========================================================================
// ?WriteText@idMD6PhaseTrack@@QAA_NPBDPBVidMD6Skel@@PBVidMD6Anim@@000@Z
// EA  : 0x82850818
// RVA : 0x00850818
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

int __fastcall idMD6PhaseTrack::WriteText(
        idMD6PhaseTrack *this,
        const char *fileName,
        const idMD6Skel *skel,
        const idMD6Anim *anim,
        const char *leftAnkleJointName,
        const char *rightAnkleJointName,
        const char *originJointName)
{
  char *v14; // r23
  char *v15; // r26
  int v16; // r29
  int v17; // r30
  int v18; // r30
  int v19; // r29
  float *v20; // r27
  idFile *v21; // r30
  idFile_vtbl *v23; // r29
  char *filePtr; // r28
  unsigned int v25; // r3
  idFile_Memory v26; // [sp+60h] [-1B0h] BYREF

  idFile_Memory::idFile_Memory(this: &v26, name: fileName);
  idFile::Printf(this: &v26, fmt: "%s version %d\n", PHASETRACK_TEXT_ID, 1);
  idFile::Printf(this: &v26, fmt: "init {\n");
  idFile::Printf(this: &v26, fmt: "\tdependentAnimName \"%s\"\n", anim->name.str);
  idFile::Printf(this: &v26, fmt: "\tdependentAnimTimestamp %d\n", anim->timestamp);
  idFile::Printf(this: &v26, fmt: "\tdependentSkelName \"%s\"\n", skel->name.str);
  idFile::Printf(this: &v26, fmt: "\tleftAnkleJoint \"%s\"\n", leftAnkleJointName);
  idFile::Printf(this: &v26, fmt: "\trightAnkleJoint \"%s\"\n", rightAnkleJointName);
  idFile::Printf(this: &v26, fmt: "\toriginJoint \"%s\"\n", originJointName);
  idFile::Printf(this: &v26, fmt: "\tnumFrames %d\n", this->data->numFrames);
  idFile::Printf(this: &v26, fmt: "}\n");
  v14 = nullptr;
  v15 = (char *)this->data + this->data->ofsPhaseTable;
  if ( this->data->ofsDistanceRemainingTable != 0 )
    v14 = (char *)this->data + this->data->ofsDistanceRemainingTable;
  idFile::Printf(this: &v26, fmt: "phase {\n\t");
  v16 = 0;
  v17 = 0;
  if ( this->data->numFrames != 0 )
  {
    do
    {
      if ( v16 > 20 )
      {
        v16 = 0;
        idFile::Printf(this: &v26, fmt: "\n\t");
      }
      idFile::Printf(this: &v26, fmt: "%d ", (unsigned __int8)v15[v17++]);
      ++v16;
    }
    while ( v17 < this->data->numFrames );
  }
  idFile::Printf(this: &v26, fmt: "\n}\n");
  if ( v14 != nullptr )
  {
    idFile::Printf(this: &v26, fmt: "distanceRemaining {\n\t");
    v18 = 0;
    v19 = 0;
    if ( this->data->numFrames != 0 )
    {
      v20 = (float *)(v14 - 4);
      do
      {
        if ( v18 > 9 )
        {
          v18 = 0;
          idFile::Printf(this: &v26, fmt: "\n\t");
        }
        ++v20;
        idFile::Printf(
          this: &v26,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*v20)),
          (unsigned int)COERCE_UNSIGNED_INT64(*v20));
        ++v19;
        ++v18;
      }
      while ( v19 < this->data->numFrames );
    }
    idFile::Printf(this: &v26, fmt: "\n}\n");
  }
  v21 = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName, a3: 0);
  if ( v21 != nullptr )
  {
    v23 = v21->__vftable;
    filePtr = v26.filePtr;
    v25 = (unsigned __int64)idFile_Memory::Length(this: &v26) >> 32;
    v23->Write(this: v21, a2: filePtr, a3: v25);
    ((void (__fastcall *)(idFile *, int))v21->dtr_idFile)(a1: v21, a2: 1);
    idFile_Memory::~idFile_Memory(this: &v26);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Couldn't open file '%s' for writing", fileName);
    idFile_Memory::~idFile_Memory(this: &v26);
    return 0;
  }
}


// ========================================================================
// __unwind$221178
// EA  : 0x82850AF8
// RVA : 0x00850AF8
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221178()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 528 + 96));
}


// ========================================================================
// ?CreatePhaseTrackData@idMD6PhaseTrack@@ABAPAUphaseTrackData_t@@PBVidMD6Skel@@PBVidMD6Anim@@ABV?$idList@E$04@@ABV?$idList@M$04@@@Z
// EA  : 0x82850B20
// RVA : 0x00850B20
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

phaseTrackData_t *__fastcall idMD6PhaseTrack::CreatePhaseTrackData(
        idMD6PhaseTrack *this,
        const idMD6Skel *skel,
        const idMD6Anim *anim,
        const idList<unsigned char,5> *phaseTable,
        const idList<float,5> *distanceTable)
{
  __int64 v5; // r28
  int num; // r10
  unsigned __int16 v9; // r11
  size_t v10; // r27
  _QWORD *v11; // r31
  int v12; // r10
  char *v13; // r3
  unsigned int v15; // [sp+54h] [-3Ch]
  __int64 v16; // [sp+58h] [-38h]

  LODWORD(v5) = 0;
  v16 = v5;
  num = distanceTable->num;
  HIWORD(v15) = 16;
  v9 = ((HIWORD(phaseTable->num) + 15) & 0xFFF0) + 16;
  if ( num != 0 )
  {
    LOWORD(v15) = ((HIWORD(phaseTable->num) + 15) & 0xFFF0) + 16;
    v9 += (4 * num + 15) & 0xFFF0;
  }
  else
  {
    LOWORD(v15) = 0;
  }
  v10 = v9;
  v11 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6PhaseTrack.cpp(395) : TAG_MD6_PHASE_TRACK",
          size: v9,
          tag: TAG_MD6_PHASE_TRACK,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  memset(Dst: v11, Val: 0, Size: v10);
  *v11 = __PAIR64__(v16, v15);
  v11[1] = v16;
  memcpy(Dst: (char *)v11 + *((unsigned __int16 *)v11 + 2), Src: phaseTable->list, Size: phaseTable->num);
  v12 = distanceTable->num;
  if ( v12 > 0 )
  {
    v13 = nullptr;
    if ( *((_WORD *)v11 + 3) != 0 )
      v13 = (char *)v11 + *((unsigned __int16 *)v11 + 3);
    memcpy(Dst: v13, Src: distanceTable->list, Size: 4 * v12);
  }
  return (phaseTrackData_t *)v11;
}


// ========================================================================
// ?GetPhase@idMD6PhaseTrack@@QBA_NHAAE@Z
// EA  : 0x82850C58
// RVA : 0x00850C58
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

int __fastcall idMD6PhaseTrack::GetPhase(idMD6PhaseTrack *this, const int frame, unsigned __int8 *phase)
{
  phaseTrackData_t *data; // r11

  data = this->data;
  if ( this->data != nullptr && frame >= 0 && frame < data->numFrames )
  {
    *phase = *((_BYTE *)&data->totalSize + data->ofsPhaseTable + frame);
    return 1;
  }
  else
  {
    *phase = 0;
    return 0;
  }
}


// ========================================================================
// ?IsValid@idMD6PhaseTrack@@QBA_NPBVidMD6Anim@@@Z
// EA  : 0x82850CA0
// RVA : 0x00850CA0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

int __fastcall idMD6PhaseTrack::IsValid(idMD6PhaseTrack *this, const idMD6Anim *anim)
{
  phaseTrackData_t *data; // r10
  idMD6AnimData *animData; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  data = this->data;
  if ( this->data == nullptr || (phaseTrackData_t *)((char *)data + data->ofsPhaseTable) == nullptr )
    return 0;
  animData = anim->animData;
  if ( animData != nullptr )
    animData = (idMD6AnimData *)animData->numFrames;
  v5 = data->numFrames == (_DWORD)animData;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}


// ========================================================================
// ?LoadBinary@idMD6PhaseTrack@@QAA_NPAVidFile@@@Z
// EA  : 0x82850EB0
// RVA : 0x00850EB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

phaseTrackData_t *__fastcall idMD6PhaseTrack::LoadBinary(idMD6PhaseTrack *this, idFile *file)
{
  phaseTrackData_t *result; // r3
  unsigned __int16 v5; // [sp+50h] [-30h] BYREF

  if ( this->data != nullptr )
  {
    idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
    this->data = nullptr;
  }
  file->Read(this: file, a2: &v5, a3: 2u);
  if ( v5 != 0 )
  {
    result = (phaseTrackData_t *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6PhaseTrack.cpp(124) : TAG_MD6_PHASE_TRACK",
                                   size: v5,
                                   tag: TAG_MD6_PHASE_TRACK,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    this->data = result;
    if ( result == nullptr )
      return result;
    file->Read(this: file, a2: &result->numFrames, a3: v5 - 2);
    this->data->totalSize = v5;
  }
  return (phaseTrackData_t *)1;
}


// ========================================================================
// ?WriteBinary@idMD6PhaseTrack@@QAA_NPAVidFile@@@Z
// EA  : 0x82850F80
// RVA : 0x00850F80
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

int __fastcall idMD6PhaseTrack::WriteBinary(idMD6PhaseTrack *this, idFile *file)
{
  idFile_vtbl *v2; // r9
  _WORD v4[4]; // [sp+50h] [-10h] BYREF

  if ( this->data != nullptr )
  {
    file->Write(this: file, a2: this->data, a3: this->data->totalSize);
  }
  else
  {
    v2 = file->__vftable;
    v4[0] = 0;
    v2->Write(this: file, a2: v4, a3: 2u);
  }
  return 1;
}


// ========================================================================
// ?LoadText@idMD6PhaseTrack@@QAA_NPBDPBVidMD6Anim@@@Z
// EA  : 0x82851468
// RVA : 0x00851468
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

BOOL __fastcall idMD6PhaseTrack::LoadText(idMD6PhaseTrack *this, const char *fileName, const idMD6Anim *anim)
{
  idMD6AnimData *animData; // r11
  int numFrames; // r18
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  unsigned int v19; // r3
  va *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  va *v24; // r3
  int len; // r30
  va *v26; // r3
  va *v27; // r3
  va *v28; // r3
  int v29; // r11
  __int64 v30; // r6
  va *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  va *v35; // r3
  idVehicleState **list; // r28
  int i; // r30
  float *v38; // r28
  int j; // r30
  const idMD6Skel *v40; // r4
  phaseTrackData_t *v41; // r3
  BOOL v42; // r30
  int v44; // [sp+8h] [-1488h]
  int v45; // [sp+Ch] [-1484h]
  int v46; // [sp+10h] [-1480h]
  int v47; // [sp+14h] [-147Ch]
  int v48; // [sp+18h] [-1478h]
  int v49; // [sp+1Ch] [-1474h]
  char v50; // [sp+50h] [-1440h]
  char v51; // [sp+51h] [-143Fh] BYREF
  char v52; // [sp+52h] [-143Eh] BYREF
  char v53; // [sp+53h] [-143Dh] BYREF
  char v54; // [sp+54h] [-143Ch] BYREF
  char v55; // [sp+55h] [-143Bh] BYREF
  char v56; // [sp+56h] [-143Ah] BYREF
  char v57; // [sp+57h] [-1439h] BYREF
  _BYTE v58[8]; // [sp+58h] [-1438h] BYREF
  idList<float,5> v59; // [sp+60h] [-1430h] BYREF
  idList<idVehicleState *,5> v60; // [sp+70h] [-1420h] BYREF
  idStr v61; // [sp+80h] [-1410h] BYREF
  idStr v62; // [sp+A0h] [-13F0h] BYREF
  idLexer v63; // [sp+C0h] [-13D0h] BYREF
  idToken v64; // [sp+150h] [-1340h] BYREF
  char v65; // [sp+198h] [-12F8h] BYREF
  idToken v66; // [sp+2A0h] [-11F0h] BYREF
  char v67; // [sp+2E8h] [-11A8h] BYREF
  va v68; // [sp+3F0h] [-10A0h] BYREF

  if ( this->data != nullptr )
  {
    idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
    this->data = nullptr;
  }
  idLexer::idLexer(this: &v63, flags_: 262704);
  if ( idLexer::LoadFile(this: &v63, filename_: fileName, OSPath: false) )
  {
    animData = anim->animData;
    numFrames = 0;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    memset(&v60, 0, 14);
    *(_WORD *)&v60.memTag = 1280;
    idList<idThread *,58>::Clear(this: &v60);
    memset(&v59, 0, 14);
    *(_WORD *)&v59.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59);
    v62.len = 0;
    v62.allocedAndFlag = 20;
    v62.data = v62.baseBuffer;
    v62.baseBuffer[0] = 0;
    v61.allocedAndFlag = 20;
    v61.data = v61.baseBuffer;
    v61.len = 0;
    v61.baseBuffer[0] = 0;
    v64.baseBuffer[0] = 0;
    v64.intvalue = 0;
    memset(&v64.whiteSpaceStart_p, 0, 12);
    v64.floatvalue = -3.4028235e38;
    v65 = 0;
    v64.data = &v65;
    v64.len = 0;
    v64.allocedAndFlag = -2147483392;
    idLexer::ExpectTokenString(this: &v63, string: PHASETRACK_TEXT_ID);
    idLexer::ExpectTokenString(this: &v63, string: "version");
    idLexer::ExpectTokenType(this: &v63, type: 3, subtype: 1, token: &v64);
    HIDWORD(v10) = atol(nptr: v64.data);
    if ( HIDWORD(v10) != 1 )
    {
      LODWORD(v10) = 1;
      v11 = va::va(
              this: &v68,
              fmt: "wrong version number.  Found '%d' should be '%d'.",
              a3: v10,
              a4: v9,
              a5: v8,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v11->buffer, count: 0x800u);
      v51 = v50;
      CxxThrowException(pExceptionObject: &v51, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    idLexer::ExpectTokenString(this: &v63, string: "init");
    idLexer::ExpectTokenType(this: &v63, type: 5, subtype: 46, token: &v64);
    while ( idLexer::ReadToken(this: &v63, token: &v64) && (v64.type != 5 || v64.subtype != 47) )
    {
      if ( idStr::Icmp(s1: v64.data, s2: "dependentAnimName") != 0 )
      {
        if ( idStr::Icmp(s1: v64.data, s2: "dependentSkelName") != 0
          && idStr::Icmp(s1: v64.data, s2: "dependentModelName") != 0 )
        {
          if ( idStr::Icmp(s1: v64.data, s2: "dependentAnimTimestamp") != 0 )
          {
            if ( idStr::Icmp(s1: v64.data, s2: "numFrames") != 0 )
            {
              if ( idStr::Icmp(s1: v64.data, s2: "leftAnkleJoint") != 0
                && idStr::Icmp(s1: v64.data, s2: "rightAnkleJoint") != 0
                && idStr::Icmp(s1: v64.data, s2: "originJoint") != 0 )
              {
                HIDWORD(v23) = v64.data;
                v24 = va::va(
                        this: &v68,
                        fmt: "unknown token '%s'",
                        a3: v23,
                        a4: v22,
                        a5: v21,
                        a6: v44,
                        a7: v45,
                        a8: v46,
                        a9: v47,
                        a10: v48,
                        a11: v49);
                strncpy(dest: idException::error, source: v24->buffer, count: 0x800u);
                v53 = v50;
                CxxThrowException(pExceptionObject: &v53, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
              }
              idLexer::ExpectTokenType(this: &v63, type: 1, subtype: 0, token: &v64);
            }
            else
            {
              v19 = idLexer::ParseInt(this: &v63);
              numFrames = v19;
              if ( v19 >= 0x10000 )
              {
                HIDWORD(v18) = v19;
                v20 = va::va(
                        this: &v68,
                        fmt: "numFrames (%d) is out of range",
                        a3: v18,
                        a4: v17,
                        a5: v16,
                        a6: v44,
                        a7: v45,
                        a8: v46,
                        a9: v47,
                        a10: v48,
                        a11: v49);
                strncpy(dest: idException::error, source: v20->buffer, count: 0x800u);
                v58[0] = v50;
                CxxThrowException(pExceptionObject: v58, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
              }
            }
          }
          else
          {
            idLexer::ParseUnsignedInt(this: &v63);
          }
        }
        else
        {
          idLexer::ExpectTokenType(this: &v63, type: 1, subtype: 0, token: &v64);
          len = v64.len;
          idStr::EnsureAlloced(this: &v61, amount: v64.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v61.data, Src: v64.data, Size: len);
          v61.data[len] = 0;
          v61.len = len;
        }
      }
      else
      {
        idLexer::ExpectTokenType(this: &v63, type: 1, subtype: 0, token: &v64);
        v15 = v64.len;
        idStr::EnsureAlloced(this: &v62, amount: v64.len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v62.data, Src: v64.data, Size: v15);
        v62.data[v15] = 0;
        v62.len = v15;
      }
    }
    if ( numFrames == 0 )
    {
      HIDWORD(v14) = fileName;
      v26 = va::va(
              this: &v68,
              fmt: "%s: init section missing numFrames.",
              a3: v14,
              a4: v13,
              a5: v12,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v26->buffer, count: 0x800u);
      v57 = v50;
      CxxThrowException(pExceptionObject: &v57, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    if ( v62.len == 0 )
    {
      HIDWORD(v14) = fileName;
      v27 = va::va(
              this: &v68,
              fmt: "%s: init section missing dependentAnimName.",
              a3: v14,
              a4: v13,
              a5: v12,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v27->buffer, count: 0x800u);
      v55 = v50;
      CxxThrowException(pExceptionObject: &v55, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    if ( v61.len == 0 )
    {
      HIDWORD(v14) = fileName;
      v28 = va::va(
              this: &v68,
              fmt: "%s: init section missing dependentAnimSkelName.",
              a3: v14,
              a4: v13,
              a5: v12,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v28->buffer, count: 0x800u);
      v52 = v50;
      CxxThrowException(pExceptionObject: &v52, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    LODWORD(v12) = anim->animData;
    v29 = 0;
    if ( (_DWORD)v12 != 0 )
      v29 = *(unsigned __int16 *)(v12 + 8);
    if ( numFrames != v29 )
    {
      LODWORD(v30) = 0;
      if ( (_DWORD)v12 != 0 )
        LODWORD(v30) = *(unsigned __int16 *)(v12 + 8);
      HIDWORD(v30) = numFrames;
      v31 = va::va(
              this: &v68,
              fmt: "Phase track num frames %d does not match loading anim num frames '%d'",
              a3: v30,
              a4: v13,
              a5: v12,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v31->buffer, count: 0x800u);
      v54 = v50;
      CxxThrowException(pExceptionObject: &v54, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    if ( idStr::Icmp(s1: v62.data, s2: anim->name.str) != 0 )
    {
      LODWORD(v34) = anim->name.str;
      HIDWORD(v34) = v62.data;
      v35 = va::va(
              this: &v68,
              fmt: "Dependent anim name '%s' does not match loading anim '%s'",
              a3: v34,
              a4: v33,
              a5: v32,
              a6: v44,
              a7: v45,
              a8: v46,
              a9: v47,
              a10: v48,
              a11: v49);
      strncpy(dest: idException::error, source: v35->buffer, count: 0x800u);
      v56 = v50;
      CxxThrowException(pExceptionObject: &v56, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    v66.floatvalue = -3.4028235e38;
    v66.baseBuffer[0] = 0;
    v66.intvalue = 0;
    memset(&v66.whiteSpaceStart_p, 0, 12);
    v67 = 0;
    v66.data = &v67;
    v66.len = 0;
    v66.allocedAndFlag = -2147483392;
    idLexer::ExpectTokenString(this: &v63, string: "phase");
    idLexer::ExpectTokenType(this: &v63, type: 5, subtype: 46, token: &v66);
    idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v60, newNum: numFrames);
    list = v60.list;
    for ( i = 0; i < numFrames; ++i )
      *((_BYTE *)list + i) = idLexer::ParseInt(this: &v63);
    idLexer::ExpectTokenType(this: &v63, type: 5, subtype: 47, token: &v66);
    if ( idLexer::CheckTokenString(this: &v63, string: "distanceRemaining") )
    {
      idLexer::ExpectTokenType(this: &v63, type: 5, subtype: 46, token: &v66);
      idList<float,5>::SetNum(this: &v59, newNum: numFrames);
      v38 = v59.list;
      for ( j = 0; j < numFrames; ++j )
        v38[j] = idLexer::ParseFloat(this: &v63, errorFlag: nullptr);
      idLexer::ExpectTokenType(this: &v63, type: 5, subtype: 47, token: &v66);
    }
    idStr::FreeData(this: &v66);
    v40 = (const idMD6Skel *)idResourceList::Load(
                               this: &idMD6Skel::resourceList,
                               name: v61.data,
                               makeDefault: false,
                               skipStaleCheck: false);
    if ( v40 != nullptr )
    {
      v41 = idMD6PhaseTrack::CreatePhaseTrackData(
              this,
              skel: v40,
              anim,
              phaseTable: (const idList<unsigned char,5> *)&v60,
              distanceTable: &v59);
      this->data = v41;
      v42 = v41 != nullptr;
      idStr::FreeData(this: &v64);
      idStr::FreeData(this: &v61);
      idStr::FreeData(this: &v62);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59);
      idList<idThread *,58>::Clear(this: &v60);
      idLexer::~idLexer(this: &v63);
      return v42;
    }
    idLib::Warning(fmt: "Phase track species invalid skeleton '%s'", v61.data);
    idStr::FreeData(this: &v64);
    idStr::FreeData(this: &v61);
    idStr::FreeData(this: &v62);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59);
    idList<idThread *,58>::Clear(this: &v60);
  }
  else
  {
    idLib::Warning(fmt: "Failed to open file '%s' for reading", fileName);
  }
  idLexer::~idLexer(this: &v63);
  return false;
}


// ========================================================================
// $M222675_0
// EA  : 0x82851D90
// RVA : 0x00851D90
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void *_M222675_0()
{
  int v0; // r12

  idLib::Warning(fmt: "Phase track file '%s': %s", *(const char **)(v0 - 5264 + 5292), idException::error);
  return &_LN49_3;
}


// ========================================================================
// $LN311
// EA  : 0x82851DD0
// RVA : 0x00851DD0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _LN311()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 5264 + 192));
}


// ========================================================================
// __unwind$221939
// EA  : 0x82851DF8
// RVA : 0x00851DF8
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221939()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5264 + 112));
}


// ========================================================================
// __unwind$221940
// EA  : 0x82851E20
// RVA : 0x00851E20
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221940()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5264 + 96));
}


// ========================================================================
// __unwind$221941
// EA  : 0x82851E48
// RVA : 0x00851E48
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 160));
}


// ========================================================================
// __unwind$221942
// EA  : 0x82851E70
// RVA : 0x00851E70
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221942()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 128));
}


// ========================================================================
// __unwind$221943_0
// EA  : 0x82851E98
// RVA : 0x00851E98
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221943_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 336));
}


// ========================================================================
// __unwind$221944
// EA  : 0x82851EC0
// RVA : 0x00851EC0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_221944()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5264 + 672));
}


// ========================================================================
// ?CreateForAnim@idMD6PhaseTrack@@AAA_NPBVidMD6Skel@@PBVidMD6Anim@@PBD22_N@Z
// EA  : 0x82851F60
// RVA : 0x00851F60
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

BOOL __fastcall idMD6PhaseTrack::CreateForAnim(
        idMD6PhaseTrack *this,
        idIndex<short,enum invalidJointIndex_t> *skel,
        const idMD6Anim *anim,
        const char *leftAnkleJointName,
        const char *rightAnkleJointName,
        const char *originJointName,
        bool createDistanceTable)
{
  phaseTrackData_t *data; // r4
  bool v15; // cr58
  idMD6AnimData *animData; // r11
  int numFrames; // r22
  int v18; // r5
  idJointMat *v19; // r30
  const idDeclVehicleUpgrade **list; // r14
  int v21; // r28
  const idDeclVehicleUpgrade **v22; // r15
  const idDeclVehicleUpgrade **v23; // r27
  const idDeclVehicleUpgrade **v24; // r29
  BOOL v25; // r23
  idVehicleState **v26; // r17
  float *v27; // r16
  double v28; // fp28
  double v29; // fp29
  double v30; // fp30
  int v31; // r25
  float *v32; // r24
  float *v33; // r28
  float *v34; // r30
  float *v35; // r29
  int v36; // r26
  int v37; // r11
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  const idDeclVehicleUpgrade **v41; // r11
  double v42; // fp9
  double v43; // fp7
  double v44; // fp3
  double v45; // fp2
  double v46; // fp11
  double v47; // fp13
  double v48; // fp0
  double v49; // fp12
  double v50; // fp9
  double v51; // fp8
  double v52; // fp7
  double v55; // fp12
  double v56; // fp13
  double v57; // fp10
  double v58; // fp13
  double v59; // fp12
  double v60; // fp11
  float *v61; // r11
  float *v62; // r8
  float *v63; // r9
  int v64; // r7
  double v65; // fp10
  float v66; // r4
  float v67; // r3
  double v70; // fp2
  double v71; // fp2
  double v72; // fp9
  double v73; // fp8
  BOOL v74; // r10
  float v75; // r3
  float v76; // r30
  float v77; // r4
  double v80; // fp4
  double v81; // fp4
  double v82; // fp1
  double v83; // fp10
  int v84; // r25
  int v85; // r24
  int v86; // r27
  int v87; // r28
  int v88; // r29
  int *v89; // r30
  int v90; // r11
  int v91; // r10
  idVehicleState **v92; // r11
  idMem *str; // r30
  __int64 v94; // r5
  int v95; // r7
  idVehicleState **v96; // r29
  int v97; // ctr
  __int64 v98; // r11
  int v99; // r8
  int v100; // r9
  phaseTrackData_t *v101; // r3
  BOOL v102; // r30
  idMem *v103; // r28
  idMD6Skel v105; // [sp+50h] [-160h] BYREF
  __int64 v106; // [sp+88h] [-128h]
  float v107; // [sp+90h] [-120h]
  idList<float,5> v108; // [sp+A0h] [-110h] BYREF
  idList<idVehicleState *,5> v109; // [sp+B0h] [-100h] BYREF
  idList<idVehicleState *,5> v110; // [sp+C0h] [-F0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v111; // [sp+D0h] [-E0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v112[3]; // [sp+E0h] [-D0h] BYREF

  if ( anim == nullptr )
    return false;
  data = this->data;
  v15 = this->data == nullptr;
  v105.name.str = (const char *)&mem;
  if ( !v15 )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->data = nullptr;
  }
  animData = anim->animData;
  numFrames = 0;
  if ( animData != nullptr )
    numFrames = animData->numFrames;
  idMD6Skel::GetJointIndex(this: &v105, result: skel, name: leftAnkleJointName);
  if ( SHIWORD(v105.__vftable) < 0 )
    idLib::Error(fmt: "Invalid left ankle joint name '%s'", leftAnkleJointName);
  idMD6Skel::GetJointIndex(this: (idMD6Skel *)((char *)&v105.__vftable + 2), result: skel, name: rightAnkleJointName);
  if ( SLOWORD(v105.__vftable) < 0 )
    idLib::Error(fmt: "Invalid right ankle joint name '%s'", rightAnkleJointName);
  idMD6Skel::GetJointIndex(this: (idMD6Skel *)&v105.trackedMemory, result: skel, name: originJointName);
  if ( v105.trackedMemory < 0 )
    idLib::Error(fmt: "Invalid origin joint name '%s'", originJointName);
  v18 = *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 2);
  v19 = (idJointMat *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6PhaseTrack.cpp(489) : TAG_TEMP",
                        size: 16 * (v18 + __ROL4__(v18, 1)),
                        tag: TAG_TEMP,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v112);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v111);
  idList<jointTransforms_t,5>::SetNum(this: (idList<jointTransforms_t,5> *)v112, newNum: numFrames);
  idList<jointTransforms_t,5>::SetNum(this: (idList<jointTransforms_t,5> *)&v111, newNum: numFrames);
  list = v112[0].list;
  v21 = 0;
  v22 = v111.list;
  if ( numFrames > 0 )
  {
    v23 = v112[0].list;
    v24 = v111.list + 24;
    do
    {
      idMD6Skel::GetJointsForAnimFrame(
        this: (idMD6Skel *)skel,
        joints: v19,
        anim,
        frame: v21,
        offset: &vec3_origin,
        removeOriginOffset: false);
      memcpy(Dst: v24 - 24, Src: &v19[SHIWORD(v105.__vftable)], Size: 0x30u);
      memcpy(Dst: v24 - 12, Src: &v19[SLOWORD(v105.__vftable)], Size: 0x30u);
      memcpy(Dst: v24, Src: &v19[SHIWORD(v105.trackedMemory)], Size: 0x30u);
      idMD6Skel::GetJointsForAnimFrame(
        this: (idMD6Skel *)skel,
        joints: v19,
        anim,
        frame: v21,
        offset: &vec3_origin,
        removeOriginOffset: true);
      memcpy(Dst: v23, Src: &v19[SHIWORD(v105.__vftable)], Size: 0x30u);
      memcpy(Dst: v23 + 12, Src: &v19[SLOWORD(v105.__vftable)], Size: 0x30u);
      memcpy(Dst: (char *)v24 + (char *)list - (char *)v22, Src: &v19[SHIWORD(v105.trackedMemory)], Size: 0x30u);
      ++v21;
      v24 += 36;
      v23 += 36;
    }
    while ( v21 < numFrames );
  }
  idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
  memset(&v109, 0, 14);
  *(_WORD *)&v109.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v109);
  idList<footInfo_t,5>::SetNum(this: (idList<footInfo_t,5> *)&v109, newNum: numFrames);
  memset(&v108, 0, 14);
  *(_WORD *)&v108.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v108);
  v25 = createDistanceTable;
  if ( createDistanceTable )
    idList<float,5>::SetNum(this: &v108, newNum: numFrames);
  v26 = v109.list;
  v27 = v108.list;
  v28 = 0.0;
  v29 = 0.0;
  v30 = 0.0;
  if ( numFrames > 0 )
  {
    v31 = -1;
    v32 = v108.list;
    v33 = (float *)(v22 + 31);
    v34 = (float *)(v109.list + 5);
    v35 = (float *)(list + 19);
    v36 = numFrames;
    do
    {
      v37 = v31;
      if ( v31 < 0 )
        v37 = idMD6Anim::NumFrames(this: anim) - 2;
      v38 = *(v35 - 16);
      v39 = *(v35 - 8);
      v40 = *(v35 - 12);
      v41 = &list[36 * v37];
      v105.resourceListPtr = (idResourceList *)(v41 + 12);
      v42 = (float)((float)v38 - *((float *)v41 + 3));
      v43 = (float)((float)v39 - *((float *)v41 + 11));
      *(v34 - 4) = (float)v40 - *((float *)v41 + 7);
      *(v34 - 3) = v43;
      *(v34 - 5) = v42;
      v44 = *((float *)v41 + 15);
      v45 = *(v35 - 4);
      v46 = (float)(*v35 - *((float *)v41 + 19));
      *v34 = v35[4] - *((float *)v41 + 23);
      *(v34 - 2) = (float)v45 - (float)v44;
      *(v34 - 1) = v46;
      v29 = (float)((float)v29 + (float)(*(float *)&v22[36 * numFrames - 5] - *v33));
      v30 = (float)((float)v30 + (float)(*(float *)&v22[36 * numFrames - 1] - v33[4]));
      v28 = (float)((float)(*(float *)&v22[36 * numFrames - 9] - *(v33 - 4)) + (float)v28);
      if ( v25 )
      {
        v47 = (float)(*(float *)&v22[36 * numFrames - 5] - *v33);
        v49 = (float)(*(float *)&v22[36 * numFrames - 9] - *(v33 - 4));
        v48 = (float)(*(float *)&v22[36 * numFrames - 1] - v33[4]);
        *v32 = __fsqrts((float)((float)((float)v48 * (float)v48)
                              + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47))));
      }
      --v36;
      ++v31;
      v34 += 11;
      v35 += 36;
      v33 += 36;
      ++v32;
    }
    while ( v36 != 0 );
  }
  *(_QWORD *)&v105.resourceListPtr = __PAIR64__(0x82000000, numFrames);
  v50 = (float)((float)v29 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numFrames)));
  v51 = (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, numFrames)) * (float)v28);
  v52 = (float)((float)v30 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numFrames)));
  _FP2 = (float)((float)((float)((float)v52 * (float)v52)
                       + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v55 = __frsqrte(_FP13);
  v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                      * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                              * (float)0.5))
                                                                              * (float)v55)
                                                                      - (float)1.5)
                                                      * (float)v55)
                                              * (float)((float)((float)((float)v52 * (float)v52)
                                                              + (float)((float)((float)v51 * (float)v51)
                                                                      + (float)((float)v50 * (float)v50)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                              * (float)((float)((float)((float)v52 * (float)v52)
                                                                                              + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                      * (float)0.5))
                                                                      * (float)v55)
                                                              - (float)1.5)
                                              * (float)v55))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v55
                                                      * (float)((float)((float)((float)v52 * (float)v52)
                                                                      + (float)((float)((float)v51 * (float)v51)
                                                                              + (float)((float)v50 * (float)v50)))
                                                              * (float)0.5))
                                              * (float)v55)
                                      - (float)1.5)
                      * (float)v55));
  v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55)
                                                                                      * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55))
                                              * (float)((float)((float)((float)v52 * (float)v52)
                                                              + (float)((float)((float)v51 * (float)v51)
                                                                      + (float)((float)v50 * (float)v50)))
                                                      * (float)0.5))
                                      * (float)v56)
                              - (float)1.5)
              * (float)v56);
  v58 = (float)((float)v51
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)((float)((float)v52 * (float)v52)
                                                                      + (float)((float)((float)v51 * (float)v51)
                                                                              + (float)((float)v50 * (float)v50)))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56));
  v59 = (float)((float)((float)v29 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numFrames))) * (float)v57);
  v60 = (float)((float)((float)v30 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numFrames))) * (float)v57);
  if ( numFrames > 0 )
  {
    v61 = (float *)(v26 + 6);
    v62 = (float *)(list + 19);
    v63 = (float *)(v22 + 31);
    v64 = numFrames;
    do
    {
      v65 = (float)((float)((float)(*(v62 - 4) * (float)v58)
                          + (float)((float)((float)v59 * *v62) + (float)((float)v60 * v62[4])))
                  - (float)((float)(*(v63 - 4) * (float)v58)
                          + (float)((float)((float)v59 * *v63) + (float)((float)v60 * v63[4]))));
      *(_DWORD *)v61 = v65 > 0.0 || v65 >= -0.0;
      v66 = *(v61 - 5);
      v67 = *(v61 - 4);
      *(float *)&v106 = *(v61 - 6);
      *((float *)&v106 + 1) = v66;
      v107 = v67;
      _FP1 = (float)((float)((float)(v66 * v66)
                           + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f3, f1, f2, f10 }
      v70 = __frsqrte(_FP3);
      v71 = (float)((float)-(float)((float)((float)((float)v70
                                                  * (float)((float)((float)(v66 * v66)
                                                                  + (float)((float)(*(float *)&v106 * *(float *)&v106)
                                                                          + (float)(v107 * v107)))
                                                          * (float)0.5))
                                          * (float)v70)
                                  - (float)1.5)
                  * (float)v70);
      v72 = (float)(v107
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71
                                                                                                  * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107))) * (float)0.5))
                                                                                          * (float)v71)
                                                                                  - (float)1.5)
                                                                  * (float)v71)
                                                          * (float)((float)((float)(v66 * v66)
                                                                          + (float)((float)(*(float *)&v106
                                                                                          * *(float *)&v106)
                                                                                  + (float)(v107 * v107)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v71
                                                                                          * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v71)
                                                                          - (float)1.5)
                                                          * (float)v71))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v71
                                                                  * (float)((float)((float)(v66 * v66)
                                                                                  + (float)((float)(*(float *)&v106
                                                                                                  * *(float *)&v106)
                                                                                          + (float)(v107 * v107)))
                                                                          * (float)0.5))
                                                          * (float)v71)
                                                  - (float)1.5)
                                  * (float)v71)));
      v73 = (float)(*(float *)&v106
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71
                                                                                                  * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107))) * (float)0.5))
                                                                                          * (float)v71)
                                                                                  - (float)1.5)
                                                                  * (float)v71)
                                                          * (float)((float)((float)(v66 * v66)
                                                                          + (float)((float)(*(float *)&v106
                                                                                          * *(float *)&v106)
                                                                                  + (float)(v107 * v107)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v71
                                                                                          * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v71)
                                                                          - (float)1.5)
                                                          * (float)v71))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v71
                                                                  * (float)((float)((float)(v66 * v66)
                                                                                  + (float)((float)(*(float *)&v106
                                                                                                  * *(float *)&v106)
                                                                                          + (float)(v107 * v107)))
                                                                          * (float)0.5))
                                                          * (float)v71)
                                                  - (float)1.5)
                                  * (float)v71)));
      v74 = (float)((float)((float)(v66
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107))) * (float)0.5)) * (float)v71)
                                                                                                  - (float)1.5)
                                                                                  * (float)v71)
                                                                          * (float)((float)((float)(v66 * v66)
                                                                                          + (float)((float)(*(float *)&v106 * *(float *)&v106)
                                                                                                  + (float)(v107 * v107)))
                                                                                  * (float)0.5))
                                                                  * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)(v66 * v66) + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107))) * (float)0.5))
                                                                                                  * (float)v71)
                                                                                          - (float)1.5)
                                                                          * (float)v71))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v71
                                                                                  * (float)((float)((float)(v66 * v66)
                                                                                                  + (float)((float)(*(float *)&v106 * *(float *)&v106) + (float)(v107 * v107)))
                                                                                          * (float)0.5))
                                                                          * (float)v71)
                                                                  - (float)1.5)
                                                  * (float)v71)))
                          * (float)v59)
                  + (float)((float)((float)v73 * (float)v58) + (float)((float)v72 * (float)v60))) <= 0.0;
      v75 = *(v61 - 3);
      v76 = *(v61 - 1);
      v77 = *(v61 - 2);
      *((_DWORD *)v61 + 1) = v74;
      *(float *)&v105.data = v75;
      *(float *)&v105.jointConversion.value = v76;
      *(float *)&v105.timestamp = v77;
      _FP2 = (float)((float)((float)(*(float *)&v105.timestamp * *(float *)&v105.timestamp)
                           + (float)((float)(v75 * v75) + (float)(v76 * v76)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f10, f2, f3, f10 }
      v80 = __frsqrte(_FP10);
      v81 = (float)((float)-(float)((float)((float)((float)v80
                                                  * (float)((float)((float)(*(float *)&v105.timestamp
                                                                          * *(float *)&v105.timestamp)
                                                                  + (float)((float)(v75 * v75) + (float)(v76 * v76)))
                                                          * (float)0.5))
                                          * (float)v80)
                                  - (float)1.5)
                  * (float)v80);
      v83 = (float)(v75
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v81
                                                                                                  * (float)((float)((float)(*(float *)&v105.timestamp * *(float *)&v105.timestamp) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5))
                                                                                          * (float)v81)
                                                                                  - (float)1.5)
                                                                  * (float)v81)
                                                          * (float)((float)((float)(*(float *)&v105.timestamp
                                                                                  * *(float *)&v105.timestamp)
                                                                          + (float)((float)(v75 * v75)
                                                                                  + (float)(v76 * v76)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v81
                                                                                          * (float)((float)((float)(*(float *)&v105.timestamp * *(float *)&v105.timestamp) + (float)((float)(v75 * v75) + (float)(v76 * v76)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v81)
                                                                          - (float)1.5)
                                                          * (float)v81))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v81
                                                                  * (float)((float)((float)(*(float *)&v105.timestamp
                                                                                          * *(float *)&v105.timestamp)
                                                                                  + (float)((float)(v75 * v75)
                                                                                          + (float)(v76 * v76)))
                                                                          * (float)0.5))
                                                          * (float)v81)
                                                  - (float)1.5)
                                  * (float)v81)));
      v82 = (float)(v76
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v81
                                                                                                  * (float)((float)((float)(*(float *)&v105.timestamp * *(float *)&v105.timestamp) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5))
                                                                                          * (float)v81)
                                                                                  - (float)1.5)
                                                                  * (float)v81)
                                                          * (float)((float)((float)(*(float *)&v105.timestamp
                                                                                  * *(float *)&v105.timestamp)
                                                                          + (float)((float)(v75 * v75)
                                                                                  + (float)(v76 * v76)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v81
                                                                                          * (float)((float)((float)(*(float *)&v105.timestamp * *(float *)&v105.timestamp) + (float)((float)(v75 * v75) + (float)(v76 * v76)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v81)
                                                                          - (float)1.5)
                                                          * (float)v81))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v81
                                                                  * (float)((float)((float)(*(float *)&v105.timestamp
                                                                                          * *(float *)&v105.timestamp)
                                                                                  + (float)((float)(v75 * v75)
                                                                                          + (float)(v76 * v76)))
                                                                          * (float)0.5))
                                                          * (float)v81)
                                                  - (float)1.5)
                                  * (float)v81)));
      *((_DWORD *)v61 + 2) = (float)((float)((float)(v77
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v81 * (float)((float)((float)(v77 * v77) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5)) * (float)v81) - (float)1.5) * (float)v81)
                                                                                           * (float)((float)((float)(v77 * v77) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v81 * (float)((float)((float)(v77 * v77) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5)) * (float)v81) - (float)1.5)
                                                                                           * (float)v81))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v81 * (float)((float)((float)(v77 * v77) + (float)((float)(v75 * v75) + (float)(v76 * v76))) * (float)0.5))
                                                                                           * (float)v81)
                                                                                   - (float)1.5)
                                                                   * (float)v81)))
                                           * (float)v59)
                                   + (float)((float)((float)v83 * (float)v58) + (float)((float)v82 * (float)v60))) <= 0.0;
      --v64;
      v61 += 11;
      v63 += 36;
      v62 += 36;
    }
    while ( v64 != 0 );
  }
  v84 = -1;
  v85 = -1;
  v86 = 0;
  v87 = 0;
  v88 = 0;
  if ( numFrames > 0 )
  {
    v89 = (int *)(v26 + 6);
    do
    {
      v90 = v88 - 1;
      if ( v88 - 1 < 0 )
        v90 = idMD6Anim::NumFrames(this: anim) - 2;
      v91 = *v89;
      v92 = &v26[11 * v90];
      if ( *v89 == 1 && v89[2] == 1 && v92[8] == nullptr )
      {
        ++v86;
        v89[4] = 0;
        if ( v84 < 0 )
          v84 = v88;
      }
      if ( v91 == 0 && v89[1] == 1 && v92[7] == nullptr )
      {
        ++v87;
        v89[3] = 128;
        if ( v85 < 0 )
          v85 = v88;
      }
      ++v88;
      v89 += 11;
    }
    while ( v88 < numFrames );
    if ( v87 > 1 || v86 > 1 )
    {
      idLib::Warning(fmt: "Multiple cycles detected in anim '%s'", anim->name.str);
      if ( (v108.listStatic == 0 || v108.listStatic == 2) && v27 != nullptr )
      {
        str = (idMem *)v105.name.str;
        idMem::Free(this: (idMem *)v105.name.str, ptr: v27, align: ALIGN_16);
      }
      else
      {
        str = (idMem *)v105.name.str;
      }
      if ( (v109.listStatic == 0 || v109.listStatic == 2) && v26 != nullptr )
        idMem::Free(this: str, ptr: v26, align: ALIGN_16);
      if ( (v111.listStatic == 0 || v111.listStatic == 2) && v22 != nullptr )
        idMem::Free(this: str, ptr: v22, align: ALIGN_16);
      goto LABEL_145;
    }
    if ( v87 != 0 )
    {
      if ( v86 == 0 )
      {
        idLib::Warning(fmt: "No cycle detected on right foot in anim '%s'", anim->name.str);
        if ( (v108.listStatic == 0 || v108.listStatic == 2) && v27 != nullptr )
        {
          str = (idMem *)v105.name.str;
          idMem::Free(this: (idMem *)v105.name.str, ptr: v27, align: ALIGN_16);
        }
        else
        {
          str = (idMem *)v105.name.str;
        }
        if ( (v109.listStatic == 0 || v109.listStatic == 2) && v26 != nullptr )
          idMem::Free(this: str, ptr: v26, align: ALIGN_16);
        if ( (v111.listStatic == 0 || v111.listStatic == 2) && v22 != nullptr )
          idMem::Free(this: str, ptr: v22, align: ALIGN_16);
        goto LABEL_145;
      }
      if ( v87 != v86 )
      {
        idLib::Warning(fmt: "Multiple cycles detected on a single foot in anim '%s'", anim->name.str);
        if ( (v108.listStatic == 0 || v108.listStatic == 2) && v27 != nullptr )
        {
          str = (idMem *)v105.name.str;
          idMem::Free(this: (idMem *)v105.name.str, ptr: v27, align: ALIGN_16);
        }
        else
        {
          str = (idMem *)v105.name.str;
        }
        if ( (v109.listStatic == 0 || v109.listStatic == 2) && v26 != nullptr )
          idMem::Free(this: str, ptr: v26, align: ALIGN_16);
        if ( (v111.listStatic == 0 || v111.listStatic == 2) && v22 != nullptr )
          idMem::Free(this: str, ptr: v22, align: ALIGN_16);
        goto LABEL_145;
      }
      if ( v84 < 0 )
      {
        idLib::Warning(fmt: "No start of phase could be found in anim '%s'", anim->name.str);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v108);
        idList<idThread *,58>::Clear(this: &v109);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v111);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v112);
        return false;
      }
      if ( v85 < 0 )
      {
        idLib::Warning(fmt: "No start of midpoint of phase could be found in anim '%s'", anim->name.str);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v108);
        idList<idThread *,58>::Clear(this: &v109);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v111);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v112);
        return false;
      }
      memset(&v110, 0, 14);
      *(_WORD *)&v110.memTag = 1280;
      idList<idThread *,58>::Clear(this: &v110);
      idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v110, newNum: numFrames);
      v95 = v85 - v84;
      if ( v85 - v84 < 0 )
        v95 += numFrames;
      v96 = v110.list;
      v97 = numFrames;
      HIDWORD(v98) = 0;
      v99 = -v95;
      do
      {
        v100 = HIDWORD(v98) + v84;
        if ( HIDWORD(v98) + v84 >= numFrames )
          v100 = v84 - numFrames + HIDWORD(v98);
        if ( SHIDWORD(v98) > v95 )
        {
          LODWORD(v98) = v99;
          LODWORD(v94) = v85;
          *(_QWORD *)&v105.data = v98;
          v106 = v94;
          v105.defaultAnim = (const idMD6Anim *)(int)(float)((float)((float)((float)v98 * (float)127.0) / (float)v94)
                                                           + (float)128.0);
          LODWORD(v98) = v105.defaultAnim;
          if ( (int)v105.defaultAnim < 0 )
          {
            LOBYTE(v98) = 0;
            goto LABEL_109;
          }
        }
        else
        {
          LODWORD(v94) = v95;
          LODWORD(v98) = HIDWORD(v98);
          *(_QWORD *)&v105.resourceListPtr = v94;
          *(_QWORD *)&v105.networkID = v98;
          v105.defaultAnim = (const idMD6Anim *)(int)(float)((float)((float)v98 * (float)128.0) / (float)v94);
          LODWORD(v98) = v105.defaultAnim;
          if ( (int)v105.defaultAnim < 0 )
          {
            LOBYTE(v98) = 0;
            goto LABEL_109;
          }
        }
        if ( (int)v98 > 255 )
          LOBYTE(v98) = -1;
LABEL_109:
        ++HIDWORD(v98);
        *((_BYTE *)v96 + v100) = v98;
        ++v99;
        --v97;
      }
      while ( v97 != 0 );
      v101 = idMD6PhaseTrack::CreatePhaseTrackData(
               this,
               (const idMD6Skel *)skel,
               anim,
               phaseTable: (const idList<unsigned char,5> *)&v110,
               distanceTable: &v108);
      this->data = v101;
      v102 = v101 != nullptr;
      if ( (v110.listStatic == 0 || v110.listStatic == 2) && v96 != nullptr )
      {
        v103 = (idMem *)v105.name.str;
        idMem::Free(this: (idMem *)v105.name.str, ptr: v96, align: ALIGN_16);
      }
      else
      {
        v103 = (idMem *)v105.name.str;
      }
      if ( (v108.listStatic == 0 || v108.listStatic == 2) && v27 != nullptr )
        idMem::Free(this: v103, ptr: v27, align: ALIGN_16);
      if ( (v109.listStatic == 0 || v109.listStatic == 2) && v26 != nullptr )
        idMem::Free(this: v103, ptr: v26, align: ALIGN_16);
      if ( (v111.listStatic == 0 || v111.listStatic == 2) && v22 != nullptr )
        idMem::Free(this: v103, ptr: v22, align: ALIGN_16);
      if ( (v112[0].listStatic == 0 || v112[0].listStatic == 2) && list != nullptr )
        idMem::Free(this: v103, ptr: list, align: ALIGN_16);
      return v102;
    }
  }
  idLib::Warning(fmt: "No cycle detected on left foot in anim '%s'", anim->name.str);
  if ( (v108.listStatic == 0 || v108.listStatic == 2) && v27 != nullptr )
  {
    str = (idMem *)v105.name.str;
    idMem::Free(this: (idMem *)v105.name.str, ptr: v27, align: ALIGN_16);
  }
  else
  {
    str = (idMem *)v105.name.str;
  }
  if ( (v109.listStatic == 0 || v109.listStatic == 2) && v26 != nullptr )
    idMem::Free(this: str, ptr: v26, align: ALIGN_16);
  if ( (v111.listStatic == 0 || v111.listStatic == 2) && v22 != nullptr )
    idMem::Free(this: str, ptr: v22, align: ALIGN_16);
LABEL_145:
  if ( (v112[0].listStatic == 0 || v112[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: str, ptr: list, align: ALIGN_16);
  return false;
}


// ========================================================================
// $LN597
// EA  : 0x82852CCC
// RVA : 0x00852CCC
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _LN597()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$222758
// EA  : 0x82852CF4
// RVA : 0x00852CF4
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_222758()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 208));
}


// ========================================================================
// __unwind$222759
// EA  : 0x82852D1C
// RVA : 0x00852D1C
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_222759()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$222760
// EA  : 0x82852D44
// RVA : 0x00852D44
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_222760()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$222761
// EA  : 0x82852D6C
// RVA : 0x00852D6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_222761()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 192));
}


// ========================================================================
// ?GeneratePhaseTrack@idMD6PhaseTrack@@SA_NPBVidMD6Skel@@PBVidMD6Anim@@PBD22_N@Z
// EA  : 0x82852DA0
// RVA : 0x00852DA0
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

int __fastcall idMD6PhaseTrack::GeneratePhaseTrack(
        idIndex<short,enum invalidJointIndex_t> *skel,
        const idMD6Anim *anim,
        const char *leftAnkleJointName,
        const char *rightAnkleJointName,
        const char *originJointName,
        bool generateDistanceTable)
{
  idMD6PhaseTrack v13[4]; // [sp+50h] [-70h] BYREF
  idStr v14[3]; // [sp+60h] [-60h] BYREF

  if ( skel == nullptr || anim == nullptr )
    return 0;
  idStr::idStr(this: v14, text: anim->name.str);
  idStr::SetFileExtension(this: v14, extension: "ptrack");
  v13[0].data = nullptr;
  if ( !idMD6PhaseTrack::CreateForAnim(
          this: v13,
          skel,
          anim,
          leftAnkleJointName,
          rightAnkleJointName,
          originJointName,
          createDistanceTable: generateDistanceTable) )
  {
    idMD6PhaseTrack::~idMD6PhaseTrack(this: v13);
    idStr::FreeData(this: v14);
    return 0;
  }
  idMD6PhaseTrack::WriteText(
    this: v13,
    fileName: v14[0].data,
    (const idMD6Skel *)skel,
    anim,
    leftAnkleJointName,
    rightAnkleJointName,
    originJointName);
  idMD6PhaseTrack::~idMD6PhaseTrack(this: v13);
  idStr::FreeData(this: v14);
  return 1;
}


// ========================================================================
// __unwind$224132
// EA  : 0x82852E7C
// RVA : 0x00852E7C
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$224133
// EA  : 0x82852EA4
// RVA : 0x00852EA4
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224133()
{
  int v0; // r12

  idMD6PhaseTrack::~idMD6PhaseTrack(this: (idMD6PhaseTrack *)(v0 - 192 + 80));
}


// ========================================================================
// ?genPhaseTrack_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82852ED8
// RVA : 0x00852ED8
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void __fastcall genPhaseTrack_f(const idCmdArgs *args)
{
  bool v2; // r19
  int v3; // r21
  int v4; // r20
  int argc; // r11
  int v6; // r30
  int v7; // r27
  const char **v8; // r29
  char *v9; // r28
  char *v10; // r10
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  char *v15; // r27
  const char *v16; // r4
  const idMD6Anim *v17; // r30
  idResource *v18; // r3
  idStr v19; // [sp+60h] [-F0h] BYREF
  idStr v20; // [sp+80h] [-D0h] BYREF
  idStr v21; // [sp+A0h] [-B0h] BYREF
  idStr v22[4]; // [sp+C0h] [-90h] BYREF

  if ( args->argc == 1 )
  {
    idLib::Printf(fmt: "USAGE: genPhaseTrack [-d] [-r name] [-l name] [-o name] <animName> <skelName>\n");
    idLib::Printf(fmt: "  -d = generate remaining distance table for the phase track.\n");
    idLib::Printf(fmt: "  -r = specify right ankle joint name.\n");
    idLib::Printf(fmt: "  -l = specify left ankle joint name.\n");
    idLib::Printf(fmt: "  -o = specify origin joint name.\n");
  }
  else
  {
    v2 = false;
    v3 = -1;
    v4 = -1;
    idStr::idStr(this: &v20, text: "rightfoot");
    idStr::idStr(this: &v19, text: "leftfoot");
    idStr::idStr(this: &v21, text: "origin");
    argc = args->argc;
    v6 = 1;
    if ( args->argc <= 1 )
    {
_M224458_1:
      idLib::Printf(fmt: "USAGE: genPhaseTrack [-d] [-r name] [-l name] [-o name] <animName> <skelName>\n");
      idLib::Printf(fmt: "  -d = generate remaining distance table for the phase track.\n");
      idLib::Printf(fmt: "  -r = specify right ankle joint name.\n");
      idLib::Printf(fmt: "  -l = specify left ankle joint name.\n");
      idLib::Printf(fmt: "  -o = specify origin joint name.\n");
      idStr::FreeData(this: &v21);
      idStr::FreeData(this: &v19);
    }
    else
    {
      v7 = 2;
      v8 = (const char **)&args->argv[1];
      v9 = &byte_8200D768;
      do
      {
        if ( v6 < 0 || v6 >= argc )
          v10 = &byte_8200D768;
        else
          v10 = (char *)*v8;
        if ( *v10 == 45 )
        {
          if ( v6 < 0 || v6 >= argc )
            v11 = &byte_8200D768;
          else
            v11 = *v8;
          if ( idStr::Icmp(s1: v11, s2: "-d") != 0 )
          {
            if ( v6 < 0 || v6 >= args->argc )
              v12 = &byte_8200D768;
            else
              v12 = *v8;
            if ( idStr::Icmp(s1: v12, s2: "-r") != 0 )
            {
              if ( v6 < 0 || v6 >= args->argc )
                v13 = &byte_8200D768;
              else
                v13 = *v8;
              if ( idStr::Icmp(s1: v13, s2: "-l") != 0 )
              {
                if ( v6 < 0 || v6 >= args->argc )
                  v14 = &byte_8200D768;
                else
                  v14 = *v8;
                if ( idStr::Icmp(s1: v14, s2: "-o") != 0 )
                {
                  if ( v6 < 0 || v6 >= args->argc )
                    v16 = &byte_8200D768;
                  else
                    v16 = args->argv[v6];
                  idLib::Warning(fmt: "Unknown switch %s", v16);
                  idStr::FreeData(this: &v21);
                  idStr::FreeData(this: &v19);
                  goto LABEL_75;
                }
                if ( v7 >= args->argc )
                {
                  idLib::Warning(fmt: "Missing joint name after -o");
                  idStr::FreeData(this: &v21);
                  idStr::FreeData(this: &v19);
                  goto LABEL_75;
                }
                ++v6;
                ++v7;
                ++v8;
                if ( v6 < 0 || v6 >= args->argc )
                  idStr::operator=(this: &v21, text: &byte_8200D768);
                else
                  idStr::operator=(this: &v21, text: *v8);
              }
              else
              {
                if ( v7 >= args->argc )
                {
                  idLib::Warning(fmt: "Missing joint name after -l");
                  idStr::FreeData(this: &v21);
                  idStr::FreeData(this: &v19);
                  goto LABEL_75;
                }
                ++v6;
                ++v7;
                ++v8;
                if ( v6 < 0 || v6 >= args->argc )
                  idStr::operator=(this: &v19, text: &byte_8200D768);
                else
                  idStr::operator=(this: &v19, text: *v8);
              }
            }
            else
            {
              if ( v7 >= args->argc )
              {
                idLib::Warning(fmt: "Missing joint name after -r");
                idStr::FreeData(this: &v21);
                idStr::FreeData(this: &v19);
                goto LABEL_75;
              }
              ++v6;
              ++v7;
              ++v8;
              if ( v6 < 0 || v6 >= args->argc )
                idStr::operator=(this: &v20, text: &byte_8200D768);
              else
                idStr::operator=(this: &v20, text: *v8);
            }
          }
          else
          {
            v2 = true;
          }
        }
        else if ( v3 >= 0 )
        {
          if ( v4 < 0 )
            v4 = v6;
        }
        else
        {
          v3 = v6;
        }
        argc = args->argc;
        ++v6;
        ++v7;
        ++v8;
      }
      while ( v6 < args->argc );
      if ( v4 < 0 || v3 < 0 )
        goto _M224458_1;
      if ( v3 >= argc )
        v15 = &byte_8200D768;
      else
        v15 = args->argv[v3];
      if ( v4 < argc )
        v9 = args->argv[v4];
      v17 = (const idMD6Anim *)idResourceList::Load(
                                 this: &idMD6Anim::resourceList,
                                 name: v15,
                                 makeDefault: false,
                                 skipStaleCheck: false);
      if ( v17 != nullptr )
      {
        v18 = idResourceList::Load(this: &idMD6Skel::resourceList, name: v9, makeDefault: false, skipStaleCheck: false);
        if ( v18 != nullptr )
        {
          if ( (unsigned __int8)idMD6PhaseTrack::GeneratePhaseTrack(
                                  skel: (idIndex<short,enum invalidJointIndex_t> *)v18,
                                  anim: v17,
                                  leftAnkleJointName: v19.data,
                                  rightAnkleJointName: v20.data,
                                  originJointName: v21.data,
                                  generateDistanceTable: v2) != 0 )
          {
            idStr::idStr(this: v22, text: v17->name.str);
            idStr::SetFileExtension(this: v22, extension: "ptrack");
            idLib::Printf(fmt: "Phase track written to '%s'.\n", v22[0].data);
            idResourceList::ReloadStaleResources(this: &idMD6Anim::resourceList);
            idStr::FreeData(this: v22);
          }
          else
          {
            idLib::Warning(fmt: "Failed to create phase track for anim '%s'", v15);
          }
          idStr::FreeData(this: &v21);
          idStr::FreeData(this: &v19);
        }
        else
        {
          idLib::Warning(fmt: "Skeleton '%s' failed to load", v9);
          idStr::FreeData(this: &v21);
          idStr::FreeData(this: &v19);
        }
      }
      else
      {
        idLib::Warning(fmt: "Animation '%s' failed to load", v15);
        idStr::FreeData(this: &v21);
        idStr::FreeData(this: &v19);
      }
    }
LABEL_75:
    idStr::FreeData(this: &v20);
  }
}


// ========================================================================
// __unwind$224190
// EA  : 0x82853410
// RVA : 0x00853410
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224190()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$224191_0
// EA  : 0x82853438
// RVA : 0x00853438
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224191_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$224192
// EA  : 0x82853460
// RVA : 0x00853460
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224192()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$224193
// EA  : 0x82853488
// RVA : 0x00853488
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

void _unwind_224193()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 192));
}


// ========================================================================
// `dynamic initializer for 'genPhaseTrack_v''
// EA  : 0x83344468
// RVA : 0x01344468
// PDB : w:\tech5\engine\models\skeletalanimation\md6phasetrack.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__genPhaseTrack_v__()
{
  return idCommandLink::idCommandLink(
           this: &genPhaseTrack_v,
           cmdName: "genPhaseTrack",
           function: genPhaseTrack_f,
           description: "generates a phase track for the specified skeleton and animation",
           argCompletion: idTestModel2::ArgCompletion_Anim);
}

