
// ========================================================================
// ??0idAnimatorParms_BlendEq@@QAA@PAVidAnimStack@@PBDW4blendOp_t@idMD6Blend@@W4originBlend_t@3@W4md6WeightGroup_t@@4M1PAVidScalarMemBlock@@@Z
// EA  : 0x82CE6048
// RVA : 0x00CE6048
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.h
// ========================================================================

idAnimatorParms_BlendEq *__fastcall idAnimatorParms_BlendEq::idAnimatorParms_BlendEq(
        idAnimatorParms_BlendEq *this,
        idAnimStack *animStack_,
        const char *name_,
        idMD6Blend::blendOp_t blendOp_,
        idMD6Blend::originBlend_t originBlend_,
        md6WeightGroup_t weightGroup_,
        md6WeightGroup_t filterGroup_,
        double alpha_,
        const char *blendEq_,
        idScalarMemBlock *scalarMem_,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        const char *a29,
        int a30,
        idScalarMemBlock *a31)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->blendOp = blendOp_;
  this->originBlend = originBlend_;
  this->weightGroup = weightGroup_;
  this->filterGroup = filterGroup_;
  idStr::idStr(this: &this->blendEq, text: a29);
  this->scalars.list = nullptr;
  this->scalars.granularity = 0;
  this->scalars.memTag = 5;
  this->scalars.listStatic = 0;
  this->scalars.size = 0;
  this->scalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  this->scalarMem = a31;
  this->anims.list = nullptr;
  this->anims.granularity = 0;
  this->anims.memTag = 5;
  this->anims.listStatic = 0;
  this->anims.size = 0;
  this->anims.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->anims);
  return this;
}


// ========================================================================
// __unwind$494308_0
// EA  : 0x82CE6108
// RVA : 0x00CE6108
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.h
// ========================================================================

void _unwind_494308_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: *(vaiAction_t::vehicleCam_t **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$494309_0
// EA  : 0x82CE6130
// RVA : 0x00CE6130
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.h
// ========================================================================

void _unwind_494309_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$494310_0
// EA  : 0x82CE615C
// RVA : 0x00CE615C
// PDB : w:\tech5\engine\gamelib\animstack\animator_blendeq.h
// ========================================================================

void _unwind_494310_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 88));
}

