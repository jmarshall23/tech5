#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf.h
// Recovered logical types: 42
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2774; PDB kind: unknown.
enum idSWF::<unnamed_tag> : __int32
{
  FOLLOW_NONE = 0xFFFFFFFF,
  FOLLOW_TOPLEFT = 0x0,
  FOLLOW_TOPCENTER = 0x1,
  FOLLOW_TOPRIGHT = 0x2,
  FOLLOW_CENTERLEFT = 0x3,
  FOLLOW_CENTERCENTER = 0x4,
  FOLLOW_CENTERRIGHT = 0x5,
  FOLLOW_BOTTOMLEFT = 0x6,
  FOLLOW_BOTTOMCENTER = 0x7,
  FOLLOW_BOTTOMRIGHT = 0x8,
};

// IDA Local Type ordinal 14777; PDB kind: class.
class idSWF
{
public:
  idAtomicString filename;
  unsigned int timestamp;
  bool isActive;
  bool inhibitControl;
  bool useInhibtControl;
  bool pausedRender;
  float frameWidth;
  float frameHeight;
  unsigned __int16 frameRate;
  float renderBorder;
  float swfScale;
  int userDeviceNumber;
  int lastRenderTime;
  bool mouseEnabled;
  bool useMouse;
  idSWFScriptObject *mouseObject;
  idSWFScriptObject *hoverObject;
  bool blackbars;
  bool crop;
  bool paused;
  bool hasHitObject;
  bool automaticRescale;
  idSWFSprite *mainsprite;
  idSWFSpriteInstance *mainspriteInstance;
  idSWFScriptObject *globals;
  idSWFScriptObject *shortcutKeys;
  idSoundEmitter *soundEmitter;
  idAtomicString atlasTextureName;
  const idMaterial *atlasMaterial;
  idImage *atlasImage;
  bool atlasPurgable;
  int atlasWidth;
  int atlasHeight;
  idFile *atlasFile;
  idBlockAlloc<idSWFSpriteInstance,16,72> spriteInstanceAllocator;
  idBlockAlloc<idSWFTextInstance,16,72> textInstanceAllocator;
  idList<idSWF::orphanedSprite_t,72> orphanedSprites;
  idList<idSWF::orphanedText_t,72> orphanedTexts;
  int c_TextInstanceAdoptions;
  int c_TextInstanceOrphans;
  int c_SpriteInstanceAdoptions;
  int c_SpriteInstanceOrphans;
  idSWF::idSWFScriptFunction_shortcutKeys_clear scriptFunction_shortcutKeys_clear;
  idSWF::idSWFScriptFunction_deactivate scriptFunction_deactivate;
  idSWF::idSWFScriptFunction_inhibitControl scriptFunction_inhibitControl;
  idSWF::idSWFScriptFunction_useInhibit scriptFunction_useInhibit;
  idSWF::idSWFScriptFunction_precacheSound scriptFunction_precacheSound;
  idSWF::idSWFScriptFunction_playSound scriptFunction_playSound;
  idSWF::idSWFScriptFunction_stopSounds scriptFunction_stopSounds;
  idSWF::idSWFScriptFunction_getPlatform scriptFunction_getPlatform;
  idSWF::idSWFScriptFunction_getTruePlatform scriptFunction_getTruePlatform;
  idSWF::idSWFScriptFunction_getLocalString scriptFunction_getLocalString;
  idSWF::idSWFScriptFunction_isMultiplayer scriptFunction_isMultiplayer;
  idSWF::idSWFScriptFunction_swapPS3Buttons scriptFunction_swapPS3Buttons;
  idSWF::idSWFScriptFunction_getCVarInteger scriptFunction_getCVarInteger;
  idSWF::idSWFScriptFunction_setCVarInteger scriptFunction_setCVarInteger;
  idSWF::idSWFScriptFunction_strReplace scriptFunction_strReplace;
  idSWF::idSWFScriptFunction_isJapanese scriptFunction_isJapanese;
  idSWF::idSWFScriptFunction_acos scriptFunction_acos;
  idSWF::idSWFScriptFunction_cos scriptFunction_cos;
  idSWF::idSWFScriptFunction_sin scriptFunction_sin;
  idSWF::idSWFScriptFunction_round scriptFunction_round;
  idSWF::idSWFScriptFunction_pow scriptFunction_pow;
  idSWF::idSWFScriptFunction_sqrt scriptFunction_sqrt;
  idSWF::idSWFScriptFunction_abs scriptFunction_abs;
  idSWF::idSWFScriptFunction_rand scriptFunction_rand;
  idSWF::idSWFScriptFunction_floor scriptFunction_floor;
  idSWF::idSWFScriptFunction_ceil scriptFunction_ceil;
  idSWF::idSWFScriptFunction_toUpper scriptFunction_toUpper;
  idSWF::idSWFScriptNativeVar_platform swfScriptVar_platform;
  idSWF::idSWFScriptNativeVar_blackbars swfScriptVar_blackbars;
  idSWF::idSWFScriptNativeVar_crop swfScriptVar_crop;
  idSWF::idSWFScriptNativeVar_automaticRescale swfScriptVar_automaticRescale;
  idSWF::idSWFScriptFunction_Object scriptFunction_Object;
  idList<idSWFDictionaryEntry,72> dictionary;
  idList<idSWF::keyButtonImages_t,72> tooltipButtonImage;
  idList<idSWF::tooltipIcon_t,72> tooltipIconList;
  const idMaterial *guiSolid;
  const idMaterial *guiStencilIncr;
  const idMaterial *guiStencilDecr;
  const idMaterial *guiCursor_arrow;
  const idMaterial *guiCursor_hand;
  const idMaterial *white;
  idSWF::idDecompressJPEG jpeg;
  idList<idSWF::imageToPack_t,72> packImages;
};

