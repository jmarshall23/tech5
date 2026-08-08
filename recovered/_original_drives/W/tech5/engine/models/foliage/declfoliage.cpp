
// ========================================================================
// ?DefaultDefinition@idDeclFoliage@@UBAPBDXZ
// EA  : 0x827D54C0
// RVA : 0x007D54C0
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

const char *__fastcall idDeclFoliage::DefaultDefinition(idDeclFoliage *this)
{
  return "{\n\tmaterial\tfoliage/default\n\tquadWidth\t64\n\tquadHeight\t64\n\tshape\t\tautosprites\n}\n";
}


// ========================================================================
// ?List@idDeclBreakable@@UBAXXZ
// EA  : 0x827D54D0
// RVA : 0x007D54D0
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDeclBreakable::List(idDeclBreakable *this)
{
  idDecl::List(this: &this->idDecl);
}


// ========================================================================
// ?Clear@idDeclFoliage@@AAAXXZ
// EA  : 0x827D54D8
// RVA : 0x007D54D8
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void __fastcall idDeclFoliage::Clear(idDeclFoliage *this)
{
  this->widthVariance = 0.0;
  this->material = nullptr;
  this->quadWidth = 0;
  this->heightVariance = 0.0;
  this->quadHeight = 0;
  this->colorVariance.x = 1.0;
  this->colorVariance.y = 1.0;
  this->colorVariance.z = 1.0;
  this->rndFlipHoriz = false;
  this->swayMagnitude = 0.0;
  this->shape = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stampMaterials);
  this->stampScale = 1.0;
  this->stampParms[3] = 1.0;
  this->stampParms[2] = 1.0;
  this->stampParms[1] = 1.0;
  this->stampParms[0] = 1.0;
  this->stampCovers[3] = 1.0;
  this->stampCovers[2] = 1.0;
  this->stampCovers[1] = 1.0;
  this->stampCovers[0] = 1.0;
  idAtomicString::Set(this: &this->stampBlendMode, str_: "none");
  this->isReferenceType = false;
  this->isSinglePlacement = false;
}


// ========================================================================
// ??0idDeclFoliage@@QAA@XZ
// EA  : 0x827D55A0
// RVA : 0x007D55A0
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

