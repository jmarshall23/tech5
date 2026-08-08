
// ========================================================================
// ?DefaultDefinition@idDeclRenderProg@@UBAPBDXZ
// EA  : 0x828AEA80
// RVA : 0x008AEA80
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

const char *__fastcall idDeclRenderProg::DefaultDefinition(idDeclRenderProg *this)
{
  return "{\tstate { depthFunc GL_LEQUAL }\n"
         "\thlsl_vp {\n"
         "\t\tresult.position.x = dot4( vertex.position, $mvpMatrixX );\n"
         "\t\tresult.position.y = dot4( vertex.position, $mvpMatrixY );\n"
         "\t\tresult.position.z = dot4( vertex.position, $mvpMatrixZ );\n"
         "\t\tresult.position.w = dot4( vertex.position, $mvpMatrixW );\n"
         "\t}\n"
         "\thlsl_fp {\n"
         "\t\tresult.color = float4( 0.2, 1.0, 0.4, 1.0 );\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ?Print@idDeclRenderProg@@UBAXXZ
// EA  : 0x828AEA90
// RVA : 0x008AEA90
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::Print(idDeclRenderProg *this)
{
  int v2; // r30
  __int16 *v3; // r28
  const idDeclRenderParm *RenderParmForIndex; // r3
  int v5; // r30
  __int16 *v6; // r28
  const idDeclRenderParm *v7; // r3
  int v8; // r30
  __int16 *v9; // r28
  const idDeclRenderParm *v10; // r3

  idLib::Printf(fmt: "--- vertex locals ---\n");
  v2 = 0;
  if ( this->numVertexParms > 0 )
  {
    v3 = (__int16 *)&this->fragmentProgramChecksum + 1;
    do
    {
      RenderParmForIndex = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: *++v3);
      RenderParmForIndex->List(this: RenderParmForIndex);
      ++v2;
    }
    while ( v2 < this->numVertexParms );
  }
  idLib::Printf(fmt: "--- fragment locals ---\n");
  v5 = 0;
  if ( this->numFragmentParms > 0 )
  {
    v6 = (__int16 *)&this->numVertexParms + 1;
    do
    {
      v7 = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: *++v6);
      v7->List(this: v7);
      ++v5;
    }
    while ( v5 < this->numFragmentParms );
  }
  idLib::Printf(fmt: "--- textures ---\n");
  v8 = 0;
  if ( this->numTextureParms > 0 )
  {
    v9 = (__int16 *)&this->numFragmentParms + 1;
    do
    {
      v10 = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: *++v9);
      v10->List(this: v10);
      ++v8;
    }
    while ( v8 < this->numTextureParms );
  }
}


// ========================================================================
// ??1idDeclRenderProg@@UAA@XZ
// EA  : 0x828AEC68
// RVA : 0x008AEC68
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::~idDeclRenderProg(idDeclRenderProg *this)
{
  this->__vftable = (idDeclRenderProg_vtbl *)&idDeclRenderProg::`vftable';
  idDeclRenderProg::FreeData(this);
  `eh vector destructor iterator'(
    ptr: this->fragmentCode,
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  `eh vector destructor iterator'(
    ptr: this->vertexCode,
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  idParmBlock::~idParmBlock(this: &this->parmBlock);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$231545
// EA  : 0x828AECF0
// RVA : 0x008AECF0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_231545()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231546
// EA  : 0x828AED18
// RVA : 0x008AED18
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_231546()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$231547
// EA  : 0x828AED44
// RVA : 0x008AED44
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_231547()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 372),
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$231548
// EA  : 0x828AED80
// RVA : 0x008AED80
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_231548()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 500),
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// ?Clear@idDeclRenderProg@@QAAXW4progTarget_t@@@Z
// EA  : 0x828AEDD0
// RVA : 0x008AEDD0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::Clear(idDeclRenderProg *this, progTarget_t target)
{
  unsigned __int64 v3; // r30
  _WORD *v4; // r10
  int i; // ctr
  _WORD *v6; // r11
  int j; // ctr
  _WORD *v8; // r11
  int k; // ctr
  char *v10; // r28
  _DWORD *v11; // r29
  _BYTE *v12; // r11
  _DWORD *v13; // r29
  _BYTE *v14; // r11
  int *p_allocedAndFlag; // r29
  int m; // r28
  _BYTE *v17; // r11
  _BYTE *v18; // r11
  const idDeclRenderProg **p_inheritedFragmentProgram; // r11
  int n; // ctr

  this->versions[0] = this;
  LODWORD(v3) = 0;
  this->versions[1] = this;
  this->versions[2] = this;
  this->versions[3] = this;
  HIDWORD(v3) = target;
  this->glState = v3;
  this->hasClip = false;
  this->hasAlphaToCoverage = false;
  this->hasHardwareSkinning = false;
  this->hasInteractions = false;
  this->has16BitScaleBias = false;
  this->hasVertexTexture = false;
  this->fragmentOutputs = 0;
  this->registerCountPS3 = 0;
  this->registerCount360 = 0;
  idParmBlock::Clear(this: &this->parmBlock);
  this->vertexMask = 0;
  this->vertexProgramChecksum = 0;
  this->fragmentProgramChecksum = 0;
  this->numVertexParms = 0;
  v4 = (_WORD *)&this->fragmentProgramChecksum + 1;
  this->numFragmentParms = 0;
  this->stageSort = 0.0;
  this->numTextureParms = 0;
  for ( i = 32; i != 0; --i )
    *++v4 = 2047;
  v6 = (_WORD *)&this->numVertexParms + 1;
  for ( j = 32; j != 0; --j )
    *++v6 = 2047;
  v8 = (_WORD *)&this->numFragmentParms + 1;
  for ( k = 16; k != 0; --k )
    *++v8 = 2047;
  if ( HIDWORD(v3) != 0 )
  {
    v10 = (char *)this + 32 * HIDWORD(v3);
    v11 = v10 + 372;
    if ( *((int *)v10 + 95) >= 0 )
    {
      idStr::FreeData(this: (idStr *)(v10 + 372));
      *((_DWORD *)v10 + 95) = 20;
      *((_DWORD *)v10 + 94) = v10 + 384;
      *v11 = 0;
      v10[384] = 0;
    }
    else
    {
      v12 = *((_BYTE **)v10 + 94);
      *v11 = 0;
      *v12 = 0;
    }
    v13 = v10 + 500;
    if ( *((int *)v10 + 127) >= 0 )
    {
      idStr::FreeData(this: (idStr *)(v10 + 500));
      *((_DWORD *)v10 + 127) = 20;
      *((_DWORD *)v10 + 126) = v10 + 512;
      *v13 = 0;
      v10[512] = 0;
    }
    else
    {
      v14 = *((_BYTE **)v10 + 126);
      *v13 = 0;
      *v14 = 0;
    }
  }
  else
  {
    p_allocedAndFlag = &this->vertexCode[0].allocedAndFlag;
    for ( m = 4; m != 0; --m )
    {
      if ( *p_allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: (idStr *)(p_allocedAndFlag - 2));
        *p_allocedAndFlag = 20;
        *(p_allocedAndFlag - 1) = (int)(p_allocedAndFlag + 1);
        *(p_allocedAndFlag - 2) = 0;
        *((_BYTE *)p_allocedAndFlag + 4) = 0;
      }
      else
      {
        v17 = (_BYTE *)*(p_allocedAndFlag - 1);
        *(p_allocedAndFlag - 2) = 0;
        *v17 = 0;
      }
      if ( p_allocedAndFlag[32] >= 0 )
      {
        idStr::FreeData(this: (idStr *)(p_allocedAndFlag + 30));
        p_allocedAndFlag[32] = 20;
        p_allocedAndFlag[31] = (int)(p_allocedAndFlag + 33);
        p_allocedAndFlag[30] = 0;
        *((_BYTE *)p_allocedAndFlag + 132) = 0;
      }
      else
      {
        v18 = (_BYTE *)p_allocedAndFlag[31];
        p_allocedAndFlag[30] = 0;
        *v18 = 0;
      }
      p_allocedAndFlag += 8;
    }
  }
  this->compiledVertexCode = nullptr;
  this->fragmentShaderD3D = nullptr;
  p_inheritedFragmentProgram = &this->inheritedFragmentProgram;
  this->numVertexDeclarations = 0;
  for ( n = 8; n != 0; --n )
    *++p_inheritedFragmentProgram = nullptr;
  this->renamed = this;
  this->isFastZ = false;
  this->inheritedVertexProgram = nullptr;
  this->inheritedFragmentProgram = nullptr;
}


// ========================================================================
// ?SamplerTypeForTextureParm@idDeclRenderProg@@ABAPBDW4progTarget_t@@H@Z
// EA  : 0x828AF000
// RVA : 0x008AF000
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

const char *__fastcall idDeclRenderProg::SamplerTypeForTextureParm(
        idDeclRenderProg *this,
        progTarget_t target,
        int parmIndex)
{
  const idDeclRenderParm *RenderParmForIndex; // r3
  unsigned int v6; // r11

  RenderParmForIndex = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex);
  if ( RenderParmForIndex == nullptr )
    return nullptr;
  if ( (unsigned int)(RenderParmForIndex->parmType - 2) > 6 )
  {
    v6 = *(_DWORD *)(RenderParmForIndex->declaredValue.swizzle[0] + 60);
    if ( v6 == 0 )
      return "sampler2D";
    if ( v6 != 1 )
    {
      if ( v6 >= 3 )
        return nullptr;
      return "samplerCUBE";
    }
    return "sampler3D";
  }
  switch ( RenderParmForIndex->parmType )
  {
    case PT_TEXTURE_2D:
      return "sampler2D";
    case PT_TEXTURE_3D:
      return "sampler3D";
    case PT_TEXTURE_CUBE:
      return "samplerCUBE";
    case PT_TEXTURE_SHADOW_2D:
      if ( target == PT_PC )
        return "sampler2DShadow";
      return "sampler2D";
    case PT_TEXTURE_SHADOW_3D:
      if ( target == PT_PC )
        return "sampler3DShadow";
      return "sampler3D";
    case PT_TEXTURE_SHADOW_CUBE:
      if ( target == PT_PC )
        return "samplerCubeShadow";
      return "samplerCUBE";
    default:
      break;
  }
  if ( target == PT_PC )
    return "sampler2DMS";
  return "sampler2D";
}


// ========================================================================
// ?List@idDeclRenderProg@@UBAXXZ
// EA  : 0x828AF180
// RVA : 0x008AF180
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::List(idDeclRenderProg *this)
{
  idLib::Printf(fmt: "%2i %2i %s\n", this->numVertexParms, this->numFragmentParms, this->name.str);
}


// ========================================================================
// ?ProgUsesParm@idDeclRenderProg@@QBA_NPBVidDeclRenderParm@@@Z
// EA  : 0x828AF1A0
// RVA : 0x008AF1A0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

int __fastcall idDeclRenderProg::ProgUsesParm(idDeclRenderProg *this, const idDeclRenderParm *parm)
{
  int numVertexParms; // r9
  int v3; // r10
  __int16 *vertexParms; // r11
  int numFragmentParms; // r9
  int v6; // r10
  __int16 *fragmentParms; // r11
  int numTextureParms; // r9
  int v9; // r10
  __int16 *i; // r11

  numVertexParms = this->numVertexParms;
  v3 = 0;
  if ( numVertexParms <= 0 )
  {
LABEL_5:
    numFragmentParms = this->numFragmentParms;
    v6 = 0;
    if ( numFragmentParms <= 0 )
    {
LABEL_9:
      numTextureParms = this->numTextureParms;
      v9 = 0;
      if ( numTextureParms <= 0 )
        return 0;
      for ( i = this->textureParms; *i != parm->parmIndex; ++i )
      {
        if ( ++v9 >= numTextureParms )
          return 0;
      }
    }
    else
    {
      fragmentParms = this->fragmentParms;
      while ( *fragmentParms != parm->parmIndex )
      {
        ++v6;
        ++fragmentParms;
        if ( v6 >= numFragmentParms )
          goto LABEL_9;
      }
    }
  }
  else
  {
    vertexParms = this->vertexParms;
    while ( *vertexParms != parm->parmIndex )
    {
      ++v3;
      ++vertexParms;
      if ( v3 >= numVertexParms )
        goto LABEL_5;
    }
  }
  return 1;
}


// ========================================================================
// ?SetTextureParm@idDeclRenderProg@@QBAXHPBVidImage@@@Z
// EA  : 0x828AF258
// RVA : 0x008AF258
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::SetTextureParm(idDeclRenderProg *this, int i, const idImage *image)
{
  int v4; // r4
  idDeclRenderParm *RenderParmForIndex; // r3

  v4 = this->textureParms[i];
  if ( v4 != 2047 )
  {
    RenderParmForIndex = idParmState::GetRenderParmForIndex(this: renderThreadParmState, parmIndex: v4);
    idDeclRenderParm::SetImage(this: RenderParmForIndex, image);
  }
}


// ========================================================================
// ?BindForImmediate@idDeclRenderProg@@QBAX_K@Z
// EA  : 0x828AF2B0
// RVA : 0x008AF2B0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::BindForImmediate(
        idDeclRenderProg *this,
        int a2,
        unsigned __int64 extraState,
        unsigned int a4)
{
  idODSObject<idDeclRenderProg> v4; // [sp+50h] [-10h] BYREF

  v4.objectPtr = this;
  HIDWORD(extraState) = 31;
  GL_BindProgram(prog: &v4, extraState, triVertexMask: a4);
}


// ========================================================================
// ?BindTexture@idDeclRenderProg@@SAXPBVidImage@@H@Z
// EA  : 0x828AF2E0
// RVA : 0x008AF2E0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::BindTexture(const idImage *image, int texUnit)
{
  idODSObject<idImage> v2; // [sp+50h] [-10h] BYREF

  v2.objectPtr = image;
  GL_BindTexture(image: &v2, texUnit);
  GL_ResetTextureState();
}


// ========================================================================
// ??0idDeclRenderProg@@QAA@XZ
// EA  : 0x828AF318
// RVA : 0x008AF318
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

idDeclRenderProg *__fastcall idDeclRenderProg::idDeclRenderProg(idDeclRenderProg *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclRenderProg_vtbl *)&idDeclRenderProg::`vftable';
  idParmBlock::idParmBlock(this: &this->parmBlock, threadId: THREAD_RENDERER);
  `eh vector constructor iterator'(
    ptr: this->vertexCode,
    size: 0x20u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  `eh vector constructor iterator'(
    ptr: this->fragmentCode,
    size: 0x20u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->hasDerived = false;
  idDeclRenderProg::Clear(this, target: PT_PC);
  return this;
}


