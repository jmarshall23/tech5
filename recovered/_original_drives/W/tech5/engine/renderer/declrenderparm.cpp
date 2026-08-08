
// ========================================================================
// ??0idDeclRenderParm@@QAA@XZ
// EA  : 0x828AD668
// RVA : 0x008AD668
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

idDeclRenderParm *__fastcall idDeclRenderParm::idDeclRenderParm(idDeclRenderParm *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->parmIndex = 2047;
  this->editRange[0] = 0.0;
  this->__vftable = (idDeclRenderParm_vtbl *)&idDeclRenderParm::`vftable';
  this->editRange[1] = 1.0;
  this->parmType = PT_VECTOR;
  this->creator = PC_PARSED;
  this->cubeFilterTexture = false;
  this->edit = PE_NO_EDIT;
  this->declaredValue.swizzle[0] = 0;
  this->declaredValue.swizzle[1] = 0;
  this->declaredValue.swizzle[2] = 0;
  this->declaredValue.swizzle[3] = 0;
  return this;
}


// ========================================================================
// ?DefaultDefinition@idDeclRenderParm@@UBAPBDXZ
// EA  : 0x828AD6F0
// RVA : 0x008AD6F0
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

const char *__fastcall idDeclRenderParm::DefaultDefinition(idDeclRenderParm *this)
{
  return "{ vec 0 }\n";
}


// ========================================================================
// ?Print@idAtlasResource@@UBAXXZ
// EA  : 0x828AD700
// RVA : 0x008AD700
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idAtlasResource::Print(idDecl *this)
{
  this->List(this);
}


// ========================================================================
// ??1idDeclRenderParm@@UAA@XZ
// EA  : 0x828AD728
// RVA : 0x008AD728
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idDeclRenderParm::~idDeclRenderParm(idDeclRenderParm *this)
{
  int parmIndex; // r11
  idParmState *v3; // r3

  this->__vftable = (idDeclRenderParm_vtbl *)&idDeclRenderParm::`vftable';
  parmIndex = this->parmIndex;
  if ( parmIndex >= 2047 )
    goto LABEL_6;
  v3 = renderThreadParmState;
  if ( (renderThreadParmState->parmStack.virtualParmBlockStackMask & renderThreadParmState->onParmBlockStack[parmIndex]) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v3 = renderThreadParmState;
  }
  if ( this->parmType == PT_STRING )
  {
    v3->values[this->parmIndex].swizzle[0] = 0;
LABEL_6:
    v3 = renderThreadParmState;
  }
  idParmState::FreeParmState(this: v3, parm: this);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$229413
// EA  : 0x828AD7CC
// RVA : 0x008AD7CC
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229413()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// ?ParseImageLine@idDeclRenderParm@@QBAPAVidImage@@AAVidParser@@@Z
// EA  : 0x828AD800
// RVA : 0x008AD800
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

idImage *__fastcall idDeclRenderParm::ParseImageLine(idDeclRenderParm *this, idParser *src)
{
  idImage *v2; // r30
  idImageOpts v4; // [sp+50h] [-180h] BYREF
  const char *v5; // [sp+A0h] [-130h]
  const char *v6; // [sp+A4h] [-12Ch]
  const char *v7; // [sp+A8h] [-128h]
  const char *v8; // [sp+ACh] [-124h]
  const char *v9; // [sp+B0h] [-120h]
  idToken v10; // [sp+C0h] [-110h] BYREF
  idStr v11[6]; // [sp+110h] [-C0h] BYREF

  v4.border.x = 0.0;
  v4.format = FMT_NONE;
  v4.border.y = 0.0;
  v4.colorFormat = CFM_DEFAULT;
  v4.border.z = 0.0;
  v4.filter = TF_DEFAULT;
  v4.border.w = 0.0;
  v4.repeat = TR_REPEAT;
  v4.lodBias = 0.0;
  v4.cubeFilter = false;
  v4.lodMinClamp = 0.0;
  v4.lodMaxClamp = 13.0;
  v4.aniso = 0.0;
  v10.floatvalue = -3.4028235e38;
  memset(&v4, 0, 20);
  v4.packedTail = true;
  v4.readback = false;
  v4.linear = false;
  v4.forceBias = false;
  v4.depthCompareMode = false;
  v4.overlayMemory = false;
  v4.startPurged = false;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  v6 = "clamp";
  v5 = "mipbias";
  v7 = "nearestMipNearest";
  v9 = "linearMipNearest";
  v8 = "linear";
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  while ( 1 )
                  {
                    while ( 1 )
                    {
                      while ( 1 )
                      {
                        while ( 1 )
                        {
                          while ( 1 )
                          {
                            while ( 1 )
                            {
                              while ( 1 )
                              {
                                while ( 1 )
                                {
                                  while ( 1 )
                                  {
                                    while ( 1 )
                                    {
                                      while ( 1 )
                                      {
                                        idParser::ReadTokenOnLine(this: src, token: &v10);
                                        if ( idStr::Icmp(s1: v10.data, s2: "nearest") != 0 )
                                          break;
                                        v4.filter = TF_NEAREST;
                                      }
                                      if ( idStr::Icmp(s1: v10.data, s2: v8) != 0 )
                                        break;
                                      v4.filter = TF_LINEAR;
                                    }
                                    if ( idStr::Icmp(s1: v10.data, s2: v9) != 0 )
                                      break;
                                    v4.filter = TF_LINEAR_MIPMAP_NEAREST;
                                  }
                                  if ( idStr::Icmp(s1: v10.data, s2: v7) != 0 )
                                    break;
                                  v4.filter = TF_NEAREST_MIPMAP_NEAREST;
                                }
                                if ( idStr::Icmp(s1: v10.data, s2: v5) != 0 )
                                  break;
                                idParser::ExpectTokenString(this: src, string: "(");
                                v4.lodBias = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                idParser::ExpectTokenString(this: src, string: ")");
                              }
                              if ( idStr::Icmp(s1: v10.data, s2: v6) != 0 )
                                break;
                              v4.repeat = TR_CLAMP;
                            }
                            if ( idStr::Icmp(s1: v10.data, s2: "borderClamp") != 0 )
                              break;
                            v4.repeat = TR_CLAMP_TO_BORDER;
                          }
                          if ( idStr::Icmp(s1: v10.data, s2: "mirror") != 0 )
                            break;
                          v4.repeat = TR_MIRROR;
                        }
                        if ( idStr::Icmp(s1: v10.data, s2: "clampS") != 0 )
                          break;
                        v4.repeat = TR_CLAMP_S;
                      }
                      if ( idStr::Icmp(s1: v10.data, s2: "clampT") != 0 )
                        break;
                      v4.repeat = TR_CLAMP_T;
                    }
                    if ( idStr::Icmp(s1: v10.data, s2: "uncompressed") != 0 )
                      break;
                    v4.format = FMT_RGBA8;
                  }
                  if ( idStr::Icmp(s1: v10.data, s2: "YCoCgDXT5") != 0 )
                    break;
                  v4.colorFormat = CFM_YCOCG_DXT5;
                  v4.format = FMT_DXT5;
                }
                if ( idStr::Icmp(s1: v10.data, s2: "hqcompress") != 0 )
                  break;
                v4.colorFormat = CFM_HQ_DXT5;
                v4.format = FMT_DXT5;
              }
              if ( idStr::Icmp(s1: v10.data, s2: "hqcompressNormal") != 0 )
                break;
              v4.colorFormat = CFM_HQ_NORMAL_DXT5;
              v4.format = FMT_DXT5;
            }
            if ( idStr::Icmp(s1: v10.data, s2: "LuminanceAlpha") != 0 )
              break;
            v4.format = FMT_L8A8;
          }
          if ( idStr::Icmp(s1: v10.data, s2: "Luminance") != 0 )
            break;
          v4.format = FMT_LUM8;
        }
        if ( idStr::Icmp(s1: v10.data, s2: "intensity") != 0 )
          break;
        v4.format = FMT_INT8;
      }
      if ( idStr::Icmp(s1: v10.data, s2: "alpha") != 0 )
        break;
      v4.format = FMT_ALPHA;
    }
    if ( idStr::Icmp(s1: v10.data, s2: "float") != 0 )
      break;
    v4.format = FMT_RGBA16F;
  }
  idParser::UnreadToken(this: src, token: &v10);
  R_ParsePastImageProgram(result: v11, src);
  v4.cubeFilter = this->cubeFilterTexture;
  v2 = idImageManager::ImageFromFile(this: globalImages, _name: v11[0].data, opts_p: &v4, makeDefault: true);
  idStr::FreeData(this: v11);
  idStr::FreeData(this: &v10);
  return v2;
}


