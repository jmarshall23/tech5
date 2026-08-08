
// ========================================================================
// GeneratePhonemsOutputFunction
// EA  : 0x826304F8
// RVA : 0x006304F8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall GeneratePhonemsOutputFunction(const char *text)
{
  if ( text != nullptr )
    idLib::Printf(fmt: text);
}


// ========================================================================
// ?Lipsync_GetDictFileName@@YAPBDPBD@Z
// EA  : 0x82630508
// RVA : 0x00630508
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

const char *__fastcall Lipsync_GetDictFileName(const char *language)
{
  int v2; // r31
  Lipsync_GetDictFileName::__l2::lipDict_t *v3; // r11
  int v4; // r29

  v2 = 0;
  if ( dicts[0].languageName == nullptr )
    return nullptr;
  v3 = dicts;
  v4 = 0;
  while ( idStr::Icmp(s1: v3->languageName, s2: language) != 0 )
  {
    v4 = ++v2;
    v3 = &dicts[v2];
    if ( v3->languageName == nullptr )
      return nullptr;
  }
  return dicts[v4].dictName;
}


// ========================================================================
// ?Lipsync_IntermediateFilePathFromSampleName@@YA_NPBDAAVidStr@@@Z
// EA  : 0x82630580
// RVA : 0x00630580
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

const char *__fastcall Lipsync_IntermediateFilePathFromSampleName(const char *sampleName, idStr *filePath)
{
  if ( sampleName != nullptr )
  {
    idStr::operator=(this: filePath, text: sampleName);
    idStr::BackSlashesToSlashes(this: filePath);
    idStr::Replace(this: filePath, old: "sound/vo/", nw: "intermediate/voicetrack/");
    return (const char *)1;
  }
  return sampleName;
}


// ========================================================================
// ??0idPhonemeEvent@idPhonemeTrack_Annosoft@@QAA@XZ
// EA  : 0x82630688
// RVA : 0x00630688
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

idPhonemeTrack_Annosoft::idPhonemeEvent *__fastcall idPhonemeTrack_Annosoft::idPhonemeEvent::idPhonemeEvent(
        idPhonemeTrack_Annosoft::idPhonemeEvent *this)
{
  this->startMS = 0;
  this->type = -1;
  this->exType = EXPHONEME_MAX;
  this->endMS = 0;
  this->numWeights = 0;
  this->weights = nullptr;
  this->text.allocedAndFlag = 20;
  this->text.data = this->text.baseBuffer;
  this->text.len = 0;
  this->text.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ??1idPhonemeEvent@idPhonemeTrack_Annosoft@@QAA@XZ
// EA  : 0x826306D0
// RVA : 0x006306D0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall idPhonemeTrack_Annosoft::idPhonemeEvent::~idPhonemeEvent(idPhonemeTrack_Annosoft::idPhonemeEvent *this)
{
  idPhonemeTrack_Annosoft::weight_t *weights; // r4

  weights = this->weights;
  if ( weights != nullptr )
  {
    idMem::Free(this: &mem, ptr: weights, align: ALIGN_16);
    this->weights = nullptr;
  }
  this->numWeights = 0;
  idStr::FreeData(this: &this->text);
}


// ========================================================================
// ?Load@idPhonemeTrack_Annosoft@@UAA_NPBVidDeclVisemeSet@@PBD@Z
// EA  : 0x82630738
// RVA : 0x00630738
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall idPhonemeTrack_Annosoft::Load(
        idPhonemeTrack_Annosoft *this,
        const idDeclVisemeSet *declVisemeSet,
        const char *fileName)
{
  signed int v6; // r29
  int v7; // r30
  unsigned __int8 *v9; // [sp+54h] [-9Ch] BYREF
  idLexerUTF8 v10; // [sp+60h] [-90h] BYREF

  v9 = nullptr;
  v6 = fileSystem->ReadFile(this: fileSystem, a2: fileName, a3: (void **)&v9, a4: nullptr);
  if ( v6 < 0 )
    return 0;
  idLexerUTF8::idLexerUTF8(this: &v10, flags_: 786432);
  idLexerUTF8::LoadMemory(this: &v10, ptr: v9, length: v6, name: fileName);
  v7 = ((int (__fastcall *)(idPhonemeTrack_Annosoft *, const idDeclVisemeSet *, idLexerUTF8 *))this->Load)(
         a1: this,
         a2: declVisemeSet,
         a3: &v10);
  fileSystem->FreeFile(this: fileSystem, a2: v9);
  idLexerUTF8::~idLexerUTF8(this: &v10);
  return v7;
}


// ========================================================================
// $M222964
// EA  : 0x82630828
// RVA : 0x00630828
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void *_M222964()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 240;
  idLib::Warning(fmt: idException::error);
  *(_BYTE *)(v1 + 80) = 0;
  return &_M222953_0;
}


// ========================================================================
// __unwind$222938
// EA  : 0x82630864
// RVA : 0x00630864
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_222938()
{
  int v0; // r12

  idLexerUTF8::~idLexerUTF8(this: (idLexerUTF8 *)(v0 - 240 + 96));
}


// ========================================================================
// ?GetNumFrames@idPhonemeTrack_Annosoft@@QBAHXZ
// EA  : 0x82630890
// RVA : 0x00630890
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall idPhonemeTrack_Annosoft::GetNumFrames(idPhonemeTrack_Annosoft *this)
{
  int endMS; // r9
  idPhonemeTrack_Annosoft::idPhonemeEvent *list; // r8
  int v3; // r10
  int num; // ctr

  endMS = 0;
  if ( this->phonemes.num > 0 )
  {
    list = this->phonemes.list;
    v3 = 0;
    num = this->phonemes.num;
    do
    {
      if ( list[v3].exType == EXPHONEME_PHONEME && endMS <= list[v3].endMS )
        endMS = list[v3].endMS;
      ++v3;
      --num;
    }
    while ( num != 0 );
  }
  return 30 * endMS / 1000;
}


// ========================================================================
// ?Copy@idPhonemeEvent@idPhonemeTrack_Annosoft@@QAAXABV12@@Z
// EA  : 0x82630B50
// RVA : 0x00630B50
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall idPhonemeTrack_Annosoft::idPhonemeEvent::Copy(
        idPhonemeTrack_Annosoft::idPhonemeEvent *this,
        const idPhonemeTrack_Annosoft::idPhonemeEvent *other)
{
  int len; // r29
  idPhonemeTrack_Annosoft::weight_t *weights; // r4
  unsigned int numWeights; // r11
  unsigned int v7; // r5
  idPhonemeTrack_Annosoft::weight_t *v8; // r3
  __int16 v9; // r9
  int v10; // r10
  int v11; // r11
  idPhonemeTrack_Annosoft::weight_t *v12; // r8
  idPhonemeTrack_Annosoft::weight_t *v13; // r7

  if ( other != this )
  {
    this->type = other->type;
    this->exType = other->exType;
    this->startMS = other->startMS;
    this->endMS = other->endMS;
    this->numWeights = other->numWeights;
    len = other->text.len;
    idStr::EnsureAlloced(this: &this->text, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->text.data, Src: other->text.data, Size: len);
    this->text.data[len] = 0;
    this->text.len = len;
    weights = this->weights;
    if ( weights != nullptr )
    {
      idMem::Free(this: &mem, ptr: weights, align: ALIGN_16);
      this->weights = nullptr;
    }
    numWeights = this->numWeights;
    if ( numWeights > 0x15555555 )
      v7 = -1;
    else
      v7 = 12 * numWeights;
    v8 = (idPhonemeTrack_Annosoft::weight_t *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                size: v7,
                                                tag: TAG_NEW,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
    v9 = this->numWeights;
    this->weights = v8;
    v10 = 0;
    if ( v9 > 0 )
    {
      v11 = 0;
      do
      {
        ++v10;
        v12 = &other->weights[v11];
        v13 = &this->weights[v11++];
        v13->startMS = v12->startMS;
        v13->endMS = v12->endMS;
        v13->weight = v12->weight;
      }
      while ( v10 < this->numWeights );
    }
  }
}


// ========================================================================
// ?Lipsync_ExecTool@@YA?AW4annosoftError_t@@PBD000AAVidStr@@1_N1@Z
// EA  : 0x826316D0
// RVA : 0x006316D0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall Lipsync_ExecTool(
        const char *languageName,
        const char *sampleName,
        const char *textFileName,
        const char *annoFilePath,
        idStr *outTextFilePath,
        idStr *outAnnoFilePath,
        const bool textless,
        idStr *errorMsg)
{
  const char *v16; // r3
  const char *v17; // r4
  const char *v19; // r4
  idStr *v20; // r3
  BOOL v21; // r9
  char *data; // r4
  BOOL v23; // r9
  char *v24; // r4
  char *DictFileName; // r4
  unsigned __int8 v26; // r11
  int v27; // r27
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  unsigned __int8 started; // r3
  __int64 v32; // r6
  va *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  va *v36; // r3
  va *v37; // r3
  va *v38; // r3
  int v39; // [sp+8h] [-4468h]
  int v40; // [sp+Ch] [-4464h]
  int v41; // [sp+10h] [-4460h]
  int v42; // [sp+14h] [-445Ch]
  int v43; // [sp+18h] [-4458h]
  int v44; // [sp+1Ch] [-4454h]
  unsigned int v45; // [sp+50h] [-4420h]
  idStr v46; // [sp+60h] [-4410h] BYREF
  idStr v47; // [sp+80h] [-43F0h] BYREF
  idStr v48; // [sp+A0h] [-43D0h] BYREF
  idStr v49; // [sp+C0h] [-43B0h] BYREF
  idStr v50; // [sp+E0h] [-4390h] BYREF
  char v51[256]; // [sp+100h] [-4370h] BYREF
  char v52[256]; // [sp+200h] [-4270h] BYREF
  char v53[256]; // [sp+300h] [-4170h] BYREF
  va v54; // [sp+400h] [-4070h] BYREF
  va v55; // [sp+1400h] [-3070h] BYREF
  va v56; // [sp+2400h] [-2070h] BYREF
  va v57; // [sp+3400h] [-1070h] BYREF

  v47.len = 0;
  v47.allocedAndFlag = 20;
  v47.data = v47.baseBuffer;
  v47.baseBuffer[0] = 0;
  if ( fileSystem->IsRelativePath(this: fileSystem, a2: vo_lipsyncToolPath.valueString.data) )
  {
    v16 = fileSystem->GetBasePathStr(this: fileSystem, a2: 0);
    idStr::operator=(this: &v47, text: v16);
    idStr::Append(this: &v47, text: "/arttools/bin/");
    idStr::Append(this: &v47, text: vo_lipsyncToolPath.valueString.data);
  }
  else
  {
    idStr::operator=(this: &v47, text: vo_lipsyncToolPath.valueString.data);
  }
  idStr::idStr(this: &v48, text: sampleName);
  idStr::BackSlashesToSlashes(this: &v48);
  idStr::SetFileExtension(this: &v48, extension: "wav");
  if ( textFileName != nullptr && *textFileName != 0 )
    v17 = textFileName;
  else
    v17 = &byte_8200D768;
  idStr::operator=(this: outTextFilePath, text: v17);
  if ( annoFilePath != nullptr )
  {
    v19 = annoFilePath;
    v20 = outAnnoFilePath;
  }
  else
  {
    if ( textFileName == nullptr || *textFileName == 0 )
    {
      idStr::FreeData(this: &v48);
      idStr::FreeData(this: &v47);
      return 5001;
    }
    v19 = textFileName;
    v20 = outAnnoFilePath;
  }
  idStr::operator=(this: v20, text: v19);
  idStr::SetFileExtension(this: outAnnoFilePath, extension: "anno");
  if ( fileSystem->FileExists(this: fileSystem, a2: outAnnoFilePath->data, a3: false) )
    fileSystem->RemoveFile(this: fileSystem, a2: outAnnoFilePath->data, a3: FSPATH_BASE);
  if ( fileSystem->IsRelativePath(this: fileSystem, a2: v48.data) )
    fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v48.data, a3: v51, a4: 256, a5: FSPATH_BASE);
  else
    idStr::Copynz(dest: v51, src: v48.data, destsize: 256);
  v21 = fileSystem->IsRelativePath(this: fileSystem, a2: outTextFilePath->data);
  data = outTextFilePath->data;
  if ( v21 )
    fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: data, a3: v53, a4: 256, a5: FSPATH_BASE);
  else
    idStr::Copynz(dest: v53, src: data, destsize: 256);
  v23 = fileSystem->IsRelativePath(this: fileSystem, a2: outAnnoFilePath->data);
  v24 = outAnnoFilePath->data;
  if ( v23 )
    fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v24, a3: v52, a4: 256, a5: FSPATH_BASE);
  else
    idStr::Copynz(dest: v52, src: v24, destsize: 256);
  idStr::idStr(this: &v49, text: &v47);
  idStr::StripFilename(this: &v49);
  idStr::AppendPath(this: &v49, text: "dicts/");
  DictFileName = (char *)Lipsync_GetDictFileName(language: languageName);
  if ( DictFileName != nullptr )
    idStr::Append(this: &v49, text: DictFileName);
  v46.allocedAndFlag = 20;
  v46.len = 0;
  v46.data = v46.baseBuffer;
  v46.baseBuffer[0] = 0;
  if ( textFileName == nullptr || (v26 = 1, *textFileName == 0) )
    v26 = 0;
  v27 = v26;
  if ( v26 == 0 || textless )
  {
    idStr::operator=(this: &v46, text: "-alex $dictfile -artic -env -rage -w $wavfile -out $outfile");
  }
  else
  {
    idStr::operator=(this: &v46, text: "-alex $dictfile -artic -env -rage -w $wavfile -t $txtfile -out $outfile");
    idStr::Replace(this: &v46, old: "$txtfile", nw: v53);
  }
  idStr::Replace(this: &v46, old: "$wavfile", nw: v51);
  idStr::Replace(this: &v46, old: "$outfile", nw: v52);
  idStr::Replace(this: &v46, old: "$dictfile", nw: v49.data);
  idStr::idStr(this: &v50, text: v51);
  idStr::StripFilename(this: &v50);
  started = idLobbyBackend360::StartArbitration(pexcept: (_exception *)v47.data);
  if ( v27 != 0 )
  {
    HIDWORD(v32) = v45;
    if ( v45 != 1002 )
      goto LABEL_40;
    if ( textless )
    {
LABEL_45:
      HIDWORD(v34) = fileSystem->FileExists(this: fileSystem, a2: outAnnoFilePath->data, a3: false);
      if ( HIDWORD(v34) != 0 )
      {
        HIDWORD(v35) = v46.data;
        v37 = va::va(
                this: &v55,
                fmt: "Phoneme generation failed. Exit code: %d. Command line: %s %s",
                a3: __SPAIR64__(v45, (unsigned int)v47.data),
                a4: v35,
                a5: v34,
                a6: v39,
                a7: v40,
                a8: v41,
                a9: v42,
                a10: v43,
                a11: v44);
        idStr::operator=(this: errorMsg, text: v37);
        idStr::FreeData(this: &v50);
        idStr::FreeData(this: &v46);
        idStr::FreeData(this: &v49);
        idStr::FreeData(this: &v48);
        idStr::FreeData(this: &v47);
        return 1002;
      }
      HIDWORD(v35) = v46.data;
      v36 = va::va(
              this: &v56,
              fmt: "Phoneme generation failed. No phoneme file was output. Exit code: %d. Command line: %s %s",
              a3: __SPAIR64__(v45, (unsigned int)v47.data),
              a4: v35,
              a5: (unsigned int)v34,
              a6: v39,
              a7: v40,
              a8: v41,
              a9: v42,
              a10: v43,
              a11: v44);
      idStr::operator=(this: errorMsg, text: v36);
      idStr::FreeData(this: &v50);
      idStr::FreeData(this: &v46);
      idStr::FreeData(this: &v49);
      idStr::FreeData(this: &v48);
      goto LABEL_57;
    }
    idLib::Printf(fmt: "Retrying without text...\n");
    idStr::operator=(this: &v46, text: "-alex $dictfile -artic -env -rage -w $wavfile -out $outfile");
    idStr::Replace(this: &v46, old: "$wavfile", nw: v51);
    idStr::Replace(this: &v46, old: "$outfile", nw: v52);
    idStr::Replace(this: &v46, old: "$dictfile", nw: v49.data);
    started = idLobbyBackend360::StartArbitration(pexcept: (_exception *)v47.data);
    HIDWORD(v28) = started;
    if ( started != 0 )
    {
      HIDWORD(v32) = v45;
LABEL_41:
      if ( HIDWORD(v32) > 0x3EA )
      {
        if ( HIDWORD(v32) == 5005 )
        {
          HIDWORD(v30) = 5005;
          v33 = va::va(
                  this: &v57,
                  fmt: "Text-based lipsync failed with exit code: %d but a retry with textless lipsync succeeded.",
                  a3: v30,
                  a4: v29,
                  a5: v28,
                  a6: v39,
                  a7: v40,
                  a8: v41,
                  a9: v42,
                  a10: v43,
                  a11: v44);
          goto LABEL_50;
        }
LABEL_51:
        idStr::FreeData(this: &v50);
        idStr::FreeData(this: &v46);
        idStr::FreeData(this: &v49);
        idStr::FreeData(this: &v48);
        idStr::FreeData(this: &v47);
        return 1002;
      }
      if ( HIDWORD(v32) < 0x3E9 )
      {
        if ( HIDWORD(v32) == 1000 )
        {
          HIDWORD(v29) = v46.data;
          v33 = va::va(
                  this: &v54,
                  fmt: "Failed to exec Annosoft utility. Exit code: %d. Command line: %s %s",
                  a3: (unsigned int)v47.data | 0x3E800000000LL,
                  a4: v29,
                  a5: v28,
                  a6: v39,
                  a7: v40,
                  a8: v41,
                  a9: v42,
                  a10: v43,
                  a11: v44);
LABEL_50:
          idStr::operator=(this: errorMsg, text: v33);
          goto LABEL_51;
        }
        goto LABEL_51;
      }
      goto LABEL_45;
    }
  }
  HIDWORD(v32) = v45;
