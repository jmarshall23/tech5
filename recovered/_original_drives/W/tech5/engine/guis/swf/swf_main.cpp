
// ========================================================================
// ?MarkImageForPurging@idSWF@@SAXPAVidImage@@@Z
// EA  : 0x82775F10
// RVA : 0x00775F10
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::MarkImageForPurging(idImage *image)
{
  int v1; // r11
  purgableSwfImage_t *v2; // r10
  purgableSwfImage_t *v3; // r10

  v1 = 0;
  v2 = idSWF::purgableSWFImages;
  do
  {
    if ( v2->image == image )
      break;
    ++v2;
    ++v1;
  }
  while ( (int)v2 < (int)&printSWFVar_v );
  if ( v1 != 8 )
    goto LABEL_11;
  v3 = idSWF::purgableSWFImages;
  v1 = 0;
  while ( v3->image != nullptr )
  {
    ++v3;
    ++v1;
    if ( (int)v3 >= (int)&printSWFVar_v )
      goto LABEL_10;
  }
  idSWF::purgableSWFImages[v1].image = image;
LABEL_10:
  if ( v1 != 8 )
LABEL_11:
    idSWF::purgableSWFImages[v1].swfFrameNum = idSWF::swfFrameNum;
}


// ========================================================================
// ?RemoveImgFromPurgableList@idSWF@@SAXPAVidImage@@@Z
// EA  : 0x82775FA0
// RVA : 0x00775FA0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::RemoveImgFromPurgableList(idImage *img)
{
  if ( idSWF::purgableSWFImages[0].image == img )
    idSWF::purgableSWFImages[0].image = nullptr;
  if ( idSWF::purgableSWFImages[1].image == img )
    idSWF::purgableSWFImages[1].image = nullptr;
  if ( idSWF::purgableSWFImages[2].image == img )
    idSWF::purgableSWFImages[2].image = nullptr;
  if ( idSWF::purgableSWFImages[3].image == img )
    idSWF::purgableSWFImages[3].image = nullptr;
  if ( idSWF::purgableSWFImages[4].image == img )
    idSWF::purgableSWFImages[4].image = nullptr;
  if ( idSWF::purgableSWFImages[5].image == img )
    idSWF::purgableSWFImages[5].image = nullptr;
  if ( idSWF::purgableSWFImages[6].image == img )
    idSWF::purgableSWFImages[6].image = nullptr;
  if ( idSWF::purgableSWFImages[7].image == img )
    idSWF::purgableSWFImages[7].image = nullptr;
}


// ========================================================================
// ?SetListener@idSWF@@QAAXH@Z
// EA  : 0x82776050
// RVA : 0x00776050
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::SetListener(idSWF *this, int id)
{
  idSoundEmitter *soundEmitter; // r11

  soundEmitter = this->soundEmitter;
  if ( soundEmitter != nullptr )
    ((void (*)(void))soundEmitter->UpdateEmitter)();
}


// ========================================================================
// ?ClearEmitter@idSWF@@QAAX_N@Z
// EA  : 0x82776090
// RVA : 0x00776090
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::ClearEmitter(idSWF *this, bool instant)
{
  idSoundEmitter *soundEmitter; // r3

  soundEmitter = this->soundEmitter;
  if ( soundEmitter != nullptr )
  {
    soundEmitter->Free(this: soundEmitter, a2: instant);
    this->soundEmitter = nullptr;
  }
}


// ========================================================================
// ?Activate@idSWF@@QAAX_N@Z
// EA  : 0x827760E0
// RVA : 0x007760E0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::Activate(idSWF *this, bool b)
{
  if ( !this->isActive && b )
  {
    this->inhibitControl = false;
    this->lastRenderTime = Sys_Milliseconds();
    idSWFSpriteInstance::FreeDisplayList(this: this->mainspriteInstance);
    idSWFSpriteInstance::Play(this: this->mainspriteInstance);
    idSWFSpriteInstance::Run(this: this->mainspriteInstance);
    idSWFSpriteInstance::RunActions(this: this->mainspriteInstance);
  }
  this->isActive = b;
}


// ========================================================================
// ?AllocateEmitter@idSWF@@QAAXPAVidSoundWorld@@@Z
// EA  : 0x82776160
// RVA : 0x00776160
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::AllocateEmitter(idSWF *this, idSoundWorld *sndWorld)
{
  if ( this->soundEmitter == nullptr && sndWorld != nullptr )
    this->soundEmitter = sndWorld->AllocSoundEmitter(this: sndWorld);
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_blackbars@idSWF@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827761B8
// RVA : 0x007761B8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::idSWFScriptNativeVar_blackbars::Set(
        idSWF::idSWFScriptNativeVar_blackbars *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  this->pThis->blackbars = idSWFScriptVar::ToBool(this: value);
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_crop@idSWF@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827761F0
// RVA : 0x007761F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::idSWFScriptNativeVar_crop::Set(
        idSWF::idSWFScriptNativeVar_crop *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  this->pThis->crop = idSWFScriptVar::ToBool(this: value);
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_automaticRescale@idSWF@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82776228
// RVA : 0x00776228
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::idSWFScriptNativeVar_automaticRescale::Set(
        idSWF::idSWFScriptNativeVar_automaticRescale *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  this->pThis->automaticRescale = idSWFScriptVar::ToBool(this: value);
}


// ========================================================================
// ?PurgeUnusedImages@idSWF@@SAXXZ
// EA  : 0x82776588
// RVA : 0x00776588
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

static void __fastcall idSWF::PurgeUnusedImages()
{
  purgableSwfImage_t *v0; // r31
  unsigned int v1; // r11

  if ( swf_purgeUnusedImages.valueInteger != 0 )
  {
    v0 = idSWF::purgableSWFImages;
    v1 = idSWF::swfFrameNum;
    do
    {
      if ( v0->image != nullptr && v1 - v0->swfFrameNum > 2 )
      {
        idImage::PurgeImage(this: v0->image);
        v1 = idSWF::swfFrameNum;
        v0->image = nullptr;
      }
      ++v0;
    }
    while ( (int)v0 < (int)&printSWFVar_v );
    idSWF::swfFrameNum = v1 + 1;
  }
}


// ========================================================================
// ?ForcePurgeImages@idSWF@@SAXXZ
// EA  : 0x82776608
// RVA : 0x00776608
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

static void __fastcall idSWF::ForcePurgeImages()
{
  purgableSwfImage_t *v0; // r31

  if ( swf_purgeUnusedImages.valueInteger != 0 )
  {
    renderSystem->SyncRenderThread(this: renderSystem, a2: true);
    v0 = idSWF::purgableSWFImages;
    do
    {
      if ( v0->image != nullptr )
      {
        idLib::Printf(fmt: "Force purging image %s\n", v0->image->name.str);
        idImage::PurgeImage(this: v0->image);
        v0->image = nullptr;
      }
      ++v0;
    }
    while ( (int)v0 < (int)&printSWFVar_v );
  }
}


// ========================================================================
// ?listSWF_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82776698
// RVA : 0x00776698
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall listSWF_f(const idCmdArgs *args)
{
  int v1; // r30
  int v2; // r29
  idSWF *v3; // r31
  imageState_t v4; // r3

  v1 = 0;
  if ( idSWF::allSWFObjects.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = idSWF::allSWFObjects.list[v2];
      idLib::Printf(
        fmt: "%-2i %4ix%4i = %4ik ",
        v1,
        v3->atlasWidth,
        v3->atlasHeight,
        v3->atlasWidth * v3->atlasHeight / 1024);
      v4 = idImage::ImageState(this: v3->atlasImage);
      if ( v4 != IS_PURGED )
      {
        if ( v4 == IS_BACKGROUND_READING )
        {
          idLib::Printf(fmt: "LOADING");
        }
        else if ( (unsigned int)v4 < (IS_READY|IS_BACKGROUND_READING) )
        {
          idLib::Printf(fmt: "      ");
        }
      }
      else
      {
        idLib::Printf(fmt: "PURGED");
      }
      idLib::Printf(fmt: " %s\n", v3->filename.str);
      ++v1;
      ++v2;
    }
    while ( v1 < idSWF::allSWFObjects.num );
  }
}


// ========================================================================
// ?IsPlayerControlInhibited@idSWF@@QBA_NXZ
// EA  : 0x82776770
// RVA : 0x00776770
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

int __fastcall idSWF::IsPlayerControlInhibited(idSWF *this)
{
  unsigned __int8 v1; // r11

  if ( this->frameRate == 0 || !this->isActive )
    return 0;
  if ( !this->inhibitControl )
    return 0;
  v1 = 1;
  if ( !this->useInhibtControl )
    return 0;
  return v1;
}


// ========================================================================
// ?FindSpriteOrphanIndex@idSWF@@ABAHPBVidSWFSpriteInstance@@@Z
// EA  : 0x827767B8
// RVA : 0x007767B8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

int __fastcall idSWF::FindSpriteOrphanIndex(idSWF *this, const idSWFSpriteInstance *spriteInstance)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->orphanedSprites.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->orphanedSprites.list[i].spriteInstance != spriteInstance; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?ExtractSpriteFromOrphanage@idSWF@@AAAPAVidSWFSpriteInstance@@ABVidStr@@PBVidSWFSprite@@HPBV2@@Z
// EA  : 0x82776800
// RVA : 0x00776800
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWF::ExtractSpriteFromOrphanage(
        idSWF *this,
        const idStr *name,
        const idSWFSprite *sprite,
        const int depth,
        const idSWFSpriteInstance *parent)
{
  int v10; // r25
  idList<idSWF::orphanedSprite_t,72> *p_orphanedSprites; // r26
  int i; // r29
  idSWF::orphanedSprite_t *v13; // r30
  idSWFSpriteInstance *spriteInstance; // r31
  char *str; // r3
  char v16; // r11

  v10 = 0;
  if ( this->orphanedSprites.num <= 0 )
    return nullptr;
  p_orphanedSprites = &this->orphanedSprites;
  for ( i = 0; ; ++i )
  {
    v13 = &p_orphanedSprites->list[i];
    spriteInstance = v13->spriteInstance;
    if ( v13->spriteInstance->parent == parent && spriteInstance->sprite == sprite )
    {
      str = (char *)spriteInstance->name.str;
      if ( str == &byte_8200D768 || (v16 = 0, *str == 0) )
        v16 = 1;
      if ( v16 != 0
         ? (_cntlzw(depth - spriteInstance->depth) & 0x20) != 0
         : (_cntlzw(idStr::Cmp(s1: str, s2: name->data)) & 0x20) != 0 )
      {
        break;
      }
    }
    if ( ++v10 >= this->orphanedSprites.num )
      return nullptr;
  }
  ++this->c_SpriteInstanceAdoptions;
  if ( v13->wasPlaying )
    idSWFSpriteInstance::Play(this: spriteInstance);
  else
    idSWFSpriteInstance::Stop(this: spriteInstance);
  idList<idSWF::orphanedSprite_t,72>::RemoveIndex(this: p_orphanedSprites, index: v10);
  return spriteInstance;
}


// ========================================================================
// ?FindTextOrphanIndex@idSWF@@ABAHPBVidSWFTextInstance@@@Z
// EA  : 0x82776938
// RVA : 0x00776938
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

int __fastcall idSWF::FindTextOrphanIndex(idSWF *this, const idSWFTextInstance *textInstance)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->orphanedTexts.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->orphanedTexts.list[i].textInstance != textInstance; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?ExtractTextFromOrphanage@idSWF@@AAAPAVidSWFTextInstance@@ABVidStr@@PAVidSWFEditText@@HPBVidSWFSpriteInstance@@@Z
// EA  : 0x82776980
// RVA : 0x00776980
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWFTextInstance *__fastcall idSWF::ExtractTextFromOrphanage(
        idSWF *this,
        const idStr *name,
        idSWFEditText *editText,
        const int depth,
        const idSWFSpriteInstance *parent)
{
  int v10; // r28
  idList<idEntityPtr<idEntity>,58> *p_orphanedTexts; // r27
  int i; // r29
  idSWFTextInstance *value; // r31
  char *str; // r11
  char v15; // r11
  bool v16; // zf

  v10 = 0;
  if ( this->orphanedTexts.num <= 0 )
    return nullptr;
  p_orphanedTexts = (idList<idEntityPtr<idEntity>,58> *)&this->orphanedTexts;
  for ( i = 0; ; ++i )
  {
    value = (idSWFTextInstance *)p_orphanedTexts->list[i].spawnId.value;
    if ( value->parent == parent )
    {
      str = (char *)value->name.str;
      if ( str == &byte_8200D768 || (v16 = *str != 0, v15 = 0, !v16) )
        v15 = 1;
      if ( v15 != 0
         ? (_cntlzw(depth - value->depth) & 0x20) != 0
         : (_cntlzw(idStr::Cmp(s1: name->data, s2: value->name.str)) & 0x20) != 0 )
      {
        break;
      }
    }
    if ( ++v10 >= this->orphanedTexts.num )
      return nullptr;
  }
  ++this->c_TextInstanceAdoptions;
  value->editText = editText;
  idSWFTextInstance::ReInit(this: value);
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_orphanedTexts, index: v10);
  return value;
}


// ========================================================================
// ?reportSWFMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82776BD8
// RVA : 0x00776BD8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall reportSWFMemory_f(const idCmdArgs *args)
{
  int v1; // r31
  _DWORD *v2; // r11
  int i; // ctr
  idSWF **list; // r6
  int num; // r5
  idSWFDictionaryEntry *v6; // r7
  int v7; // r8
  int v8; // ctr
  int type; // r11
  _DWORD v10[16]; // [sp+50h] [-40h] BYREF

  v1 = 0;
  v2 = v10;
  v10[0] = 0;
  for ( i = 7; i != 0; --i )
    *++v2 = 0;
  if ( idSWF::allSWFObjects.num > 0 )
  {
    list = idSWF::allSWFObjects.list;
    num = idSWF::allSWFObjects.num;
    do
    {
      if ( (*list)->dictionary.num > 0 )
      {
        v6 = (*list)->dictionary.list;
        v7 = 0;
        v8 = (*list)->dictionary.num;
        do
        {
          type = v6[v7].type;
          if ( type < 8 )
            ++v10[type];
          ++v7;
          --v8;
        }
        while ( v8 != 0 );
      }
      --num;
      ++list;
    }
    while ( num != 0 );
  }
  do
  {
    idLib::Printf(fmt: "%6i %s\n", v10[v1], dictTypeNames[v1]);
    ++v1;
  }
  while ( v1 < 8 );
}


// ========================================================================
// ?reportMainMenuFonts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82776CB8
// RVA : 0x00776CB8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall reportMainMenuFonts_f(const idCmdArgs *args)
{
  int v1; // r20
  int v2; // r23
  idSWF *v3; // r29
  int v4; // r27
  int v5; // r28
  idSWFDictionaryEntry *v6; // r30
  idSWFDictionaryEntry *DictionaryEntry; // r19
  float *p_x; // r8
  idStr v9; // [sp+50h] [-B0h] BYREF
  idStr v10[4]; // [sp+70h] [-90h] BYREF

  v1 = 0;
  if ( idSWF::allSWFObjects.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = idSWF::allSWFObjects.list[v2];
      idLib::Printf(fmt: "++++ %s ++++\n", v3->filename.str);
      v4 = 0;
      if ( v3->dictionary.num > 0 )
      {
        v5 = 0;
        do
        {
          v6 = &v3->dictionary.list[v5];
          if ( v6 != nullptr && v6->type == SWF_DICT_EDITTEXT )
          {
            DictionaryEntry = idSWF::FindDictionaryEntry(
                                this: v3,
                                characterID: v6->edittext->fontID,
                                type: SWF_DICT_FONT);
            idStr::idStr(this: v10, text: v6->edittext->initialText.str);
            idStr::idStr(this: &v9, text: v6->edittext->variable.str);
            idStr::Replace(this: v10, old: "\n", nw: "\\n");
            idStr::Replace(this: &v9, old: "\n", nw: "\\n");
            p_x = &v6->edittext->bounds.tl.x;
            idLib::Printf(
              fmt: "\t%s - [ %s, %s ] ( %f, %f ) - ( %f, %f )\n",
              DictionaryEntry->font->fontID->name.str,
              v10[0].data,
              (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_x[2])),
              p_x[2],
              p_x[3],
              *p_x,
              p_x[1]);
            idStr::FreeData(this: &v9);
            idStr::FreeData(this: v10);
          }
          ++v4;
          ++v5;
        }
        while ( v4 < v3->dictionary.num );
      }
      ++v1;
      ++v2;
    }
    while ( v1 < idSWF::allSWFObjects.num );
  }
}


// ========================================================================
// __unwind$227363_0
// EA  : 0x82776E2C
// RVA : 0x00776E2C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_227363_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$227364_0
// EA  : 0x82776E54
// RVA : 0x00776E54
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_227364_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// ?PlaySound@idSWF@@QAAHPBVidSoundShader@@W4soundChannel_t@@_N@Z
// EA  : 0x82776E80
// RVA : 0x00776E80
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

int __fastcall idSWF::PlaySound(
        idSWF *this,
        const idSoundShader *soundShader,
        soundChannel_t channel,
        const bool blocking)
{
  soundShaderGroups_t v8; // r11
  soundShaderParms_t v10; // [sp+50h] [-C0h] BYREF

  if ( !this->isActive )
    return -1;
  if ( this->soundEmitter == nullptr )
  {
    idLib::Warning(fmt: "idSWF::PlaySound: No playing sound world on soundSystem!");
    return -1;
  }
  soundShaderParms_t::Clear(this: &v10);
  soundShaderParms_t::Clear(this: &v10);
  v10.soundChannel = channel;
  if ( channel == SND_CHANNEL_MUSIC1 || channel == SND_CHANNEL_MUSIC2 || (v8 = SSG_UI, channel == SND_CHANNEL_MUSIC3) )
    v8 = SSG_MUSIC_MENU;
  v10.groups = v8;
  if ( blocking )
    v10.soundShaderFlags = SSF_BLOCK_ON_LOAD;
  return this->soundEmitter->StartSound(this: this->soundEmitter, a2: channel, a3: soundShader, a4: &v10);
}


// ========================================================================
// ?PlaySound@idSWF@@QAAHPBDW4soundChannel_t@@_N@Z
// EA  : 0x82776F40
// RVA : 0x00776F40
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

int __fastcall idSWF::PlaySound(idSWF *this, const char *sound, soundChannel_t channel, bool blocking)
{
  const idSoundShader *v8; // r3

  if ( !this->isActive )
    return -1;
  if ( this->soundEmitter == nullptr )
  {
    idLib::Warning(fmt: "idSWF::PlaySound: No playing sound world on soundSystem!");
    return -1;
  }
  if ( sound == nullptr )
    return idSWF::PlaySound(this, soundShader: nullptr, channel, blocking);
  v8 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                this: &idSoundShader::resourceList,
                                name: sound,
                                makeDefault: true);
  return idSWF::PlaySound(this, soundShader: v8, channel, blocking);
}