// ========================================================================
// __unwind$229439
// EA  : 0x828ADC88
// RVA : 0x008ADC88
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229439()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 192));
}


// ========================================================================
// __unwind$229440
// EA  : 0x828ADCB0
// RVA : 0x008ADCB0
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229440()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 272));
}


// ========================================================================
// ?ParseVectorConstant@idDeclRenderParm@@SA_NAAVidParser@@QAM@Z
// EA  : 0x828ADCE0
// RVA : 0x008ADCE0
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

int __fastcall idDeclRenderParm::ParseVectorConstant(idParser *src, float *vec)
{
  int v2; // r30
  float *v5; // r27
  double v6; // fp0
  double v8; // fp1
  double FloatValue; // fp1
  idToken v10[2]; // [sp+50h] [-90h] BYREF

  v2 = 0;
  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].floatvalue = -3.4028235e38;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  v10[0].intvalue = 0;
  v10[0].whiteSpaceStart_p = nullptr;
  v10[0].whiteSpaceEnd_p = nullptr;
  v10[0].next = nullptr;
  idParser::ReadToken(this: src, token: v10);
  if ( idStr::Cmp(s1: v10[0].data, s2: "{") != 0 )
  {
    if ( idStr::Cmp(s1: v10[0].data, s2: "-") != 0 )
    {
      if ( v10[0].type == 3 )
      {
        FloatValue = idToken::GetFloatValue(this: v10);
        vec[3] = FloatValue;
        vec[2] = FloatValue;
        vec[1] = FloatValue;
        *vec = FloatValue;
        idStr::FreeData(this: &v10[0]);
        return 1;
      }
      vec[3] = 0.0;
      vec[2] = 0.0;
      vec[1] = 0.0;
      *vec = 0.0;
      idParser::Warning(this: src, str: "Non numeric constant\n");
    }
    else
    {
      idParser::ReadToken(this: src, token: v10);
      if ( v10[0].type == 3 )
      {
        v8 = idToken::GetFloatValue(this: v10);
        vec[3] = -v8;
        vec[2] = -v8;
        vec[1] = -v8;
        *vec = -v8;
        idStr::FreeData(this: &v10[0]);
        return 1;
      }
      idParser::Warning(this: src, str: "Bad negative number '%s'\n", v10[0].data);
    }
LABEL_32:
    idStr::FreeData(this: &v10[0]);
    return 0;
  }
  else
  {
    v5 = vec;
    *vec = 0.0;
    vec[3] = 0.0;
    vec[2] = 0.0;
    vec[1] = 0.0;
    do
    {
      idParser::ReadToken(this: src, token: v10);
      if ( idStr::Cmp(s1: v10[0].data, s2: "-") != 0 )
      {
        if ( v10[0].type != 3 )
        {
          idParser::Warning(this: src, str: "Non numeric term in vector constant");
          goto LABEL_32;
        }
        if ( (v10[0].subtype & 0x10000) == 0 )
          idToken::NumberValue(this: v10);
        *v5 = v10[0].floatvalue;
      }
      else
      {
        idParser::ReadToken(this: src, token: v10);
        if ( v10[0].type != 3 )
        {
          idParser::Warning(this: src, str: "Bad negative number '%s'", v10[0].data);
          goto LABEL_32;
        }
        if ( (v10[0].subtype & 0x10000) == 0 )
          idToken::NumberValue(this: v10);
        *v5 = -v10[0].floatvalue;
      }
      ++v2;
      ++v5;
      idParser::ReadToken(this: src, token: v10);
      if ( idStr::Cmp(s1: v10[0].data, s2: "}") == 0 )
        break;
      if ( v2 == 4 )
      {
        idParser::Warning(this: src, str: "Over four elements in a vector constant\n");
        goto LABEL_32;
      }
      if ( idStr::Cmp(s1: v10[0].data, s2: ",") != 0 )
      {
        idParser::Warning(this: src, str: "Missing comma in vector constant\n");
        goto LABEL_32;
      }
    }
    while ( v2 < 4 );
    if ( v2 == 0 )
    {
      idParser::Warning(this: src, str: "Vector constant with no elements\n");
      goto LABEL_32;
    }
    if ( v2 == 1 )
    {
      v6 = *vec;
      vec[3] = *vec;
      vec[2] = v6;
      vec[1] = v6;
    }
    idStr::FreeData(this: &v10[0]);
    return 1;
  }
}


