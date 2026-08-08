
// ========================================================================
// ?ParseVectorConstant@idCodeRenderParm@@ABA_NAAVidParser@@QAM@Z
// EA  : 0x828A8648
// RVA : 0x008A8648
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

int __fastcall idCodeRenderParm::ParseVectorConstant(idCodeRenderParm *this, idParser *src, float *vec)
{
  int v3; // r30
  float *v6; // r27
  double v7; // fp0
  double v9; // fp1
  double FloatValue; // fp1
  idToken v11[2]; // [sp+50h] [-90h] BYREF

  v3 = 0;
  v11[0].len = 0;
  v11[0].allocedAndFlag = 20;
  v11[0].floatvalue = -3.4028235e38;
  v11[0].data = v11[0].baseBuffer;
  v11[0].baseBuffer[0] = 0;
  v11[0].intvalue = 0;
  v11[0].whiteSpaceStart_p = nullptr;
  v11[0].whiteSpaceEnd_p = nullptr;
  v11[0].next = nullptr;
  idParser::ReadToken(this: src, token: v11);
  if ( idStr::Cmp(s1: v11[0].data, s2: "{") != 0 )
  {
    if ( idStr::Cmp(s1: v11[0].data, s2: "-") != 0 )
    {
      if ( v11[0].type == 3 )
      {
        FloatValue = idToken::GetFloatValue(this: v11);
        vec[3] = FloatValue;
        vec[2] = FloatValue;
        vec[1] = FloatValue;
        *vec = FloatValue;
        idStr::FreeData(this: &v11[0]);
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
      idParser::ReadToken(this: src, token: v11);
      if ( v11[0].type == 3 )
      {
        v9 = idToken::GetFloatValue(this: v11);
        vec[3] = -v9;
        vec[2] = -v9;
        vec[1] = -v9;
        *vec = -v9;
        idStr::FreeData(this: &v11[0]);
        return 1;
      }
      idParser::Warning(this: src, str: "Bad negative number '%s'\n", v11[0].data);
    }
LABEL_32:
    idStr::FreeData(this: &v11[0]);
    return 0;
  }
  else
  {
    v6 = vec;
    *vec = 0.0;
    vec[3] = 0.0;
    vec[2] = 0.0;
    vec[1] = 0.0;
    do
    {
      idParser::ReadToken(this: src, token: v11);
      if ( idStr::Cmp(s1: v11[0].data, s2: "-") != 0 )
      {
        if ( v11[0].type != 3 )
        {
          idParser::Warning(this: src, str: "Non numeric term in vector constant");
          goto LABEL_32;
        }
        if ( (v11[0].subtype & 0x10000) == 0 )
          idToken::NumberValue(this: v11);
        *v6 = v11[0].floatvalue;
      }
      else
      {
        idParser::ReadToken(this: src, token: v11);
        if ( v11[0].type != 3 )
        {
          idParser::Warning(this: src, str: "Bad negative number '%s'", v11[0].data);
          goto LABEL_32;
        }
        if ( (v11[0].subtype & 0x10000) == 0 )
          idToken::NumberValue(this: v11);
        *v6 = -v11[0].floatvalue;
      }
      ++v3;
      ++v6;
      idParser::ReadToken(this: src, token: v11);
      if ( idStr::Cmp(s1: v11[0].data, s2: "}") == 0 )
        break;
      if ( v3 == 4 )
      {
        idParser::Warning(this: src, str: "Over four elements in a vector constant\n");
        goto LABEL_32;
      }
      if ( idStr::Cmp(s1: v11[0].data, s2: ",") != 0 )
      {
        idParser::Warning(this: src, str: "Missing comma in vector constant\n");
        goto LABEL_32;
      }
    }
    while ( v3 < 4 );
    if ( v3 == 0 )
    {
      idParser::Warning(this: src, str: "Vector constant with no elements\n");
      goto LABEL_32;
    }
    if ( v3 == 1 )
    {
      v7 = *vec;
      vec[3] = *vec;
      vec[2] = v7;
      vec[1] = v7;
    }
    idStr::FreeData(this: &v11[0]);
    return 1;
  }
}


// ========================================================================
// __unwind$235469
// EA  : 0x828A8944
// RVA : 0x008A8944
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_235469()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?RenderParmForName@idCodeRenderParm@@SAPAV1@PBD@Z
// EA  : 0x828A8978
// RVA : 0x008A8978
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idCodeRenderParm *__fastcall idCodeRenderParm::RenderParmForName(const char *name)
{
  char *data; // r9
  int v2; // r11
  unsigned __int8 i; // r8
  int v4; // r11
  int v5; // r9
  idCodeRenderParm *v6; // r30
  const char *str; // r9
  idAtomicString v9; // [sp+50h] [-50h] BYREF
  idCodeRenderParm *v10; // [sp+54h] [-4Ch]
  idStr v11; // [sp+60h] [-40h] BYREF

  idStr::idStr(this: &v11, text: name);
  idStr::MakeNameCanonical(this: &v11);
  idAtomicString::Set(this: &v9, str_: v11.data);
  data = v11.data;
  v2 = 0;
  for ( i = *v11.data; *data != 0; i = *data )
  {
    ++data;
    v2 = 31 * v2 + i;
  }
  v4 = codeRenderParmHashIndex.hash[codeRenderParmHashIndex.lookupMask & codeRenderParmHashIndex.hashMask & v2];
  if ( v4 == -1 )
  {
LABEL_7:
    idStr::FreeData(this: &v11);
    return nullptr;
  }
  else
  {
    v5 = v4;
    while ( 1 )
    {
      v6 = codeRenderParmList.list[v5];
      str = v6->name.str;
      v10 = v6;
      if ( str == v9.str )
        break;
      v4 = codeRenderParmHashIndex.indexChain[codeRenderParmHashIndex.lookupMask & v4];
      v5 = v4;
      if ( v4 == -1 )
        goto LABEL_7;
    }
    v10 = v6;
    idStr::FreeData(this: &v11);
    return v6;
  }
}


// ========================================================================
// __unwind$235870_0
// EA  : 0x828A8A8C
// RVA : 0x008A8A8C
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_235870_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?matchRenderParms_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A8AB8
// RVA : 0x008A8AB8
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __fastcall matchRenderParms_f(const idCmdArgs *args)
{
  idDeclInfo *v1; // r28
  int v2; // r26
  int v3; // r29
  const char **p_str; // r30
  const idDecl *v5; // r31
  idCodeRenderParm *v6; // r3
  idResourceList **p_resourceListPtr; // r11
  parmValue_t *p_declaredValue; // r10
  int v9; // r7
  int v10; // r9

  v1 = rp->addProgram->GetDeclInfo(this: rp->addProgram);
  v2 = 0;
  if ( v1->declSources.num > 0 )
  {
    v3 = 0;
    do
    {
      p_str = &v1->declSources.list[v3]->name.str;
      if ( *p_str != nullptr
        && (v5 = idDeclInfo::FindWithInheritance(
                   this: &idDeclRenderParm::resourceList,
                   name: *p_str,
                   makeDefault: false)) != nullptr )
      {
        v6 = idCodeRenderParm::RenderParmForName(name: *p_str);
        if ( v6 != nullptr )
        {
          p_resourceListPtr = &v5[1].resourceListPtr;
          p_declaredValue = &v6->declaredValue;
          do
          {
            v9 = HIBYTE(p_declaredValue->value[0]);
            v10 = *(unsigned __int8 *)p_resourceListPtr - v9;
            if ( *(unsigned __int8 *)p_resourceListPtr != v9 )
              break;
            p_resourceListPtr = (idResourceList **)((char *)p_resourceListPtr + 1);
            p_declaredValue = (parmValue_t *)((char *)p_declaredValue + 1);
          }
          while ( p_resourceListPtr != (idResourceList **)((char *)&v5[1].idResource + 32) );
          if ( v10 != 0 )
            idLib::Printf(fmt: "%s didn't match\n", *p_str);
        }
        else
        {
          idLib::Printf(fmt: "code renderparm %s not found\n", *p_str);
        }
      }
      else
      {
        idLib::Printf(fmt: "decl renderparm %s not found\n", *p_str);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->declSources.num );
  }
}


// ========================================================================
// ?emitCodeRenderParms_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A8BC8
// RVA : 0x008A8BC8
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __fastcall emitCodeRenderParms_f(const idCmdArgs *args)
{
  idDeclInfo *v1; // r19
  char *v2; // r16
  int v3; // r17
  int v4; // r18
  idDeclSource *v5; // r30
  idDecl *v6; // r29
  char *FileName; // r3
  const char *v8; // r3
  idStr v9[5]; // [sp+50h] [-B0h] BYREF

  v1 = rp->addProgram->GetDeclInfo(this: rp->addProgram);
  idLib::Printf(fmt: "// -----------------------\n");
  v2 = nullptr;
  v3 = 0;
  if ( v1->declSources.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = v1->declSources.list[v4];
      if ( v5->name.str != nullptr
        && (v6 = (idDecl *)idDeclInfo::FindWithInheritance(
                             this: &idDeclRenderParm::resourceList,
                             name: v5->name.str,
                             makeDefault: false)) != nullptr )
      {
        if ( idCodeRenderParm::RenderParmForName(name: v5->name.str) == nullptr )
        {
          if ( idDeclSource::GetFileName(this: v5) != v2 )
          {
            FileName = idDeclSource::GetFileName(this: v5);
            idLib::Printf(fmt: "\n// %s\n", FileName);
            v2 = idDeclSource::GetFileName(this: v5);
          }
          v8 = (const char *)idLobby::PeerIndexOnHost(this: (LEAPCORE::CXboxRendererConnection *)v6);
          idStr::idStr(this: v9, text: v8);
          idStr::StripLeading(this: v9, string: "{");
          idStr::StripLeading(this: v9, string: " ");
          idStr::StripTrailing(this: v9, string: "}");
          idStr::StripTrailing(this: v9, string: " ");
          idStr::Replace(this: v9, old: "\"", nw: "\\\"");
          idLib::Printf(fmt: "RP( %s\t,\"%s\" );\n", v6->name.str, v9[0].data);
          idStr::FreeData(this: v9);
        }
      }
      else
      {
        idLib::Printf(fmt: "decl renderparm %s not found\n", v5->name.str);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < v1->declSources.num );
  }
  idLib::Printf(fmt: "// -----------------------\n");
}


// ========================================================================
// __unwind$236058
// EA  : 0x828A8D74
// RVA : 0x008A8D74
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236058()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// ?ParseImageDef@@YA?AVidImageDef@@AAVidParser@@@Z
// EA  : 0x828A8DA8
// RVA : 0x008A8DA8
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idImageDef *__fastcall ParseImageDef(idImageDef *result, idParser *src)
{
  idStr *v3; // r29
  size_t len; // r30
  idStr v6; // [sp+60h] [-110h] BYREF
  idToken v7; // [sp+80h] [-F0h] BYREF

  idImageDef::idImageDef(this: result);
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
                                  v7.floatvalue = -3.4028235e38;
                                  v7.len = 0;
                                  v7.data = v7.baseBuffer;
                                  v7.allocedAndFlag = 20;
                                  v7.baseBuffer[0] = 0;
                                  v7.intvalue = 0;
                                  memset(&v7.whiteSpaceStart_p, 0, 12);
                                  idParser::ReadTokenOnLine(this: src, token: &v7);
                                  if ( idStr::Icmp(s1: v7.data, s2: "nearest") != 0 )
                                    break;
                                  result->opts.filter = TF_NEAREST;
                                  idStr::FreeData(this: &v7);
                                }
                                if ( idStr::Icmp(s1: v7.data, s2: "linear") != 0 )
                                  break;
                                result->opts.filter = TF_LINEAR;
                                idStr::FreeData(this: &v7);
                              }
                              if ( idStr::Icmp(s1: v7.data, s2: "clamp") != 0 )
                                break;
                              result->opts.repeat = TR_CLAMP;
                              idStr::FreeData(this: &v7);
                            }
                            if ( idStr::Icmp(s1: v7.data, s2: "borderClamp") != 0 )
                              break;
                            result->opts.repeat = TR_CLAMP_TO_BORDER;
                            idStr::FreeData(this: &v7);
                          }
                          if ( idStr::Icmp(s1: v7.data, s2: "mirror") != 0 )
                            break;
                          result->opts.repeat = TR_MIRROR;
                          idStr::FreeData(this: &v7);
                        }
                        if ( idStr::Icmp(s1: v7.data, s2: "clampS") != 0 )
                          break;
                        result->opts.repeat = TR_CLAMP_S;
                        idStr::FreeData(this: &v7);
                      }
                      if ( idStr::Icmp(s1: v7.data, s2: "clampT") != 0 )
                        break;
                      result->opts.repeat = TR_CLAMP_T;
                      idStr::FreeData(this: &v7);
                    }
                    if ( idStr::Icmp(s1: v7.data, s2: "uncompressed") != 0 )
                      break;
                    result->opts.format = FMT_RGBA8;
                    idStr::FreeData(this: &v7);
                  }
                  if ( idStr::Icmp(s1: v7.data, s2: "YCoCgDXT5") != 0 )
                    break;
                  result->opts.colorFormat = CFM_YCOCG_DXT5;
                  result->opts.format = FMT_DXT5;
                  idStr::FreeData(this: &v7);
                }
                if ( idStr::Icmp(s1: v7.data, s2: "hqcompress") != 0 )
                  break;
                result->opts.colorFormat = CFM_HQ_DXT5;
                result->opts.format = FMT_DXT5;
                idStr::FreeData(this: &v7);
              }
              if ( idStr::Icmp(s1: v7.data, s2: "hqcompressNormal") != 0 )
                break;
              result->opts.colorFormat = CFM_HQ_NORMAL_DXT5;
              result->opts.format = FMT_DXT5;
              idStr::FreeData(this: &v7);
            }
            if ( idStr::Icmp(s1: v7.data, s2: "LuminanceAlpha") != 0 )
              break;
            result->opts.format = FMT_L8A8;
            idStr::FreeData(this: &v7);
          }
          if ( idStr::Icmp(s1: v7.data, s2: "Luminance") != 0 )
            break;
          result->opts.format = FMT_LUM8;
          idStr::FreeData(this: &v7);
        }
        if ( idStr::Icmp(s1: v7.data, s2: "intensity") != 0 )
          break;
        result->opts.format = FMT_INT8;
        idStr::FreeData(this: &v7);
      }
      if ( idStr::Icmp(s1: v7.data, s2: "alpha") != 0 )
        break;
      result->opts.format = FMT_ALPHA;
      idStr::FreeData(this: &v7);
    }
    if ( idStr::Icmp(s1: v7.data, s2: "float") != 0 )
      break;
    result->opts.format = FMT_RGBA16F;
    idStr::FreeData(this: &v7);
  }
  idParser::UnreadToken(this: src, token: &v7);
  idStr::FreeData(this: &v7);
  v3 = R_ParsePastImageProgram(result: &v6, src);
  len = v3->len;
  idStr::EnsureAlloced(this: &result->imageProgram, amount: v3->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->imageProgram.data, Src: v3->data, Size: len);
  result->imageProgram.data[len] = 0;
  result->imageProgram.len = len;
  idStr::FreeData(this: &v6);
  return result;
}