// ========================================================================
// ?Call@idSWFScriptFunction_inhibitControl@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827771B8
// RVA : 0x007771B8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_inhibitControl *__fastcall idSWF::idSWFScriptFunction_inhibitControl::Call(
        idSWF::idSWFScriptFunction_inhibitControl *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  v6 = idSWFScriptVar::ToBool(this: parms->list);
  LODWORD(v7.f) = result->value;
  this->__vftable = (idSWF::idSWFScriptFunction_inhibitControl_vtbl *)4;
  *(_BYTE *)(v7.i + 9) = v6;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_useInhibit@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777208
// RVA : 0x00777208
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_useInhibit *__fastcall idSWF::idSWFScriptFunction_useInhibit::Call(
        idSWF::idSWFScriptFunction_useInhibit *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  v6 = idSWFScriptVar::ToBool(this: parms->list);
  LODWORD(v7.f) = result->value;
  this->__vftable = (idSWF::idSWFScriptFunction_useInhibit_vtbl *)4;
  *(_BYTE *)(v7.i + 10) = v6;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_deactivate@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777258
// RVA : 0x00777258
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_deactivate *__fastcall idSWF::idSWFScriptFunction_deactivate::Call(
        idSWF::idSWFScriptFunction_deactivate *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWF::Activate(this: (idSWF *)result->value.i, b: false);
  this->__vftable = (idSWF::idSWFScriptFunction_deactivate_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_playSound@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827772A8
// RVA : 0x007772A8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_playSound *__fastcall idSWF::idSWFScriptFunction_playSound::Call(
        idSWF::idSWFScriptFunction_playSound *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  soundChannel_t v4; // r29
  idStr *v8; // r3
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v4 = SND_CHANNEL_ANY;
  if ( parms->num > 1 )
    v4 = idSWFScriptVar::ToInteger(this: parms->list + 1);
  v8 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v10, result: (idStr *)parms->list);
  idSWF::PlaySound(this: (idSWF *)result->value.i, sound: v8->data, channel: v4, blocking: false);
  idStr::FreeData(this: v10);
  this->__vftable = (idSWF::idSWFScriptFunction_playSound_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$228187
// EA  : 0x82777324
// RVA : 0x00777324
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228187()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_stopSounds@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777350
// RVA : 0x00777350
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_stopSounds *__fastcall idSWF::idSWFScriptFunction_stopSounds::Call(
        idSWF::idSWFScriptFunction_stopSounds *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r4
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  v6 = 0;
  if ( parms->num == 1 )
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
  LODWORD(v7.f) = result->value;
  if ( *(_DWORD *)(v7.i + 76) != 0 )
    (*(void (__fastcall **)(_DWORD, int, idSWFScriptObject *))(**(_DWORD **)(v7.i + 76) + 24))(
      a1: *(_DWORD *)(v7.i + 76),
      a2: v6,
      a3: thisObject);
  else
    idLib::Warning(fmt: "No playing sound world on soundSystem in swf play sound!", v6, thisObject);
  this->__vftable = (idSWF::idSWFScriptFunction_stopSounds_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setCVarInteger@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827773F0
// RVA : 0x007773F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_setCVarInteger *__fastcall idSWF::idSWFScriptFunction_setCVarInteger::Call(
        idSWF::idSWFScriptFunction_setCVarInteger *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char *data; // r27
  idSWFScriptVar *v7; // r3
  idCVarSystem_vtbl *v8; // r30
  int v9; // r3
  idStr v11[2]; // [sp+60h] [-50h] BYREF

  data = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v11, result: (idStr *)parms->list)->data;
  v7 = parms->list + 1;
  v8 = cvarSystem->__vftable;
  v9 = idSWFScriptVar::ToInteger(this: v7);
  v8->SetCVarInteger(this: cvarSystem, a2: data, a3: v9, a4: 0);
  idStr::FreeData(this: v11);
  this->__vftable = (idSWF::idSWFScriptFunction_setCVarInteger_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$228257
// EA  : 0x82777470
// RVA : 0x00777470
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228257()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?printSWFVar_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82777768
// RVA : 0x00777768
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall printSWFVar_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r3
  int v4; // r3
  idSWF *v5; // r29
  int v6; // r30
  const char *v7; // r4
  int v8; // r27
  int v9; // r26
  const char **v10; // r29
  const idSWFScriptVar *NestedVar; // r3
  idSWFScriptObject v12; // [sp+50h] [-A0h] BYREF

  argc = args->argc;
  v12.refCount = args->argc;
  if ( v12.refCount == 3 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v4 = atol(nptr: v3);
    if ( v4 < 0 || v4 >= idSWF::allSWFObjects.num )
    {
      idLib::Printf(
        fmt: "printSWFVar index %d is out of range. Expecting range [0, %d]\n",
        v4,
        idSWF::allSWFObjects.num - 1);
    }
    else
    {
      v5 = idSWF::allSWFObjects.list[v4];
      idLib::Printf(fmt: "Printing from SWF %s...\n", v5->filename.str);
      v6 = 0;
      v12.variablesHash[2] = 1280;
      memset(&v12.variables.granularity, 0, 12);
      if ( args->argc <= 2 )
        v7 = &byte_8200D768;
      else
        v7 = args->argv[2];
      idStrListBreakupString(list: (idList<idStr,5> *)&v12.variables.granularity, string: v7, separator: ".");
      idSWFScriptObject::Get(this: &v12, result: (idSWFScriptVar *)v5->globals, name: "_global");
      v8 = v12.variablesHash[0];
      if ( v12.variablesHash[0] <= 0 )
      {
LABEL_15:
        idSWFScriptVar::PrintToConsole(this: (idSWFScriptVar *)&v12);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v12);
        idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)&v12.variables.granularity);
      }
      else
      {
        v9 = *(_DWORD *)&v12.variables.granularity;
        v10 = (const char **)(*(_DWORD *)&v12.variables.granularity + 4);
        while ( 1 )
        {
          NestedVar = idSWFScriptVar::GetNestedVar(
                        this: (idSWFScriptVar *)&v12.variables.num,
                        result: (idSWFScriptVar *)&v12,
                        arg1: *v10,
                        arg2: nullptr,
                        arg3: nullptr,
                        arg4: nullptr,
                        arg5: nullptr,
                        arg6: nullptr);
          idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v12, other: NestedVar);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v12.variables.num);
          if ( v12.refCount == 4 )
            break;
          ++v6;
          v10 += 8;
          if ( v6 >= v8 )
            goto LABEL_15;
        }
        idStr::idStr(this: (idStr *)&v12.variablesHash[11], text: (const idStr *)(32 * v6 + v9));
        idList<idStr,3>::SetNum(this: (idList<idStr,5> *)&v12.variables.granularity, newNum: v6);
        idStrListCombineString(
          result: (idStr *)&v12.variablesHash[3],
          list: (const idList<idStr,5> *)&v12.variables.granularity,
          separator: ".");
        idLib::Printf(
          fmt: "Could not resolve '%s' under object '%s'\n",
          (const char *)v12.variablesHash[12],
          (const char *)v12.variablesHash[4]);
        idStr::FreeData(this: (idStr *)&v12.variablesHash[3]);
        idStr::FreeData(this: (idStr *)&v12.variablesHash[11]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v12);
        idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)&v12.variables.granularity);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: printSWFVar <SWF id from listSWF> <path.to.object>\n");
  }
}


// ========================================================================
// __unwind$228737
// EA  : 0x82777958
// RVA : 0x00777958
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228737()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$228738
// EA  : 0x82777980
// RVA : 0x00777980
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228738()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$228739
// EA  : 0x827779A8
// RVA : 0x007779A8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228739()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$228740
// EA  : 0x827779D0
// RVA : 0x007779D0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228740()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$228741
// EA  : 0x827779F8
// RVA : 0x007779F8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?Call@idSWFScriptFunction_precacheSound@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777A28
// RVA : 0x00777A28
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_precacheSound *__fastcall idSWF::idSWFScriptFunction_precacheSound::Call(
        idSWF::idSWFScriptFunction_precacheSound *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  const idDecl *v5; // r30
  char *data; // r4
  idStr v8[2]; // [sp+60h] [-40h] BYREF

  v5 = nullptr;
  data = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)parms->list)->data;
  if ( data != nullptr )
    v5 = idDeclInfo::FindWithInheritance(this: &idSoundShader::resourceList, name: data, makeDefault: true);
  idStr::FreeData(this: v8);
  idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: v5->name.str);
  return this;
}


// ========================================================================
// __unwind$228895
// EA  : 0x82777A90
// RVA : 0x00777A90
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228895()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getTruePlatform@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777AB8
// RVA : 0x00777AB8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_getTruePlatform *__fastcall idSWF::idSWFScriptFunction_getTruePlatform::Call(
        idSWF::idSWFScriptFunction_getTruePlatform *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  this->__vftable = (idSWF::idSWFScriptFunction_getTruePlatform_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->pThis = nullptr;
  this->__vftable = (idSWF::idSWFScriptFunction_getTruePlatform_vtbl *)6;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_strReplace@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777B10
// RVA : 0x00777B10
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_strReplace *__fastcall idSWF::idSWFScriptFunction_strReplace::Call(
        idSWF::idSWFScriptFunction_strReplace *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStr v7; // [sp+60h] [-80h] BYREF
  idStr v8; // [sp+80h] [-60h] BYREF
  idStr v9[2]; // [sp+A0h] [-40h] BYREF

  if ( parms->num == 3 )
  {
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v7, result: (idStr *)parms->list);
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)v9, result: (idStr *)&parms->list[1]);
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v8, result: (idStr *)&parms->list[2]);
    idStr::Replace(this: &v7, old: v9[0].data, nw: v8.data);
    this->__vftable = (idSWF::idSWFScriptFunction_strReplace_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWF::idSWFScriptFunction_strReplace_vtbl *)1;
    this->pThis = (idSWF *)idSWFScriptString::Alloc(s: &v7);
    idStr::FreeData(this: &v8);
    idStr::FreeData(this: v9);
    idStr::FreeData(this: &v7);
  }
  else
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// __unwind$228993
// EA  : 0x82777BDC
// RVA : 0x00777BDC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228993()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 224;
  if ( (*(_DWORD *)(v0 - 224 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 244));
  }
}


// ========================================================================
// __unwind$228996
// EA  : 0x82777C20
// RVA : 0x00777C20
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$228997
// EA  : 0x82777C48
// RVA : 0x00777C48
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228997()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 160));
}


// ========================================================================
// __unwind$228998
// EA  : 0x82777C70
// RVA : 0x00777C70
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_228998()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getLocalString@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777CA0
// RVA : 0x00777CA0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_getLocalString *__fastcall idSWF::idSWFScriptFunction_getLocalString::Call(
        idSWF::idSWFScriptFunction_getLocalString *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar *v4; // r30
  idStr *v5; // r3
  const char *String; // r3
  idStr v8; // [sp+60h] [-60h] BYREF
  idStr v9[2]; // [sp+80h] [-40h] BYREF

  v4 = (idSWFScriptVar *)this;
  if ( parms->num != 0 )
  {
    v5 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v9, result: (idStr *)parms->list);
    String = idLocalization::GetString(inString: v5->data);
    idStr::idStr(this: &v8, text: String);
    idStr::FreeData(this: v9);
    v4->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v4);
    v4->type = SWF_VAR_STRING;
    v4->value.i = (int)idSWFScriptString::Alloc(s: &v8);
    idStr::FreeData(this: &v8);
    return (idSWF::idSWFScriptFunction_getLocalString *)v4;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_getLocalString_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$229083
// EA  : 0x82777D3C
// RVA : 0x00777D3C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229083()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 212));
  }
}


// ========================================================================
// __unwind$229086
// EA  : 0x82777D80
// RVA : 0x00777D80
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229086()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$229087
// EA  : 0x82777DA8
// RVA : 0x00777DA8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isMultiplayer@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777DD0
// RVA : 0x00777DD0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_isMultiplayer *__fastcall idSWF::idSWFScriptFunction_isMultiplayer::Call(
        idSWF::idSWFScriptFunction_isMultiplayer *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r11
  bool v6; // r31

  valueInteger = com_multiplayer.valueInteger;
  this->__vftable = (idSWF::idSWFScriptFunction_isMultiplayer_vtbl *)4;
  v6 = valueInteger != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idSWF::idSWFScriptFunction_isMultiplayer_vtbl *)5;
  return this;
}