// ========================================================================
// __unwind$232271
// EA  : 0x828AF3C4
// RVA : 0x008AF3C4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_232271()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$232272
// EA  : 0x828AF3EC
// RVA : 0x008AF3EC
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_232272()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$232273
// EA  : 0x828AF418
// RVA : 0x008AF418
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_232273()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 372),
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$232274
// EA  : 0x828AF454
// RVA : 0x008AF454
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_232274()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 500),
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// ?ParseInheritance@idDeclRenderProg@@AAA_NW4progTarget_t@@AAVidParser@@@Z
// EA  : 0x828AF4F8
// RVA : 0x008AF4F8
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

int __fastcall idDeclRenderProg::ParseInheritance(idDeclRenderProg *this, progTarget_t target, idParser *src)
{
  char *data; // r4
  const idDecl *v8; // r3
  const idDeclRenderProg *v9; // r29
  unsigned __int64 glState; // r5
  __int16 *vertexParms; // r11
  int v12; // r9
  int i; // ctr
  __int16 *fragmentParms; // r11
  int j; // ctr
  __int16 *textureParms; // r11
  int k; // ctr
  const idDeclRenderProg *inheritedVertexProgram; // r11
  const idDeclRenderProg **p_inheritedFragmentProgram; // r10
  const idDeclRenderProg **v20; // r9
  int v21; // ctr
  const idDeclRenderProg *inheritedFragmentProgram; // r11
  idToken v23; // [sp+50h] [-80h] BYREF

  v23.len = 0;
  v23.allocedAndFlag = 20;
  v23.floatvalue = -3.4028235e38;
  v23.data = v23.baseBuffer;
  v23.baseBuffer[0] = 0;
  v23.intvalue = 0;
  memset(&v23.whiteSpaceStart_p, 0, 12);
  if ( !idParser::ReadToken(this: src, token: &v23) )
  {
    idParser::Warning(this: src, str: "Unexpected EOF after 'inherit'");
    idStr::FreeData(this: &v23);
    return 0;
  }
  data = v23.data;
  if ( v23.data == nullptr )
    goto LABEL_6;
  v8 = idDeclInfo::FindWithInheritance(this: &idDeclRenderProg::resourceList, name: v23.data, makeDefault: false);
  v9 = (const idDeclRenderProg *)v8;
  if ( v8 == nullptr )
  {
    data = v23.data;
LABEL_6:
    idParser::Warning(this: src, str: "Unknown RenderProg %s", data);
    idStr::FreeData(this: &v23);
    return 0;
  }
  declManager->AddDependency_2(this: declManager, a2: (idDecl *)this, a3: v8);
  v9->hasDerived = true;
  idDeclRenderProg::Clear(this, target);
  this->inheritedVertexProgram = v9;
  this->inheritedFragmentProgram = v9;
  this->hasClip = v9->hasClip;
  this->hasAlphaToCoverage = v9->hasAlphaToCoverage;
  this->hasHardwareSkinning = v9->hasHardwareSkinning;
  this->hasInteractions = v9->hasInteractions;
  this->has16BitScaleBias = v9->has16BitScaleBias;
  this->hasVertexTexture = v9->hasVertexTexture;
  this->fragmentOutputs = v9->fragmentOutputs;
  this->registerCountPS3 = v9->registerCountPS3;
  this->registerCount360 = v9->registerCount360;
  glState = v9->glState;
  this->glState = glState;
  this->stageSort = v9->stageSort;
  idParmBlock::CopyFrom(this: &this->parmBlock, other: (const idParmBlock *)HIDWORD(glState));
  vertexParms = this->vertexParms;
  v12 = (char *)v9 - (char *)this;
  this->numVertexParms = v9->numVertexParms;
  for ( i = 32; i != 0; --i )
  {
    *vertexParms = *(__int16 *)((char *)vertexParms + v12);
    ++vertexParms;
  }
  fragmentParms = this->fragmentParms;
  this->numFragmentParms = v9->numFragmentParms;
  for ( j = 32; j != 0; --j )
  {
    *fragmentParms = *(__int16 *)((char *)fragmentParms + v12);
    ++fragmentParms;
  }
  textureParms = this->textureParms;
  this->numTextureParms = v9->numTextureParms;
  for ( k = 16; k != 0; --k )
  {
    *textureParms = *(__int16 *)((char *)textureParms + v12);
    ++textureParms;
  }
  this->versions[0] = v9->versions[0];
  this->versions[1] = v9->versions[1];
  this->versions[2] = v9->versions[2];
  this->versions[3] = v9->versions[3];
  inheritedVertexProgram = this->inheritedVertexProgram;
  this->vertexMask = v9->vertexMask;
  if ( inheritedVertexProgram != nullptr )
  {
    p_inheritedFragmentProgram = &inheritedVertexProgram->inheritedFragmentProgram;
    v20 = &this->inheritedFragmentProgram;
    this->vertexProgramChecksum = inheritedVertexProgram->vertexProgramChecksum;
    v21 = 8;
    this->compiledVertexCode = inheritedVertexProgram->compiledVertexCode;
    do
    {
      *++v20 = *++p_inheritedFragmentProgram;
      --v21;
    }
    while ( v21 != 0 );
    this->numVertexDeclarations = this->inheritedVertexProgram->numVertexDeclarations;
  }
  inheritedFragmentProgram = this->inheritedFragmentProgram;
  if ( inheritedFragmentProgram != nullptr )
  {
    this->fragmentProgramChecksum = inheritedFragmentProgram->fragmentProgramChecksum;
    this->fragmentShaderD3D = inheritedFragmentProgram->fragmentShaderD3D;
  }
  idStr::FreeData(this: &v23);
  return 1;
}