// ========================================================================
// __unwind$236173
// EA  : 0x828A91B0
// RVA : 0x008A91B0
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236173()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 368;
  if ( (*(_DWORD *)(v0 - 368 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idImageDef::~idImageDef(this: *(idImageDef **)(v1 + 388));
  }
}


// ========================================================================
// __unwind$236176
// EA  : 0x828A91F4
// RVA : 0x008A91F4
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236176()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$236177
// EA  : 0x828A921C
// RVA : 0x008A921C
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236177()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// ?ParseImageLine@idCodeRenderParm@@ABAPAVidImage@@AAVidParser@@@Z
// EA  : 0x828A9250
// RVA : 0x008A9250
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idImage *__fastcall idCodeRenderParm::ParseImageLine(idCodeRenderParm *this, idParser *src)
{
  idImage *v4; // r30
  idImageDef v5; // [sp+50h] [-90h] BYREF

  ParseImageDef(result: &v5, src);
  if ( resolveRenderParmResourcesHasBeenCalled )
  {
    v5.opts.cubeFilter = this->cubeFilterTexture;
    v4 = idImageManager::ImageFromFile(
           this: globalImages,
           _name: v5.imageProgram.data,
           opts_p: &v5.opts,
           makeDefault: true);
    idStr::FreeData(this: &v5.imageProgram);
    return v4;
  }
  else
  {
    idStr::FreeData(this: &v5.imageProgram);
    return nullptr;
  }
}


// ========================================================================
// __unwind$236504
// EA  : 0x828A92DC
// RVA : 0x008A92DC
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236504()
{
  int v0; // r12

  idImageDef::~idImageDef(this: (idImageDef *)(v0 - 224 + 80));
}


// ========================================================================
// ?ParseValue@idCodeRenderParm@@ABAXAAVidParser@@PATparmValue_t@@@Z
// EA  : 0x828A9310
// RVA : 0x008A9310
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __fastcall idCodeRenderParm::ParseValue(idCodeRenderParm *this, idParser *src, parmValue_t *value)
{
  idAtomicString v5; // [sp+50h] [-A0h] BYREF
  idStr v6; // [sp+60h] [-90h] BYREF
  idToken v7; // [sp+80h] [-70h] BYREF

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.floatvalue = -3.4028235e38;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  switch ( this->parmType )
  {
    case PT_VECTOR:
      idCodeRenderParm::ParseVectorConstant(this, src, vec: value->value);
      break;
    case PT_TEXTURE:
    case PT_TEXTURE_2D:
    case PT_TEXTURE_3D:
    case PT_TEXTURE_CUBE:
    case PT_TEXTURE_SHADOW_2D:
    case PT_TEXTURE_SHADOW_3D:
    case PT_TEXTURE_SHADOW_CUBE:
    case PT_TEXTURE_MULTISAMPLE_2D:
      value->swizzle[0] = (int)idCodeRenderParm::ParseImageLine(this, src);
      break;
    case PT_PROGRAM:
      if ( idParser::ExpectAnyToken(this: src, token: &v7) != 0 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "0") != 0 )
        {
          if ( resolveRenderParmResourcesHasBeenCalled )
          {
            if ( v7.data != nullptr )
              value->swizzle[0] = (int)idDeclInfo::FindWithInheritance(
                                         this: &idDeclRenderProg::resourceList,
                                         name: v7.data,
                                         makeDefault: true);
            else
              value->swizzle[0] = 0;
          }
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
      idStr::idStr(this: &v6, text: &byte_8200D768);
      while ( idParser::ReadToken(this: src, token: &v7) )
      {
        if ( v6.len > 0 )
          idStr::Append(this: &v6, text: " ");
        idStr::Append(this: &v6, text: v7.data);
      }
      idAtomicString::Set(this: &v5, str_: v6.data);
      LODWORD(value->value[0]) = (idAtomicString)v5.str;
      idStr::FreeData(this: &v6);
      break;
    default:
      idParser::Warning(this: src, str: "Bad renderParm type: %s\n", v7.baseBuffer);
      break;
  }
  idStr::FreeData(this: &v7);
}


// ========================================================================
// __unwind$236548
// EA  : 0x828A94FC
// RVA : 0x008A94FC
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236548()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$236549
// EA  : 0x828A9524
// RVA : 0x008A9524
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236549()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?ParseInitializer@idCodeRenderParm@@AAAXXZ
// EA  : 0x828A9558
// RVA : 0x008A9558
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __fastcall idCodeRenderParm::ParseInitializer(idCodeRenderParm *this)
{
  const char *initString; // r11
  int v3; // r10
  parmType_t v4; // r11
  idToken v5; // [sp+50h] [-320h] BYREF
  idParser v6; // [sp+A0h] [-2D0h] BYREF

  idParser::idParser(this: &v6, flags: 0);
  idParser::SetFlags(this: &v6, flags: 156216);
  initString = this->initString;
  do
    v3 = *(unsigned __int8 *)initString++;
  while ( v3 != 0 );
  idParser::LoadMemory(
    this: &v6,
    ptr: this->initString,
    length: initString - this->initString - 1,
    name: this->name.str);
  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.floatvalue = -3.4028235e38;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  idParser::ExpectAnyToken(this: &v6, token: &v5);
  if ( idStr::Icmp(s1: v5.data, s2: "environment") != 0 )
  {
    if ( idStr::Icmp(s1: v5.data, s2: "Tex") == 0 )
    {
      this->parmType = PT_TEXTURE;
      goto LABEL_28;
    }
    if ( idStr::Icmp(s1: v5.data, s2: "Tex2D") == 0 )
    {
      this->parmType = PT_TEXTURE_2D;
      goto LABEL_28;
    }
    if ( idStr::Icmp(s1: v5.data, s2: "Tex3D") == 0 )
    {
      this->parmType = PT_TEXTURE_3D;
      goto LABEL_28;
    }
    if ( idStr::Icmp(s1: v5.data, s2: "TexCube") != 0 )
    {
      if ( idStr::Icmp(s1: v5.data, s2: "TexShadow2D") != 0 )
      {
        if ( idStr::Icmp(s1: v5.data, s2: "TexShadow3D") != 0 )
        {
          if ( idStr::Icmp(s1: v5.data, s2: "TexShadowCube") != 0 )
          {
            if ( idStr::Icmp(s1: v5.data, s2: "TexMultisample2D") != 0 )
            {
              if ( idStr::Icmp(s1: v5.data, s2: "Program") != 0 )
              {
                if ( idStr::Icmp(s1: v5.data, s2: "Vec") == 0 )
                {
                  this->parmType = PT_VECTOR;
                  goto LABEL_28;
                }
                if ( idStr::Icmp(s1: v5.data, s2: "String") != 0 )
                  goto _LN151;
                v4 = PT_STRING;
              }
              else
              {
                v4 = PT_PROGRAM;
              }
            }
            else
            {
              v4 = PT_TEXTURE_MULTISAMPLE_2D;
            }
          }
          else
          {
            v4 = PT_TEXTURE_SHADOW_CUBE;
          }
        }
        else
        {
          v4 = PT_TEXTURE_SHADOW_3D;
        }
      }
      else
      {
        v4 = PT_TEXTURE_SHADOW_2D;
      }
    }
    else
    {
      v4 = PT_TEXTURE_CUBE;
    }
  }
  else
  {
    v4 = PT_TEXTURE_CUBE;
    this->cubeFilterTexture = true;
  }
  this->parmType = v4;
LABEL_28:
  idCodeRenderParm::ParseValue(this, src: &v6, value: &this->declaredValue);
  if ( !idParser::ReadToken(this: &v6, token: &v5) || idStr::Cmp(s1: v5.data, s2: "}") == 0 )
    goto LABEL_29;
  if ( idStr::Icmp(s1: v5.data, s2: "Bool") == 0 )
  {
    this->edit = PE_BOOL;
    idStr::FreeData(this: &v5);
    goto LABEL_30;
  }
  if ( idStr::Icmp(s1: v5.data, s2: "Color") == 0 )
  {
    this->edit = PE_COLOR;
    if ( idParser::ReadToken(this: &v6, token: &v5) )
    {
      idParser::UnreadToken(this: &v6, token: &v5);
      this->editRange[0] = idParser::ParseFloat(this: &v6, errorFlag: nullptr);
      idParser::ExpectTokenString(this: &v6, string: ",");
      this->editRange[1] = idParser::ParseFloat(this: &v6, errorFlag: nullptr);
    }
    else
    {
      this->editRange[0] = 0.0;
      this->editRange[1] = 1.0;
    }
LABEL_29:
    idStr::FreeData(this: &v5);
LABEL_30:
    idParser::~idParser(this: &v6);
    return;
  }
  if ( idStr::Icmp(s1: v5.data, s2: "Range") == 0 )
  {
    this->edit = PE_RANGE;
    this->editRange[0] = idParser::ParseFloat(this: &v6, errorFlag: nullptr);
    idParser::ExpectTokenString(this: &v6, string: ",");
    this->editRange[1] = idParser::ParseFloat(this: &v6, errorFlag: nullptr);
    idStr::FreeData(this: &v5);
    goto LABEL_30;
  }
  idLib::FatalError(fmt: "Unknown edit specifier '%s'\n", v5.data);
_LN151:
  idLib::FatalError(fmt: "Bad renderParm type: %s\n", v5.data);
  _LN152();
}


// ========================================================================
// $LN152
// EA  : 0x828A9930
// RVA : 0x008A9930
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _LN152()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 880 + 160));
}