// ========================================================================
// ?PurgeOrphanage@idSWF@@AAAXXZ
// EA  : 0x82777E30
// RVA : 0x00777E30
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::PurgeOrphanage(idSWF *this)
{
  int v2; // r27
  idBlockAlloc<idSWFSpriteInstance,16,72> *p_spriteInstanceAllocator; // r29
  int v4; // r28
  idSWF::orphanedSprite_t *list; // r11
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *spriteInstance; // r31
  idList<idSWF::orphanedSprite_t,72> *p_orphanedSprites; // r31
  int v8; // r27
  int v9; // r28
  idSWF::orphanedText_t *v10; // r11
  idBlockAlloc<idSWFTextInstance,16,72>::element_t *textInstance; // r31
  idList<idSWF::orphanedText_t,72> *p_orphanedTexts; // r31

  v2 = 0;
  if ( this->orphanedSprites.num > 0 )
  {
    p_spriteInstanceAllocator = &this->spriteInstanceAllocator;
    v4 = 0;
    do
    {
      list = this->orphanedSprites.list;
      spriteInstance = (idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *)list[v4].spriteInstance;
      if ( spriteInstance != nullptr )
      {
        idSWFSpriteInstance::~idSWFSpriteInstance(this: list[v4].spriteInstance);
        spriteInstance->data = (idSWFSpriteInstance *)p_spriteInstanceAllocator->free;
        p_spriteInstanceAllocator->free = spriteInstance;
        --p_spriteInstanceAllocator->active;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->orphanedSprites.num );
  }
  p_orphanedSprites = &this->orphanedSprites;
  if ( this->orphanedSprites.size < 0 )
  {
    if ( this->orphanedSprites.listStatic == 0 || this->orphanedSprites.listStatic == 2 )
    {
      if ( p_orphanedSprites->list != nullptr )
        idMem::Free(this: &mem, ptr: p_orphanedSprites->list, align: ALIGN_16);
      p_orphanedSprites->list = nullptr;
      this->orphanedSprites.size = 0;
    }
    this->orphanedSprites.num = 0;
  }
  v8 = 0;
  this->orphanedSprites.num = __CFADD__(-this->orphanedSprites.size, this->orphanedSprites.size ^ 0x80000000)
                            ? 0
                            : this->orphanedSprites.size;
  if ( this->orphanedTexts.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->orphanedTexts.list;
      textInstance = (idBlockAlloc<idSWFTextInstance,16,72>::element_t *)v10[v9].textInstance;
      if ( textInstance != nullptr )
      {
        idSWFTextInstance::~idSWFTextInstance(this: v10[v9].textInstance);
        textInstance->data = (idSWFTextInstance *)this->textInstanceAllocator.free;
        this->textInstanceAllocator.free = textInstance;
        --this->textInstanceAllocator.active;
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->orphanedTexts.num );
  }
  p_orphanedTexts = &this->orphanedTexts;
  if ( this->orphanedTexts.size < 0 )
  {
    if ( this->orphanedTexts.listStatic == 0 || this->orphanedTexts.listStatic == 2 )
    {
      if ( p_orphanedTexts->list != nullptr )
        idMem::Free(this: &mem, ptr: p_orphanedTexts->list, align: ALIGN_16);
      p_orphanedTexts->list = nullptr;
      this->orphanedTexts.size = 0;
    }
    this->orphanedTexts.num = 0;
  }
  this->orphanedTexts.num = __CFADD__(-this->orphanedTexts.size, this->orphanedTexts.size ^ 0x80000000)
                          ? 0
                          : this->orphanedTexts.size;
  this->c_TextInstanceAdoptions = 0;
  this->c_TextInstanceOrphans = 0;
  this->c_SpriteInstanceAdoptions = 0;
  this->c_SpriteInstanceOrphans = 0;
}


// ========================================================================
// ?Call@idSWFScriptFunction_swapPS3Buttons@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82777FE8
// RVA : 0x00777FE8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_swapPS3Buttons *__fastcall idSWF::idSWFScriptFunction_swapPS3Buttons::Call(
        idSWF::idSWFScriptFunction_swapPS3Buttons *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  this->__vftable = (idSWF::idSWFScriptFunction_swapPS3Buttons_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = 0;
  this->__vftable = (idSWF::idSWFScriptFunction_swapPS3Buttons_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getCVarInteger@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778040
// RVA : 0x00778040
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_getCVarInteger *__fastcall idSWF::idSWFScriptFunction_getCVarInteger::Call(
        idSWF::idSWFScriptFunction_getCVarInteger *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idStr *v5; // r3
  idSWF *v6; // r29
  idStr v8[2]; // [sp+60h] [-40h] BYREF

  v5 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)parms->list);
  v6 = (idSWF *)cvarSystem->GetCVarInteger(this: cvarSystem, a2: v5->data, a3: 0);
  this->__vftable = (idSWF::idSWFScriptFunction_getCVarInteger_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->pThis = v6;
  this->__vftable = (idSWF::idSWFScriptFunction_getCVarInteger_vtbl *)6;
  idStr::FreeData(this: v8);
  return this;
}


// ========================================================================
// __unwind$229592
// EA  : 0x827780C8
// RVA : 0x007780C8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$229593
// EA  : 0x827780F0
// RVA : 0x007780F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229593()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 180));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_isJapanese@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778138
// RVA : 0x00778138
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_isJapanese *__fastcall idSWF::idSWFScriptFunction_isJapanese::Call(
        idSWF::idSWFScriptFunction_isJapanese *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r11
  bool v6; // r31

  valueInteger = sys_langJapanese.valueInteger;
  this->__vftable = (idSWF::idSWFScriptFunction_isJapanese_vtbl *)4;
  v6 = valueInteger != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idSWF::idSWFScriptFunction_isJapanese_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_acos@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778198
// RVA : 0x00778198
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_acos *__fastcall idSWF::idSWFScriptFunction_acos::Call(
        idSWF::idSWFScriptFunction_acos *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  long double v5; // fp2
  double v6; // fp31

  if ( parms->num == 1 )
  {
    *(double *)&v5 = idSWFScriptVar::ToFloat(this: parms->list);
    v6 = idMath::ACos(a: v5);
    this->__vftable = (idSWF::idSWFScriptFunction_acos_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v6;
    this->__vftable = (idSWF::idSWFScriptFunction_acos_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_acos_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_cos@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778210
// RVA : 0x00778210
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_cos *__fastcall idSWF::idSWFScriptFunction_cos::Call(
        idSWF::idSWFScriptFunction_cos *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp31

  if ( parms->num == 1 )
  {
    *(double *)&v5 = idSWFScriptVar::ToFloat(this: parms->list);
    v6 = cos(x: v5);
    v7 = (float)*(double *)&v6;
    this->__vftable = (idSWF::idSWFScriptFunction_cos_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v7;
    this->__vftable = (idSWF::idSWFScriptFunction_cos_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_cos_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_sin@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778288
// RVA : 0x00778288
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_sin *__fastcall idSWF::idSWFScriptFunction_sin::Call(
        idSWF::idSWFScriptFunction_sin *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp31

  if ( parms->num == 1 )
  {
    *(double *)&v5 = idSWFScriptVar::ToFloat(this: parms->list);
    v6 = sin(x: v5);
    v7 = (float)*(double *)&v6;
    this->__vftable = (idSWF::idSWFScriptFunction_sin_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v7;
    this->__vftable = (idSWF::idSWFScriptFunction_sin_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_sin_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_round@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778300
// RVA : 0x00778300
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_round *__fastcall idSWF::idSWFScriptFunction_round::Call(
        idSWF::idSWFScriptFunction_round *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp1
  double v6; // fp31

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToFloat(this: parms->list);
    this->__vftable = (idSWF::idSWFScriptFunction_round_vtbl *)4;
    v6 = (float)((float)v5 + (float)0.5);
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = (idSWF *)(int)v6;
    this->__vftable = (idSWF::idSWFScriptFunction_round_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_round_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_pow@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778388
// RVA : 0x00778388
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_pow *__fastcall idSWF::idSWFScriptFunction_pow::Call(
        idSWF::idSWFScriptFunction_pow *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v6; // fp31
  long double v7; // fp2
  long double v8; // fp4
  long double v9; // fp2
  double v10; // fp31

  if ( parms->num == 2 )
  {
    v6 = idSWFScriptVar::ToFloat(this: parms->list);
    *((double *)&v7 + 1) = idSWFScriptVar::ToFloat(this: parms->list + 1);
    *(double *)&v7 = v6;
    v9 = pow(x: v7, y: v8);
    v10 = (float)*(double *)&v9;
    this->__vftable = (idSWF::idSWFScriptFunction_pow_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v10;
    this->__vftable = (idSWF::idSWFScriptFunction_pow_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_pow_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_sqrt@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778428
// RVA : 0x00778428
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_sqrt *__fastcall idSWF::idSWFScriptFunction_sqrt::Call(
        idSWF::idSWFScriptFunction_sqrt *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp31

  if ( parms->num == 1 )
  {
    v5 = __fsqrts(idSWFScriptVar::ToFloat(this: parms->list));
    this->__vftable = (idSWF::idSWFScriptFunction_sqrt_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v5;
    this->__vftable = (idSWF::idSWFScriptFunction_sqrt_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_sqrt_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_abs@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827784A0
// RVA : 0x007784A0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_abs *__fastcall idSWF::idSWFScriptFunction_abs::Call(
        idSWF::idSWFScriptFunction_abs *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  double v5; // fp31

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToFloat(this: parms->list);
    this->__vftable = (idSWF::idSWFScriptFunction_abs_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = __fabs(v5);
    this->__vftable = (idSWF::idSWFScriptFunction_abs_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_abs_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_rand@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778520
// RVA : 0x00778520
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_rand *__fastcall idSWF::idSWFScriptFunction_rand::Call(
        idSWF::idSWFScriptFunction_rand *this,
        idSWFScriptVar *result,
        __int64 parms)
{
  int v4; // r29
  int seed; // r3
  unsigned int v6; // r11
  idSWFScriptVar *v8; // r29
  double v9; // fp31
  double v10; // fp1
  unsigned int v11; // r11
  __int64 v12; // r5
  double v13; // fp1
  double v14; // fp1
  __int64 v15; // r5

  v4 = parms;
  if ( *(int *)(parms + 4) <= 2 )
  {
    if ( (_S13_16 & 1) != 0 )
    {
      seed = random_3.seed;
    }
    else
    {
      _S13_16 |= 1u;
      seed = Sys_Milliseconds();
      random_3.seed = seed;
    }
    v6 = *(_DWORD *)(v4 + 4);
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        v14 = idSWFScriptVar::ToFloat(this: *(idSWFScriptVar **)v4);
        v11 = 1664525 * random_3.seed + 1013904223;
        LODWORD(v15) = (v11 >> 10) & 0x7FFF;
        v13 = (float)((float)((float)v15 * (float)v14) * (float)0.000030518509);
      }
      else
      {
        if ( v6 >= 3 )
        {
          this->__vftable = (idSWF::idSWFScriptFunction_rand_vtbl *)4;
          return this;
        }
        v8 = *(idSWFScriptVar **)v4;
        v9 = idSWFScriptVar::ToFloat(this: v8 + 1);
        v10 = idSWFScriptVar::ToFloat(this: v8);
        v11 = 1664525 * random_3.seed + 1013904223;
        LODWORD(v12) = (v11 >> 10) & 0x7FFF;
        v13 = (float)((float)((float)((float)v12 * (float)((float)v9 - (float)v10)) * (float)0.000030518509) + (float)v10);
      }
    }
    else
    {
      v11 = 1664525 * seed + 1013904223;
      LODWORD(parms) = (v11 >> 10) & 0x7FFF;
      v13 = (float)((float)parms * (float)0.000030518509);
    }
    random_3.seed = v11;
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: v13);
  }
  else
  {
    this->__vftable = (idSWF::idSWFScriptFunction_rand_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$229927
// EA  : 0x827786AC
// RVA : 0x007786AC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_229927()
{
  _S13_16 &= ~1u;
}


// ========================================================================
// ?Call@idSWFScriptFunction_floor@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827786D0
// RVA : 0x007786D0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_floor *__fastcall idSWF::idSWFScriptFunction_floor::Call(
        idSWF::idSWFScriptFunction_floor *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        int a7)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v9; // r11
  bool v10; // zf
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp31
  int v14; // r10

  if ( parms->num != 1 )
    goto LABEL_8;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v10 = type != SWF_VAR_BOOL, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
  {
    *(double *)&v11 = idSWFScriptVar::ToFloat(this: parms->list);
    v12 = floor(x: v11);
    v13 = (float)*(double *)&v12;
    this->__vftable = (idSWF::idSWFScriptFunction_floor_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v13;
    v14 = 2;
  }
  else
  {
LABEL_8:
    idLib::Warning(fmt: "Invalid parameters specified for floor", result, thisObject, parms, a5, a6, a7, 0);
    v14 = 4;
  }
  this->__vftable = (idSWF::idSWFScriptFunction_floor_vtbl *)v14;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_ceil@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778788
// RVA : 0x00778788
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_ceil *__fastcall idSWF::idSWFScriptFunction_ceil::Call(
        idSWF::idSWFScriptFunction_ceil *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        int a7)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v9; // r11
  bool v10; // zf
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp31
  int v14; // r10

  if ( parms->num != 1 )
    goto LABEL_8;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v10 = type != SWF_VAR_BOOL, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
  {
    *(double *)&v11 = idSWFScriptVar::ToFloat(this: parms->list);
    v12 = ceil(x: v11);
    v13 = (float)*(double *)&v12;
    this->__vftable = (idSWF::idSWFScriptFunction_ceil_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *(float *)&this->pThis = v13;
    v14 = 2;
  }
  else
  {
LABEL_8:
    idLib::Warning(fmt: "Invalid parameters specified for ceil", result, thisObject, parms, a5, a6, a7, 0);
    v14 = 4;
  }
  this->__vftable = (idSWF::idSWFScriptFunction_ceil_vtbl *)v14;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_toUpper@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82778848
// RVA : 0x00778848
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_toUpper *__fastcall idSWF::idSWFScriptFunction_toUpper::Call(
        idSWF::idSWFScriptFunction_toUpper *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v6; // r11
  bool v7; // zf
  idStr *v8; // r3
  const char *String; // r3
  idStr v11; // [sp+60h] [-60h] BYREF
  idStr v12; // [sp+80h] [-40h] BYREF

  if ( parms->num != 1 )
    goto LABEL_7;
  result = parms->list;
  type = parms->list->type;
  if ( type == SWF_VAR_STRING || (v7 = type != SWF_VAR_STRINGID, v6 = 0, !v7) )
    v6 = 1;
  if ( v6 != 0 )
  {
    v8 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v12, (idStr *)result);
    String = idLocalization::GetString(inString: v8->data);
    idStr::idStr(this: &v11, text: String);
    idStr::FreeData(this: &v12);
    idStr::ToUpper(this: &v11);
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: &v11);
    idStr::FreeData(this: &v11);
    return this;
  }
  else
  {
LABEL_7:
    idLib::Warning(fmt: "Invalid parameters specified for toUpper", result, thisObject);
    this->__vftable = (idSWF::idSWFScriptFunction_toUpper_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$230130
// EA  : 0x82778930
// RVA : 0x00778930
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230130()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$230131
// EA  : 0x82778958
// RVA : 0x00778958
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230131()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$230127
// EA  : 0x82778980
// RVA : 0x00778980
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230127()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 212));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_shortcutKeys_clear@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827789D0
// RVA : 0x007789D0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptFunction_shortcutKeys_clear *__fastcall idSWF::idSWFScriptFunction_shortcutKeys_clear::Call(
        idSWF::idSWFScriptFunction_shortcutKeys_clear *this,
        idSWFScriptFunction *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r11
  idSWFScriptObject *v7; // r28
  idSWFScriptVar v9; // [sp+50h] [-120h] BYREF
  idSWFScriptVar v10; // [sp+58h] [-118h] BYREF
  idSWFScriptVar v11; // [sp+60h] [-110h] BYREF
  idSWFScriptVar v12; // [sp+68h] [-108h] BYREF
  idSWFScriptVar v13; // [sp+70h] [-100h] BYREF
  idSWFScriptVar v14; // [sp+78h] [-F8h] BYREF
  idSWFScriptVar v15; // [sp+80h] [-F0h] BYREF
  idSWFScriptVar v16; // [sp+88h] [-E8h] BYREF
  idSWFScriptVar v17; // [sp+90h] [-E0h] BYREF
  idSWFScriptVar v18; // [sp+98h] [-D8h] BYREF
  idSWFScriptVar v19; // [sp+A0h] [-D0h] BYREF
  idSWFScriptVar v20; // [sp+A8h] [-C8h] BYREF
  idSWFScriptVar v21; // [sp+B0h] [-C0h] BYREF
  idSWFScriptVar v22; // [sp+B8h] [-B8h] BYREF
  idSWFScriptVar v23; // [sp+C0h] [-B0h] BYREF
  idSWFScriptVar v24; // [sp+C8h] [-A8h] BYREF
  idSWFScriptVar v25; // [sp+D0h] [-A0h] BYREF
  idSWFScriptVar v26; // [sp+D8h] [-98h] BYREF
  idSWFScriptVar v27; // [sp+E0h] [-90h] BYREF
  idSWFScriptVar v28; // [sp+E8h] [-88h] BYREF
  idSWFScriptVar v29; // [sp+F0h] [-80h] BYREF
  idSWFScriptVar v30; // [sp+F8h] [-78h] BYREF
  idSWFScriptVar v31; // [sp+100h] [-70h] BYREF
  idSWFScriptVar v32; // [sp+108h] [-68h] BYREF
  idSWFScriptVar v33; // [sp+110h] [-60h] BYREF
  idSWFScriptVar v34; // [sp+118h] [-58h] BYREF
  idSWFScriptVar v35[10]; // [sp+120h] [-50h] BYREF

  *(idSWFScriptFunction_vtbl **)&v4.f = result[1].__vftable;
  v9.type = SWF_VAR_STRINGID;
  v7 = *(idSWFScriptObject **)(v4.i + 72);
  idSWFScriptObject::Clear(this: v7);
  idSWFScriptVar::idSWFScriptVar(this: &v9, nf: result);
  idSWFScriptObject::Set(this: v7, name: "clear", value: &v9);
  idSWFScriptVar::Free(this: &v9);
  idSWFScriptVar::idSWFScriptVar(this: &v32, s: "ENTER");
  idSWFScriptObject::Set(this: v7, name: "JOY1", value: &v32);
  idSWFScriptVar::Free(this: &v32);
  idSWFScriptVar::idSWFScriptVar(this: &v12, s: "BACKSPACE");
  idSWFScriptObject::Set(this: v7, name: "JOY2", value: &v12);
  idSWFScriptVar::Free(this: &v12);
  idSWFScriptVar::idSWFScriptVar(this: &v24, s: "START");
  idSWFScriptObject::Set(this: v7, name: "JOY3", value: &v24);
  idSWFScriptVar::Free(this: &v24);
  idSWFScriptVar::idSWFScriptVar(this: &v14, s: "LB");
  idSWFScriptObject::Set(this: v7, name: "JOY5", value: &v14);
  idSWFScriptVar::Free(this: &v14);
  idSWFScriptVar::idSWFScriptVar(this: &v30, s: "RB");
  idSWFScriptObject::Set(this: v7, name: "JOY6", value: &v30);
  idSWFScriptVar::Free(this: &v30);
  idSWFScriptVar::idSWFScriptVar(this: &v16, s: "START");
  idSWFScriptObject::Set(this: v7, name: "JOY9", value: &v16);
  idSWFScriptVar::Free(this: &v16);
  idSWFScriptVar::idSWFScriptVar(this: &v26, s: "BACKSPACE");
  idSWFScriptObject::Set(this: v7, name: "JOY10", value: &v26);
  idSWFScriptVar::Free(this: &v26);
  idSWFScriptVar::idSWFScriptVar(this: &v18, s: "UP");
  idSWFScriptObject::Set(this: v7, name: "JOY_DPAD_UP", value: &v18);
  idSWFScriptVar::Free(this: &v18);
  idSWFScriptVar::idSWFScriptVar(this: &v34, s: "DOWN");
  idSWFScriptObject::Set(this: v7, name: "JOY_DPAD_DOWN", value: &v34);
  idSWFScriptVar::Free(this: &v34);
  idSWFScriptVar::idSWFScriptVar(this: &v20, s: "LEFT");
  idSWFScriptObject::Set(this: v7, name: "JOY_DPAD_LEFT", value: &v20);
  idSWFScriptVar::Free(this: &v20);
  idSWFScriptVar::idSWFScriptVar(this: &v28, s: "RIGHT");
  idSWFScriptObject::Set(this: v7, name: "JOY_DPAD_RIGHT", value: &v28);
  idSWFScriptVar::Free(this: &v28);
  idSWFScriptVar::idSWFScriptVar(this: &v22, s: "STICK1_UP");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK1_UP", value: &v22);
  idSWFScriptVar::Free(this: &v22);
  idSWFScriptVar::idSWFScriptVar(this: &v10, s: "STICK1_DOWN");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK1_DOWN", value: &v10);
  idSWFScriptVar::Free(this: &v10);
  idSWFScriptVar::idSWFScriptVar(this: &v11, s: "STICK1_LEFT");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK1_LEFT", value: &v11);
  idSWFScriptVar::Free(this: &v11);
  idSWFScriptVar::idSWFScriptVar(this: &v13, s: "STICK1_RIGHT");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK1_RIGHT", value: &v13);
  idSWFScriptVar::Free(this: &v13);
  idSWFScriptVar::idSWFScriptVar(this: &v15, s: "STICK2_UP");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK2_UP", value: &v15);
  idSWFScriptVar::Free(this: &v15);
  idSWFScriptVar::idSWFScriptVar(this: &v17, s: "STICK2_DOWN");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK2_DOWN", value: &v17);
  idSWFScriptVar::Free(this: &v17);
  idSWFScriptVar::idSWFScriptVar(this: &v19, s: "STICK2_LEFT");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK2_LEFT", value: &v19);
  idSWFScriptVar::Free(this: &v19);
  idSWFScriptVar::idSWFScriptVar(this: &v21, s: "STICK2_RIGHT");
  idSWFScriptObject::Set(this: v7, name: "JOY_STICK2_RIGHT", value: &v21);
  idSWFScriptVar::Free(this: &v21);
  idSWFScriptVar::idSWFScriptVar(this: &v23, s: "ENTER");
  idSWFScriptObject::Set(this: v7, name: "KP_ENTER", value: &v23);
  idSWFScriptVar::Free(this: &v23);
  idSWFScriptVar::idSWFScriptVar(this: &v25, s: "MWHEEL_DOWN");
  idSWFScriptObject::Set(this: v7, name: "MWHEELDOWN", value: &v25);
  idSWFScriptVar::Free(this: &v25);
  idSWFScriptVar::idSWFScriptVar(this: &v27, s: "MWHEEL_UP");
  idSWFScriptObject::Set(this: v7, name: "MWHEELUP", value: &v27);
  idSWFScriptVar::Free(this: &v27);
  idSWFScriptVar::idSWFScriptVar(this: &v29, s: "LEFT");
  idSWFScriptObject::Set(this: v7, name: "LEFTARROW", value: &v29);
  idSWFScriptVar::Free(this: &v29);
  idSWFScriptVar::idSWFScriptVar(this: &v31, s: "RIGHT");
  idSWFScriptObject::Set(this: v7, name: "RIGHTARROW", value: &v31);
  idSWFScriptVar::Free(this: &v31);
  idSWFScriptVar::idSWFScriptVar(this: &v33, s: "UP");
  idSWFScriptObject::Set(this: v7, name: "UPARROW", value: &v33);
  idSWFScriptVar::Free(this: &v33);
  idSWFScriptVar::idSWFScriptVar(this: v35, s: "DOWN");
  idSWFScriptObject::Set(this: v7, name: "DOWNARROW", value: v35);
  idSWFScriptVar::Free(this: v35);
  this->__vftable = (idSWF::idSWFScriptFunction_shortcutKeys_clear_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$230223
// EA  : 0x82778EB4
// RVA : 0x00778EB4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230223()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$230224
// EA  : 0x82778EDC
// RVA : 0x00778EDC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230224()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 264));
}


// ========================================================================
// __unwind$230225
// EA  : 0x82778F04
// RVA : 0x00778F04
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230225()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 104));
}


// ========================================================================
// __unwind$230226
// EA  : 0x82778F2C
// RVA : 0x00778F2C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230226()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 200));
}


// ========================================================================
// __unwind$230227
// EA  : 0x82778F54
// RVA : 0x00778F54
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230227()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 120));
}


// ========================================================================
// __unwind$230228
// EA  : 0x82778F7C
// RVA : 0x00778F7C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230228()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 248));
}


// ========================================================================
// __unwind$230229
// EA  : 0x82778FA4
// RVA : 0x00778FA4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230229()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 136));
}


// ========================================================================
// __unwind$230230
// EA  : 0x82778FCC
// RVA : 0x00778FCC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230230()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 216));
}


// ========================================================================
// __unwind$230231
// EA  : 0x82778FF4
// RVA : 0x00778FF4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230231()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 152));
}


// ========================================================================
// __unwind$230232
// EA  : 0x8277901C
// RVA : 0x0077901C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230232()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 280));
}


// ========================================================================
// __unwind$230233
// EA  : 0x82779044
// RVA : 0x00779044
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230233()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 168));
}


// ========================================================================
// __unwind$230234
// EA  : 0x8277906C
// RVA : 0x0077906C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230234()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 232));
}


// ========================================================================
// __unwind$230235
// EA  : 0x82779094
// RVA : 0x00779094
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230235()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 184));
}


// ========================================================================
// __unwind$230236
// EA  : 0x827790BC
// RVA : 0x007790BC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230236()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 88));
}


// ========================================================================
// __unwind$230237
// EA  : 0x827790E4
// RVA : 0x007790E4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230237()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$230238
// EA  : 0x8277910C
// RVA : 0x0077910C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230238()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$230239
// EA  : 0x82779134
// RVA : 0x00779134
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230239()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$230240
// EA  : 0x8277915C
// RVA : 0x0077915C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230240()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$230241
// EA  : 0x82779184
// RVA : 0x00779184
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230241()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$230242
// EA  : 0x827791AC
// RVA : 0x007791AC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230242()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$230243
// EA  : 0x827791D4
// RVA : 0x007791D4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230243()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$230244
// EA  : 0x827791FC
// RVA : 0x007791FC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230244()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 208));
}


// ========================================================================
// __unwind$230245
// EA  : 0x82779224
// RVA : 0x00779224
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230245()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 224));
}


// ========================================================================
// __unwind$230246
// EA  : 0x8277924C
// RVA : 0x0077924C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230246()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 240));
}


// ========================================================================
// __unwind$230247
// EA  : 0x82779274
// RVA : 0x00779274
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230247()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 256));
}


