
// ========================================================================
// ?IsTransitioning@idAnimator_AnimWeb@@QBA_NXZ
// EA  : 0x826D1400
// RVA : 0x006D1400
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

int __fastcall idAnimator_AnimWeb::IsTransitioning(idAnimator_AnimWeb *this)
{
  unsigned __int8 v1; // r11

  if ( (unsigned __int16)this->curEdgeNodeIndex.value >= 0x8000u )
    return 0;
  v1 = 1;
  if ( (unsigned __int16)this->curEdgeIndex >= 0x8000u )
    return 0;
  return v1;
}


// ========================================================================
// ?GetHandle@idAnimator_AnimWeb@@UBAABV?$idHandle@FW4invalidAnimWebHandle_t@@$0?0@@XZ
// EA  : 0x826D5CD0
// RVA : 0x006D5CD0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

const idHandle<short,enum invalidAnimWebHandle_t,-1> *__fastcall idAnimator_AnimWeb::GetHandle(
        idAnimator_AnimWeb *this)
{
  return &this->handle;
}


// ========================================================================
// ??0idAnimatorParms_AnimWeb@@QAA@PAVidAnimStack@@PBDW4blendOp_t@idMD6Blend@@W4originBlend_t@3@W4md6WeightGroup_t@@4MPBVidDeclAnimWeb@@11H@Z
// EA  : 0x82A02220
// RVA : 0x00A02220
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

idAnimatorParms_AnimWeb *__fastcall idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
        idAnimatorParms_AnimWeb *this,
        idAnimStack *animStack_,
        const char *name_,
        idMD6Blend::blendOp_t blendOp_,
        idMD6Blend::originBlend_t originBlend_,
        md6WeightGroup_t weightGroup_,
        md6WeightGroup_t filterGroup_,
        double alpha_,
        const idDeclAnimWeb *webDecl_,
        const char *initialSubWebName_,
        const char *initialStateName_,
        const int curTime_,
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
        const idDeclAnimWeb *a29,
        int a30,
        const char *a31,
        int a32,
        const char *a33,
        int a34,
        int a35)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->blendOp = blendOp_;
  this->originBlend = originBlend_;
  this->weightGroup = weightGroup_;
  this->filterGroup = filterGroup_;
  this->webDecl = a29;
  idStr::idStr(this: &this->initialStateName, text: a33);
  idStr::idStr(this: &this->initialSubWebName, text: a31);
  this->curTime = a35;
  this->activeLayers.list = nullptr;
  this->activeLayers.granularity = 0;
  this->activeLayers.memTag = 5;
  this->activeLayers.listStatic = 0;
  this->activeLayers.size = 0;
  this->activeLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeLayers);
  return this;
}


// ========================================================================
// __unwind$537626
// EA  : 0x82A022D4
// RVA : 0x00A022D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

void _unwind_537626()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: *(vaiAction_t::vehicleCam_t **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$537627
// EA  : 0x82A022FC
// RVA : 0x00A022FC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

void _unwind_537627()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 60));
}


// ========================================================================
// __unwind$537628
// EA  : 0x82A02328
// RVA : 0x00A02328
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.h
// ========================================================================

void _unwind_537628()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}