LABEL_40:
  if ( HIDWORD(v32) != 0 )
    goto LABEL_41;
  if ( started != 0 )
  {
    HIDWORD(v28) = fileSystem->FileExists(this: fileSystem, a2: outAnnoFilePath->data, a3: false);
    if ( HIDWORD(v28) != 0 )
    {
      idStr::FreeData(this: &v50);
      idStr::FreeData(this: &v46);
      idStr::FreeData(this: &v49);
      idStr::FreeData(this: &v48);
      idStr::FreeData(this: &v47);
      return 0;
    }
    HIDWORD(v32) = v45;
  }
  HIDWORD(v29) = v46.data;
  LODWORD(v32) = v47.data;
  v38 = va::va(
          this: &v57,
          fmt: "Phonem generation failed. No phoneme file was output. Exit code: %d. Command line: %s %s",
          a3: v32,
          a4: v29,
          a5: v28,
          a6: v39,
          a7: v40,
          a8: v41,
          a9: v42,
          a10: v43,
          a11: v44);
  idStr::operator=(this: errorMsg, text: v38);
  idStr::FreeData(this: &v50);
  idStr::FreeData(this: &v46);
  idStr::FreeData(this: &v49);
  idStr::FreeData(this: &v48);
LABEL_57:
  idStr::FreeData(this: &v47);
  return 1001;
}


// ========================================================================
// __unwind$224783
// EA  : 0x82631DC0
// RVA : 0x00631DC0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_224783()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17520 + 128));
}


// ========================================================================
// __unwind$224784
// EA  : 0x82631DE8
// RVA : 0x00631DE8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_224784()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17520 + 160));
}


// ========================================================================
// __unwind$224785
// EA  : 0x82631E10
// RVA : 0x00631E10
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_224785()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17520 + 192));
}


// ========================================================================
// __unwind$224786
// EA  : 0x82631E38
// RVA : 0x00631E38
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_224786()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17520 + 96));
}


// ========================================================================
// __unwind$224787
// EA  : 0x82631E60
// RVA : 0x00631E60
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_224787()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 17520 + 224));
}


// ========================================================================
// ?GetVoiceTrack@idPhonemeTrack_Annosoft@@UBA_NAAVidVoiceTrack@@H@Z
// EA  : 0x826322D8
// RVA : 0x006322D8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idPhonemeTrack_Annosoft::GetVoiceTrack(idPhonemeTrack_Annosoft *this, idVoiceTrack *out, char genFlags)
{
  const idDeclVisemeSet *declVisemeSet; // r21
  int v7; // r15
  idPhonemeTrack_Annosoft::idPhonemeEvent *v8; // r26
  idPhonemeTrack_Annosoft::extendedPhoneme_t exType; // r11
  int type; // r4
  char v11; // r11
  int v12; // r27
  int v13; // r4
  char v14; // r11
  __int64 v15; // r8
  int v16; // r29
  int v17; // r28
  double v18; // fp10
  int v19; // r25
  int v20; // r30
  idVoiceEvent *v21; // r3
  int v22; // r11
  double weight; // fp0
  int v24; // r8
  int v25; // r6
  int v26; // r11
  int v27; // r10
  idPhonemeTrack_Annosoft::weight_t *v28; // r9
  double v29; // fp0
  idVoiceEvent *v30; // r3
  int v31; // r11
  idViseme_Frame *v32; // r27
  int v33; // r28
  int v34; // r29
  int v35; // r9
  int numWeights; // r6
  signed int v37; // r3
  int v38; // r5
  int v39; // r4
  int v40; // r10
  idPhonemeTrack_Annosoft::weight_t *weights; // r30
  __int64 v42; // r8 OVERLAPPED
  int v43; // r11
  int v44; // r11
  int v45; // r11
  double v46; // fp13
  int v47; // r9
  int v48; // r11
  double v49; // fp0
  int v50; // r11
  int v51; // r9
  idVoiceEvent *Event; // r30
  int v53; // r11
  idVoiceEvent *v54; // r3
  int v55; // r11
  int v57; // [sp+58h] [-2F8h]
  idVoiceTrack v58; // [sp+5Ch] [-2F4h] BYREF

  idVoiceTrack::FreeVisemeEvents(this: out, freeTextToo: true);
  out->rebuildFrameRefs = false;
  declVisemeSet = out->declVisemeSet;
  v57 = 0;
  if ( this->phonemes.num > 0 )
  {
    v58.trackedMemory = (int)"Unknown phoneme extended type: %d";
    v7 = 0;
    v58.name.str = "Invalid viseme type %d";
    v58.resourceError = "Invalid phoneme type %d";
    do
    {
      v8 = &this->phonemes.list[v7];
      exType = v8->exType;
      if ( exType != EXPHONEME_PHONEME )
      {
        if ( exType == EXPHONEME_WORD )
        {
          idVoiceTrack::AllocEvent(
            this: (idVoiceTrack *)&v58.networkID,
            result: (vtrEventHandle_t *)out,
            type: VOICEEVENT_TEXT);
          Event = idVoiceEventManager::GetEvent(
                    this: &out->voiceEventManager,
                    handle: (const vtrEventHandle_t *)v58.networkID);
          idStr::operator=(this: (idStr *)&Event[1], text: v8->text.data);
          Event->startMS = v8->startMS;
          v53 = v8->endMS - v8->startMS;
          if ( v53 >= 0 )
          {
            if ( v53 > 0x7FFF )
              LOWORD(v53) = 0x7FFF;
            Event->durationMS = v53;
          }
          else
          {
            Event->durationMS = 0;
          }
        }
        else if ( exType == EXPHONEME_PUNCTUATION )
        {
          idVoiceTrack::AllocEvent(this: &v58, result: (vtrEventHandle_t *)out, type: VOICEEVENT_PUNCTUATION);
          v54 = idVoiceEventManager::GetEvent(
                  this: &out->voiceEventManager,
                  handle: (const vtrEventHandle_t *)v58.__vftable);
          HIBYTE(v54[1].__vftable) = *v8->text.data;
          v54->startMS = v8->startMS;
          v55 = v8->endMS - v8->startMS;
          if ( v55 >= 0 )
          {
            if ( v55 > 0x7FFF )
              LOWORD(v55) = 0x7FFF;
            v54->durationMS = v55;
          }
          else
          {
            v54->durationMS = 0;
          }
        }
        else
        {
          idLib::Warning(fmt: (const char *)v58.trackedMemory, v8->type);
        }
        goto LABEL_76;
      }
      type = v8->type;
      if ( v8->type < 0 || (v11 = 1, type >= declVisemeSet->phonemes.num) )
        v11 = 0;
      if ( v11 != 0 )
      {
        v12 = (int)&declVisemeSet->phonemes.list[type];
        v13 = *(_DWORD *)(v12 + 8);
        if ( v13 < 0 || (v14 = 1, v13 >= declVisemeSet->visemes.num) )
          v14 = 0;
        if ( v14 != 0 )
        {
          HIDWORD(v15) = v8->endMS;
          v16 = (int)&declVisemeSet->visemes.list[v13];
          v17 = 16
              * ((int)((((unsigned int)(*(_DWORD *)(v12 + 20) + v8->startMS) >> 31) - 1)
                     & (*(_DWORD *)(v12 + 20) + v8->startMS))
               / 16);
          LODWORD(v15) = HIDWORD(v15) - v17;
          v18 = (float)((float)v15 * *(float *)(v12 + 16));
          *(_QWORD *)&v58.staleCount = v15;
          v19 = (int)((((unsigned int)(int)v18 >> 31) - 1) & (int)v18) / 16;
          v20 = 16 * v19;
          if ( (genFlags & 1) == 0 )
          {
            idVoiceTrack::AllocEvent(
              this: (idVoiceTrack *)&v58.nextOnHashChain,
              result: (vtrEventHandle_t *)out,
              type: VOICEEVENT_VISEME_FRAME);
            v30 = idVoiceEventManager::GetEvent(
                    this: &out->voiceEventManager,
                    handle: (const vtrEventHandle_t *)v58.nextOnHashChain);
            v31 = *(_DWORD *)(v16 + 8);
            v32 = (idViseme_Frame *)v30;
            v30->startMS = v17;
            HIBYTE(v30[1].__vftable) = v31;
            if ( (v19 & 0x8000000) != 0 )
            {
              LOWORD(v20) = 0;
            }
            else if ( v20 > 0x7FFF )
            {
              LOWORD(v20) = 0x7FFF;
            }
            v30->durationMS = v20;
            v58.voiceEventManager.eventsVisemeSimple.size = 512;
            v58.voiceEventManager.eventsVisemeSimple.num = 0;
            v58.voiceEventManager.eventsVisemeSimple.granularity = 1;
            v58.voiceEventManager.eventsVisemeSimple.list = (idViseme_Simple *)&v58.voiceEventManager.eventsGame;
            v58.voiceEventManager.eventsVisemeSimple.memTag = 5;
            v58.voiceEventManager.eventsVisemeSimple.listStatic = 1;
            idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v58.voiceEventManager, newNum: v19);
            v33 = 0;
            if ( v19 <= 0 )
            {
LABEL_57:
              idViseme_Frame::SetWeights(
                this: v32,
                weights_: (const unsigned __int8 *)v58.voiceEventManager.eventsVisemeSimple.list,
                numWeights_: v58.voiceEventManager.eventsVisemeSimple.num);
              if ( v58.voiceEventManager.eventsVisemeSimple.listStatic == 0
                || v58.voiceEventManager.eventsVisemeSimple.listStatic == 2 )
              {
                if ( v58.voiceEventManager.eventsVisemeSimple.list != nullptr )
                  idMem::Free(this: &mem, ptr: v58.voiceEventManager.eventsVisemeSimple.list, align: ALIGN_16);
                v58.voiceEventManager.eventsVisemeSimple.list = nullptr;
                v58.voiceEventManager.eventsVisemeSimple.size = 0;
              }
              v58.voiceEventManager.eventsVisemeSimple.num = 0;
              goto LABEL_76;
            }
            while ( 2 )
            {
              v34 = 16 * v33;
              v35 = -1;
              numWeights = v8->numWeights;
              v37 = 0x80000000;
              v38 = -1;
              v39 = 0x7FFFFFFF;
              v40 = 0;
              if ( numWeights <= 0 )
                goto LABEL_44;
              weights = v8->weights;
              LODWORD(v42) = 0;
              HIDWORD(v42) = v8->startMS;
              do
              {
                v43 = *(int *)((char *)&weights->startMS + v42) - HIDWORD(v42) - v34;
                if ( v43 <= 0 && v43 > v37 )
                {
                  v35 = v40;
                  v37 = *(int *)((char *)&weights->startMS + v42) - HIDWORD(v42) - v34;
                }
                if ( v43 >= 0 && v43 < v39 )
                {
                  v38 = v40;
                  v39 = *(int *)((char *)&weights->startMS + v42) - HIDWORD(v42) - v34;
                }
                ++v40;
                LODWORD(v42) = v42 + 12;
              }
              while ( v40 < numWeights );
              if ( v35 == v38 )
              {
LABEL_44:
                v44 = (int)(float)(v8->weights[v35].weight * (float)255.0);
                if ( v44 < 0 )
                {
                  LOBYTE(v44) = 0;
                  goto LABEL_56;
                }
LABEL_54:
                if ( v44 > 255 )
                  LOBYTE(v44) = -1;
              }
              else
              {
                if ( v35 < 0 )
                {
                  v47 = 0;
                  v46 = 0.0;
                }
                else
                {
                  v45 = (int)&v8->weights[v35];
                  v46 = *(float *)(v45 + 8);
                  v47 = *(_DWORD *)v45 - HIDWORD(v42);
                }
                if ( v38 < 0 )
                {
                  v50 = 16 * v33;
                  v49 = 0.0;
                }
                else
                {
                  v48 = (int)&v8->weights[v38];
                  v49 = *(float *)(v48 + 8);
                  v50 = *(_DWORD *)v48 - HIDWORD(v42);
                }
                LODWORD(v42) = v34 - v47;
                v51 = v50 - v47;
                *(_QWORD *)&v58.events.list = *(__int64 *)((char *)&v42 - 4);
                *(_QWORD *)&v58.events.size = v42;
                v44 = (int)(float)((float)((float)((float)((float)v49 - (float)v46)
                                                 * (float)((float)v42 / (float)*(__int64 *)((char *)&v42 - 4)))
                                         + (float)v46)
                                 * (float)255.0);
                if ( v44 >= 0 )
                  goto LABEL_54;
                LOBYTE(v44) = 0;
              }
LABEL_56:
              *((_BYTE *)&v58.voiceEventManager.eventsVisemeSimple.list->__vftable + v33++) = v44;
              if ( v33 >= v19 )
                goto LABEL_57;
              continue;
            }
          }
          idVoiceTrack::AllocEvent(
            this: (idVoiceTrack *)&v58.resourceListPtr,
            result: (vtrEventHandle_t *)out,
            type: VOICEEVENT_VISEME_SIMPLE);
          v21 = idVoiceEventManager::GetEvent(
                  this: &out->voiceEventManager,
                  handle: (const vtrEventHandle_t *)v58.resourceListPtr);
          v22 = *(_DWORD *)(v16 + 8);
          v21->startMS = v17;
          HIBYTE(v21[1].__vftable) = v22;
          if ( (v19 & 0x8000000) != 0 )
          {
            LOWORD(v20) = 0;
          }
          else if ( v20 > 0x7FFF )
          {
            LOWORD(v20) = 0x7FFF;
          }
          v21->durationMS = v20;
          weight = 0.0;
          v24 = v8->numWeights;
          v25 = -1;
          v26 = 0;
          if ( v24 > 0 )
          {
            v27 = 0;
            v28 = v8->weights;
            do
            {
              if ( v28->weight > weight )
              {
                v25 = v26;
                weight = v28->weight;
              }
              ++v26;
              v28 = &v8->weights[++v27];
            }
            while ( v26 < v24 );
          }
          HIWORD(v21[1].startMS) = v8->weights[v25].startMS - v17;
          v29 = (float)(*(float *)(v12 + 12) * (float)weight);
          if ( v29 >= 0.0 )
          {
            if ( v29 > 1.0 )
              v29 = 1.0;
          }
          else
          {
            v29 = 0.0;
          }
          BYTE2(v21[1].startMS) = (int)(float)((float)v29 * (float)255.0);
        }
        else
        {
          idLib::Warning(fmt: v58.name.str, v13);
        }
      }
      else
      {
        idLib::Warning(fmt: v58.resourceError, type);
      }
LABEL_76:
      ++v7;
      ++v57;
    }
    while ( v57 < this->phonemes.num );
  }
  if ( vo_mergeVisemes.valueInteger != 0 )
  {
    idVoiceTrack::OffsetVisemeEvents(this: out, ofs: EVENTOFFSET_FORWARDS);
    idVoiceTrack::MergeVisemes(this: out);
  }
  else
  {
    idVoiceTrack::OffsetVisemeEvents(this: out, ofs: EVENTOFFSET_FORWARDS);
  }
  out->rebuildFrameRefs = true;
  idVoiceTrack::BuildFrameRefs(this: out);
  return 1;
}