// ========================================================================
// __unwind$232318
// EA  : 0x828AF780
// RVA : 0x008AF780
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_232318()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ParseState@idDeclRenderProg@@AAA_NAAVidParser@@@Z
// EA  : 0x828AF7B0
// RVA : 0x008AF7B0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idDeclRenderProg::ParseState(idDeclRenderProg *this, idParser *src)
{
  idParser *v2; // r30
  __int64 v3; // r24
  __int64 v4; // r27
  __int64 v5; // r4
  idParser *v6; // r29
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r10
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // r10
  unsigned __int64 v12; // r10
  unsigned __int64 v13; // r10
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // r10
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // r10
  unsigned __int64 v19; // r10
  unsigned __int64 v20; // r10
  unsigned __int64 v21; // r10
  unsigned __int64 v22; // r9
  unsigned __int64 v23; // r10
  unsigned __int64 v24; // r10
  unsigned __int64 v25; // r10
  unsigned __int64 v26; // r10
  unsigned __int64 v27; // r10
  unsigned __int64 v28; // r10
  int v29; // r29
  __int64 v30; // r9 OVERLAPPED
  unsigned __int64 v31; // r7
  int v32; // r10
  __int64 v33; // r8
  unsigned __int64 v34; // r6
  __int64 v35; // r11
  __int64 v36; // r11
  unsigned __int64 v37; // r10
  int v38; // r12
  unsigned __int64 v39; // r9
  unsigned __int64 v40; // r9
  idToken v42; // [sp+60h] [-170h] BYREF
  const char *v43; // [sp+A8h] [-128h]
  const char *v44; // [sp+ACh] [-124h]
  const char *v45; // [sp+B0h] [-120h]
  const char *v46; // [sp+B4h] [-11Ch]
  const char *v47; // [sp+B8h] [-118h]
  const char *v48; // [sp+BCh] [-114h]
  const char *v49; // [sp+C0h] [-110h]
  const char *v50; // [sp+C4h] [-10Ch]
  const char *v51; // [sp+C8h] [-108h]
  const char *v52; // [sp+CCh] [-104h]
  const char *v53; // [sp+D0h] [-100h]
  const char *v54; // [sp+D4h] [-FCh]
  const char *v55; // [sp+D8h] [-F8h]
  const char *v56; // [sp+DCh] [-F4h]
  const char *v57; // [sp+E0h] [-F0h]
  const char *v58; // [sp+E4h] [-ECh]
  const char *v59; // [sp+E8h] [-E8h]
  const char *v60; // [sp+ECh] [-E4h]
  const char *v61; // [sp+F0h] [-E0h]
  const char *v62; // [sp+F4h] [-DCh]
  const char *v63; // [sp+F8h] [-D8h]
  const char *v64; // [sp+FCh] [-D4h]
  const char *v65; // [sp+100h] [-D0h]
  const char *v66; // [sp+104h] [-CCh]
  const char *v67; // [sp+108h] [-C8h]
  const char *v68; // [sp+10Ch] [-C4h]
  const char *v69; // [sp+110h] [-C0h]
  const char *v70; // [sp+114h] [-BCh]
  const char *v71; // [sp+118h] [-B8h]
  __int64 v72; // [sp+120h] [-B0h]
  __int64 v73; // [sp+128h] [-A8h]
  __int64 v74; // [sp+130h] [-A0h]

  v42.len = 0;
  v2 = src;
  v42.allocedAndFlag = 20;
  v42.data = v42.baseBuffer;
  v42.floatvalue = -3.4028235e38;
  v42.baseBuffer[0] = 0;
  v42.intvalue = 0;
  memset(&v42.whiteSpaceStart_p, 0, 12);
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    if ( !idParser::ReadToken(this: v2, token: &v42) )
    {
LABEL_124:
      idParser::Warning(this: v2, str: "Unexpected EOF in state block");
      goto LABEL_125;
    }
    v60 = (const char *)-2112262432;
    v58 = (const char *)-2111649980;
    v66 = "Unknown drawing state option '%s'\n";
    v56 = (const char *)-2111649936;
    v54 = (const char *)-2111649956;
    v52 = (const char *)-2111649948;
    v64 = (const char *)-2113270080;
    v62 = (const char *)-2113270008;
    v50 = (const char *)-2111649968;
    HIDWORD(v3) = &off_82230000;
    LODWORD(v3) = -2111635456;
    HIDWORD(v4) = &off_82230000;
    LODWORD(v4) = -2111635456;
    HIDWORD(v5) = &off_82230000;
    LODWORD(v5) = -2111635456;
    v73 = v5;
    v74 = v4;
    v46 = "backSided";
    v72 = v3;
    v55 = "alphaMask";
    v43 = "SRC_COLOR";
    v53 = "depthMask";
    v51 = "wireframe";
    v69 = "depthFunc";
    v70 = "MIN";
    v47 = (const char *)-2111650008;
    v67 = (const char *)-2111649988;
    v61 = "MAX";
    v49 = "SUB";
    v65 = "twoSided";
    v6 = src;
    v44 = "ONE_MINUS_DST_COLOR";
    v57 = "blendOp";
    v45 = "ONE_MINUS_SRC_COLOR";
    v71 = "colorMask";
    v63 = "alphaCoverage";
    v48 = (const char *)-2111650000;
    v68 = (const char *)-2111650060;
    v59 = (const char *)-2111650052;
    while ( idStr::Cmp(s1: v42.data, s2: "}") != 0 )
    {
      if ( idStr::Icmp(s1: v42.data, s2: "blend") == 0 )
      {
        if ( !idParser::ReadToken(this: v6, token: &v42) )
          goto _M232903_0;
        idStr::ToUpper(this: &v42);
        idStr::StripLeading(this: &v42, string: "GL_");
        if ( idStr::Icmp(s1: v42.data, s2: "ONE") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: "ZERO") != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: "DST_COLOR") != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: v44) != 0 )
              {
                if ( idStr::Icmp(s1: v42.data, s2: "SRC_ALPHA") != 0 )
                {
                  if ( idStr::Icmp(s1: v42.data, s2: "ONE_MINUS_SRC_ALPHA") != 0 )
                  {
                    if ( idStr::Icmp(s1: v42.data, s2: "DST_ALPHA") != 0 )
                    {
                      if ( idStr::Icmp(s1: v42.data, s2: "ONE_MINUS_DST_ALPHA") != 0 )
                        goto _M232889_0;
                      LODWORD(v7) = LODWORD(this->glState) | 7;
                    }
                    else
                    {
                      LODWORD(v7) = LODWORD(this->glState) | 6;
                    }
                  }
                  else
                  {
                    LODWORD(v7) = LODWORD(this->glState) | 5;
                  }
                }
                else
                {
                  LODWORD(v7) = LODWORD(this->glState) | 4;
                }
              }
              else
              {
                LODWORD(v7) = LODWORD(this->glState) | 3;
              }
            }
            else
            {
              LODWORD(v7) = LODWORD(this->glState) | 2;
            }
          }
          else
          {
            LODWORD(v7) = LODWORD(this->glState) | 1;
          }
          this->glState = v7;
        }
        if ( !idParser::ReadToken(this: v6, token: &v42) )
        {
_M232903_0:
          idParser::Warning(this: v6, str: "EOF in program.");
          goto LABEL_125;
        }
        idStr::ToUpper(this: &v42);
        idStr::StripLeading(this: &v42, string: "GL_");
        if ( idStr::Icmp(s1: v42.data, s2: "ONE") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: "ZERO") != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: "SRC_ALPHA") != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: "ONE_MINUS_SRC_ALPHA") != 0 )
              {
                if ( idStr::Icmp(s1: v42.data, s2: "DST_ALPHA") != 0 )
                {
                  if ( idStr::Icmp(s1: v42.data, s2: "ONE_MINUS_DST_ALPHA") != 0 )
                  {
                    if ( idStr::Icmp(s1: v42.data, s2: v43) != 0 )
                    {
                      if ( idStr::Icmp(s1: v42.data, s2: v45) != 0 )
                      {
_M232889_0:
                        idParser::Warning(this: v6, str: "bad blend mode %s", v42.data);
                        goto LABEL_125;
                      }
                      LODWORD(v14) = LODWORD(this->glState) | 0x18;
                      this->glState = v14;
                    }
                    else
                    {
                      LODWORD(v13) = LODWORD(this->glState) | 0x10;
                      this->glState = v13;
                    }
                  }
                  else
                  {
                    LODWORD(v12) = LODWORD(this->glState) | 0x38;
                    this->glState = v12;
                  }
                }
                else
                {
                  LODWORD(v11) = LODWORD(this->glState) | 0x30;
                  this->glState = v11;
                }
              }
              else
              {
                LODWORD(v10) = LODWORD(this->glState) | 0x28;
                this->glState = v10;
              }
            }
            else
            {
              LODWORD(v9) = LODWORD(this->glState) | 0x20;
              this->glState = v9;
            }
          }
        }
        else
        {
          LODWORD(v8) = LODWORD(this->glState) | 8;
          this->glState = v8;
        }
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v57) == 0 )
      {
        if ( !idParser::ReadToken(this: v6, token: &v42) )
          goto _M232903_0;
        idStr::ToUpper(this: &v42);
        idStr::StripLeading(this: &v42, string: "GL_");
        if ( idStr::Icmp(s1: v42.data, s2: "ADD") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: v70) != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: v61) != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: v49) != 0 )
              {
                idParser::Warning(this: v6, str: "bad blend op %s", v42.data);
                goto LABEL_125;
              }
              LODWORD(v17) = LODWORD(this->glState) | 0x40000;
              this->glState = v17;
            }
            else
            {
              LODWORD(v16) = LODWORD(this->glState) | 0xC0000;
              this->glState = v16;
            }
          }
          else
          {
            LODWORD(v15) = LODWORD(this->glState) | 0x80000;
            this->glState = v15;
          }
        }
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v69) == 0 )
      {
        if ( !idParser::ReadToken(this: v6, token: &v42) )
          goto _M232903_0;
        idStr::ToUpper(this: &v42);
        idStr::StripLeading(this: &v42, string: "GL_");
        if ( idStr::Icmp(s1: v42.data, s2: "ALWAYS") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: "EQUAL") != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: (const char *)&off_82230000) != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: "LEQUAL") != 0 )
              {
                idParser::Warning(this: v6, str: "bad depthFunc %s", v42.data);
                goto LABEL_125;
              }
            }
            else
            {
              LODWORD(v20) = LODWORD(this->glState) | 0x2000;
              this->glState = v20;
            }
          }
          else
          {
            LODWORD(v19) = LODWORD(this->glState) | 0x6000;
            this->glState = v19;
          }
        }
        else
        {
          LODWORD(v18) = LODWORD(this->glState) | 0x4000;
          this->glState = v18;
        }
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v51) == 0 )
      {
        LODWORD(v21) = LODWORD(this->glState) | 0x800;
        this->glState = v21;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v63) == 0 )
      {
        LODWORD(v22) = LODWORD(this->glState) | 0x20000;
        this->hasAlphaToCoverage = true;
        this->glState = v22;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v53) == 0 )
      {
        LODWORD(v23) = LODWORD(this->glState) | 0x40;
        this->glState = v23;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v71) == 0 )
      {
        LODWORD(v24) = LODWORD(this->glState) | 0x380;
        this->glState = v24;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v55) == 0 )
      {
        LODWORD(v25) = LODWORD(this->glState) | 0x400;
        this->glState = v25;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v65) == 0 )
      {
        LODWORD(v26) = LODWORD(this->glState) | 0x8000;
        this->glState = v26;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v46) == 0 )
      {
        LODWORD(v27) = LODWORD(this->glState) | 0x10000;
        this->glState = v27;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: "polygonOffset") == 0 )
      {
        LODWORD(v28) = LODWORD(this->glState) | 0x1000;
        this->glState = v28;
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: "stencilOp") == 0 )
      {
        v29 = 0;
        while ( 1 )
        {
          if ( !idParser::ReadToken(this: src, token: &v42) )
          {
            idParser::Warning(this: src, str: "EOF in program.");
            goto LABEL_125;
          }
          idStr::ToUpper(this: &v42);
          idStr::StripLeading(this: &v42, string: "GL_");
          if ( idStr::Icmp(s1: v42.data, s2: "KEEP") != 0 )
            break;
          *(__int64 *)((char *)&v30 - 4) = this->glState;
          LODWORD(v30) = 0;
          LODWORD(v31) = (v30 << v29) | v32;
          this->glState = v31;
LABEL_95:
          v29 += 3;
          if ( v29 >= 9 )
          {
            v6 = src;
            goto LABEL_122;
          }
        }
        if ( idStr::Icmp(s1: v42.data, s2: "ZERO") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: v68) != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: v59) != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: v67) == 0 )
              {
                LODWORD(v33) = 512;
                goto LABEL_94;
              }
              if ( idStr::Icmp(s1: v42.data, s2: v47) != 0 )
              {
                if ( idStr::Icmp(s1: v42.data, s2: v48) == 0 )
                {
                  LODWORD(v36) = 3;
                  v33 = v36 << 40;
                  goto LABEL_94;
                }
                if ( idStr::Icmp(s1: v42.data, s2: v50) != 0 )
                {
                  idParser::Warning(this: src, str: "bad stencilOp %s", v42.data);
                  goto LABEL_125;
                }
                LODWORD(v35) = 7;
              }
              else
              {
                LODWORD(v35) = 5;
              }
            }
            else
            {
              LODWORD(v35) = 3;
            }
            v33 = v35 << 39;
            goto LABEL_94;
          }
          LODWORD(v33) = 256;
        }
        else
        {
          LODWORD(v33) = 128;
        }
LABEL_94:
        LODWORD(v34) = (v33 << HIDWORD(this->glState)) | LODWORD(this->glState);
        this->glState = v34;
        goto LABEL_95;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v52) == 0 )
      {
        if ( !idParser::ReadToken(this: v6, token: &v42) )
          goto _M232903_0;
        idStr::ToUpper(this: &v42);
        idStr::StripLeading(this: &v42, string: "GL_");
        if ( idStr::Icmp(s1: v42.data, s2: "ALWAYS") != 0 )
        {
          if ( idStr::Icmp(s1: v42.data, s2: v54) == 0 )
          {
            v38 = 16;
            goto LABEL_112;
          }
          if ( idStr::Icmp(s1: v42.data, s2: "LEQUAL") == 0 )
          {
            v38 = 32;
            goto LABEL_112;
          }
          if ( idStr::Icmp(s1: v42.data, s2: (const char *)&off_82230000) != 0 )
          {
            if ( idStr::Icmp(s1: v42.data, s2: v56) == 0 )
            {
              v38 = 64;
              goto LABEL_112;
            }
            if ( idStr::Icmp(s1: v42.data, s2: "EQUAL") != 0 )
            {
              if ( idStr::Icmp(s1: v42.data, s2: v58) == 0 )
              {
                v38 = 0;
                goto LABEL_112;
              }
              if ( idStr::Icmp(s1: v42.data, s2: v60) != 0 )
              {
                idParser::Warning(this: v6, str: "bad stencilFunc %s", v42.data);
                goto LABEL_125;
              }
            }
          }
          v38 = 0;
LABEL_112:
          LODWORD(v37) = LODWORD(this->glState) | v38;
          this->glState = v37;
        }
        if ( idParser::ReadTokenOnLine(this: v6, token: &v42) != 0 )
        {
          LODWORD(v39) = (idToken::GetUnsignedIntValue(this: &v42) << 20) & 0xFF00000 | LODWORD(this->glState);
          this->glState = v39;
        }
        if ( idParser::ReadTokenOnLine(this: v6, token: &v42) != 0 )
        {
          LODWORD(v40) = (idToken::GetUnsignedIntValue(this: &v42) << 28)
                       | HIDWORD(this->glState) & 0xFFFFFFF
                       | LODWORD(this->glState);
          this->glState = v40;
        }
        goto LABEL_122;
      }
      if ( idStr::Icmp(s1: v42.data, s2: v62) != 0 )
      {
        if ( idStr::Icmp(s1: v42.data, s2: v64) != 0 )
          idParser::Warning(this: v6, str: v66, v42.data);
        else
          this->registerCount360 = idParser::ParseInt(this: v6);
      }
      else
      {
        this->registerCountPS3 = idParser::ParseInt(this: v6);
      }
LABEL_122:
      if ( !idParser::ReadToken(this: v6, token: &v42) )
      {
        v2 = src;
        goto LABEL_124;
      }
    }
    idStr::FreeData(this: &v42);
    return 1;
  }
  else
  {
LABEL_125:
    idStr::FreeData(this: &v42);
    return 0;
  }
}


// ========================================================================
// $M232907
// EA  : 0x828B04D0
// RVA : 0x008B04D0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _M232907()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 96));
}


// ========================================================================
// ?testRenderProgs_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828B0500
// RVA : 0x008B0500
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall testRenderProgs_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r24
  int v4; // r29
  const char *v5; // r3
  const char *v6; // r3
  const char *v7; // r3
  const char *v8; // r3
  const char *v9; // r3
  idDeclSource *DeclSource; // r11
  char v11; // [sp+50h] [-70h]
  idDeclSource *v12; // [sp+58h] [-68h]
  int valueInteger; // [sp+5Ch] [-64h]
  int v14; // [sp+64h] [-5Ch]

  argc = args->argc;
  if ( args->argc == 2 || argc == 3 )
  {
    v3 = 0;
    v4 = 1;
    v11 = 0;
    if ( argc <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[1];
    if ( idStr::Icmp(s1: v5, s2: "pc") != 0 )
    {
      if ( args->argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      if ( idStr::Icmp(s1: v6, s2: "360") != 0 )
      {
        if ( args->argc <= 1 )
          v7 = &byte_8200D768;
        else
          v7 = args->argv[1];
        if ( idStr::Icmp(s1: v7, s2: "ps3") != 0 )
        {
          if ( args->argc <= 1 )
            v8 = &byte_8200D768;
          else
            v8 = args->argv[1];
          if ( idStr::Icmp(s1: v8, s2: "all") != 0 )
          {
            v9 = args->argc <= 1 ? &byte_8200D768 : args->argv[1];
            if ( idStr::Icmp(s1: v9, s2: "auto") == 0 )
              v11 = 1;
          }
        }
        else
        {
          v4 = 3;
        }
      }
      else
      {
        v4 = 2;
      }
    }
    else
    {
      v4 = 0;
    }
    valueInteger = r_genAllRenderProgs.valueInteger;
    idCVar::SetInteger(this: &r_genAllRenderProgs, newValue: v4, force: true);
    v14 = r_validateRenderProgs.valueInteger;
    idCVar::SetInteger(this: &r_validateRenderProgs, newValue: 1, force: true);
    idResourceList::ForceAllResourcesToReload();
    if ( args->argc == 3 )
    {
      DeclSource = idDeclInfo::FindDeclSource(this: &idDeclRenderProg::resourceList, name: args->argv[2]);
      if ( DeclSource != nullptr )
        idResourceList::Load(
          this: &idDeclRenderProg::resourceList,
          name: (char *)DeclSource->name.str,
          makeDefault: false,
          skipStaleCheck: false);
    }
    else
    {
      while ( v3 < idDeclRenderProg::resourceList.declSources.num )
      {
        v12 = idDeclRenderProg::resourceList.declSources.list[v3];
        idResourceList::Load(
          this: &idDeclRenderProg::resourceList,
          name: (char *)v12->name.str,
          makeDefault: false,
          skipStaleCheck: false);
        idLib::Printf(fmt: "testRenderProgs loaded: %s\n", v12->name.str);
        ++v3;
      }
    }
    idCVar::SetInteger(this: &r_genAllRenderProgs, newValue: valueInteger, force: true);
    idCVar::SetInteger(this: &r_validateRenderProgs, newValue: v14, force: true);
    if ( v11 != 0 )
      Sys_Quit(exitCode: 0);
  }
  else
  {
    idLib::Printf(
      fmt: "Recompiles all render progs (or a specific renderprog) for the selected platforms and reports any errors\n"
      "USAGE: testRenderProgs <platform> [name]\n"
      "platform:\n"
      "   pc   = generate for the PC\n"
      "   360  = generate for the Xbox 360\n"
      "   ps3  = generate for the PlayStation 3\n"
      "   all  = generate for all platforms\n"
      "   auto = generate for all platforms for automation\n"
      "name:\n"
      "\toptional\n");
  }
}


// ========================================================================
// $M233124_0
// EA  : 0x828B0800
// RVA : 0x008B0800
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void *_M233124_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( *(_BYTE *)(v0 - 192 + 80) == 0 )
  {
    idLib::Printf(fmt: "testRenderProgs failed to load: %s\n", **(const char ***)(v1 + 88));
    idCVar::SetInteger(this: &r_genAllRenderProgs, newValue: *(_DWORD *)(v1 + 92), force: true);
    CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
  }
  *(_BYTE *)(v1 + 81) = 0;
  *(_DWORD *)(v1 + 96) = 1;
  return &_LN29;
}


