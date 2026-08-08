
// ========================================================================
// ?SetJointOffset@idJointGroup@@QAAXHVidVec3@@@Z
// EA  : 0x82825C48
// RVA : 0x00825C48
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.h
// ========================================================================

void __fastcall idJointGroup::SetJointOffset(idJointGroup *this, __int64 o)
{
  int v2; // r30
  idVec3 *v4; // r11
  __int64 v5; // [sp+90h] [+20h]
  float v6; // [sp+98h] [+28h]

  v2 = HIDWORD(o)++;
  v5 = o;
  v6 = *((float *)&o + 1);
  if ( SHIDWORD(o) <= this->jointOffsets.num )
    HIDWORD(o) = this->jointOffsets.num;
  idList<idVec3,30>::SetNum(this: &this->jointOffsets, newNum: SHIDWORD(o), initValue: &vec3_origin);
  v4 = &this->jointOffsets.list[v2];
  *(_QWORD *)&v4->x = v5;
  v4->z = v6;
}

