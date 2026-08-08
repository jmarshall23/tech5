
// ========================================================================
// ?DefaultDefinition@idDeclDetail@@UBAPBDXZ
// EA  : 0x827CA3C8
// RVA : 0x007CA3C8
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

const char *__fastcall idDeclDetail::DefaultDefinition(idDeclDetail *this)
{
  return "{\n\tmodel\t_default\n}\n";
}


// ========================================================================
// ?Print@idDeclBreakable@@UBAXXZ
// EA  : 0x827CA3D8
// RVA : 0x007CA3D8
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDeclBreakable::Print(idDeclBreakable *this)
{
  idAtlasResource::Print(this: &this->idDecl);
}


// ========================================================================
// ??0idDeclDetail@@QAA@XZ
// EA  : 0x827CA3F8
// RVA : 0x007CA3F8
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

idDeclDetail *__fastcall idDeclDetail::idDeclDetail(idDeclDetail *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclDetail_vtbl *)&idDeclDetail::`vftable';
  this->modelName.str = &byte_8200D768;
  idAtomicString::Set(this: &this->modelName, str_: &byte_8200D768);
  this->colorVariance.x = 1.0;
  this->colorVariance.y = 1.0;
  this->colorVariance.z = 1.0;
  return this;
}


// ========================================================================
// __unwind$219227
// EA  : 0x827CA484
// RVA : 0x007CA484
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

void _unwind_219227()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// ?Parse@idDeclDetail@@UAAXAAVidParser@@@Z
// EA  : 0x827CA520
// RVA : 0x007CA520
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

void __fastcall idDeclDetail::Parse(idDeclDetail *this, idParser *src)
{
  idAtomicString *p_modelName; // r24
  idToken v5[2]; // [sp+50h] [-90h] BYREF

  p_modelName = &this->modelName;
  idAtomicString::Set(this: &this->modelName, str_: &byte_8200D768);
  v5[0].len = 0;
  v5[0].allocedAndFlag = 20;
  v5[0].data = v5[0].baseBuffer;
  v5[0].floatvalue = -3.4028235e38;
  v5[0].baseBuffer[0] = 0;
  this->colorVariance.x = 1.0;
  v5[0].intvalue = 0;
  this->colorVariance.y = 1.0;
  v5[0].whiteSpaceStart_p = nullptr;
  this->colorVariance.z = 1.0;
  v5[0].whiteSpaceEnd_p = nullptr;
  v5[0].next = nullptr;
  while ( idParser::ReadToken(this: src, token: v5) )
  {
    if ( idStr::Icmp(s1: v5[0].data, s2: "}") == 0 )
      break;
    if ( idStr::Icmp(s1: v5[0].data, s2: "model") != 0 )
    {
      if ( idStr::Icmp(s1: v5[0].data, s2: "colorVariance") != 0 )
      {
        idParser::Warning(this: src, str: "idDeclDetail::Parse - bad token %s", v5[0].data);
      }
      else
      {
        this->colorVariance.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
        this->colorVariance.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
        this->colorVariance.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
      }
    }
    else
    {
      if ( idParser::ExpectAnyToken(this: src, token: v5) == 0 )
        break;
      idAtomicString::Set(this: p_modelName, str_: v5[0].data);
    }
  }
  idStr::FreeData(this: &v5[0]);
}


// ========================================================================
// __unwind$219285
// EA  : 0x827CA6A4
// RVA : 0x007CA6A4
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

void _unwind_219285()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// `dynamic initializer for 'r_skipDetailModels''
// EA  : 0x833424E8
// RVA : 0x013424E8
// PDB : w:\tech5\engine\models\detail\decldetail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDetailModels__()
{
  idCVar::idCVar(
    this: &r_skipDetailModels,
    name: "r_skipDetailModels",
    value: "0",
    flags: 1,
    description: "Completely disable detail model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDetailModels__);
}

