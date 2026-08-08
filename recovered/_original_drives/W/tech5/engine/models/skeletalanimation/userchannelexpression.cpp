
// ========================================================================
// ?LookUpVar@VarContext@idUserChannelExpression@@QAA_NPBDAAVVarId@2@@Z
// EA  : 0x82864FC0
// RVA : 0x00864FC0
// PDB : w:\tech5\engine\models\skeletalanimation\userchannelexpression.cpp
// ========================================================================

int __fastcall idUserChannelExpression::VarContext::LookUpVar(
        idUserChannelExpression::VarContext *this,
        const char *name,
        idUserChannelExpression::VarId *resId)
{
  idMD6Skel v7[6]; // [sp+50h] [-150h] BYREF

  idMD6Skel::GetUserChannelIndex(
    this: v7,
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)this->decl->model->skeleton,
    name);
  if ( SHIWORD(v7[0].__vftable) < 0 )
  {
    HIBYTE(v7[0].staleCount) = 0;
    HIBYTE(v7[0].jointConversion.value) = 0;
    v7[0].resourceError = (const char *)&v7[0].jointConversion;
    v7[0].resourceListPtr = nullptr;
    v7[0].networkID = -2147483408;
    idStr::Format(this: (idStr *)&v7[0].resourceListPtr, fmt: "facedata_%s", name);
    idMD6Skel::GetUserChannelIndex(
      this: (idMD6Skel *)((char *)&v7[0].__vftable + 2),
      result: (idIndex<short,enum invalidUserChannelIndex_t> *)this->decl->model->skeleton,
      name: v7[0].resourceError);
    HIWORD(v7[0].__vftable) = v7[0].__vftable;
    idStr::FreeData(this: (idStr *)&v7[0].resourceListPtr);
  }
  if ( SHIWORD(v7[0].__vftable) < 0 )
    return 0;
  resId->index = SHIWORD(v7[0].__vftable);
  return 1;
}


// ========================================================================
// __unwind$220713
// EA  : 0x8286508C
// RVA : 0x0086508C
// PDB : w:\tech5\engine\models\skeletalanimation\userchannelexpression.cpp
// ========================================================================

void _unwind_220713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// ?Eval@idUserChannelExpression@@QAAMPBMH@Z
// EA  : 0x82865648
// RVA : 0x00865648
// PDB : w:\tech5\engine\models\skeletalanimation\userchannelexpression.cpp
// ========================================================================

float __fastcall idUserChannelExpression::Eval(
        idUserChannelExpression *this,
        const float *userChannels,
        int numChannels)
{
  double v3; // fp1
  idUserChannelExpression::VarContext v5; // [sp+50h] [-20h] BYREF

  if ( this->expr.root == 255 )
  {
    v3 = 0.0;
  }
  else
  {
    v5.channels = userChannels;
    v5.numChannels = numChannels;
    v5.decl = nullptr;
    v3 = idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Eval(
           this: &this->expr,
           varContext: &v5);
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?Parse@idUserChannelExpression@@QAA_NPBDPBVidDeclMD6@@@Z
// EA  : 0x828665E0
// RVA : 0x008665E0
// PDB : w:\tech5\engine\models\skeletalanimation\userchannelexpression.cpp
// ========================================================================

int __fastcall idUserChannelExpression::Parse(
        idUserChannelExpression *this,
        const char *exprStr,
        const idDeclMD6 *decl)
{
  idUserChannelExpression::VarContext v4; // [sp+50h] [-20h] BYREF

  v4.decl = decl;
  v4.channels = nullptr;
  v4.numChannels = 0;
  return idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::Parse(
           this: &this->expr,
           exprStr,
           varContext: &v4);
}