// ========================================================================
// __unwind$230248
// EA  : 0x8277929C
// RVA : 0x0077929C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230248()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 272));
}


// ========================================================================
// __unwind$230249
// EA  : 0x827792C4
// RVA : 0x007792C4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_230249()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 288));
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_blackbars@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x827792F0
// RVA : 0x007792F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptNativeVar_blackbars *__fastcall idSWF::idSWFScriptNativeVar_blackbars::Get(
        idSWF::idSWFScriptNativeVar_blackbars *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  char v4; // r30

  v4 = *(_BYTE *)(result->value.i + 52);
  this->__vftable = (idSWF::idSWFScriptNativeVar_blackbars_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v4;
  this->__vftable = (idSWF::idSWFScriptNativeVar_blackbars_vtbl *)5;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_crop@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82779348
// RVA : 0x00779348
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptNativeVar_crop *__fastcall idSWF::idSWFScriptNativeVar_crop::Get(
        idSWF::idSWFScriptNativeVar_crop *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  char v4; // r30

  v4 = *(_BYTE *)(result->value.i + 53);
  this->__vftable = (idSWF::idSWFScriptNativeVar_crop_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v4;
  this->__vftable = (idSWF::idSWFScriptNativeVar_crop_vtbl *)5;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_automaticRescale@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x827793A0
// RVA : 0x007793A0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF::idSWFScriptNativeVar_automaticRescale *__fastcall idSWF::idSWFScriptNativeVar_automaticRescale::Get(
        idSWF::idSWFScriptNativeVar_automaticRescale *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  char v4; // r30

  v4 = *(_BYTE *)(result->value.i + 56);
  this->__vftable = (idSWF::idSWFScriptNativeVar_automaticRescale_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v4;
  this->__vftable = (idSWF::idSWFScriptNativeVar_automaticRescale_vtbl *)5;
  return this;
}


// ========================================================================
// ?AddSpriteOrphan@idSWF@@AAAXPAVidSWFSpriteInstance@@@Z
// EA  : 0x82779508
// RVA : 0x00779508
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::AddSpriteOrphan(idSWF *this, idSWFSpriteInstance *spriteInstance)
{
  int v4; // r10
  int v5; // r11
  idList<idSWF::orphanedSprite_t,72> *p_orphanedSprites; // r30
  int v7; // r3
  idSWF::orphanedSprite_t *list; // r9

  if ( spriteInstance == nullptr )
    goto LABEL_10;
  v4 = 0;
  if ( this->orphanedSprites.num <= 0 )
    goto LABEL_8;
  v5 = 0;
  while ( this->orphanedSprites.list[v5].spriteInstance != spriteInstance )
  {
    ++v4;
    ++v5;
    if ( v4 >= this->orphanedSprites.num )
      goto LABEL_8;
  }
  if ( v4 == -1 )
  {
LABEL_8:
    p_orphanedSprites = &this->orphanedSprites;
    v7 = idList<idSWF::orphanedSprite_t,72>::AllocIndex(this: &this->orphanedSprites);
    if ( v7 >= 0 )
    {
      list = p_orphanedSprites->list;
      ++this->c_SpriteInstanceOrphans;
      list[v7].spriteInstance = spriteInstance;
      p_orphanedSprites->list[v7].wasPlaying = spriteInstance->isPlaying;
    }
  }
  else
  {
LABEL_10:
    idLib::Warning(fmt: "SWF: Sprite Instance is NULL or already exists on the orphan list");
  }
}


// ========================================================================
// ?AddTextOrphan@idSWF@@AAAXPAVidSWFTextInstance@@@Z
// EA  : 0x827795C0
// RVA : 0x007795C0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::AddTextOrphan(idSWF *this, idSWFTextInstance *textInstance)
{
  int v4; // r10
  int v5; // r11
  idList<idSWF::orphanedText_t,72> *p_orphanedTexts; // r30
  int v7; // r3
  idSWF::orphanedText_t *list; // r9

  if ( textInstance == nullptr )
    goto LABEL_10;
  v4 = 0;
  if ( this->orphanedTexts.num <= 0 )
    goto LABEL_8;
  v5 = 0;
  while ( this->orphanedTexts.list[v5].textInstance != textInstance )
  {
    ++v4;
    ++v5;
    if ( v4 >= this->orphanedTexts.num )
      goto LABEL_8;
  }
  if ( v4 == -1 )
  {
LABEL_8:
    p_orphanedTexts = &this->orphanedTexts;
    v7 = idList<idSWF::orphanedText_t,72>::AllocIndex(this: &this->orphanedTexts);
    if ( v7 >= 0 )
    {
      list = p_orphanedTexts->list;
      ++this->c_TextInstanceOrphans;
      list[v7].textInstance = textInstance;
    }
  }
  else
  {
LABEL_10:
    idLib::Warning(fmt: "SWF: Text Instance is NULL or already exists on the orphan list");
  }
}


// ========================================================================
// ??0idSWF@@QAA@PBDPAVidSoundWorld@@_N@Z
// EA  : 0x82779750
// RVA : 0x00779750
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idSWF *__fastcall idSWF::idSWF(idSWF *this, char *filename_, idSoundWorld *soundWorld, bool atlasPurgable_)
{
  idBlockAlloc<idSWFSpriteInstance,16,72> *p_spriteInstanceAllocator; // r23
  idList<idSWF::keyButtonImages_t,72> *p_tooltipButtonImage; // r28
  int num; // r9
  int v10; // r27
  int v11; // r26
  const char *xbImage; // r4
  const char *psImage; // r4
  int v14; // r25
  idSWFSprite *v15; // r3
  idSWFSprite *v16; // r3
  idAtomicString *v17; // r29
  int v18; // r3
  char *v19; // r9
  char *v20; // r10
  int i; // ctr
  int v22; // r11
  idSWFScriptObject *v23; // r3
  idSWFScriptObject *v24; // r28
  idSWFSpriteInstance *v25; // r3
  idSWFScriptObject *v26; // r3
  idAtomicString *v27; // r27
  idSWFScriptObject *shortcutKeys; // r27
  idSWFScriptVar::swfScriptVarValue_t v29; // r27
  idSWFScriptVar::swfScriptVarValue_t v30; // r27
  idSWFScriptVar::swfScriptVarValue_t v31; // r27
  idSWFScriptVar::swfScriptVarValue_t v32; // r27
  idSWFScriptVar::swfScriptVarValue_t v33; // r27
  idSWFScriptVar::swfScriptVarValue_t v34; // r27
  idSWFScriptVar::swfScriptVarValue_t v35; // r25
  idSWFScriptVar::swfScriptVarValue_t v36; // r27
  idSWFScriptVar::swfScriptVarValue_t v37; // r27
  idSWFScriptVar::swfScriptVarValue_t v38; // r27
  idSWFScriptVar::swfScriptVarValue_t v39; // r27
  idSWFScriptObject *scriptObject; // r27
  idSWFScriptVar::swfScriptVarValue_t v41; // r27
  idSWFScriptVar::swfScriptVarValue_t v42; // r27
  idSWFScriptVar::swfScriptVarValue_t v43; // r27
  idSWFScriptVar::swfScriptVarValue_t v44; // r27
  idSWFScriptVar::swfScriptVarValue_t v45; // r27
  idSWFScriptVar::swfScriptVarValue_t v46; // r27
  const idStr *v47; // r29
  idSWFScriptNativeVariable *v48; // r5
  idSWFScriptObject *globals; // r3
  idSWFScriptNativeVariable *v50; // r5
  idSWFScriptObject *v51; // r3
  idSWFScriptNativeVariable *v52; // r5
  idSWFScriptObject *v53; // r3
  idSWFScriptObject *v54; // r3
  idSWFScriptObject *v55; // r3
  int valueInteger; // r29
  int v57; // r11
  idMem *v58; // r29
  idSWFScriptNativeVariable *p_swfScriptVar_automaticRescale; // [sp+50h] [-410h] BYREF
  idSWF::keyButtonImages_t v61; // [sp+60h] [-400h] BYREF
  idAtomicString *p_scriptFunction_strReplace; // [sp+78h] [-3E8h]
  int v63; // [sp+7Ch] [-3E4h]
  bool v64; // [sp+80h] [-3E0h]
  idMem *v65; // [sp+84h] [-3DCh]
  int v66; // [sp+88h] [-3D8h]
  idAtomicString *p_atlasTextureName; // [sp+8Ch] [-3D4h]
  idSWFScriptVar v68; // [sp+90h] [-3D0h] BYREF
  idSWFScriptVar v69; // [sp+98h] [-3C8h] BYREF
  idSWFScriptVar v70; // [sp+A0h] [-3C0h] BYREF
  idSWFScriptVar v71; // [sp+A8h] [-3B8h] BYREF
  idSWFScriptVar v72; // [sp+B0h] [-3B0h] BYREF
  idSWFScriptVar v73; // [sp+B8h] [-3A8h] BYREF
  idSWFScriptVar v74; // [sp+C0h] [-3A0h] BYREF
  idSWFScriptVar v75; // [sp+C8h] [-398h] BYREF
  idSWFScriptVar v76; // [sp+D0h] [-390h] BYREF
  idSWFScriptVar v77; // [sp+D8h] [-388h] BYREF
  idSWFScriptVar v78; // [sp+E0h] [-380h] BYREF
  idSWFScriptVar v79; // [sp+E8h] [-378h] BYREF
  idSWFScriptVar v80; // [sp+F0h] [-370h] BYREF
  idSWFScriptVar v81; // [sp+F8h] [-368h] BYREF
  idSWFScriptVar v82; // [sp+100h] [-360h] BYREF
  idSWFScriptVar v83; // [sp+108h] [-358h] BYREF
  idSWFScriptVar v84; // [sp+110h] [-350h] BYREF
  idSWFScriptVar v85; // [sp+118h] [-348h] BYREF
  idSWFScriptVar v86; // [sp+120h] [-340h] BYREF
  idSWFScriptVar v87; // [sp+128h] [-338h] BYREF
  idSWF::idSWFScriptFunction_Object *p_scriptFunction_Object; // [sp+130h] [-330h]
  idSWFScriptVar v89; // [sp+138h] [-328h] BYREF
  idSWFScriptVar v90; // [sp+140h] [-320h] BYREF
  idSWFScriptVar v91; // [sp+148h] [-318h] BYREF
  idSWFScriptVar v92; // [sp+150h] [-310h] BYREF
  idSWFScriptVar v93; // [sp+158h] [-308h] BYREF
  idSWFScriptVar v94; // [sp+160h] [-300h] BYREF
  idSWFScriptVar v95; // [sp+168h] [-2F8h] BYREF
  idSWFScriptVar v96; // [sp+170h] [-2F0h] BYREF
  idSWFScriptVar v97; // [sp+178h] [-2E8h] BYREF
  idSWFScriptVar v98; // [sp+180h] [-2E0h] BYREF
  idSWFScriptVar v99; // [sp+188h] [-2D8h] BYREF
  idSWF::idSWFScriptFunction_getTruePlatform *p_scriptFunction_getTruePlatform; // [sp+190h] [-2D0h]
  idSWF::idSWFScriptFunction_sqrt *p_scriptFunction_sqrt; // [sp+194h] [-2CCh]
  idSWF::idSWFScriptFunction_abs *p_scriptFunction_abs; // [sp+198h] [-2C8h]
  idSWF::idSWFScriptNativeVar_platform *p_swfScriptVar_platform; // [sp+19Ch] [-2C4h]
  idSWF::idSWFScriptFunction_rand *p_scriptFunction_rand; // [sp+1A0h] [-2C0h]
  idSWF::idSWFScriptFunction_isMultiplayer *p_scriptFunction_isMultiplayer; // [sp+1A4h] [-2BCh]
  idSWF::idSWFScriptFunction_floor *p_scriptFunction_floor; // [sp+1A8h] [-2B8h]
  idSWF::idSWFScriptFunction_deactivate *p_scriptFunction_deactivate; // [sp+1ACh] [-2B4h]
  idSWF::idSWFScriptFunction_getPlatform *p_scriptFunction_getPlatform; // [sp+1B0h] [-2B0h]
  idSWF::idSWFScriptFunction_useInhibit *p_scriptFunction_useInhibit; // [sp+1B4h] [-2ACh]
  idSWF::idSWFScriptFunction_getLocalString *p_scriptFunction_getLocalString; // [sp+1B8h] [-2A8h]
  idSWF::idSWFScriptFunction_playSound *p_scriptFunction_playSound; // [sp+1BCh] [-2A4h]
  idSWF::idSWFScriptFunction_ceil *p_scriptFunction_ceil; // [sp+1C0h] [-2A0h]
  idSWF::idSWFScriptFunction_toUpper *p_scriptFunction_toUpper; // [sp+1C4h] [-29Ch]
  idSWF::idSWFScriptFunction_swapPS3Buttons *p_scriptFunction_swapPS3Buttons; // [sp+1C8h] [-298h]
  idSWF::idSWFScriptFunction_inhibitControl *p_scriptFunction_inhibitControl; // [sp+1CCh] [-294h]
  idSWF::idSWFScriptFunction_stopSounds *p_scriptFunction_stopSounds; // [sp+1D0h] [-290h]
  idSWF::idSWFScriptNativeVar_blackbars *p_swfScriptVar_blackbars; // [sp+1D4h] [-28Ch]
  idSWF::idSWFScriptFunction_precacheSound *p_scriptFunction_precacheSound; // [sp+1D8h] [-288h]
  idSWF::idSWFScriptFunction_shortcutKeys_clear *p_scriptFunction_shortcutKeys_clear; // [sp+1DCh] [-284h]
  idStr v120; // [sp+1E0h] [-280h] BYREF
  idSWFScriptVar v121[2]; // [sp+200h] [-260h] BYREF
  idStr v122; // [sp+210h] [-250h] BYREF
  char v123[256]; // [sp+230h] [-230h] BYREF
  idStaticList<idSWFScriptVar,16> v124[2]; // [sp+330h] [-130h] BYREF

  p_spriteInstanceAllocator = &this->spriteInstanceAllocator;
  this->filename.str = &byte_8200D768;
  p_atlasTextureName = &this->atlasTextureName;
  this->atlasTextureName.str = &byte_8200D768;
  this->spriteInstanceAllocator.blocks = nullptr;
  this->spriteInstanceAllocator.free = nullptr;
  this->spriteInstanceAllocator.total = 0;
  this->spriteInstanceAllocator.active = 0;
  this->spriteInstanceAllocator.allowAllocs = true;
  this->spriteInstanceAllocator.clearAllocs = false;
  this->textInstanceAllocator.blocks = nullptr;
  this->textInstanceAllocator.free = nullptr;
  this->textInstanceAllocator.total = 0;
  this->textInstanceAllocator.active = 0;
  this->textInstanceAllocator.allowAllocs = true;
  this->textInstanceAllocator.clearAllocs = false;
  this->orphanedSprites.list = nullptr;
  this->orphanedSprites.granularity = 0;
  this->orphanedSprites.memTag = 72;
  this->orphanedSprites.listStatic = 0;
  this->orphanedSprites.size = 0;
  this->orphanedSprites.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orphanedSprites);
  this->orphanedTexts.list = nullptr;
  this->orphanedTexts.granularity = 0;
  this->orphanedTexts.memTag = 72;
  this->orphanedTexts.listStatic = 0;
  this->orphanedTexts.size = 0;
  this->orphanedTexts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orphanedTexts);
  p_scriptFunction_shortcutKeys_clear = &this->scriptFunction_shortcutKeys_clear;
  this->scriptFunction_shortcutKeys_clear.pThis = nullptr;
  this->scriptFunction_shortcutKeys_clear.__vftable = (idSWF::idSWFScriptFunction_shortcutKeys_clear_vtbl *)&idSWF::idSWFScriptFunction_shortcutKeys_clear::`vftable';
  p_scriptFunction_deactivate = &this->scriptFunction_deactivate;
  this->scriptFunction_deactivate.pThis = nullptr;
  this->scriptFunction_deactivate.__vftable = (idSWF::idSWFScriptFunction_deactivate_vtbl *)&idSWF::idSWFScriptFunction_deactivate::`vftable';
  p_scriptFunction_inhibitControl = &this->scriptFunction_inhibitControl;
  this->scriptFunction_inhibitControl.pThis = nullptr;
  this->scriptFunction_inhibitControl.__vftable = (idSWF::idSWFScriptFunction_inhibitControl_vtbl *)&idSWF::idSWFScriptFunction_inhibitControl::`vftable';
  p_scriptFunction_useInhibit = &this->scriptFunction_useInhibit;
  this->scriptFunction_useInhibit.pThis = nullptr;
  this->scriptFunction_useInhibit.__vftable = (idSWF::idSWFScriptFunction_useInhibit_vtbl *)&idSWF::idSWFScriptFunction_useInhibit::`vftable';
  p_scriptFunction_precacheSound = &this->scriptFunction_precacheSound;
  this->scriptFunction_precacheSound.pThis = nullptr;
  this->scriptFunction_precacheSound.__vftable = (idSWF::idSWFScriptFunction_precacheSound_vtbl *)&idSWF::idSWFScriptFunction_precacheSound::`vftable';
  p_scriptFunction_playSound = &this->scriptFunction_playSound;
  this->scriptFunction_playSound.pThis = nullptr;
  this->scriptFunction_playSound.__vftable = (idSWF::idSWFScriptFunction_playSound_vtbl *)&idSWF::idSWFScriptFunction_playSound::`vftable';
  p_scriptFunction_stopSounds = &this->scriptFunction_stopSounds;
  this->scriptFunction_stopSounds.pThis = nullptr;
  this->scriptFunction_stopSounds.__vftable = (idSWF::idSWFScriptFunction_stopSounds_vtbl *)&idSWF::idSWFScriptFunction_stopSounds::`vftable';
  p_scriptFunction_getPlatform = &this->scriptFunction_getPlatform;
  this->scriptFunction_getPlatform.pThis = nullptr;
  this->scriptFunction_getPlatform.__vftable = (idSWF::idSWFScriptFunction_getPlatform_vtbl *)&idSWF::idSWFScriptFunction_getPlatform::`vftable';
  p_scriptFunction_getTruePlatform = &this->scriptFunction_getTruePlatform;
  this->scriptFunction_getTruePlatform.pThis = nullptr;
  this->scriptFunction_getTruePlatform.__vftable = (idSWF::idSWFScriptFunction_getTruePlatform_vtbl *)&idSWF::idSWFScriptFunction_getTruePlatform::`vftable';
  p_scriptFunction_getLocalString = &this->scriptFunction_getLocalString;
  this->scriptFunction_getLocalString.pThis = nullptr;
  this->scriptFunction_getLocalString.__vftable = (idSWF::idSWFScriptFunction_getLocalString_vtbl *)&idSWF::idSWFScriptFunction_getLocalString::`vftable';
  p_scriptFunction_isMultiplayer = &this->scriptFunction_isMultiplayer;
  this->scriptFunction_isMultiplayer.pThis = nullptr;
  this->scriptFunction_isMultiplayer.__vftable = (idSWF::idSWFScriptFunction_isMultiplayer_vtbl *)&idSWF::idSWFScriptFunction_isMultiplayer::`vftable';
  p_scriptFunction_swapPS3Buttons = &this->scriptFunction_swapPS3Buttons;
  this->scriptFunction_swapPS3Buttons.pThis = nullptr;
  this->scriptFunction_swapPS3Buttons.__vftable = (idSWF::idSWFScriptFunction_swapPS3Buttons_vtbl *)&idSWF::idSWFScriptFunction_swapPS3Buttons::`vftable';
  this->scriptFunction_getCVarInteger.pThis = nullptr;
  this->scriptFunction_getCVarInteger.__vftable = (idSWF::idSWFScriptFunction_getCVarInteger_vtbl *)&idSWF::idSWFScriptFunction_getCVarInteger::`vftable';
  this->scriptFunction_setCVarInteger.pThis = nullptr;
  this->scriptFunction_setCVarInteger.__vftable = (idSWF::idSWFScriptFunction_setCVarInteger_vtbl *)&idSWF::idSWFScriptFunction_setCVarInteger::`vftable';
  this->scriptFunction_strReplace.pThis = nullptr;
  this->scriptFunction_strReplace.__vftable = (idSWF::idSWFScriptFunction_strReplace_vtbl *)&idSWF::idSWFScriptFunction_strReplace::`vftable';
  this->scriptFunction_isJapanese.pThis = nullptr;
  this->scriptFunction_isJapanese.__vftable = (idSWF::idSWFScriptFunction_isJapanese_vtbl *)&idSWF::idSWFScriptFunction_isJapanese::`vftable';
  this->scriptFunction_acos.pThis = nullptr;
  this->scriptFunction_acos.__vftable = (idSWF::idSWFScriptFunction_acos_vtbl *)&idSWF::idSWFScriptFunction_acos::`vftable';
  this->scriptFunction_cos.pThis = nullptr;
  this->scriptFunction_cos.__vftable = (idSWF::idSWFScriptFunction_cos_vtbl *)&idSWF::idSWFScriptFunction_cos::`vftable';
  this->scriptFunction_sin.pThis = nullptr;
  this->scriptFunction_sin.__vftable = (idSWF::idSWFScriptFunction_sin_vtbl *)&idSWF::idSWFScriptFunction_sin::`vftable';
  this->scriptFunction_round.pThis = nullptr;
  this->scriptFunction_round.__vftable = (idSWF::idSWFScriptFunction_round_vtbl *)&idSWF::idSWFScriptFunction_round::`vftable';
  this->scriptFunction_pow.pThis = nullptr;
  this->scriptFunction_pow.__vftable = (idSWF::idSWFScriptFunction_pow_vtbl *)&idSWF::idSWFScriptFunction_pow::`vftable';
  p_scriptFunction_sqrt = &this->scriptFunction_sqrt;
  this->scriptFunction_sqrt.pThis = nullptr;
  this->scriptFunction_sqrt.__vftable = (idSWF::idSWFScriptFunction_sqrt_vtbl *)&idSWF::idSWFScriptFunction_sqrt::`vftable';
  p_scriptFunction_abs = &this->scriptFunction_abs;
  this->scriptFunction_abs.pThis = nullptr;
  this->scriptFunction_abs.__vftable = (idSWF::idSWFScriptFunction_abs_vtbl *)&idSWF::idSWFScriptFunction_abs::`vftable';
  p_scriptFunction_rand = &this->scriptFunction_rand;
  this->scriptFunction_rand.pThis = nullptr;
  this->scriptFunction_rand.__vftable = (idSWF::idSWFScriptFunction_rand_vtbl *)&idSWF::idSWFScriptFunction_rand::`vftable';
  p_scriptFunction_floor = &this->scriptFunction_floor;
  this->scriptFunction_floor.pThis = nullptr;
  this->scriptFunction_floor.__vftable = (idSWF::idSWFScriptFunction_floor_vtbl *)&idSWF::idSWFScriptFunction_floor::`vftable';
  p_scriptFunction_ceil = &this->scriptFunction_ceil;
  this->scriptFunction_ceil.pThis = nullptr;
  this->scriptFunction_ceil.__vftable = (idSWF::idSWFScriptFunction_ceil_vtbl *)&idSWF::idSWFScriptFunction_ceil::`vftable';
  p_scriptFunction_toUpper = &this->scriptFunction_toUpper;
  this->scriptFunction_toUpper.pThis = nullptr;
  this->scriptFunction_toUpper.__vftable = (idSWF::idSWFScriptFunction_toUpper_vtbl *)&idSWF::idSWFScriptFunction_toUpper::`vftable';
  p_swfScriptVar_platform = &this->swfScriptVar_platform;
  this->swfScriptVar_platform.pThis = nullptr;
  this->swfScriptVar_platform.__vftable = (idSWF::idSWFScriptNativeVar_platform_vtbl *)&idSWF::idSWFScriptNativeVar_platform::`vftable';
  p_swfScriptVar_blackbars = &this->swfScriptVar_blackbars;
  this->swfScriptVar_blackbars.pThis = nullptr;
  this->swfScriptVar_blackbars.__vftable = (idSWF::idSWFScriptNativeVar_blackbars_vtbl *)&idSWF::idSWFScriptNativeVar_blackbars::`vftable';
  this->swfScriptVar_crop.pThis = nullptr;
  this->swfScriptVar_crop.__vftable = (idSWF::idSWFScriptNativeVar_crop_vtbl *)&idSWF::idSWFScriptNativeVar_crop::`vftable';
  p_swfScriptVar_automaticRescale = &this->swfScriptVar_automaticRescale;
  this->swfScriptVar_automaticRescale.pThis = nullptr;
  this->swfScriptVar_automaticRescale.__vftable = (idSWF::idSWFScriptNativeVar_automaticRescale_vtbl *)&idSWF::idSWFScriptNativeVar_automaticRescale::`vftable';
  p_scriptFunction_Object = &this->scriptFunction_Object;
  idSWF::idSWFScriptFunction_Object::idSWFScriptFunction_Object(this: &this->scriptFunction_Object);
  this->dictionary.granularity = 0;
  this->dictionary.memTag = 72;
  this->dictionary.listStatic = 0;
  this->dictionary.list = nullptr;
  this->dictionary.size = 0;
  this->dictionary.num = 0;
  this->tooltipButtonImage.list = nullptr;
  this->tooltipButtonImage.granularity = 0;
  p_tooltipButtonImage = &this->tooltipButtonImage;
  this->tooltipButtonImage.memTag = 72;
  this->tooltipButtonImage.listStatic = 0;
  this->tooltipButtonImage.size = 0;
  this->tooltipButtonImage.num = 0;
  v65 = (idMem *)&this->tooltipButtonImage;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tooltipButtonImage);
  this->tooltipIconList.list = nullptr;
  this->tooltipIconList.granularity = 0;
  this->tooltipIconList.memTag = 72;
  this->tooltipIconList.listStatic = 0;
  this->tooltipIconList.size = 0;
  this->tooltipIconList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tooltipIconList);
  idSWF::idDecompressJPEG::idDecompressJPEG(this: &this->jpeg);
  this->packImages.list = nullptr;
  this->packImages.granularity = 0;
  this->packImages.memTag = 72;
  this->packImages.listStatic = 0;
  this->packImages.size = 0;
  this->packImages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->packImages);
  this->atlasPurgable = atlasPurgable_;
  this->atlasImage = nullptr;
  this->atlasMaterial = nullptr;
  this->atlasFile = nullptr;
  this->atlasWidth = 0;
  this->swfScale = 1.0;
  this->atlasHeight = 0;
  v64 = idLib::PushWarningInfo(type: "swf", name: filename_);
  this->guiSolid = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                         this: &idMaterial::resourceList,
                                         name: "guiSolid",
                                         makeDefault: true);
  this->guiStencilIncr = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                               this: &idMaterial::resourceList,
                                               name: "guiStencilIncr",
                                               makeDefault: true);
  this->guiStencilDecr = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                               this: &idMaterial::resourceList,
                                               name: "guiStencilDecr",
                                               makeDefault: true);
  this->guiCursor_arrow = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                this: &idMaterial::resourceList,
                                                name: "textures/guis/default/guicursor_arrow",
                                                makeDefault: true);
  this->guiCursor_hand = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                               this: &idMaterial::resourceList,
                                               name: "textures/guis/default/guicursor_hand",
                                               makeDefault: true);
  this->white = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                      this: &idMaterial::resourceList,
                                      name: "_white",
                                      makeDefault: true);
  v61.baseline = 0;
  v61.width = 48;
  v61.key = "<DPAD>";
  v61.xbImage = "textures/guis/controller/xb360/360_dpad";
  v61.psImage = "textures/guis/controller/ps3/ps3_dpad";
  v61.height = 48;
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  v61.xbImage = "textures/guis/controller/xb360/360_dpad_up";
  v61.psImage = "textures/guis/controller/ps3/ps3_dpad_up";
  v61.key = "<JOY_DPAD_UP>";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  v61.xbImage = "textures/guis/controller/xb360/360_dpad_right";
  v61.key = "<JOY_DPAD_RIGHT>";
  v61.psImage = "textures/guis/controller/ps3/ps3_dpad_right";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.key = "<JOY_DPAD_DOWN>";
  v61.xbImage = "textures/guis/controller/xb360/360_dpad_down";
  v61.psImage = "textures/guis/controller/ps3/ps3_dpad_down";
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  v61.key = "<JOY_DPAD_LEFT>";
  v61.xbImage = "textures/guis/controller/xb360/360_dpad_left";
  v61.psImage = "textures/guis/controller/ps3/ps3_dpad_left";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.key = "<JOY1>";
  v61.xbImage = "textures/guis/controller/xb360/360_a_alt";
  v61.width = 32;
  v61.psImage = "textures/guis/controller/ps3/ps3_x_alt";
  v61.height = 32;
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 32;
  v61.height = 32;
  v61.baseline = 0;
  v61.key = "<JOY2>";
  v61.xbImage = "textures/guis/controller/xb360/360_b_alt";
  v61.psImage = "textures/guis/controller/ps3/ps3_circle";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 32;
  v61.height = 32;
  v61.baseline = 0;
  v61.key = "<JOY3>";
  v61.xbImage = "textures/guis/controller/xb360/360_x_alt";
  v61.psImage = "textures/guis/controller/ps3/ps3_square";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 32;
  v61.height = 32;
  v61.baseline = 0;
  v61.key = "<JOY4>";
  v61.xbImage = "textures/guis/controller/xb360/360_y_alt";
  v61.psImage = "textures/guis/controller/ps3/ps3_triangle";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  v61.key = "<JOY5>";
  v61.xbImage = "textures/guis/controller/xb360/360_lb";
  v61.psImage = "textures/guis/controller/ps3/ps3_l1";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 48;
  v61.height = 48;
  v61.baseline = 0;
  v61.key = "<JOY6>";
  v61.xbImage = "textures/guis/controller/xb360/360_rb";
  v61.psImage = "textures/guis/controller/ps3/ps3_r1";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.key = "<JOY10>";
  v61.xbImage = "textures/guis/controller/xb360/360_back";
  v61.width = 64;
  v61.psImage = "textures/guis/controller/ps3/ps3_select";
  v61.height = 64;
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 64;
  v61.height = 64;
  v61.baseline = 0;
  v61.key = "<JOY7>";
  v61.xbImage = "textures/guis/controller/xb360/360_l3";
  v61.psImage = "textures/guis/controller/ps3/ps3_l3";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.width = 64;
  v61.height = 64;
  v61.baseline = 0;
  v61.key = "<JOY8>";
  v61.xbImage = "textures/guis/controller/xb360/360_r3";
  v61.psImage = "textures/guis/controller/ps3/ps3_r3";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.width = 48;
  v61.height = 48;
  v61.key = "<LEFT_STICK>";
  v61.xbImage = "textures/guis/controller/xb360/360_ls";
  v61.psImage = "textures/guis/controller/ps3/ps3_ls";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.width = 48;
  v61.height = 48;
  v61.key = "<RIGHT_STICK>";
  v61.xbImage = "textures/guis/controller/xb360/360_rs";
  v61.psImage = "textures/guis/controller/ps3/ps3_rs";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.width = 48;
  v61.height = 48;
  v61.key = "<JOY_TRIGGER2>";
  v61.xbImage = "textures/guis/controller/xb360/360_rt";
  v61.psImage = "textures/guis/controller/ps3/ps3_r2";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  v61.baseline = 0;
  v61.width = 48;
  v61.height = 48;
  v61.key = "<JOY_TRIGGER1>";
  v61.xbImage = "textures/guis/controller/xb360/360_lt";
  v61.psImage = "textures/guis/controller/ps3/ps3_l2";
  idList<idSWF::keyButtonImages_t,72>::Append(this: &this->tooltipButtonImage, obj: &v61);
  num = this->tooltipButtonImage.num;
  v10 = 0;
  v66 = -2088566784;
  if ( num > 0 )
  {
    v11 = 0;
    v65 = (idMem *)&com_production;
    do
    {
      xbImage = p_tooltipButtonImage->list[v11].xbImage;
      if ( xbImage != nullptr && *xbImage != 0 )
      {
        p_scriptFunction_strReplace = (idAtomicString *)p_tooltipButtonImage->list[v11].xbImage;
        idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: xbImage, makeDefault: true);
        if ( *(_DWORD *)(v66 - 18116) == 1 || *(_DWORD *)&v65[32] != 0 )
        {
          psImage = p_tooltipButtonImage->list[v11].psImage;
          if ( psImage != nullptr )
            idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: psImage, makeDefault: true);
        }
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->tooltipButtonImage.num );
  }
  idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: "textures/gui/load_image", makeDefault: true);
  this->frameRate = 0;
  this->lastRenderTime = 0;
  this->userDeviceNumber = 0;
  this->isActive = false;
  this->inhibitControl = false;
  this->renderBorder = 0.0;
  this->useInhibtControl = true;
  this->frameWidth = 0.0;
  this->crop = false;
  this->frameHeight = 0.0;
  this->blackbars = false;
  this->paused = false;
  this->hasHitObject = false;
  this->automaticRescale = true;
  this->useMouse = true;
  this->mouseEnabled = false;
  this->mouseObject = nullptr;
  this->hoverObject = nullptr;
  this->soundEmitter = nullptr;
  this->c_TextInstanceAdoptions = 0;
  this->c_TextInstanceOrphans = 0;
  this->c_SpriteInstanceAdoptions = 0;
  this->c_SpriteInstanceOrphans = 0;
  idStr::idStr(this: &v120, text: filename_);
  if ( idStr::Cmpn(s1: filename_, s2: "swf/", n: 4) != 0 )
  {
    idStr::operator=(this: &v120, text: "swf/");
    idStr::Append(this: &v120, text: filename_);
  }
  else
  {
    idStr::operator=(this: &v120, text: filename_);
  }
  idStr::MakeNameCanonical(this: &v120);
  idStr::StripFileExtension(this: &v120);
  idStr::Append(this: &v120, text: ".swf");
  idAtomicString::Set(this: &this->filename, str_: v120.data);
  v14 = v66;
  if ( *(_DWORD *)(v66 - 18116) != 0 )
    this->timestamp = 1;
  else
    this->timestamp = fileSystem->GetTimestamp(this: fileSystem, a2: this->filename.str, a3: false);
  v65 = &mem;
  v15 = (idSWFSprite *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x4Cu,
                         tag: TAG_SWF,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  p_scriptFunction_strReplace = (idAtomicString *)v15;
  if ( v15 != nullptr )
    v16 = idSWFSprite::idSWFSprite(this: v15, _swf: this);
  else
    v16 = nullptr;
  this->mainsprite = v16;
  this->mainspriteInstance = nullptr;
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bimage",
    a4: this->filename.str,
    a5: v123,
    a6: 256);
  v17 = p_atlasTextureName;
  p_scriptFunction_strReplace = p_atlasTextureName;
  idAtomicString::Set(this: p_atlasTextureName, str_: v123);
  v18 = idStr::Find(searchIn: v123, searchFor: ".bimage", casesensitive: true, start: 0, end: -1);
  v19 = "";
  v20 = &v123[v18 - 1];
  for ( i = 6; i != 0; --i )
    *++v20 = *++v19;
  v22 = *(_DWORD *)(v14 - 18116);
  p_atlasTextureName = (idAtomicString *)&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  if ( v22 == 2 || v22 == 3 )
  {
    resourceManager->SetFileHook(this: resourceManager);
    v22 = *(_DWORD *)(v14 - 18116);
  }
  if ( swf_loadBinary.valueInteger != 0 )
  {
    if ( v22 == 2 )
    {
      idSWF::LoadBinary(this, bfilename: v123);
    }
    else if ( (!fileSystem->FileExists(this: fileSystem, a2: v123, a3: false)
            || (unsigned __int8)idSWF::LoadBinary(this, bfilename: v123) == 0)
           && (unsigned __int8)idSWF::LoadSWF(this, fullpath: this->filename.str) != 0 )
    {
      idSWF::WriteBinary(this, bfilename: v123);
    }
  }
  else
  {
    idSWF::LoadSWF(this, fullpath: this->filename.str);
  }
  idSWF::CreateAltasImageAndMaterial(this);
  if ( resourceManager->GetBuildPlatforms(this: resourceManager) != 0 )
  {
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 15u);
    idResourceList::Load(this: &idFileResource::resourceList, name: v123, makeDefault: true, skipStaleCheck: false);
    idResourceList::Load(
      this: &idFileResource::resourceList,
      name: (char *)v17->str,
      makeDefault: true,
      skipStaleCheck: false);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  }
  v23 = idSWFScriptObject::Alloc();
  this->globals = v23;
  v24 = v23;
  v68.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v68);
  if ( v24 != nullptr )
  {
    v68.value.i = (int)v24;
    v68.type = SWF_VAR_OBJECT;
    ++v24->refCount;
  }
  else
  {
    v68.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: this->globals, name: "_global", value: &v68);
  idSWFScriptVar::Free(this: &v68);
  v71.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v71);
  if ( p_scriptFunction_Object != nullptr )
  {
    v71.value.i = (int)p_scriptFunction_Object;
    v71.type = SWF_VAR_FUNCTION;
    p_scriptFunction_Object->AddRef(this: p_scriptFunction_Object);
  }
  else
  {
    v71.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: this->globals, name: "Object", value: &v71);
  idSWFScriptVar::Free(this: &v71);
  v25 = (idSWFSpriteInstance *)idBlockAlloc<idSWFSpriteInstance,16,72>::Alloc(this: p_spriteInstanceAllocator);
  this->mainspriteInstance = v25;
  idSWFSpriteInstance::Init(this: v25, _sprite: this->mainsprite, _parent: nullptr, _name: "_root", _depth: 0);
  v26 = idSWFScriptObject::Alloc();
  v27 = (idAtomicString *)p_scriptFunction_shortcutKeys_clear;
  this->shortcutKeys = v26;
  v27[1].str = (const char *)this;
  p_scriptFunction_strReplace = v27;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: v124);
  (*((void (__fastcall **)(idSWFScriptVar *, idAtomicString *, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))v27->str
   + 1))(
    a1: v121,
    a2: v27,
    a3: this->shortcutKeys,
    a4: v124);
  idSWFScriptVar::Free(this: v121);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v124);
  v70.type = SWF_VAR_UNDEF;
  shortcutKeys = this->shortcutKeys;
  idSWFScriptVar::Free(this: &v70);
  if ( shortcutKeys != nullptr )
  {
    v70.value.i = (int)shortcutKeys;
    v70.type = SWF_VAR_OBJECT;
    ++shortcutKeys->refCount;
  }
  else
  {
    v70.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: this->globals, name: "shortcutKeys", value: &v70);
  idSWFScriptVar::Free(this: &v70);
  v29.i = (int)p_scriptFunction_deactivate;
  v72.type = SWF_VAR_UNDEF;
  p_scriptFunction_deactivate->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v29.i;
  idSWFScriptVar::Free(this: &v72);
  v72.value = v29;
  v72.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v29.i + 8))(a1: v29.i);
  idSWFScriptObject::Set(this: this->globals, name: "deactivate", value: &v72);
  idSWFScriptVar::Free(this: &v72);
  v30.i = (int)p_scriptFunction_inhibitControl;
  v78.type = SWF_VAR_UNDEF;
  p_scriptFunction_inhibitControl->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v30.i;
  idSWFScriptVar::Free(this: &v78);
  v78.value = v30;
  v78.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v30.i + 8))(a1: v30.i);
  idSWFScriptObject::Set(this: this->globals, name: "inhibitControl", value: &v78);
  idSWFScriptVar::Free(this: &v78);
  v31.i = (int)p_scriptFunction_useInhibit;
  v94.type = SWF_VAR_UNDEF;
  p_scriptFunction_useInhibit->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v31.i;
  idSWFScriptVar::Free(this: &v94);
  v94.value = v31;
  v94.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v31.i + 8))(a1: v31.i);
  idSWFScriptObject::Set(this: this->globals, name: "useInhibit", value: &v94);
  idSWFScriptVar::Free(this: &v94);
  v32.i = (int)p_scriptFunction_precacheSound;
  p_scriptFunction_precacheSound->pThis = this;
  v80.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)v32.i;
  idSWFScriptVar::Free(this: &v80);
  v80.value = v32;
  v80.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v32.i + 8))(a1: v32.i);
  idSWFScriptObject::Set(this: this->globals, name: "precacheSound", value: &v80);
  idSWFScriptVar::Free(this: &v80);
  v33.i = (int)p_scriptFunction_playSound;
  v90.type = SWF_VAR_UNDEF;
  p_scriptFunction_playSound->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v33.i;
  idSWFScriptVar::Free(this: &v90);
  v90.value = v33;
  v90.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v33.i + 8))(a1: v33.i);
  idSWFScriptObject::Set(this: this->globals, name: "playSound", value: &v90);
  idSWFScriptVar::Free(this: &v90);
  v34.i = (int)p_scriptFunction_stopSounds;
  v82.type = SWF_VAR_UNDEF;
  p_scriptFunction_stopSounds->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v34.i;
  idSWFScriptVar::Free(this: &v82);
  v82.value = v34;
  v82.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v34.i + 8))(a1: v34.i);
  idSWFScriptObject::Set(this: this->globals, name: "stopSounds", value: &v82);
  idSWFScriptVar::Free(this: &v82);
  v35.i = (int)p_scriptFunction_getPlatform;
  v73.type = SWF_VAR_UNDEF;
  p_scriptFunction_getPlatform->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v35.i;
  idSWFScriptVar::Free(this: &v73);
  v73.type = SWF_VAR_FUNCTION;
  v73.value = v35;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v35.i + 8))(a1: v35.i);
  idSWFScriptObject::Set(this: this->globals, name: "getPlatform", value: &v73);
  idSWFScriptVar::Free(this: &v73);
  v36.i = (int)p_scriptFunction_getTruePlatform;
  v74.type = SWF_VAR_UNDEF;
  p_scriptFunction_getTruePlatform->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v36.i;
  idSWFScriptVar::Free(this: &v74);
  v74.value = v36;
  v74.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v36.i + 8))(a1: v36.i);
  idSWFScriptObject::Set(this: this->globals, name: "getTruePlatform", value: &v74);
  idSWFScriptVar::Free(this: &v74);
  v37.i = (int)p_scriptFunction_getLocalString;
  v98.type = SWF_VAR_UNDEF;
  p_scriptFunction_getLocalString->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v37.i;
  idSWFScriptVar::Free(this: &v98);
  v98.value = v37;
  v98.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v37.i + 8))(a1: v37.i);
  idSWFScriptObject::Set(this: this->globals, name: "getLocalString", value: &v98);
  idSWFScriptVar::Free(this: &v98);
  v38.i = (int)p_scriptFunction_isMultiplayer;
  v84.type = SWF_VAR_UNDEF;
  p_scriptFunction_isMultiplayer->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v38.i;
  idSWFScriptVar::Free(this: &v84);
  v84.value = v38;
  v84.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v38.i + 8))(a1: v38.i);
  idSWFScriptObject::Set(this: this->globals, name: "isMultiplayer", value: &v84);
  idSWFScriptVar::Free(this: &v84);
  v39.i = (int)p_scriptFunction_swapPS3Buttons;
  p_scriptFunction_swapPS3Buttons->pThis = this;
  v92.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)v39.i;
  idSWFScriptVar::Free(this: &v92);
  v92.value = v39;
  v92.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v39.i + 8))(a1: v39.i);
  idSWFScriptObject::Set(this: this->globals, name: "swapPS3Buttons", value: &v92);
  idSWFScriptVar::Free(this: &v92);
  scriptObject = this->mainspriteInstance->scriptObject;
  v69.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v69);
  if ( scriptObject != nullptr )
  {
    v69.value.i = (int)scriptObject;
    v69.type = SWF_VAR_OBJECT;
    ++scriptObject->refCount;
  }
  else
  {
    v69.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: this->globals, name: "_root", value: &v69);
  idSWFScriptVar::Free(this: &v69);
  this->scriptFunction_strReplace.pThis = this;
  v86.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_strReplace;
  idSWFScriptVar::Free(this: &v86);
  v86.value.i = (int)&this->scriptFunction_strReplace;
  v86.type = SWF_VAR_FUNCTION;
  this->scriptFunction_strReplace.AddRef(this: &this->scriptFunction_strReplace);
  idSWFScriptObject::Set(this: this->globals, name: "strReplace", value: &v86);
  idSWFScriptVar::Free(this: &v86);
  this->scriptFunction_getCVarInteger.pThis = this;
  v96.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_getCVarInteger;
  idSWFScriptVar::Free(this: &v96);
  v96.value.i = (int)&this->scriptFunction_getCVarInteger;
  v96.type = SWF_VAR_FUNCTION;
  this->scriptFunction_getCVarInteger.AddRef(this: &this->scriptFunction_getCVarInteger);
  idSWFScriptObject::Set(this: this->globals, name: "getCVarInteger", value: &v96);
  idSWFScriptVar::Free(this: &v96);
  this->scriptFunction_setCVarInteger.pThis = this;
  v75.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_setCVarInteger;
  idSWFScriptVar::Free(this: &v75);
  v75.value.i = (int)&this->scriptFunction_setCVarInteger;
  v75.type = SWF_VAR_FUNCTION;
  this->scriptFunction_setCVarInteger.AddRef(this: &this->scriptFunction_setCVarInteger);
  idSWFScriptObject::Set(this: this->globals, name: "setCVarInteger", value: &v75);
  idSWFScriptVar::Free(this: &v75);
  this->scriptFunction_isJapanese.pThis = this;
  v77.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_isJapanese;
  idSWFScriptVar::Free(this: &v77);
  v77.value.i = (int)&this->scriptFunction_isJapanese;
  v77.type = SWF_VAR_FUNCTION;
  this->scriptFunction_isJapanese.AddRef(this: &this->scriptFunction_isJapanese);
  idSWFScriptObject::Set(this: this->globals, name: "isJapanese", value: &v77);
  idSWFScriptVar::Free(this: &v77);
  this->scriptFunction_acos.pThis = this;
  v79.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_acos;
  idSWFScriptVar::Free(this: &v79);
  v79.value.i = (int)&this->scriptFunction_acos;
  v79.type = SWF_VAR_FUNCTION;
  this->scriptFunction_acos.AddRef(this: &this->scriptFunction_acos);
  idSWFScriptObject::Set(this: this->globals, name: "acos", value: &v79);
  idSWFScriptVar::Free(this: &v79);
  this->scriptFunction_cos.pThis = this;
  v81.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_cos;
  idSWFScriptVar::Free(this: &v81);
  v81.value.i = (int)&this->scriptFunction_cos;
  v81.type = SWF_VAR_FUNCTION;
  this->scriptFunction_cos.AddRef(this: &this->scriptFunction_cos);
  idSWFScriptObject::Set(this: this->globals, name: "cos", value: &v81);
  idSWFScriptVar::Free(this: &v81);
  this->scriptFunction_sin.pThis = this;
  v83.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_sin;
  idSWFScriptVar::Free(this: &v83);
  v83.value.i = (int)&this->scriptFunction_sin;
  v83.type = SWF_VAR_FUNCTION;
  this->scriptFunction_sin.AddRef(this: &this->scriptFunction_sin);
  idSWFScriptObject::Set(this: this->globals, name: "sin", value: &v83);
  idSWFScriptVar::Free(this: &v83);
  this->scriptFunction_round.pThis = this;
  v85.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_round;
  idSWFScriptVar::Free(this: &v85);
  v85.value.i = (int)&this->scriptFunction_round;
  v85.type = SWF_VAR_FUNCTION;
  this->scriptFunction_round.AddRef(this: &this->scriptFunction_round);
  idSWFScriptObject::Set(this: this->globals, name: "round", value: &v85);
  idSWFScriptVar::Free(this: &v85);
  this->scriptFunction_pow.pThis = this;
  v87.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)&this->scriptFunction_pow;
  idSWFScriptVar::Free(this: &v87);
  v87.value.i = (int)&this->scriptFunction_pow;
  v87.type = SWF_VAR_FUNCTION;
  this->scriptFunction_pow.AddRef(this: &this->scriptFunction_pow);
  idSWFScriptObject::Set(this: this->globals, name: "pow", value: &v87);
  idSWFScriptVar::Free(this: &v87);
  v41.i = (int)p_scriptFunction_sqrt;
  v89.type = SWF_VAR_UNDEF;
  p_scriptFunction_sqrt->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v41.i;
  idSWFScriptVar::Free(this: &v89);
  v89.value = v41;
  v89.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v41.i + 8))(a1: v41.i);
  idSWFScriptObject::Set(this: this->globals, name: "sqrt", value: &v89);
  idSWFScriptVar::Free(this: &v89);
  v42.i = (int)p_scriptFunction_abs;
  v91.type = SWF_VAR_UNDEF;
  p_scriptFunction_abs->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v42.i;
  idSWFScriptVar::Free(this: &v91);
  v91.value = v42;
  v91.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v42.i + 8))(a1: v42.i);
  idSWFScriptObject::Set(this: this->globals, name: "abs", value: &v91);
  idSWFScriptVar::Free(this: &v91);
  v43.i = (int)p_scriptFunction_rand;
  v93.type = SWF_VAR_UNDEF;
  p_scriptFunction_rand->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v43.i;
  idSWFScriptVar::Free(this: &v93);
  v93.value = v43;
  v93.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v43.i + 8))(a1: v43.i);
  idSWFScriptObject::Set(this: this->globals, name: "rand", value: &v93);
  idSWFScriptVar::Free(this: &v93);
  v44.i = (int)p_scriptFunction_floor;
  v95.type = SWF_VAR_UNDEF;
  p_scriptFunction_floor->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v44.i;
  idSWFScriptVar::Free(this: &v95);
  v95.value = v44;
  v95.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v44.i + 8))(a1: v44.i);
  idSWFScriptObject::Set(this: this->globals, name: "floor", value: &v95);
  idSWFScriptVar::Free(this: &v95);
  v45.i = (int)p_scriptFunction_ceil;
  v97.type = SWF_VAR_UNDEF;
  p_scriptFunction_ceil->pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)v45.i;
  idSWFScriptVar::Free(this: &v97);
  v97.value = v45;
  v97.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v45.i + 8))(a1: v45.i);
  idSWFScriptObject::Set(this: this->globals, name: "ceil", value: &v97);
  idSWFScriptVar::Free(this: &v97);
  v46.i = (int)p_scriptFunction_toUpper;
  p_scriptFunction_toUpper->pThis = this;
  v99.type = SWF_VAR_UNDEF;
  p_scriptFunction_strReplace = (idAtomicString *)v46.i;
  idSWFScriptVar::Free(this: &v99);
  v99.value = v46;
  v99.type = SWF_VAR_FUNCTION;
  (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v46.i + 8))(a1: v46.i);
  idSWFScriptObject::Set(this: this->globals, name: "toUpper", value: &v99);
  idSWFScriptVar::Free(this: &v99);
  v76.type = SWF_VAR_UNDEF;
  v47 = idStr::idStr(this: &v122, text: com_version.valueString.data);
  idSWFScriptVar::Free(this: &v76);
  v76.type = SWF_VAR_STRING;
  v76.value.i = (int)idSWFScriptString::Alloc(s: v47);
  idStr::FreeData(this: &v122);
  idSWFScriptObject::Set(this: this->globals, name: "buildversion", value: &v76);
  idSWFScriptVar::Free(this: &v76);
  v48 = p_swfScriptVar_platform;
  p_swfScriptVar_platform->pThis = (idSWF::idSWFScriptFunction_getPlatform *)v35.i;
  globals = this->globals;
  p_scriptFunction_strReplace = (idAtomicString *)v48;
  idSWFScriptObject::SetNative(this: globals, name: "platform", native: v48);
  v50 = p_swfScriptVar_blackbars;
  p_swfScriptVar_blackbars->pThis = this;
  v51 = this->globals;
  p_scriptFunction_strReplace = (idAtomicString *)v50;
  idSWFScriptObject::SetNative(this: v51, name: "blackbars", native: v50);
  v52 = p_swfScriptVar_automaticRescale;
  p_swfScriptVar_automaticRescale[1].__vftable = (idSWFScriptNativeVariable_vtbl *)this;
  v53 = this->globals;
  p_scriptFunction_strReplace = (idAtomicString *)v52;
  idSWFScriptObject::SetNative(this: v53, name: "automaticRescale", native: v52);
  this->swfScriptVar_crop.pThis = this;
  v54 = this->globals;
  p_scriptFunction_strReplace = (idAtomicString *)&this->swfScriptVar_crop;
  idSWFScriptObject::SetNative(this: v54, name: "cropToHeight", native: &this->swfScriptVar_crop);
  this->swfScriptVar_crop.pThis = this;
  v55 = this->globals;
  p_scriptFunction_strReplace = (idAtomicString *)&this->swfScriptVar_crop;
  idSWFScriptObject::SetNative(this: v55, name: "cropToFit", native: &this->swfScriptVar_crop);
  this->swfScriptVar_crop.pThis = this;
  p_scriptFunction_strReplace = (idAtomicString *)&this->swfScriptVar_crop;
  idSWFScriptObject::SetNative(this: this->globals, name: "crop", native: &this->swfScriptVar_crop);
  valueInteger = swf_debug.valueInteger;
  idCVar::SetInteger(this: &swf_debug, newValue: 0, force: true);
  idSWFSpriteInstance::Run(this: this->mainspriteInstance);
  idSWFSpriteInstance::RunActions(this: this->mainspriteInstance);
  idSWFSpriteInstance::RunTo(this: this->mainspriteInstance, targetFrame: 0);
  idCVar::SetInteger(this: &swf_debug, newValue: valueInteger, force: true);
  if ( idSWF::mouseX == -1 )
  {
    v63 = (int)(float)(this->frameWidth * (float)0.5);
    idSWF::mouseX = v63;
  }
  if ( idSWF::mouseY == -1 )
  {
    v63 = (int)(float)(this->frameHeight * (float)0.5);
    idSWF::mouseY = v63;
  }
  if ( soundWorld != nullptr )
    this->soundEmitter = soundWorld->AllocSoundEmitter(this: soundWorld);
  v57 = *(_DWORD *)(v66 - 18116);
  if ( v57 == 2 || v57 == 3 )
    (*(void (__fastcall **)(const char *))(*(_DWORD *)p_atlasTextureName[-7020].str + 36))(a1: p_atlasTextureName[-7020].str);
  v58 = v65;
  idMem::PushHeap(this: v65, heapType: HEAP_SYSTEMHEAP);
  p_swfScriptVar_automaticRescale = (idSWFScriptNativeVariable *)this;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&idSWF::allSWFObjects,
    obj: (const encounterGroupRole_t *)&p_swfScriptVar_automaticRescale);
  idMem::PopHeap(this: v58);
  idStr::FreeData(this: &v120);
  if ( v64 )
    idLib::PopWarningInfo();
  return this;
}


// ========================================================================
// __unwind$231036
// EA  : 0x8277B13C
// RVA : 0x0077B13C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231036()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 1120 + 1140) + 108));
}


// ========================================================================
// __unwind$231037
// EA  : 0x8277B168
// RVA : 0x0077B168
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231037()
{
  int v0; // r12

  idBlockAlloc<idSWFTextInstance,16,72>::~idBlockAlloc<idSWFTextInstance,16,72>(this: (idBlockAlloc<idSWFTextInstance,16,72> *)(*(_DWORD *)(v0 - 1120 + 1140) + 128));
}


// ========================================================================
// __unwind$231038
// EA  : 0x8277B194
// RVA : 0x0077B194
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231038()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1120 + 1140) + 148));
}


// ========================================================================
// __unwind$231039
// EA  : 0x8277B1C0
// RVA : 0x0077B1C0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231039()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1120 + 1140) + 164));
}


// ========================================================================
// __unwind$231040
// EA  : 0x8277B1EC
// RVA : 0x0077B1EC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231040()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 196));
}


// ========================================================================
// __unwind$231041
// EA  : 0x8277B218
// RVA : 0x0077B218
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231041()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 204));
}


// ========================================================================
// __unwind$231042
// EA  : 0x8277B244
// RVA : 0x0077B244
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231042()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 212));
}


// ========================================================================
// __unwind$231043
// EA  : 0x8277B270
// RVA : 0x0077B270
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231043()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 220));
}


// ========================================================================
// __unwind$231044
// EA  : 0x8277B29C
// RVA : 0x0077B29C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231044()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 228));
}


// ========================================================================
// __unwind$231045
// EA  : 0x8277B2C8
// RVA : 0x0077B2C8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231045()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 236));
}


// ========================================================================
// __unwind$231046
// EA  : 0x8277B2F4
// RVA : 0x0077B2F4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231046()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 244));
}


// ========================================================================
// __unwind$231047
// EA  : 0x8277B320
// RVA : 0x0077B320
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231047()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 252));
}


// ========================================================================
// __unwind$231048
// EA  : 0x8277B34C
// RVA : 0x0077B34C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231048()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 260));
}


// ========================================================================
// __unwind$231049
// EA  : 0x8277B378
// RVA : 0x0077B378
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231049()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 268));
}


// ========================================================================
// __unwind$231050
// EA  : 0x8277B3A4
// RVA : 0x0077B3A4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231050()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 276));
}


// ========================================================================
// __unwind$231051
// EA  : 0x8277B3D0
// RVA : 0x0077B3D0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231051()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 284));
}


// ========================================================================
// __unwind$231052
// EA  : 0x8277B3FC
// RVA : 0x0077B3FC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231052()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 292));
}


// ========================================================================
// __unwind$231053
// EA  : 0x8277B428
// RVA : 0x0077B428
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231053()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 300));
}


// ========================================================================
// __unwind$231054
// EA  : 0x8277B454
// RVA : 0x0077B454
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231054()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 308));
}


// ========================================================================
// __unwind$231055
// EA  : 0x8277B480
// RVA : 0x0077B480
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231055()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 316));
}


// ========================================================================
// __unwind$231056
// EA  : 0x8277B4AC
// RVA : 0x0077B4AC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231056()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 324));
}


// ========================================================================
// __unwind$231057
// EA  : 0x8277B4D8
// RVA : 0x0077B4D8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231057()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 332));
}


// ========================================================================
// __unwind$231058
// EA  : 0x8277B504
// RVA : 0x0077B504
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231058()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 340));
}


// ========================================================================
// __unwind$231059
// EA  : 0x8277B530
// RVA : 0x0077B530
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231059()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 348));
}


// ========================================================================
// __unwind$231060
// EA  : 0x8277B55C
// RVA : 0x0077B55C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231060()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 356));
}


// ========================================================================
// __unwind$231061
// EA  : 0x8277B588
// RVA : 0x0077B588
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231061()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 364));
}


// ========================================================================
// __unwind$231062
// EA  : 0x8277B5B4
// RVA : 0x0077B5B4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231062()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 372));
}


// ========================================================================
// __unwind$231063
// EA  : 0x8277B5E0
// RVA : 0x0077B5E0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231063()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 380));
}


// ========================================================================
// __unwind$231064
// EA  : 0x8277B60C
// RVA : 0x0077B60C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231064()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 388));
}


// ========================================================================
// __unwind$231065
// EA  : 0x8277B638
// RVA : 0x0077B638
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231065()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 396));
}


// ========================================================================
// __unwind$231066
// EA  : 0x8277B664
// RVA : 0x0077B664
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231066()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 1120 + 1140) + 404));
}


// ========================================================================
// __unwind$231067
// EA  : 0x8277B690
// RVA : 0x0077B690
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231067()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 1120 + 1140) + 412));
}


// ========================================================================
// __unwind$231068
// EA  : 0x8277B6BC
// RVA : 0x0077B6BC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231068()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 1120 + 1140) + 420));
}


// ========================================================================
// __unwind$231069
// EA  : 0x8277B6E8
// RVA : 0x0077B6E8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231069()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 1120 + 1140) + 428));
}


// ========================================================================
// __unwind$231070
// EA  : 0x8277B714
// RVA : 0x0077B714
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231070()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 1120 + 1140) + 436));
}


// ========================================================================
// __unwind$231071
// EA  : 0x8277B740
// RVA : 0x0077B740
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231071()
{
  int v0; // r12

  idSWF::idSWFScriptFunction_Object::~idSWFScriptFunction_Object(this: (idSWF::idSWFScriptFunction_Object *)(*(_DWORD *)(v0 - 1120 + 1140) + 444));
}


// ========================================================================
// __unwind$231072
// EA  : 0x8277B76C
// RVA : 0x0077B76C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231072()
{
  int v0; // r12

  idList<idSWFDictionaryEntry,72>::~idList<idSWFDictionaryEntry,72>(this: (idList<idSWFDictionaryEntry,72> *)(*(_DWORD *)(v0 - 1120 + 1140) + 544));
}


// ========================================================================
// __unwind$231073
// EA  : 0x8277B798
// RVA : 0x0077B798
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231073()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1120 + 1140) + 560));
}


// ========================================================================
// __unwind$231074
// EA  : 0x8277B7C4
// RVA : 0x0077B7C4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231074()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1120 + 1140) + 576));
}


// ========================================================================
// __unwind$231075
// EA  : 0x8277B7F0
// RVA : 0x0077B7F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231075()
{
  int v0; // r12

  idSWF::idDecompressJPEG::~idDecompressJPEG(this: (idSWF::idDecompressJPEG *)(*(_DWORD *)(v0 - 1120 + 1140) + 616));
}


// ========================================================================
// __unwind$231076
// EA  : 0x8277B81C
// RVA : 0x0077B81C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231076()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1120 + 1140) + 620));
}


// ========================================================================
// __unwind$231077
// EA  : 0x8277B848
// RVA : 0x0077B848
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231077()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 1120 + 128));
}


// ========================================================================
// __unwind$231078
// EA  : 0x8277B870
// RVA : 0x0077B870
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231078()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 480));
}


// ========================================================================
// __unwind$231079
// EA  : 0x8277B898
// RVA : 0x0077B898
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231079()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1120 + 120), tag: TAG_SWF);
}


// ========================================================================
// __unwind$231080
// EA  : 0x8277B8C4
// RVA : 0x0077B8C4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231080()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 144));
}


// ========================================================================
// __unwind$231081
// EA  : 0x8277B8EC
// RVA : 0x0077B8EC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231081()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 168));
}


// ========================================================================
// __unwind$231082
// EA  : 0x8277B914
// RVA : 0x0077B914
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231082()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 1120 + 816));
}


// ========================================================================
// __unwind$231084
// EA  : 0x8277B93C
// RVA : 0x0077B93C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231084()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 160));
}


// ========================================================================
// __unwind$231085
// EA  : 0x8277B964
// RVA : 0x0077B964
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231085()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 176));
}


// ========================================================================
// __unwind$231086
// EA  : 0x8277B98C
// RVA : 0x0077B98C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231086()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 224));
}


// ========================================================================
// __unwind$231087
// EA  : 0x8277B9B4
// RVA : 0x0077B9B4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231087()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 352));
}


// ========================================================================
// __unwind$231088
// EA  : 0x8277B9DC
// RVA : 0x0077B9DC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231088()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 240));
}


// ========================================================================
// __unwind$231089
// EA  : 0x8277BA04
// RVA : 0x0077BA04
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231089()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 320));
}


// ========================================================================
// __unwind$231090
// EA  : 0x8277BA2C
// RVA : 0x0077BA2C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231090()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 256));
}


// ========================================================================
// __unwind$231091
// EA  : 0x8277BA54
// RVA : 0x0077BA54
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231091()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 184));
}


// ========================================================================
// __unwind$231092
// EA  : 0x8277BA7C
// RVA : 0x0077BA7C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231092()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 192));
}


// ========================================================================
// __unwind$231093
// EA  : 0x8277BAA4
// RVA : 0x0077BAA4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231093()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 384));
}


// ========================================================================
// __unwind$231094
// EA  : 0x8277BACC
// RVA : 0x0077BACC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231094()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 272));
}


// ========================================================================
// __unwind$231095
// EA  : 0x8277BAF4
// RVA : 0x0077BAF4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231095()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 336));
}


// ========================================================================
// __unwind$231096
// EA  : 0x8277BB1C
// RVA : 0x0077BB1C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231096()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 152));
}


// ========================================================================
// __unwind$231097
// EA  : 0x8277BB44
// RVA : 0x0077BB44
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231097()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 288));
}


// ========================================================================
// __unwind$231098
// EA  : 0x8277BB6C
// RVA : 0x0077BB6C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231098()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 368));
}


// ========================================================================
// __unwind$231099
// EA  : 0x8277BB94
// RVA : 0x0077BB94
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231099()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 200));
}


// ========================================================================
// __unwind$231100
// EA  : 0x8277BBBC
// RVA : 0x0077BBBC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231100()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 216));
}


// ========================================================================
// __unwind$231101
// EA  : 0x8277BBE4
// RVA : 0x0077BBE4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231101()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 232));
}


// ========================================================================
// __unwind$231102
// EA  : 0x8277BC0C
// RVA : 0x0077BC0C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231102()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 248));
}


// ========================================================================
// __unwind$231103
// EA  : 0x8277BC34
// RVA : 0x0077BC34
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231103()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 264));
}


// ========================================================================
// __unwind$231104
// EA  : 0x8277BC5C
// RVA : 0x0077BC5C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231104()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 280));
}


// ========================================================================
// __unwind$231105
// EA  : 0x8277BC84
// RVA : 0x0077BC84
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231105()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 296));
}


// ========================================================================
// __unwind$231106
// EA  : 0x8277BCAC
// RVA : 0x0077BCAC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231106()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 312));
}


// ========================================================================
// __unwind$231107
// EA  : 0x8277BCD4
// RVA : 0x0077BCD4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231107()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 328));
}


// ========================================================================
// __unwind$231108
// EA  : 0x8277BCFC
// RVA : 0x0077BCFC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231108()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 344));
}


// ========================================================================
// __unwind$231109
// EA  : 0x8277BD24
// RVA : 0x0077BD24
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231109()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 360));
}


// ========================================================================
// __unwind$231110
// EA  : 0x8277BD4C
// RVA : 0x0077BD4C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231110()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 376));
}


// ========================================================================
// __unwind$231111
// EA  : 0x8277BD74
// RVA : 0x0077BD74
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231111()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 392));
}


// ========================================================================
// __unwind$232507
// EA  : 0x8277BD9C
// RVA : 0x0077BD9C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_232507()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 528));
}


// ========================================================================
// __unwind$231112
// EA  : 0x8277BDC4
// RVA : 0x0077BDC4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_231112()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1120 + 208));
}


// ========================================================================
// ??1idSWF@@QAA@XZ
// EA  : 0x8277BDF8
// RVA : 0x0077BDF8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::~idSWF(idSWF *this)
{
  idImage *atlasImage; // r3
  idFile *atlasFile; // r3
  int v4; // r4
  idSWF **list; // r11
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *mainspriteInstance; // r29
  idSWFSprite *mainsprite; // r29
  int v8; // r27
  int v9; // r28
  idSWFDictionaryEntry *v10; // r11
  idSWFSprite *sprite; // r29
  idSWFDictionaryEntry *v12; // r11
  idSWFShape *shape; // r29
  idSWFFont *font; // r29
  char *v15; // r3
  idSWFText *text; // r29
  swfGlyphEntry_t *v17; // r4
  idSWFTextRecord *v18; // r4
  idSWFEditText *edittext; // r4
  idSWF::keyButtonImages_t *v20; // r4
  idSWFScriptObject *globals; // r29
  idSWFScriptObject *shortcutKeys; // r29
  idSoundEmitter *soundEmitter; // r3
  idSWF::imageToPack_t *v26; // r4
  idSWF::tooltipIcon_t *v27; // r4
  idSWF::keyButtonImages_t *v28; // r4
  idSWFDictionaryEntry *v29; // r27
  int size; // r29
  idSWFDictionaryEntry *v31; // r28
  idSWF::orphanedText_t *v32; // r4
  idSWF::orphanedSprite_t *v33; // r4

  atlasImage = this->atlasImage;
  if ( atlasImage != nullptr && atlasImage->d3dTexture != nullptr && this->atlasPurgable )
    idSWF::MarkImageForPurging(image: atlasImage);
  if ( this->atlasFile != nullptr
    && ((unsigned __int8 (__fastcall *)(idResourceManager *))resourceManager->IsResourceFile)(a1: resourceManager) == 0 )
  {
    while ( idImage::ImageState(this: this->atlasImage) == IS_BACKGROUND_READING )
      mgthread_sleep(ms: 10);
    if ( resourceManager->GetCacheFile(this: resourceManager) != nullptr || idLib::production == PROD_DEVELOPMENT )
    {
      atlasFile = this->atlasFile;
      if ( atlasFile != nullptr )
        ((void (__fastcall *)(idFile *, int))atlasFile->dtr_idFile)(a1: atlasFile, a2: 1);
    }
    this->atlasFile = nullptr;
  }
  v4 = 0;
  if ( idSWF::allSWFObjects.num > 0 )
  {
    list = idSWF::allSWFObjects.list;
    while ( *list != this )
    {
      ++v4;
      ++list;
      if ( v4 >= idSWF::allSWFObjects.num )
        goto LABEL_21;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
        this: (idList<idEntityPtr<idEntity>,58> *)&idSWF::allSWFObjects,
        index: v4);
  }
LABEL_21:
  idSWF::PurgeOrphanage(this);
  mainspriteInstance = (idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *)this->mainspriteInstance;
  if ( mainspriteInstance != nullptr )
  {
    idSWFSpriteInstance::~idSWFSpriteInstance(this: this->mainspriteInstance);
    mainspriteInstance->data = (idSWFSpriteInstance *)this->spriteInstanceAllocator.free;
    this->spriteInstanceAllocator.free = mainspriteInstance;
    --this->spriteInstanceAllocator.active;
  }
  mainsprite = this->mainsprite;
  if ( mainsprite != nullptr )
  {
    idSWFSprite::~idSWFSprite(this: this->mainsprite);
    idMem::Free(this: &mem, ptr: mainsprite, align: ALIGN_16);
  }
  v8 = 0;
  if ( this->dictionary.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->dictionary.list[v9];
      sprite = v10->sprite;
      if ( sprite != nullptr )
      {
        idSWFSprite::~idSWFSprite(this: v10->sprite);
        idMem::Free(this: &mem, ptr: sprite, align: ALIGN_16);
        this->dictionary.list[v9].sprite = nullptr;
      }
      v12 = &this->dictionary.list[v9];
      shape = v12->shape;
      if ( shape != nullptr )
      {
        idSWFShape::~idSWFShape(this: v12->shape);
        idMem::Free(this: &mem, ptr: shape, align: ALIGN_16);
        this->dictionary.list[v9].shape = nullptr;
      }
      font = this->dictionary.list[v9].font;
      if ( font != nullptr )
      {
        if ( font->glyphs.listStatic == 0 || font->glyphs.listStatic == 2 )
        {
          v15 = (char *)font->glyphs.list;
          if ( v15 != nullptr )
            idListArrayDelete<idSWFFontGlyph>(ptr: v15, num: font->glyphs.size);
          font->glyphs.list = nullptr;
          font->glyphs.size = 0;
        }
        font->glyphs.num = 0;
        idMem::Free(this: &mem, ptr: font, align: ALIGN_16);
        this->dictionary.list[v9].font = nullptr;
      }
      text = this->dictionary.list[v9].text;
      if ( text != nullptr )
      {
        if ( text->glyphs.listStatic == 0 || text->glyphs.listStatic == 2 )
        {
          v17 = text->glyphs.list;
          if ( v17 != nullptr )
            idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
          text->glyphs.list = nullptr;
          text->glyphs.size = 0;
        }
        text->glyphs.num = 0;
        if ( text->textRecords.listStatic == 0 || text->textRecords.listStatic == 2 )
        {
          v18 = text->textRecords.list;
          if ( v18 != nullptr )
            idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
          text->textRecords.list = nullptr;
          text->textRecords.size = 0;
        }
        text->textRecords.num = 0;
        idMem::Free(this: &mem, ptr: text, align: ALIGN_16);
        this->dictionary.list[v9].text = nullptr;
      }
      edittext = this->dictionary.list[v9].edittext;
      if ( edittext != nullptr )
      {
        idMem::Free(this: &mem, ptr: edittext, align: ALIGN_16);
        this->dictionary.list[v9].edittext = nullptr;
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->dictionary.num );
  }
  idSWFScriptObject::Clear(this: this->globals);
  if ( this->tooltipButtonImage.listStatic == 0 || this->tooltipButtonImage.listStatic == 2 )
  {
    v20 = this->tooltipButtonImage.list;
    if ( v20 != nullptr )
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
    this->tooltipButtonImage.list = nullptr;
    this->tooltipButtonImage.size = 0;
  }
  this->tooltipButtonImage.num = 0;
  globals = this->globals;
  if ( globals->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: globals);
    idMem::Free(this: &mem, ptr: globals, align: ALIGN_16);
  }
  idSWFScriptObject::Clear(this: this->shortcutKeys);
  shortcutKeys = this->shortcutKeys;
  if ( shortcutKeys->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: shortcutKeys);
    idMem::Free(this: &mem, ptr: shortcutKeys, align: ALIGN_16);
  }
  soundEmitter = this->soundEmitter;
  if ( soundEmitter != nullptr )
  {
    soundEmitter->Free(this: soundEmitter, a2: true);
    this->soundEmitter = nullptr;
  }
  if ( this->packImages.listStatic == 0 || this->packImages.listStatic == 2 )
  {
    v26 = this->packImages.list;
    if ( v26 != nullptr )
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    this->packImages.list = nullptr;
    this->packImages.size = 0;
  }
  this->packImages.num = 0;
  idSWF::idDecompressJPEG::~idDecompressJPEG(this: &this->jpeg);
  if ( this->tooltipIconList.listStatic == 0 || this->tooltipIconList.listStatic == 2 )
  {
    v27 = this->tooltipIconList.list;
    if ( v27 != nullptr )
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
    this->tooltipIconList.list = nullptr;
    this->tooltipIconList.size = 0;
  }
  this->tooltipIconList.num = 0;
  if ( this->tooltipButtonImage.listStatic == 0 || this->tooltipButtonImage.listStatic == 2 )
  {
    v28 = this->tooltipButtonImage.list;
    if ( v28 != nullptr )
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
    this->tooltipButtonImage.list = nullptr;
    this->tooltipButtonImage.size = 0;
  }
  this->tooltipButtonImage.num = 0;
  if ( this->dictionary.listStatic == 0 || this->dictionary.listStatic == 2 )
  {
    v29 = this->dictionary.list;
    if ( v29 != nullptr )
    {
      size = this->dictionary.size;
      if ( size > 0 )
      {
        v31 = this->dictionary.list;
        do
        {
          idSWFDictionaryEntry::~idSWFDictionaryEntry(this: v31);
          --size;
          ++v31;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    }
    this->dictionary.list = nullptr;
    this->dictionary.size = 0;
  }
  this->dictionary.num = 0;
  idSWFScriptObject::~idSWFScriptObject(this: &this->scriptFunction_Object.object);
  this->scriptFunction_Object.__vftable = (idSWF::idSWFScriptFunction_Object_vtbl *)&idSWFScriptFunction::`vftable';
  this->swfScriptVar_automaticRescale.__vftable = (idSWF::idSWFScriptNativeVar_automaticRescale_vtbl *)&idSWFScriptNativeVariable::`vftable';
  this->swfScriptVar_crop.__vftable = (idSWF::idSWFScriptNativeVar_crop_vtbl *)&idSWFScriptNativeVariable::`vftable';
  this->swfScriptVar_blackbars.__vftable = (idSWF::idSWFScriptNativeVar_blackbars_vtbl *)&idSWFScriptNativeVariable::`vftable';
  this->swfScriptVar_platform.__vftable = (idSWF::idSWFScriptNativeVar_platform_vtbl *)&idSWFScriptNativeVariable::`vftable';
  this->scriptFunction_toUpper.__vftable = (idSWF::idSWFScriptFunction_toUpper_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_ceil.__vftable = (idSWF::idSWFScriptFunction_ceil_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_floor.__vftable = (idSWF::idSWFScriptFunction_floor_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_rand.__vftable = (idSWF::idSWFScriptFunction_rand_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_abs.__vftable = (idSWF::idSWFScriptFunction_abs_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_sqrt.__vftable = (idSWF::idSWFScriptFunction_sqrt_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_pow.__vftable = (idSWF::idSWFScriptFunction_pow_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_round.__vftable = (idSWF::idSWFScriptFunction_round_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_sin.__vftable = (idSWF::idSWFScriptFunction_sin_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_cos.__vftable = (idSWF::idSWFScriptFunction_cos_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_acos.__vftable = (idSWF::idSWFScriptFunction_acos_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isJapanese.__vftable = (idSWF::idSWFScriptFunction_isJapanese_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_strReplace.__vftable = (idSWF::idSWFScriptFunction_strReplace_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_setCVarInteger.__vftable = (idSWF::idSWFScriptFunction_setCVarInteger_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getCVarInteger.__vftable = (idSWF::idSWFScriptFunction_getCVarInteger_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_swapPS3Buttons.__vftable = (idSWF::idSWFScriptFunction_swapPS3Buttons_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_isMultiplayer.__vftable = (idSWF::idSWFScriptFunction_isMultiplayer_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getLocalString.__vftable = (idSWF::idSWFScriptFunction_getLocalString_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getTruePlatform.__vftable = (idSWF::idSWFScriptFunction_getTruePlatform_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_getPlatform.__vftable = (idSWF::idSWFScriptFunction_getPlatform_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_stopSounds.__vftable = (idSWF::idSWFScriptFunction_stopSounds_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_playSound.__vftable = (idSWF::idSWFScriptFunction_playSound_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_precacheSound.__vftable = (idSWF::idSWFScriptFunction_precacheSound_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_useInhibit.__vftable = (idSWF::idSWFScriptFunction_useInhibit_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_inhibitControl.__vftable = (idSWF::idSWFScriptFunction_inhibitControl_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_deactivate.__vftable = (idSWF::idSWFScriptFunction_deactivate_vtbl *)&idSWFScriptFunction::`vftable';
  this->scriptFunction_shortcutKeys_clear.__vftable = (idSWF::idSWFScriptFunction_shortcutKeys_clear_vtbl *)&idSWFScriptFunction::`vftable';
  if ( this->orphanedTexts.listStatic == 0 || this->orphanedTexts.listStatic == 2 )
  {
    v32 = this->orphanedTexts.list;
    if ( v32 != nullptr )
      idMem::Free(this: &mem, ptr: v32, align: ALIGN_16);
    this->orphanedTexts.list = nullptr;
    this->orphanedTexts.size = 0;
  }
  this->orphanedTexts.num = 0;
  if ( this->orphanedSprites.listStatic == 0 || this->orphanedSprites.listStatic == 2 )
  {
    v33 = this->orphanedSprites.list;
    if ( v33 != nullptr )
      idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
    this->orphanedSprites.list = nullptr;
    this->orphanedSprites.size = 0;
  }
  this->orphanedSprites.num = 0;
  idBlockAlloc<idSWFTextInstance,16,72>::Shutdown(this: &this->textInstanceAllocator);
  idBlockAlloc<idSWFSpriteInstance,16,72>::Shutdown(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)&this->spriteInstanceAllocator);
}


// ========================================================================
// __unwind$233030
// EA  : 0x8277C484
// RVA : 0x0077C484
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233030()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 160 + 180) + 108));
}


// ========================================================================
// __unwind$233031
// EA  : 0x8277C4B0
// RVA : 0x0077C4B0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233031()
{
  int v0; // r12

  idBlockAlloc<idSWFTextInstance,16,72>::~idBlockAlloc<idSWFTextInstance,16,72>(this: (idBlockAlloc<idSWFTextInstance,16,72> *)(*(_DWORD *)(v0 - 160 + 180) + 128));
}


// ========================================================================
// __unwind$233032
// EA  : 0x8277C4DC
// RVA : 0x0077C4DC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233032()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 148));
}


// ========================================================================
// __unwind$233033
// EA  : 0x8277C508
// RVA : 0x0077C508
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233033()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 164));
}


// ========================================================================
// __unwind$233034
// EA  : 0x8277C534
// RVA : 0x0077C534
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233034()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 196));
}


// ========================================================================
// __unwind$233035
// EA  : 0x8277C560
// RVA : 0x0077C560
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233035()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 204));
}


// ========================================================================
// __unwind$233036
// EA  : 0x8277C58C
// RVA : 0x0077C58C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233036()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 212));
}


// ========================================================================
// __unwind$233037
// EA  : 0x8277C5B8
// RVA : 0x0077C5B8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233037()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 220));
}


// ========================================================================
// __unwind$233038
// EA  : 0x8277C5E4
// RVA : 0x0077C5E4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233038()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 228));
}


// ========================================================================
// __unwind$233039
// EA  : 0x8277C610
// RVA : 0x0077C610
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233039()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 236));
}


// ========================================================================
// __unwind$233040
// EA  : 0x8277C63C
// RVA : 0x0077C63C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233040()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 244));
}


// ========================================================================
// __unwind$233041
// EA  : 0x8277C668
// RVA : 0x0077C668
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233041()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 252));
}


// ========================================================================
// __unwind$233042
// EA  : 0x8277C694
// RVA : 0x0077C694
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233042()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 260));
}


