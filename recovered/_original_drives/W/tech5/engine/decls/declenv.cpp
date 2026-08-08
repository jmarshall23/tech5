
// ========================================================================
// ?DefaultDefinition@idDeclEnv@@UBAPBDXZ
// EA  : 0x8261B378
// RVA : 0x0061B378
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

const char *__fastcall idDeclEnv::DefaultDefinition(idDeclEnv *this)
{
  return "{\n"
         "\trenderParms {\n"
         "\t\tenvBlendTime\t\t\t2.2\n"
         "\t\tuserEnvMap\t\t\t\tenv/default_px\n"
         "\t\tambientEnvMap\t\t\tenv/ambiTest_px\n"
         "\t\tenvMapRotation\t\t\t{ 0, 0, 0 }\n"
         "\t\tcbShadow\t\t\t\t{ 0, 0, 0 }\n"
         "\t\tcbMidtone\t\t\t\t{ 0, 0, 0 }\n"
         "\t\tcbHighlight\t\t\t\t{ 0, 0, 0 }\n"
         "\t\tcbDesaturate\t\t\t0\n"
         "\t\tcbBrightness\t\t\t{ 1, 1, 1, 1 }\n"
         "\t\tcbColorDodge\t\t\t{ 0, 0, 0, 0 }\n"
         "\t\tcbColorBurn\t\t\t\t{ 1, 1, 1, 1 }\n"
         "\t\tcbColorMultiply\t\t\t{ 1, 1, 1, 1 }\n"
         "\t\tcbColorScreen\t\t\t{ 0, 0, 0, 0 }\n"
         "\t\tdepthBasedColorGrading\t{ 0, 0, 0, 0 }\n"
         "\t\tfogColor\t\t\t\t{ 0.2, 0.43, 0.5, 0.0 }\n"
         "\t\tfogScale\t\t\t\t0.00005\n"
         "\t\tfogStart\t\t\t\t0.0\n"
         "\t\tfogEnd\t\t\t\t\t32000.0\n"
         "\t\tnewAmbientScale\t\t\t{ 0.3, 0.3, 0.3 }\n"
         "\t\texposure\t\t\t\t1.0\n"
         "\t\tglareScale\t\t\t\t0.3\n"
         "\t\tdepthOfField\t\t\t{ 1.0, 1.0, 5500.0, 1.0 }\n"
         "\t\tscreenOverlay\t\t\t_white\n"
         "\t\toverlayOpacity\t\t\t0\n"
         "\t\tgrainMap\t\t\t\ttextures/common/postgrain\n"
         "\t\tgrainAmount\t\t\t\t0.03\n"
         "\t\tgrainHz\t\t\t\t\t20\n"
         "\t\tgrainLevelsMin\t\t\t0\n"
         "\t\tgrainLevelsMax\t\t\t1\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ?FreeData@idDeclEnv@@UAAXXZ
// EA  : 0x8261B388
// RVA : 0x0061B388
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

void __fastcall idDeclEnv::FreeData(idDeclEnv *this)
{
  idParmBlock::Clear(this: &this->parmBlock);
}


// ========================================================================
// ?Parse@idDeclEnv@@UAAXAAVidParser@@@Z
// EA  : 0x8261B398
// RVA : 0x0061B398
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

void __fastcall idDeclEnv::Parse(idDeclEnv *this, idParser *src)
{
  char *data; // r11
  const idDecl *v5; // r30
  const idDecl *v6; // r3
  char v7; // r11
  char *v8; // r4
  idParmBlock v9; // [sp+50h] [-F0h] BYREF
  idToken v10[2]; // [sp+80h] [-C0h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].floatvalue = -3.4028235e38;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  v10[0].intvalue = 0;
  v10[0].whiteSpaceStart_p = nullptr;
  v10[0].whiteSpaceEnd_p = nullptr;
  v10[0].next = nullptr;
  this->FreeData(this);
  idParmBlock::idParmBlock(this: &v9, threadId: THREAD_MAIN);
  if ( idParser::ReadToken(this: src, token: v10) )
  {
    while ( 1 )
    {
      if ( idStr::Cmp(s1: v10[0].data, s2: "}") == 0 )
      {
        idParmBlock::Append(this: &this->parmBlock, block: &v9);
        this->blendDuration = idParmBlock::GetFloat(
                                this: &this->parmBlock,
                                parm: (const idDeclRenderParm *)rpBlendDuration.r);
        idParmBlock::~idParmBlock(this: &v9);
        goto LABEL_29;
      }
      if ( idStr::Icmp(s1: v10[0].data, s2: "inherit") == 0 )
      {
        if ( !idParser::ExpectTokenString(this: src, string: "{") )
          goto _M219370;
        if ( idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: v10) == 0 )
        {
          idParser::Error(this: src, str: "idDeclEnv::Parse Failed to parse inherit data\n");
          idParmBlock::~idParmBlock(this: &v9);
          goto LABEL_29;
        }
        if ( !idParser::ExpectTokenString(this: src, string: "}") )
        {
          idParser::Error(this: src, str: "idDeclEnv::Parse Unexpected token, missing '}'\n");
          idParmBlock::~idParmBlock(this: &v9);
          goto LABEL_29;
        }
        if ( v10[0].len != 0 )
          break;
      }
LABEL_18:
      if ( idStr::Icmp(s1: v10[0].data, s2: "renderParms") == 0 )
      {
        if ( !idParser::ExpectTokenString(this: src, string: "{") )
        {
_M219370:
          idParser::Error(this: src, str: "idDeclEnv::Parse Unexpected token, missing '{'\n");
          idParmBlock::~idParmBlock(this: &v9);
          goto LABEL_29;
        }
        idParmBlock::Parse(this: &v9, src);
        if ( idParser::HadWarning(this: src) )
        {
          idParmBlock::~idParmBlock(this: &v9);
          goto LABEL_29;
        }
      }
      if ( !idParser::ReadToken(this: src, token: v10) )
        goto LABEL_22;
    }
    data = v10[0].data;
    if ( v10[0].data != nullptr )
    {
      v6 = idDeclInfo::FindWithInheritance(this: &idDeclEnv::resourceList, name: v10[0].data, makeDefault: false);
      v5 = v6;
      if ( v6 != nullptr )
      {
        idParmBlock::Append(this: &this->parmBlock, block: (const idParmBlock *)&v6[1]);
        v7 = 1;
        goto LABEL_14;
      }
      data = v10[0].data;
    }
    else
    {
      v5 = nullptr;
    }
    idParser::Warning(this: src, str: "idDeclEnv::Parse - Invalid base decl '%s'", data);
    v7 = 0;
LABEL_14:
    if ( v7 != 0 )
    {
      declManager->AddDependency_2(this: declManager, a2: (idDecl *)this, a3: v5);
      v8 = v10[0].data;
    }
    else
    {
      v8 = &byte_8200D768;
    }
    idAtomicString::Set(this: &this->parentDeclName, str_: v8);
    goto LABEL_18;
  }
LABEL_22:
  idParser::Error(this: src, str: "idDeclEnv::Parse Unexpected End of File\n");
  idParmBlock::~idParmBlock(this: &v9);
LABEL_29:
  idStr::FreeData(this: &v10[0]);
}


// ========================================================================
// __unwind$219193
// EA  : 0x8261B6AC
// RVA : 0x0061B6AC
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

void _unwind_219193()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$219194
// EA  : 0x8261B6D4
// RVA : 0x0061B6D4
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

void _unwind_219194()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(v0 - 320 + 80));
}


// ========================================================================
// `dynamic initializer for 'rpBlendDuration''
// EA  : 0x83336668
// RVA : 0x01336668
// PDB : w:\tech5\engine\decls\declenv.cpp
// ========================================================================

void _dynamic_initializer_for__rpBlendDuration__()
{
  rpBlendDuration.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpBlendDuration;
}