// ========================================================================
// __unwind$236733
// EA  : 0x828A9958
// RVA : 0x008A9958
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _unwind_236733()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 80));
}


// ========================================================================
// ?ResolveIRenderParmResources@idCodeRenderParm@@SAXXZ
// EA  : 0x828A9980
// RVA : 0x008A9980
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

static void __fastcall idCodeRenderParm::ResolveIRenderParmResources()
{
  int v0; // r29
  int num; // r10
  int v2; // r30
  idCodeRenderParm *v3; // r3
  parmType_t parmType; // r11

  v0 = 0;
  resolveRenderParmResourcesHasBeenCalled = true;
  num = codeRenderParmList.num;
  if ( codeRenderParmList.num > 0 )
  {
    v2 = 0;
    do
    {
      v3 = codeRenderParmList.list[v2];
      parmType = v3->parmType;
      if ( parmType != PT_VECTOR && parmType != PT_STRING )
      {
        idCodeRenderParm::ParseInitializer(this: v3);
        num = codeRenderParmList.num;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < num );
  }
}


// ========================================================================
// ??0idCodeRenderParm@@QAA@PBD0@Z
// EA  : 0x828A99F8
// RVA : 0x008A99F8
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idCodeRenderParm *__fastcall idCodeRenderParm::idCodeRenderParm(
        idCodeRenderParm *this,
        const char *name_,
        const char *initializer)
{
  int num; // r28
  char *data; // r10
  int v7; // r27
  unsigned __int8 i; // r9
  int v9; // r11
  int v10; // r10
  int indexSize; // r11
  int v12; // r7
  idCodeRenderParm *v14; // [sp+50h] [-80h] BYREF
  idStr v15[3]; // [sp+60h] [-70h] BYREF

  num = (int)name_;
  this->name.str = &byte_8200D768;
  idStr::idStr(this: v15, text: name_);
  idStr::MakeNameCanonical(this: v15);
  idAtomicString::Set(this: &this->name, str_: v15[0].data);
  data = v15[0].data;
  v7 = 0;
  for ( i = *v15[0].data; *data != 0; i = *data )
  {
    ++data;
    v7 = 31 * v7 + i;
  }
  v9 = codeRenderParmHashIndex.hash[codeRenderParmHashIndex.lookupMask & codeRenderParmHashIndex.hashMask & v7];
  if ( v9 == -1 )
  {
LABEL_7:
    this->parmIndex = codeRenderParmList.num;
    num = codeRenderParmList.num;
    indexSize = codeRenderParmHashIndex.indexSize;
    if ( codeRenderParmHashIndex.hash == idHashIndex::INVALID_INDEX )
    {
      if ( codeRenderParmList.num >= codeRenderParmHashIndex.indexSize )
        indexSize = codeRenderParmList.num + 1;
      idHashIndex::Allocate(
        this: &codeRenderParmHashIndex,
        newHashSize: codeRenderParmHashIndex.hashSize,
        newIndexSize: indexSize);
      goto LABEL_14;
    }
  }
  else
  {
    v10 = v9;
    while ( codeRenderParmList.list[v10]->name.str != this->name.str )
    {
      v9 = codeRenderParmHashIndex.indexChain[codeRenderParmHashIndex.lookupMask & v9];
      v10 = v9;
      if ( v9 == -1 )
        goto LABEL_7;
    }
    idLib::FatalError(fmt: "CodeRenderParm %s is duplicated", (const char *)num);
  }
  if ( num >= indexSize )
    idHashIndex::ResizeIndex(this: &codeRenderParmHashIndex, newIndexSize: num + 1);
LABEL_14:
  v14 = this;
  v12 = codeRenderParmHashIndex.hashMask & v7;
  codeRenderParmHashIndex.indexChain[num] = codeRenderParmHashIndex.hash[v12];
  codeRenderParmHashIndex.hash[v12] = num;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&codeRenderParmList,
    obj: (const encounterGroupRole_t *)&v14);
  this->initString = initializer;
  this->parmType = PT_VECTOR;
  this->cubeFilterTexture = false;
  this->parmIndex = 2047;
  this->edit = PE_NO_EDIT;
  this->editRange[0] = 0.0;
  this->editRange[1] = 1.0;
  this->declaredValue.swizzle[0] = 0;
  this->declaredValue.swizzle[1] = 0;
  this->declaredValue.swizzle[2] = 0;
  this->declaredValue.swizzle[3] = 0;
  idCodeRenderParm::ParseInitializer(this);
  idStr::FreeData(this: v15);
  return this;
}