// IDA Local Type ordinal 14817; PDB kind: struct.
struct __declspec(align(4)) idSWF::orphanedSprite_t
{
  idSWFSpriteInstance *spriteInstance;
  bool wasPlaying;
};

// IDA Local Type ordinal 14819; PDB kind: struct.
struct idSWF::orphanedText_t
{
  idSWFTextInstance *textInstance;
};

// IDA Local Type ordinal 14823; PDB kind: class.
class idSWF::idSWFScriptFunction_shortcutKeys_clear : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14824.
  virtual ~idSWFScriptFunction_shortcutKeys_clear();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14825; PDB kind: class.
class idSWF::idSWFScriptFunction_deactivate : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14826.
  virtual ~idSWFScriptFunction_deactivate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14827; PDB kind: class.
class idSWF::idSWFScriptFunction_inhibitControl : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14828.
  virtual ~idSWFScriptFunction_inhibitControl();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14829; PDB kind: class.
class idSWF::idSWFScriptFunction_useInhibit : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14830.
  virtual ~idSWFScriptFunction_useInhibit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14831; PDB kind: class.
class idSWF::idSWFScriptFunction_precacheSound : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14832.
  virtual ~idSWFScriptFunction_precacheSound();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14833; PDB kind: class.
class idSWF::idSWFScriptFunction_playSound : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14834.
  virtual ~idSWFScriptFunction_playSound();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14835; PDB kind: class.
class idSWF::idSWFScriptFunction_stopSounds : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14836.
  virtual ~idSWFScriptFunction_stopSounds();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14837; PDB kind: class.
class idSWF::idSWFScriptFunction_getPlatform : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14838.
  virtual ~idSWFScriptFunction_getPlatform();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14839; PDB kind: class.
class idSWF::idSWFScriptFunction_getTruePlatform : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14840.
  virtual ~idSWFScriptFunction_getTruePlatform();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14841; PDB kind: class.
class idSWF::idSWFScriptFunction_getLocalString : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14842.
  virtual ~idSWFScriptFunction_getLocalString();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14843; PDB kind: class.
class idSWF::idSWFScriptFunction_isMultiplayer : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14844.
  virtual ~idSWFScriptFunction_isMultiplayer();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14845; PDB kind: class.
class idSWF::idSWFScriptFunction_swapPS3Buttons : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14846.
  virtual ~idSWFScriptFunction_swapPS3Buttons();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14847; PDB kind: class.
class idSWF::idSWFScriptFunction_getCVarInteger : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14848.
  virtual ~idSWFScriptFunction_getCVarInteger();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14849; PDB kind: class.
class idSWF::idSWFScriptFunction_setCVarInteger : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14850.
  virtual ~idSWFScriptFunction_setCVarInteger();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14851; PDB kind: class.
class idSWF::idSWFScriptFunction_strReplace : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14852.
  virtual ~idSWFScriptFunction_strReplace();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14853; PDB kind: class.
class idSWF::idSWFScriptFunction_isJapanese : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14854.
  virtual ~idSWFScriptFunction_isJapanese();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14855; PDB kind: class.
class idSWF::idSWFScriptFunction_acos : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14856.
  virtual ~idSWFScriptFunction_acos();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14857; PDB kind: class.
class idSWF::idSWFScriptFunction_cos : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14858.
  virtual ~idSWFScriptFunction_cos();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14859; PDB kind: class.
class idSWF::idSWFScriptFunction_sin : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14860.
  virtual ~idSWFScriptFunction_sin();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14861; PDB kind: class.