// ========================================================================
// __unwind$225603
// EA  : 0x82632954
// RVA : 0x00632954
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_225603()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 848 + 144));
}


// ========================================================================
// ReadListFile
// EA  : 0x82632988
// RVA : 0x00632988
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall ReadListFile(const char *path, const char *prefix, idList<idStr,5> *files)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  va *v9; // r3
  char v10; // r30
  int v11; // r30
  int v12; // r10
  int i; // r9
  int v14; // r11
  int v15; // r3
  int v16; // [sp+8h] [-3168h]
  int v17; // [sp+Ch] [-3164h]
  int v18; // [sp+10h] [-3160h]
  int v19; // [sp+14h] [-315Ch]
  int v20; // [sp+18h] [-3158h]
  int v21; // [sp+1Ch] [-3154h]
  _BYTE v22[16]; // [sp+50h] [-3120h] BYREF
  idLexer v23; // [sp+60h] [-3110h] BYREF
  idStr v24; // [sp+F0h] [-3080h] BYREF
  char v25; // [sp+110h] [-3060h] BYREF
  idStr v26; // [sp+1110h] [-2060h] BYREF
  char v27; // [sp+1130h] [-2040h] BYREF
  va v28; // [sp+2130h] [-1040h] BYREF

  idLexer::idLexer(this: &v23, flags_: 0);
  if ( !idLexer::LoadFile(this: &v23, filename_: path, OSPath: false) )
  {
    HIDWORD(v8) = path;
    v9 = va::va(
           this: &v28,
           fmt: "Failed to load list file '%s'",
           a3: v8,
           a4: v7,
           a5: v6,
           a6: v16,
           a7: v17,
           a8: v18,
           a9: v19,
           a10: v20,
           a11: v21);
    strncpy(dest: idException::error, source: v9->buffer, count: 0x800u);
    CxxThrowException(pExceptionObject: v22, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
  }
  v26.baseBuffer[0] = 0;
  v27 = 0;
  v26.data = &v27;
  v26.len = 0;
  v26.allocedAndFlag = -2147479552;
  while ( !idLexer::EndOfFile(this: &v23) )
  {
    idLexer::ParseCompleteLine(this: &v23, out: &v26);
    idStr::StripLeadingWhiteSpace(this: &v26);
    v10 = 1;
    if ( prefix != nullptr && *prefix != 0 )
    {
      if ( idStr::Find(searchIn: v26.data, searchFor: prefix, casesensitive: true, start: 0, end: -1) != 0 )
        v10 = 0;
      else
        idStr::StripLeading(this: &v26, string: prefix);
    }
    if ( v10 != 0 )
    {
      v11 = 0;
      v12 = 0;
      for ( i = 0; i < v26.len; ++v11 )
      {
        v14 = v26.data[i];
        if ( v14 < 48 || v14 > 57 )
        {
          if ( v14 == 58 && v12 == 1 )
          {
            v12 = 2;
          }
          else
          {
            if ( v14 != 32 || v12 != 2 )
              break;
            v12 = 3;
          }
        }
        else
        {
          v12 = 1;
        }
        ++i;
      }
      v24.baseBuffer[0] = 0;
      v25 = 0;
      v24.data = &v25;
      v24.len = 0;
      v24.allocedAndFlag = -2147479552;
      idStr::operator=(this: &v24, text: &v26.data[v11]);
      if ( v11 > 0 )
      {
        v15 = idStr::Find(str: v24.data, c: 58, start: 0, end: -1);
        if ( v15 != -1 )
          v24.data[v15] = 0;
      }
      idStr::StripTrailingWhitespace(this: &v24);
      idStr::StripTrailing(this: &v24, c: 10);
      idStr::StripTrailing(this: &v26, c: 13);
      idList<idStr,5>::Append(this: files, obj: &v24);
      idStr::FreeData(this: &v24);
    }
  }
  if ( files->num <= 0 )
  {
    strncpy(dest: idException::error, source: "No files found.", count: 0x800u);
    CxxThrowException(pExceptionObject: v22, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
  }
  idStr::FreeData(this: &v26);
  idLexer::~idLexer(this: &v23);
}


// ========================================================================
// $LN103_0
// EA  : 0x82632C20
// RVA : 0x00632C20
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _LN103_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 12656 + 96));
}


// ========================================================================
// __unwind$225960
// EA  : 0x82632C48
// RVA : 0x00632C48
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_225960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12656 + 4368));
}


// ========================================================================
// __unwind$226050
// EA  : 0x82632C70
// RVA : 0x00632C70
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226050()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12656 + 240));
}


// ========================================================================
// __unwind$225961
// EA  : 0x82632C98
// RVA : 0x00632C98
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_225961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12656 + 240));
}


// ========================================================================
// ?Lipsync_WriteTextAndExecTool@@YA?AW4annosoftError_t@@PBD00AAVidStr@@1_N1@Z
// EA  : 0x82632CC8
// RVA : 0x00632CC8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall Lipsync_WriteTextAndExecTool(
        const char *languageName,
        const char *lipsyncText,
        const char *sampleName,
        idStr *outTextFilePath,
        idStr *outAnnoFilePath,
        bool textless,
        idStr *errorMsg)
{
  char *data; // r4
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  int v19; // r3
  void (__fastcall ***v20)(_DWORD, int); // r29
  va *v21; // r3
  int v22; // r5
  int v23; // r30
  int v24; // [sp+8h] [-10E8h]
  int v25; // [sp+Ch] [-10E4h]
  int v26; // [sp+10h] [-10E0h]
  int v27; // [sp+14h] [-10DCh]
  int v28; // [sp+18h] [-10D8h]
  int v29; // [sp+1Ch] [-10D4h]
  idStr v30; // [sp+50h] [-10A0h] BYREF
  idStr v31; // [sp+70h] [-1080h] BYREF
  va v32; // [sp+90h] [-1060h] BYREF

  if ( lipsyncText == nullptr )
    return 5001;
  if ( sampleName == nullptr )
    return 5002;
  v30.len = 0;
  v30.allocedAndFlag = 20;
  v30.data = v30.baseBuffer;
  v30.baseBuffer[0] = 0;
  if ( *lipsyncText != 0 )
  {
    if ( (unsigned __int8)Lipsync_IntermediateFilePathFromSampleName(sampleName, filePath: &v30) == 0 )
    {
      idStr::FreeData(this: &v30);
      return 5003;
    }
    idStr::SetFileExtension(this: &v30, extension: "txt");
  }
  v31.allocedAndFlag = 20;
  v31.len = 0;
  v31.data = v31.baseBuffer;
  v31.baseBuffer[0] = 0;
  idStr::operator=(this: &v31, text: &v30);
  idStr::SetFileExtension(this: &v31, extension: "anno");
  data = v30.data;
  if ( *v30.data != 0 )
  {
    v19 = ((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
    v20 = (void (__fastcall ***)(_DWORD, int))v19;
    if ( v19 == 0 )
    {
      HIDWORD(v18) = v30.data;
      v21 = va::va(
              this: &v32,
              fmt: "Error writing text file:\n\n%s",
              a3: v18,
              a4: v17,
              a5: v16,
              a6: v24,
              a7: v25,
              a8: v26,
              a9: v27,
              a10: v28,
              a11: v29);
      idStr::operator=(this: errorMsg, text: v21);
      idStr::FreeData(this: &v31);
      idStr::FreeData(this: &v30);
      return 5004;
    }
    v22 = 0;
    if ( *lipsyncText != 0 )
    {
      do
        ++v22;
      while ( lipsyncText[v22] != 0 );
    }
    (*(void (__fastcall **)(int, const char *, int))(*(_DWORD *)v19 + 16))(a1: v19, a2: lipsyncText, a3: v22);
    (**v20)(a1: v20, a2: 1);
    data = v30.data;
  }
  v23 = Lipsync_ExecTool(
          languageName,
          sampleName,
          textFileName: data,
          annoFilePath: v31.data,
          outTextFilePath,
          outAnnoFilePath,
          textless,
          errorMsg);
  idStr::FreeData(this: &v31);
  idStr::FreeData(this: &v30);
  return v23;
}


// ========================================================================
// __unwind$226190
// EA  : 0x82632EB0
// RVA : 0x00632EB0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226190()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 80));
}


// ========================================================================
// __unwind$226191
// EA  : 0x82632ED8
// RVA : 0x00632ED8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226191()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 112));
}


// ========================================================================
// ??0idPhonemeTrack_Annosoft@@QAA@XZ
// EA  : 0x82633098
// RVA : 0x00633098
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