// ========================================================================
// __unwind$233043
// EA  : 0x8277C6C0
// RVA : 0x0077C6C0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233043()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 268));
}


// ========================================================================
// __unwind$233044
// EA  : 0x8277C6EC
// RVA : 0x0077C6EC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233044()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 276));
}


// ========================================================================
// __unwind$233045
// EA  : 0x8277C718
// RVA : 0x0077C718
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233045()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 284));
}


// ========================================================================
// __unwind$233046
// EA  : 0x8277C744
// RVA : 0x0077C744
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233046()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 292));
}


// ========================================================================
// __unwind$233047
// EA  : 0x8277C770
// RVA : 0x0077C770
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233047()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 300));
}


// ========================================================================
// __unwind$233048
// EA  : 0x8277C79C
// RVA : 0x0077C79C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233048()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 308));
}


// ========================================================================
// __unwind$233049
// EA  : 0x8277C7C8
// RVA : 0x0077C7C8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233049()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 316));
}


// ========================================================================
// __unwind$233050
// EA  : 0x8277C7F4
// RVA : 0x0077C7F4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233050()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 324));
}


// ========================================================================
// __unwind$233051
// EA  : 0x8277C820
// RVA : 0x0077C820
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233051()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 332));
}


// ========================================================================
// __unwind$233052
// EA  : 0x8277C84C
// RVA : 0x0077C84C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233052()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 340));
}