// ========================================================================
// __unwind$229662
// EA  : 0x828ADFD8
// RVA : 0x008ADFD8
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229662()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?List@idDeclRenderParm@@UBAXXZ
// EA  : 0x828AE000
// RVA : 0x008AE000
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idDeclRenderParm::List(idDeclRenderParm *this)
{
  parmValue_t *p_declaredValue; // r15
  parmValue_t *v3; // r25
  int i; // r14
  float v5; // r3
  parmValue_t *v6; // r10
  parmValue_t *v7; // r11
  int v8; // r7
  int v9; // r9

  p_declaredValue = &this->declaredValue;
  idLib::Printf(fmt: "%s ", this->name.str);
  v3 = &renderThreadParmState->values[this->parmIndex];
  for ( i = 0; i < 2; ++i )
  {
    switch ( this->parmType )
    {
      case PT_VECTOR:
        idLib::Printf(
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v3->value[0])),
          (unsigned int)COERCE_UNSIGNED_INT64(v3->value[0]),
          (unsigned int)COERCE_UNSIGNED_INT64(v3->value[1]),
          (unsigned int)COERCE_UNSIGNED_INT64(v3->value[2]),
          (unsigned int)COERCE_UNSIGNED_INT64(v3->value[3]));
        break;
      case PT_TEXTURE:
      case PT_TEXTURE_2D:
        idLib::Printf(fmt: "Tex2D ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_3D:
        idLib::Printf(fmt: "Tex3D ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_CUBE:
        idLib::Printf(fmt: "TexCube ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_SHADOW_2D:
        idLib::Printf(fmt: "TexShadow2D ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_SHADOW_3D:
        idLib::Printf(fmt: "TexShadow3D ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_SHADOW_CUBE:
        idLib::Printf(fmt: "TexShadowCube ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] == 0 )
          goto LABEL_17;
        goto LABEL_5;
      case PT_TEXTURE_MULTISAMPLE_2D:
        idLib::Printf(fmt: "TexMultisample2D ");
        v5 = v3->value[0];
        if ( v3->swizzle[0] != 0 )
LABEL_5:
          (*(void (__fastcall **)(double))(*(_DWORD *)LODWORD(v5) + 20))(a1: COERCE_DOUBLE(LODWORD(v5)));
        else
LABEL_17:
          idLib::Printf(fmt: "WARNING: NULL\n");
        break;
      case PT_PROGRAM:
        if ( v3->swizzle[0] != 0 )
          idLib::Printf(fmt: "Program %s\n", *(const char **)(v3->swizzle[0] + 8));
        else
          idLib::Printf(fmt: "Program WARNING: NULL\n");
        break;
      case PT_STRING:
        if ( v3->swizzle[0] != 0 )
          idLib::Printf(fmt: "String \"%s\"\n", v3->string);
        else
          idLib::Printf(fmt: "String WARNING: NULL\n");
        break;
      default:
        idLib::Printf(fmt: "BAD TYPE!\n");
        break;
    }
    v6 = p_declaredValue;
    v7 = v3;
    do
    {
      v8 = HIBYTE(v6->value[0]);
      v9 = HIBYTE(v7->value[0]) - v8;
      if ( HIBYTE(v7->value[0]) != v8 )
        break;
      v7 = (parmValue_t *)((char *)v7 + 1);
      v6 = (parmValue_t *)((char *)v6 + 1);
    }
    while ( v7 != &v3[1] );
    if ( v9 == 0 )
      break;
    v3 = p_declaredValue;
    idLib::Printf(fmt: "  Declared:\n");
  }
}


// ========================================================================
// ?ParseValue@idDeclRenderParm@@ABAXAAVidParser@@PATparmValue_t@@@Z
// EA  : 0x828AE330
// RVA : 0x008AE330
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idDeclRenderParm::ParseValue(idDeclRenderParm *this, idParser *src, parmValue_t *value)
{
  char *data; // r11
  const char *v6; // r10
  int v7; // r9
  int v8; // r9
  bool v9; // zf
  idAtomicString v10; // [sp+50h] [-B0h] BYREF
  idStr v11; // [sp+60h] [-A0h] BYREF
  idToken v12; // [sp+80h] [-80h] BYREF

  v12.len = 0;
  v12.allocedAndFlag = 20;
  v12.floatvalue = -3.4028235e38;
  v12.data = v12.baseBuffer;
  v12.baseBuffer[0] = 0;
  v12.intvalue = 0;
  memset(&v12.whiteSpaceStart_p, 0, 12);
  switch ( this->parmType )
  {
    case PT_VECTOR:
      idDeclRenderParm::ParseVectorConstant(src, vec: value->value);
      break;
    case PT_TEXTURE:
    case PT_TEXTURE_2D:
    case PT_TEXTURE_3D:
    case PT_TEXTURE_CUBE:
    case PT_TEXTURE_SHADOW_2D:
    case PT_TEXTURE_SHADOW_3D:
    case PT_TEXTURE_SHADOW_CUBE:
    case PT_TEXTURE_MULTISAMPLE_2D:
      value->swizzle[0] = (int)idDeclRenderParm::ParseImageLine(this, src);
      break;
    case PT_PROGRAM:
      if ( idParser::ExpectAnyToken(this: src, token: &v12) != 0 )
      {
        if ( idStr::Icmp(s1: v12.data, s2: "0") != 0 )
        {
          if ( v12.data != nullptr )
            value->swizzle[0] = (int)idDeclInfo::FindWithInheritance(
                                       this: &idDeclRenderProg::resourceList,
                                       name: v12.data,
                                       makeDefault: true);
          else
            value->swizzle[0] = 0;
        }
        else
        {
          value->swizzle[0] = 0;
        }
      }
      else
      {
        value->swizzle[0] = 0;
      }
      break;
    case PT_STRING:
      idStr::idStr(this: &v11, text: &byte_8200D768);
      if ( idParser::ExpectAnyToken(this: src, token: &v12) != 0 )
      {
        while ( 1 )
        {
          data = v12.data;
          v6 = "}";
          do
          {
            v7 = (unsigned __int8)*data;
            v9 = v7 == 0;
            v8 = v7 - *(unsigned __int8 *)v6;
            if ( v9 )
              break;
            ++data;
            ++v6;
          }
          while ( v8 == 0 );
          if ( v8 == 0 )
            break;
          if ( v11.len > 0 )
            idStr::Append(this: &v11, text: " ");
          idStr::Append(this: &v11, text: v12.data);
          if ( idParser::ExpectAnyToken(this: src, token: &v12) == 0 )
            goto LABEL_21;
        }
        idParser::UnreadToken(this: src, token: &v12);
      }
LABEL_21:
      idAtomicString::Set(this: &v10, str_: v11.data);
      LODWORD(value->value[0]) = (idAtomicString)v10.str;
      idStr::FreeData(this: &v11);
      break;
    default:
      idParser::Warning(this: src, str: "Bad renderParm type: %s\n", v12.baseBuffer);
      break;
  }
  idStr::FreeData(this: &v12);
}


// ========================================================================
// __unwind$229971
// EA  : 0x828AE550
// RVA : 0x008AE550
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229971()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$229972
// EA  : 0x828AE578
// RVA : 0x008AE578
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_229972()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?ParseStringToValue@idDeclRenderParm@@QBAXPBDPATparmValue_t@@@Z
// EA  : 0x828AE5A8
// RVA : 0x008AE5A8
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idDeclRenderParm::ParseStringToValue(idDeclRenderParm *this, const char *str, parmValue_t *value)
{
  int v6; // r5
  idParser v7; // [sp+50h] [-2C0h] BYREF

  idParser::idParser(this: &v7, flags: 156216);
  v6 = 0;
  if ( *str != 0 )
  {
    do
      ++v6;
    while ( str[v6] != 0 );
  }
  idParser::LoadMemory(this: &v7, ptr: str, length: v6, name: "value string");
  idDeclRenderParm::ParseValue(this, src: &v7, value);
  idParser::~idParser(this: &v7);
}


// ========================================================================
// __unwind$230126_0
// EA  : 0x828AE628
// RVA : 0x008AE628
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_230126_0()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 784 + 80));
}


// ========================================================================
// ?Parse@idDeclRenderParm@@UAAXAAVidParser@@@Z
// EA  : 0x828AE658
// RVA : 0x008AE658
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void __fastcall idDeclRenderParm::Parse(idDeclRenderParm *this, idParser *src)
{
  parmType_t v4; // r11
  parmValue_t *v5; // r9
  idToken v6[2]; // [sp+50h] [-90h] BYREF

  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].floatvalue = -3.4028235e38;
  v6[0].data = v6[0].baseBuffer;
  v6[0].baseBuffer[0] = 0;
  v6[0].intvalue = 0;
  v6[0].whiteSpaceStart_p = nullptr;
  v6[0].whiteSpaceEnd_p = nullptr;
  v6[0].next = nullptr;
  if ( idParser::ExpectAnyToken(this: src, token: v6) == 0 )
    goto LABEL_42;
  if ( idStr::Icmp(s1: v6[0].data, s2: "environment") == 0 )
  {
    v4 = PT_TEXTURE_CUBE;
    this->cubeFilterTexture = true;
LABEL_26:
    this->parmType = v4;
    goto LABEL_27;
  }
  if ( idStr::Icmp(s1: v6[0].data, s2: "Tex") != 0 )
  {
    if ( idStr::Icmp(s1: v6[0].data, s2: "Tex2D") != 0 )
    {
      if ( idStr::Icmp(s1: v6[0].data, s2: "Tex3D") != 0 )
      {
        if ( idStr::Icmp(s1: v6[0].data, s2: "TexCube") == 0 )
        {
          v4 = PT_TEXTURE_CUBE;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "TexShadow2D") == 0 )
        {
          v4 = PT_TEXTURE_SHADOW_2D;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "TexShadow3D") == 0 )
        {
          v4 = PT_TEXTURE_SHADOW_3D;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "TexShadowCube") == 0 )
        {
          v4 = PT_TEXTURE_SHADOW_CUBE;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "TexMultisample2D") == 0 )
        {
          v4 = PT_TEXTURE_MULTISAMPLE_2D;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "Program") == 0 )
        {
          v4 = PT_PROGRAM;
          goto LABEL_26;
        }
        if ( idStr::Icmp(s1: v6[0].data, s2: "Vec") != 0 )
        {
          if ( idStr::Icmp(s1: v6[0].data, s2: "String") != 0 )
          {
            idParser::Warning(this: src, str: "Bad renderParm type: %s\n", v6[0].data);
            goto LABEL_42;
          }
          v4 = PT_STRING;
          goto LABEL_26;
        }
        this->parmType = PT_VECTOR;
      }
      else
      {
        this->parmType = PT_TEXTURE_3D;
      }
    }
    else
    {
      this->parmType = PT_TEXTURE_2D;
    }
  }
  else
  {
    this->parmType = PT_TEXTURE;
  }
