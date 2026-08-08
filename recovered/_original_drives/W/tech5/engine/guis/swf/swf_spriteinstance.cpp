
// ========================================================================
// ?Play@idSWFSpriteInstance@@QAAXXZ
// EA  : 0x82791528
// RVA : 0x00791528
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::Play(idSWFSpriteInstance *this)
{
  idSWFSpriteInstance *parent; // r11

  parent = this->parent;
  if ( parent != nullptr )
  {
    do
    {
      parent->childrenRunning = true;
      parent = parent->parent;
    }
    while ( parent != nullptr );
    this->isPlaying = true;
  }
  else
  {
    this->isPlaying = true;
  }
}


// ========================================================================
// ?Stop@idSWFSpriteInstance@@QAAXXZ
// EA  : 0x82791560
// RVA : 0x00791560
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::Stop(idSWFSpriteInstance *this)
{
  this->isPlaying = false;
}


// ========================================================================
// ?SetVisible@idSWFSpriteInstance@@QAAX_N@Z
// EA  : 0x82791570
// RVA : 0x00791570
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::SetVisible(idSWFSpriteInstance *this, bool visible)
{
  idSWFSpriteInstance *i; // r11

  this->isVisible = visible;
  if ( visible )
  {
    for ( i = this->parent; i != nullptr; i = i->parent )
      i->childrenRunning = true;
  }
}


// ========================================================================
// ?FindDisplayEntry@idSWFSpriteInstance@@QAAPAUswfDisplayEntry_t@@H@Z
// EA  : 0x82791658
// RVA : 0x00791658
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

swfDisplayEntry_t *__fastcall idSWFSpriteInstance::FindDisplayEntry(idSWFSpriteInstance *this, int depth)
{
  int num; // r8
  int v3; // r7
  int v4; // r11

  num = this->displayList.num;
  v3 = 0;
  if ( num > 0 )
  {
    do
    {
      v4 = num >> 1;
      if ( this->displayList.list[v3 + (num >> 1)].depth <= depth )
        v3 += num >> 1;
      num -= v4;
    }
    while ( v4 > 0 );
  }
  return depth != this->displayList.list[v3].depth ? nullptr : &this->displayList.list[v3];
}


// ========================================================================
// ?FindChildSprite@idSWFSpriteInstance@@QAAPAV1@PBD@Z
// EA  : 0x827916C0
// RVA : 0x007916C0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFSpriteInstance::FindChildSprite(idSWFSpriteInstance *this, const char *targetName)
{
  int v4; // r29
  int i; // r30
  idSWFSpriteInstance *spriteInstance; // r11

  v4 = 0;
  if ( this->displayList.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    spriteInstance = this->displayList.list[i].spriteInstance;
    if ( spriteInstance != nullptr && idStr::Icmp(s1: spriteInstance->name.str, s2: targetName) == 0 )
      break;
    if ( ++v4 >= this->displayList.num )
      return nullptr;
  }
  return this->displayList.list[v4].spriteInstance;
}


// ========================================================================
// ?FindFrame@idSWFSpriteInstance@@QBAIPBD@Z
// EA  : 0x82791748
// RVA : 0x00791748
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

int __fastcall idSWFSpriteInstance::FindFrame(idSWFSpriteInstance *this, const char *labelName)
{
  int result; // r3
  idSWFSprite *sprite; // r11
  int v6; // r30
  int v7; // r31
  int v8; // r3

  result = atol(nptr: labelName);
  if ( result <= 0 )
  {
    sprite = this->sprite;
    v6 = 0;
    if ( sprite->frameLabels.num <= 0 )
    {
LABEL_6:
      idLib::Warning(fmt: "Could not find frame '%s' in sprite '%s'", labelName, this->name.str);
      return this->currentFrame;
    }
    else
    {
      v7 = 0;
      while ( 1 )
      {
        v8 = idStr::Icmp(s1: sprite->frameLabels.list[v7].frameLabel.str, s2: labelName);
        sprite = this->sprite;
        if ( v8 == 0 )
          return sprite->frameLabels.list[v6].frameNum;
        ++v6;
        ++v7;
        if ( v6 >= sprite->frameLabels.num )
          goto LABEL_6;
      }
    }
  }
  return result;
}


// ========================================================================
// ?FrameExists@idSWFSpriteInstance@@QBA_NPBD@Z
// EA  : 0x827917F0
// RVA : 0x007917F0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

BOOL __fastcall idSWFSpriteInstance::FrameExists(idSWFSpriteInstance *this, const char *labelName)
{
  int v4; // r3
  idSWFSprite *sprite; // r11
  int v7; // r30
  int i; // r31

  v4 = atol(nptr: labelName);
  sprite = this->sprite;
  if ( v4 > 0 )
    return sprite->frameCount >= v4;
  v7 = 0;
  if ( sprite->frameLabels.num <= 0 )
    return false;
  for ( i = 0; idStr::Icmp(s1: sprite->frameLabels.list[i].frameLabel.str, s2: labelName) != 0; ++i )
  {
    sprite = this->sprite;
    if ( ++v7 >= sprite->frameLabels.num )
      return false;
  }
  return true;
}


// ========================================================================
// ?IsBetweenFrames@idSWFSpriteInstance@@QBA_NPBD0@Z
// EA  : 0x82791898
// RVA : 0x00791898
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

int __fastcall idSWFSpriteInstance::IsBetweenFrames(
        idSWFSpriteInstance *this,
        const char *frameLabel1,
        const char *frameLabel2)
{
  unsigned int Frame; // r3
  unsigned __int8 v6; // r11

  if ( this->currentFrame < (unsigned int)idSWFSpriteInstance::FindFrame(this, labelName: frameLabel1) )
    return 0;
  Frame = idSWFSpriteInstance::FindFrame(this, labelName: frameLabel2);
  v6 = 1;
  if ( this->currentFrame > Frame )
    return 0;
  return v6;
}


// ========================================================================
// ?GetXPos@idSWFSpriteInstance@@QBAMXZ
// EA  : 0x82791900
// RVA : 0x00791900
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

float __fastcall idSWFSpriteInstance::GetXPos(idSWFSpriteInstance *this)
{
  idSWFSpriteInstance *parent; // r3
  double tx; // fp1
  int v4; // r4
  swfDisplayEntry_t *DisplayEntry; // r3

  parent = this->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: this->depth);
    if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == this )
    {
      tx = DisplayEntry->matrix.tx;
    }
    else
    {
      idLib::Warning(fmt: "GetXPos: Couldn't find our display entry in our parent's display list for depth %d", v4);
      tx = 0.0;
    }
  }
  else
  {
    tx = 0.0;
  }
  return *((float *)&tx + 1);
}


// ========================================================================
// ?GetYPos@idSWFSpriteInstance@@QBAMXZ
// EA  : 0x82791998
// RVA : 0x00791998
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

float __fastcall idSWFSpriteInstance::GetYPos(idSWFSpriteInstance *this)
{
  idSWFSpriteInstance *parent; // r3
  double ty; // fp1
  int v4; // r4
  swfDisplayEntry_t *DisplayEntry; // r3

  parent = this->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: this->depth);
    if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == this )
    {
      ty = DisplayEntry->matrix.ty;
    }
    else
    {
      idLib::Warning(fmt: "GetYPos: Couldn't find our display entry in our parents display list for depth %d", v4);
      ty = 0.0;
    }
  }
  else
  {
    ty = 0.0;
  }
  return *((float *)&ty + 1);
}


// ========================================================================
// ?SetXPos@idSWFSpriteInstance@@QAAXM@Z
// EA  : 0x82791A30
// RVA : 0x00791A30
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::SetXPos(idSWFSpriteInstance *this, double xPos)
{
  idSWFSpriteInstance *parent; // r3
  int v4; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  double v6; // fp1

  parent = this->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: this->depth);
    if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == this )
      DisplayEntry->matrix.tx = v6;
    else
      idLib::Warning(fmt: "SetXPos: Couldn't find our display entry in our parents display list for depth %d", v4);
  }
}


// ========================================================================
// ?SetYPos@idSWFSpriteInstance@@QAAXM@Z
// EA  : 0x82791AA8
// RVA : 0x00791AA8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::SetYPos(idSWFSpriteInstance *this, double yPos)
{
  idSWFSpriteInstance *parent; // r3
  int v4; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  double v6; // fp1

  parent = this->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: this->depth);
    if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == this )
      DisplayEntry->matrix.ty = v6;
    else
      idLib::Warning(fmt: "SetYPos: Couldn't find our display entry in our parents display list for depth %d", v4);
  }
}


