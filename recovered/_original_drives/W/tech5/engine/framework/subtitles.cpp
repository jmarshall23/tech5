
// ========================================================================
// ?GetLanguageIsoName@idSubtitles@@SAPBDH@Z
// EA  : 0x826A6A18
// RVA : 0x006A6A18
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

const char *__fastcall idSubtitles::GetLanguageIsoName(unsigned int language)
{
  if ( language > 9 )
    return idSubtitles::languagesIsoNames[0];
  else
    return idSubtitles::languagesIsoNames[language];
}


// ========================================================================
// ?Update@idSubtitleSequencer@@QAAPBDMI@Z
// EA  : 0x826A6AB0
// RVA : 0x006A6AB0
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

char *__fastcall idSubtitleSequencer::Update(
        idSubtitleSequencer *this,
        double newTime,
        unsigned int languageMask,
        int a4,
        __int64 a5)
{
  int current; // r11
  int num; // r8
  int v7; // r11
  idSubtitles::idPart *v8; // r11

  current = this->current;
  num = this->parts.num;
  if ( current + 1 < num )
  {
    LODWORD(a5) = (int)this->parts.list[current + 1].startTime;
    if ( newTime >= (float)a5 )
      this->current = current + 1;
  }
  v7 = this->current;
  if ( v7 < num && (v8 = &this->parts.list[v7], ((1 << v8->language) & a4) != 0) && newTime > v8->startTime )
    return v8->phrase.data;
  else
    return nullptr;
}


// ========================================================================
// ?End@idSubtitles_VideoOverlay@@UAAXXZ
// EA  : 0x826A6B58
// RVA : 0x006A6B58
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void __fastcall idSubtitles_VideoOverlay::End(idSubtitles_VideoOverlay *this)
{
  idSWF *swf; // r29

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  swf = this->swf;
  if ( swf != nullptr )
  {
    idSWF::~idSWF(this: this->swf);
    idMem::Free(this: &mem, ptr: swf, align: ALIGN_16);
  }
  this->swf = nullptr;
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$219828
// EA  : 0x826A6BBC
// RVA : 0x006A6BBC
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_219828()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 80));
}


// ========================================================================
// ?ProcessText@idSubtitles@@SA_NPBDMPAV?$idList@VidPart@idSubtitles@@$04@@@Z
// EA  : 0x826A6EC8
// RVA : 0x006A6EC8
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

