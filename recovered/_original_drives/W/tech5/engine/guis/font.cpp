
// ========================================================================
// ?GetMaterial@idFont@@QBAPBVidMaterial@@XZ
// EA  : 0x8276C9B8
// RVA : 0x0076C9B8
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

const idMaterial *__fastcall idFont::GetMaterial(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->material;
  else
    return nullptr;
}


// ========================================================================
// ?GetMaterialWidth@idFont@@QBAIXZ
// EA  : 0x8276C9F0
// RVA : 0x0076C9F0
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

unsigned int __fastcall idFont::GetMaterialWidth(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->imageWidth;
  else
    return 1;
}


// ========================================================================
// ?GetMaterialHeight@idFont@@QBAIXZ
// EA  : 0x8276CA30
// RVA : 0x0076CA30
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

unsigned int __fastcall idFont::GetMaterialHeight(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->imageHeight;
  else
    return 1;
}


// ========================================================================
// ?GetPointSize@idFont@@QBAIXZ
// EA  : 0x8276CA70
// RVA : 0x0076CA70
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

unsigned int __fastcall idFont::GetPointSize(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->pointSize;
  else
    return 0;
}


// ========================================================================
// ?GetAscender@idFont@@QBAHXZ
// EA  : 0x8276CAB0
// RVA : 0x0076CAB0
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

int __fastcall idFont::GetAscender(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->ascender;
  else
    return 0;
}


// ========================================================================
// ?GetDescender@idFont@@QBAHXZ
// EA  : 0x8276CAF0
// RVA : 0x0076CAF0
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

int __fastcall idFont::GetDescender(idFont *this)
{
  idFont *i; // r11
  fontInfo_t *fontInfo; // r11

  for ( i = this->alias; i != nullptr; i = i->alias )
    this = i;
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
    return fontInfo->descender;
  else
    return 0;
}


// ========================================================================
// ?TestFont_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8276CBD0
// RVA : 0x0076CBD0
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void __fastcall TestFont_f(const idCmdArgs *args)
{
  const idFont *v2; // r29
  const char *v3; // r3
  long double v4; // fp2
  double v5; // fp30
  char *v6; // r21
  idRenderModelGui *v7; // r27
  __int64 v8; // r26
  __int64 v9; // r3
  unsigned __int64 v10; // r6
  int v11; // r28
  double v12; // fp23
  __int64 v13; // r11
  int v14; // r6
  const char *v15; // r5
  const idVec4 *v16; // r4
  double v17; // fp31
  int i; // r31
  double v19; // fp20
  idRenderSystem_vtbl *v20; // r31
  void *v21; // r3
  idRenderModelGui *v22; // [sp+78h] [-5D8h] BYREF
  idDeviceContext v23; // [sp+80h] [-5D0h] BYREF

  if ( args->argc == 4 )
  {
    v2 = (const idFont *)idResourceList::Load(
                           this: &idFont::resourceList,
                           name: args->argv[1],
                           makeDefault: false,
                           skipStaleCheck: false);
    if ( v2 != nullptr )
    {
      if ( args->argc <= 2 )
        v3 = &byte_8200D768;
      else
        v3 = args->argv[2];
      v4 = atof(nptr: v3);
      v5 = (float)*(double *)&v4;
      if ( v5 > 0.0 )
      {
        if ( args->argc <= 3 )
          v6 = &byte_8200D768;
        else
          v6 = args->argv[3];
        v7 = console->Gui(this: console);
        v22 = v7;
        idDeviceContext::idDeviceContext(this: &v23, guiModel: v7);
        LODWORD(v8) = renderSystem->GetWidth(this: renderSystem);
        HIDWORD(v8) = renderSystem->GetHeight(this: renderSystem);
        idDeviceContext::SetFont(this: &v23, font: v2);
        LODWORD(v9) = HIDWORD(v8);
        LODWORD(v10) = &off_82010000;
        v11 = 60;
        v12 = (float)v9;
        do
        {
          idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v10);
          idRenderModelGui::DrawFilled(
            this: v7,
            color: (const idVec4 *)&idColor::colorDkGrey,
            x: 0.0,
            y: 0.0,
            w: (float)v8,
            h: v12);
          if ( v5 > 2.0 )
          {
            idDeviceContext::DrawTextA(
              this: &v23,
              x: 10.0,
              y: 500.0,
              scale: v5,
              color: v16,
              text: v15,
              a7: v14,
              a8: (const idVec4 *)&idColor::colorWhite,
              a9: (const unsigned __int8 *)v6);
          }
          else
          {
            v17 = 800.0;
            for ( i = 0; i < 20; ++i )
            {
              LODWORD(v13) = i;
              v19 = (float)((float)((float)v13 * (float)0.02) + (float)v5);
              idDeviceContext::DrawTextA(
                this: &v23,
                x: 10.0,
                y: v17,
                scale: v19,
                color: v16,
                text: v15,
                a7: v14,
                a8: (const idVec4 *)&idColor::colorWhite,
                a9: (const unsigned __int8 *)v6);
              v17 = (float)-(float)((float)((float)v19 * (float)50.0) - (float)v17);
            }
          }
          v20 = renderSystem->__vftable;
          v21 = renderSystem->GetGameWindow(this: renderSystem);
          ((void (__fastcall *)(idRenderSystem *, void *, _DWORD, _DWORD, _DWORD, idRenderModelGui **, int, int))v20->EndFrame)(
            a1: renderSystem,
            a2: v21,
            a3: v8,
            a4: HIDWORD(v8),
            a5: 0,
            a6: &v22,
            a7: 1,
            a8: 1);
          --v11;
        }
        while ( v11 != 0 );
        mgthread_sleep(ms: 10000);
      }
    }
    else if ( args->argc <= 1 )
    {
      idLib::Printf(fmt: "Font '%s' not found\n", &byte_8200D768);
    }
    else
    {
      idLib::Printf(fmt: "Font '%s' not found\n", args->argv[1]);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: testFont <fontName> <fontSize> <text>\n");
  }
}