// ========================================================================
// __unwind$233053
// EA  : 0x8277C878
// RVA : 0x0077C878
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233053()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 348));
}


// ========================================================================
// __unwind$233054
// EA  : 0x8277C8A4
// RVA : 0x0077C8A4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233054()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 356));
}


// ========================================================================
// __unwind$233055
// EA  : 0x8277C8D0
// RVA : 0x0077C8D0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233055()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 364));
}


// ========================================================================
// __unwind$233056
// EA  : 0x8277C8FC
// RVA : 0x0077C8FC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233056()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 372));
}


// ========================================================================
// __unwind$233057
// EA  : 0x8277C928
// RVA : 0x0077C928
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233057()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 380));
}


// ========================================================================
// __unwind$233058
// EA  : 0x8277C954
// RVA : 0x0077C954
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233058()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 388));
}


// ========================================================================
// __unwind$233059
// EA  : 0x8277C980
// RVA : 0x0077C980
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233059()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 396));
}


// ========================================================================
// __unwind$233060
// EA  : 0x8277C9AC
// RVA : 0x0077C9AC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233060()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 160 + 180) + 404));
}


// ========================================================================
// __unwind$233061
// EA  : 0x8277C9D8
// RVA : 0x0077C9D8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233061()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 160 + 180) + 412));
}