idPhonemeTrack_Annosoft *__fastcall idPhonemeTrack_Annosoft::idPhonemeTrack_Annosoft(idPhonemeTrack_Annosoft *this)
{
  this->__vftable = (idPhonemeTrack_Annosoft_vtbl *)&idPhonemeTrack_Annosoft::`vftable';
  this->phonemes.granularity = 0;
  this->phonemes.memTag = 68;
  this->phonemes.listStatic = 0;
  this->phonemes.list = nullptr;
  this->phonemes.size = 0;
  this->phonemes.num = 0;
  return this;
}


// ========================================================================
// __unwind$226457
// EA  : 0x826330E4
// RVA : 0x006330E4
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226457()
{
  int v0; // r12

  idPhonemeTrack::~idPhonemeTrack(this: *(idPhonemeTrack **)(v0 - 32 + 52));
}


// ========================================================================
// ??1idPhonemeTrack_Annosoft@@UAA@XZ
// EA  : 0x82633118
// RVA : 0x00633118
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(idPhonemeTrack_Annosoft *this)
{
  idPhonemeTrack_Annosoft::idPhonemeEvent *list; // r3

  this->__vftable = (idPhonemeTrack_Annosoft_vtbl *)&idPhonemeTrack_Annosoft::`vftable';
  if ( this->phonemes.listStatic == 0 || this->phonemes.listStatic == 2 )
  {
    list = this->phonemes.list;
    if ( list != nullptr )
      idListArrayDelete<idPhonemeTrack_Annosoft::idPhonemeEvent>(ptr: list, num: this->phonemes.size);
    this->phonemes.list = nullptr;
    this->phonemes.size = 0;
  }
  this->phonemes.num = 0;
  this->__vftable = (idPhonemeTrack_Annosoft_vtbl *)&idPhonemeTrack::`vftable';
}


// ========================================================================
// __unwind$226490
// EA  : 0x82633188
// RVA : 0x00633188
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226490()
{
  int v0; // r12

  idPhonemeTrack::~idPhonemeTrack(this: *(idPhonemeTrack **)(v0 - 112 + 132));
}


// ========================================================================
// ?ConvertPhonemeTrack@@YA_NPBD000PBVidDeclVisemeSet@@0HAAVidStr@@@Z
// EA  : 0x826331B8
// RVA : 0x006331B8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall ConvertPhonemeTrack(
        const char *languageName,
        const char *inFile,
        const char *lipsyncTextFile,
        const char *soundShaderName,
        const idDeclVisemeSet *declVisemeSet,
        const char *outFileName,
        char genFlags,
        idStr *errorMsg)
{
  unsigned int v15; // r30
  idVoiceTrack *v16; // r29
  const idDeclVisemeSet *v17; // r4
  bool v18; // r23
  unsigned int v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  va *v22; // r3
  char v24; // r5
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  va *v28; // r3
  va *v29; // r3
  const idSoundShader *v30; // r4
  va *v31; // r3
  int v32; // [sp+8h] [-1118h]
  int v33; // [sp+Ch] [-1114h]
  int v34; // [sp+10h] [-1110h]
  int v35; // [sp+14h] [-110Ch]
  int v36; // [sp+18h] [-1108h]
  int v37; // [sp+1Ch] [-1104h]
  idStrId v38[4]; // [sp+50h] [-10D0h] BYREF
  idPhonemeTrack_Annosoft v39; // [sp+60h] [-10C0h] BYREF
  char *v40; // [sp+74h] [-10ACh] BYREF
  idStr v41; // [sp+80h] [-10A0h] BYREF
  idStr v42; // [sp+A0h] [-1080h] BYREF
  va v43; // [sp+C0h] [-1060h] BYREF

  v15 = 0;
  v39.__vftable = (idPhonemeTrack_Annosoft_vtbl *)&idPhonemeTrack_Annosoft::`vftable';
  v39.phonemes.memTag = 68;
  v39.phonemes.listStatic = 0;
  memset(&v39.phonemes, 0, 14);
  idStr::idStr(this: &v42, text: inFile);
  v41.len = 0;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.baseBuffer[0] = 0;
  idStr::ExtractFileExtension(this: &v42, dest: &v41);
  v16 = (idVoiceTrack *)idResourceList::Load(
                          this: &idVoiceTrack::resourceList,
                          name: outFileName,
                          makeDefault: false,
                          skipStaleCheck: false);
  v17 = declVisemeSet;
  v16->declVisemeSet = declVisemeSet;
  v18 = v16->resourceError != nullptr;
  if ( (unsigned __int8)idPhonemeTrack_Annosoft::Load(this: &v39, declVisemeSet: v17, fileName: v42.data) == 0 )
  {
    HIDWORD(v21) = v42.data;
    v22 = va::va(
            this: &v43,
            fmt: "Failed to load file '%s'...",
            a3: v21,
            a4: v20,
            a5: v19,
            a6: v32,
            a7: v33,
            a8: v34,
            a9: v35,
            a10: v36,
            a11: v37);
    idStr::operator=(this: errorMsg, text: v22);
    idStr::FreeData(this: &v41);
    idStr::FreeData(this: &v42);
    idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
    return 0;
  }
  v24 = genFlags;
  if ( vo_genSimpleVisemes.valueInteger != 0 )
    v24 = genFlags | 1;
  if ( (unsigned __int8)idPhonemeTrack_Annosoft::GetVoiceTrack(this: &v39, out: v16, genFlags: v24) == 0 )
  {
    HIDWORD(v27) = v42.data;
    v28 = va::va(
            this: &v43,
            fmt: "Error building voice track from phoneme track '%s'",
            a3: v27,
            a4: v26,
            a5: v25,
            a6: v32,
            a7: v33,
            a8: v34,
            a9: v35,
            a10: v36,
            a11: v37);
    idStr::operator=(this: errorMsg, text: v28);
    idStr::FreeData(this: &v41);
    idStr::FreeData(this: &v42);
    idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
    return 0;
  }
  if ( (genFlags & 2) != 0 )
  {
    if ( lipsyncTextFile == nullptr
      || *lipsyncTextFile == 0
      || (v38[0].index = 0,
          LODWORD(v27) = fileSystem->ReadFile(this: fileSystem, a2: lipsyncTextFile, a3: (void **)v38, a4: nullptr),
          (int)v27 <= 0) )
    {
      HIDWORD(v27) = lipsyncTextFile;
      v29 = va::va(
              this: &v43,
              fmt: "Failed to spread out text events - missing text file '%s'",
              a3: v27,
              a4: v26,
              a5: v25,
              a6: v32,
              a7: v33,
              a8: v34,
              a9: v35,
              a10: v36,
              a11: v37);
      idStr::operator=(this: errorMsg, text: v29);
      idStr::FreeData(this: &v41);
      idStr::FreeData(this: &v42);
      idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
      return 0;
    }
    if ( !idVoiceTrack::SpreadOutTextEvents(
            this: v16,
            languageName,
            text: (const char *)v38[0].index,
            textLen: v27,
            errorMsg) )
    {
      fileSystem->FreeFile(this: fileSystem, a2: (void *)v38[0].index);
      idStr::FreeData(this: &v41);
      idStr::FreeData(this: &v42);
      idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
      return 0;
    }
    fileSystem->FreeFile(this: fileSystem, a2: (void *)v38[0].index);
  }
  if ( !v18 )
  {
    if ( soundShaderName == nullptr
      || (v30 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                         this: &idSoundShader::resourceList,
                                         name: soundShaderName,
                                         makeDefault: false)) == nullptr )
    {
      HIDWORD(v27) = v42.data;
      v31 = va::va(
              this: &v43,
              fmt: "No sound shader could be found for vtr '%s'",
              a3: v27,
              a4: v26,
              a5: v25,
              a6: v32,
              a7: v33,
              a8: v34,
              a9: v35,
              a10: v36,
              a11: v37);
      idStr::operator=(this: errorMsg, text: v31);
      idStr::FreeData(this: &v41);
      idStr::FreeData(this: &v42);
      idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
      return 0;
    }
    idVoiceTrack::SetSoundShader(this: v16, shader: v30);
  }
  v38[0] = v16->textId;
  idVoiceTrack::SetTrackTextId(this: v16, id: v38);
  if ( lipsyncTextFile != nullptr
    && *lipsyncTextFile != 0
    && fileSystem->ReadFile(this: fileSystem, a2: lipsyncTextFile, a3: (void **)&v40, a4: nullptr) != 0 )
  {
    v15 = idVoiceTrack::CalcTextCRC(text: v40);
    fileSystem->FreeFile(this: fileSystem, a2: v40);
  }
  v16->lipsyncTextCRC = v15;
  idVoiceTrack::Save(this: v16, fileName: outFileName);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v42);
  idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v39);
  return 1;
}


// ========================================================================
// __unwind$226543
// EA  : 0x826335A8
// RVA : 0x006335A8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226543()
{
  int v0; // r12

  idPhonemeTrack::~idPhonemeTrack(this: (idPhonemeTrack *)(v0 - 4384 + 96));
}


// ========================================================================
// __unwind$226539
// EA  : 0x826335D0
// RVA : 0x006335D0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226539()
{
  int v0; // r12

  idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: (idPhonemeTrack_Annosoft *)(v0 - 4384 + 96));
}


// ========================================================================
// __unwind$226540
// EA  : 0x826335F8
// RVA : 0x006335F8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226540()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 160));
}


// ========================================================================
// __unwind$226541
// EA  : 0x82633620
// RVA : 0x00633620
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226541()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 128));
}


// ========================================================================
// ?Lipsync_ConvertPhonemes@@YA_NPBD00000HW4annosoftError_t@@AAVidStr@@@Z
// EA  : 0x82633650
// RVA : 0x00633650
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall Lipsync_ConvertPhonemes(
        const char *languageName,
        const char *annoFilePath,
        const char *textFilePath,
        const char *vtrPath,
        const char *visemeSetName,
        const char *soundShaderName,
        char genFlags,
        const annosoftError_t genError,
        idStr *errorMsg,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idStr *a28)
{
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  const idDeclVisemeSet *v38; // r28
  va *v39; // r3
  char v41; // r30
  int v42; // [sp+8h] [-10F8h]
  int v43; // [sp+Ch] [-10F4h]
  int v44; // [sp+10h] [-10F0h]
  int v45; // [sp+14h] [-10ECh]
  int v46; // [sp+18h] [-10E8h]
  int v47; // [sp+1Ch] [-10E4h]
  idStr v48; // [sp+50h] [-10B0h] BYREF
  idStr v49; // [sp+70h] [-1090h] BYREF
  idStr v50; // [sp+90h] [-1070h] BYREF
  va v51; // [sp+B0h] [-1050h] BYREF

  idStr::idStr(this: &v50, text: annoFilePath);
  if ( soundShaderName == nullptr )
    soundShaderName = "vo/default";
  idStr::idStr(this: &v49, text: textFilePath);
  idStr::idStr(this: &v48, text: vtrPath);
  if ( visemeSetName == nullptr
    || (v38 = (const idDeclVisemeSet *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclVisemeSet::resourceList,
                                         name: visemeSetName,
                                         makeDefault: true)) == nullptr )
  {
    HIDWORD(v37) = visemeSetName;
    v39 = va::va(
            this: &v51,
            fmt: "The viseme set '%s' was not found.",
            a3: v37,
            a4: v36,
            a5: v35,
            a6: v42,
            a7: v43,
            a8: v44,
            a9: v45,
            a10: v46,
            a11: v47);
    idStr::operator=(this: a28, text: v39);
    idStr::FreeData(this: &v48);
    idStr::FreeData(this: &v49);
    idStr::FreeData(this: &v50);
    return 0;
  }
  v41 = genFlags;
  if ( genError == ANNOSOFT_ERROR_PHONEME_GEN_FAILED )
  {
    v41 = genFlags | 2;
  }
  else if ( genError != ANNOSOFT_ERROR_SUCCESS )
  {
    idStr::operator=(this: a28, text: "Unrecoverable Annosoft generation error.");
    idStr::FreeData(this: &v48);
    idStr::FreeData(this: &v49);
    idStr::FreeData(this: &v50);
    return 0;
  }
  idStr::SetFileExtension(this: &v48, extension: "vtr");
  if ( (unsigned __int8)ConvertPhonemeTrack(
                          languageName,
                          inFile: v50.data,
                          lipsyncTextFile: v49.data,
                          soundShaderName,
                          declVisemeSet: v38,
                          outFileName: v48.data,
                          genFlags: v41,
                          errorMsg: a28) != 0 )
  {
    idStr::FreeData(this: &v48);
    idStr::FreeData(this: &v49);
    idStr::FreeData(this: &v50);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v48);
    idStr::FreeData(this: &v49);
    idStr::FreeData(this: &v50);
    return 0;
  }
}


// ========================================================================
// __unwind$226758
// EA  : 0x826337E4
// RVA : 0x006337E4
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 144));
}


// ========================================================================
// __unwind$226759
// EA  : 0x8263380C
// RVA : 0x0063380C
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226759()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 112));
}


// ========================================================================
// __unwind$226760
// EA  : 0x82633834
// RVA : 0x00633834
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226760()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 80));
}


// ========================================================================
// ?convertPhonemes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82633868
// RVA : 0x00633868
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall convertPhonemes_f(const idCmdArgs *args)
{
  char v1; // r30
  int argc; // r10
  idStr *v3; // [sp+8h] [-A8h]
  int v4; // [sp+Ch] [-A4h]
  int v5; // [sp+10h] [-A0h]
  int v6; // [sp+14h] [-9Ch]
  int v7; // [sp+18h] [-98h]
  int v8; // [sp+1Ch] [-94h]
  int v9; // [sp+20h] [-90h]
  int v10; // [sp+24h] [-8Ch]
  int v11; // [sp+28h] [-88h]
  int v12; // [sp+2Ch] [-84h]
  int v13; // [sp+30h] [-80h]
  int v14; // [sp+34h] [-7Ch]
  int v15; // [sp+38h] [-78h]
  int v16; // [sp+3Ch] [-74h]
  int v17; // [sp+40h] [-70h]
  int v18; // [sp+44h] [-6Ch]
  int v19; // [sp+48h] [-68h]
  int v20; // [sp+4Ch] [-64h]
  int v21; // [sp+50h] [-60h]
  idStr v22; // [sp+70h] [-40h] BYREF

  v1 = 0;
  v22.len = 0;
  v22.baseBuffer[0] = 0;
  v22.allocedAndFlag = 20;
  v22.data = v22.baseBuffer;
  argc = args->argc;
  if ( args->argc == 3 )
  {
    v1 = Lipsync_ConvertPhonemes(
           languageName: sys_lang.valueString.data,
           annoFilePath: args->argv[0],
           textFilePath: args->argv[1],
           vtrPath: nullptr,
           visemeSetName: nullptr,
           soundShaderName: nullptr,
           genFlags: 0,
           genError: ANNOSOFT_ERROR_SUCCESS,
           errorMsg: v3,
           a10: v4,
           a11: v5,
           a12: v6,
           a13: v7,
           a14: v8,
           a15: v9,
           a16: v10,
           a17: v11,
           a18: v12,
           a19: v13,
           a20: v14,
           a21: v15,
           a22: v16,
           a23: v17,
           a24: v18,
           a25: v19,
           a26: v20,
           a27: v21,
           a28: &v22);
  }
  else if ( argc == 5 )
  {
    v1 = Lipsync_ConvertPhonemes(
           languageName: sys_lang.valueString.data,
           annoFilePath: args->argv[0],
           textFilePath: args->argv[1],
           vtrPath: args->argv[2],
           visemeSetName: args->argv[3],
           soundShaderName: nullptr,
           genFlags: 0,
           genError: ANNOSOFT_ERROR_SUCCESS,
           errorMsg: v3,
           a10: v4,
           a11: v5,
           a12: v6,
           a13: v7,
           a14: v8,
           a15: v9,
           a16: v10,
           a17: v11,
           a18: v12,
           a19: v13,
           a20: v14,
           a21: v15,
           a22: v16,
           a23: v17,
           a24: v18,
           a25: v19,
           a26: v20,
           a27: v21,
           a28: &v22);
  }
  else if ( argc == 6 )
  {
    v1 = Lipsync_ConvertPhonemes(
           languageName: sys_lang.valueString.data,
           annoFilePath: args->argv[0],
           textFilePath: args->argv[1],
           vtrPath: args->argv[2],
           visemeSetName: args->argv[3],
           soundShaderName: args->argv[4],
           genFlags: 0,
           genError: ANNOSOFT_ERROR_SUCCESS,
           errorMsg: v3,
           a10: v4,
           a11: v5,
           a12: v6,
           a13: v7,
           a14: v8,
           a15: v9,
           a16: v10,
           a17: v11,
           a18: v12,
           a19: v13,
           a20: v14,
           a21: v15,
           a22: v16,
           a23: v17,
           a24: v18,
           a25: v19,
           a26: v20,
           a27: v21,
           a28: &v22);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: convertPhonemes [.anno folder] [viseme set name]\n");
    idLib::Printf(fmt: "USAGE: convertPhonemes [.anno file] [text file name] [out name] [viseme set name] <sound shader name>\n");
    idLib::Printf(fmt: "  Converts an Annosoft phoneme file to a voice track file.\n");
    idLib::Printf(fmt: "  If a folder name is given then all .anno files in the\n");
    idLib::Printf(fmt: "  folder and its children are converted, using the folder\n");
    idLib::Printf(fmt: "  names as a base for constructing the voice track decl names.\n");
    idLib::Printf(fmt: "  If a .anno file name is given, then the file is converted,\n");
    idLib::Printf(fmt: "  to a voice track decl, its name is set to the out name, and\n");
    idLib::Printf(fmt: "  its sound shader (if specified) is set.\n");
  }
  if ( v1 == 0 )
    idLib::Warning(fmt: v22.data);
  idStr::FreeData(this: &v22);
}