// ========================================================================
// ?SetAlpha@idSWFSpriteInstance@@QAAXM@Z
// EA  : 0x82791B20
// RVA : 0x00791B20
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::SetAlpha(idSWFSpriteInstance *this, double val)
{
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  double v5; // fp1

  parent = this->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: this->depth);
    if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == this )
      DisplayEntry->cxf.mul.w = v5;
    else
      idLib::Warning(fmt: "_alpha: Couldn't find our display entry in our parents display list");
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__x@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791BF0
// RVA : 0x00791BF0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFSpriteInstance *sprite; // r31
  double v8; // fp1

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    sprite = object->data.sprite;
    if ( sprite != nullptr )
    {
      v8 = idSWFScriptVar::ToFloat(this: value, a2: (int)object, a3: (int)value, a4, a5, a6, a7);
      idSWFSpriteInstance::SetXPos(this: sprite, xPos: v8);
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__y@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791C48
// RVA : 0x00791C48
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFSpriteInstance *sprite; // r31
  double v8; // fp1

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    sprite = object->data.sprite;
    if ( sprite != nullptr )
    {
      v8 = idSWFScriptVar::ToFloat(this: value, a2: (int)object, a3: (int)value, a4, a5, a6, a7);
      idSWFSpriteInstance::SetYPos(this: sprite, yPos: v8);
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__xscale@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791CA0
// RVA : 0x00791CA0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  float *p_characterID; // r31
  double v14; // fp1
  double v15; // fp9
  double v16; // fp8
  double v19; // fp2
  double v20; // fp2

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v4.sprite = (idSWFSpriteInstance *)object->data;
    if ( v4.sprite != nullptr )
    {
      parent = v4.sprite->parent;
      if ( parent != nullptr )
      {
        DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
        p_characterID = (float *)&DisplayEntry->characterID;
        if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
        {
          v14 = idSWFScriptVar::ToFloat(this: value, a2: v11, a3: v10, a4: v9, a5: v8, a6: v7, a7: v6);
          v15 = (float)((float)(p_characterID[4] * (float)0.0) + p_characterID[2]);
          v16 = (float)((float)(p_characterID[3] * (float)0.0) + p_characterID[5]);
          _FP5 = (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f3, f5, f6, f12 }
          v19 = __frsqrte(_FP3);
          v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)v15 * (float)v15))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                              + (float)((float)v15 * (float)v15))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19));
          if ( (float)((float)((float)-(float)((float)((float)((float)v20
                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)v15 * (float)v15))
                                                                     * (float)0.5))
                                                     * (float)v20)
                                             - (float)1.5)
                             * (float)v20)
                     * (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) == 0.0 )
          {
            p_characterID[2] = (float)v14 * (float)0.0099999998;
            p_characterID[5] = 0.0;
          }
          else
          {
            p_characterID[2] = (float)((float)((float)-(float)((float)((float)((float)v20
                                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                                             + (float)((float)v15 * (float)v15))
                                                                                     * (float)0.5))
                                                                     * (float)v20)
                                                             - (float)1.5)
                                             * (float)v20)
                                     * (float)v15)
                             * (float)((float)v14 * (float)0.0099999998);
            p_characterID[5] = (float)((float)((float)-(float)((float)((float)((float)v20
                                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                                             + (float)((float)v15 * (float)v15))
                                                                                     * (float)0.5))
                                                                     * (float)v20)
                                                             - (float)1.5)
                                             * (float)v20)
                                     * (float)v16)
                             * (float)((float)v14 * (float)0.0099999998);
          }
        }
        else
        {
          idLib::Warning(fmt: "_xscale: Couldn't find our display entry in our parents display list");
        }
      }
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__yscale@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791DD8
// RVA : 0x00791DD8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  float *p_characterID; // r31
  double v14; // fp1
  double v15; // fp9
  double v16; // fp8
  double v19; // fp2
  double v20; // fp2

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v4.sprite = (idSWFSpriteInstance *)object->data;
    if ( v4.sprite != nullptr )
    {
      parent = v4.sprite->parent;
      if ( parent != nullptr )
      {
        DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
        p_characterID = (float *)&DisplayEntry->characterID;
        if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
        {
          v14 = idSWFScriptVar::ToFloat(this: value, a2: v11, a3: v10, a4: v9, a5: v8, a6: v7, a7: v6);
          v15 = (float)((float)(p_characterID[5] * (float)0.0) + p_characterID[3]);
          v16 = (float)((float)(p_characterID[2] * (float)0.0) + p_characterID[4]);
          _FP5 = (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f3, f5, f6, f12 }
          v19 = __frsqrte(_FP3);
          v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)v15 * (float)v15))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                              + (float)((float)v15 * (float)v15))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19));
          if ( (float)((float)((float)-(float)((float)((float)((float)v20
                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)v15 * (float)v15))
                                                                     * (float)0.5))
                                                     * (float)v20)
                                             - (float)1.5)
                             * (float)v20)
                     * (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) == 0.0 )
          {
            p_characterID[3] = (float)v14 * (float)0.0099999998;
            p_characterID[4] = 0.0;
          }
          else
          {
            p_characterID[3] = (float)((float)((float)-(float)((float)((float)((float)v20
                                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                                             + (float)((float)v15 * (float)v15))
                                                                                     * (float)0.5))
                                                                     * (float)v20)
                                                             - (float)1.5)
                                             * (float)v20)
                                     * (float)v15)
                             * (float)((float)v14 * (float)0.0099999998);
            p_characterID[4] = (float)((float)((float)-(float)((float)((float)((float)v20
                                                                             * (float)((float)((float)((float)v16 * (float)v16)
                                                                                             + (float)((float)v15 * (float)v15))
                                                                                     * (float)0.5))
                                                                     * (float)v20)
                                                             - (float)1.5)
                                             * (float)v20)
                                     * (float)v16)
                             * (float)((float)v14 * (float)0.0099999998);
          }
        }
        else
        {
          idLib::Warning(fmt: "_yscale: Couldn't find our display entry in our parents display list");
        }
      }
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__alpha@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791F10
// RVA : 0x00791F10
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFSpriteInstance *sprite; // r31
  double v8; // fp1

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    sprite = object->data.sprite;
    if ( sprite != nullptr )
    {
      v8 = idSWFScriptVar::ToFloat(this: value, a2: (int)object, a3: (int)value, a4, a5, a6, a7);
      idSWFSpriteInstance::SetAlpha(this: sprite, val: v8);
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__brightness@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82791F68
// RVA : 0x00791F68
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  float *p_characterID; // r31
  double v14; // fp1
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v4.sprite = (idSWFSpriteInstance *)object->data;
    if ( v4.sprite != nullptr )
    {
      parent = v4.sprite->parent;
      if ( parent != nullptr )
      {
        DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
        p_characterID = (float *)&DisplayEntry->characterID;
        if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
        {
          v14 = idSWFScriptVar::ToFloat(this: value, a2: v11, a3: v10, a4: v9, a5: v8, a6: v7, a7: v6);
          v15 = (float)((float)1.0 - (float)v14);
          if ( v14 < 0.0 )
          {
            v15 = (float)((float)v14 + (float)1.0);
            v14 = 0.0;
          }
          v16 = p_characterID[15];
          p_characterID[12] = v14;
          p_characterID[13] = v14;
          p_characterID[14] = v14;
          p_characterID[15] = v16;
          v17 = p_characterID[11];
          p_characterID[8] = v15;
          p_characterID[9] = v15;
          p_characterID[10] = v15;
          p_characterID[11] = v17;
        }
        else
        {
          idLib::Warning(fmt: "_brightness: Couldn't find our display entry in our parents display list");
        }
      }
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__visible@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82792038
// RVA : 0x00792038
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31
  char v4; // r3
  idSWFSpriteInstance *i; // r11

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
    {
      v4 = idSWFScriptVar::ToBool(this: value);
      v3.sprite->isVisible = v4;
      if ( v4 != 0 )
      {
        for ( i = v3.sprite->parent; i != nullptr; i = i->parent )
          i->childrenRunning = true;
      }
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__rotation@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827920B8
// RVA : 0x007920B8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r4
  swfDisplayEntry_t *DisplayEntry; // r3
  float *p_characterID; // r31
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp31
  double v19; // fp30
  long double v20; // fp2
  float *v21; // r3
  double v22; // fp0
  double v23; // fp1
  double v24; // fp13
  float v25; // [sp+50h] [-40h] BYREF
  float v26[3]; // [sp+54h] [-3Ch] BYREF

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v4.sprite = (idSWFSpriteInstance *)object->data;
    if ( v4.sprite != nullptr )
    {
      parent = v4.sprite->parent;
      if ( parent != nullptr )
      {
        DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
        p_characterID = (float *)&DisplayEntry->characterID;
        if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
        {
          LODWORD(v6) = 0x82000000;
          v14 = (float)((float)(DisplayEntry->matrix.xy * (float)0.0) + DisplayEntry->matrix.xx);
          v15 = (float)((float)(DisplayEntry->matrix.xx * (float)0.0) + DisplayEntry->matrix.xy);
          v16 = (float)((float)(DisplayEntry->matrix.yy * (float)0.0) + DisplayEntry->matrix.yx);
          v17 = (float)((float)(DisplayEntry->matrix.yx * (float)0.0) + DisplayEntry->matrix.yy);
          v18 = __fsqrts((float)((float)((float)v16 * (float)v16) + (float)((float)v14 * (float)v14)));
          v19 = __fsqrts((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)));
          *(double *)&v20 = (float)(idSWFScriptVar::ToFloat(
                                      this: value,
                                      a2: v11,
                                      a3: v10,
                                      a4: v9,
                                      a5: v8,
                                      a6: v7,
                                      a7: v6)
                                  * idMath::M_DEG2RAD);
          idMath::SinCos(a: v20, s: v21, c: &v25, a4: v26);
          v22 = v25;
          v23 = (float)(v25 * (float)v19);
          v24 = v26[0];
          p_characterID[2] = v26[0] * (float)v18;
          p_characterID[5] = (float)v22 * (float)v18;
          p_characterID[3] = (float)v24 * (float)v19;
          p_characterID[4] = -v23;
        }
        else
        {
          idLib::Warning(fmt: "_rotation: Couldn't find our display entry in our parents display list");
        }
      }
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__itemindex@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827921D8
// RVA : 0x007921D8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite->itemIndex = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_materialWidth@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82792228
// RVA : 0x00792228
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite->materialWidth = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_materialHeight@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82792278
// RVA : 0x00792278
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite->materialHeight = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_xOffset@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827922C8
// RVA : 0x007922C8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptObject::swfObjectData_t v7; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v7.sprite = (idSWFSpriteInstance *)object->data;
    if ( v7.sprite != nullptr )
      v7.sprite->xOffset = idSWFScriptVar::ToFloat(this: value, a2: (int)object, a3: (int)value, a4, a5, a6, a7);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__followBorder@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82792318
// RVA : 0x00792318
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite->followBorder = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_material@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82792550
// RVA : 0x00792550
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material *this,
        idSWFScriptObject *object,
        __int64 value,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v5; // r30
  char v6; // r11
  const char *i; // r4
  idMaterial *materialOverride; // r3
  unsigned __int16 Width; // r11
  idMaterial *v10; // r3
  idStr v11[2]; // [sp+50h] [-40h] BYREF

  if ( object != nullptr )
  {
    LODWORD(a5) = object->objectType;
    if ( (_DWORD)a5 == 2 )
    {
      v5.sprite = (idSWFSpriteInstance *)object->data;
      if ( v5.sprite != nullptr )
      {
        if ( *(_DWORD *)HIDWORD(value) == 1 || (v6 = 0, *(_DWORD *)HIDWORD(value) == 0) )
          v6 = 1;
        if ( v6 != 0 )
        {
          i = (const char *)idSWFScriptVar::ToString(
                              this: (idSWFScriptVar *)v11,
                              result: (idStr *)HIDWORD(value),
                              a3: value,
                              a4,
                              a5)->value.i;
          if ( i != nullptr && *i != 0 )
            v5.sprite->materialOverride = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                this: &idMaterial::resourceList,
                                                                name: i,
                                                                makeDefault: true);
          else
            v5.sprite->materialOverride = nullptr;
          materialOverride = v5.sprite->materialOverride;
          if ( materialOverride != nullptr )
          {
            Width = idMaterial::GetWidth(this: materialOverride);
            v10 = v5.sprite->materialOverride;
            v5.sprite->materialWidth = Width;
            v5.sprite->materialHeight = idMaterial::GetHeight(this: v10);
          }
          else
          {
            v5.sprite->materialWidth = 0;
            v5.sprite->materialHeight = 0;
          }
          idStr::FreeData(this: v11);
        }
        else
        {
          v5.sprite->materialOverride = nullptr;
        }
      }
    }
  }
}


// ========================================================================
// __unwind$226583
// EA  : 0x82792638
// RVA : 0x00792638
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_226583()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?RemoveDisplayEntry@idSWFSpriteInstance@@QAAXH@Z
// EA  : 0x82792778
// RVA : 0x00792778
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::RemoveDisplayEntry(idSWFSpriteInstance *this, int depth)
{
  swfDisplayEntry_t *DisplayEntry; // r3
  swfDisplayEntry_t *v4; // r30
  idSWFSpriteInstance *spriteInstance; // r4
  idSWFTextInstance *textInstance; // r4

  DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this, depth);
  v4 = DisplayEntry;
  if ( DisplayEntry != nullptr )
  {
    spriteInstance = DisplayEntry->spriteInstance;
    if ( spriteInstance != nullptr )
      idSWF::AddSpriteOrphan(this: this->sprite->swf, spriteInstance);
    textInstance = v4->textInstance;
    if ( textInstance != nullptr )
      idSWF::AddTextOrphan(this: this->sprite->swf, textInstance);
    idList<swfDisplayEntry_t,72>::RemoveIndex(this: &this->displayList, index: v4 - this->displayList.list);
  }
}