// ========================================================================
// ?ParseProgram@idDeclRenderProg@@AAA_NW4progTarget_t@@W4programType_t@1@AAVidParser@@ABVidStr@@@Z
// EA  : 0x828B0880
// RVA : 0x008B0880
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

BOOL __fastcall idDeclRenderProg::ParseProgram(
        idDeclRenderProg *this,
        progTarget_t target,
        idDeclRenderProg::programType_t pt,
        idParser *src,
        const idStr *globalInclude,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  attribInfo_t *v15; // r11
  unsigned int v16; // r30
  int *p_numFragmentParms; // r11
  bool v18; // r3
  signed int v19; // r26
  const char *v20; // r30
  __int16 *v21; // r16
  char *data; // r11
  __int64 v23; // r10
  __int64 numTextureParms; // r8
  __int64 v25; // r6
  const idDecl *v26; // r3
  const idDecl *v27; // r29
  char v28; // r11
  __int16 *textureParms; // r11
  const char *v30; // r4
  int v31; // r30
  __int16 *v32; // r11
  __int64 v33; // r6
  va *v34; // r3
  const idStr *v35; // r3
  signed int v36; // r30
  const char **v37; // r29
  __int64 v38; // r10
  const attribInfo_t *v39; // r11
  __int64 v40; // r8
  va *v41; // r3
  const idStr *v42; // r3
  signed int v43; // r29
  const char **v44; // r30
  __int64 v45; // r10
  __int64 v46; // r8
  const attribInfo_t *v47; // r30
  va *v48; // r3
  __int64 v49; // r6
  __int64 v50; // r10
  __int64 v51; // r8
  va *v52; // r3
  const idStr *v53; // r3
  signed int v54; // r30
  const char **v55; // r29
  __int64 v56; // r10
  void *v57; // r29
  const attribInfo_t *v58; // r11
  __int64 v59; // r8
  va *v60; // r3
  const idStr *v61; // r3
  signed int v62; // r30
  const char **p_name; // r29
  __int64 v64; // r10
  __int64 v65; // r8
  const attribInfo_t *v66; // r11
  va *v67; // r3
  const char *v68; // r6
  const char *v70; // r6
  const char *v71; // r6
  const char *v72; // r6
  char *v73; // r30
  size_t v74; // r29
  idStr *v75; // r30
  __int64 v76; // r10
  __int64 v77; // r8
  __int64 v78; // r6
  va *v79; // r3
  const char *v80; // r4
  int v81; // r29
  __int16 *v82; // r28
  const char *v83; // r3
  __int64 v84; // r10
  __int64 v85; // r8
  va *v86; // r3
  va *v87; // r3
  __int64 v88; // r10
  __int64 v89; // r8
  __int64 v90; // r6
  va *v91; // r3
  __int64 v92; // r10
  __int64 v93; // r6
  __int64 v94; // r8
  va *v95; // r3
  va *v96; // r3
  __int64 v97; // r8
  __int64 v98; // r6
  __int64 v99; // r10
  int v100; // r29
  __int16 *v101; // r28
  __int64 v102; // r6
  __int64 v103; // r10
  __int64 v104; // r8
  va *v105; // r3
  va *v106; // r3
  __int64 v107; // r10
  __int64 v108; // r6
  __int64 v109; // r8
  va *v110; // r3
  int v111; // r29
  __int16 *v112; // r28
  const char *v113; // r3
  __int64 v114; // r10
  __int64 v115; // r8
  va *v116; // r3
  va *v117; // r3
  int v118; // r29
  __int16 *v119; // r28
  const char *v120; // r3
  __int64 v121; // r10
  __int64 v122; // r8
  va *v123; // r3
  int v124; // r29
  __int16 *v125; // r28
  __int16 v126; // r23
  const char *v127; // r22
  const char *v128; // r3
  __int64 v129; // r8
  __int64 v130; // r10
  va *v131; // r3
  size_t len; // r29
  __int64 v133; // r10
  __int64 v134; // r8
  __int64 v135; // r6
  va *v136; // r3
  int v137; // r29
  __int16 *v138; // r28
  const char *v139; // r3
  __int64 v140; // r10
  __int64 v141; // r8
  va *v142; // r3
  va *v143; // r3
  int v144; // r29
  __int16 *v145; // r28
  __int64 v146; // r6
  __int64 v147; // r10
  __int64 v148; // r8
  va *v149; // r3
  int v150; // r29
  __int16 *v151; // r28
  const char *ParmNameForIndex; // r3
  __int64 v153; // r10
  __int64 v154; // r8
  va *v155; // r3
  int v156; // r29
  __int16 *v157; // r28
  __int16 v158; // r23
  const char *v159; // r22
  const char *v160; // r3
  __int64 v161; // r8
  __int64 v162; // r10
  va *v163; // r3
  __int64 v164; // r10
  __int64 v165; // r8
  __int64 v166; // r6
  va *v167; // r3
  int v168; // r10
  int v169; // r9
  int v170; // r8
  int v171; // r7
  int v172; // r6
  int v173; // r5
  int v174; // r4
  int v175; // r3
  int v176; // [sp+8h] [-1408h]
  int v177; // [sp+8h] [-1408h]
  int v178; // [sp+8h] [-1408h]
  int v179; // [sp+8h] [-1408h]
  int v180; // [sp+Ch] [-1404h]
  int v181; // [sp+Ch] [-1404h]
  int v182; // [sp+Ch] [-1404h]
  int v183; // [sp+Ch] [-1404h]
  int v184; // [sp+10h] [-1400h]
  int v185; // [sp+10h] [-1400h]
  int v186; // [sp+10h] [-1400h]
  int v187; // [sp+10h] [-1400h]
  int v188; // [sp+14h] [-13FCh]
  int v189; // [sp+14h] [-13FCh]
  int v190; // [sp+14h] [-13FCh]
  int v191; // [sp+14h] [-13FCh]
  int v192; // [sp+18h] [-13F8h]
  int v193; // [sp+18h] [-13F8h]
  int v194; // [sp+18h] [-13F8h]
  int v195; // [sp+18h] [-13F8h]
  int v196; // [sp+1Ch] [-13F4h]
  int v197; // [sp+1Ch] [-13F4h]
  int v198; // [sp+1Ch] [-13F4h]
  int v199; // [sp+1Ch] [-13F4h]
  char v200; // [sp+50h] [-13C0h]
  char v201; // [sp+51h] [-13BFh]
  char v202; // [sp+52h] [-13BEh]
  char v203; // [sp+53h] [-13BDh]
  char v204; // [sp+54h] [-13BCh]
  int *v205; // [sp+5Ch] [-13B4h]
  const attribInfo_t *v206; // [sp+60h] [-13B0h]
  idTempArray<char> v207; // [sp+68h] [-13A8h] BYREF
  idTempArray<char> v208; // [sp+70h] [-13A0h] BYREF
  __int16 *fragmentParms; // [sp+78h] [-1398h]
  int v210; // [sp+7Ch] [-1394h]
  idStr v211; // [sp+80h] [-1390h] BYREF
  idCVar *v212; // [sp+A0h] [-1370h]
  const char *v213; // [sp+A4h] [-136Ch]
  idStr v214; // [sp+B0h] [-1360h] BYREF
  idStr v215; // [sp+D0h] [-1340h] BYREF
  idToken v216; // [sp+F0h] [-1320h] BYREF
  const char *v217; // [sp+138h] [-12D8h]
  const char *v218; // [sp+13Ch] [-12D4h]
  const char *v219; // [sp+140h] [-12D0h]
  idCodeResource<idDeclRenderParm> *v220; // [sp+144h] [-12CCh]
  idCodeResource<idDeclRenderParm> *v221; // [sp+148h] [-12C8h]
  const char *v222; // [sp+14Ch] [-12C4h]
  const char *v223; // [sp+150h] [-12C0h]
  const char *v224; // [sp+154h] [-12BCh]
  const char *v225; // [sp+158h] [-12B8h]
  const char *v226; // [sp+15Ch] [-12B4h]
  const char *v227; // [sp+160h] [-12B0h]
  const char *v228; // [sp+164h] [-12ACh]
  const char *v229; // [sp+168h] [-12A8h]
  char *v230; // [sp+16Ch] [-12A4h]
  idStr v231; // [sp+170h] [-12A0h] BYREF
  idStr v232; // [sp+190h] [-1280h] BYREF
  idToken v233; // [sp+1B0h] [-1260h] BYREF
  idToken v234; // [sp+200h] [-1210h] BYREF
  idToken v235; // [sp+250h] [-11C0h] BYREF
  idToken v236; // [sp+2A0h] [-1170h] BYREF
  idStr v237; // [sp+2F0h] [-1120h] BYREF
  idStr v238; // [sp+310h] [-1100h] BYREF
  idStr v239; // [sp+330h] [-10E0h] BYREF
  idStr v240; // [sp+350h] [-10C0h] BYREF
  va v241; // [sp+370h] [-10A0h] BYREF

  if ( pt != PROGRAM_TYPE_VERTEX )
  {
    if ( pt == PROGRAM_TYPE_FRAGMENT )
    {
      this->hasClip = false;
      this->fragmentOutputs = 0;
    }
  }
  else
  {
    this->hasHardwareSkinning = false;
    this->vertexMask = 0;
  }
  if ( (unsigned int)target > PT_PS3 )
  {
    idLib::FatalError(fmt: "idDeclRenderProg::ParseProgram: bad target");
    return _LN766_0(a1: v175, a2: v174, a3: v173, a4: v172, a5: v171, a6: v170, a7: v169, a8: v168, a9, a10, a11, a12);
  }
  if ( target == PT_PC_D3D )
  {
    v16 = 48;
    v206 = attribsPCD3D;
  }
  else if ( target == PT_360 )
  {
    v16 = 49;
    v206 = attribs360;
  }
  else
  {
    if ( target != PT_PC )
    {
      v16 = 48;
      v15 = (attribInfo_t *)attribsPS3;
    }
    else
    {
      v16 = 55;
      v15 = attribsPC;
    }
    v206 = v15;
  }
  idTempArray<char>::idTempArray<char>(this: &v208, num: v16);
  idTempArray<char>::idTempArray<char>(this: &v207, num: v16);
  memset(Dst: v208.buffer, Val: 0, Size: v208.num);
  memset(Dst: v207.buffer, Val: 0, Size: v207.num);
  v201 = 0;
  v204 = 0;
  v200 = 0;
  v203 = 0;
  v202 = 0;
  if ( pt != PROGRAM_TYPE_VERTEX )
  {
    fragmentParms = this->fragmentParms;
    p_numFragmentParms = &this->numFragmentParms;
  }
  else
  {
    fragmentParms = this->vertexParms;
    p_numFragmentParms = &this->numVertexParms;
  }
  v205 = p_numFragmentParms;
  *p_numFragmentParms = 0;
  v216.len = 0;
  v216.baseBuffer[0] = 0;
  v216.allocedAndFlag = 20;
  v216.data = v216.baseBuffer;
  v216.floatvalue = -3.4028235e38;
  v216.intvalue = 0;
  memset(&v216.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v216);
  v211.allocedAndFlag = 20;
  v211.data = v211.baseBuffer;
  v211.len = 0;
  v211.baseBuffer[0] = 0;
  v215.allocedAndFlag = 20;
  v215.data = v215.baseBuffer;
  v215.len = 0;
  v215.baseBuffer[0] = 0;
  v214.allocedAndFlag = 20;
  v214.data = v214.baseBuffer;
  v214.len = 0;
  v214.baseBuffer[0] = 0;
  v231.allocedAndFlag = 20;
  v231.data = v231.baseBuffer;
  v231.len = 0;
  v231.baseBuffer[0] = 0;
  v210 = 1;
  v18 = idParser::ReadToken(this: src, token: &v216);
  v212 = &r_useUniformArrays;
  if ( !v18 )
  {
_M234240_0:
    if ( pt == PROGRAM_TYPE_VERTEX )
    {
      this->has16BitScaleBias = true;
      if ( (v201 == 0 || v204 == 0) && v203 != 0 )
        this->has16BitScaleBias = false;
      if ( v200 == 0 && v202 != 0 )
        this->has16BitScaleBias = false;
    }
    if ( v211.len == 0 )
    {
      v73 = (char *)this + 32 * target;
      if ( pt != PROGRAM_TYPE_VERTEX )
      {
        idStr::EnsureAlloced(this: (idStr *)(v73 + 500), amount: 1, keepold: true, geometricGrowth: false);
        **((_BYTE **)v73 + 126) = 0;
        *((_DWORD *)v73 + 125) = 0;
      }
      else
      {
        idStr::EnsureAlloced(this: (idStr *)(v73 + 372), amount: 1, keepold: true, geometricGrowth: false);
        **((_BYTE **)v73 + 94) = 0;
        *((_DWORD *)v73 + 93) = 0;
      }
      idStr::FreeData(this: &v231);
      idStr::FreeData(this: &v214);
      idStr::FreeData(this: &v215);
      idStr::FreeData(this: &v211);
      idStr::FreeData(this: &v216);
      if ( v207.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
      if ( v208.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v208.buffer, align: ALIGN_16);
      return true;
    }
    if ( pt != PROGRAM_TYPE_VERTEX )
    {
      len = globalInclude->len;
      v75 = &this->fragmentCode[target];
      idStr::EnsureAlloced(this: v75, amount: globalInclude->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->fragmentCode[target].data, Src: globalInclude->data, Size: len);
      v75->data[len] = 0;
      v75->len = len;
      if ( target != PT_PC )
      {
        if ( target == PT_PC_D3D )
        {
          v143 = va::va(
                   this: &v241,
                   fmt: "cbuffer constantBufferP : register(c%i) {\n",
                   a3: (unsigned int)v135,
                   a4: v134,
                   a5: v133,
                   a6: v176,
                   a7: v180,
                   a8: v184,
                   a9: v188,
                   a10: v192,
                   a11: v196);
          idStr::Append(this: v75, text: v143);
          v144 = 0;
          if ( this->numFragmentParms > 0 )
          {
            v145 = (__int16 *)&this->numVertexParms + 1;
            do
            {
              HIDWORD(v146) = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v145);
              v149 = va::va(
                       this: &v241,
                       fmt: "\tfloat4 %s;\n",
                       a3: v146,
                       a4: v148,
                       a5: v147,
                       a6: v176,
                       a7: v180,
                       a8: v184,
                       a9: v188,
                       a10: v192,
                       a11: v196);
              idStr::Append(this: v75, text: v149);
              ++v144;
            }
            while ( v144 < this->numFragmentParms );
          }
          idStr::Append(this: v75, text: "};\n");
        }
        else if ( target == PT_PS3 || target == PT_360 )
        {
          v150 = 0;
          if ( this->numFragmentParms > 0 )
          {
            v151 = (__int16 *)&this->numVertexParms + 1;
            do
            {
              ParmNameForIndex = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v151);
              v155 = va::va(
                       this: &v241,
                       fmt: "uniform float4 %s : register(c%i);\n",
                       a3: __SPAIR64__((unsigned int)ParmNameForIndex, v150),
                       a4: v154,
                       a5: v153,
                       a6: v176,
                       a7: v180,
                       a8: v184,
                       a9: v188,
                       a10: v192,
                       a11: v196);
              idStr::Append(this: v75, text: v155);
              ++v150;
            }
            while ( v150 < this->numFragmentParms );
          }
        }
      }
      else if ( v212->valueInteger != 0 )
      {
        HIDWORD(v135) = this->numFragmentParms;
        v136 = va::va(
                 this: &v241,
                 fmt: "uniform float4 _fa_[%d];\n",
                 a3: v135,
                 a4: v134,
                 a5: v133,
                 a6: v176,
                 a7: v180,
                 a8: v184,
                 a9: v188,
                 a10: v192,
                 a11: v196);
        idStr::Append(this: v75, text: v136);
      }
      else
      {
        v137 = 0;
        if ( this->numFragmentParms > 0 )
        {
          v138 = (__int16 *)&this->numVertexParms + 1;
          do
          {
            v139 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v138);
            v142 = va::va(
                     this: &v241,
                     fmt: "uniform float4 %s : register(c%i);\n",
                     a3: __SPAIR64__((unsigned int)v139, v137),
                     a4: v141,
                     a5: v140,
                     a6: v176,
                     a7: v180,
                     a8: v184,
                     a9: v188,
                     a10: v192,
                     a11: v196);
            idStr::Append(this: v75, text: v142);
            ++v137;
          }
          while ( v137 < this->numFragmentParms );
        }
      }
      v156 = 0;
      if ( this->numTextureParms > 0 )
      {
        v157 = (__int16 *)&this->numFragmentParms + 1;
        do
        {
          v158 = v157[1];
          v159 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v157);
          v160 = idDeclRenderProg::SamplerTypeForTextureParm(this, target, parmIndex: v158);
          HIDWORD(v161) = v156;
          v163 = va::va(
                   this: &v241,
                   fmt: "uniform %s samp_%s : register(s%i);\n",
                   a3: __SPAIR64__((unsigned int)v160, (unsigned int)v159),
                   a4: v161,
                   a5: v162,
                   a6: v176,
                   a7: v180,
                   a8: v184,
                   a9: v188,
                   a10: v192,
                   a11: v196);
          idStr::Append(this: v75, text: v163);
          ++v156;
        }
        while ( v156 < this->numTextureParms );
      }
      idStr::Append(this: v75, text: "struct PS_IN {\n");
      idStr::Append(this: v75, text: &v215);
      if ( target == PT_PS3 && v215.len == 0 )
        idStr::Append(this: v75, text: "\tfloat4 foo;\n");
      idStr::Append(this: v75, text: "};\n");
      idStr::Append(this: v75, text: "struct PS_OUT {\n");
      idStr::Append(this: v75, text: &v214);
      if ( target == PT_PS3 && v214.len == 0 )
        idStr::Append(this: v75, text: "\tfloat4 foo;\n");
      idStr::Append(this: v75, text: "};\n");
      if ( target == PT_360 && this->registerCount360 != 0 )
      {
        HIDWORD(v166) = this->registerCount360;
        v167 = va::va(
                 this: &v241,
                 fmt: "[maxtempreg(%d)]\n",
                 a3: v166,
                 a4: v165,
                 a5: v164,
                 a6: v176,
                 a7: v180,
                 a8: v184,
                 a9: v188,
                 a10: v192,
                 a11: v196);
        idStr::Append(this: v75, text: v167);
      }
      idStr::Append(this: v75, text: "void main( PS_IN fragment, out PS_OUT result ) {\n");
      idStr::Append(this: v75, text: &v211);