LABEL_27:
  if ( this->parmIndex >= 2047 )
    this->parmIndex = idParmState::AllocParmState(this: renderThreadParmState, parm: this);
  idDeclRenderParm::ParseValue(this, src, value: &this->declaredValue);
  v5 = &renderThreadParmState->values[this->parmIndex];
  v5->swizzle[0] = this->declaredValue.swizzle[0];
  v5->swizzle[1] = this->declaredValue.swizzle[1];
  v5->swizzle[2] = this->declaredValue.swizzle[2];
  v5->swizzle[3] = this->declaredValue.swizzle[3];
  if ( idParser::ExpectAnyToken(this: src, token: v6) != 0 && idStr::Cmp(s1: v6[0].data, s2: "}") != 0 )
  {
    if ( idStr::Icmp(s1: v6[0].data, s2: "Bool") != 0 )
    {
      if ( idStr::Icmp(s1: v6[0].data, s2: "Color") != 0 )
      {
        if ( idStr::Icmp(s1: v6[0].data, s2: "Range") != 0 )
        {
          idParser::Warning(this: src, str: "Unknown edit specifier '%s'\n", v6[0].data);
        }
        else
        {
          this->edit = PE_RANGE;
          this->editRange[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
          idParser::ExpectTokenString(this: src, string: ",");
          this->editRange[1] = idParser::ParseFloat(this: src, errorFlag: nullptr);
          idParser::ExpectTokenString(this: src, string: "}");
        }
      }
      else
      {
        this->edit = PE_COLOR;
        if ( idParser::ExpectAnyToken(this: src, token: v6) != 0 )
        {
          if ( idStr::Cmp(s1: v6[0].data, s2: "}") != 0 )
          {
            idParser::UnreadToken(this: src, token: v6);
            this->editRange[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
            idParser::ExpectTokenString(this: src, string: ",");
            this->editRange[1] = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
          else
          {
            this->editRange[0] = 0.0;
            this->editRange[1] = 1.0;
          }
        }
      }
    }
    else
    {
      this->edit = PE_BOOL;
      idParser::ExpectTokenString(this: src, string: "}");
    }
  }
LABEL_42:
  idStr::FreeData(this: &v6[0]);
}


// ========================================================================
// __unwind$230155
// EA  : 0x828AEA54
// RVA : 0x008AEA54
// PDB : w:\tech5\engine\renderer\declrenderparm.cpp
// ========================================================================

void _unwind_230155()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}