// ========================================================================
// $LN56_2
// EA  : 0x828A9BE4
// RVA : 0x008A9BE4
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void _LN56_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// `dynamic initializer for 'codeRenderParmList''
// EA  : 0x83346448
// RVA : 0x01346448
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__codeRenderParmList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__codeRenderParmList__);
}


// ========================================================================
// `dynamic initializer for 'codeRenderParmHashIndex''
// EA  : 0x83346458
// RVA : 0x01346458
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__codeRenderParmHashIndex__()
{
  idHashIndex::InternalInit(this: &codeRenderParmHashIndex, initialHashSize: 1024, initialIndexSize: 1024);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__codeRenderParmHashIndex__);
}


// ========================================================================
// `dynamic initializer for 'matchRenderParms_v''
// EA  : 0x8334B1B8
// RVA : 0x0134B1B8
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__matchRenderParms_v__()
{
  return idCommandLink::idCommandLink(
           this: &matchRenderParms_v,
           cmdName: "matchRenderParms",
           function: matchRenderParms_f,
           description: "check code render parms against decl render parms",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'emitCodeRenderParms_v''
// EA  : 0x8334B1E0
// RVA : 0x0134B1E0
// PDB : w:\tech5\engine\renderer\coderenderparm.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__emitCodeRenderParms_v__()
{
  return idCommandLink::idCommandLink(
           this: &emitCodeRenderParms_v,
           cmdName: "emitCodeRenderParms",
           function: emitCodeRenderParms_f,
           description: "writes code that can be copied into the header during transition",
           argCompletion: nullptr);
}