// ========================================================================
// __unwind$226878
// EA  : 0x82633AC8
// RVA : 0x00633AC8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_226878()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?RegenVoicetrack@@YA_NABVidStr@@PBVidDeclVisemeSet@@_NHAAV1@3@Z
// EA  : 0x82633AF8
// RVA : 0x00633AF8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall RegenVoicetrack(
        const idStr *vtrFileName,
        const idDeclVisemeSet *visemeSet,
        const bool verifyOnly,
        char regenFlags,
        idStr *errorMsg,
        idStr *warningMsg)
{
  char v12; // r30
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  va *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  idVoiceTrack *v20; // r3
  idVoiceTrack *v21; // r25
  const char *v22; // r4
  char *data; // r11
  const idSoundShader *soundShader; // r20
  unsigned int v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  va *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  va *v33; // r3
  const char *LocalizedString; // r3
  __int64 v35; // r8
  __int64 v36; // r6
  __int64 v37; // r10
  va *v38; // r4
  idStr *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  idFile *v43; // r3
  idFile *v44; // r29
  va *v45; // r3
  int v46; // r3
  bool v47; // r11
  unsigned int v48; // r3
  int index; // r11
  int v50; // [sp+8h] [-13C8h]
  int v51; // [sp+Ch] [-13C4h]
  int v52; // [sp+10h] [-13C0h]
  int v53; // [sp+14h] [-13BCh]
  int v54; // [sp+18h] [-13B8h]
  int v55; // [sp+1Ch] [-13B4h]
  idStrId v56; // [sp+50h] [-1380h] BYREF
  idStr v57; // [sp+60h] [-1370h] BYREF
  idStr v58; // [sp+80h] [-1350h] BYREF
  idStr v59; // [sp+A0h] [-1330h] BYREF
  idStr v60; // [sp+C0h] [-1310h] BYREF
  idStr v61; // [sp+E0h] [-12F0h] BYREF
  idStr v62; // [sp+100h] [-12D0h] BYREF
  idStr v63; // [sp+120h] [-12B0h] BYREF
  idStr v64; // [sp+140h] [-1290h] BYREF
  char v65[256]; // [sp+160h] [-1270h] BYREF
  _BYTE v66[256]; // [sp+260h] [-1170h] BYREF
  va v67; // [sp+360h] [-1070h] BYREF

  idStr::EnsureAlloced(this: errorMsg, amount: 1, keepold: true, geometricGrowth: false);
  v12 = 0;
  *errorMsg->data = 0;
  errorMsg->len = 0;
  idStr::EnsureAlloced(this: warningMsg, amount: 1, keepold: true, geometricGrowth: false);
  LODWORD(v15) = warningMsg->data;
  *(_BYTE *)v15 = 0;
  warningMsg->len = 0;
  if ( visemeSet == nullptr )
  {
    v16 = va::va(
            this: &v67,
            fmt: "NULL viseme set.",
            a3: v14,
            a4: v13,
            a5: v15,
            a6: v50,
            a7: v51,
            a8: v52,
            a9: v53,
            a10: v54,
            a11: v55);
LABEL_44:
    idStr::operator=(this: errorMsg, text: v16);
    return 0;
  }
  v20 = (idVoiceTrack *)idResourceList::Load(
                          this: &idVoiceTrack::resourceList,
                          name: vtrFileName->data,
                          makeDefault: false,
                          skipStaleCheck: false);
  v21 = v20;
  if ( v20 == nullptr )
  {
    v22 = "Error loading voice track '%s'.";
LABEL_43:
    HIDWORD(v19) = vtrFileName->data;
    v16 = va::va(
            this: &v67,
            fmt: v22,
            a3: v19,
            a4: v18,
            a5: v17,
            a6: v50,
            a7: v51,
            a8: v52,
            a9: v53,
            a10: v54,
            a11: v55);
    goto LABEL_44;
  }
  if ( (regenFlags & 1) == 0 && (unsigned __int8)idVoiceTrack::IsEdited(this: v20) != 0 )
  {
    idLib::Printf(fmt: "^6Skipping edited voice track '%s'.\n", vtrFileName->data);
    return 1;
  }
  if ( (regenFlags & 4) == 0 )
  {
    data = v21->animName.data;
    LODWORD(v17) = (unsigned __int8)*data;
    if ( *data != 0 )
    {
      idLib::Printf(fmt: "^6Skipping hand-keyed voice track '%s'.\n", vtrFileName->data);
      return 1;
    }
  }
  if ( (regenFlags & 2) == 0 && idVoiceTrack::IsCustomized(this: v21) )
  {
    idLib::Printf(fmt: "^6Skipping customized voice track '%s'.\n", vtrFileName->data);
    return 1;
  }
  soundShader = v21->soundShader;
  if ( soundShader == nullptr
    || (v56.index = soundShader->entries.num) <= 0
    || (LODWORD(v17) = soundShader->entries.list, HIDWORD(v17) = *(_DWORD *)v17, *(_DWORD *)v17 == 0) )
  {
    v22 = "Voice track '%s' has an invalid sound shader.";
    goto LABEL_43;
  }
  idStr::idStr(
    this: &v57,
    text: *(const char **)((((__PAIR64__((unsigned int)v56.index >> 31, 0) - (unsigned int)v56.index) >> 32) & HIDWORD(v17))
                   + 8));
  if ( fileSystem->FileExists(this: fileSystem, a2: v57.data, a3: false) )
  {
    v60.len = 0;
    v60.baseBuffer[0] = 0;
    v60.allocedAndFlag = 20;
    v60.data = v60.baseBuffer;
    idStr::ExtractFileExtension(this: &v57, dest: &v60);
    idStr::ToLower(this: &v60);
    if ( idStr::Cmp(s1: v60.data, s2: "wav") != 0 )
    {
      HIDWORD(v32) = v57.data;
      v33 = va::va(
              this: &v67,
              fmt: "Annosoft phoneme tool only accepts .wav files as audio input. Wave file was '%s'",
              a3: v32,
              a4: v31,
              a5: v30,
              a6: v50,
              a7: v51,
              a8: v52,
              a9: v53,
              a10: v54,
              a11: v55);
      idStr::operator=(this: errorMsg, text: v33);
      idStr::FreeData(this: &v60);
      idStr::FreeData(this: &v57);
    }
    else
    {
      fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v57.data, a3: v65, a4: 256, a5: FSPATH_BASE);
      idStr::operator=(this: &v57, text: v65);
      LocalizedString = idStrId::GetLocalizedString(this: &v21->textId);
      idStr::idStr(this: &v59, text: LocalizedString);
      HIDWORD(v37) = v59.len;
      if ( v59.len == 0 )
      {
        HIDWORD(v36) = v59.data;
        if ( verifyOnly )
        {
          v38 = va::va(
                  this: &v67,
                  fmt: "Missing string id '%s'",
                  a3: v36,
                  a4: v35,
                  a5: v37,
                  a6: v50,
                  a7: v51,
                  a8: v52,
                  a9: v53,
                  a10: v54,
                  a11: v55);
          v39 = errorMsg;
        }
        else
        {
          v38 = va::va(
                  this: &v67,
                  fmt: "Missing string id '%s'. Regenerating with empty text.",
                  a3: v36,
                  a4: v35,
                  a5: v37,
                  a6: v50,
                  a7: v51,
                  a8: v52,
                  a9: v53,
                  a10: v54,
                  a11: v55);
          v39 = warningMsg;
        }
        idStr::operator=(this: v39, text: v38);
      }
      if ( verifyOnly )
      {
        idStr::FreeData(this: &v59);
        idStr::FreeData(this: &v60);
        idStr::FreeData(this: &v57);
        return 1;
      }
      idStr::idStr(this: &v63, text: "intermediate/");
      idStr::Append(this: &v63, text: vtrFileName);
      fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v63.data, a3: v65, a4: 256, a5: FSPATH_BASE);
      idStr::operator=(this: &v63, text: v65);
      idStr::idStr(this: &v64, text: &v63);
      idStr::SetFileExtension(this: &v64, extension: "anno");
      v58.allocedAndFlag = 20;
      v58.data = v58.baseBuffer;
      v58.len = 0;
      v58.baseBuffer[0] = 0;
      if ( v59.len != 0 )
      {
        idStr::operator=(this: &v58, text: &v63);
        idStr::SetFileExtension(this: &v58, extension: "txt");
        fileSystem->OSPathToRelativePath(this: fileSystem, a2: v58.data, a3: v66, a4: 256);
        v43 = fileSystem->OpenFileWrite(this: fileSystem, a2: v66, a3: 0);
        v44 = v43;
        if ( v43 == nullptr )
        {
          HIDWORD(v42) = v58.data;
          v45 = va::va(
                  this: &v67,
                  fmt: "Error writing text file '%s'",
                  a3: v42,
                  a4: v41,
                  a5: v40,
                  a6: v50,
                  a7: v51,
                  a8: v52,
                  a9: v53,
                  a10: v54,
                  a11: v55);
          idStr::operator=(this: errorMsg, text: v45);
          idStr::FreeData(this: &v58);
          idStr::FreeData(this: &v64);
          idStr::FreeData(this: &v63);
          idStr::FreeData(this: &v59);
          idStr::FreeData(this: &v60);
          idStr::FreeData(this: &v57);
          return 0;
        }
        v43->Write(this: v43, a2: v59.data, a3: v59.len);
        ((void (__fastcall *)(idFile *, int))v44->dtr_idFile)(a1: v44, a2: 1);
      }
      v62.allocedAndFlag = 20;
      v62.len = 0;
      v62.data = v62.baseBuffer;
      v62.baseBuffer[0] = 0;
      v61.allocedAndFlag = 20;
      v61.data = v61.baseBuffer;
      v61.len = 0;
      v61.baseBuffer[0] = 0;
      v46 = Lipsync_ExecTool(
              languageName: sys_lang.valueString.data,
              sampleName: v57.data,
              textFileName: v59.len == 0 ? nullptr : v58.data,
              annoFilePath: v64.data,
              outTextFilePath: &v62,
              outAnnoFilePath: &v61,
              textless: (regenFlags & 0x10) != 0,
              errorMsg);
      if ( v46 == 0 || v46 == 1002 )
      {
        v47 = (_cntlzw((regenFlags & 0x18) - 24) & 0x20) != 0;
        if ( v46 == 1002 || v47 )
        {
          if ( (regenFlags & 8) == 0 )
          {
            idStr::operator=(this: errorMsg, text: "Phoneme generation failed while text redistribution was disabled.");
            idStr::FreeData(this: &v61);
            idStr::FreeData(this: &v62);
            idStr::FreeData(this: &v58);
            idStr::FreeData(this: &v64);
            idStr::FreeData(this: &v63);
            idStr::FreeData(this: &v59);
            idStr::FreeData(this: &v60);
            idStr::FreeData(this: &v57);
            return 0;
          }
          v12 = 2;
        }
        v48 = idVoiceTrack::CalcTextCRC(text: v59.data);
        index = v21->textId.index;
        v21->lipsyncTextCRC = v48;
        v56.index = index;
        idVoiceTrack::SetTrackTextId(this: v21, id: &v56);
        idVoiceTrack::SetSoundShader(this: v21, shader: soundShader);
        if ( (unsigned __int8)ConvertPhonemeTrack(
                                languageName: sys_lang.valueString.data,
                                inFile: v61.data,
                                lipsyncTextFile: v62.data,
                                soundShaderName: soundShader->name.str,
                                declVisemeSet: visemeSet,
                                outFileName: vtrFileName->data,
                                genFlags: v12,
                                errorMsg) != 0 )
        {
          idLib::Printf(fmt: "Rewrote voicetrack '%s'.\n", vtrFileName->data);
          idStr::FreeData(this: &v61);
          idStr::FreeData(this: &v62);
          idStr::FreeData(this: &v58);
          idStr::FreeData(this: &v64);
          idStr::FreeData(this: &v63);
          idStr::FreeData(this: &v59);
          idStr::FreeData(this: &v60);
          idStr::FreeData(this: &v57);
          return 1;
        }
      }
      idStr::FreeData(this: &v61);
      idStr::FreeData(this: &v62);
      idStr::FreeData(this: &v58);
      idStr::FreeData(this: &v64);
      idStr::FreeData(this: &v63);
      idStr::FreeData(this: &v59);
      idStr::FreeData(this: &v60);
      idStr::FreeData(this: &v57);
    }
  }
  else
  {
    HIDWORD(v28) = v57.data;
    v29 = va::va(
            this: &v67,
            fmt: "Wave file '%s' was not found.",
            a3: v28,
            a4: v27,
            a5: v26,
            a6: v50,
            a7: v51,
            a8: v52,
            a9: v53,
            a10: v54,
            a11: v55);
    idStr::operator=(this: errorMsg, text: v29);
    idStr::FreeData(this: &v57);
  }
  return 0;
}


// ========================================================================
// __unwind$227069
// EA  : 0x82634228
// RVA : 0x00634228
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 96));
}


// ========================================================================
// __unwind$227070
// EA  : 0x82634250
// RVA : 0x00634250
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227070()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 192));
}


// ========================================================================
// __unwind$227071
// EA  : 0x82634278
// RVA : 0x00634278
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227071()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 160));
}


// ========================================================================
// __unwind$227072
// EA  : 0x826342A0
// RVA : 0x006342A0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227072()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 288));
}


// ========================================================================
// __unwind$227073
// EA  : 0x826342C8
// RVA : 0x006342C8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 320));
}


// ========================================================================
// __unwind$227074
// EA  : 0x826342F0
// RVA : 0x006342F0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 128));
}


// ========================================================================
// __unwind$227075
// EA  : 0x82634318
// RVA : 0x00634318
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 256));
}


// ========================================================================
// __unwind$227076
// EA  : 0x82634340
// RVA : 0x00634340
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5072 + 224));
}


