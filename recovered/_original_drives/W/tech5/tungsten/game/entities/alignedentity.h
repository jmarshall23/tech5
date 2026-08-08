
// ========================================================================
// ??0queuedAnim_t@idAlignedEntity@@QAA@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82BF1C58
// RVA : 0x00BF1C58
// PDB : w:\tech5\tungsten\game\entities\alignedentity.h
// ========================================================================

idAlignedEntity::queuedAnim_t *__fastcall idAlignedEntity::queuedAnim_t::queuedAnim_t(
        idAlignedEntity::queuedAnim_t *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *_aliasHandle,
        bool _loop,
        int _durationMS,
        const blendParms_t *_blendParms,
        double _rateScale)
{
  blendParms_t *p_blendParms; // r31
  unsigned __int16 value; // r10
  char *p_flags; // r11
  char *v15; // r10
  int i; // ctr
  char *v18; // r11
  char *v19; // r10
  int j; // ctr
  char v21; // [sp+4Ch] [-64h] BYREF
  blendParms_t v22; // [sp+50h] [-60h] BYREF

  p_blendParms = &this->blendParms;
  this->aliasHandle.value = -1;
  blendParms_t::blendParms_t(this: &this->blendParms);
  value = _aliasHandle->value;
  this->rateScale = _rateScale;
  this->loop = _loop;
  this->durationMS = _durationMS;
  this->aliasHandle.value = value;
  if ( _blendParms != nullptr )
  {
    p_flags = &_blendParms[-1].parms.flags;
    v15 = &p_blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v15 += 4;
      *(_DWORD *)v15 = *(_DWORD *)p_flags;
    }
    return this;
  }
  else
  {
    blendParms_t::blendParms_t(this: &v22);
    v18 = &v21;
    v19 = &p_blendParms[-1].parms.flags;
    for ( j = 5; j != 0; --j )
    {
      v18 += 4;
      v19 += 4;
      *(_DWORD *)v19 = *(_DWORD *)v18;
    }
    return this;
  }
}


// ========================================================================
// ??0animInfo_t@idAlignedEntity@@QAA@XZ
// EA  : 0x82BF3878
// RVA : 0x00BF3878
// PDB : w:\tech5\tungsten\game\entities\alignedentity.h
// ========================================================================

idAlignedEntity::animInfo_t *__fastcall idAlignedEntity::animInfo_t::animInfo_t(idAlignedEntity::animInfo_t *this)
{
  this->animDurationMS = 0;
  this->curAliasHandle.value = -1;
  this->queuedAnims.list = nullptr;
  this->queuedAnims.granularity = 0;
  this->queuedAnims.memTag = 5;
  this->queuedAnims.listStatic = 0;
  this->queuedAnims.size = 0;
  this->queuedAnims.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->queuedAnims);
  this->startBlendOut = false;
  this->startTime = 0;
  return this;
}


// ========================================================================
// ?GetAttachments@idAlignedEntity@@UBAPBVidAttachmentCollection@@XZ
// EA  : 0x82BF4AA0
// RVA : 0x00BF4AA0
// PDB : w:\tech5\tungsten\game\entities\alignedentity.h
// ========================================================================

const idAttachmentCollection *__fastcall idAlignedEntity::GetAttachments(idAlignedEntity *this)
{
  return &this->attachmentCollection;
}


// ========================================================================
// ?IsDead@idAlignedEntity@@UBA_NXZ
// EA  : 0x82BF4AA8
// RVA : 0x00BF4AA8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.h
// ========================================================================

BOOL __fastcall idAlignedEntity::IsDead(idAlignedEntity *this)
{
  return (_cntlzw(this->isAlive) & 0x20) != 0;
}


// ========================================================================
// ?GetInventory@idAlignedEntity@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82BF4AB8
// RVA : 0x00BF4AB8
// PDB : w:\tech5\tungsten\game\entities\alignedentity.h
// ========================================================================

const idInventoryCollection *__fastcall idAlignedEntity::GetInventory(idAlignedEntity *this)
{
  return &this->inventory;
}