// ========================================================================
// __unwind$233062
// EA  : 0x8277CA04
// RVA : 0x0077CA04
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233062()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 160 + 180) + 420));
}


// ========================================================================
// __unwind$233063
// EA  : 0x8277CA30
// RVA : 0x0077CA30
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233063()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 160 + 180) + 428));
}


// ========================================================================
// __unwind$233064
// EA  : 0x8277CA5C
// RVA : 0x0077CA5C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233064()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 160 + 180) + 436));
}


// ========================================================================
// __unwind$233065
// EA  : 0x8277CA88
// RVA : 0x0077CA88
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233065()
{
  int v0; // r12

  idSWF::idSWFScriptFunction_Object::~idSWFScriptFunction_Object(this: (idSWF::idSWFScriptFunction_Object *)(*(_DWORD *)(v0 - 160 + 180) + 444));
}


// ========================================================================
// __unwind$233066
// EA  : 0x8277CAB4
// RVA : 0x0077CAB4
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233066()
{
  int v0; // r12

  idList<idSWFDictionaryEntry,72>::~idList<idSWFDictionaryEntry,72>(this: (idList<idSWFDictionaryEntry,72> *)(*(_DWORD *)(v0 - 160 + 180) + 544));
}


// ========================================================================
// __unwind$233067
// EA  : 0x8277CAE0
// RVA : 0x0077CAE0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233067()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 560));
}