int __fastcall idSubtitles::ProcessText(const char *text, double endTime, idList<idSubtitles::idPart,5> *parts, int a4)
{
  int v7; // r11
  int v8; // r29
  const char *i; // r10
  int v10; // r4
  int v11; // r11
  unsigned int allocedAndFlag; // r10
  char v13; // r23
  const char *v14; // r27
  int v15; // r30
  const char *v16; // r29
  int v17; // r11
  signed int v18; // r30
  int v19; // r11
  unsigned int v20; // ctr
  long double v21; // fp2
  const char **v22; // r30
  unsigned int v23; // r29
  const char *v24; // r4
  int v25; // r10
  int v26; // r11
  bool v27; // zf
  idSubtitles::idPart v29; // [sp+50h] [-300h] BYREF
  idSubtitles::idPart v30; // [sp+80h] [-2D0h] BYREF
  int v31; // [sp+ACh] [-2A4h]
  idStr v32; // [sp+B0h] [-2A0h] BYREF
  char v33; // [sp+D0h] [-280h] BYREF

  v7 = *text;
  v8 = 2;
  for ( i = text; *i != 0; v7 = *i )
  {
    if ( v7 == 91 )
      ++v8;
    ++i;
  }
  v10 = *(_DWORD *)(a4 + 8);
  if ( v10 < 0 )
  {
    if ( *(_BYTE *)(a4 + 15) == 0 || *(_BYTE *)(a4 + 15) == 2 )
    {
      if ( *(_DWORD *)a4 != 0 )
        idListArrayDelete<idPcDisplayInfo>(ptr: *(char **)a4, num: v10);
      *(_DWORD *)a4 = 0;
      *(_DWORD *)(a4 + 8) = 0;
    }
    *(_DWORD *)(a4 + 4) = 0;
  }
  v31 = *(_DWORD *)(a4 + 8);
  v11 = v31;
  *(_DWORD *)(a4 + 4) = __CFADD__(-v31, v31 ^ 0x80000000) ? 0 : v31;
  if ( v8 > v11 )
    idList<idSubtitles::idPart,5>::Resize(this: (idList<idSubtitles::idPart,5> *)a4, newsize: v8);
  v29.flags = 0;
  v29.phrase.len = 0;
  v29.language = 0;
  allocedAndFlag = 20;
  v29.phrase.baseBuffer[0] = 0;
  v29.phrase.data = v29.phrase.baseBuffer;
  v29.startTime = 0.0;
  v29.phrase.allocedAndFlag = 20;
  v13 = 0;
  v14 = text;
  if ( *text != 0 )
  {
    while ( 1 )
    {
      v15 = *(unsigned __int8 *)v14;
      if ( v15 == 91 )
      {
        v16 = ++v14;
        while ( 1 )
        {
          v17 = *v14;
          if ( *v14 == 0 )
          {
            idStr::FreeData(this: &v29.phrase);
            return 0;
          }
          if ( v17 == 32 || v17 == 93 )
            break;
          ++v14;
        }
        v32.baseBuffer[0] = 0;
        v33 = 0;
        v32.data = &v33;
        v32.len = 0;
        v32.allocedAndFlag = -2147483136;
        v18 = (((unsigned int)(v14 - v16) >> 31) - 1) & (v14 - v16);
        if ( v18 + 1 > 512
          && AssertFailed(
               file: "w:\\tech5\\shared\\idlib\\text/Str.h",
               line: 463,
               expression: "amount <= GetAlloced()",
               inlineBreak: true) )
        {
          __trap();
        }
        v19 = 0;
        if ( v18 > 0 )
        {
          v20 = (((unsigned int)(v14 - v16) >> 31) - 1) & (v14 - v16);
          do
          {
            v32.data[v19] = v16[v19];
            ++v19;
            --v20;
          }
          while ( v20 != 0 );
        }
        v32.data[v18] = 0;
        v32.len = (((unsigned int)(v14 - v16) >> 31) - 1) & (v14 - v16);
        if ( idStr::IsNumeric(s: v32.data) )
        {
          if ( v13 != 0 || v29.phrase.len != 0 )
          {
            idList<idSubtitles::idPart,5>::Append(this: (idList<idSubtitles::idPart,5> *)a4, obj: &v29);
            idStr::operator=(this: &v29.phrase, text: &byte_8200D768);
          }
          v21 = atof(nptr: v32.data);
          v29.startTime = *(double *)&v21;
          v13 = 1;
        }
        else
        {
          v22 = idSubtitles::languagesIsoNames;
          v23 = 0;
          while ( 1 )
          {
            v24 = v23 > 9 ? idSubtitles::languagesIsoNames[0] : *v22;
            if ( idStr::Cmp(s1: v32.data, s2: v24) == 0 )
              break;
            ++v22;
            ++v23;
            if ( (int)v22 >= (int)&timeManager )
              goto LABEL_45;
          }
          if ( v29.language != v23 )
          {
            if ( v29.phrase.len != 0 )
            {
              idList<idSubtitles::idPart,5>::Append(this: (idList<idSubtitles::idPart,5> *)a4, obj: &v29);
              idStr::operator=(this: &v29.phrase, text: &byte_8200D768);
              v13 = 0;
            }
            v29.language = v23;
          }
        }
LABEL_45:
        idStr::FreeData(this: &v32);
      }
      else
      {
        v26 = v29.phrase.len + 2;
        v27 = allocedAndFlag >> 31 == 0;
        v25 = allocedAndFlag & 0x7FFFFFFF;
        if ( v27 )
        {
          if ( v26 > v25 )
            idStr::ReAllocate(this: &v29.phrase, amount: (v26 >> 1) + v26, keepold: true);
        }
        else if ( v26 > v25
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        v29.phrase.data[v29.phrase.len++] = v15;
        v29.phrase.data[v29.phrase.len] = 0;
      }
      if ( *++v14 == 0 )
        break;
      allocedAndFlag = v29.phrase.allocedAndFlag;
    }
  }
  if ( v13 != 0 || v29.phrase.len != 0 )
  {
    idList<idSubtitles::idPart,5>::Append(this: (idList<idSubtitles::idPart,5> *)a4, obj: &v29);
    if ( v29.phrase.len != 0 )
    {
      v30.flags = 0;
      v30.language = 0;
      v30.phrase.data = v30.phrase.baseBuffer;
      v30.phrase.len = 0;
      v30.phrase.baseBuffer[0] = 0;
      v30.phrase.allocedAndFlag = 20;
      if ( endTime <= 0.0 )
        v30.startTime = v29.startTime + (float)2.0;
      else
        v30.startTime = endTime;
      idList<idSubtitles::idPart,5>::Append(this: (idList<idSubtitles::idPart,5> *)a4, obj: &v30);
      idStr::FreeData(this: &v30.phrase);
    }
  }
  idStr::FreeData(this: &v29.phrase);
  return 1;
}


// ========================================================================
// __unwind$220425
// EA  : 0x826A730C
// RVA : 0x006A730C
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_220425()
{
  int v0; // r12

  idSubtitles::idPart::~idPart(this: (idSubtitles::idPart *)(v0 - 848 + 80));
}


// ========================================================================
// __unwind$220426
// EA  : 0x826A7334
// RVA : 0x006A7334
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_220426()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 176));
}


