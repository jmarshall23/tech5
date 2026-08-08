
// ========================================================================
// ??0idAnimWebPath@@QAA@PBD00@Z
// EA  : 0x826D0C68
// RVA : 0x006D0C68
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.h
// ========================================================================

idAnimWebPath *__fastcall idAnimWebPath::idAnimWebPath(
        idAnimWebPath *this,
        const char *webName,
        const char *subWebName,
        const char *stateName)
{
  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  idAnimWebPath::SetPath(this, webName, subWebName, stateName);
  return this;
}


// ========================================================================
// __unwind$251720
// EA  : 0x826D0CC4
// RVA : 0x006D0CC4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.h
// ========================================================================

void _unwind_251720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetJointIndex@idDeclMD6@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@ABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@@Z
// EA  : 0x826E3098
// RVA : 0x006E3098
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.h
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::GetJointIndex(
        idDeclMD6 *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const idHandle<unsigned short,enum invalidJointHandle_t,65535> *handle)
{
  int v3; // r11
  idIndex<short,enum invalidJointIndex_t> *v5; // r4
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  _WORD v8[8]; // [sp+50h] [-20h] BYREF

  v3 = *(_DWORD *)&result[30].value;
  if ( v3 != 0 && (v5 = *(idIndex<short,enum invalidJointIndex_t> **)(v3 + 212)) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: (idMD6Skel *)v8, result: v5, handle);
  }
  else
  {
    JointIndex = (idIndex<short,enum invalidJointIndex_t> *)v8;
    v8[0] = -1;
  }
  HIWORD(this->__vftable) = (idIndex<short,enum invalidJointIndex_t>)JointIndex->value;
  return this;
}


// ========================================================================
// ?GetJointIndex@idDeclMD6@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@PBD@Z
// EA  : 0x826EE008
// RVA : 0x006EE008
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.h
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::GetJointIndex(
        idDeclMD6 *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const char *jointName)
{
  int v3; // r11
  idIndex<short,enum invalidJointIndex_t> *v5; // r4
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  _WORD v8[8]; // [sp+50h] [-20h] BYREF

  v3 = *(_DWORD *)&result[30].value;
  if ( v3 != 0 && (v5 = *(idIndex<short,enum invalidJointIndex_t> **)(v3 + 212)) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: (idMD6Skel *)v8, result: v5, name: jointName);
  }
  else
  {
    JointIndex = (idIndex<short,enum invalidJointIndex_t> *)v8;
    v8[0] = -1;
  }
  HIWORD(this->__vftable) = (idIndex<short,enum invalidJointIndex_t>)JointIndex->value;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclMD6@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82816578
// RVA : 0x00816578
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.h
// ========================================================================

idDeclInfoTemplate<idDeclMD6> *__fastcall idDeclMD6::GetDeclInfo(idDeclMD6 *this)
{
  return &idDeclMD6::resourceList;
}