// ========================================================================
// __unwind$233068
// EA  : 0x8277CB0C
// RVA : 0x0077CB0C
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233068()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 576));
}


// ========================================================================
// __unwind$233069
// EA  : 0x8277CB38
// RVA : 0x0077CB38
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233069()
{
  int v0; // r12

  idSWF::idDecompressJPEG::~idDecompressJPEG(this: (idSWF::idDecompressJPEG *)(*(_DWORD *)(v0 - 160 + 180) + 616));
}


// ========================================================================
// __unwind$233070
// EA  : 0x8277CB64
// RVA : 0x0077CB64
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233070()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 620));
}


// ========================================================================
// __unwind$233228
// EA  : 0x8277CB90
// RVA : 0x0077CB90
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233228()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 80) + 40));
}


// ========================================================================
// __unwind$233627
// EA  : 0x8277CBBC
// RVA : 0x0077CBBC
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_233627()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 160 + 84));
}


// ========================================================================
// ?checkSWF_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8277CBF0
// RVA : 0x0077CBF0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall checkSWF_f(const idCmdArgs *args)
{
  idSWF *v2; // r3
  idSWF *v3; // r30

  if ( args->argc == 2 )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&memLocal);
    v2 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
    {
      if ( args->argc <= 1 )
        v3 = idSWF::idSWF(this: v2, filename_: &byte_8200D768, soundWorld: nullptr, atlasPurgable_: true);
      else
        v3 = idSWF::idSWF(this: v2, filename_: args->argv[1], soundWorld: nullptr, atlasPurgable_: true);
    }
    else
    {
      v3 = nullptr;
    }
    idLobbyBackend360::StartArbitration(pexcept: (_exception *)&memLocal);
    if ( v3 != nullptr )
    {
      idSWF::~idSWF(this: v3);
      idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
    }
    idLobbyBackend360::StartArbitration(pexcept: (_exception *)&memLocal);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: checkSWF <swfFile>\n");
  }
}


// ========================================================================
// __unwind$234419
// EA  : 0x8277CD04
// RVA : 0x0077CD04
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_234419()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?RegisterSWFResources@idSWF@@SAXPBD@Z
// EA  : 0x8277CD38
// RVA : 0x0077CD38
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __fastcall idSWF::RegisterSWFResources(char *filename)
{
  int v2; // r27
  idSWF *v3; // r3
  idSWF *v4; // r30
  int v5; // r3

  v2 = Sys_Milliseconds();
  if ( resourceManager->GetBuildPlatforms(this: resourceManager) != 0 )
  {
    v3 = (idSWF *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x27Cu,
                    tag: TAG_SWF,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idSWF::idSWF(this: v3, filename_: filename, soundWorld: nullptr, atlasPurgable_: true);
    else
      v4 = nullptr;
    if ( v4 != nullptr )
    {
      idSWF::~idSWF(this: v4);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
    }
  }
  v5 = Sys_Milliseconds();
  idLib::Printf(fmt: "idSWF::RegisterSWFResources %s took %d ms\n", filename, v5 - v2);
}


// ========================================================================
// __unwind$234470
// EA  : 0x8277CE08
// RVA : 0x0077CE08
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _unwind_234470()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// `dynamic initializer for 'swf_platformOverride''
// EA  : 0x83341800
// RVA : 0x01341800
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_platformOverride__()
{
  idCVar::idCVar(
    this: &swf_platformOverride,
    name: "swf_platformOverride",
    value: "-1",
    flags: 2,
    description: "used to force which buttons are displayed for testing UI 0 - xbox, 1 - ps3, 2 - pc",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_platformOverride__);
}


// ========================================================================
// `dynamic initializer for 'swf_loadBinary''
// EA  : 0x83341858
// RVA : 0x01341858
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_loadBinary__()
{
  idCVar::idCVar(
    this: &swf_loadBinary,
    name: "swf_loadBinary",
    value: "1",
    flags: 2,
    description: "used to set whether to load binary swf from generated",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_loadBinary__);
}


// ========================================================================
// `dynamic initializer for 'swf_purgeUnusedImages''
// EA  : 0x833418B0
// RVA : 0x013418B0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_purgeUnusedImages__()
{
  idCVar::idCVar(
    this: &swf_purgeUnusedImages,
    name: "swf_purgeUnusedImages",
    value: "1",
    flags: 1,
    description: "purge atlas images when a swf is not being rendered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_purgeUnusedImages__);
}


// ========================================================================
// `dynamic initializer for 'idSWF::purgableSWFImages''
// EA  : 0x83341908
// RVA : 0x01341908
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void _dynamic_initializer_for__idSWF::purgableSWFImages__()
{
  idSWF::purgableSWFImages[0].image = nullptr;
  idSWF::purgableSWFImages[0].swfFrameNum = 0;
  idSWF::purgableSWFImages[1].image = nullptr;
  idSWF::purgableSWFImages[1].swfFrameNum = 0;
  idSWF::purgableSWFImages[2].image = nullptr;
  idSWF::purgableSWFImages[2].swfFrameNum = 0;
  idSWF::purgableSWFImages[3].image = nullptr;
  idSWF::purgableSWFImages[3].swfFrameNum = 0;
  idSWF::purgableSWFImages[4].image = nullptr;
  idSWF::purgableSWFImages[4].swfFrameNum = 0;
  idSWF::purgableSWFImages[5].image = nullptr;
  idSWF::purgableSWFImages[5].swfFrameNum = 0;
  idSWF::purgableSWFImages[6].image = nullptr;
  idSWF::purgableSWFImages[6].swfFrameNum = 0;
  idSWF::purgableSWFImages[7].image = nullptr;
  idSWF::purgableSWFImages[7].swfFrameNum = 0;
}


// ========================================================================
// `dynamic initializer for 'idSWF::allSWFObjects''
// EA  : 0x83341968
// RVA : 0x01341968
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idSWF::allSWFObjects__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idSWF::allSWFObjects__);
}


// ========================================================================
// `dynamic initializer for 'listSWF_v''
// EA  : 0x83341978
// RVA : 0x01341978
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listSWF_v__()
{
  return idCommandLink::idCommandLink(
           this: &listSWF_v,
           cmdName: "listSWF",
           function: listSWF_f,
           description: "Lists all current idSWF objects",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'printSWFVar_v''
// EA  : 0x833419A0
// RVA : 0x013419A0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__printSWFVar_v__()
{
  return idCommandLink::idCommandLink(
           this: &printSWFVar_v,
           cmdName: "printSWFVar",
           function: printSWFVar_f,
           description: "Prints the contents of a SWF variable to console",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportSWFMemory_v''
// EA  : 0x833419C8
// RVA : 0x013419C8
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportSWFMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportSWFMemory_v,
           cmdName: "reportSWFMemory",
           function: reportSWFMemory_f,
           description: "Lists all current idSWF dictType objects",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'checkSWF_v''
// EA  : 0x833419F0
// RVA : 0x013419F0
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__checkSWF_v__()
{
  return idCommandLink::idCommandLink(
           this: &checkSWF_v,
           cmdName: "checkSWF",
           function: checkSWF_f,
           description: "Loads and unloads a swf to report memory usage and check for leaks",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportMainMenuFonts_v''
// EA  : 0x83341A18
// RVA : 0x01341A18
// PDB : w:\tech5\engine\guis\swf\swf_main.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportMainMenuFonts_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportMainMenuFonts_v,
           cmdName: "reportMainMenuFonts",
           function: reportMainMenuFonts_f,
           description: "reports font usage in main menu",
           argCompletion: nullptr);
}