LABEL_242:
      idStr::Append(this: v75, text: "\n}\n");
      idStr::FreeData(this: &v231);
      idStr::FreeData(this: &v214);
      idStr::FreeData(this: &v215);
      idStr::FreeData(this: &v211);
      idStr::FreeData(this: &v216);
      if ( v207.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
      if ( v208.buffer != nullptr )
      {
        idMem::Free(this: &mem, ptr: v208.buffer, align: ALIGN_16);
        return true;
      }
      return true;
    }
    v74 = globalInclude->len;
    v75 = &this->vertexCode[target];
    idStr::EnsureAlloced(this: v75, amount: globalInclude->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->vertexCode[target].data, Src: globalInclude->data, Size: v74);
    v75->data[v74] = 0;
    v75->len = v74;
    if ( target != PT_PC )
    {
      switch ( target )
      {
        case PT_PC_D3D:
          v96 = va::va(
                  this: &v241,
                  fmt: "cbuffer constantBufferV : register(c%i) {\n",
                  a3: (unsigned int)v78,
                  a4: v77,
                  a5: v76,
                  a6: v176,
                  a7: v180,
                  a8: v184,
                  a9: v188,
                  a10: v192,
                  a11: v196);
          idStr::Append(this: v75, text: v96);
          LODWORD(v99) = this->numVertexParms;
          v100 = 0;
          if ( (int)v99 > 0 )
          {
            v101 = (__int16 *)&this->fragmentProgramChecksum + 1;
            do
            {
              HIDWORD(v102) = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v101);
              v105 = va::va(
                       this: &v241,
                       fmt: "\tfloat4 %s;\n",
                       a3: v102,
                       a4: v104,
                       a5: v103,
                       a6: v179,
                       a7: v183,
                       a8: v187,
                       a9: v191,
                       a10: v195,
                       a11: v199);
              idStr::Append(this: v75, text: v105);
              ++v100;
            }
            while ( v100 < this->numVertexParms );
          }
          v106 = va::va(
                   this: &v241,
                   fmt: "\tfloat4 skinOffsets;\n",
                   a3: v98,
                   a4: v97,
                   a5: v99,
                   a6: v179,
                   a7: v183,
                   a8: v187,
                   a9: v191,
                   a10: v195,
                   a11: v199);
          idStr::Append(this: v75, text: v106);
          if ( this->hasHardwareSkinning )
          {
            idStr::Append(this: v75, text: "\tfloat4 hardwareSkinning;\n");
            LODWORD(v107) = &off_82230000;
            HIDWORD(v108) = 222;
            v110 = va::va(
                     this: &v241,
                     fmt: "\tfloat4 matrices[%d];\n",
                     a3: v108,
                     a4: v109,
                     a5: v107,
                     a6: v176,
                     a7: v180,
                     a8: v184,
                     a9: v188,
                     a10: v192,
                     a11: v196);
            idStr::Append(this: v75, text: v110);
          }
          idStr::Append(this: v75, text: "};\n");
          goto LABEL_199;
        case PT_PS3:
          v111 = 0;
          if ( this->numVertexParms > 0 )
          {
            v112 = (__int16 *)&this->fragmentProgramChecksum + 1;
            do
            {
              v113 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v112);
              v116 = va::va(
                       this: &v241,
                       fmt: "uniform float4 %s : register(c%i);\n",
                       a3: __SPAIR64__((unsigned int)v113, v111),
                       a4: v115,
                       a5: v114,
                       a6: v176,
                       a7: v180,
                       a8: v184,
                       a9: v188,
                       a10: v192,
                       a11: v196);
              idStr::Append(this: v75, text: v116);
              ++v111;
            }
            while ( v111 < this->numVertexParms );
          }
          HIDWORD(v78) = this->numVertexParms;
          v117 = va::va(
                   this: &v241,
                   fmt: "uniform float4 skinOffsets : register(c%i);\n",
                   a3: v78,
                   a4: v77,
                   a5: v76,
                   a6: v176,
                   a7: v180,
                   a8: v184,
                   a9: v188,
                   a10: v192,
                   a11: v196);
          idStr::Append(this: v75, text: v117);
          LODWORD(v76) = this->hasHardwareSkinning;
          if ( !this->hasHardwareSkinning )
            goto LABEL_199;
          HIDWORD(v78) = 435;
          v80 = "uniform float4 matrices[%d];\n";
          break;
        case PT_360:
          v118 = 0;
          if ( this->numVertexParms > 0 )
          {
            v119 = (__int16 *)&this->fragmentProgramChecksum + 1;
            do
            {
              v120 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v119);
              v123 = va::va(
                       this: &v241,
                       fmt: "uniform float4 %s : register(c%i);\n",
                       a3: __SPAIR64__((unsigned int)v120, v118),
                       a4: v122,
                       a5: v121,
                       a6: v176,
                       a7: v180,
                       a8: v184,
                       a9: v188,
                       a10: v192,
                       a11: v196);
              idStr::Append(this: v75, text: v123);
              ++v118;
            }
            while ( v118 < this->numVertexParms );
          }
          HIDWORD(v78) = this->numVertexParms;
          v80 = "uniform float4 skinOffsets : register(c%i);\n";
          break;
        default:
          goto LABEL_199;
      }
    }
    else
    {
      if ( v212->valueInteger == 0 )
      {
        v81 = 0;
        if ( this->numVertexParms > 0 )
        {
          v82 = (__int16 *)&this->fragmentProgramChecksum + 1;
          do
          {
            v83 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v82);
            v86 = va::va(
                    this: &v241,
                    fmt: "uniform float4 %s : register(c%i);\n",
                    a3: __SPAIR64__((unsigned int)v83, v81),
                    a4: v85,
                    a5: v84,
                    a6: v176,
                    a7: v180,
                    a8: v184,
                    a9: v188,
                    a10: v192,
                    a11: v196);
            idStr::Append(this: v75, text: v86);
            ++v81;
          }
          while ( v81 < this->numVertexParms );
        }
        HIDWORD(v78) = this->numVertexParms;
        v87 = va::va(
                this: &v241,
                fmt: "uniform float4 skinOffsets : register(c%i);\n",
                a3: v78,
                a4: v77,
                a5: v76,
                a6: v176,
                a7: v180,
                a8: v184,
                a9: v188,
                a10: v192,
                a11: v196);
        idStr::Append(this: v75, text: v87);
        if ( !this->hasHardwareSkinning )
          goto LABEL_199;
        LODWORD(v88) = &off_82230000;
        HIDWORD(v90) = this->numVertexParms + 1;
        v91 = va::va(
                this: &v241,
                fmt: "uniform float4 hardwareSkinning : register(c%i);\n",
                a3: v90,
                a4: v89,
                a5: v88,
                a6: v176,
                a7: v180,
                a8: v184,
                a9: v188,
                a10: v192,
                a11: v196);
        idStr::Append(this: v75, text: v91);
        HIDWORD(v92) = &off_82230000;
        HIDWORD(v93) = 222;
        LODWORD(v93) = this->numVertexParms + 2;
        v95 = va::va(
                this: &v241,
                fmt: "uniform float4 matrices[%d] : register(c%i);\n",
                a3: v93,
                a4: v94,
                a5: v92,
                a6: v178,
                a7: v182,
                a8: v186,
                a9: v190,
                a10: v194,
                a11: v198);
        goto LABEL_198;
      }
      HIDWORD(v78) = this->numVertexParms;
      v79 = va::va(
              this: &v241,
              fmt: "uniform float4 _va_[%d];\n",
              a3: v78,
              a4: v77,
              a5: v76,
              a6: v176,
              a7: v180,
              a8: v184,
              a9: v188,
              a10: v192,
              a11: v196);
      idStr::Append(this: v75, text: v79);
      idStr::Append(this: v75, text: "uniform float4 skinOffsets;\n");
      if ( !this->hasHardwareSkinning )
        goto LABEL_199;
      idStr::Append(this: v75, text: "uniform float4 hardwareSkinning;\n");
      LODWORD(v76) = &off_82230000;
      HIDWORD(v78) = 222;
      v80 = "uniform float4 matrices[%d];\n";
    }
    v95 = va::va(
            this: &v241,
            fmt: v80,
            a3: v78,
            a4: v77,
            a5: v76,
            a6: v176,
            a7: v180,
            a8: v184,
            a9: v188,
            a10: v192,
            a11: v196);
