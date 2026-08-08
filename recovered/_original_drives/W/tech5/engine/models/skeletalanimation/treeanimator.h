
// ========================================================================
// ?GetPropsCollection@idTreeAnimator@@QAAPAVidPropsCollection@@XZ
// EA  : 0x8270B1A0
// RVA : 0x0070B1A0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.h
// ========================================================================

idPropsCollection *__fastcall idTreeAnimator::GetPropsCollection(idTreeAnimator *this)
{
  const idDeclMD6 *decl; // r11
  idPropsCollection *result; // r3

  decl = this->decl;
  result = &decl->props;
  if ( decl == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetModelDefName@idTreeAnimator@@QBAPBDXZ
// EA  : 0x82A35450
// RVA : 0x00A35450
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.h
// ========================================================================

char *__fastcall idTreeAnimator::GetModelDefName(idTreeAnimator *this)
{
  const idDeclMD6 *decl; // r11

  decl = this->decl;
  if ( decl != nullptr )
    return (char *)decl->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetJointGroupCollection@idTreeAnimator@@QAAPAVidJointGroupCollection@@XZ
// EA  : 0x82ABA900
// RVA : 0x00ABA900
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.h
// ========================================================================

idJointGroupCollection *__fastcall idTreeAnimator::GetJointGroupCollection(idTreeAnimator *this)
{
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *result; // r3

  decl = this->decl;
  result = &decl->jointGroupCollection;
  if ( decl == nullptr )
    return nullptr;
  return result;
}