idDeclFoliage *__fastcall idDeclFoliage::idDeclFoliage(idDeclFoliage *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclFoliage_vtbl *)&idDeclFoliage::`vftable';
  this->stampMaterials.list = nullptr;
  this->stampMaterials.granularity = 0;
  this->stampMaterials.memTag = 5;
  this->stampMaterials.listStatic = 0;
  this->stampMaterials.size = 0;
  this->stampMaterials.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stampMaterials);
  this->stampBlendMode.str = &byte_8200D768;
  idDeclFoliage::Clear(this);
  return this;
}


// ========================================================================
// __unwind$219979
// EA  : 0x827D5630
// RVA : 0x007D5630
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_219979()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219980
// EA  : 0x827D5658
// RVA : 0x007D5658
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_219980()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// ??1idDeclFoliage@@UAA@XZ
// EA  : 0x827D56A0
// RVA : 0x007D56A0
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void __fastcall idDeclFoliage::~idDeclFoliage(idDeclFoliage *this)
{
  this->__vftable = (idDeclFoliage_vtbl *)&idDeclFoliage::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stampMaterials);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$220017
// EA  : 0x827D56F4
// RVA : 0x007D56F4
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_220017()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// ?Parse@idDeclFoliage@@UAAXAAVidParser@@@Z
// EA  : 0x827D5788
// RVA : 0x007D5788
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void __fastcall idDeclFoliage::Parse(idDeclFoliage *this, idParser *src)
{
  int v3; // r30
  const foliageShapeDesc_t *v4; // r11
  idStr *list; // r30
  int i; // r29
  char *data; // r4
  const idDecl *v8; // r3
  idList<idStr,5> v9; // [sp+50h] [-150h] BYREF
  idToken v10; // [sp+60h] [-140h] BYREF
  const char *v11; // [sp+A8h] [-F8h]
  const char *v12; // [sp+ACh] [-F4h]
  const char *v13; // [sp+B0h] [-F0h]
  const char *v14; // [sp+B4h] [-ECh]
  const idDecl *v15; // [sp+B8h] [-E8h] BYREF
  const char *v16; // [sp+BCh] [-E4h]
  const char *v17; // [sp+C0h] [-E0h]
  const char *v18; // [sp+C4h] [-DCh]
  const char *v19; // [sp+C8h] [-D8h]
  const char *v20; // [sp+CCh] [-D4h]
  const char *v21; // [sp+D0h] [-D0h]
  const char *v22; // [sp+D4h] [-CCh]
  const char *v23; // [sp+D8h] [-C8h]
  const char *v24; // [sp+DCh] [-C4h]
  idStr v25[6]; // [sp+E0h] [-C0h] BYREF

  idDeclFoliage::Clear(this);
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.floatvalue = -3.4028235e38;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v10) )
  {
    v11 = "material";
    v19 = "stampParms";
    v17 = "stampScale";
    v13 = "stampMaterial";
    v20 = "colorVariance";
    v24 = "swayMagnitude";
    v16 = "rndFlipHoriz";
    v12 = "shape";
    v14 = "heightVariance";
    v22 = "widthVariance";
    v23 = "quadHeight";
    v21 = "quadWidth";
    v18 = "}";
    do
    {
      if ( idStr::Icmp(s1: v10.data, s2: v18) == 0 )
        break;
      if ( idStr::Icmp(s1: v10.data, s2: v21) != 0 )
      {
        if ( idStr::Icmp(s1: v10.data, s2: v23) != 0 )
        {
          if ( idStr::Icmp(s1: v10.data, s2: v22) != 0 )
          {
            if ( idStr::Icmp(s1: v10.data, s2: v14) != 0 )
            {
              if ( idStr::Icmp(s1: v10.data, s2: v20) != 0 )
              {
                if ( idStr::Icmp(s1: v10.data, s2: v16) != 0 )
                {
                  if ( idStr::Icmp(s1: v10.data, s2: v24) != 0 )
                  {
                    if ( idStr::Icmp(s1: v10.data, s2: v11) != 0 )
                    {
                      if ( idStr::Icmp(s1: v10.data, s2: v12) != 0 )
                        goto LABEL_31;
                      idParser::ReadToken(this: src, token: &v10);
                      v3 = 0;
                      if ( "autosprites" != nullptr )
                      {
                        v4 = foliageShapeDesc;
                        do
                        {
                          if ( idStr::Icmp(s1: v10.data, s2: v4->name) == 0 )
                            break;
                          v4 = &foliageShapeDesc[++v3];
                        }
                        while ( v4->name != nullptr );
                      }
                      if ( foliageShapeDesc[v3].name == nullptr )
                      {
                        idParser::Error(this: src, str: "bad shape type: %s\n", v10.data);
LABEL_31:
                        if ( idStr::Icmp(s1: v10.data, s2: v13) != 0 )
                        {
                          if ( idStr::Icmp(s1: v10.data, s2: v17) != 0 )
                          {
                            if ( idStr::Icmp(s1: v10.data, s2: v19) != 0 )
                            {
                              if ( idStr::Icmp(s1: v10.data, s2: "stampCovers") != 0 )
                              {
                                if ( idStr::Icmp(s1: v10.data, s2: "stampBlendMode") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v10.data, s2: "referenceType") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v10.data, s2: "singlePlacement") != 0 )
                                      idParser::Warning(this: src, str: "idDeclFoliage::Parse - bad token %s", v10.data);
                                    else
                                      this->isSinglePlacement = idParser::ParseBool(this: src);
                                  }
                                  else
                                  {
                                    this->isReferenceType = idParser::ParseBool(this: src);
                                  }
                                }
                                else
                                {
                                  if ( idParser::ExpectAnyToken(this: src, token: &v10) == 0 )
                                    break;
                                  idAtomicString::Set(this: &this->stampBlendMode, str_: v10.data);
                                }
                              }
                              else if ( !idParser::Parse1DMatrix(this: src, x: 4, m: this->stampCovers) )
                              {
                                idParser::Error(this: src, str: "Invalid stampCovers parameter: %s\n", this->name.str);
                              }
                            }
                            else if ( !idParser::Parse1DMatrix(this: src, x: 4, m: this->stampParms) )
                            {
                              idParser::Error(this: src, str: "Invalid stampParms parameter: %s\n", this->name.str);
                            }
                          }
                          else
                          {
                            this->stampScale = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stampMaterials);
                          idParser::ParseRestOfLine(this: src, out: &v10);
                          *(_WORD *)&v9.memTag = 1280;
                          memset(&v9, 0, 14);
                          idStrListBreakupString(list: &v9, string: v10.data, separator: " ");
                          if ( v9.num > 0 )
                          {
                            list = v9.list;
                            for ( i = v9.num; i != 0; --i )
                            {
                              idStr::idStr(this: v25, text: list);
                              idStr::StripLeading(this: v25, string: " ");
                              idStr::StripTrailing(this: v25, string: " ");
                              data = v25[0].data;
                              if ( v25[0].data != nullptr )
                              {
                                v8 = idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: v25[0].data,
                                       makeDefault: false);
                                data = v25[0].data;
                              }
                              else
                              {
                                v8 = nullptr;
                              }
                              v15 = v8;
                              if ( v8 != nullptr )
                                idList<idAnimWebBlendTree *,5>::Append(
                                  this: (idList<enum encounterGroupRole_t,5> *)&this->stampMaterials,
                                  obj: (const encounterGroupRole_t *)&v15);
                              else
                                idLib::Warning(fmt: "Foliage stamp material '%s' NOT found!", data);
                              idStr::FreeData(this: v25);
                              ++list;
                            }
                          }
                          idList<idStr,99>::~idList<idStr,99>(this: &v9);
                        }
                        continue;
                      }
                      this->shape = foliageShapeDesc[v3].shape;
                    }
                    else
                    {
                      if ( idParser::ExpectAnyToken(this: src, token: &v10) == 0 )
                        break;
                      if ( v10.data != nullptr )
                        this->material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                               this: &idMaterial::resourceList,
                                                               name: v10.data,
                                                               makeDefault: true);
                      else
                        this->material = nullptr;
                    }
                  }
                  else
                  {
                    this->swayMagnitude = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  this->rndFlipHoriz = idParser::ParseBool(this: src);
                }
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
              this->heightVariance = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            this->widthVariance = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          this->quadHeight = idParser::ParseInt(this: src);
        }
      }
      else
      {
        this->quadWidth = idParser::ParseInt(this: src);
      }
    }
    while ( idParser::ReadToken(this: src, token: &v10) );
  }
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$220196
// EA  : 0x827D5DE8
// RVA : 0x007D5DE8
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_220196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$220197
// EA  : 0x827D5E10
// RVA : 0x007D5E10
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_220197()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$220198
// EA  : 0x827D5E38
// RVA : 0x007D5E38
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void _unwind_220198()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 224));
}


// ========================================================================
// `dynamic initializer for 'r_skipFoliage''
// EA  : 0x83342B80
// RVA : 0x01342B80
// PDB : w:\tech5\engine\models\foliage\declfoliage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipFoliage__()
{
  idCVar::idCVar(
    this: &r_skipFoliage,
    name: "r_skipFoliage",
    value: "0",
    flags: 1,
    description: "Completely disable foliage models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipFoliage__);
}