// ========================================================================
// ?regenVoicetracks_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82634370
// RVA : 0x00634370
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall regenVoicetracks_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v3; // r15
  int v4; // r17
  int v5; // r29
  int v6; // r30
  const char **v7; // r28
  const char *v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  const char *v15; // r4
  int v16; // r11
  const char *v17; // r4
  const idDecl *v18; // r3
  const idDeclVisemeSet *v19; // r19
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  sysFolder_t v23; // r3
  va *v24; // r3
  idStr *list; // r18
  idFileList *v26; // r29
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  va *v30; // r3
  int v31; // r28
  int v32; // r30
  idStr *v33; // r21
  idStr *v34; // r23
  int num; // r24
  __int64 v36; // kr00_8
  __int64 v37; // kr08_8
  char **p_data; // r30
  int i; // r27
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  va *v43; // r3
  __int64 v44; // r6
  va *v45; // r3
  int v46; // r11
  const char **v47; // r28
  int v48; // r30
  int v49; // r11
  const char **v50; // r29
  int v51; // r30
  idStr *v52; // r29
  int j; // r30
  idStr *v54; // r29
  int k; // r30
  int size; // r30
  idStr *v57; // r29
  int v58; // [sp+8h] [-12D8h]
  int v59; // [sp+Ch] [-12D4h]
  int v60; // [sp+10h] [-12D0h]
  int v61; // [sp+14h] [-12CCh]
  int v62; // [sp+18h] [-12C8h]
  int v63; // [sp+1Ch] [-12C4h]
  idList<idStr,5> v64; // [sp+60h] [-1280h] BYREF
  idList<idStr,5> v65; // [sp+70h] [-1270h] BYREF
  idList<idStr,5> v66; // [sp+80h] [-1260h] BYREF
  idStr v67; // [sp+90h] [-1250h] BYREF
  idStr v68; // [sp+B0h] [-1230h] BYREF
  idStr v69; // [sp+D0h] [-1210h] BYREF
  idStr v70; // [sp+F0h] [-11F0h] BYREF
  idStr v71; // [sp+110h] [-11D0h] BYREF
  idStr v72; // [sp+130h] [-11B0h] BYREF
  char v73[256]; // [sp+150h] [-1190h] BYREF
  va v74; // [sp+250h] [-1090h] BYREF

  argc = args->argc;
  if ( args->argc == 1 )
  {
    idLib::Printf(fmt: "USAGE: regenVoicetracks [-v] [-o] [-e] [-h] [-c] [-t] <path> [viseme set name]\n");
    idLib::Printf(fmt: "Switches:\n");
    idLib::Printf(fmt: "  -v : only verify the voice track assets exists -- do not write out new voice tracks.\n");
    idLib::Printf(fmt: "  -o : overwrite all voicetracks.\n");
    idLib::Printf(fmt: "  -e : overwrite voicetracks edited in maya.\n");
    idLib::Printf(fmt: "  -h : overwrite voice tracks with hand-keyed animations.\n");
    idLib::Printf(fmt: "  -c : overwrite voice tracks with custom parameters.\n");
    idLib::Printf(fmt: "  -r : do not redistribute text event timings if generation fails.\n");
    idLib::Printf(fmt: "  -t : use Annosoft textless generation.\n");
    return;
  }
  v3 = false;
  v4 = 8;
  v5 = 0;
  v6 = 1;
  if ( argc > 1 )
  {
    v7 = (const char **)&args->argv[1];
    do
    {
      if ( v6 < 0 || v6 >= argc )
        v8 = &byte_8200D768;
      else
        v8 = *v7;
      if ( idStr::Icmp(s1: v8, s2: "-v") != 0 )
      {
        if ( v6 < 0 || v6 >= args->argc )
          v9 = &byte_8200D768;
        else
          v9 = *v7;
        if ( idStr::Icmp(s1: v9, s2: "-o") != 0 )
        {
          if ( v6 < 0 || v6 >= args->argc )
            v10 = &byte_8200D768;
          else
            v10 = *v7;
          if ( idStr::Icmp(s1: v10, s2: "-e") != 0 )
          {
            if ( v6 < 0 || v6 >= args->argc )
              v11 = &byte_8200D768;
            else
              v11 = *v7;
            if ( idStr::Icmp(s1: v11, s2: "-h") != 0 )
            {
              if ( v6 < 0 || v6 >= args->argc )
                v12 = &byte_8200D768;
              else
                v12 = *v7;
              if ( idStr::Icmp(s1: v12, s2: "-c") != 0 )
              {
                if ( v6 < 0 || v6 >= args->argc )
                  v13 = &byte_8200D768;
                else
                  v13 = *v7;
                if ( idStr::Icmp(s1: v13, s2: "-r") != 0 )
                {
                  if ( v6 < 0 || v6 >= args->argc )
                    v14 = &byte_8200D768;
                  else
                    v14 = *v7;
                  if ( idStr::Icmp(s1: v14, s2: "-t") != 0 )
                    goto LABEL_48;
                  v4 |= 0x18u;
                }
                else
                {
                  v4 &= ~8u;
                }
              }
              else
              {
                v4 |= 2u;
              }
            }
            else
            {
              v4 |= 4u;
            }
          }
          else
          {
            v4 |= 1u;
          }
        }
        else
        {
          v4 |= 7u;
        }
      }
      else
      {
        v3 = true;
      }
      ++v5;
LABEL_48:
      argc = args->argc;
      ++v6;
      ++v7;
    }
    while ( v6 < args->argc );
  }
  if ( v5 + 1 < 0 || v5 + 1 >= argc )
    v15 = &byte_8200D768;
  else
    v15 = args->argv[v5 + 1];
  idStr::idStr(this: &v67, text: v15);
  if ( !fileSystem->IsRelativePath(this: fileSystem, a2: v67.data) )
  {
    fileSystem->OSPathToRelativePath(this: fileSystem, a2: v67.data, a3: v73, a4: 256);
    idStr::operator=(this: &v67, text: v73);
  }
  v16 = v5 + 2;
  if ( args->argc <= v5 + 2 )
  {
    v17 = idVoiceTrack::DEFAULT_VISEME_SET_NAME;
  }
  else
  {
    if ( v16 < 0 || v16 >= args->argc )
    {
      v17 = &byte_8200D768;
LABEL_60:
      v18 = idDeclInfo::FindWithInheritance(this: &idDeclVisemeSet::resourceList, name: v17, makeDefault: true);
      goto LABEL_61;
    }
    v17 = args->argv[v5 + 2];
  }
  if ( v17 != nullptr )
    goto LABEL_60;
  v18 = nullptr;
LABEL_61:
  v19 = (const idDeclVisemeSet *)v18;
  *(_WORD *)&v64.memTag = 1280;
  memset(&v64, 0, 14);
  v69.len = 0;
  v69.allocedAndFlag = 20;
  v69.data = v69.baseBuffer;
  v69.baseBuffer[0] = 0;
  v68.allocedAndFlag = 20;
  v68.data = v68.baseBuffer;
  v68.len = 0;
  v68.baseBuffer[0] = 0;
  v23 = fileSystem->IsFolder(this: fileSystem, a2: v67.data, a3: FSPATH_BASE);
  if ( v23 != FOLDER_ERROR )
  {
    if ( v23 != FOLDER_NO )
    {
      v26 = fileSystem->ListFilesTree(this: fileSystem, a2: v67.data, a3: "vtr", a4: 0);
      if ( v26 == nullptr )
      {
        HIDWORD(v29) = v67.data;
        v30 = va::va(
                this: &v74,
                fmt: "No files found at path '%s'",
                a3: v29,
                a4: v28,
                a5: v27,
                a6: v58,
                a7: v59,
                a8: v60,
                a9: v61,
                a10: v62,
                a11: v63);
        idLib::Warning(fmt: v30->buffer);
        idStr::FreeData(this: &v68);
        idStr::FreeData(this: &v69);
        idList<idStr,99>::~idList<idStr,99>(this: &v64);
        goto LABEL_112;
      }
      idList<idStr,3>::SetNum(this: &v64, newNum: v26->list.num);
      v31 = 0;
      list = v64.list;
      if ( v26->list.num > 0 )
      {
        v32 = 0;
        do
        {
          idStr::operator=(this: &list[v32], text: v26->list.list[v32].data);
          ++v31;
          ++v32;
        }
        while ( v31 < v26->list.num );
      }
      fileSystem->FreeFileList(this: fileSystem, a2: v26);
    }
    else
    {
      v70.allocedAndFlag = 20;
      v70.len = 0;
      v70.data = v70.baseBuffer;
      v70.baseBuffer[0] = 0;
      idStr::ExtractFileExtension(this: &v67, dest: &v70);
      if ( idStr::Cmp(s1: v70.data, s2: "vtr") != 0 )
        ReadListFile(path: v67.data, prefix: nullptr, files: &v64);
      else
        idList<idStr,5>::Append(this: &v64, obj: &v67);
      idStr::FreeData(this: &v70);
      list = v64.list;
    }
    common->SetRefreshOnPrint(this: common, a2: true);
    v33 = nullptr;
    *(_WORD *)&v66.memTag = 1280;
    memset(&v66, 0, 14);
    v34 = nullptr;
    *(_WORD *)&v65.memTag = 1280;
    memset(&v65, 0, 14);
    num = v64.num;
    v36 = 0;
    v37 = 0;
    if ( v64.num > 0 )
    {
      p_data = &list->data;
      for ( i = v64.num; i != 0; --i )
      {
        idLib::Printf(fmt: "----------------------------------------\n");
        if ( (unsigned __int8)RegenVoicetrack(
                                vtrFileName: (const idStr *)(p_data - 1),
                                visemeSet: v19,
                                verifyOnly: v3,
                                regenFlags: v4,
                                errorMsg: &v69,
                                warningMsg: &v68) == 0 )
        {
          HIDWORD(v42) = *p_data;
          LODWORD(v42) = v69.data;
          v43 = va::va(
                  this: &v74,
                  fmt: "%s: %s",
                  a3: v42,
                  a4: v41,
                  a5: v40,
                  a6: v58,
                  a7: v59,
                  a8: v60,
                  a9: v61,
                  a10: v62,
                  a11: v63);
          idStr::idStr(this: &v71, text: v43);
          idList<idStr,5>::Append(this: &v66, obj: &v71);
          idLib::Warning(fmt: v69.data);
          idStr::FreeData(this: &v71);
        }
        if ( v68.len != 0 )
        {
          LODWORD(v44) = v68.data;
          HIDWORD(v44) = *p_data;
          v45 = va::va(
                  this: &v74,
                  fmt: "%s: %s",
                  a3: v44,
                  a4: v41,
                  a5: v40,
                  a6: v58,
                  a7: v59,
                  a8: v60,
                  a9: v61,
                  a10: v62,
                  a11: v63);
          idStr::idStr(this: &v72, text: v45);
          idList<idStr,5>::Append(this: &v65, obj: &v72);
          idLib::Warning(fmt: v68.data);
          idStr::FreeData(this: &v72);
        }
        p_data += 8;
      }
      v36 = *(_QWORD *)&v66.num;
      v33 = v66.list;
      v37 = *(_QWORD *)&v65.num;
      v34 = v65.list;
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idLib::Printf(fmt: "Successfully regenerated ^2%d ^7voice tracks.\n", num - HIDWORD(v36));
    idLib::Printf(fmt: "Failed to regenerate ^1%d ^7voice tracks. Errors follow:\n", HIDWORD(v36));
    if ( SHIDWORD(v36) > 0 )
    {
      v46 = 0;
      v47 = (const char **)&v33[-1].data;
      do
      {
        v48 = v46 + 1;
        v47 += 8;
        idLib::Printf(fmt: "^7%d: ^1%s\n", v46 + 1, *v47);
        v46 = v48;
      }
      while ( v48 < SHIDWORD(v36) );
    }
    if ( SHIDWORD(v37) > 0 )
    {
      idLib::Printf(fmt: "^3%d ^7voice tracks had warnings during regeneration. Warnings follow:\n", HIDWORD(v37));
      v49 = 0;
      v50 = (const char **)&v34[-1].data;
      do
      {
        v51 = v49 + 1;
        v50 += 8;
        idLib::Printf(fmt: "^7%d: ^3%s\n", v49 + 1, *v50);
        v49 = v51;
      }
      while ( v51 < SHIDWORD(v37) );
    }
    if ( (v65.listStatic == 0 || v65.listStatic == 2) && v34 != nullptr )
    {
      if ( (int)v37 > 0 )
      {
        v52 = v34;
        for ( j = v37; j != 0; --j )
          idStr::FreeData(this: v52++);
      }
      idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
    }
    if ( (v66.listStatic == 0 || v66.listStatic == 2) && v33 != nullptr )
    {
      if ( (int)v36 > 0 )
      {
        v54 = v33;
        for ( k = v36; k != 0; --k )
          idStr::FreeData(this: v54++);
      }
      idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
    }
    idStr::FreeData(this: &v68);
    idStr::FreeData(this: &v69);
    if ( (v64.listStatic == 0 || v64.listStatic == 2) && list != nullptr )
    {
      size = v64.size;
      if ( v64.size > 0 )
      {
        v57 = list;
        do
        {
          idStr::FreeData(this: v57);
          --size;
          ++v57;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    goto LABEL_112;
  }
  HIDWORD(v22) = v67.data;
  v24 = va::va(
          this: &v74,
          fmt: "Error finding path '%s'",
          a3: v22,
          a4: v21,
          a5: v20,
          a6: v58,
          a7: v59,
          a8: v60,
          a9: v61,
          a10: v62,
          a11: v63);
  idLib::Warning(fmt: v24->buffer);
  idStr::FreeData(this: &v68);
  idStr::FreeData(this: &v69);
LABEL_112:
  idStr::FreeData(this: &v67);
}


// ========================================================================
// __unwind$227695
// EA  : 0x82634BF8
// RVA : 0x00634BF8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227695()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 144));
}


// ========================================================================
// __unwind$227696
// EA  : 0x82634C20
// RVA : 0x00634C20
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227696()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4832 + 96));
}


// ========================================================================
// __unwind$227697
// EA  : 0x82634C48
// RVA : 0x00634C48
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227697()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 208));
}


// ========================================================================
// __unwind$227698
// EA  : 0x82634C70
// RVA : 0x00634C70
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227698()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 176));
}


// ========================================================================
// __unwind$227699
// EA  : 0x82634C98
// RVA : 0x00634C98
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227699()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 240));
}


// ========================================================================
// __unwind$227700
// EA  : 0x82634CC0
// RVA : 0x00634CC0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227700()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4832 + 128));
}


// ========================================================================
// __unwind$227701
// EA  : 0x82634CE8
// RVA : 0x00634CE8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227701()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4832 + 112));
}


// ========================================================================
// __unwind$227702
// EA  : 0x82634D10
// RVA : 0x00634D10
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227702()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 272));
}


// ========================================================================
// __unwind$227703
// EA  : 0x82634D38
// RVA : 0x00634D38
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_227703()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 304));
}