class idSWF::idSWFScriptFunction_round : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14862.
  virtual ~idSWFScriptFunction_round();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14863; PDB kind: class.
class idSWF::idSWFScriptFunction_pow : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14864.
  virtual ~idSWFScriptFunction_pow();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14865; PDB kind: class.
class idSWF::idSWFScriptFunction_sqrt : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14866.
  virtual ~idSWFScriptFunction_sqrt();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14867; PDB kind: class.
class idSWF::idSWFScriptFunction_abs : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14868.
  virtual ~idSWFScriptFunction_abs();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14869; PDB kind: class.
class idSWF::idSWFScriptFunction_rand : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14870.
  virtual ~idSWFScriptFunction_rand();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14871; PDB kind: class.
class idSWF::idSWFScriptFunction_floor : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14872.
  virtual ~idSWFScriptFunction_floor();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14873; PDB kind: class.
class idSWF::idSWFScriptFunction_ceil : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14874.
  virtual ~idSWFScriptFunction_ceil();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14875; PDB kind: class.
class idSWF::idSWFScriptFunction_toUpper : public idSWFScriptFunction_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14876.
  virtual ~idSWFScriptFunction_toUpper();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14879; PDB kind: class.
class idSWF::idSWFScriptNativeVar_platform : public idSWFScriptNativeVariable_Nested<idSWF::idSWFScriptFunction_getPlatform>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14880.
  virtual ~idSWFScriptNativeVar_platform();
  virtual bool IsReadOnly();
  virtual void Set(idSWFScriptObject *, const idSWFScriptVar *);
  virtual idSWFScriptVar *Get(idSWFScriptVar *result, idSWFScriptObject *);

};

// IDA Local Type ordinal 14883; PDB kind: class.
class idSWF::idSWFScriptNativeVar_blackbars : public idSWFScriptNativeVariable_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14884.
  virtual ~idSWFScriptNativeVar_blackbars();
  virtual bool IsReadOnly();
  virtual void Set(idSWFScriptObject *, const idSWFScriptVar *);
  virtual idSWFScriptVar *Get(idSWFScriptVar *result, idSWFScriptObject *);

};

// IDA Local Type ordinal 14885; PDB kind: class.
class idSWF::idSWFScriptNativeVar_crop : public idSWFScriptNativeVariable_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14886.
  virtual ~idSWFScriptNativeVar_crop();
  virtual bool IsReadOnly();
  virtual void Set(idSWFScriptObject *, const idSWFScriptVar *);
  virtual idSWFScriptVar *Get(idSWFScriptVar *result, idSWFScriptObject *);

};

// IDA Local Type ordinal 14887; PDB kind: class.
class idSWF::idSWFScriptNativeVar_automaticRescale : public idSWFScriptNativeVariable_Nested<idSWF>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14888.
  virtual ~idSWFScriptNativeVar_automaticRescale();
  virtual bool IsReadOnly();
  virtual void Set(idSWFScriptObject *, const idSWFScriptVar *);
  virtual idSWFScriptVar *Get(idSWFScriptVar *result, idSWFScriptObject *);

};

// IDA Local Type ordinal 14889; PDB kind: class.
class idSWF::idSWFScriptFunction_Object : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14890.
  virtual ~idSWFScriptFunction_Object();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject object;
};

// IDA Local Type ordinal 14916; PDB kind: struct.
struct idSWF::keyButtonImages_t
{
  const char *key;
  const char *xbImage;
  const char *psImage;
  int width;
  int height;
  int baseline;
};

// IDA Local Type ordinal 14918; PDB kind: struct.
struct idSWF::tooltipIcon_t
{
  int startIndex;
  int endIndex;
  const idMaterial *material;
  __int16 imageWidth;
  __int16 imageHeight;
  int baseline;
};

// IDA Local Type ordinal 14920; PDB kind: class.
class idSWF::idDecompressJPEG
{
public:
  void *vinfo;
};

// IDA Local Type ordinal 14921; PDB kind: struct.
struct idSWF::imageToPack_t
{
  int characterID;
  idVec2i trueSize;
  unsigned __int8 *imageData;
  idVec2i allocSize;
};

// IDA Local Type ordinal 22057; PDB kind: class.
class idSWF::idSortBlocks : public idSort_Quick<idSWF::imageToPack_t,idSWF::idSortBlocks>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22058.
  virtual ~idSortBlocks();
  virtual void Sort(idSWF::imageToPack_t *, unsigned int);

};

// IDA Local Type ordinal 23387; PDB kind: struct.
struct idSWF::Inflate::__l2::local_swf_alloc_t
{
};
