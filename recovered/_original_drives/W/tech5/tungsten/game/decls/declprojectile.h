
// ========================================================================
// ?GetDeclInfo@idDeclProjectile@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCB4C0
// RVA : 0x00BCB4C0
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

idDeclInfoTemplate<idDeclProjectile> *__fastcall idDeclProjectile::GetDeclInfo(idDeclProjectile *this)
{
  return &idDeclProjectile::resourceList;
}


// ========================================================================
// ??0projectileImpactEffect_t@idDeclProjectileImpactEffect@@QAA@XZ
// EA  : 0x82BD2FA8
// RVA : 0x00BD2FA8
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

idDeclProjectileImpactEffect::projectileImpactEffect_t *__fastcall idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(
        idDeclProjectileImpactEffect::projectileImpactEffect_t *this)
{
  this->decalMaterial.list = nullptr;
  this->decalMaterial.granularity = 0;
  this->decalMaterial.memTag = 5;
  this->decalMaterial.listStatic = 0;
  this->decalMaterial.size = 0;
  this->decalMaterial.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->decalQuad = false;
  this->particleImpact = nullptr;
  this->sndImpact = nullptr;
  this->useSmokeSystem = false;
  this->decalLifetime = 8000;
  this->isBloody = false;
  this->decalSize = 8.0;
  this->decalDepth = 4.0;
  this->decalAngle = 0.0;
  return this;
}


// ========================================================================
// ??0idDeclProjectileImpactEffect@@QAA@XZ
// EA  : 0x82BD4520
// RVA : 0x00BD4520
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

idDeclProjectileImpactEffect *__fastcall idDeclProjectileImpactEffect::idDeclProjectileImpactEffect(
        idDeclProjectileImpactEffect *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclProjectileImpactEffect_vtbl *)&idDeclProjectileImpactEffect::`vftable';
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->debugDefaultEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->defaultEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->metalEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->metalHollow);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->metalSheet);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->stoneEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->fleshEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->fleshPlayerEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->woodEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->cardboardEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->liquidEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->glassEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->plasticEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->asphaltEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->dirtEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->concreteEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->foilageEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->linoleumEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->fabricEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->rubberEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->rockEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->steamPipeEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->waterPipeEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->armorEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->sludgeEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->bloodPoolEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->mutantFleshEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->thickPaddingEffect);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->ricketyMetal);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->ricketyWood);
  idDeclProjectileImpactEffect::projectileImpactEffect_t::projectileImpactEffect_t(this: &this->bloodReplacementEffect);
  return this;
}


// ========================================================================
// __unwind$502412
// EA  : 0x82BD4664
// RVA : 0x00BD4664
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502412()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$502413
// EA  : 0x82BD468C
// RVA : 0x00BD468C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502413()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$502414
// EA  : 0x82BD46B8
// RVA : 0x00BD46B8
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502414()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 112));
}


// ========================================================================
// __unwind$502415
// EA  : 0x82BD46E4
// RVA : 0x00BD46E4
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502415()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 160));
}


// ========================================================================
// __unwind$502416
// EA  : 0x82BD4710
// RVA : 0x00BD4710
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502416()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 208));
}


// ========================================================================
// __unwind$502417
// EA  : 0x82BD473C
// RVA : 0x00BD473C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502417()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 256));
}


// ========================================================================
// __unwind$502418
// EA  : 0x82BD4768
// RVA : 0x00BD4768
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502418()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$502419
// EA  : 0x82BD4794
// RVA : 0x00BD4794
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502419()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 352));
}


// ========================================================================
// __unwind$502420
// EA  : 0x82BD47C0
// RVA : 0x00BD47C0
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502420()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 400));
}


// ========================================================================
// __unwind$502421
// EA  : 0x82BD47EC
// RVA : 0x00BD47EC
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502421()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 448));
}


// ========================================================================
// __unwind$502422
// EA  : 0x82BD4818
// RVA : 0x00BD4818
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502422()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 496));
}


// ========================================================================
// __unwind$502423
// EA  : 0x82BD4844
// RVA : 0x00BD4844
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502423()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 544));
}


// ========================================================================
// __unwind$502424
// EA  : 0x82BD4870
// RVA : 0x00BD4870
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502424()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 592));
}


// ========================================================================
// __unwind$502425
// EA  : 0x82BD489C
// RVA : 0x00BD489C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502425()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// __unwind$502426
// EA  : 0x82BD48C8
// RVA : 0x00BD48C8
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502426()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 688));
}


// ========================================================================
// __unwind$502427
// EA  : 0x82BD48F4
// RVA : 0x00BD48F4
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502427()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 736));
}


// ========================================================================
// __unwind$502428
// EA  : 0x82BD4920
// RVA : 0x00BD4920
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502428()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 784));
}


// ========================================================================
// __unwind$502429
// EA  : 0x82BD494C
// RVA : 0x00BD494C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502429()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 832));
}


// ========================================================================
// __unwind$502430
// EA  : 0x82BD4978
// RVA : 0x00BD4978
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// __unwind$502431
// EA  : 0x82BD49A4
// RVA : 0x00BD49A4
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502431()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 928));
}


// ========================================================================
// __unwind$502432
// EA  : 0x82BD49D0
// RVA : 0x00BD49D0
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502432()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 976));
}


// ========================================================================
// __unwind$502433
// EA  : 0x82BD49FC
// RVA : 0x00BD49FC
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502433()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1024));
}


// ========================================================================
// __unwind$502434
// EA  : 0x82BD4A28
// RVA : 0x00BD4A28
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502434()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1072));
}


// ========================================================================
// __unwind$502435
// EA  : 0x82BD4A54
// RVA : 0x00BD4A54
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502435()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1120));
}


// ========================================================================
// __unwind$502436
// EA  : 0x82BD4A80
// RVA : 0x00BD4A80
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1168));
}


// ========================================================================
// __unwind$502437
// EA  : 0x82BD4AAC
// RVA : 0x00BD4AAC
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502437()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1216));
}


// ========================================================================
// __unwind$502438
// EA  : 0x82BD4AD8
// RVA : 0x00BD4AD8
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502438()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1264));
}


// ========================================================================
// __unwind$502439
// EA  : 0x82BD4B04
// RVA : 0x00BD4B04
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502439()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1312));
}


// ========================================================================
// __unwind$502440
// EA  : 0x82BD4B30
// RVA : 0x00BD4B30
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502440()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1360));
}


// ========================================================================
// __unwind$502441
// EA  : 0x82BD4B5C
// RVA : 0x00BD4B5C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502441()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1408));
}


// ========================================================================
// __unwind$502442
// EA  : 0x82BD4B88
// RVA : 0x00BD4B88
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

void _unwind_502442()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1456));
}


// ========================================================================
// ?GetDeclInfo@idDeclProjectileImpactEffect@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD4BB8
// RVA : 0x00BD4BB8
// PDB : w:\tech5\tungsten\game\decls\declprojectile.h
// ========================================================================

idDeclInfoTemplate<idDeclProjectileImpactEffect> *__fastcall idDeclProjectileImpactEffect::GetDeclInfo(
        idDeclProjectileImpactEffect *this)
{
  return &idDeclProjectileImpactEffect::resourceList;
}