// ========================================================================
// ?GenerateAnimation@idPhonemeTrack_Annosoft@@QBA_NPBDPBVidDeclVisemeSet@@@Z
// EA  : 0x82634FB0
// RVA : 0x00634FB0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall idPhonemeTrack_Annosoft::GenerateAnimation(
        idPhonemeTrack_Annosoft *this,
        const char *fileName,
        const idDeclVisemeSet *visemeSet)
{
  int num; // r14
  int NumFrames; // r22
  int v8; // r26
  int v9; // r21
  int v10; // r18
  const idDeclVehicleUpgrade **list; // r15
  idFile *v12; // r3
  int j; // r30
  int k; // r29
  void (*Printf)(void); // ctr
  int m; // r30
  int n; // r11
  idPhonemeTrack_Annosoft::idPhonemeEvent *v19; // r28
  int type; // r4
  char v21; // r11
  int viseme; // r27
  char v23; // r11
  __int64 v24; // r10
  const idVec1 *v25; // r4
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp5
  double v30; // fp4
  double v31; // fp3
  double v32; // fp2
  int numWeights; // r29
  const idVec1 *v34; // r4
  double v35; // fp8
  double v36; // fp7
  double v37; // fp6
  double v38; // fp5
  double v39; // fp4
  double v40; // fp3
  double v41; // fp2
  __int64 v42; // r9
  const idVec1 *v43; // r4
  double v44; // fp8
  double v45; // fp7
  double v46; // fp6
  double v47; // fp5
  double v48; // fp4
  double v49; // fp3
  double v50; // fp2
  int i; // r30
  int v52; // r11
  __int64 v53; // r7
  const idVec1 *v54; // r4
  double v55; // fp8
  double v56; // fp7
  double v57; // fp6
  double v58; // fp5
  double v59; // fp4
  double v60; // fp3
  double v61; // fp2
  __int64 v62; // r11
  double v63; // fp8
  double v64; // fp7
  double v65; // fp6
  double v66; // fp5
  double v67; // fp4
  double v68; // fp3
  double v69; // fp2
  __int64 v70; // r11
  int v71; // r30
  int v72; // r29
  float *v73; // r28
  float v76; // [sp+8h] [-198h]
  float v77; // [sp+8h] [-198h]
  float v78; // [sp+8h] [-198h]
  float v79; // [sp+8h] [-198h]
  float v80; // [sp+8h] [-198h]
  float v81; // [sp+Ch] [-194h]
  float v82; // [sp+Ch] [-194h]
  float v83; // [sp+Ch] [-194h]
  float v84; // [sp+Ch] [-194h]
  float v85; // [sp+Ch] [-194h]
  float v86; // [sp+10h] [-190h]
  float v87; // [sp+10h] [-190h]
  float v88; // [sp+10h] [-190h]
  float v89; // [sp+10h] [-190h]
  float v90; // [sp+10h] [-190h]
  float v91; // [sp+14h] [-18Ch]
  float v92; // [sp+14h] [-18Ch]
  float v93; // [sp+14h] [-18Ch]
  float v94; // [sp+14h] [-18Ch]
  float v95; // [sp+14h] [-18Ch]
  float v96; // [sp+18h] [-188h]
  float v97; // [sp+18h] [-188h]
  float v98; // [sp+18h] [-188h]
  float v99; // [sp+18h] [-188h]
  float v100; // [sp+18h] [-188h]
  float v101; // [sp+1Ch] [-184h]
  float v102; // [sp+1Ch] [-184h]
  float v103; // [sp+1Ch] [-184h]
  float v104; // [sp+1Ch] [-184h]
  float v105; // [sp+1Ch] [-184h]
  double v106; // [sp+20h] [-180h]
  idFileLocal v107; // [sp+50h] [-150h] BYREF
  float v108; // [sp+54h] [-14Ch] BYREF
  idList<idDeclVehicleUpgrade const *,5> v109; // [sp+60h] [-140h] BYREF
  idVec1 v110; // [sp+70h] [-130h] BYREF
  idVec1 v111; // [sp+74h] [-12Ch] BYREF
  idVec1 v112; // [sp+78h] [-128h] BYREF
  idVec1 v113; // [sp+7Ch] [-124h] BYREF
  idVec1 v114; // [sp+80h] [-120h] BYREF
  idVec1 v115; // [sp+84h] [-11Ch] BYREF
  idCurve_CatmullRomSpline<idVec1> v116; // [sp+90h] [-110h] BYREF
  idCurve_CatmullRomSpline<idVec1> v117; // [sp+C4h] [-DCh] BYREF

  if ( fileName == nullptr || visemeSet == nullptr )
    return 0;
  num = visemeSet->visemes.num;
  NumFrames = idPhonemeTrack_Annosoft::GetNumFrames(this);
  v108 = 0.0;
  v8 = 1000 * NumFrames / 30;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v109);
  idList<float,17>::SetNum(this: (idList<float,32> *)&v109, newNum: NumFrames * num, initValue: &v108);
  v9 = 0;
  v108 = COERCE_FLOAT(&mem);
  v10 = this->phonemes.num;
  list = v109.list;
  while ( v9 < v10 )
  {
    v19 = &this->phonemes.list[v9];
    if ( v19->exType == EXPHONEME_PHONEME )
    {
      type = v19->type;
      if ( v19->type < 0 || (v21 = 1, type >= visemeSet->phonemes.num) )
        v21 = 0;
      if ( v21 == 0 )
      {
        idLib::Warning(fmt: "Invalid phoneme type %d", type);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v109);
        return 0;
      }
      viseme = visemeSet->phonemes.list[type].viseme;
      if ( viseme < 0 || (v23 = 1, viseme >= visemeSet->visemes.num) )
        v23 = 0;
      if ( v23 == 0 )
      {
        idLib::Warning(fmt: "Invalid viseme type %d", viseme);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v109);
        return 0;
      }
      idCurve_CatmullRomSpline<idVec1>::idCurve_CatmullRomSpline<idVec1>(this: &v116);
      numWeights = v19->numWeights;
      if ( numWeights > 0 )
      {
        v114.x = 0.0;
        LODWORD(v24) = -33;
        *(_QWORD *)&v117.values.size = v24;
        idCurve<idVec1>::AddValue(
          this: &v116,
          time: (float)v24,
          value: v25,
          a4: &v114,
          a5: v32,
          a6: v31,
          a7: v30,
          a8: v29,
          a9: v28,
          a10: v27,
          a11: v26,
          a12: v76,
          a13: v81,
          a14: v86,
          a15: v91,
          a16: v96,
          a17: v101);
        v115.x = 0.0;
        idCurve<idVec1>::AddValue(
          this: &v116,
          time: 0.0,
          value: v34,
          a4: &v115,
          a5: v41,
          a6: v40,
          a7: v39,
          a8: v38,
          a9: v37,
          a10: v36,
          a11: v35,
          a12: v77,
          a13: v82,
          a14: v87,
          a15: v92,
          a16: v97,
          a17: v102);
        for ( i = 0; i < numWeights; i = (__int16)(i + 1) )
        {
          v52 = (int)&v19->weights[i];
          LODWORD(v42) = *(_DWORD *)v52;
          v110.x = *(float *)(v52 + 8);
          *(_QWORD *)&v117.boundaryType = v42;
          idCurve<idVec1>::AddValue(
            this: &v116,
            time: (float)v42,
            value: v43,
            a4: &v110,
            a5: v50,
            a6: v49,
            a7: v48,
            a8: v47,
            a9: v46,
            a10: v45,
            a11: v44,
            a12: v78,
            a13: v83,
            a14: v88,
            a15: v93,
            a16: v98,
            a17: v103);
          HIDWORD(v42) = i + 1;
        }
        v113.x = 0.0;
        LODWORD(v53) = v19->weights[numWeights - 1].endMS;
        *(_QWORD *)&v117.currentIndex = v53;
        idCurve<idVec1>::AddValue(
          this: &v116,
          time: (float)v53,
          value: v43,
          a4: &v113,
          a5: v50,
          a6: v49,
          a7: v48,
          a8: v47,
          a9: v46,
          a10: v45,
          a11: v44,
          a12: v78,
          a13: v83,
          a14: v88,
          a15: v93,
          a16: v98,
          a17: v103);
        v111.x = 0.0;
        *(_QWORD *)&v117.values.list = __PAIR64__(&v111, v8);
        idCurve<idVec1>::AddValue(
          this: &v116,
          time: (float)__SPAIR64__(&v111, v8),
          value: v54,
          a4: &v111,
          a5: v61,
          a6: v60,
          a7: v59,
          a8: v58,
          a9: v57,
          a10: v56,
          a11: v55,
          a12: v79,
          a13: v84,
          a14: v89,
          a15: v94,
          a16: v99,
          a17: v104);
        v112.x = 0.0;
        LODWORD(v62) = v8 + 33;
        *(_QWORD *)&v117.times.list = v62;
        idCurve<idVec1>::AddValue(
          this: &v116,
          time: (float)v62,
          value: (const idVec1 *)(v8 + 33),
          a4: &v112,
          a5: v69,
          a6: v68,
          a7: v67,
          a8: v66,
          a9: v65,
          a10: v64,
          a11: v63,
          a12: v80,
          a13: v85,
          a14: v90,
          a15: v95,
          a16: v100,
          a17: v105);
        HIDWORD(v70) = 30 * v8 / 1000;
        LODWORD(v70) = 30 * v19->weights->startMS / 1000;
        if ( (int)v70 < SHIDWORD(v70) )
        {
          v71 = 1000 * v70;
          v72 = HIDWORD(v70) - v70;
          v73 = (float *)(&list[v70 - 1] + viseme * NumFrames);
          do
          {
            if ( v71 / 30 < v8 )
            {
              LODWORD(v70) = v71 / 30;
              *(_QWORD *)&v117.times.size = v70;
              _FP12 = *(float *)&idCurve_CatmullRomSpline<idVec1>::GetCurrentValue(
                                   this: &v117,
                                   result: &v116,
                                   time: (float)v70)->__vftable;
              __asm { fsel      f0, f12, f12, f31 }
            }
            else
            {
              _FP0 = 0.0;
            }
            *++v73 = _FP0;
            --v72;
            v71 += 1000;
          }
          while ( v72 != 0 );
        }
      }
      v116.__vftable = (idCurve_CatmullRomSpline<idVec1>_vtbl *)&idCurve<idVec1>::`vftable';
      if ( v116.values.listStatic == 0 || v116.values.listStatic == 2 )
      {
        if ( v116.values.list != nullptr )
          idMem::Free(this: (idMem *)LODWORD(v108), ptr: v116.values.list, align: ALIGN_16);
        v116.values.list = nullptr;
        v116.values.size = 0;
      }
      v116.values.num = 0;
      if ( v116.times.listStatic == 0 || v116.times.listStatic == 2 )
      {
        if ( v116.times.list != nullptr )
          idMem::Free(this: (idMem *)LODWORD(v108), ptr: v116.times.list, align: ALIGN_16);
        v116.times.list = nullptr;
        v116.times.size = 0;
      }
      v116.times.num = 0;
    }
    ++v9;
  }
  v12 = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName, a3: 0);
  v107.file = v12;
  if ( v12 != nullptr )
  {
    v12->Printf(this: v12, a2: "%s %i\n", MD6_VERSION_STRING, 7);
    v107.file->Printf(this: v107.file, a2: "init {\n");
    v107.file->Printf(
      this: v107.file,
      a2: "\tcommandLine \"-ex anim -startframe 0 -endframe %i -framerate 30.000000 -errorTolerance 0.600000\"\n",
      NumFrames - 1);
    v107.file->Printf(this: v107.file, a2: "\tsourceAnim \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\tsubtractiveAnim \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\trotationMask \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\tscaleMask \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\ttranslationMask \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\tskeletonName \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\tmeshName \"\"\n");
    v107.file->Printf(this: v107.file, a2: "\tnumFrames %i\n", NumFrames);
    v107.file->Printf(this: v107.file, a2: "\tframeRate 30\n");
    v107.file->Printf(this: v107.file, a2: "\tnumJoints 0\n");
    v107.file->Printf(this: v107.file, a2: "\tnumUserChannels %i\n", num);
    v107.file->Printf(this: v107.file, a2: "\ttranslatedBounds ( 0 0 0 ) ( 0 0 0 )\n");
    v107.file->Printf(this: v107.file, a2: "\tnormalizedBounds ( 0 0 0 ) ( 0 0 0 )\n");
    v107.file->Printf(this: v107.file, a2: "\terrorTolerance 0.600000\n");
    v107.file->Printf(this: v107.file, a2: "}\n\n");
    v107.file->Printf(this: v107.file, a2: "flags {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "joints {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "userChannels {\n");
    for ( j = 0; j < num; ++j )
      v107.file->Printf(this: v107.file, a2: "\t\"%s\"\n", visemeSet->visemes.list[j].name.str);
    v107.file->Printf(this: v107.file, a2: "}\n\n");
    v107.file->Printf(this: v107.file, a2: "rotationMask {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "scaleMask {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "translationMask {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "frames {\n}\n\n");
    v107.file->Printf(this: v107.file, a2: "userChannels {\n");
    for ( k = 0; ; ++k )
    {
      Printf = (void (*)(void))v107.file->Printf;
      if ( k >= NumFrames )
        break;
      Printf();
      for ( m = 0; m < num; ++m )
      {
        v106 = *((float *)&list[m * NumFrames] + k);
        v107.file->WriteFloatString(this: v107.file, a2: (const char *)HIDWORD(v106), LODWORD(v106));
      }
      v107.file->Printf(this: v107.file, a2: ")\n");
    }
    Printf();
    idFileLocal::~idFileLocal(this: &v107);
    if ( (v109.listStatic == 0 || v109.listStatic == 2) && list != nullptr )
    {
      for ( n = 0; n < v109.size; ++n )
        ;
      idMem::Free(this: (idMem *)LODWORD(v108), ptr: list, align: ALIGN_16);
    }
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Failed to open file '%s'", fileName);
    idFileLocal::~idFileLocal(this: &v107);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v109);
    return 0;
  }
}


// ========================================================================
// $M229133
// EA  : 0x826358BC
// RVA : 0x006358BC
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void *_M229133()
{
  idLib::Warning(fmt: "Error writing .md6anim file");
  return &_LN39;
}


// ========================================================================
// __unwind$228559
// EA  : 0x826358EC
// RVA : 0x006358EC
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_228559()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$228561
// EA  : 0x82635914
// RVA : 0x00635914
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_228561()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$228560
// EA  : 0x8263593C
// RVA : 0x0063593C
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_228560()
{
  int v0; // r12

  idCurve_CatmullRomSpline<idVec1>::~idCurve_CatmullRomSpline<idVec1>(this: (idCurve_CatmullRomSpline<idVec1> *)(v0 - 416 + 144));
}


// ========================================================================
// __unwind$228694
// EA  : 0x82635964
// RVA : 0x00635964
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_228694()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 148));
}


// ========================================================================
// ?ConvertPhonemesToAnim@@YA_NPBDPBVidDeclVisemeSet@@@Z
// EA  : 0x82635998
// RVA : 0x00635998
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall ConvertPhonemesToAnim(const char *inFile, const idDeclVisemeSet *declVisemeSet)
{
  idPhonemeTrack_Annosoft v5; // [sp+50h] [-60h] BYREF
  idStr v6[2]; // [sp+70h] [-40h] BYREF

  if ( inFile != nullptr && declVisemeSet != nullptr )
  {
    v5.__vftable = (idPhonemeTrack_Annosoft_vtbl *)&idPhonemeTrack_Annosoft::`vftable';
    v5.phonemes.memTag = 68;
    v5.phonemes.listStatic = 0;
    memset(&v5.phonemes, 0, 14);
    if ( (unsigned __int8)idPhonemeTrack_Annosoft::Load(this: &v5, declVisemeSet, fileName: inFile) != 0 )
    {
      idStr::idStr(this: v6, text: inFile);
      idStr::SetFileExtension(this: v6, extension: ".md6anim");
      if ( (unsigned __int8)idPhonemeTrack_Annosoft::GenerateAnimation(
                              this: &v5,
                              fileName: v6[0].data,
                              visemeSet: declVisemeSet) != 0 )
      {
        idStr::FreeData(this: v6);
        idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v5);
        return 1;
      }
      idLib::Warning(fmt: "Failed to generate animation from '%s'...", inFile);
      idStr::FreeData(this: v6);
      idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v5);
    }
    else
    {
      idLib::Warning(fmt: "Failed to load file '%s'...", inFile);
      idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: &v5);
    }
  }
  else
  {
    idLib::Warning(fmt: "ConvertPhonemesToAnim: Invalid parameters.");
  }
  return 0;
}