LABEL_198:
    idStr::Append(this: v75, text: v95);
LABEL_199:
    if ( this->hasVertexTexture )
    {
      v124 = 0;
      if ( this->numTextureParms > 0 )
      {
        v125 = (__int16 *)&this->numFragmentParms + 1;
        do
        {
          v126 = v125[1];
          v127 = idParmState::GetParmNameForIndex(this: renderThreadParmState, parmIndex: *++v125);
          v128 = idDeclRenderProg::SamplerTypeForTextureParm(this, target, parmIndex: v126);
          HIDWORD(v129) = v124;
          v131 = va::va(
                   this: &v241,
                   fmt: "uniform %s samp_%s : register(s%i);\n",
                   a3: __SPAIR64__((unsigned int)v128, (unsigned int)v127),
                   a4: v129,
                   a5: v130,
                   a6: v176,
                   a7: v180,
                   a8: v184,
                   a9: v188,
                   a10: v192,
                   a11: v196);
          idStr::Append(this: v75, text: v131);
          ++v124;
        }
        while ( v124 < this->numTextureParms );
      }
    }
    idStr::Append(this: v75, text: "struct VS_IN {\n");
    idStr::Append(this: v75, text: &v215);
    if ( target == PT_PS3 && v215.len == 0 )
      idStr::Append(this: v75, text: "\tfloat4 foo;\n");
    idStr::Append(this: v75, text: "};\n");
    idStr::Append(this: v75, text: "struct VS_OUT {\n");
    idStr::Append(this: v75, text: &v214);
    if ( target == PT_PS3 && v214.len == 0 )
      idStr::Append(this: v75, text: "\tfloat4 foo;\n");
    idStr::Append(this: v75, text: "};\n");
    idStr::Append(this: v75, text: "void main( VS_IN vertex, out VS_OUT result ) {\n");
    if ( target == PT_360 )
      idStr::Append(this: v75, text: &v231);
    idStr::Append(this: v75, text: &v211);
    goto LABEL_242;
  }
  v218 = "texcoord0";
  v222 = " _fa_[%d /* %s */]";
  v19 = v16;
  v224 = " %s";
  v220 = &rpVertexStScaleBias;
  v219 = "branch";
  v221 = &rpVertexXYZBias;
  v213 = " samp_%s";
  v20 = "vertex";
  v227 = "clip";
  v223 = "\t%s %s : %s%s;\n";
  v229 = "_centroid";
  v217 = "TEXCOORD";
  v230 = &byte_8200D768;
  v228 = "hardwareSkinning";
  v225 = "\tresult.%s = 0;\n";
  v21 = fragmentParms;
  v226 = "position";
  fragmentParms = (__int16 *)"vertex";
  while ( v216.type != 5 )
  {
LABEL_66:
    if ( pt != PROGRAM_TYPE_VERTEX )
    {
      if ( pt == PROGRAM_TYPE_FRAGMENT && v216.type == 4 )
      {
        if ( idStr::Cmp(s1: v216.data, s2: "fragment") != 0 || idParser::CheckTokenString(this: src, string: ".") == 0 )
        {
          if ( idStr::Cmp(s1: v216.data, s2: "result") != 0 || idParser::CheckTokenString(this: src, string: ".") == 0 )
          {
            if ( idStr::Cmp(s1: v216.data, s2: v227) != 0 )
              idStr::Cmp(s1: v216.data, s2: v219);
            else
              this->hasClip = true;
          }
          else
          {
            v235.floatvalue = -3.4028235e38;
            v235.allocedAndFlag = 20;
            v235.data = v235.baseBuffer;
            v235.len = 0;
            v235.baseBuffer[0] = 0;
            v235.intvalue = 0;
            memset(&v235.whiteSpaceStart_p, 0, 12);
            idParser::ReadToken(this: src, token: &v235);
            v61 = operator+(result: &v240, a: ".", b: &v235);
            idStr::Append(this: &v216, text: v61);
            idStr::FreeData(this: &v240);
            v62 = 0;
            p_name = &v206->name;
            while ( ((unsigned int)p_name[4] & 0x10) == 0
                 || v207.buffer[v62] != 0
                 || idStr::Cmp(s1: v235.data, s2: *p_name) != 0 )
            {
              ++v62;
              p_name += 7;
              if ( v62 >= v19 )
                goto LABEL_118;
            }
            v66 = &v206[v62];
            HIDWORD(v65) = v66->semantic;
            v67 = va::va(
                    this: &v241,
                    fmt: "\t%s %s : %s;\n",
                    a3: *(_QWORD *)&v66->type,
                    a4: v65,
                    a5: v64,
                    a6: v176,
                    a7: v180,
                    a8: v184,
                    a9: v188,
                    a10: v192,
                    a11: v196);
            idStr::Append(this: &v214, text: v67);
            v207.buffer[v62] = 1;
            ++this->fragmentOutputs;
LABEL_118:
            idStr::FreeData(this: &v235);
          }
        }
        else
        {
          v236.floatvalue = -3.4028235e38;
          v236.allocedAndFlag = 20;
          v236.data = v236.baseBuffer;
          v236.len = 0;
          v236.baseBuffer[0] = 0;
          v236.intvalue = 0;
          memset(&v236.whiteSpaceStart_p, 0, 12);
          idParser::ReadToken(this: src, token: &v236);
          v53 = operator+(result: &v239, a: ".", b: &v236);
          idStr::Append(this: &v216, text: v53);
          idStr::FreeData(this: &v239);
          v54 = 0;
          v55 = &v206->name;
          while ( ((unsigned int)v55[4] & 8) == 0 || v208.buffer[v54] != 0 || idStr::Cmp(s1: v236.data, s2: *v55) != 0 )
          {
            ++v54;
            v55 += 7;
            if ( v54 >= v19 )
              goto LABEL_108;
          }
          v57 = v230;
          if ( target == PT_360 && idStr::Icmpn(s1: v206[v54].semantic, s2: v217, n: 8) == 0 )
            v57 = (void *)v229;
          v58 = &v206[v54];
          LODWORD(v59) = v57;
          HIDWORD(v59) = v58->semantic;
          v60 = va::va(
                  this: &v241,
                  fmt: v223,
                  a3: *(_QWORD *)&v58->type,
                  a4: v59,
                  a5: v56,
                  a6: v176,
                  a7: v180,
                  a8: v184,
                  a9: v188,
                  a10: v192,
                  a11: v196);
          idStr::Append(this: &v215, text: v60);
          v208.buffer[v54] = 1;
LABEL_108:
          idStr::FreeData(this: &v236);
        }
      }
    }
    else if ( v216.type == 4 )
    {
      if ( idStr::Cmp(s1: v216.data, s2: v20) != 0 || idParser::CheckTokenString(this: src, string: ".") == 0 )
      {
        if ( idStr::Cmp(s1: v216.data, s2: "result") != 0 || idParser::CheckTokenString(this: src, string: ".") == 0 )
        {
          if ( idStr::Cmpn(s1: v216.data, s2: v228, n: 16) == 0 )
            this->hasHardwareSkinning = true;
        }
        else
        {
          v234.floatvalue = -3.4028235e38;
          v234.allocedAndFlag = 20;
          v234.data = v234.baseBuffer;
          v234.len = 0;
          v234.baseBuffer[0] = 0;
          v234.intvalue = 0;
          memset(&v234.whiteSpaceStart_p, 0, 12);
          idParser::ReadToken(this: src, token: &v234);
          v42 = operator+(result: &v237, a: ".", b: &v234);
          idStr::Append(this: &v216, text: v42);
          idStr::FreeData(this: &v237);
          v43 = 0;
          v44 = &v206->name;
          while ( ((unsigned int)v44[4] & 4) == 0 || v207.buffer[v43] != 0 || idStr::Cmp(s1: v234.data, s2: *v44) != 0 )
          {
            ++v43;
            v44 += 7;
            if ( v43 >= v19 )
              goto LABEL_91;
          }
          v47 = &v206[v43];
          HIDWORD(v46) = v47->semantic;
          v48 = va::va(
                  this: &v241,
                  fmt: "\t%s %s : %s;\n",
                  a3: *(_QWORD *)&v47->type,
                  a4: v46,
                  a5: v45,
                  a6: v176,
                  a7: v180,
                  a8: v184,
                  a9: v188,
                  a10: v192,
                  a11: v196);
          idStr::Append(this: &v214, text: v48);
          HIDWORD(v49) = v47->name;
          v52 = va::va(
                  this: &v241,
                  fmt: v225,
                  a3: v49,
                  a4: v51,
                  a5: v50,
                  a6: v177,
                  a7: v181,
                  a8: v185,
                  a9: v189,
                  a10: v193,
                  a11: v197);
          idStr::Append(this: &v231, text: v52);
          v207.buffer[v43] = 1;
LABEL_91:
          idStr::FreeData(this: &v234);
        }
      }
      else
      {
        v233.floatvalue = -3.4028235e38;
        v233.allocedAndFlag = 20;
        v233.data = v233.baseBuffer;
        v233.len = 0;
        v233.baseBuffer[0] = 0;
        v233.intvalue = 0;
        memset(&v233.whiteSpaceStart_p, 0, 12);
        idParser::ReadToken(this: src, token: &v233);
        v35 = operator+(result: &v238, a: ".", b: &v233);
        idStr::Append(this: &v216, text: v35);
        idStr::FreeData(this: &v238);
        v36 = 0;
        v37 = &v206->name;
        while ( ((unsigned int)v37[4] & 2) == 0 || v208.buffer[v36] != 0 || idStr::Cmp(s1: v233.data, s2: *v37) != 0 )
        {
          ++v36;
          v37 += 7;
          if ( v36 >= v19 )
            goto LABEL_77;
        }
        LODWORD(v38) = this->vertexMask;
        v39 = &v206[v36];
        HIDWORD(v38) = v39->vertexMask;
        LODWORD(v40) = HIDWORD(v38) | v38;
        this->vertexMask = HIDWORD(v38) | v38;
        HIDWORD(v40) = v39->semantic;
        v41 = va::va(
                this: &v241,
                fmt: "\t%s %s : %s;\n",
                a3: *(_QWORD *)&v39->type,
                a4: v40,
                a5: v38,
                a6: v176,
                a7: v180,
                a8: v184,
                a9: v188,
                a10: v192,
                a11: v196);
        idStr::Append(this: &v215, text: v41);
        v208.buffer[v36] = 1;
LABEL_77:
        if ( idStr::Cmp(s1: v233.data, s2: v226) != 0 )
        {
          if ( idStr::Cmp(s1: v233.data, s2: v218) == 0 )
            v202 = 1;
        }
        else
        {
          v203 = 1;
        }
        idStr::FreeData(this: &v233);
      }
    }
    if ( v216.linesCrossed > 0 )
    {
      idStr::EnsureAlloced(this: &v211, amount: v211.len + 2, keepold: true, geometricGrowth: true);
      v211.data[v211.len++] = 10;
      v211.data[v211.len] = 0;
    }
    if ( v216.whiteSpaceStart_p < v216.whiteSpaceEnd_p )
    {
      idStr::EnsureAlloced(this: &v211, amount: v211.len + 2, keepold: true, geometricGrowth: true);
      v211.data[v211.len++] = 32;
      v211.data[v211.len] = 0;
    }
    idStr::Append(this: &v211, text: &v216);
LABEL_127:
    if ( !idParser::ReadToken(this: src, token: &v216) )
      goto _M234240_0;
    v20 = (const char *)fragmentParms;
  }
  if ( v216.subtype != 52 )
  {
    if ( v216.subtype == 46 )
    {
      ++v210;
    }
    else if ( v216.subtype == 47 && --v210 <= 0 )
    {
      goto _M234240_0;
    }
    goto LABEL_66;
  }
  idParser::ReadToken(this: src, token: &v216);
  idStr::idStr(this: &v232, text: &v216);
  data = v232.data;
  if ( v232.data == nullptr )
    goto LABEL_130;
  v26 = idDeclInfo::FindWithInheritance(this: &idDeclRenderParm::resourceList, name: v232.data, makeDefault: false);
  v27 = v26;
  if ( v26 != nullptr )
  {
    LODWORD(v23) = v26[1].trackedMemory;
    if ( (int)v23 < 1 || (v28 = 1, (int)v23 > 8) )
      v28 = 0;
    if ( v28 != 0 )
    {
      numTextureParms = (unsigned int)this->numTextureParms;
      LODWORD(v23) = 0;
      if ( (int)numTextureParms > 0 )
      {
        HIDWORD(v23) = v26[1].__vftable;
        textureParms = this->textureParms;
        while ( 1 )
        {
          LODWORD(v25) = (unsigned __int16)*textureParms;
          if ( (__int16)v25 == HIDWORD(v23) )
            break;
          LODWORD(v25) = this->numTextureParms;
          LODWORD(v23) = v23 + 1;
          ++textureParms;
          if ( (int)v23 >= (int)v25 )
            goto LABEL_33;
        }
        HIDWORD(numTextureParms) = 1;
      }
LABEL_33:
      if ( BYTE3(numTextureParms) == 0 )
      {
        if ( (int)numTextureParms >= 16 )
        {
          v70 = v20;
          if ( pt != PROGRAM_TYPE_VERTEX )
            v70 = "fragment";
          idParser::Warning(this: src, str: "more than %d samplers used in %s program", 16, v70);
          idStr::FreeData(this: &v232);
          idStr::FreeData(this: &v231);
          idStr::FreeData(this: &v214);
          idStr::FreeData(this: &v215);
          idStr::FreeData(this: &v211);
          idStr::FreeData(this: &v216);
          if ( v207.buffer != nullptr )
            idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
          goto LABEL_134;
        }
        LODWORD(v23) = v26[1].__vftable;
        HIDWORD(v23) = 2 * (numTextureParms + 138);
        *(_WORD *)((char *)&this->__vftable + HIDWORD(v23)) = v23;
        HIDWORD(numTextureParms) = this->numTextureParms + 1;
        this->numTextureParms = HIDWORD(numTextureParms);
      }
      if ( pt == PROGRAM_TYPE_VERTEX )
      {
        this->hasVertexTexture = true;
        idParser::Warning(this: src, str: "using a texture sampler in the vertex program");
      }
      v30 = v213;
LABEL_60:
      HIDWORD(v25) = v27->name.str;
      v34 = va::va(
              this: &v241,
              fmt: v30,
              a3: v25,
              a4: numTextureParms,
              a5: v23,
              a6: v176,
              a7: v180,
              a8: v184,
              a9: v188,
              a10: v192,
              a11: v196);
    }
    else
    {
      if ( (_DWORD)v23 != 0 )
      {
        v72 = v20;
        if ( pt != PROGRAM_TYPE_VERTEX )
          v72 = "fragment";
        idParser::Warning(this: src, str: "invalid render parm '%s' used in %s program", v232.data, v72);
        idStr::FreeData(this: &v232);
        idStr::FreeData(this: &v231);
        idStr::FreeData(this: &v214);
        idStr::FreeData(this: &v215);
        idStr::FreeData(this: &v211);
        idStr::FreeData(this: &v216);
        if ( v207.buffer != nullptr )
          idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
        goto LABEL_134;
      }
      HIDWORD(v23) = *v205;
      v31 = 0;
      if ( *v205 > 0 )
      {
        LODWORD(v23) = v26[1].__vftable;
        v32 = v21;
        do
        {
          LODWORD(numTextureParms) = (unsigned __int16)*v32;
          HIDWORD(numTextureParms) = (__int16)numTextureParms;
          if ( (__int16)numTextureParms == (_DWORD)v23 )
            break;
          LODWORD(numTextureParms) = *v205;
          ++v31;
          ++v32;
        }
        while ( v31 < *v205 );
      }
      if ( v31 == HIDWORD(v23) )
      {
        if ( v31 >= 32 )
        {
          v71 = (const char *)fragmentParms;
          if ( pt != PROGRAM_TYPE_VERTEX )
            v71 = "fragment";
          idParser::Warning(this: src, str: "more than %d render parms used in %s program", 32, v71);
          idStr::FreeData(this: &v232);
          idStr::FreeData(this: &v231);
          idStr::FreeData(this: &v214);
          idStr::FreeData(this: &v215);
          idStr::FreeData(this: &v211);
          idStr::FreeData(this: &v216);
          if ( v207.buffer != nullptr )
            idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
          goto LABEL_134;
        }
        LODWORD(v23) = 2 * v31;
        v21[v31] = (__int16)v26[1].__vftable;
        LODWORD(numTextureParms) = *v205 + 1;
        *v205 = numTextureParms;
      }
      if ( pt == PROGRAM_TYPE_VERTEX )
      {
        if ( idStr::Icmp(s1: v26->name.str, s2: rpVertexXYZScale.r->name.str) == 0 )
          v201 = 1;
        if ( idStr::Icmp(s1: v27->name.str, s2: v221->r->name.str) == 0 )
          v204 = 1;
        if ( idStr::Icmp(s1: v27->name.str, s2: v220->r->name.str) == 0 )
          v200 = 1;
      }
      if ( target != PT_PC || v212->valueInteger == 0 )
      {
        v30 = v224;
        goto LABEL_60;
      }
      HIDWORD(v33) = v31;
      LODWORD(v33) = v27->name.str;
      if ( pt != PROGRAM_TYPE_VERTEX )
        v34 = va::va(
                this: &v241,
                fmt: v222,
                a3: v33,
                a4: numTextureParms,
                a5: v23,
                a6: v176,
                a7: v180,
                a8: v184,
                a9: v188,
                a10: v192,
                a11: v196);
      else
        v34 = va::va(
                this: &v241,
                fmt: " _va_[%d /* %s */]",
                a3: v33,
                a4: numTextureParms,
                a5: v23,
                a6: v176,
                a7: v180,
                a8: v184,
                a9: v188,
                a10: v192,
                a11: v196);
    }
    idStr::Append(this: &v211, text: v34);
    idStr::FreeData(this: &v232);
    goto LABEL_127;
  }
  data = v232.data;