// ========================================================================
// ?RemapFont@idFont@@CAPAV1@PBD@Z
// EA  : 0x8276D110
// RVA : 0x0076D110
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

idFont *__fastcall idFont::RemapFont(const char *baseName)
{
  bool v1; // r30
  idResource *v2; // r30
  idStr *v4; // r3
  char *String; // r30
  idResource *v6; // r30
  const char *v7; // r3
  idStr v8; // [sp+50h] [-60h] BYREF
  idStr v9; // [sp+70h] [-40h] BYREF

  idStr::idStr(this: &v8, text: baseName);
  v1 = idStr::ReplaceChar(this: &v8, oldChar: 45, newChar: 95);
  if ( idStr::ReplaceChar(this: &v8, oldChar: 32, newChar: 95) || v1 )
  {
    v2 = idResourceList::Load(this: &idFont::resourceList, name: v8.data, makeDefault: true, skipStaleCheck: false);
    idStr::FreeData(this: &v8);
    return (idFont *)v2;
  }
  else if ( idStr::Cmp(s1: v8.data, s2: idFont::DEFAULT_FONT) != 0
         && ((v4 = operator+(result: &v9, a: "#font_", b: &v8),
              String = (char *)idLocalization::FindString(inString: v4->data),
              idStr::FreeData(this: &v9),
              String != nullptr)
          || (v7 = idLocalization::FindString(inString: "#font_*"), String = (char *)v7, v7 != nullptr)
          && idStr::Icmp(s1: v8.data, s2: v7) != 0) )
  {
    v6 = idResourceList::Load(this: &idFont::resourceList, name: String, makeDefault: true, skipStaleCheck: false);
    idStr::FreeData(this: &v8);
    return (idFont *)v6;
  }
  else
  {
    idStr::FreeData(this: &v8);
    return nullptr;
  }
}


// ========================================================================
// __unwind$220974
// EA  : 0x8276D290
// RVA : 0x0076D290
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_220974()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$220975
// EA  : 0x8276D2B8
// RVA : 0x0076D2B8
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_220975()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?ReloadIfStale@idFont@@UAA_NXZ
// EA  : 0x8276D2E8
// RVA : 0x0076D2E8
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