// ========================================================================
// __unwind$229165
// EA  : 0x82635AAC
// RVA : 0x00635AAC
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_229165()
{
  int v0; // r12

  idPhonemeTrack::~idPhonemeTrack(this: (idPhonemeTrack *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$229162
// EA  : 0x82635AD4
// RVA : 0x00635AD4
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_229162()
{
  int v0; // r12

  idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft(this: (idPhonemeTrack_Annosoft *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$229163
// EA  : 0x82635AFC
// RVA : 0x00635AFC
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_229163()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?Lipsync_ConvertPhonemesToAnim@@YAXPBD0@Z
// EA  : 0x82635B30
// RVA : 0x00635B30
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall Lipsync_ConvertPhonemesToAnim(char *annoFilePath, const char *visemeSetName)
{
  const idDeclVisemeSet *v4; // r23
  int v5; // r25
  int v6; // r26
  idFileList *v7; // r3
  int num; // r28
  idFileList *v9; // r29
  int v10; // r30
  int v11; // r27
  char *v12; // r4
  idStr v13[3]; // [sp+50h] [-70h] BYREF

  idStr::idStr(this: v13, text: "convertPhonemesToAnim: ");
  if ( annoFilePath != nullptr && visemeSetName != nullptr
    || (idLib::Warning(fmt: v13[0].data, "Invalid parameters."), visemeSetName != nullptr) )
  {
    v4 = (const idDeclVisemeSet *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclVisemeSet::resourceList,
                                    name: visemeSetName,
                                    makeDefault: true);
    if ( v4 != nullptr )
    {
      if ( fileSystem->IsFolder(this: fileSystem, a2: annoFilePath, a3: FSPATH_BASE) != FOLDER_NO )
      {
        v5 = 0;
        v6 = 0;
        v7 = fileSystem->ListFilesTree(this: fileSystem, a2: annoFilePath, a3: ".anno", a4: 0);
        num = v7->list.num;
        v9 = v7;
        if ( num <= 0 )
        {
          idStr::Append(this: v13, text: "No phonemes files (.anno) found in ");
          v12 = annoFilePath;
LABEL_22:
          idStr::Append(this: v13, text: v12);
          idLib::Printf(fmt: v13[0].data);
          goto LABEL_23;
        }
        v10 = 0;
        v11 = v7->list.num;
        do
        {
          if ( (unsigned __int8)ConvertPhonemesToAnim(inFile: v9->list.list[v10].data, declVisemeSet: v4) != 0 )
            ++v5;
          else
            ++v6;
          --v11;
          ++v10;
        }
        while ( v11 != 0 );
        if ( v5 != num )
        {
          if ( v6 == num )
          {
            v12 = "Failed!";
          }
          else
          {
            idStr::Append(this: v13, text: "Partial success. ");
            idStr::operator+=(this: v13, a: v5);
            idStr::Append(this: v13, text: " files successful. ");
            idStr::operator+=(this: v13, a: v6);
            v12 = " files failed.";
          }
          goto LABEL_22;
        }
      }
      else if ( (unsigned __int8)ConvertPhonemesToAnim(inFile: annoFilePath, declVisemeSet: v4) == 0 )
      {
        v12 = "Failed!";
        goto LABEL_22;
      }
      v12 = "Success!";
      goto LABEL_22;
    }
  }
  idLib::Warning(fmt: "The viseme set '%s' was not found.", visemeSetName);
  idLib::Printf(fmt: v13[0].data, "Failed!");
LABEL_23:
  idStr::FreeData(this: v13);
}


// ========================================================================
// __unwind$229238
// EA  : 0x82635D34
// RVA : 0x00635D34
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_229238()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?convertPhonemesToAnim_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82635D60
// RVA : 0x00635D60
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __fastcall convertPhonemesToAnim_f(const idCmdArgs *args)
{
  if ( args->argc == 3 )
  {
    Lipsync_ConvertPhonemesToAnim(annoFilePath: args->argv[1], visemeSetName: args->argv[2]);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: convertPhonemesToAnim [.anno folder] [viseme set name]\n");
    idLib::Printf(fmt: "USAGE: convertPhonemesToAnim [.anno file] [viseme set name]\n");
    idLib::Printf(fmt: "  Converts an Annosoft phoneme file to an animation file.\n");
    idLib::Printf(fmt: "  If a folder name is given then all .anno files in the\n");
    idLib::Printf(fmt: "  folder and its children are converted.\n");
  }
}


// ========================================================================
// ?Load@idPhonemeTrack_Annosoft@@UAA_NPBVidDeclVisemeSet@@AAVidLexerUTF8@@@Z
// EA  : 0x82635E60
// RVA : 0x00635E60
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

int __fastcall idPhonemeTrack_Annosoft::Load(
        idPhonemeTrack_Annosoft *this,
        const idDeclVisemeSet *visemeSet,
        idLexerUTF8 *src)
{
  idPhonemeTrack_Annosoft::idPhonemeEvent *list; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idPhonemeTrack_Annosoft::idPhonemeEvent *v9; // r28
  unsigned int numWeights; // r11
  unsigned int v11; // r5
  int v12; // r27
  int v13; // r29
  int v14; // r26
  idPhonemeTrack_Annosoft::idPhonemeEvent *v15; // r29
  size_t len; // r27
  int v18; // [sp+8h] [-148h]
  int v19; // [sp+Ch] [-144h]
  int v20; // [sp+10h] [-140h]
  int v21; // [sp+14h] [-13Ch]
  int v22; // [sp+18h] [-138h]
  int v23; // [sp+1Ch] [-134h]
  idStr v24; // [sp+50h] [-100h] BYREF
  idToken v25[3]; // [sp+70h] [-E0h] BYREF

  v25[0].len = 0;
  v25[0].allocedAndFlag = 20;
  v25[0].floatvalue = -3.4028235e38;
  v25[0].data = v25[0].baseBuffer;
  v25[0].baseBuffer[0] = 0;
  v25[0].intvalue = 0;
  v25[0].whiteSpaceStart_p = nullptr;
  v25[0].whiteSpaceEnd_p = nullptr;
  v25[0].next = nullptr;
  if ( this->phonemes.listStatic == 0 || this->phonemes.listStatic == 2 )
  {
    list = this->phonemes.list;
    if ( list != nullptr )
      idListArrayDelete<idPhonemeTrack_Annosoft::idPhonemeEvent>(ptr: list, num: this->phonemes.size);
    this->phonemes.list = nullptr;
    this->phonemes.size = 0;
  }
  this->phonemes.num = 0;
  LODWORD(v6) = (unsigned __int8)idLexerUTF8::CheckTokenString(this: src, string: "phonemes");
  if ( (_DWORD)v6 != 0 )
  {
    src->flags &= ~0x80000u;
    idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 46, token: v25);
    while ( idLexerUTF8::ReadToken(this: src, token: v25) && (v25[0].type != 5 || v25[0].subtype != 47) )
    {
      if ( idStr::Cmp(s1: v25[0].data, s2: "env") != 0 )
      {
        if ( idStr::Cmp(s1: v25[0].data, s2: "word") == 0 || idStr::Cmp(s1: v25[0].data, s2: "punct") == 0 )
        {
          v14 = ((_cntlzw(idStr::Cmp(s1: v25[0].data, s2: "word")) & 0x20) == 0) + 1;
          idLexerUTF8::ExpectTokenType(this: src, type: 1, subType: 0, token: v25);
          idStr::idStr(this: &v24, text: &v25[0]);
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 46, token: v25);
          idLexerUTF8::ExpectTokenString(this: src, string: "start");
          v15 = idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68>::Alloc(this: &this->phonemes);
          v15->type = -1;
          v15->startMS = idLexerUTF8::ParseInt(this: src);
          idLexerUTF8::ExpectTokenString(this: src, string: "end");
          v15->endMS = idLexerUTF8::ParseInt(this: src);
          len = v24.len;
          idStr::EnsureAlloced(this: &v15->text, amount: v24.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v15->text.data, Src: v24.data, Size: len);
          v15->text.data[len] = 0;
          v15->text.len = len;
          v15->exType = v14;
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 47, token: v25);
          idStr::FreeData(this: &v24);
        }
      }
      else
      {
        idLexerUTF8::ExpectTokenType(this: src, type: 4, subType: 0, token: v25);
        if ( idStr::Cmp(s1: v25[0].data, s2: "x") != 0 )
        {
          v9 = idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68>::Alloc(this: &this->phonemes);
          v9->type = idDeclVisemeSet::PhonemeForName(this: visemeSet, name: v25[0].data);
          v9->exType = EXPHONEME_PHONEME;
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 46, token: v25);
          idLexerUTF8::ExpectTokenString(this: src, string: "start");
          v9->startMS = idLexerUTF8::ParseInt(this: src);
          idLexerUTF8::ExpectTokenString(this: src, string: "end");
          v9->endMS = idLexerUTF8::ParseInt(this: src);
          idLexerUTF8::ExpectTokenString(this: src, string: "weights");
          v9->numWeights = idLexerUTF8::ParseInt(this: src);
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 46, token: v25);
          numWeights = v9->numWeights;
          if ( numWeights > 0x15555555 )
            v11 = -1;
          else
            v11 = 12 * numWeights;
          v12 = 0;
          v9->weights = (idPhonemeTrack_Annosoft::weight_t *)idMem::AllocWithLocation(
                                                               this: &mem,
                                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                               size: v11,
                                                               tag: TAG_NEW,
                                                               zeroBuffer: false,
                                                               align: ALIGN_16,
                                                               heap: HEAP_DEFAULTHEAP);
          while ( v12 < v9->numWeights )
          {
            v13 = v12;
            v9->weights[v12].startMS = idLexerUTF8::ParseInt(this: src);
            v9->weights[v13].endMS = idLexerUTF8::ParseInt(this: src);
            ++v12;
            v9->weights[v13].weight = idLexerUTF8::ParseFloat(this: src);
          }
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 47, token: v25);
          idLexerUTF8::ExpectTokenType(this: src, type: 5, subType: 47, token: v25);
        }
        else
        {
          idLexerUTF8::SkipBracedSection(this: src, parseFirstBrace: true);
        }
      }
    }
  }
  else
  {
    idLexerUTF8::Error(
      this: src,
      str: "Unsupported format",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v18,
      a7: v19,
      a8: v20,
      a9: v21,
      a10: v22,
      a11: v23);
  }
  idStr::FreeData(this: &v25[0]);
  return 1;
}


// ========================================================================
// $M229577
// EA  : 0x826362F4
// RVA : 0x006362F4
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __noreturn _M229577()
{
  int v0; // r12

  idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68>::RemoveIndex(
    this: (idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68> *)(*(_DWORD *)(v0 - 336 + 356) + 4),
    index: *(_DWORD *)(*(_DWORD *)(v0 - 336 + 356) + 8) - 1);
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $M229580
// EA  : 0x8263632C
// RVA : 0x0063632C
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __noreturn _M229580()
{
  int v0; // r12

  idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68>::RemoveIndex(
    this: (idList<idPhonemeTrack_Annosoft::idPhonemeEvent,68> *)(*(_DWORD *)(v0 - 336 + 356) + 4),
    index: *(_DWORD *)(*(_DWORD *)(v0 - 336 + 356) + 8) - 1);
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $LN147
// EA  : 0x8263635C
// RVA : 0x0063635C
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _LN147()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$229406
// EA  : 0x82636384
// RVA : 0x00636384
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void _unwind_229406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// `dynamic initializer for 'vo_genSimpleVisemes''
// EA  : 0x83337380
// RVA : 0x01337380
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vo_genSimpleVisemes__()
{
  idCVar::idCVar(
    this: &vo_genSimpleVisemes,
    name: "vo_genSimpleVisemes",
    value: "1",
    flags: 1,
    description: "1 = use simple, one peak visemes, 0 = use visemes that store a weight per-frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vo_genSimpleVisemes__);
}


// ========================================================================
// `dynamic initializer for 'vo_mergeVisemes''
// EA  : 0x833373D8
// RVA : 0x013373D8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vo_mergeVisemes__()
{
  idCVar::idCVar(
    this: &vo_mergeVisemes,
    name: "vo_mergeVisemes",
    value: "1",
    flags: 1,
    description: "1 = merge overlapping visemes of the same type",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vo_mergeVisemes__);
}


// ========================================================================
// `dynamic initializer for 'vo_lipsyncToolPath''
// EA  : 0x83337430
// RVA : 0x01337430
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vo_lipsyncToolPath__()
{
  idCVar::idCVar(
    this: &vo_lipsyncToolPath,
    name: "vo_lipsyncToolPath",
    value: "cmdlinesync.exe",
    flags: 0,
    description: "locatoin of tje lip sync command line tool",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vo_lipsyncToolPath__);
}


// ========================================================================
// `dynamic initializer for 'convertPhonemes_v''
// EA  : 0x83337488
// RVA : 0x01337488
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertPhonemes_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertPhonemes_v,
           cmdName: "convertPhonemes",
           function: convertPhonemes_f,
           description: "converts a phonemes file (.anno) to a voice track",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'convertPhonemesToAnim_v''
// EA  : 0x833374B0
// RVA : 0x013374B0
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertPhonemesToAnim_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertPhonemesToAnim_v,
           cmdName: "convertPhonemesToAnim",
           function: convertPhonemesToAnim_f,
           description: "converts a phonemes file (.anno) to an animation (.md6anim)",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'regenVoicetracks_v''
// EA  : 0x833374D8
// RVA : 0x013374D8
// PDB : w:\tech5\engine\decls\voiceovers\lipsync_annosoft.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__regenVoicetracks_v__()
{
  return idCommandLink::idCommandLink(
           this: &regenVoicetracks_v,
           cmdName: "regenVoicetracks",
           function: regenVoicetracks_f,
           description: "Loads and regenerates visemes for existing voicetrack in a path.",
           argCompletion: nullptr);
}