// ========================================================================
// __unwind$220427
// EA  : 0x826A735C
// RVA : 0x006A735C
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_220427()
{
  int v0; // r12

  idSubtitles::idPart::~idPart(this: (idSubtitles::idPart *)(v0 - 848 + 128));
}


// ========================================================================
// ??0idDedicatedServerSearch@@QAA@XZ
// EA  : 0x826A7388
// RVA : 0x006A7388
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

idSubtitleSequencer *__fastcall idDedicatedServerSearch::idDedicatedServerSearch(idSubtitleSequencer *this)
{
  this->parts.granularity = 0;
  this->parts.memTag = 5;
  this->parts.listStatic = 0;
  this->parts.list = nullptr;
  this->parts.size = 0;
  this->parts.num = 0;
  this->current = 0;
  return this;
}


// ========================================================================
// ?Start@idSubtitleSequencer@@QAAXPBDM@Z
// EA  : 0x826A73B0
// RVA : 0x006A73B0
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void __fastcall idSubtitleSequencer::Start(idSubtitleSequencer *this, char *text, double endTime)
{
  this->current = 0;
  idSubtitles::ProcessText(text, endTime, parts: (idList<idSubtitles::idPart,5> *)text, a4: (int)this);
}


// ========================================================================
// ??1idSubtitles_VideoOverlay@@UAA@XZ
// EA  : 0x826A73D0
// RVA : 0x006A73D0
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void __fastcall idSubtitles_VideoOverlay::~idSubtitles_VideoOverlay(idSubtitles_VideoOverlay *this)
{
  idSWF *swf; // r28
  char *list; // r3

  this->__vftable = (idSubtitles_VideoOverlay_vtbl *)&idSubtitles_VideoOverlay::`vftable';
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  swf = this->swf;
  if ( swf != nullptr )
  {
    idSWF::~idSWF(this: this->swf);
    idMem::Free(this: &mem, ptr: swf, align: ALIGN_16);
  }
  this->swf = nullptr;
  idMem::PopHeap(this: &mem);
  if ( this->sequencer.parts.listStatic == 0 || this->sequencer.parts.listStatic == 2 )
  {
    list = (char *)this->sequencer.parts.list;
    if ( list != nullptr )
      idListArrayDelete<idPcDisplayInfo>(ptr: list, num: this->sequencer.parts.size);
    this->sequencer.parts.list = nullptr;
    this->sequencer.parts.size = 0;
  }
  this->sequencer.parts.num = 0;
  this->__vftable = (idSubtitles_VideoOverlay_vtbl *)&idRenderVideoOverlay::`vftable';
}