int __fastcall idFont::ReloadIfStale(idFont *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  int v7; // [sp+8h] [-1088h]
  int v8; // [sp+Ch] [-1084h]
  int v9; // [sp+10h] [-1080h]
  int v10; // [sp+14h] [-107Ch]
  int v11; // [sp+18h] [-1078h]
  int v12; // [sp+1Ch] [-1074h]
  idStr v13; // [sp+50h] [-1040h] BYREF
  va v14; // [sp+70h] [-1020h] BYREF

  if ( this->alias == idFont::RemapFont(baseName: this->name.str) )
  {
    HIDWORD(v4) = this->name.str;
    v5 = va::va(
           this: &v14,
           fmt: "fonts/%s/48.dat",
           a3: v4,
           a4: v3,
           a5: v2,
           a6: v7,
           a7: v8,
           a8: v9,
           a9: v10,
           a10: v11,
           a11: v12);
    idStr::idStr(this: &v13, text: v5);
    if ( this->timestamp != -1 && this->timestamp == fileSystem->GetTimestamp(this: fileSystem, a2: v13.data, a3: false) )
    {
      idStr::FreeData(this: &v13);
      return 0;
    }
    this->LoadResource(this);
    idStr::FreeData(this: &v13);
  }
  else
  {
    this->LoadResource(this);
  }
  return 1;
}


// ========================================================================
// __unwind$221061
// EA  : 0x8276D3D4
// RVA : 0x0076D3D4
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_221061()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4240 + 80));
}