LABEL_130:
  v68 = v20;
  if ( pt != PROGRAM_TYPE_VERTEX )
    v68 = "fragment";
  idParser::Warning(this: src, str: "render parm '%s' not found for %s program", data, v68);
  idStr::FreeData(this: &v232);
  idStr::FreeData(this: &v231);
  idStr::FreeData(this: &v214);
  idStr::FreeData(this: &v215);
  idStr::FreeData(this: &v211);
  idStr::FreeData(this: &v216);
  if ( v207.buffer != nullptr )
    idMem::Free(this: &mem, ptr: v207.buffer, align: ALIGN_16);
LABEL_134:
  if ( v208.buffer != nullptr )
    idMem::Free(this: &mem, ptr: v208.buffer, align: ALIGN_16);
  return false;
}


// ========================================================================
// $LN766_0
// EA  : 0x828B20B4
// RVA : 0x008B20B4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _LN766_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 5136 + 112));
}


// ========================================================================
// __unwind$233256
// EA  : 0x828B20DC
// RVA : 0x008B20DC
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233256()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 5136 + 104));
}


// ========================================================================
// __unwind$233257
// EA  : 0x828B2104
// RVA : 0x008B2104
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233257()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 240));
}


// ========================================================================
// __unwind$233258
// EA  : 0x828B212C
// RVA : 0x008B212C
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233258()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 128));
}


// ========================================================================
// __unwind$233259
// EA  : 0x828B2154
// RVA : 0x008B2154
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233259()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 208));
}


// ========================================================================
// __unwind$233260
// EA  : 0x828B217C
// RVA : 0x008B217C
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233260()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 176));
}


// ========================================================================
// __unwind$233261
// EA  : 0x828B21A4
// RVA : 0x008B21A4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233261()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 368));
}


// ========================================================================
// __unwind$233262
// EA  : 0x828B21CC
// RVA : 0x008B21CC
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233262()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 400));
}


// ========================================================================
// __unwind$233263
// EA  : 0x828B21F4
// RVA : 0x008B21F4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233263()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 432));
}


// ========================================================================
// __unwind$233264
// EA  : 0x828B221C
// RVA : 0x008B221C
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233264()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 784));
}


// ========================================================================
// __unwind$233265
// EA  : 0x828B2244
// RVA : 0x008B2244
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 512));
}


// ========================================================================
// __unwind$233266
// EA  : 0x828B226C
// RVA : 0x008B226C
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233266()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 752));
}


// ========================================================================
// __unwind$233267
// EA  : 0x828B2294
// RVA : 0x008B2294
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233267()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 672));
}


// ========================================================================
// __unwind$233268
// EA  : 0x828B22BC
// RVA : 0x008B22BC
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233268()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 816));
}


// ========================================================================
// __unwind$233269
// EA  : 0x828B22E4
// RVA : 0x008B22E4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233269()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 592));
}


// ========================================================================
// __unwind$233270
// EA  : 0x828B230C
// RVA : 0x008B230C
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_233270()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 848));
}


