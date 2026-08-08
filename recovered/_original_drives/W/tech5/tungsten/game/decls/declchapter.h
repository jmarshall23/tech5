
// ========================================================================
// ??$ContainsAll@V?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@V?$idList@VidAtomicString@@$04@@@idDeclChapter@@SA_NABV?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@ABV?$idList@VidAtomicString@@$04@@@Z
// EA  : 0x82BBCD48
// RVA : 0x00BBCD48
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

int __fastcall idDeclChapter::ContainsAll<idStaticList<idStrStatic<128>,256>,idList<idAtomicString,5>>(
        const idStaticList<idStrStatic<128>,256> *haystack,
        const idList<idAtomicString,5> *needles)
{
  int v4; // r26
  char v5; // r25
  int v6; // r28
  int v7; // r31

  v4 = 0;
  if ( needles->num <= 0 )
    return 1;
  while ( 1 )
  {
    v5 = 0;
    v6 = 0;
    if ( haystack->num > 0 )
    {
      v7 = 0;
      while ( idStr::Cmp(s1: haystack->list[v7].data, s2: needles->list[v4].str) != 0 )
      {
        ++v6;
        ++v7;
        if ( v6 >= haystack->num )
          goto LABEL_8;
      }
      v5 = 1;
    }
LABEL_8:
    if ( v5 == 0 )
      return 0;
    if ( ++v4 >= needles->num )
      return 1;
  }
}


// ========================================================================
// ?GetDeclInfo@idDeclSecretType@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC9A0
// RVA : 0x00BCC9A0
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

idDeclInfoTemplate<idDeclSecretType> *__fastcall idDeclSecretType::GetDeclInfo(idDeclSecretType *this)
{
  return &idDeclSecretType::resourceList;
}


// ========================================================================
// ??0idDeclSecrets@@QAA@XZ
// EA  : 0x82BD3100
// RVA : 0x00BD3100
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

idDeclSecrets *__fastcall idDeclSecrets::idDeclSecrets(idDeclSecrets *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclSecrets_vtbl *)&idDeclSecrets::`vftable';
  this->id = -1;
  this->map.str = &byte_8200D768;
  this->layers.list = nullptr;
  this->layers.granularity = 0;
  this->layers.memTag = 5;
  this->layers.listStatic = 0;
  this->layers.size = 0;
  this->layers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layers);
  this->secrets.list = nullptr;
  this->secrets.granularity = 0;
  this->secrets.memTag = 5;
  this->secrets.listStatic = 0;
  this->secrets.size = 0;
  this->secrets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secrets);
  return this;
}


// ========================================================================
// __unwind$501274
// EA  : 0x82BD3198
// RVA : 0x00BD3198
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_501274()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$501275
// EA  : 0x82BD31C0
// RVA : 0x00BD31C0
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_501275()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// ?GetDeclInfo@idDeclSecrets@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD31F0
// RVA : 0x00BD31F0
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

idDeclInfoTemplate<idDeclSecrets> *__fastcall idDeclSecrets::GetDeclInfo(idDeclSecrets *this)
{
  return &idDeclSecrets::resourceList;
}


// ========================================================================
// ??1idDeclSecrets@@UAA@XZ
// EA  : 0x82BD3208
// RVA : 0x00BD3208
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void __fastcall idDeclSecrets::~idDeclSecrets(idDeclSecrets *this)
{
  this->__vftable = (idDeclSecrets_vtbl *)&idDeclSecrets::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secrets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layers);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$501312
// EA  : 0x82BD3264
// RVA : 0x00BD3264
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_501312()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501313
// EA  : 0x82BD328C
// RVA : 0x00BD328C
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_501313()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ??0idDeclChapter@@QAA@XZ
// EA  : 0x82BD78B0
// RVA : 0x00BD78B0
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

idDeclChapter *__fastcall idDeclChapter::idDeclChapter(idDeclChapter *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->sortId = 0;
  this->__vftable = (idDeclChapter_vtbl *)&idDeclChapter::`vftable';
  this->displayName.index = -1;
  this->lockedName.index = -1;
  this->type = CHAPTERTYPE_CAMPAIGN;
  this->offset = vec2_origin;
  this->sideMap.allocedAndFlag = 20;
  this->sideMap.data = this->sideMap.baseBuffer;
  this->sideMap.len = 0;
  this->sideMap.baseBuffer[0] = 0;
  this->variations.granularity = 0;
  this->variations.listStatic = 0;
  this->variations.memTag = 5;
  this->variations.list = nullptr;
  this->variations.size = 0;
  this->variations.num = 0;
  return this;
}


// ========================================================================
// __unwind$505424
// EA  : 0x82BD796C
// RVA : 0x00BD796C
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_505424()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505425
// EA  : 0x82BD7994
// RVA : 0x00BD7994
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_505425()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ?GetDeclInfo@idDeclChapter@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD79C0
// RVA : 0x00BD79C0
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

idDeclInfoTemplate<idDeclChapter> *__fastcall idDeclChapter::GetDeclInfo(idDeclChapter *this)
{
  return &idDeclChapter::resourceList;
}


// ========================================================================
// ??1idDeclChapter@@UAA@XZ
// EA  : 0x82BD79D8
// RVA : 0x00BD79D8
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void __fastcall idDeclChapter::~idDeclChapter(idDeclChapter *this)
{
  char *list; // r3

  this->__vftable = (idDeclChapter_vtbl *)&idDeclChapter::`vftable';
  if ( this->variations.listStatic == 0 || this->variations.listStatic == 2 )
  {
    list = (char *)this->variations.list;
    if ( list != nullptr )
      idListArrayDelete<idChapterVariation>(ptr: list, num: this->variations.size);
    this->variations.list = nullptr;
    this->variations.size = 0;
  }
  this->variations.num = 0;
  idStr::FreeData(this: &this->sideMap);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$505492
// EA  : 0x82BD7A4C
// RVA : 0x00BD7A4C
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_505492()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505493
// EA  : 0x82BD7A74
// RVA : 0x00BD7A74
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

void _unwind_505493()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ??$ContainsAll@V?$idList@VidAtomicString@@$04@@V1@@idDeclChapter@@SA_NABV?$idList@VidAtomicString@@$04@@0@Z
// EA  : 0x82DA2688
// RVA : 0x00DA2688
// PDB : w:\tech5\tungsten\game\decls\declchapter.h
// ========================================================================

int __fastcall idDeclChapter::ContainsAll<idList<idAtomicString,5>,idList<idAtomicString,5>>(
        const idList<idAtomicString,5> *haystack,
        const idList<idAtomicString,5> *needles)
{
  int num; // r30
  int v3; // r31
  int v4; // r6
  int i; // r7
  char v6; // r5
  int v7; // r10
  int v8; // r11

  num = needles->num;
  v3 = 0;
  if ( num <= 0 )
    return 1;
  v4 = haystack->num;
  for ( i = 0; ; ++i )
  {
    v6 = 0;
    v7 = 0;
    if ( v4 > 0 )
    {
      v8 = 0;
      while ( haystack->list[v8].str != needles->list[i].str )
      {
        ++v7;
        ++v8;
        if ( v7 >= v4 )
          goto LABEL_9;
      }
      v6 = 1;
    }
LABEL_9:
    if ( v6 == 0 )
      break;
    if ( ++v3 >= num )
      return 1;
  }
  return 0;
}