// ========================================================================
// __unwind$221058
// EA  : 0x826A7484
// RVA : 0x006A7484
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221058()
{
  int v0; // r12

  idRenderVideoOverlay::~idRenderVideoOverlay(this: *(idRenderVideoOverlay **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221059
// EA  : 0x826A74AC
// RVA : 0x006A74AC
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221059()
{
  int v0; // r12

  idList<idSubtitles::idPart,5>::Clear(this: (idSubtitleSequencer *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}


// ========================================================================
// __unwind$221060
// EA  : 0x826A74D8
// RVA : 0x006A74D8
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221060()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 80));
}


// ========================================================================
// ?Start@idSubtitles_VideoOverlay@@UAAXPBDM@Z
// EA  : 0x826A7508
// RVA : 0x006A7508
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void __fastcall idSubtitles_VideoOverlay::Start(idSubtitles_VideoOverlay *this, const char *videoName, double length)
{
  idPlayerProfile *v6; // r3
  idSWF *v7; // r3
  idSWF *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  va *v12; // r3
  const char *LocalizedString; // r3
  idList<idSubtitles::idPart,5> *v14; // r4
  int v15; // [sp+8h] [-14D8h]
  int v16; // [sp+Ch] [-14D4h]
  int v17; // [sp+10h] [-14D0h]
  int v18; // [sp+14h] [-14CCh]
  int v19; // [sp+18h] [-14C8h]
  int v20; // [sp+1Ch] [-14C4h]
  idStrId v21[4]; // [sp+50h] [-1490h] BYREF
  idStr v22; // [sp+60h] [-1480h] BYREF
  char v23; // [sp+80h] [-1460h] BYREF
  idStrStatic<512> v24; // [sp+280h] [-1260h] BYREF
  va v25; // [sp+4A0h] [-1040h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v6 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v6 != nullptr )
    this->languageMask = v6->GetSubtitleLanguageMask(this: v6);
  v7 = (idSWF *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x27Cu,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v21[1].index = (int)v7;
  if ( v7 != nullptr )
    v8 = idSWF::idSWF(this: v7, filename_: "vo", soundWorld: nullptr, atlasPurgable_: false);
  else
    v8 = nullptr;
  this->swf = v8;
  idSWF::LoadAtlasImage(this: v8, force: true);
  idSWF::Activate(this: this->swf, b: true);
  idStrStatic<512>::idStrStatic<512>(this: &v24, text: videoName);
  v22.baseBuffer[0] = 0;
  v23 = 0;
  v22.data = &v23;
  v22.len = 0;
  v22.allocedAndFlag = -2147483136;
  idStr::ExtractFileBase(this: &v24, dest: &v22);
  LODWORD(v9) = "_AI_OBSTACLE";
  HIDWORD(v10) = v22.data;
  v12 = va::va(
          this: &v25,
          fmt: "#str_video_%s",
          a3: v10,
          a4: v9,
          a5: v11,
          a6: v15,
          a7: v16,
          a8: v17,
          a9: v18,
          a10: v19,
          a11: v20);
  idStrId::Set(this: v21, key: v12->buffer);
  LocalizedString = idStrId::GetLocalizedString(this: v21);
  this->sequencer.current = 0;
  idSubtitles::ProcessText(text: LocalizedString, endTime: length, parts: v14, a4: (int)&this->sequencer);
  idStr::FreeData(this: &v22);
  idStr::FreeData(this: &v24);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$221136
// EA  : 0x826A7670
// RVA : 0x006A7670
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221136()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 5344 + 5280));
}


// ========================================================================
// __unwind$221137
// EA  : 0x826A7698
// RVA : 0x006A7698
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221137()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 5344 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$221138
// EA  : 0x826A76C4
// RVA : 0x006A76C4
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221138()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5344 + 640));
}


// ========================================================================
// __unwind$221139
// EA  : 0x826A76EC
// RVA : 0x006A76EC
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221139()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5344 + 96));
}


// ========================================================================
// ??0idSubtitles_VideoOverlay@@QAA@XZ
// EA  : 0x826A7720
// RVA : 0x006A7720
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

idSubtitles_VideoOverlay *__fastcall idSubtitles_VideoOverlay::idSubtitles_VideoOverlay(idSubtitles_VideoOverlay *this)
{
  this->__vftable = (idSubtitles_VideoOverlay_vtbl *)&idSubtitles_VideoOverlay::`vftable';
  this->sequencer.parts.granularity = 0;
  this->sequencer.parts.memTag = 5;
  this->sequencer.parts.listStatic = 0;
  this->sequencer.parts.list = nullptr;
  this->sequencer.parts.size = 0;
  this->sequencer.parts.num = 0;
  this->sequencer.current = 0;
  this->swf = nullptr;
  this->languageMask = -1;
  return this;
}


// ========================================================================
// __unwind$221283
// EA  : 0x826A777C
// RVA : 0x006A777C
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221283()
{
  int v0; // r12

  idRenderVideoOverlay::~idRenderVideoOverlay(this: *(idRenderVideoOverlay **)(v0 - 32 + 52));
}


// ========================================================================
// ?Render@idSubtitles_VideoOverlay@@UAAXPAVidRenderModelGui@@M@Z
// EA  : 0x826A7810
// RVA : 0x006A7810
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void __fastcall idSubtitles_VideoOverlay::Render(
        idSubtitles_VideoOverlay *this,
        idRenderModelGui *guiModel,
        double videoTime)
{
  __int64 v6; // r8
  unsigned int v7; // r4
  char *v8; // r27
  idStaticList<idSWFScriptVar,16> v9; // [sp+50h] [-D0h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v8 = idSubtitleSequencer::Update(
         this: &this->sequencer,
         newTime: videoTime,
         languageMask: v7,
         a4: this->languageMask,
         a5: v6);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v9);
  idSWFParmList::Append(this: (idSWFParmList *)&v9, s: v8);
  idSWF::Invoke(this: this->swf, functionName: "setSubtitle", parms: (const idSWFParmList *)&v9);
  idSWF::Render(this: this->swf, gui: guiModel, time: 0, isSplitscreen: false);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v9);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$221415
// EA  : 0x826A78B0
// RVA : 0x006A78B0
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221415()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 288 + 224));
}


// ========================================================================
// __unwind$221416
// EA  : 0x826A78D8
// RVA : 0x006A78D8
// PDB : w:\tech5\engine\framework\subtitles.cpp
// ========================================================================

void _unwind_221416()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 80));
}