// ========================================================================
// ?ParseSingleTarget@idDeclRenderProg@@AAAXW4progTarget_t@@AAVidParser@@@Z
// EA  : 0x828B2340
// RVA : 0x008B2340
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::ParseSingleTarget(idDeclRenderProg *this, progTarget_t target, idParser *src)
{
  unsigned __int64 v3; // r30
  int includeLevel; // r22
  int v8; // r11
  int v9; // r10
  int v10; // r11
  int v11; // r10
  char v12; // r24
  long double v13; // fp2
  long double v14; // fp2
  int Flags; // r24
  int v16; // r10
  int v17; // r9
  int v18; // r8
  bool v19; // r15
  int v20; // r24
  int v21; // r10
  int v22; // r9
  int v23; // r8
  bool v24; // r15
  int v25; // [sp+8h] [-148h]
  int v26; // [sp+Ch] [-144h]
  int v27; // [sp+10h] [-140h]
  int v28; // [sp+14h] [-13Ch]
  idStr v29; // [sp+50h] [-100h] BYREF
  idToken v30[3]; // [sp+70h] [-E0h] BYREF

  LODWORD(v3) = 0;
  v30[0].len = 0;
  v30[0].allocedAndFlag = 20;
  v30[0].floatvalue = -3.4028235e38;
  v30[0].data = v30[0].baseBuffer;
  v30[0].baseBuffer[0] = 0;
  v30[0].intvalue = 0;
  v30[0].whiteSpaceStart_p = nullptr;
  v30[0].whiteSpaceEnd_p = nullptr;
  v30[0].next = nullptr;
  v29.allocedAndFlag = 20;
  v29.data = v29.baseBuffer;
  v29.len = 0;
  v29.baseBuffer[0] = 0;
  idStr::ReAllocate(this: &v29, amount: 40000, keepold: false);
  includeLevel = src->includeLevel;
  idParser::AddInclude(this: src, fileName: "/decls/renderprogs/global.inc");
  if ( idParser::ReadToken(this: src, token: v30) )
  {
    while ( src->includeLevel > includeLevel )
    {
      HIDWORD(v3) = v30[0].whiteSpaceStart_p < v30[0].whiteSpaceEnd_p;
      if ( v30[0].linesCrossed > 0 )
      {
        idStr::EnsureAlloced(this: &v29, amount: v29.len + 2, keepold: true, geometricGrowth: true);
        --HIDWORD(v3);
        v29.data[v29.len++] = 10;
        v29.data[v29.len] = 0;
      }
      if ( SHIDWORD(v3) > 0 )
      {
        do
        {
          v8 = v29.len + 2;
          v9 = v29.allocedAndFlag & 0x7FFFFFFF;
          if ( v29.allocedAndFlag >= 0 )
          {
            if ( v8 > v9 )
              idStr::ReAllocate(this: &v29, amount: (v8 >> 1) + v8, keepold: true);
          }
          else if ( v8 > v9
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          --HIDWORD(v3);
          v29.data[v29.len++] = 32;
          v29.data[v29.len] = 0;
        }
        while ( HIDWORD(v3) != 0 );
      }
      idStr::Append(this: &v29, text: &v30[0]);
      if ( !idParser::ReadToken(this: src, token: v30) )
        goto LABEL_16;
    }
    idParser::UnreadToken(this: src, token: v30);
  }
LABEL_16:
  v10 = v29.len + 2;
  v11 = v29.allocedAndFlag & 0x7FFFFFFF;
  if ( v29.allocedAndFlag >= 0 )
  {
    if ( v10 > v11 )
      idStr::ReAllocate(this: &v29, amount: (v10 >> 1) + v10, keepold: true);
  }
  else if ( v10 > v11
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  v29.data[v29.len++] = 10;
  v29.data[v29.len] = 0;
  declManager->AddDependency(this: declManager, a2: (idDecl *)this, a3: "/decls/renderprogs/global.inc");
  this->glState = v3;
  v12 = 0;
  idParmBlock::Clear(this: &this->parmBlock);
  this->numVertexParms = 0;
  this->numFragmentParms = 0;
  this->numTextureParms = 0;
  if ( !idParser::ReadToken(this: src, token: v30) )
    goto LABEL_42;
  while ( idStr::Icmp(s1: v30[0].data, s2: "inherit") == 0 )
  {
    if ( LODWORD(this->glState) != 0 || this->parmBlock.ops.num != 0 || v12 != 0 )
    {
      idParser::Warning(this: src, str: "'inherit' MUST come before all other commands");
      idStr::FreeData(this: &v29);
      goto _M234627_1;
    }
    if ( (unsigned __int8)idDeclRenderProg::ParseInheritance(this, target, src) == 0 )
      goto LABEL_42;
LABEL_41:
    if ( !idParser::ReadToken(this: src, token: v30) )
      goto LABEL_42;
  }
  if ( idStr::Icmp(s1: v30[0].data, s2: "parms") == 0 )
  {
    idParser::ExpectTokenString(this: src, string: "{");
    idParmBlock::Clear(this: &this->parmBlock);
    idParmBlock::Parse(this: &this->parmBlock, src);
    *(double *)&v13 = idParmBlock::GetFloat(this: &this->parmBlock, parm: (const idDeclRenderParm *)rpStageSort.r);
    v14 = floor(x: v13);
    this->stageSort = *(double *)&v14;
    goto LABEL_41;
  }
  if ( idStr::Icmp(s1: v30[0].data, s2: "state") == 0 )
  {
    HIDWORD(v3) = &this->parmBlock;
    this->glState = v3;
    this->hasAlphaToCoverage = false;
    idDeclRenderProg::ParseState(this, src);
    goto LABEL_41;
  }
  if ( idStr::Icmp(s1: v30[0].data, s2: "interaction") == 0 )
  {
    this->hasInteractions = true;
    goto LABEL_41;
  }
  if ( idStr::Icmp(s1: v30[0].data, s2: "hlsl_vp") == 0 )
  {
    Flags = (int)idParser::GetFlags(this: (idClientGame *)src);
    idParser::SetFlags(this: src, flags: Flags & 0xFFFFFDFF);
    idParser::PushDefineScope(this: src);
    v19 = idDeclRenderProg::ParseProgram(
            this,
            target,
            pt: PROGRAM_TYPE_VERTEX,
            src,
            globalInclude: &v29,
            a6: v18,
            a7: v17,
            a8: v16,
            a9: v25,
            a10: v26,
            a11: v27,
            a12: v28);
    idParser::PopDefineScope(this: src);
    idParser::SetFlags(this: src, flags: Flags);
    if ( !v19 )
      goto LABEL_42;
LABEL_40:
    v12 = 1;
    goto LABEL_41;
  }
  if ( idStr::Icmp(s1: v30[0].data, s2: "hlsl_fp") == 0 )
  {
    v20 = (int)idParser::GetFlags(this: (idClientGame *)src);
    idParser::SetFlags(this: src, flags: v20 & 0xFFFFFDFF);
    idParser::PushDefineScope(this: src);
    v24 = idDeclRenderProg::ParseProgram(
            this,
            target,
            pt: PROGRAM_TYPE_FRAGMENT,
            src,
            globalInclude: &v29,
            a6: v23,
            a7: v22,
            a8: v21,
            a9: v25,
            a10: v26,
            a11: v27,
            a12: v28);
    idParser::PopDefineScope(this: src);
    idParser::SetFlags(this: src, flags: v20);
    if ( !v24 )
      goto LABEL_42;
    goto LABEL_40;
  }
  if ( idStr::Cmp(s1: v30[0].data, s2: "}") != 0 )
  {
    idParser::Warning(this: src, str: "Unknown program type: %s", v30[0].data);
    idStr::FreeData(this: &v29);
    goto _M234627_1;
  }
LABEL_42:
  idStr::FreeData(this: &v29);
_M234627_1:
  idStr::FreeData(this: &v30[0]);
}


// ========================================================================
// $M234638_1
// EA  : 0x828B28D4
// RVA : 0x008B28D4
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _M234638_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$234331
// EA  : 0x828B28FC
// RVA : 0x008B28FC
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _unwind_234331()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// ?Parse@idDeclRenderProg@@UAAXAAVidParser@@@Z
// EA  : 0x828B2928
// RVA : 0x008B2928
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __fastcall idDeclRenderProg::Parse(idDeclRenderProg *this, idParser *src)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  va *v10; // r4
  const idDeclRenderProg *v11; // r11
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r4
  const idDeclRenderProg *v16; // r3
  va *v17; // r4
  const idDeclRenderProg *v18; // r3
  const idDeclRenderProg *v19; // r11
  int i; // r31
  idResource *v21; // r3
  int staleCount; // r11
  idResource_vtbl **v23; // r10
  idResource *v24; // r9
  int v25; // ctr
  int v26; // r11
  int *p_allocedAndFlag; // r31
  int j; // r29
  _BYTE *v29; // r11
  _BYTE *v30; // r11
  int v31; // [sp+8h] [-1078h]
  int v32; // [sp+8h] [-1078h]
  int v33; // [sp+8h] [-1078h]
  int v34; // [sp+Ch] [-1074h]
  int v35; // [sp+Ch] [-1074h]
  int v36; // [sp+Ch] [-1074h]
  int v37; // [sp+10h] [-1070h]
  int v38; // [sp+10h] [-1070h]
  int v39; // [sp+10h] [-1070h]
  int v40; // [sp+14h] [-106Ch]
  int v41; // [sp+14h] [-106Ch]
  int v42; // [sp+14h] [-106Ch]
  int v43; // [sp+18h] [-1068h]
  int v44; // [sp+18h] [-1068h]
  int v45; // [sp+18h] [-1068h]
  int v46; // [sp+1Ch] [-1064h]
  int v47; // [sp+1Ch] [-1064h]
  int v48; // [sp+1Ch] [-1064h]
  va v49; // [sp+50h] [-1030h] BYREF

  if ( r_feedbackBGRA.valueInteger != 0 )
    idParser::AddDefine(this: src, string: "FEEDBACK_BGRA 1");
  idDeclRenderProg::ParseSingleTarget(this, target: PT_360, src);
  idParmState::UpdateParmUsageMasks(this: renderThreadParmState, prog: this);
  if ( this->fragmentCode[2].len != 0 || this->vertexCode[2].len != 0 )
    idDeclRenderProg::UploadTargetCode(this);
  if ( this->hasInteractions )
  {
    HIDWORD(v6) = this->name.str;
    LODWORD(v4) = this->hasInteractions;
    v10 = va::va(
            this: &v49,
            fmt: "%s_point",
            a3: v6,
            a4: v5,
            a5: v4,
            a6: v31,
            a7: v34,
            a8: v37,
            a9: v40,
            a10: v43,
            a11: v46);
    if ( v10 != nullptr )
      v11 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderProg::resourceList,
                                        name: v10->buffer,
                                        makeDefault: true);
    else
      v11 = nullptr;
    this->versions[0] = v11;
    HIDWORD(v9) = this->name.str;
    v15 = va::va(
            this: &v49,
            fmt: "%s_spot",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v32,
            a7: v35,
            a8: v38,
            a9: v41,
            a10: v44,
            a11: v47);
    if ( v15 != nullptr )
      v16 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderProg::resourceList,
                                        name: v15->buffer,
                                        makeDefault: true);
    else
      v16 = nullptr;
    this->versions[1] = v16;
    HIDWORD(v14) = this->name.str;
    v17 = va::va(
            this: &v49,
            fmt: "%s_parallel",
            a3: v14,
            a4: v13,
            a5: v12,
            a6: v33,
            a7: v36,
            a8: v39,
            a9: v42,
            a10: v45,
            a11: v48);
    if ( v17 != nullptr )
      v18 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderProg::resourceList,
                                        name: v17->buffer,
                                        makeDefault: true);
    else
      v18 = nullptr;
    v19 = this->versions[0];
    this->versions[2] = v18;
    this->versions[3] = v19;
  }
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  if ( this->hasDerived )
  {
    for ( i = 0; i < idDeclRenderProg::resourceList.num; ++i )
    {
      v21 = idResourceList::Index(this: &idDeclRenderProg::resourceList, index: i);
      staleCount = v21[8].staleCount;
      if ( staleCount != 0 )
      {
        v23 = (idResource_vtbl **)(staleCount + 320);
        v24 = (idResource *)((char *)v21 + 320);
        v21[3].networkID = *(_DWORD *)(staleCount + 132);
        v25 = 8;
        v21[10].__vftable = *(idResource_vtbl **)(staleCount + 360);
        do
        {
          ++v23;
          v24 = (idResource *)((char *)v24 + 4);
          v24->__vftable = *v23;
          --v25;
        }
        while ( v25 != 0 );
        *((_DWORD *)&v21[9] + 8) = *(_DWORD *)(v21[8].staleCount + 356);
      }
      v26 = *((_DWORD *)&v21[8] + 8);
      if ( v26 != 0 )
      {
        v21[3].staleCount = *(_DWORD *)(v26 + 136);
        v21[10].trackedMemory = *(_DWORD *)(v26 + 364);
      }
    }
  }
  if ( !idLib::headless )
  {
    if ( this->numVertexDeclarations == 0 )
      idParser::Warning(this: src, str: "renderprog error");
    p_allocedAndFlag = &this->vertexCode[0].allocedAndFlag;
    for ( j = 4; j != 0; --j )
    {
      if ( *p_allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: (idStr *)(p_allocedAndFlag - 2));
        *p_allocedAndFlag = 20;
        *(p_allocedAndFlag - 1) = (int)(p_allocedAndFlag + 1);
        *(p_allocedAndFlag - 2) = 0;
        *((_BYTE *)p_allocedAndFlag + 4) = 0;
      }
      else
      {
        v29 = (_BYTE *)*(p_allocedAndFlag - 1);
        *(p_allocedAndFlag - 2) = 0;
        *v29 = 0;
      }
      if ( p_allocedAndFlag[32] >= 0 )
      {
        idStr::FreeData(this: (idStr *)(p_allocedAndFlag + 30));
        p_allocedAndFlag[32] = 20;
        p_allocedAndFlag[31] = (int)(p_allocedAndFlag + 33);
        p_allocedAndFlag[30] = 0;
        *((_BYTE *)p_allocedAndFlag + 132) = 0;
      }
      else
      {
        v30 = (_BYTE *)p_allocedAndFlag[31];
        p_allocedAndFlag[30] = 0;
        *v30 = 0;
      }
      p_allocedAndFlag += 8;
    }
  }
}


// ========================================================================
// `dynamic initializer for 'rpStageSort''
// EA  : 0x8334B880
// RVA : 0x0134B880
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _dynamic_initializer_for__rpStageSort__()
{
  rpStageSort.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpStageSort;
}


// ========================================================================
// `dynamic initializer for 'rpVertexXYZScale''
// EA  : 0x8334B8A0
// RVA : 0x0134B8A0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _dynamic_initializer_for__rpVertexXYZScale__()
{
  rpVertexXYZScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpVertexXYZScale;
}


// ========================================================================
// `dynamic initializer for 'rpVertexXYZBias''
// EA  : 0x8334B8C0
// RVA : 0x0134B8C0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _dynamic_initializer_for__rpVertexXYZBias__()
{
  rpVertexXYZBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpVertexXYZBias;
}


// ========================================================================
// `dynamic initializer for 'rpVertexStScaleBias''
// EA  : 0x8334B8E0
// RVA : 0x0134B8E0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void _dynamic_initializer_for__rpVertexStScaleBias__()
{
  rpVertexStScaleBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpVertexStScaleBias;
}


// ========================================================================
// `dynamic initializer for 'r_useUniformArrays''
// EA  : 0x8334B900
// RVA : 0x0134B900
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useUniformArrays__()
{
  idCVar::idCVar(
    this: &r_useUniformArrays,
    name: "r_useUniformArrays",
    value: "1",
    flags: 16386,
    description: "0: use individual uniforms, 1: use uniform array",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useUniformArrays__);
}


// ========================================================================
// `dynamic initializer for 'r_genAllRenderProgs''
// EA  : 0x8334B968
// RVA : 0x0134B968
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_genAllRenderProgs__()
{
  idCVar::idCVar(
    this: &r_genAllRenderProgs,
    name: "r_genAllRenderProgs",
    value: "0",
    flags: 2,
    description: "generate render-progs for all platforms, 1 = ALL, 2 = 360 & PC Only, 3 = PS3 & PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_genAllRenderProgs__);
}


// ========================================================================
// `dynamic initializer for 'r_validateRenderProgs''
// EA  : 0x8334B9C0
// RVA : 0x0134B9C0
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_validateRenderProgs__()
{
  idCVar::idCVar(
    this: &r_validateRenderProgs,
    name: "r_validateRenderProgs",
    value: "1",
    flags: 2,
    description: "if > 0 validates 360 shaders and points out potential shader patch issues - use with r_genAllRenderProgs on PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_validateRenderProgs__);
}


// ========================================================================
// `dynamic initializer for 'testRenderProgs_v''
// EA  : 0x8334BA18
// RVA : 0x0134BA18
// PDB : w:\tech5\engine\renderer\declrenderprog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testRenderProgs_v__()
{
  return idCommandLink::idCommandLink(
           this: &testRenderProgs_v,
           cmdName: "testRenderProgs",
           function: testRenderProgs_f,
           description: "Load and compile all render progs or load and compile a specific renderprog",
           argCompletion: nullptr);
}