// ========================================================================
// ?LoadResource@idFont@@UAAXXZ
// EA  : 0x8276D408
// RVA : 0x0076D408
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void __fastcall idFont::LoadResource(idFont *this)
{
  fontInfo_t *fontInfo; // r29
  const char *str; // r3
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idFont *v7; // r3
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idFile *v12; // r3
  idFile *v13; // r29
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  fontInfo_t *v17; // r3
  fontInfo_t *v18; // r11
  int v19; // r9
  int v20; // r10
  glyphInfo_t *v21; // r11
  char s_high; // r7
  glyphInfo_t *v23; // r11
  char t_high; // r5
  fontInfo_t *v25; // r6
  __int16 numGlyphs; // r5
  _BYTE *v27; // r11
  int v28; // ctr
  char v29; // r9
  char v30; // r8
  char v31; // r7
  int v32; // [sp+8h] [-10D8h]
  int v33; // [sp+8h] [-10D8h]
  int v34; // [sp+Ch] [-10D4h]
  int v35; // [sp+Ch] [-10D4h]
  int v36; // [sp+10h] [-10D0h]
  int v37; // [sp+10h] [-10D0h]
  int v38; // [sp+14h] [-10CCh]
  int v39; // [sp+14h] [-10CCh]
  int v40; // [sp+18h] [-10C8h]
  int v41; // [sp+18h] [-10C8h]
  int v42; // [sp+1Ch] [-10C4h]
  int v43; // [sp+1Ch] [-10C4h]
  int v44[4]; // [sp+50h] [-1090h] BYREF
  idStr v45; // [sp+60h] [-1080h] BYREF
  idStr v46; // [sp+80h] [-1060h] BYREF
  va v47; // [sp+A0h] [-1040h] BYREF

  fontInfo = this->fontInfo;
  this->timestamp = -1;
  if ( fontInfo != nullptr )
  {
    idMem::Free(this: &mem, ptr: fontInfo->glyphData, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: fontInfo->charIndex, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: fontInfo, align: ALIGN_16);
  }
  str = this->name.str;
  this->fontInfo = nullptr;
  v7 = idFont::RemapFont(baseName: str);
  this->alias = v7;
  if ( v7 != nullptr )
  {
    *((_BYTE *)&this->idResource + 32) &= ~0x80u;
  }
  else
  {
    HIDWORD(v6) = this->name.str;
    v8 = va::va(
           this: &v47,
           fmt: "fonts/%s/48.dat",
           a3: v6,
           a4: v5,
           a5: v4,
           a6: v32,
           a7: v34,
           a8: v36,
           a9: v38,
           a10: v40,
           a11: v42);
    idStr::idStr(this: &v45, text: v8);
    if ( idLib::production < PROD_PRODUCTION || !resourceManager->ExcludeFont(this: resourceManager, a2: v45.data) )
    {
      v12 = fileSystem->OpenFileRead(this: fileSystem, a2: v45.data, a3: 1, a4: 0);
      v13 = v12;
      if ( v12 != nullptr )
      {
        v44[0] = 0;
        v12->Read(this: v12, a2: v44, a3: 4u);
        HIDWORD(v15) = 1768161280;
        HIDWORD(v16) = v44[0];
        LODWORD(v16) = 1768187434;
        if ( v44[0] == 1768187434 )
        {
          this->timestamp = v13->Timestamp(this: v13);
          v17 = (fontInfo_t *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x18u,
                                tag: TAG_FONTS,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
          if ( v17 != nullptr )
          {
            v17->glyphData = nullptr;
            v18 = v17;
            v17->charIndex = nullptr;
            v17->material = nullptr;
            v17->imageWidth = 0;
            v17->imageHeight = 0;
            v17->pointSize = 0;
            v17->ascender = 0;
            v17->descender = 0;
            v17->numGlyphs = 0;
          }
          else
          {
            v18 = nullptr;
          }
          this->fontInfo = v18;
          v13->Read(this: v13, a2: &v18->pointSize, a3: 2u);
          v13->Read(this: v13, a2: &this->fontInfo->ascender, a3: 2u);
          v13->Read(this: v13, a2: &this->fontInfo->descender, a3: 2u);
          v13->Read(this: v13, a2: &this->fontInfo->numGlyphs, a3: 2u);
          fontInfo_t::AllocateGlyphs(this: this->fontInfo, num: this->fontInfo->numGlyphs);
          v13->Read(this: v13, a2: this->fontInfo->glyphData, a3: 10 * this->fontInfo->numGlyphs);
          v19 = 0;
          if ( this->fontInfo->numGlyphs > 0 )
          {
            v20 = 0;
            do
            {
              ++v19;
              v21 = &this->fontInfo->glyphData[v20];
              s_high = HIBYTE(v21->s);
              HIBYTE(v21->s) = v21->s;
              LOBYTE(v21->s) = s_high;
              v23 = &this->fontInfo->glyphData[v20];
              t_high = HIBYTE(v23->t);
              ++v20;
              HIBYTE(v23->t) = v23->t;
              LOBYTE(v23->t) = t_high;
            }
            while ( v19 < this->fontInfo->numGlyphs );
          }
          v13->Read(this: v13, a2: this->fontInfo->charIndex, a3: 4 * this->fontInfo->numGlyphs);
          v25 = this->fontInfo;
          numGlyphs = v25->numGlyphs;
          if ( numGlyphs > 0 )
          {
            v27 = (char *)v25->charIndex - 2;
            v28 = numGlyphs;
            do
            {
              v29 = v27[5];
              v30 = v27[4];
              v31 = v27[3];
              v27[5] = v27[2];
              v27[2] = v29;
              v27[3] = v30;
              v27 += 4;
              *v27 = v31;
              --v28;
            }
            while ( v28 != 0 );
          }
          ((void (__fastcall *)(idFile *, int))v13->dtr_idFile)(a1: v13, a2: 1);
          idStr::idStr(this: &v46, text: &v45);
          idStr::SetFileExtension(this: &v46, extension: "tga");
          this->fontInfo->material = (const idMaterial *)idResourceList::Load(
                                                           this: &idMaterial::resourceList,
                                                           name: v46.data,
                                                           makeDefault: true,
                                                           skipStaleCheck: false);
          if ( idLib::production < PROD_PRODUCTION )
            idMaterial::ReloadImages(this: this->fontInfo->material, force: false);
          this->fontInfo->imageWidth = idMaterial::GetWidth(this: this->fontInfo->material);
          this->fontInfo->imageHeight = idMaterial::GetHeight(this: this->fontInfo->material);
          idStr::FreeData(this: &v46);
        }
        else
        {
          HIDWORD(v14) = this->name.str;
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Wrong Version for idFont '%s'",
            a3: v14,
            a4: v16,
            a5: v15,
            a6: v33,
            a7: v35,
            a8: v37,
            a9: v39,
            a10: v41,
            a11: v43);
          if ( idStr::Icmp(s1: this->name.str, s2: idFont::DEFAULT_FONT) == 0 )
            idLib::Error(fmt: "Couldn't load default font");
          this->alias = (idFont *)idResourceList::Load(
                                    this: &idFont::resourceList,
                                    name: (char *)idFont::DEFAULT_FONT,
                                    makeDefault: true,
                                    skipStaleCheck: false);
          ((void (__fastcall *)(idFile *, int))v13->dtr_idFile)(a1: v13, a2: 1);
        }
      }
      else
      {
        HIDWORD(v11) = v45.data;
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Couldn't open '%s'",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v33,
          a7: v35,
          a8: v37,
          a9: v39,
          a10: v41,
          a11: v43);
        if ( idStr::Icmp(s1: this->name.str, s2: idFont::DEFAULT_FONT) == 0 )
          idLib::Error(fmt: "Couldn't load default font");
        this->alias = (idFont *)idResourceList::Load(
                                  this: &idFont::resourceList,
                                  name: (char *)idFont::DEFAULT_FONT,
                                  makeDefault: true,
                                  skipStaleCheck: false);
      }
    }
    idStr::FreeData(this: &v45);
  }
}