// ========================================================================
// ?SwapDepths@idSWFSpriteInstance@@QAAXHH@Z
// EA  : 0x82792808
// RVA : 0x00792808
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::SwapDepths(idSWFSpriteInstance *this, const int depth1, const int depth2)
{
  int v6; // r26
  int v7; // r29
  swfDisplayEntry_t *v8; // r11
  int depth; // r10
  swfDisplayEntry_t *v10; // r11
  char *str; // r11
  char v12; // r11
  bool v13; // zf
  char *v14; // r11
  char v15; // r11
  swfDisplayEntry_t *list; // r4
  unsigned int num; // r5
  idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth> v18[24]; // [sp+50h] [-60h] BYREF

  v6 = 0;
  if ( this->displayList.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->displayList.list[v7];
      depth = v8->depth;
      if ( depth == depth1 )
      {
        v8->depth = depth2;
      }
      else if ( depth == depth2 )
      {
        v8->depth = depth1;
      }
      v10 = &this->displayList.list[v7];
      if ( v10->spriteInstance != nullptr )
      {
        this->displayList.list[v7].spriteInstance->depth = this->displayList.list[v7].depth;
        str = (char *)this->displayList.list[v7].spriteInstance->name.str;
        if ( str == &byte_8200D768 || (v13 = *str != 0, v12 = 0, !v13) )
          v12 = 1;
        if ( v12 != 0 )
          idLib::Warning(fmt: "SWF: SwapDepths called on unnamed sprite. Please give this sprite a name.");
      }
      else if ( v10->textInstance != nullptr )
      {
        this->displayList.list[v7].textInstance->depth = this->displayList.list[v7].depth;
        v14 = (char *)this->displayList.list[v7].textInstance->name.str;
        if ( v14 == &byte_8200D768 || (v13 = *v14 != 0, v15 = 0, !v13) )
          v15 = 1;
        if ( v15 != 0 )
          idLib::Warning(fmt: "SWF: SwapDepths called on unnamed edittext. Please give this edittext a name.");
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->displayList.num );
  }
  v18[0].__vftable = (idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth>_vtbl *)&idSort_SpriteDepth::`vftable';
  list = this->displayList.list;
  if ( list != nullptr )
  {
    num = this->displayList.num;
    v18[1] = (idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth>)this->displayList.list;
    idSort_Quick<swfDisplayEntry_t,idSort_SpriteDepth>::Sort(this: v18, base: list, num);
  }
}


// ========================================================================
// __unwind$226905
// EA  : 0x82792994
// RVA : 0x00792994
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_226905()
{
  int v0; // r12

  idSort_SpriteDepth::~idSort_SpriteDepth(this: (idSort_SpriteDepth *)(v0 - 176 + 80));
}


// ========================================================================
// ??0idSWFSpriteInstance@@QAA@XZ
// EA  : 0x82793018
// RVA : 0x00793018
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFSpriteInstance::idSWFSpriteInstance(idSWFSpriteInstance *this)
{
  this->firstRun = false;
  this->isPlaying = true;
  this->xOffset = 0.0;
  this->isVisible = true;
  this->yOffset = 0.0;
  this->childrenRunning = true;
  this->currentFrame = 0;
  this->sprite = nullptr;
  this->parent = nullptr;
  this->depth = 0;
  this->itemIndex = 0;
  this->materialOverride = nullptr;
  this->materialWidth = 0;
  this->materialHeight = 0;
  this->displayList.list = nullptr;
  this->displayList.granularity = 0;
  this->displayList.memTag = 72;
  this->displayList.listStatic = 0;
  this->displayList.size = 0;
  this->displayList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->displayList);
  this->name.str = &byte_8200D768;
  this->actions.list = nullptr;
  this->actions.granularity = 0;
  this->actions.memTag = 72;
  this->actions.listStatic = 0;
  this->actions.size = 0;
  this->actions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actions);
  this->onEnterFrame.type = SWF_VAR_UNDEF;
  this->followBorder = -1;
  return this;
}


// ========================================================================
// __unwind$227462
// EA  : 0x827930F4
// RVA : 0x007930F4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227462()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// ??1idSWFSpriteInstance@@QAA@XZ
// EA  : 0x82793128
// RVA : 0x00793128
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::~idSWFSpriteInstance(idSWFSpriteInstance *this)
{
  idSWFSpriteInstance *parent; // r11
  idSWFScriptObject *scriptObject; // r29
  int v5; // r26
  int v6; // r27
  int SpriteOrphanIndex; // r3
  int v8; // r10
  idSWF *swf; // r11
  idList<idSWF::orphanedSprite_t,72> *p_orphanedSprites; // r8
  int num; // r11
  int v12; // r11
  int v13; // r9
  idSWF::orphanedSprite_t *v14; // r11
  int TextOrphanIndex; // r3
  int v16; // r11
  idSWF *v17; // r10
  idList<idSWF::orphanedText_t,72> *p_orphanedTexts; // r8
  int v19; // r10
  int v20; // r10
  int v21; // r10
  idSWF::orphanedText_t *v22; // r9
  swfDisplayEntry_t *v23; // r9
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *spriteInstance; // r29
  idBlockAlloc<idSWFSpriteInstance,16,72> *p_spriteInstanceAllocator; // r28
  swfDisplayEntry_t *v26; // r9
  idBlockAlloc<idSWFTextInstance,16,72>::element_t *textInstance; // r29
  idBlockAlloc<idSWFTextInstance,16,72> *p_textInstanceAllocator; // r28
  idSWFScriptObject *v29; // r11
  idSWFScriptObject *v30; // r29
  idSWFSpriteInstance::swfAction_t *list; // r4
  swfDisplayEntry_t *v33; // r4
  idSWFScriptVar v34[11]; // [sp+58h] [-58h] BYREF

  parent = this->parent;
  if ( parent != nullptr )
  {
    v34[0].type = SWF_VAR_UNDEF;
    idSWFScriptObject::Set(this: parent->scriptObject, name: (char *)this->name.str, value: v34);
    idSWFScriptVar::Free(this: v34);
    scriptObject = this->parent->scriptObject;
    if ( scriptObject->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: scriptObject);
      idMem::Free(this: &mem, ptr: scriptObject, align: ALIGN_16);
    }
  }
  v5 = 0;
  if ( this->displayList.num > 0 )
  {
    v6 = 0;
    do
    {
      SpriteOrphanIndex = idSWF::FindSpriteOrphanIndex(
                            this: this->sprite->swf,
                            spriteInstance: this->displayList.list[v6].spriteInstance);
      v8 = SpriteOrphanIndex;
      if ( SpriteOrphanIndex != -1 )
      {
        swf = this->sprite->swf;
        p_orphanedSprites = &swf->orphanedSprites;
        if ( SpriteOrphanIndex >= 0 )
        {
          num = swf->orphanedSprites.num;
          if ( SpriteOrphanIndex < num )
          {
            v12 = num - 1;
            p_orphanedSprites->num = v12;
            if ( SpriteOrphanIndex < v12 )
            {
              v13 = SpriteOrphanIndex;
              do
              {
                ++v8;
                v14 = &p_orphanedSprites->list[v13++];
                v14->spriteInstance = v14[1].spriteInstance;
                *(_DWORD *)&v14->wasPlaying = *(_DWORD *)&v14[1].wasPlaying;
              }
              while ( v8 < p_orphanedSprites->num );
            }
          }
        }
      }
      TextOrphanIndex = idSWF::FindTextOrphanIndex(
                          this: this->sprite->swf,
                          textInstance: this->displayList.list[v6].textInstance);
      v16 = TextOrphanIndex;
      if ( TextOrphanIndex != -1 )
      {
        v17 = this->sprite->swf;
        p_orphanedTexts = &v17->orphanedTexts;
        if ( TextOrphanIndex >= 0 )
        {
          v19 = v17->orphanedTexts.num;
          if ( TextOrphanIndex < v19 )
          {
            v20 = v19 - 1;
            p_orphanedTexts->num = v20;
            if ( TextOrphanIndex < v20 )
            {
              v21 = TextOrphanIndex;
              do
              {
                ++v16;
                v22 = &p_orphanedTexts->list[v21++];
                v22->textInstance = v22[1].textInstance;
              }
              while ( v16 < p_orphanedTexts->num );
            }
          }
        }
      }
      v23 = &this->displayList.list[v6];
      spriteInstance = (idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *)v23->spriteInstance;
      p_spriteInstanceAllocator = &this->sprite->swf->spriteInstanceAllocator;
      if ( spriteInstance != nullptr )
      {
        idSWFSpriteInstance::~idSWFSpriteInstance(this: v23->spriteInstance);
        spriteInstance->data = (idSWFSpriteInstance *)p_spriteInstanceAllocator->free;
        p_spriteInstanceAllocator->free = spriteInstance;
        --p_spriteInstanceAllocator->active;
      }
      v26 = &this->displayList.list[v6];
      textInstance = (idBlockAlloc<idSWFTextInstance,16,72>::element_t *)v26->textInstance;
      p_textInstanceAllocator = &this->sprite->swf->textInstanceAllocator;
      if ( textInstance != nullptr )
      {
        idSWFTextInstance::~idSWFTextInstance(this: v26->textInstance);
        textInstance->data = (idSWFTextInstance *)p_textInstanceAllocator->free;
        p_textInstanceAllocator->free = textInstance;
        --p_textInstanceAllocator->active;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->displayList.num );
  }
  v29 = this->scriptObject;
  v29->data.sprite = nullptr;
  v29->objectType = SWF_OBJECT_SPRITE;
  idSWFScriptObject::Clear(this: this->scriptObject);
  v30 = this->scriptObject;
  if ( v30->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v30);
    idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
  }
  this->actionScript->Release(this: this->actionScript);
  idSWFScriptVar::Free(this: &this->onEnterFrame);
  if ( this->actions.listStatic == 0 || this->actions.listStatic == 2 )
  {
    list = this->actions.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->actions.list = nullptr;
    this->actions.size = 0;
  }
  this->actions.num = 0;
  if ( this->displayList.listStatic == 0 || this->displayList.listStatic == 2 )
  {
    v33 = this->displayList.list;
    if ( v33 != nullptr )
      idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
    this->displayList.list = nullptr;
    this->displayList.size = 0;
  }
  this->displayList.num = 0;
}


// ========================================================================
// __unwind$227497
// EA  : 0x82793430
// RVA : 0x00793430
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 44));
}


// ========================================================================
// __unwind$227498
// EA  : 0x8279345C
// RVA : 0x0079345C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227498()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 64));
}


// ========================================================================
// __unwind$227499
// EA  : 0x82793488
// RVA : 0x00793488
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227499()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(*(_DWORD *)(v0 - 176 + 196) + 84));
}


// ========================================================================
// __unwind$227500
// EA  : 0x827934B4
// RVA : 0x007934B4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227500()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 88));
}


// ========================================================================
// ??0idSWFScriptObject_SpriteInstancePrototype@@QAA@XZ
// EA  : 0x827934E8
// RVA : 0x007934E8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptObject_SpriteInstancePrototype(
        idSWFScriptObject_SpriteInstancePrototype *this)
{
  idSWFScriptVar v3; // [sp+A8h] [-E8h] BYREF
  idSWFScriptVar v4; // [sp+B0h] [-E0h] BYREF
  idSWFScriptVar v5; // [sp+B8h] [-D8h] BYREF
  idSWFScriptVar v6; // [sp+C0h] [-D0h] BYREF
  idSWFScriptVar v7; // [sp+C8h] [-C8h] BYREF
  idSWFScriptVar v8; // [sp+D0h] [-C0h] BYREF
  idSWFScriptVar v9; // [sp+D8h] [-B8h] BYREF
  idSWFScriptVar v10; // [sp+E0h] [-B0h] BYREF
  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder *p_swfScriptVar__followBorder; // [sp+E8h] [-A8h]

  idSWFScriptObject::idSWFScriptObject(this);
  this->scriptFunction_duplicateMovieClip.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip::`vftable';
  this->scriptFunction_gotoAndPlay.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay::`vftable';
  this->scriptFunction_gotoAndStop.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop::`vftable';
  this->scriptFunction_swapDepths.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths::`vftable';
  this->scriptFunction_nextFrame.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame::`vftable';
  this->scriptFunction_prevFrame.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame::`vftable';
  this->scriptFunction_play.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play::`vftable';
  this->scriptFunction_stop.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop::`vftable';
  this->swfScriptVar__x.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x::`vftable';
  this->swfScriptVar__y.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y::`vftable';
  this->swfScriptVar__xscale.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale::`vftable';
  this->swfScriptVar__yscale.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale::`vftable';
  this->swfScriptVar__alpha.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha::`vftable';
  this->swfScriptVar__brightness.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness::`vftable';
  this->swfScriptVar__visible.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible::`vftable';
  this->swfScriptVar__width.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__width_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__width::`vftable';
  this->swfScriptVar__height.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height::`vftable';
  this->swfScriptVar__rotation.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation::`vftable';
  this->swfScriptVar__name.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name::`vftable';
  this->swfScriptVar__currentframe.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::`vftable';
  this->swfScriptVar__totalframes.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__totalframes_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__totalframes::`vftable';
  this->swfScriptVar__target.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__target_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__target::`vftable';
  this->swfScriptVar__framesloaded.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded::`vftable';
  this->swfScriptVar__droptarget.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__droptarget_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__droptarget::`vftable';
  this->swfScriptVar__url.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__url_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__url::`vftable';
  this->swfScriptVar__highquality.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality::`vftable';
  this->swfScriptVar__focusrect.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect::`vftable';
  this->swfScriptVar__soundbuftime.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__soundbuftime_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__soundbuftime::`vftable';
  this->swfScriptVar__quality.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__quality_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__quality::`vftable';
  this->swfScriptVar__mousex.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex::`vftable';
  this->swfScriptVar__mousey.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey::`vftable';
  this->swfScriptVar__itemindex.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex::`vftable';
  this->swfScriptVar_material.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material::`vftable';
  this->swfScriptVar_materialWidth.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth::`vftable';
  this->swfScriptVar_materialHeight.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight::`vftable';
  this->swfScriptVar_xOffset.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset::`vftable';
  this->swfScriptVar_onEnterFrame.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame::`vftable';
  this->swfScriptVar__followBorder.__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder_vtbl *)&idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder::`vftable';
  p_swfScriptVar__followBorder = &this->swfScriptVar__followBorder;
  this->scriptFunction_duplicateMovieClip.AddRef(this: &this->scriptFunction_duplicateMovieClip);
  idSWFScriptVar::idSWFScriptVar(this: &v3, nf: &this->scriptFunction_duplicateMovieClip);
  idSWFScriptObject::Set(this, name: "duplicateMovieClip", value: &v3);
  idSWFScriptVar::Free(this: &v3);
  this->scriptFunction_gotoAndPlay.AddRef(this: &this->scriptFunction_gotoAndPlay);
  idSWFScriptVar::idSWFScriptVar(this: &v9, nf: &this->scriptFunction_gotoAndPlay);
  idSWFScriptObject::Set(this, name: "gotoAndPlay", value: &v9);
  idSWFScriptVar::Free(this: &v9);
  this->scriptFunction_gotoAndStop.AddRef(this: &this->scriptFunction_gotoAndStop);
  idSWFScriptVar::idSWFScriptVar(this: &v7, nf: &this->scriptFunction_gotoAndStop);
  idSWFScriptObject::Set(this, name: "gotoAndStop", value: &v7);
  idSWFScriptVar::Free(this: &v7);
  this->scriptFunction_swapDepths.AddRef(this: &this->scriptFunction_swapDepths);
  idSWFScriptVar::idSWFScriptVar(this: &v4, nf: &this->scriptFunction_swapDepths);
  idSWFScriptObject::Set(this, name: "swapDepths", value: &v4);
  idSWFScriptVar::Free(this: &v4);
  this->scriptFunction_nextFrame.AddRef(this: &this->scriptFunction_nextFrame);
  idSWFScriptVar::idSWFScriptVar(this: &v6, nf: &this->scriptFunction_nextFrame);
  idSWFScriptObject::Set(this, name: "nextFrame", value: &v6);
  idSWFScriptVar::Free(this: &v6);
  this->scriptFunction_prevFrame.AddRef(this: &this->scriptFunction_prevFrame);
  idSWFScriptVar::idSWFScriptVar(this: &v8, nf: &this->scriptFunction_prevFrame);
  idSWFScriptObject::Set(this, name: "prevFrame", value: &v8);
  idSWFScriptVar::Free(this: &v8);
  this->scriptFunction_play.AddRef(this: &this->scriptFunction_play);
  idSWFScriptVar::idSWFScriptVar(this: &v10, nf: &this->scriptFunction_play);
  idSWFScriptObject::Set(this, name: "play", value: &v10);
  idSWFScriptVar::Free(this: &v10);
  this->scriptFunction_stop.AddRef(this: &this->scriptFunction_stop);
  idSWFScriptVar::idSWFScriptVar(this: &v5, nf: &this->scriptFunction_stop);
  idSWFScriptObject::Set(this, name: "stop", value: &v5);
  idSWFScriptVar::Free(this: &v5);
  idSWFScriptObject::SetNative(this, name: "_x", native: &this->swfScriptVar__x);
  idSWFScriptObject::SetNative(this, name: "_y", native: &this->swfScriptVar__y);
  idSWFScriptObject::SetNative(this, name: "_xscale", native: &this->swfScriptVar__xscale);
  idSWFScriptObject::SetNative(this, name: "_yscale", native: &this->swfScriptVar__yscale);
  idSWFScriptObject::SetNative(this, name: "_alpha", native: &this->swfScriptVar__alpha);
  idSWFScriptObject::SetNative(this, name: "_brightness", native: &this->swfScriptVar__brightness);
  idSWFScriptObject::SetNative(this, name: "_visible", native: &this->swfScriptVar__visible);
  idSWFScriptObject::SetNative(this, name: "_width", native: &this->swfScriptVar__width);
  idSWFScriptObject::SetNative(this, name: "_height", native: &this->swfScriptVar__height);
  idSWFScriptObject::SetNative(this, name: "_rotation", native: &this->swfScriptVar__rotation);
  idSWFScriptObject::SetNative(this, name: "_name", native: &this->swfScriptVar__name);
  idSWFScriptObject::SetNative(this, name: "_currentframe", native: &this->swfScriptVar__currentframe);
  idSWFScriptObject::SetNative(this, name: "_totalframes", native: &this->swfScriptVar__totalframes);
  idSWFScriptObject::SetNative(this, name: "_target", native: &this->swfScriptVar__target);
  idSWFScriptObject::SetNative(this, name: "_framesloaded", native: &this->swfScriptVar__framesloaded);
  idSWFScriptObject::SetNative(this, name: "_droptarget", native: &this->swfScriptVar__droptarget);
  idSWFScriptObject::SetNative(this, name: "_url", native: &this->swfScriptVar__url);
  idSWFScriptObject::SetNative(this, name: "_highquality", native: &this->swfScriptVar__highquality);
  idSWFScriptObject::SetNative(this, name: "_focusrect", native: &this->swfScriptVar__focusrect);
  idSWFScriptObject::SetNative(this, name: "_soundbuftime", native: &this->swfScriptVar__soundbuftime);
  idSWFScriptObject::SetNative(this, name: "_quality", native: &this->swfScriptVar__quality);
  idSWFScriptObject::SetNative(this, name: "_mousex", native: &this->swfScriptVar__mousex);
  idSWFScriptObject::SetNative(this, name: "_mousey", native: &this->swfScriptVar__mousey);
  idSWFScriptObject::SetNative(this, name: "_itemindex", native: &this->swfScriptVar__itemindex);
  idSWFScriptObject::SetNative(this, name: "material", native: &this->swfScriptVar_material);
  idSWFScriptObject::SetNative(this, name: "materialWidth", native: &this->swfScriptVar_materialWidth);
  idSWFScriptObject::SetNative(this, name: "materialHeight", native: &this->swfScriptVar_materialHeight);
  idSWFScriptObject::SetNative(this, name: "xOffset", native: &this->swfScriptVar_xOffset);
  idSWFScriptObject::SetNative(this, name: "onEnterFrame", native: &this->swfScriptVar_onEnterFrame);
  idSWFScriptObject::SetNative(this, name: "_followBorder", native: &this->swfScriptVar__followBorder);
  return this;
}


// ========================================================================
// __unwind$227777
// EA  : 0x82793C98
// RVA : 0x00793C98
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227777()
{
  int v0; // r12

  idSWFScriptObject::~idSWFScriptObject(this: *(idSWFScriptObject **)(v0 - 400 + 420));
}


// ========================================================================
// __unwind$227778
// EA  : 0x82793CC0
// RVA : 0x00793CC0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227778()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 96));
}


// ========================================================================
// __unwind$227779
// EA  : 0x82793CEC
// RVA : 0x00793CEC
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227779()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 100));
}


// ========================================================================
// __unwind$227780
// EA  : 0x82793D18
// RVA : 0x00793D18
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227780()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 104));
}


// ========================================================================
// __unwind$227781
// EA  : 0x82793D44
// RVA : 0x00793D44
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227781()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 108));
}


// ========================================================================
// __unwind$227782
// EA  : 0x82793D70
// RVA : 0x00793D70
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227782()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 112));
}


// ========================================================================
// __unwind$227783
// EA  : 0x82793D9C
// RVA : 0x00793D9C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227783()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 116));
}


// ========================================================================
// __unwind$227784
// EA  : 0x82793DC8
// RVA : 0x00793DC8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227784()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 120));
}


// ========================================================================
// __unwind$227785
// EA  : 0x82793DF4
// RVA : 0x00793DF4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227785()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 400 + 420) + 124));
}


// ========================================================================
// __unwind$227786
// EA  : 0x82793E20
// RVA : 0x00793E20
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227786()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 128));
}


// ========================================================================
// __unwind$227787
// EA  : 0x82793E4C
// RVA : 0x00793E4C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227787()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 132));
}


// ========================================================================
// __unwind$227788
// EA  : 0x82793E78
// RVA : 0x00793E78
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227788()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 136));
}


// ========================================================================
// __unwind$227789
// EA  : 0x82793EA4
// RVA : 0x00793EA4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227789()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 140));
}


// ========================================================================
// __unwind$227790
// EA  : 0x82793ED0
// RVA : 0x00793ED0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227790()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 144));
}


// ========================================================================
// __unwind$227791
// EA  : 0x82793EFC
// RVA : 0x00793EFC
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227791()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 148));
}


// ========================================================================
// __unwind$227792
// EA  : 0x82793F28
// RVA : 0x00793F28
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227792()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 152));
}


// ========================================================================
// __unwind$227793
// EA  : 0x82793F54
// RVA : 0x00793F54
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227793()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 156));
}


// ========================================================================
// __unwind$227794
// EA  : 0x82793F80
// RVA : 0x00793F80
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227794()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 160));
}


// ========================================================================
// __unwind$227795
// EA  : 0x82793FAC
// RVA : 0x00793FAC
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227795()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 164));
}


// ========================================================================
// __unwind$227796
// EA  : 0x82793FD8
// RVA : 0x00793FD8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227796()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 168));
}


// ========================================================================
// __unwind$227797
// EA  : 0x82794004
// RVA : 0x00794004
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227797()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 172));
}


// ========================================================================
// __unwind$227798
// EA  : 0x82794030
// RVA : 0x00794030
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227798()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 176));
}


// ========================================================================
// __unwind$227799
// EA  : 0x8279405C
// RVA : 0x0079405C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227799()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 180));
}


// ========================================================================
// __unwind$227800
// EA  : 0x82794088
// RVA : 0x00794088
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227800()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 184));
}


// ========================================================================
// __unwind$227801
// EA  : 0x827940B4
// RVA : 0x007940B4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227801()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 188));
}


// ========================================================================
// __unwind$227802
// EA  : 0x827940E0
// RVA : 0x007940E0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227802()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 192));
}


// ========================================================================
// __unwind$227803
// EA  : 0x8279410C
// RVA : 0x0079410C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227803()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 196));
}


// ========================================================================
// __unwind$227804
// EA  : 0x82794138
// RVA : 0x00794138
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227804()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 200));
}


// ========================================================================
// __unwind$227805
// EA  : 0x82794164
// RVA : 0x00794164
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227805()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 204));
}


// ========================================================================
// __unwind$227806
// EA  : 0x82794190
// RVA : 0x00794190
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227806()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 208));
}


// ========================================================================
// __unwind$227807
// EA  : 0x827941BC
// RVA : 0x007941BC
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227807()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 212));
}


// ========================================================================
// __unwind$227808_0
// EA  : 0x827941E8
// RVA : 0x007941E8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227808_0()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 216));
}


// ========================================================================
// __unwind$227809
// EA  : 0x82794214
// RVA : 0x00794214
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227809()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 220));
}


// ========================================================================
// __unwind$227810
// EA  : 0x82794240
// RVA : 0x00794240
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227810()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 224));
}


// ========================================================================
// __unwind$227811
// EA  : 0x8279426C
// RVA : 0x0079426C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227811()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 228));
}


// ========================================================================
// __unwind$227812
// EA  : 0x82794298
// RVA : 0x00794298
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227812()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 232));
}


// ========================================================================
// __unwind$227813
// EA  : 0x827942C4
// RVA : 0x007942C4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227813()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 236));
}


// ========================================================================
// __unwind$227814
// EA  : 0x827942F0
// RVA : 0x007942F0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227814()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 240));
}


// ========================================================================
// __unwind$227815
// EA  : 0x8279431C
// RVA : 0x0079431C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227815()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 400 + 420) + 244));
}


// ========================================================================
// __unwind$227816
// EA  : 0x82794348
// RVA : 0x00794348
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227816()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 168));
}


// ========================================================================
// __unwind$227817
// EA  : 0x82794370
// RVA : 0x00794370
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227817()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 216));
}


// ========================================================================
// __unwind$227818_0
// EA  : 0x82794398
// RVA : 0x00794398
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227818_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 200));
}


// ========================================================================
// __unwind$227819
// EA  : 0x827943C0
// RVA : 0x007943C0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227819()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$227820
// EA  : 0x827943E8
// RVA : 0x007943E8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227820()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 192));
}


// ========================================================================
// __unwind$227821
// EA  : 0x82794410
// RVA : 0x00794410
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227821()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$227822
// EA  : 0x82794438
// RVA : 0x00794438
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227822()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$227823
// EA  : 0x82794460
// RVA : 0x00794460
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_227823()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 184));
}


// ========================================================================
// ?Call@idSWFScriptFunction_swapDepths@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82794488
// RVA : 0x00794488
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r31
  int v6; // r3

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    if ( v5.sprite->parent != nullptr )
    {
      if ( parms->num >= 1 )
      {
        v6 = idSWFScriptVar::ToInteger(this: parms->list);
        idSWFSpriteInstance::SwapDepths(this: v5.sprite->parent, depth1: v5.sprite->depth, depth2: v6);
      }
      else
      {
        idLib::Warning(fmt: "swapDepths: expected 1 parameters", result);
      }
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths_vtbl *)4;
    }
    else
    {
      idLib::Warning(fmt: "Tried to swap depths on root movie clip", result);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths_vtbl *)4;
    }
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call swapDepths on NULL sprite", result);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_swapDepths_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_play@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82794560
// RVA : 0x00794560
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r9
  idSWFSpriteInstance *i; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    for ( i = v5.sprite->parent; i != nullptr; i = i->parent )
      i->childrenRunning = true;
    v5.sprite->isPlaying = true;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call play on NULL sprite", result);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_play_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_stop@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x827945F0
// RVA : 0x007945F0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFSpriteInstance *sprite; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (sprite = thisObject->data.sprite) != nullptr )
  {
    sprite->isPlaying = false;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call stop on NULL sprite", result);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_stop_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_onEnterFrame@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794668
// RVA : 0x00794668
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, other: &v4.sprite->onEnterFrame);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_onEnterFrame@idSWFScriptObject_SpriteInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827946D0
// RVA : 0x007946D0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame::Set(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_onEnterFrame *this,
        idSWFScriptObject *object,
        const idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r11

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      idSWFScriptVar::operator=(this: &v3.sprite->onEnterFrame, other: value);
  }
}


// ========================================================================
// ?FreeDisplayList@idSWFSpriteInstance@@QAAXXZ
// EA  : 0x827948A8
// RVA : 0x007948A8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::FreeDisplayList(idSWFSpriteInstance *this)
{
  int v2; // r29
  int v3; // r30
  idSWFSpriteInstance *spriteInstance; // r4
  idSWFTextInstance *textInstance; // r4
  idList<swfDisplayEntry_t,72> *p_displayList; // r30

  v2 = 0;
  if ( this->displayList.num > 0 )
  {
    v3 = 0;
    do
    {
      spriteInstance = this->displayList.list[v3].spriteInstance;
      if ( spriteInstance != nullptr )
        idSWF::AddSpriteOrphan(this: this->sprite->swf, spriteInstance);
      textInstance = this->displayList.list[v3].textInstance;
      if ( textInstance != nullptr )
        idSWF::AddTextOrphan(this: this->sprite->swf, textInstance);
      ++v2;
      ++v3;
    }
    while ( v2 < this->displayList.num );
  }
  p_displayList = &this->displayList;
  if ( this->displayList.size < 0 )
  {
    if ( this->displayList.listStatic == 0 || this->displayList.listStatic == 2 )
    {
      if ( p_displayList->list != nullptr )
        idMem::Free(this: &mem, ptr: p_displayList->list, align: ALIGN_16);
      p_displayList->list = nullptr;
      this->displayList.size = 0;
    }
    this->displayList.num = 0;
  }
  this->displayList.num = __CFADD__(-this->displayList.size, this->displayList.size ^ 0x80000000)
                        ? 0
                        : this->displayList.size;
  this->currentFrame = 0;
}


// ========================================================================
// ?DoAction@idSWFSpriteInstance@@QAAXAAVidSWFBitStream@@@Z
// EA  : 0x82794998
// RVA : 0x00794998
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::DoAction(idSWFSpriteInstance *this, idSWFBitStream *bitstream)
{
  breakableIsland_t *v3; // r3
  unsigned __int64 v4; // r10
  breakableIsland_t *v5; // r30
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5

  v3 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&this->actions);
  LODWORD(v4) = bitstream->startp;
  v5 = v3;
  v3->index = (int)idSWFBitStream::ReadData(
                     this: bitstream,
                     size: (int)&bitstream->endp[-v4],
                     a3: v9,
                     a4: v8,
                     a5: v7,
                     a6: v6,
                     a7: v4);
  LODWORD(v5->lowestPoint) = bitstream->endp - bitstream->startp;
}


// ========================================================================
// ?ResolveTarget@idSWFSpriteInstance@@QAAPAV1@PBD@Z
// EA  : 0x82794A08
// RVA : 0x00794A08
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFSpriteInstance::ResolveTarget(idSWFSpriteInstance *this, const char *targetName)
{
  const char *v3; // r24
  idSWFSpriteInstance *v4; // r28
  idSWFSpriteInstance *i; // r11
  int v6; // r30
  __int64 v7; // kr00_8
  char **p_data; // r29
  idList<idStr,5> v10; // [sp+50h] [-60h] BYREF

  v3 = targetName;
  if ( *targetName == 0 )
    return this;
  v4 = this;
  if ( *targetName == 47 )
  {
    for ( i = this->parent; i != nullptr; i = i->parent )
      v4 = i;
    ++targetName;
  }
  v6 = 0;
  *(_WORD *)&v10.memTag = 1280;
  memset(&v10, 0, 14);
  idStrListBreakupString(list: &v10, string: targetName, separator: 47);
  v7 = *(_QWORD *)&v10.list;
  if ( v10.num > 0 )
  {
    p_data = &v10.list->data;
    while ( 1 )
    {
      v4 = idStr::Cmp(s1: *p_data, s2: "..") != 0
         ? idSWFSpriteInstance::FindChildSprite(this: v4, targetName: *p_data)
         : v4->parent;
      if ( v4 == nullptr )
        break;
      ++v6;
      p_data += 8;
      if ( v6 >= (int)v7 )
        goto LABEL_13;
    }
    idLib::Warning(fmt: "SWF: Could not resolve %s, %s not found", v3, *(const char **)(32 * v6 + HIDWORD(v7) + 4));
    if ( (v10.listStatic == 0 || v10.listStatic == 2) && HIDWORD(v7) != 0 )
      idListArrayDelete<idStr>(ptr: (idStr *)HIDWORD(v7), num: v10.size);
    return this;
  }
LABEL_13:
  if ( (v10.listStatic == 0 || v10.listStatic == 2) && HIDWORD(v7) != 0 )
    idListArrayDelete<idStr>(ptr: (idStr *)HIDWORD(v7), num: v10.size);
  return v4;
}


// ========================================================================
// __unwind$229018
// EA  : 0x82794B68
// RVA : 0x00794B68
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_229018()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 176 + 80));
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__url@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794B90
// RVA : 0x00794B90
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__url *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__url::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__url *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: &byte_8200D768);
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__highquality@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794BC8
// RVA : 0x00794BC8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__highquality_vtbl *)6;
  *((_DWORD *)this + 1) = 2;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__focusrect@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794C10
// RVA : 0x00794C10
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__focusrect_vtbl *)5;
  *((_BYTE *)this + 4) = 1;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__quality@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794C58
// RVA : 0x00794C58
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__quality *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__quality::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__quality *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "BEST");
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__height@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794C90
// RVA : 0x00794C90
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__height_vtbl *)2;
  *((float *)this + 1) = 0.0;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__x@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794CE0
// RVA : 0x00794CE0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFSpriteInstance *sprite; // r3
  double XPos; // fp31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE && (sprite = object->data.sprite) != nullptr )
  {
    XPos = idSWFSpriteInstance::GetXPos(this: sprite);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = XPos;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__x_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__y@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794D68
// RVA : 0x00794D68
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFSpriteInstance *sprite; // r3
  double YPos; // fp31

  if ( object != nullptr && object->objectType == SWF_OBJECT_SPRITE && (sprite = object->data.sprite) != nullptr )
  {
    YPos = idSWFSpriteInstance::GetYPos(this: sprite);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = YPos;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__y_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__xscale@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794DF0
// RVA : 0x00794DF0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  double v7; // fp9
  double v8; // fp8
  double v9; // fp1

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        v7 = (float)((float)(DisplayEntry->matrix.xy * (float)0.0) + DisplayEntry->matrix.xx);
        v8 = (float)((float)(DisplayEntry->matrix.yy * (float)0.0) + DisplayEntry->matrix.yx);
        v9 = (float)((float)__fsqrts((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                   * (float)100.0);
      }
      else
      {
        idLib::Warning(fmt: "_xscale: Couldn't find our display entry in our parents display list");
        v9 = 1.0;
      }
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: v9);
    }
    else
    {
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale_vtbl *)2;
      *((float *)this + 1) = 1.0;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__xscale_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__yscale@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82794F00
// RVA : 0x00794F00
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  double v7; // fp9
  double v8; // fp8
  double v9; // fp1

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        v7 = (float)((float)(DisplayEntry->matrix.xx * (float)0.0) + DisplayEntry->matrix.xy);
        v8 = (float)((float)(DisplayEntry->matrix.yx * (float)0.0) + DisplayEntry->matrix.yy);
        v9 = (float)((float)__fsqrts((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                   * (float)100.0);
      }
      else
      {
        idLib::Warning(fmt: "_yscale: Couldn't find our display entry in our parents display list");
        v9 = 1.0;
      }
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: v9);
    }
    else
    {
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale_vtbl *)2;
      *((float *)this + 1) = 1.0;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__yscale_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__alpha@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795010
// RVA : 0x00795010
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  double w; // fp1

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        w = DisplayEntry->cxf.mul.w;
      }
      else
      {
        idLib::Warning(fmt: "_alpha: Couldn't find our display entry in our parents display list");
        w = 1.0;
      }
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: w);
    }
    else
    {
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)2;
      *((float *)this + 1) = 1.0;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__brightness@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x827950E8
// RVA : 0x007950E8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  idSWFScriptVar *v7; // r3
  double v8; // fp1
  double v9; // fp0

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        v8 = (float)((float)((float)(DisplayEntry->cxf.add.z + DisplayEntry->cxf.add.y) + DisplayEntry->cxf.add.x)
                   * (float)0.33333334);
        v9 = (float)((float)((float)(DisplayEntry->cxf.mul.z + DisplayEntry->cxf.mul.y) + DisplayEntry->cxf.mul.x)
                   * (float)0.33333334);
        v7 = (idSWFScriptVar *)this;
        if ( v8 <= 1.0 )
          v8 = (float)((float)v9 - (float)1.0);
      }
      else
      {
        idLib::Warning(fmt: "_brightness: Couldn't find our display entry in our parents display list");
        v7 = (idSWFScriptVar *)this;
        v8 = 1.0;
      }
      idSWFScriptVar::idSWFScriptVar(this: v7, f: v8);
    }
    else
    {
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness_vtbl *)2;
      *((float *)this + 1) = 1.0;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__brightness_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__visible@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795208
// RVA : 0x00795208
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  bool isVisible; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    isVisible = v4.sprite->isVisible;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = isVisible;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__rotation@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795288
// RVA : 0x00795288
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  double v7; // fp10
  double v8; // fp9
  double v11; // fp3
  long double v12; // fp2
  double v13; // fp7
  double v14; // fp30
  double v15; // fp1

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        v7 = (float)((float)(DisplayEntry->matrix.yx * (float)0.0) + DisplayEntry->matrix.yy);
        v8 = (float)((float)(DisplayEntry->matrix.xx * (float)0.0) + DisplayEntry->matrix.xy);
        _FP6 = (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f4, f6, f7, f13 }
        v11 = __frsqrte(_FP4);
        *((double *)&v12 + 1) = (float)v11;
        v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                            * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5))
                                                                                    * (float)v11)
                                                                            - (float)1.5)
                                                            * (float)v11)
                                                    * (float)((float)((float)((float)v8 * (float)v8)
                                                                    + (float)((float)v7 * (float)v7))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v11
                                                                                    * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))
                                                                                            * (float)0.5))
                                                                            * (float)v11)
                                                                    - (float)1.5)
                                                    * (float)v11))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v11
                                                            * (float)((float)((float)((float)v8 * (float)v8)
                                                                            + (float)((float)v7 * (float)v7))
                                                                    * (float)0.5))
                                                    * (float)v11)
                                            - (float)1.5)
                            * (float)v11));
        *(double *)&v12 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11) - (float)1.5) * (float)v11) * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11) - (float)1.5) * (float)v11))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                        * (float)v11))
                                                                        * (float)((float)((float)((float)v8 * (float)v8)
                                                                                        + (float)((float)v7 * (float)v7))
                                                                                * (float)0.5))
                                                                * (float)v13)
                                                        - (float)1.5)
                                        * (float)v13)
                                * (float)v7);
        v14 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11) - (float)1.5) * (float)v11) * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11) - (float)1.5) * (float)v11))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5)) * (float)v11)
                                                                                            - (float)1.5)
                                                                            * (float)v11))
                                                            * (float)((float)((float)((float)v8 * (float)v8)
                                                                            + (float)((float)v7 * (float)v7))
                                                                    * (float)0.5))
                                                    * (float)v13)
                                            - (float)1.5)
                            * (float)v13)
                    * (float)v8);
        v15 = (float)(idMath::ACos(a: v12) * idMath::M_RAD2DEG);
        if ( v14 < 0.0 )
          v15 = -v15;
      }
      else
      {
        idLib::Warning(fmt: "_rotation: Couldn't find our display entry in our parents display list");
        v15 = 0.0;
      }
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: v15);
    }
    else
    {
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation_vtbl *)2;
      *((float *)this + 1) = 0.0;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__rotation_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__name@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795408
// RVA : 0x00795408
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: v4.sprite->name.str);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__name_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__currentframe@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795470
// RVA : 0x00795470
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int currentFrame; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    currentFrame = v4.sprite->currentFrame;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = currentFrame;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__framesloaded@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x827954F0
// RVA : 0x007954F0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int frameCount; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    frameCount = v4.sprite->frameCount;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = frameCount;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__framesloaded_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__mousex@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795570
// RVA : 0x00795570
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  int v6; // r30
  __int64 v7; // r10
  swfDisplayEntry_t *DisplayEntry; // r3

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        LODWORD(v7) = idSWF::mouseX;
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: (float)((float)v7 - DisplayEntry->matrix.ty));
      }
      else
      {
        idLib::Warning(fmt: "_mousex: Couldn't find our display entry in our parents display list");
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)idSWF::mouseX);
      }
    }
    else
    {
      v6 = idSWF::mouseX;
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      *((_DWORD *)this + 1) = v6;
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex_vtbl *)6;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousex_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__mousey@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795670
// RVA : 0x00795670
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r30
  idSWFSpriteInstance *parent; // r3
  int v6; // r30
  __int64 v7; // r10
  swfDisplayEntry_t *DisplayEntry; // r3

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    parent = v4.sprite->parent;
    if ( parent != nullptr )
    {
      DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v4.sprite->depth);
      if ( DisplayEntry != nullptr && DisplayEntry->spriteInstance == v4.sprite )
      {
        LODWORD(v7) = idSWF::mouseY;
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, f: (float)((float)v7 - DisplayEntry->matrix.ty));
      }
      else
      {
        idLib::Warning(fmt: "_mousey: Couldn't find our display entry in our parents display list");
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)idSWF::mouseY);
      }
    }
    else
    {
      v6 = idSWF::mouseY;
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      *((_DWORD *)this + 1) = v6;
      this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey_vtbl *)6;
    }
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__mousey_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__itemindex@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795770
// RVA : 0x00795770
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int itemIndex; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    itemIndex = v4.sprite->itemIndex;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = itemIndex;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__itemindex_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_material@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x827957F0
// RVA : 0x007957F0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material *v3; // r31
  idSWFScriptObject::swfObjectData_t v4; // r11
  const idMaterial *materialOverride; // r11

  v3 = this;
  if ( object == nullptr
    || object->objectType != SWF_OBJECT_SPRITE
    || (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite == nullptr) )
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material_vtbl *)4;
    return v3;
  }
  materialOverride = v4.sprite->materialOverride;
  if ( materialOverride != nullptr )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: materialOverride->name.str);
    return v3;
  }
  this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_material_vtbl *)4;
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_materialWidth@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795880
// RVA : 0x00795880
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int materialWidth; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    materialWidth = v4.sprite->materialWidth;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = materialWidth;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialWidth_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_materialHeight@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795900
// RVA : 0x00795900
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int materialHeight; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    materialHeight = v4.sprite->materialHeight;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = materialHeight;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_materialHeight_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_xOffset@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795980
// RVA : 0x00795980
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  double xOffset; // fp31

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    xOffset = v4.sprite->xOffset;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = xOffset;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar_xOffset_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__followBorder@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82795A00
// RVA : 0x00795A00
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder::Get(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int followBorder; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_SPRITE
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    followBorder = v4.sprite->followBorder;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = followBorder;
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__followBorder_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?RunTo@idSWFSpriteInstance@@QAAXH@Z
// EA  : 0x82795A80
// RVA : 0x00795A80
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::RunTo(idSWFSpriteInstance *this, int targetFrame)
{
  int currentFrame; // r11
  int v4; // r27
  idSWFSprite *sprite; // r11
  unsigned __int64 v6; // r10
  int v7; // r7
  int *v8; // r6
  int v9; // r8
  int v10; // r5
  unsigned int v11; // r30
  unsigned int v12; // r25
  unsigned int v13; // r29
  idSWFSprite::swfSpriteCommand_t *v14; // r11
  idSWFBitStream *p_stream; // r4
  swfTag_t tag; // r3
  const char *TagName; // r3

  currentFrame = this->currentFrame;
  v4 = targetFrame;
  if ( targetFrame != currentFrame )
  {
    if ( targetFrame < currentFrame )
      idSWFSpriteInstance::FreeDisplayList(this);
    if ( v4 >= 1 )
    {
      sprite = this->sprite;
      if ( v4 > sprite->frameOffsets.num - 1 )
        v4 = sprite->frameOffsets.num - 1;
      HIDWORD(v6) = this->currentFrame;
      LODWORD(v6) = sprite->frameOffsets.list;
      v7 = __ROL4__(HIDWORD(v6), 2);
      v8 = (int *)(v6 + 4 * v4);
      v9 = v6;
      v10 = *v8;
      v11 = *(_DWORD *)(v7 + v6);
      v12 = *(v8 - 1);
      if ( v11 < *v8 )
      {
        v13 = v11;
        while ( 1 )
        {
          v14 = &this->sprite->commands.list[v13];
          if ( v14->tag == Tag_DoAction && v11 < v12 )
            goto LABEL_23;
          LODWORD(v6) = v14->stream.startp;
          p_stream = &v14->stream;
          v14->stream.readp = (const unsigned __int8 *)v6;
          tag = v14->tag;
          if ( v14->tag > Tag_PlaceObject2 )
            break;
          if ( v14->tag == Tag_PlaceObject2 )
          {
            idSWFSpriteInstance::PlaceObject2(this, bitstream: p_stream);
          }
          else if ( tag == Tag_DoAction )
          {
            idSWFSpriteInstance::DoAction(this, bitstream: p_stream);
          }
          else
          {
            if ( tag != Tag_StartSound )
              goto LABEL_20;
            idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
          }
LABEL_23:
          ++v11;
          ++v13;
          HIDWORD(v6) = this->sprite->frameOffsets.list[v4];
          if ( v11 >= HIDWORD(v6) )
            goto LABEL_24;
        }
        if ( tag == Tag_RemoveObject2 )
        {
          idSWFSpriteInstance::RemoveObject2(this, bitstream: p_stream, a3: v10, a4: (int)v8, a5: v7, a6: v9, a7: v6);
          goto LABEL_23;
        }
        if ( tag == Tag_PlaceObject3 )
        {
          idSWFSpriteInstance::PlaceObject3(this, bitstream: p_stream);
          goto LABEL_23;
        }
LABEL_20:
        TagName = idSWF::GetTagName(tag);
        idLib::Printf(fmt: "Run Sprite: Unhandled tag %s\n", TagName);
        goto LABEL_23;
      }
LABEL_24:
      this->currentFrame = v4;
    }
  }
}


// ========================================================================
// ?PlayFrame@idSWFSpriteInstance@@QAAXABVidSWFParmList@@@Z
// EA  : 0x82795BE0
// RVA : 0x00795BE0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::PlayFrame(idSWFSpriteInstance *this, const idSWFParmList *parms)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idSWFScriptVar *v7; // r3
  int Frame; // r3
  idSWFSpriteInstance *i; // r11
  idStr v10[2]; // [sp+50h] [-40h] BYREF

  if ( parms->num <= 0 )
  {
    idLib::Warning(fmt: "gotoAndPlay: expected 1 parameter");
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actions);
    v7 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v10, result: (idStr *)parms->list, a3: v6, a4: v5, a5: v4);
    Frame = idSWFSpriteInstance::FindFrame(this, labelName: (const char *)v7->value.i);
    idSWFSpriteInstance::RunTo(this, targetFrame: Frame);
    idStr::FreeData(this: v10);
    for ( i = this->parent; i != nullptr; i = i->parent )
      i->childrenRunning = true;
    this->isPlaying = true;
  }
}


// ========================================================================
// __unwind$230088
// EA  : 0x82795C74
// RVA : 0x00795C74
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230088()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?StopFrame@idSWFSpriteInstance@@QAAXABVidSWFParmList@@@Z
// EA  : 0x82795CA8
// RVA : 0x00795CA8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::StopFrame(
        idSWFSpriteInstance *this,
        const idSWFParmList *parms,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v8; // r11
  bool v9; // zf
  int Frame; // r3
  idSWFScriptVar *v11; // r3
  int v12; // r3
  idStr v13[2]; // [sp+60h] [-40h] BYREF

  if ( parms->num <= 0 )
  {
    idLib::Warning(fmt: "gotoAndStop: expected 1 parameter");
  }
  else
  {
    type = parms->list->type;
    if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v9 = type != SWF_VAR_BOOL, v8 = 0, !v9) )
      v8 = 1;
    if ( v8 != 0 && idSWFScriptVar::ToInteger(this: parms->list) < 1 )
    {
      Frame = idSWFSpriteInstance::FindFrame(this, labelName: "1");
      idSWFSpriteInstance::RunTo(this, targetFrame: Frame);
      this->isPlaying = false;
    }
    else
    {
      v11 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v13, result: (idStr *)parms->list, a3, a4, a5);
      v12 = idSWFSpriteInstance::FindFrame(this, labelName: (const char *)v11->value.i);
      idSWFSpriteInstance::RunTo(this, targetFrame: v12);
      idStr::FreeData(this: v13);
      this->isPlaying = false;
    }
  }
}


// ========================================================================
// __unwind$230137
// EA  : 0x82795D88
// RVA : 0x00795D88
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230137()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_gotoAndPlay@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82795DB8
// RVA : 0x00795DB8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v6; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idSWFScriptVar *v10; // r3
  int Frame; // r3
  idSWFSpriteInstance *i; // r11
  idStr v14[2]; // [sp+60h] [-50h] BYREF

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (v6.sprite = (idSWFSpriteInstance *)thisObject->data, v6.sprite != nullptr) )
  {
    if ( parms->num <= 0 )
    {
      idLib::Warning(fmt: "gotoAndPlay: expected 1 parameter");
    }
    else
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v6.sprite->actions);
      v10 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v14, result: (idStr *)parms->list, a3: v9, a4: v8, a5: v7);
      Frame = idSWFSpriteInstance::FindFrame(this: v6.sprite, labelName: (const char *)v10->value.i);
      idSWFSpriteInstance::RunTo(this: v6.sprite, targetFrame: Frame);
      idStr::FreeData(this: v14);
      for ( i = v6.sprite->parent; i != nullptr; i = i->parent )
        i->childrenRunning = true;
      v6.sprite->isPlaying = true;
    }
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call gotoAndPlay on NULL sprite");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndPlay_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$230200
// EA  : 0x82795E98
// RVA : 0x00795E98
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230200()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_gotoAndStop@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82795EC8
// RVA : 0x00795EC8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idStr **v6; // r29
  idSWFSpriteInstance *v7; // r30
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  int Frame; // r3
  idSWFScriptVar *v12; // r3
  int v13; // r3
  idStr v15[2]; // [sp+60h] [-50h] BYREF

  v6 = (idStr **)parms;
  if ( HIDWORD(parms) != 0
    && *(_DWORD *)(HIDWORD(parms) + 88) == 2
    && (v7 = *(idSWFSpriteInstance **)(HIDWORD(parms) + 92)) != nullptr )
  {
    if ( *(int *)(parms + 4) <= 0 )
    {
      idLib::Warning(fmt: "gotoAndStop: expected 1 parameter");
    }
    else
    {
      v8 = **(_DWORD **)parms;
      if ( v8 == 2 || v8 == 6 || (v10 = v8 != 5, v9 = 0, !v10) )
        v9 = 1;
      if ( v9 != 0 && idSWFScriptVar::ToInteger(this: *(idSWFScriptVar **)parms) < 1 )
      {
        Frame = idSWFSpriteInstance::FindFrame(this: v7, labelName: "1");
        idSWFSpriteInstance::RunTo(this: v7, targetFrame: Frame);
        v7->isPlaying = false;
      }
      else
      {
        v12 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v15, result: *v6, a3: parms, a4, a5);
        v13 = idSWFSpriteInstance::FindFrame(this: v7, labelName: (const char *)v12->value.i);
        idSWFSpriteInstance::RunTo(this: v7, targetFrame: v13);
        idStr::FreeData(this: v15);
        v7->isPlaying = false;
      }
    }
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call gotoAndStop on NULL sprite");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_gotoAndStop_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$230269
// EA  : 0x82795FEC
// RVA : 0x00795FEC
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230269()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Run@idSWFSpriteInstance@@QAA_NXZ
// EA  : 0x82796018
// RVA : 0x00796018
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

int __fastcall idSWFSpriteInstance::Run(idSWFSpriteInstance *this)
{
  int num; // r6
  int v4; // r11
  int v5; // r10
  swfDisplayEntry_t *list; // r9
  int v8; // r29
  int v9; // r30
  swfDisplayEntry_t *v10; // r11
  unsigned int frameCount; // r10
  int currentFrame; // r11
  int v13; // r4
  unsigned __int8 v14; // r11

  if ( !this->isVisible )
    return 0;
  if ( this->childrenRunning )
  {
    num = this->displayList.num;
    v4 = 0;
    v5 = 0;
    this->childrenRunning = false;
    if ( num > 0 )
    {
      list = this->displayList.list;
      do
      {
        _R9 = list->spriteInstance;
        if ( _R9 != nullptr )
          __asm { dcbt      0, r9 }
        ++v5;
        list = &this->displayList.list[++v4];
      }
      while ( v5 < num );
    }
    v8 = 0;
    if ( num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->displayList.list[v9];
        if ( v10->spriteInstance != nullptr )
          this->childrenRunning |= idSWFSpriteInstance::Run(this: v10->spriteInstance);
        ++v8;
        ++v9;
      }
      while ( v8 < this->displayList.num );
    }
  }
  if ( this->isPlaying )
  {
    frameCount = this->frameCount;
    currentFrame = this->currentFrame;
    if ( currentFrame == frameCount )
    {
      if ( frameCount <= 1 )
        goto LABEL_20;
      idSWFSpriteInstance::FreeDisplayList(this);
      v13 = 1;
    }
    else
    {
      v13 = currentFrame + 1;
    }
    idSWFSpriteInstance::RunTo(this, targetFrame: v13);
  }
LABEL_20:
  if ( this->childrenRunning )
    return 1;
  v14 = 0;
  if ( this->isPlaying )
    return 1;
  return v14;
}


// ========================================================================
// ?NextFrame@idSWFSpriteInstance@@QAAXXZ
// EA  : 0x82796150
// RVA : 0x00796150
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::NextFrame(idSWFSpriteInstance *this)
{
  unsigned int currentFrame; // r11

  currentFrame = this->currentFrame;
  if ( currentFrame < this->frameCount )
    idSWFSpriteInstance::RunTo(this, targetFrame: currentFrame + 1);
}


// ========================================================================
// ?PrevFrame@idSWFSpriteInstance@@QAAXXZ
// EA  : 0x82796170
// RVA : 0x00796170
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::PrevFrame(idSWFSpriteInstance *this)
{
  unsigned int currentFrame; // r11

  currentFrame = this->currentFrame;
  if ( currentFrame > 1 )
    idSWFSpriteInstance::RunTo(this, targetFrame: currentFrame - 1);
}


// ========================================================================
// ?Call@idSWFScriptFunction_nextFrame@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82796188
// RVA : 0x00796188
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFSpriteInstance *sprite; // r3
  unsigned int currentFrame; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (sprite = thisObject->data.sprite) != nullptr )
  {
    currentFrame = sprite->currentFrame;
    if ( currentFrame < sprite->frameCount )
      idSWFSpriteInstance::RunTo(this: sprite, targetFrame: currentFrame + 1);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call nextFrame on NULL sprite", result);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_nextFrame_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_prevFrame@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82796210
// RVA : 0x00796210
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFSpriteInstance *sprite; // r3
  unsigned int currentFrame; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_SPRITE
    && (sprite = thisObject->data.sprite) != nullptr )
  {
    currentFrame = sprite->currentFrame;
    if ( currentFrame > 1 )
      idSWFSpriteInstance::RunTo(this: sprite, targetFrame: currentFrame - 1);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call prevFrame on NULL sprite", result);
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_prevFrame_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Init@idSWFSpriteInstance@@QAAXPAVidSWFSprite@@PAV1@PBDH@Z
// EA  : 0x82796298
// RVA : 0x00796298
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::Init(
        idSWFSpriteInstance *this,
        idSWFSprite *_sprite,
        idSWFSpriteInstance *_parent,
        const char *_name,
        int _depth)
{
  idSWFSpriteInstance *parent; // r11
  idSWFScriptObject *v7; // r3
  idSWFScriptObject *scriptObject; // r6
  int v9; // r27
  int v10; // r29
  idSWFScriptFunction_Script *actionScript; // r10
  const unsigned __int8 *startp; // r8
  const unsigned __int8 *endp; // r9
  idSWFSpriteInstance *i; // r11
  idSWFBitStream *v15; // [sp+50h] [-110h]
  idList<enum encounterGroupRole_t,5> v16; // [sp+60h] [-100h] BYREF
  int v17; // [sp+70h] [-F0h] BYREF
  idSWFScriptVar v18[2]; // [sp+80h] [-E0h] BYREF
  idStaticList<idSWFScriptVar,16> v19; // [sp+90h] [-D0h] BYREF

  this->depth = _depth;
  this->sprite = _sprite;
  this->parent = _parent;
  idAtomicString::Set(this: &this->name, str_: _name);
  parent = this->parent;
  if ( parent != nullptr )
    ++parent->scriptObject->refCount;
  this->frameCount = this->sprite->frameCount;
  v7 = idSWFScriptObject::Alloc();
  this->scriptObject = v7;
  v7->prototype = &spriteInstanceScriptObjectPrototype;
  ++spriteInstanceScriptObjectPrototype.refCount;
  scriptObject = this->scriptObject;
  scriptObject->objectType = SWF_OBJECT_SPRITE;
  scriptObject->data.sprite = this;
  this->firstRun = true;
  this->actionScript = idSWFScriptFunction_Script::Alloc();
  v9 = 0;
  v16.granularity = 1;
  v16.listStatic = 1;
  v16.num = 0;
  v16.size = 4;
  v16.list = (encounterGroupRole_t *)&v17;
  v16.memTag = 5;
  idList<idAnimWebBlendTree *,5>::Append(this: &v16, obj: (const encounterGroupRole_t *)&this->sprite->swf->globals);
  idList<idAnimWebBlendTree *,5>::Append(this: &v16, obj: (const encounterGroupRole_t *)&this->scriptObject);
  idSWFScriptFunction_Script::SetScope(this: this->actionScript, newScope: (const idList<idMD6Filter *,5> *)&v16);
  v10 = 0;
  for ( this->actionScript->defaultSprite = this; v10 < this->sprite->doInitActions.num; ++v9 )
  {
    actionScript = this->actionScript;
    v15 = &this->sprite->doInitActions.list[v9];
    startp = v15->startp;
    endp = v15->endp;
    actionScript->data = startp;
    actionScript->length = endp - startp;
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v19);
    this->actionScript->Call(
      this: (struct idSWFScriptFunction_Script *)v18,
      result: (idSWFScriptVar *)this->actionScript,
      a3: this->scriptObject,
      a4: (const idSWFParmList *)&v19);
    idSWFScriptVar::Free(this: v18);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v19);
    ++v10;
  }
  for ( i = this->parent; i != nullptr; i = i->parent )
    i->childrenRunning = true;
  this->isPlaying = true;
  if ( (v16.listStatic == 0 || v16.listStatic == 2) && v16.list != nullptr )
    idMem::Free(this: &mem, ptr: v16.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$230697
// EA  : 0x8279647C
// RVA : 0x0079647C
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230697()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$230698
// EA  : 0x827964A4
// RVA : 0x007964A4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230698()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 352 + 144));
}


// ========================================================================
// ?AddDisplayEntry@idSWFSpriteInstance@@QAAPAUswfDisplayEntry_t@@HHABVidStr@@@Z
// EA  : 0x827964D8
// RVA : 0x007964D8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

swfDisplayEntry_t *__fastcall idSWFSpriteInstance::AddDisplayEntry(
        idSWFSpriteInstance *this,
        int depth,
        int characterID,
        const idStr *objectName)
{
  idSWFScriptVar::swfScriptVarType num; // r8
  int v9; // r5
  int v10; // r10
  swfDisplayEntry_t *v11; // r9
  int v12; // r9
  int v13; // r3
  swfDisplayEntry_t *list; // r11
  swfDisplayEntry_t *v15; // r29
  idSWFDictionaryEntry *DictionaryEntry; // r3
  idSWFDictionaryEntry *v17; // r28
  idSWFSpriteInstance *SpriteFromOrphanage; // r3
  idSWFSpriteInstance *v19; // r3
  idSWFScriptObject *scriptObject; // r28
  idSWFScriptVar *v22; // r3
  idSWFTextInstance *TextFromOrphanage; // r3
  idSWFTextInstance *v24; // r3
  idSWFScriptVar v25; // [sp+50h] [-A0h] BYREF
  idSWFScriptVar v26; // [sp+58h] [-98h] BYREF
  swfDisplayEntry_t v27; // [sp+60h] [-90h] BYREF

  num = this->displayList.num;
  v9 = 0;
  v25.type = num;
  if ( num <= SWF_VAR_STRINGID )
  {
LABEL_6:
    v27.characterID = 0;
    v27.depth = 0;
    v27.clipDepth = 0;
    v27.blendMode = 0;
    v27.spriteInstance = nullptr;
    v27.textInstance = nullptr;
    v27.matrix.xx = 1.0;
    v27.matrix.yy = 1.0;
    v27.matrix.xy = 0.0;
    v27.matrix.yx = 0.0;
    v27.matrix.tx = 0.0;
    v27.matrix.ty = 0.0;
    v27.cxf.mul.x = 1.0;
    v27.cxf.mul.y = 1.0;
    v27.cxf.mul.z = 1.0;
    v27.cxf.mul.w = 1.0;
    v27.cxf.add.x = 0.0;
    v27.cxf.add.y = 0.0;
    v27.cxf.add.z = 0.0;
    v27.cxf.add.w = 0.0;
    v27.ratio = 0.0;
    v13 = idList<swfDisplayEntry_t,72>::Insert(this: &this->displayList, obj: &v27, index: v9);
    list = this->displayList.list;
    list[v13].characterID = characterID;
    v15 = &list[v13];
    v15->depth = depth;
    DictionaryEntry = idSWF::FindDictionaryEntry(this: this->sprite->swf, characterID);
    v17 = DictionaryEntry;
    if ( DictionaryEntry != nullptr )
    {
      if ( DictionaryEntry->type == SWF_DICT_SPRITE )
      {
        SpriteFromOrphanage = idSWF::ExtractSpriteFromOrphanage(
                                this: this->sprite->swf,
                                name: objectName,
                                sprite: DictionaryEntry->sprite,
                                depth,
                                parent: this);
        v15->spriteInstance = SpriteFromOrphanage;
        if ( SpriteFromOrphanage == nullptr )
        {
          v19 = (idSWFSpriteInstance *)idBlockAlloc<idSWFSpriteInstance,16,72>::Alloc(this: &this->sprite->swf->spriteInstanceAllocator);
          v15->spriteInstance = v19;
          idSWFSpriteInstance::Init(
            this: v19,
            _sprite: v17->sprite,
            _parent: this,
            _name: objectName->data,
            _depth: depth);
          idSWFSpriteInstance::RunTo(this: v15->spriteInstance, targetFrame: 1);
        }
        scriptObject = v15->spriteInstance->scriptObject;
        v25.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v25);
        if ( scriptObject != nullptr )
        {
          v25.value.i = (int)scriptObject;
          v25.type = SWF_VAR_OBJECT;
          ++scriptObject->refCount;
        }
        else
        {
          v25.type = SWF_VAR_NULL;
        }
        idSWFScriptObject::Set(this: this->scriptObject, name: objectName->data, value: &v25);
        v22 = &v25;
_M230988_0:
        idSWFScriptVar::Free(this: v22);
        return v15;
      }
      if ( DictionaryEntry->type == SWF_DICT_EDITTEXT )
      {
        TextFromOrphanage = idSWF::ExtractTextFromOrphanage(
                              this: this->sprite->swf,
                              name: objectName,
                              editText: DictionaryEntry->edittext,
                              depth,
                              parent: this);
        v15->textInstance = TextFromOrphanage;
        if ( TextFromOrphanage == nullptr )
        {
          v24 = (idSWFTextInstance *)idBlockAlloc<idSWFTextInstance,16,72>::Alloc(this: &this->sprite->swf->textInstanceAllocator);
          v15->textInstance = v24;
          idSWFTextInstance::Init(
            this: v24,
            _editText: v17->edittext,
            _parent: this,
            _name: objectName->data,
            _depth: depth,
            _swf: this->sprite->swf);
        }
        idSWFScriptVar::idSWFScriptVar(this: &v26, o: v15->textInstance->scriptObject);
        idSWFScriptObject::Set(this: this->scriptObject, name: objectName->data, value: &v26);
        v22 = &v26;
        goto _M230988_0;
      }
    }
    return v15;
  }
  v10 = 0;
  v11 = this->displayList.list;
  while ( 1 )
  {
    v12 = v11->depth;
    if ( v12 == depth )
      return nullptr;
    if ( v12 <= depth )
    {
      ++v9;
      v11 = &this->displayList.list[++v10];
      if ( v9 < num )
        continue;
    }
    goto LABEL_6;
  }
}


// ========================================================================
// __unwind$230859
// EA  : 0x82796740
// RVA : 0x00796740
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230859()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$230860
// EA  : 0x82796768
// RVA : 0x00796768
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_230860()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// ?RunActions@idSWFSpriteInstance@@QAA_NXZ
// EA  : 0x82796798
// RVA : 0x00796798
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

int __fastcall idSWFSpriteInstance::RunActions(idSWFSpriteInstance *this)
{
  idSWFScriptObject::swfNamedVar_t *list; // r29
  idSWFScriptVar::swfScriptVarValue_t v4; // r29
  int v5; // r28
  int v6; // r29
  idSWFScriptFunction_Script *actionScript; // r10
  idSWFSpriteInstance::swfAction_t *v8; // r11
  const unsigned __int8 *data; // r8
  int v10; // r10
  int num; // r6
  int v12; // r11
  swfDisplayEntry_t *v13; // r9
  int v15; // r28
  int v16; // r29
  idSWFSpriteInstance *spriteInstance; // r3
  idSWFScriptObject v18; // [sp+50h] [-200h] BYREF
  idStaticList<idSWFScriptVar,16> v19; // [sp+100h] [-150h] BYREF
  idStaticList<idSWFScriptVar,16> v20; // [sp+190h] [-C0h] BYREF

  if ( this->isVisible )
  {
    if ( this->firstRun && idSWFScriptObject::HasProperty(this: this->scriptObject, name: "onLoad") )
    {
      this->firstRun = false;
      idSWFScriptObject::Get(this: &v18, result: this->scriptObject, name: "onLoad");
      list = v18.variables.list;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v18.variablesHash[3]);
      (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, int *))(list->index + 4))(
        a1: &v18.variablesHash[1],
        a2: list,
        a3: this->scriptObject,
        a4: &v18.variablesHash[3]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v18.variablesHash[1]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v18.variablesHash[3]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v18);
    }
    if ( this->onEnterFrame.type == SWF_VAR_FUNCTION )
    {
      LODWORD(v4.f) = this->onEnterFrame.value;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v19);
      (*(void (__fastcall **)(__int16 *, int __struct_ptr, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v4.i + 4))(
        a1: &v18.variables.granularity,
        a2: v4.i,
        a3: this->scriptObject,
        a4: &v19);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v18.variables.granularity);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v19);
    }
    v5 = 0;
    if ( this->actions.num > 0 )
    {
      v6 = 0;
      do
      {
        actionScript = this->actionScript;
        v8 = &this->actions.list[v6];
        data = v8->data;
        actionScript->length = v8->dataLength;
        actionScript->data = data;
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v20);
        this->actionScript->Call(
          this: (struct idSWFScriptFunction_Script *)&v18.variables.num,
          result: (idSWFScriptVar *)this->actionScript,
          a3: this->scriptObject,
          a4: (const idSWFParmList *)&v20);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v18.variables.num);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v20);
        ++v5;
        ++v6;
      }
      while ( v5 < this->actions.num );
    }
    if ( this->actions.size < 0 )
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actions);
    v10 = 0;
    this->actions.num = __CFADD__(-this->actions.size, this->actions.size ^ 0x80000000) ? 0 : this->actions.size;
    num = this->displayList.num;
    if ( num > 0 )
    {
      v12 = 0;
      v13 = this->displayList.list;
      do
      {
        _R9 = v13->spriteInstance;
        if ( _R9 != nullptr )
          __asm { dcbt      0, r9 }
        ++v10;
        v13 = &this->displayList.list[++v12];
      }
      while ( v10 < num );
    }
    v15 = 0;
    if ( num > 0 )
    {
      v16 = 0;
      do
      {
        spriteInstance = this->displayList.list[v16].spriteInstance;
        if ( spriteInstance != nullptr )
          idSWFSpriteInstance::RunActions(this: spriteInstance);
        ++v15;
        ++v16;
      }
      while ( v15 < this->displayList.num );
    }
    return 1;
  }
  else
  {
    idList<idSWFSpriteInstance::swfAction_t,72>::SetNum(this: &this->actions, newNum: 0);
    return 0;
  }
}


// ========================================================================
// __unwind$231013
// EA  : 0x827969D8
// RVA : 0x007969D8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231013()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 592 + 80));
}


// ========================================================================
// __unwind$231014
// EA  : 0x82796A00
// RVA : 0x00796A00
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231014()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 592 + 112));
}


// ========================================================================
// __unwind$231016
// EA  : 0x82796A28
// RVA : 0x00796A28
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231016()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 592 + 256));
}


// ========================================================================
// __unwind$231018
// EA  : 0x82796A50
// RVA : 0x00796A50
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231018()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 592 + 400));
}


// ========================================================================
// ?Call@idSWFScriptFunction_duplicateMovieClip@idSWFScriptObject_SpriteInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82796A80
// RVA : 0x00796A80
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip *__fastcall idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip::Call(
        idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v6; // r29
  idSWFSpriteInstance *parent; // r3
  __int64 v8; // r8
  __int64 v9; // r6
  swfDisplayEntry_t *DisplayEntry; // r3
  swfDisplayEntry_t *v11; // r30
  float *v12; // r10
  unsigned __int16 *p_clipDepth; // r11
  int i; // ctr
  __int64 v15; // r10
  _DWORD *p_ty; // r11
  int j; // ctr
  int characterID; // r30
  int v19; // r3
  swfDisplayEntry_t *v20; // r3
  swfDisplayEntry_t *v21; // r30
  double v23; // fp13
  double v24; // fp12
  double v25; // fp11
  double v26; // fp10
  double v27; // fp9
  idSWFSpriteInstance *spriteInstance; // r3
  double v29; // fp7
  double v30; // fp6
  double v31; // fp5
  double v32; // fp4
  double v33; // fp3
  double v34; // fp2
  double v35; // fp1
  float v36[8]; // [sp+5Ch] [-94h] BYREF
  float v37[9]; // [sp+7Ch] [-74h] BYREF
  idStr v38[2]; // [sp+A0h] [-50h] BYREF

  if ( thisObject == nullptr
    || thisObject->objectType != SWF_OBJECT_SPRITE
    || (v6.sprite = (idSWFSpriteInstance *)thisObject->data, v6.sprite == nullptr) )
  {
    idLib::Warning(fmt: "SWF: tried to call duplicateMovieClip on NULL sprite");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)4;
    return this;
  }
  parent = v6.sprite->parent;
  if ( parent == nullptr )
  {
    idLib::Warning(fmt: "Tried to duplicate root movie clip");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)4;
    return this;
  }
  if ( parms->num < 2 )
  {
    idLib::Warning(fmt: "duplicateMovieClip: expected 2 parameters");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)4;
    return this;
  }
  DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: v6.sprite->depth);
  v11 = DisplayEntry;
  if ( DisplayEntry == nullptr || DisplayEntry->spriteInstance != v6.sprite )
  {
    idLib::Warning(fmt: "duplicateMovieClip: Couldn't find our display entry in our parents display list");
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)4;
    return this;
  }
  v12 = v36;
  p_clipDepth = &DisplayEntry->clipDepth;
  for ( i = 6; i != 0; --i )
  {
    p_clipDepth += 2;
    *++v12 = *(float *)p_clipDepth;
  }
  LODWORD(v15) = v37;
  p_ty = (_DWORD *)&DisplayEntry->matrix.ty;
  for ( j = 8; j != 0; --j )
  {
    HIDWORD(v15) = *++p_ty;
    LODWORD(v15) = v15 + 4;
    *(_DWORD *)v15 = *p_ty;
  }
  idSWFScriptVar::ToString(this: (idSWFScriptVar *)v38, result: (idStr *)parms->list, a3: v9, a4: v8, a5: v15);
  characterID = v11->characterID;
  v19 = idSWFScriptVar::ToInteger(this: parms->list + 1);
  v20 = idSWFSpriteInstance::AddDisplayEntry(this: v6.sprite->parent, depth: v19 + 0x4000, characterID, objectName: v38);
  v21 = v20;
  if ( v20 != nullptr )
  {
    v23 = v36[2];
    v24 = v36[3];
    v25 = v36[4];
    v26 = v36[5];
    v27 = v36[6];
    spriteInstance = v20->spriteInstance;
    v21->matrix.xx = v36[1];
    v21->matrix.yy = v23;
    v21->matrix.xy = v24;
    v21->matrix.yx = v25;
    v21->matrix.tx = v26;
    v21->matrix.ty = v27;
    v29 = v37[2];
    v30 = v37[3];
    v31 = v37[4];
    v32 = v37[5];
    v33 = v37[6];
    v34 = v37[7];
    v35 = v37[8];
    v21->cxf.mul.x = v37[1];
    v21->cxf.mul.y = v29;
    v21->cxf.mul.z = v30;
    v21->cxf.mul.w = v31;
    v21->cxf.add.x = v32;
    v21->cxf.add.y = v33;
    v21->cxf.add.z = v34;
    v21->cxf.add.w = v35;
    idSWFSpriteInstance::RunTo(this: spriteInstance, targetFrame: 1);
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, o: v21->spriteInstance->scriptObject);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_SpriteInstancePrototype::idSWFScriptFunction_duplicateMovieClip_vtbl *)4;
  }
  idStr::FreeData(this: v38);
  return this;
}


// ========================================================================
// __unwind$231329
// EA  : 0x82796CB0
// RVA : 0x00796CB0
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231329()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 240;
  if ( (*(_DWORD *)(v0 - 240 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 260));
  }
}


// ========================================================================
// __unwind$231332
// EA  : 0x82796CF4
// RVA : 0x00796CF4
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void _unwind_231332()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// `dynamic initializer for 'spriteInstanceScriptObjectPrototype''
// EA  : 0x83341D78
// RVA : 0x01341D78
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spriteInstanceScriptObjectPrototype__()
{
  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptObject_SpriteInstancePrototype(this: &spriteInstanceScriptObjectPrototype);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spriteInstanceScriptObjectPrototype__);
}

