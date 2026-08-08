
// ========================================================================
// ?GetRadiusDamageJointIndices@idAnimatedEntity@@UAAAAV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@XZ
// EA  : 0x824E3428
// RVA : 0x004E3428
// PDB : w:\tech5\tungsten\game\entities\animatedentity.h
// ========================================================================

idList<idIndex<short,enum invalidJointIndex_t>,5> *__fastcall idAnimatedEntity::GetRadiusDamageJointIndices(
        idAnimatedEntity *this)
{
  return &this->radiusDamageJointIndices;
}


// ========================================================================
// ?GetMD6Tree@idAnimatedEntity@@UBAPBVidMD6Node@@XZ
// EA  : 0x824E3430
// RVA : 0x004E3430
// PDB : w:\tech5\tungsten\game\entities\animatedentity.h
// ========================================================================

const idMD6Node *__fastcall idAnimatedEntity::GetMD6Tree(idAnimatedEntity *this)
{
  return this->GetAnimStack(this)->tree;
}


// ========================================================================
// ?GetMD6Tree@idAnimatedEntity@@UAAPAVidMD6Node@@XZ
// EA  : 0x824E3460
// RVA : 0x004E3460
// PDB : w:\tech5\tungsten\game\entities\animatedentity.h
// ========================================================================

idMD6Node *__fastcall idAnimatedEntity::GetMD6Tree(idAnimatedEntity *this)
{
  return this->GetAnimStack_2(this)->tree;
}


// ========================================================================
// ?GetFXDecl@idAnimatedEntity@@UBAPBVidDeclFX@@XZ
// EA  : 0x824E3490
// RVA : 0x004E3490
// PDB : w:\tech5\tungsten\game\entities\animatedentity.h
// ========================================================================

const idDeclFX *__fastcall idAnimatedEntity::GetFXDecl(idAnimatedEntity *this)
{
  return this->fxDecl;
}


// ========================================================================
// ?GetTreeAnimatorFromPresentable@idAnimatedEntity@@QAAPAVidTreeAnimator@@XZ
// EA  : 0x829F08B8
// RVA : 0x009F08B8
// PDB : w:\tech5\tungsten\game\entities\animatedentity.h
// ========================================================================

idTreeAnimator *__fastcall idAnimatedEntity::GetTreeAnimatorFromPresentable(idAnimatedEntity *this)
{
  idPresentable *presentable; // r3
  idPresentable *v3; // r3
  idPresentableAnimatedEntity *v4; // r3

  presentable = this->presentable;
  if ( presentable == nullptr || presentable->GetAnimatedEntityInterface(this: presentable) == nullptr )
    return nullptr;
  v3 = this->presentable;
  if ( v3 == nullptr )
    return idPresentableAnimatedEntity::GetTreeAnimator(this: nullptr);
  v4 = v3->GetAnimatedEntityInterface(this: v3);
  return idPresentableAnimatedEntity::GetTreeAnimator(this: v4);
}