// ========================================================================
// $LN205
// EA  : 0x8276D8E8
// RVA : 0x0076D8E8
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _LN205()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 96));
}


// ========================================================================
// __unwind$221133
// EA  : 0x8276D910
// RVA : 0x0076D910
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_221133()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 128));
}


// ========================================================================
// ?GetGlyph@idFont@@QBAABUglyphInfo_t@@I@Z
// EA  : 0x8276DAE8
// RVA : 0x0076DAE8
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

const glyphInfo_t *__fastcall idFont::GetGlyph(
        idFont *this,
        unsigned int idx,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        unsigned int a14)
{
  idFont *alias; // r3
  fontInfo_t *fontInfo; // r11
  int v17; // r3
  fontInfo_t *v19; // r11
  int v20; // r3
  idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > v21; // [sp+50h] [-40h] BYREF
  idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> > v22; // [sp+54h] [-3Ch] BYREF
  unsigned int v23[14]; // [sp+58h] [-38h] BYREF

  alias = this->alias;
  a14 = idx;
  if ( alias != nullptr )
    return idFont::GetGlyph(this: alias, idx);
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr
    && fontInfo->glyphData != nullptr
    && fontInfo->charIndex != nullptr
    && fontInfo->numGlyphs != 0 )
  {
    v21.__vftable = (idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> >_vtbl *)&idSearch_BinaryDefault<unsigned int>::`vftable';
    v17 = idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search(
            this: &v21,
            base: fontInfo->charIndex,
            num: fontInfo->numGlyphs,
            value: &a14);
    v21.__vftable = (idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> >_vtbl *)&idSearch<unsigned int>::`vftable';
    if ( v17 >= 0 )
      return &this->fontInfo->glyphData[v17];
  }
  alias = this->alias;
  if ( alias != nullptr )
  {
    idx = 42;
    return idFont::GetGlyph(this: alias, idx);
  }
  v19 = this->fontInfo;
  if ( v19 != nullptr
    && v19->glyphData != nullptr
    && v19->charIndex != nullptr
    && v19->numGlyphs != 0
    && (v22.__vftable = (idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> >_vtbl *)&idSearch_BinaryDefault<unsigned int>::`vftable',
        v23[0] = 42,
        v20 = idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int>>::Search(
                this: &v22,
                base: v19->charIndex,
                num: v19->numGlyphs,
                value: v23),
        v22.__vftable = (idSearch_Binary<unsigned int,idSearch_BinaryDefault<unsigned int> >_vtbl *)&idSearch<unsigned int>::`vftable',
        v20 >= 0) )
  {
    return &this->fontInfo->glyphData[v20];
  }
  else
  {
    return &defaultGlyph;
  }
}


// ========================================================================
// __unwind$221654
// EA  : 0x8276DC44
// RVA : 0x0076DC44
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_221654()
{
  int v0; // r12

  idSearch_BinaryDefault<unsigned int>::~idSearch_BinaryDefault<unsigned int>(this: (idSearch_BinaryDefault<unsigned int> *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$221655
// EA  : 0x8276DC6C
// RVA : 0x0076DC6C
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void _unwind_221655()
{
  int v0; // r12

  idSearch_BinaryDefault<unsigned int>::~idSearch_BinaryDefault<unsigned int>(this: (idSearch_BinaryDefault<unsigned int> *)(v0 - 144 + 84));
}


// ========================================================================
// `dynamic initializer for 'idFont::resourceList''
// EA  : 0x83341730
// RVA : 0x01341730
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFont::resourceList__()
{
  idResourceList::idResourceList(this: &idFont::resourceList, typeName: "font");
  idFont::resourceList.__vftable = (idTypedResourceList<idFont>_vtbl *)&idTypedResourceList<idFont>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFont::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'TestFont_v''
// EA  : 0x83341780
// RVA : 0x01341780
// PDB : w:\tech5\engine\guis\font.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestFont_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestFont_v,
           cmdName: "TestFont",
           function: TestFont_f,
           description: "Render text to the screen",
           argCompletion: nullptr);
}

