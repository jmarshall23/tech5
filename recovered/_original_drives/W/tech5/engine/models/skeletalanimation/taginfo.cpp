
// ========================================================================
// ?Equal@idTagInfo@@QBA_NABV1@@Z
// EA  : 0x8285A990
// RVA : 0x0085A990
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idTagInfo::Equal(idTagInfo *this, const idTagInfo *other)
{
  char v2; // r11
  char v3; // r11
  unsigned __int8 v4; // r11

  if ( this->tagData.trans.x != other->tagData.trans.x
    || this->tagData.trans.y != other->tagData.trans.y
    || (v2 = 1, this->tagData.trans.z != other->tagData.trans.z) )
  {
    v2 = 0;
  }
  if ( v2 == 0 )
    return 0;
  if ( this->tagData.rot.x != other->tagData.rot.x
    || this->tagData.rot.y != other->tagData.rot.y
    || this->tagData.rot.z != other->tagData.rot.z
    || (v3 = 1, this->tagData.rot.w != other->tagData.rot.w) )
  {
    v3 = 0;
  }
  if ( v3 == 0 )
    return 0;
  v4 = 1;
  if ( this->tagData.parentJoint.value != other->tagData.parentJoint.value )
    return 0;
  return v4;
}


// ========================================================================
// ?FindJoint@idTagInfo@@QAA?AV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@PBDPBVidDeclMD6@@@Z
// EA  : 0x8285AA48
// RVA : 0x0085AA48
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

idTagInfo *__fastcall idTagInfo::FindJoint(
        idTagInfo *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *result,
        const char *jointName,
        const idDeclMD6 *decl)
{
  ((void (*)(void))animation->FindJointHandle)();
  if ( HIWORD(this->tagName.str) == 0xFFFF )
    idLib::Warning(
      fmt: "%s - joint <%s> not found on tag <%s> for <%s>",
      "idTagInfo::FindJoint",
      jointName,
      *(const char **)&result->value,
      decl->name.str);
  return this;
}


// ========================================================================
// ?Write@idTagInfo@@QBAXAAVidFile_String@@PBD@Z
// EA  : 0x8285AAB8
// RVA : 0x0085AAB8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idTagInfo::Write(idTagInfo *this, idFile_String *file, __int64 indent, __int64 a4, __int64 a5)
{
  unsigned int v7; // r29
  va *v8; // r3
  const char *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  const char *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  int v24; // [sp+8h] [-1068h]
  int v25; // [sp+8h] [-1068h]
  int v26; // [sp+8h] [-1068h]
  int v27; // [sp+8h] [-1068h]
  int v28; // [sp+8h] [-1068h]
  int v29; // [sp+Ch] [-1064h]
  int v30; // [sp+Ch] [-1064h]
  int v31; // [sp+Ch] [-1064h]
  int v32; // [sp+Ch] [-1064h]
  int v33; // [sp+Ch] [-1064h]
  int v34; // [sp+10h] [-1060h]
  int v35; // [sp+10h] [-1060h]
  int v36; // [sp+10h] [-1060h]
  int v37; // [sp+10h] [-1060h]
  int v38; // [sp+10h] [-1060h]
  int v39; // [sp+14h] [-105Ch]
  int v40; // [sp+14h] [-105Ch]
  int v41; // [sp+14h] [-105Ch]
  int v42; // [sp+14h] [-105Ch]
  int v43; // [sp+14h] [-105Ch]
  int v44; // [sp+18h] [-1058h]
  int v45; // [sp+18h] [-1058h]
  int v46; // [sp+18h] [-1058h]
  int v47; // [sp+18h] [-1058h]
  int v48; // [sp+18h] [-1058h]
  int v49; // [sp+1Ch] [-1054h]
  int v50; // [sp+1Ch] [-1054h]
  int v51; // [sp+1Ch] [-1054h]
  int v52; // [sp+1Ch] [-1054h]
  int v53; // [sp+1Ch] [-1054h]
  double y; // [sp+30h] [-1040h]
  double z; // [sp+38h] [-1038h]
  double w; // [sp+40h] [-1030h]
  va v57; // [sp+50h] [-1020h] BYREF

  LODWORD(indent) = this->tagName.str;
  v7 = HIDWORD(indent);
  v8 = va::va(
         this: &v57,
         fmt: "%stag \"%s\" {\n",
         a3: indent,
         a4,
         a5,
         a6: v24,
         a7: v29,
         a8: v34,
         a9: v39,
         a10: v44,
         a11: v49);
  idFile_String::operator+=(this: file, str: v8->buffer);
  v9 = idVec3::ToString(this: (idAngles *)&this->tagData, precision: 4);
  LODWORD(v10) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  v12 = va::va(
          this: &v57,
          fmt: "%s\ttrans ( %s )\n",
          a3: __SPAIR64__(v7, (unsigned int)v9),
          a4: v11,
          a5: v10,
          a6: v25,
          a7: v30,
          a8: v35,
          a9: v40,
          a10: v45,
          a11: v50);
  idFile_String::operator+=(this: file, str: v12->buffer);
  w = this->tagData.rot.w;
  HIDWORD(v13) = LODWORD(w);
  z = this->tagData.rot.z;
  LODWORD(v14) = LODWORD(z);
  y = this->tagData.rot.y;
  HIDWORD(v14) = LODWORD(y);
  v15 = va::va(
          this: &v57,
          fmt: "%s\trot ( %g %g %g %g )\n",
          a3: COERCE__INT64(this->tagData.rot.x),
          a4: v14,
          a5: v13,
          a6: v26,
          a7: v31,
          a8: v36,
          a9: v41,
          a10: v46,
          a11: v51);
  idFile_String::operator+=(this: file, str: v15->buffer);
  v16 = animation->GetJointName(this: animation, a2: &this->tagData.parentJoint);
  v19 = va::va(
          this: &v57,
          fmt: "%s\tparent \"%s\"\n",
          a3: __SPAIR64__(v7, (unsigned int)v16),
          a4: v18,
          a5: v17,
          a6: v27,
          a7: v32,
          a8: v37,
          a9: v42,
          a10: v47,
          a11: v52);
  idFile_String::operator+=(this: file, str: v19->buffer);
  HIDWORD(v20) = v7;
  v23 = va::va(
          this: &v57,
          fmt: "%s}\n",
          a3: v20,
          a4: v22,
          a5: v21,
          a6: v28,
          a7: v33,
          a8: v38,
          a9: v43,
          a10: v48,
          a11: v53);
  idFile_String::operator+=(this: file, str: v23->buffer);
}


// ========================================================================
// ?Equal@idPropInfo@@QBA_NABV1@@Z
// EA  : 0x8285ABE0
// RVA : 0x0085ABE0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idPropInfo::Equal(idPropInfo *this, const idPropInfo *other)
{
  int num; // r28
  const idPropInfo *v4; // r5
  int v5; // r29
  int v6; // r31
  int i; // r7
  char v8; // r6
  int v9; // r9
  int v10; // r11
  idTagInfo *list; // r8
  idTagInfo *v12; // r3

  num = this->tags.num;
  v4 = other;
  v5 = 0;
  if ( num <= 0 )
    return 1;
  v6 = other->tags.num;
  for ( i = 0; ; ++i )
  {
    v8 = 0;
    v9 = 0;
    if ( v6 > 0 )
    {
      v10 = 0;
      list = v4->tags.list;
      v12 = &this->tags.list[i];
      while ( v12->tagName.str != list[v10].tagName.str )
      {
        ++v9;
        ++v10;
        if ( v9 >= v6 )
          goto LABEL_10;
      }
      if ( (unsigned __int8)idTagInfo::Equal(this: v12, other: &list[v9]) == 0 )
        break;
      v8 = 1;
    }
LABEL_10:
    if ( v8 == 0 )
      return 0;
    if ( ++v5 >= num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?Parse@idTagInfo@@QAAHAAVidParser@@PBVidDeclMD6@@@Z
// EA  : 0x8285ACB0
// RVA : 0x0085ACB0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idTagInfo::Parse(idTagInfo *this, idParser *src, const idDeclMD6 *decl)
{
  idQuat *p_rot; // r30
  tagData_t *p_tagData; // r18
  double x; // fp11
  double z; // fp10
  double w; // fp9
  double v13; // fp2
  double v14; // fp5
  double v15; // fp2
  idTagInfo v17; // [sp+50h] [-F0h] BYREF
  int v18; // [sp+80h] [-C0h]
  int v19; // [sp+84h] [-BCh]
  int v20; // [sp+94h] [-ACh]
  float v21; // [sp+98h] [-A8h]
  int v22; // [sp+9Ch] [-A4h]
  int v23; // [sp+A0h] [-A0h]
  int v24; // [sp+A4h] [-9Ch]

  v17.tagData.rot.x = 0.0;
  this->tagData.trans.x = 0.0;
  this->tagData.trans.y = 0.0;
  p_rot = &this->tagData.rot;
  this->tagData.trans.z = 0.0;
  p_tagData = &this->tagData;
  this->tagData.rot.x = 0.0;
  LODWORD(v17.tagData.rot.z) = 20;
  this->tagData.rot.y = 0.0;
  LODWORD(v17.tagData.rot.y) = &v17.tagData.rot.w;
  this->tagData.rot.z = 0.0;
  HIBYTE(v17.tagData.rot.w) = 0;
  this->tagData.rot.w = 0.0;
  v20 = 0;
  v21 = -3.4028235e38;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v17.tagData.rot);
  idAtomicString::Set(this: &this->tagName, str_: (const char *const)LODWORD(v17.tagData.rot.y));
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v17.tagData.rot);
  while ( idParser::ReadToken(this: src, token: (idToken *)&v17.tagData.rot) )
  {
    if ( v18 == 5 && v19 == 47 )
      break;
    if ( idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "offset") != 0
      && idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "trans") != 0 )
    {
      if ( idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "quat") != 0
        && idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "rot") != 0 )
      {
        if ( idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "actor_joint") != 0
          && idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "parent") != 0 )
        {
          if ( idStr::Cmp(s1: (const char *)LODWORD(v17.tagData.rot.y), s2: "movemode") != 0 )
            idParser::Error(
              this: src,
              str: "Unknown token '%s' in modeldef '%s'",
              (const char *)LODWORD(v17.tagData.rot.y),
              decl->name.str);
          else
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v17.tagData.rot);
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v17.tagData.rot);
          idStr::ToLower(this: (idStr *)&v17.tagData.rot);
          this->tagData.parentJoint.value = HIWORD(idTagInfo::FindJoint(
                                                     this: &v17,
                                                     result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this,
                                                     jointName: (const char *)LODWORD(v17.tagData.rot.y),
                                                     decl)->tagName.str);
        }
      }
      else
      {
        idParser::Parse1DMatrix(this: src, x: 4, m: &p_rot->x);
        x = p_rot->x;
        z = p_rot->z;
        w = p_rot->w;
        _FP5 = (float)((float)((float)(p_rot->w * p_rot->w)
                             + (float)((float)(p_rot->z * p_rot->z)
                                     + (float)((float)(p_rot->x * p_rot->x) + (float)(p_rot->y * p_rot->y))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f3, f5, f6, f0 }
        v13 = __frsqrte(_FP3);
        v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                            * (float)((float)((float)(p_rot->w * p_rot->w) + (float)((float)(p_rot->z * p_rot->z) + (float)((float)(p_rot->x * p_rot->x) + (float)(p_rot->y * p_rot->y)))) * (float)0.5))
                                                                                    * (float)v13)
                                                                            - (float)1.5)
                                                            * (float)v13)
                                                    * (float)((float)((float)(p_rot->w * p_rot->w)
                                                                    + (float)((float)(p_rot->z * p_rot->z)
                                                                            + (float)((float)(p_rot->x * p_rot->x)
                                                                                    + (float)(p_rot->y * p_rot->y))))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v13
                                                                                    * (float)((float)((float)(p_rot->w * p_rot->w) + (float)((float)(p_rot->z * p_rot->z) + (float)((float)(p_rot->x * p_rot->x) + (float)(p_rot->y * p_rot->y))))
                                                                                            * (float)0.5))
                                                                            * (float)v13)
                                                                    - (float)1.5)
                                                    * (float)v13))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v13
                                                            * (float)((float)((float)(p_rot->w * p_rot->w)
                                                                            + (float)((float)(p_rot->z * p_rot->z)
                                                                                    + (float)((float)(p_rot->x * p_rot->x)
                                                                                            + (float)(p_rot->y * p_rot->y))))
                                                                    * (float)0.5))
                                                    * (float)v13)
                                            - (float)1.5)
                            * (float)v13));
        v15 = (float)((float)-(float)((float)((float)((float)v14
                                                    * (float)((float)((float)(p_rot->w * p_rot->w)
                                                                    + (float)((float)(p_rot->z * p_rot->z)
                                                                            + (float)((float)(p_rot->x * p_rot->x)
                                                                                    + (float)(p_rot->y * p_rot->y))))
                                                            * (float)0.5))
                                            * (float)v14)
                                    - (float)1.5)
                    * (float)v14);
        p_rot->y = p_rot->y
                 * (float)((float)-(float)((float)((float)((float)v14
                                                         * (float)((float)((float)(p_rot->w * p_rot->w)
                                                                         + (float)((float)(p_rot->z * p_rot->z)
                                                                                 + (float)((float)(p_rot->x * p_rot->x)
                                                                                         + (float)(p_rot->y * p_rot->y))))
                                                                 * (float)0.5))
                                                 * (float)v14)
                                         - (float)1.5)
                         * (float)v14);
        p_rot->x = (float)x * (float)v15;
        p_rot->z = (float)z * (float)v15;
        p_rot->w = (float)w * (float)v15;
      }
    }
    else
    {
      idParser::Parse1DMatrix(this: src, x: 3, m: &p_tagData->trans.x);
    }
  }
  idStr::FreeData(this: (idStr *)&v17.tagData.rot);
  return 0;
}


// ========================================================================
// __unwind$220690
// EA  : 0x8285AFB8
// RVA : 0x0085AFB8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_220690()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// ?GetTag@idPropsCollection@@QBAABUtagData_t@@PBD0@Z
// EA  : 0x8285AFE0
// RVA : 0x0085AFE0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

const tagData_t *__fastcall idPropsCollection::GetTag(
        idPropsCollection *this,
        const char *propName,
        const char *tagName)
{
  int v6; // r29
  int v7; // r31
  const tagData_t *result; // r3
  int v9; // r28
  idPropInfo *v10; // r11
  int v11; // r31
  int v12; // r29

  v6 = 0;
  if ( this->props.num <= 0 )
    goto LABEL_5;
  v7 = 0;
  while ( idStr::Icmp(s1: this->props.list[v7].propName.data, s2: propName) != 0 )
  {
    ++v6;
    ++v7;
    if ( v6 >= this->props.num )
      goto LABEL_5;
  }
  v9 = v6;
  v10 = &this->props.list[v6];
  v11 = 0;
  if ( v10->tags.num <= 0 )
  {
LABEL_5:
    result = &blank;
    if ( (_S13_21 & 1) == 0 )
    {
      _S13_21 |= 1u;
      blank.parentJoint.value = -1;
      blank.trans.x = 0.0;
      blank.trans.y = 0.0;
      blank.trans.z = 0.0;
      blank.rot.x = 0.0;
      blank.rot.y = 0.0;
      blank.rot.z = 0.0;
      blank.rot.w = 0.0;
    }
  }
  else
  {
    v12 = 0;
    while ( idStr::Icmp(s1: v10->tags.list[v12].tagName.str, s2: tagName) != 0 )
    {
      ++v11;
      ++v12;
      v10 = &this->props.list[v9];
      if ( v11 >= v10->tags.num )
        goto LABEL_5;
    }
    return &this->props.list[v9].tags.list[v11].tagData;
  }
  return result;
}


// ========================================================================
// ?GetTagByIndices@idPropsCollection@@QBAABUtagData_t@@HH@Z
// EA  : 0x8285B118
// RVA : 0x0085B118
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

const tagData_t *__fastcall idPropsCollection::GetTagByIndices(idPropsCollection *this, int propIndex, int tagIndex)
{
  idPropInfo *v3; // r11
  const tagData_t *result; // r3

  if ( propIndex >= 0 && propIndex < this->props.num )
  {
    v3 = &this->props.list[propIndex];
    if ( tagIndex >= 0 && tagIndex < v3->tags.num )
      return &v3->tags.list[tagIndex].tagData;
  }
  result = &blank_0;
  if ( (_S14_4 & 1) == 0 )
  {
    _S14_4 |= 1u;
    blank_0.parentJoint.value = -1;
    blank_0.trans.x = 0.0;
    blank_0.trans.y = 0.0;
    blank_0.trans.z = 0.0;
    blank_0.rot.x = 0.0;
    blank_0.rot.y = 0.0;
    blank_0.rot.z = 0.0;
    blank_0.rot.w = 0.0;
  }
  return result;
}


// ========================================================================
// ?FindProp@idPropsCollection@@QBAPBVidPropInfo@@PBD@Z
// EA  : 0x8285B1C0
// RVA : 0x0085B1C0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

const idPropInfo *__fastcall idPropsCollection::FindProp(idPropsCollection *this, const char *propName)
{
  int v4; // r29
  int i; // r30

  v4 = 0;
  if ( this->props.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->props.list[i].propName.data, s2: propName) != 0; ++i )
  {
    if ( ++v4 >= this->props.num )
      return nullptr;
  }
  return &this->props.list[v4];
}


// ========================================================================
// ?FindPropIndex@idPropsCollection@@QBAHPBD@Z
// EA  : 0x8285B238
// RVA : 0x0085B238
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idPropsCollection::FindPropIndex(idPropsCollection *this, const char *propName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->props.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->props.list[i].propName.data, s2: propName) != 0; ++i )
  {
    if ( ++v4 >= this->props.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?FindTag@idPropsCollection@@QBAPBVidTagInfo@@HPBD@Z
// EA  : 0x8285B2A8
// RVA : 0x0085B2A8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

const idTagInfo *__fastcall idPropsCollection::FindTag(idPropsCollection *this, int propIdx, const char *tagName)
{
  idPropInfo *v4; // r31
  int v5; // r30
  int i; // r29

  if ( tagName == nullptr )
    return nullptr;
  if ( *tagName == 0 )
    return nullptr;
  v4 = &this->props.list[propIdx];
  if ( v4 == nullptr )
    return nullptr;
  v5 = 0;
  if ( v4->tags.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: v4->tags.list[i].tagName.str, s2: tagName) != 0; ++i )
  {
    if ( ++v5 >= v4->tags.num )
      return nullptr;
  }
  return &v4->tags.list[v5];
}


// ========================================================================
// ?FindTagIndex@idPropsCollection@@QBAHHPBD@Z
// EA  : 0x8285B348
// RVA : 0x0085B348
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idPropsCollection::FindTagIndex(idPropsCollection *this, int propIdx, const char *tagName)
{
  idPropInfo *v4; // r31
  int v5; // r29
  int i; // r30

  if ( tagName == nullptr )
    return -1;
  if ( *tagName == 0 )
    return -1;
  v4 = &this->props.list[propIdx];
  if ( v4 == nullptr )
    return -1;
  v5 = 0;
  if ( v4->tags.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: v4->tags.list[i].tagName.str, s2: tagName) != 0; ++i )
  {
    if ( ++v5 >= v4->tags.num )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?Write@idPropInfo@@QBAXAAVidFile_String@@PBDPBVidPropsCollection@@@Z
// EA  : 0x8285B3E0
// RVA : 0x0085B3E0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idPropInfo::Write(
        idPropInfo *this,
        idFile_String *file,
        __int64 otherCollection,
        __int64 a4,
        __int64 a5)
{
  const char *v5; // r25
  idPropsCollection *v8; // r30
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  const idPropInfo *Prop; // r28
  int v14; // r27
  int v15; // r30
  int v16; // r11
  idTagInfo *v17; // r3
  va *v18; // r3
  unsigned int i; // r5
  int v20; // [sp+8h] [-10B8h]
  int v21; // [sp+8h] [-10B8h]
  int v22; // [sp+Ch] [-10B4h]
  int v23; // [sp+Ch] [-10B4h]
  int v24; // [sp+10h] [-10B0h]
  int v25; // [sp+10h] [-10B0h]
  int v26; // [sp+14h] [-10ACh]
  int v27; // [sp+14h] [-10ACh]
  int v28; // [sp+18h] [-10A8h]
  int v29; // [sp+18h] [-10A8h]
  int v30; // [sp+1Ch] [-10A4h]
  int v31; // [sp+1Ch] [-10A4h]
  idStr v32; // [sp+50h] [-1070h] BYREF
  int num; // [sp+70h] [-1050h]
  va v34; // [sp+80h] [-1040h] BYREF

  v5 = (const char *)HIDWORD(otherCollection);
  HIDWORD(otherCollection) = this->propName.data;
  v8 = (idPropsCollection *)otherCollection;
  v9 = va::va(
         this: &v34,
         fmt: "\"%s\" {\n",
         a3: otherCollection,
         a4,
         a5,
         a6: v20,
         a7: v22,
         a8: v24,
         a9: v26,
         a10: v28,
         a11: v30);
  idFile_String::operator+=(this: file, str: v9->buffer);
  idStr::idStr(this: &v32, text: v5);
  idStr::EnsureAlloced(this: &v32, amount: v32.len + 2, keepold: true, geometricGrowth: true);
  HIDWORD(v12) = v32.len;
  LODWORD(v10) = v32.data;
  HIDWORD(v11) = 9;
  LODWORD(v12) = 0;
  v32.data[v32.len++] = 9;
  v32.data[v32.len] = 0;
  if ( v8 != nullptr )
    Prop = idPropsCollection::FindProp(this: v8, propName: this->propName.data);
  else
    Prop = nullptr;
  v14 = 0;
  if ( this->tags.num > 0 )
  {
    v15 = 0;
    do
    {
      LODWORD(v10) = 1;
      if ( Prop != nullptr )
      {
        LODWORD(v11) = 0;
        num = Prop->tags.num;
        HIDWORD(v12) = num;
        if ( num > 0 )
        {
          v16 = 0;
          LODWORD(v12) = Prop->tags.list;
          v17 = &this->tags.list[v15];
          HIDWORD(v11) = v17->tagName.str;
          while ( HIDWORD(v11) != *(_DWORD *)(v16 + v12) )
          {
            LODWORD(v11) = v11 + 1;
            v16 += 36;
            if ( (int)v11 >= num )
              goto LABEL_13;
          }
          LODWORD(v11) = (unsigned __int8)idTagInfo::Equal(this: v17, other: (const idTagInfo *)(36 * v11 + v12));
          HIDWORD(v11) = v11 - 1;
          HIDWORD(v12) = ((_DWORD)v11 != 0) - 1;
          LODWORD(v10) = HIDWORD(v12) & v10;
        }
      }
LABEL_13:
      if ( (_BYTE)v10 != 0 )
      {
        HIDWORD(v10) = v32.data;
        idTagInfo::Write(this: &this->tags.list[v15], file, indent: v10, a4: v12, a5: v11);
      }
      ++v14;
      ++v15;
    }
    while ( v14 < this->tags.num );
  }
  HIDWORD(v10) = v5;
  v18 = va::va(
          this: &v34,
          fmt: "%s}\n",
          a3: v10,
          a4: v12,
          a5: v11,
          a6: v21,
          a7: v23,
          a8: v25,
          a9: v27,
          a10: v29,
          a11: v31);
  for ( i = 0; v18->buffer[i] != 0; ++i )
    ;
  file->Write(this: file, a2: v18, a3: i);
  idStr::FreeData(this: &v32);
}


// ========================================================================
// __unwind$221371
// EA  : 0x8285B5AC
// RVA : 0x0085B5AC
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_221371()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?Write@idPropsCollection@@ABAXAAVidFile_String@@PBV1@PBD@Z
// EA  : 0x8285B5E0
// RVA : 0x0085B5E0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idPropsCollection::Write(
        idPropsCollection *this,
        idFile_String *file,
        __int64 indent,
        __int64 a4,
        __int64 a5)
{
  idPropsCollection *v7; // r25
  const char *v8; // r23
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  int v13; // r24
  int v14; // r27
  char *data; // r30
  idPropInfo *Prop; // r3
  const idPropInfo *v17; // r29
  va *v18; // r3
  unsigned int i; // r5
  __int64 v20; // r10
  __int64 v21; // r8
  va *v22; // r3
  unsigned int j; // r5
  int v24; // [sp+8h] [-10C8h]
  int v25; // [sp+8h] [-10C8h]
  int v26; // [sp+Ch] [-10C4h]
  int v27; // [sp+Ch] [-10C4h]
  int v28; // [sp+10h] [-10C0h]
  int v29; // [sp+10h] [-10C0h]
  int v30; // [sp+14h] [-10BCh]
  int v31; // [sp+14h] [-10BCh]
  int v32; // [sp+18h] [-10B8h]
  int v33; // [sp+18h] [-10B8h]
  int v34; // [sp+1Ch] [-10B4h]
  int v35; // [sp+1Ch] [-10B4h]
  idStr v36; // [sp+50h] [-1080h] BYREF
  va v37; // [sp+70h] [-1060h] BYREF

  v7 = (idPropsCollection *)HIDWORD(indent);
  HIDWORD(indent) = indent;
  v8 = (const char *)indent;
  v9 = va::va(
         this: &v37,
         fmt: "%sprops {\n",
         a3: indent,
         a4,
         a5,
         a6: v24,
         a7: v26,
         a8: v28,
         a9: v30,
         a10: v32,
         a11: v34);
  idFile_String::operator+=(this: file, str: v9->buffer);
  idStr::idStr(this: &v36, text: v8);
  idStr::EnsureAlloced(this: &v36, amount: v36.len + 2, keepold: true, geometricGrowth: true);
  HIDWORD(v12) = v36.len;
  LODWORD(v10) = v36.data;
  HIDWORD(v11) = 9;
  LODWORD(v12) = 0;
  v13 = 0;
  v36.data[v36.len++] = 9;
  v36.data[v36.len] = 0;
  if ( this->props.num > 0 )
  {
    v14 = 0;
    do
    {
      if ( v7 == nullptr )
        goto LABEL_8;
      data = this->props.list[v14].propName.data;
      Prop = (idPropInfo *)idPropsCollection::FindProp(this: v7, propName: data);
      v17 = Prop;
      if ( Prop != nullptr )
      {
        Prop = (idPropInfo *)idPropsCollection::FindProp(this, propName: data);
        if ( Prop != nullptr )
          LOBYTE(Prop) = idPropInfo::Equal(this: Prop, other: v17);
      }
      if ( (_BYTE)Prop == 0 )
      {
LABEL_8:
        HIDWORD(v10) = v36.data;
        v18 = va::va(
                this: &v37,
                fmt: "%sprop ",
                a3: v10,
                a4: v12,
                a5: v11,
                a6: v25,
                a7: v27,
                a8: v29,
                a9: v31,
                a10: v33,
                a11: v35);
        for ( i = 0; v18->buffer[i] != 0; ++i )
          ;
        file->Write(this: file, a2: v18, a3: i);
        idPropInfo::Write(
          this: &this->props.list[v14],
          file,
          otherCollection: __SPAIR64__((unsigned int)v36.data, (unsigned int)v7),
          a4: v21,
          a5: v20);
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->props.num );
  }
  HIDWORD(v10) = v8;
  v22 = va::va(
          this: &v37,
          fmt: "%s}\n",
          a3: v10,
          a4: v12,
          a5: v11,
          a6: v25,
          a7: v27,
          a8: v29,
          a9: v31,
          a10: v33,
          a11: v35);
  for ( j = 0; v22->buffer[j] != 0; ++j )
    ;
  file->Write(this: file, a2: v22, a3: j);
  idStr::FreeData(this: &v36);
}


// ========================================================================
// __unwind$221490
// EA  : 0x8285B7B0
// RVA : 0x0085B7B0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_221490()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 80));
}


// ========================================================================
// ??4idPropInfo@@QAAAAV0@ABV0@@Z
// EA  : 0x8285B9C8
// RVA : 0x0085B9C8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

idPropInfo *__fastcall idPropInfo::operator=(idPropInfo *this, const idPropInfo *other)
{
  char *data; // r3
  size_t v5; // r5

  if ( other != this )
  {
    data = this->propName.data;
    v5 = other->propName.len + 1;
    this->propName.len = other->propName.len;
    memcpy(Dst: data, Src: other->propName.data, Size: v5);
    idList<idTagInfo,82>::operator=(this: &this->tags, other: &other->tags);
  }
  return this;
}


// ========================================================================
// ?Write@idPropsCollection@@QBAXAAVidFile_String@@PBVidDeclMD6@@PBD@Z
// EA  : 0x8285BA30
// RVA : 0x0085BA30
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idPropsCollection::Write(
        idPropsCollection *this,
        idFile_String *file,
        const idDeclMD6 *decl,
        const char *indent,
        __int64 a5,
        __int64 a6)
{
  char *data; // r4
  const idDecl *v10; // r3
  __int64 v11; // r6

  data = decl->parent.data;
  if ( data == nullptr
    || (v10 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: data, makeDefault: false),
        HIDWORD(v11) = (char *)v10 + 352,
        v10 == nullptr) )
  {
    HIDWORD(v11) = 0;
  }
  LODWORD(v11) = indent;
  idPropsCollection::Write(this, file, indent: v11, a4: a5, a5: a6);
}


// ========================================================================
// ?Parse@idPropInfo@@QAAHAAVidParser@@PBVidDeclMD6@@@Z
// EA  : 0x8285BD30
// RVA : 0x0085BD30
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idPropInfo::Parse(idPropInfo *this, idParser *src, const idDeclMD6 *decl)
{
  char *data; // r4
  size_t v7; // r5
  char *v8; // r3
  signed int UnsignedIntValue; // r4
  int v10; // r27
  idList<idTagInfo,82> *p_tags; // r30
  int num; // r11
  int size; // r10
  idTagInfo *list; // r10
  idToken v16; // [sp+50h] [-1C0h] BYREF
  idStrStatic<256> v17; // [sp+A0h] [-170h] BYREF

  v16.len = 0;
  v16.allocedAndFlag = 20;
  v16.floatvalue = -3.4028235e38;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  v16.intvalue = 0;
  memset(&v16.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v16);
  idStrStatic<256>::idStrStatic<256>(this: &v17, text: &v16);
  data = v17.data;
  v7 = v17.len + 1;
  v8 = this->propName.data;
  this->propName.len = v17.len;
  memcpy(Dst: v8, Src: data, Size: v7);
  idStr::FreeData(this: &v17);
  if ( idParser::CheckTokenType(this: src, type: 3, subtype: 0, token: &v16) != 0 )
  {
    UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v16);
    if ( UnsignedIntValue > this->tags.size )
      idList<idTagInfo,82>::Resize(this: &this->tags, newsize: UnsignedIntValue);
  }
  v10 = 0;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v16);
  while ( idParser::ReadToken(this: src, token: &v16) )
  {
    if ( v16.type == 5 && v16.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v16.data, s2: "tag") != 0 )
    {
      idParser::Error(
        this: src,
        str: "Unknown token '%s' while parsing prop info for modeldef '%s'",
        v16.data,
        decl->name.str);
    }
    else
    {
      p_tags = &this->tags;
      idList<idTagInfo,82>::PreAllocateWithGranularity(this: &this->tags, newSize: this->tags.num + 1);
      num = this->tags.num;
      size = this->tags.size;
      if ( num >= size )
      {
        v10 += idTagInfo::Parse(this: &p_tags->list[size - 1], src, decl);
      }
      else
      {
        list = p_tags->list;
        this->tags.num = num + 1;
        v10 += idTagInfo::Parse(this: &list[num], src, decl);
      }
    }
  }
  idList<idTagInfo,82>::Resize(this: &this->tags, newsize: this->tags.num);
  idStr::FreeData(this: &v16);
  return v10;
}


// ========================================================================
// __unwind$222244
// EA  : 0x8285BF3C
// RVA : 0x0085BF3C
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_222244()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 80));
}


// ========================================================================
// ??0idPropsCollection@@QAA@XZ
// EA  : 0x8285C2D8
// RVA : 0x0085C2D8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

idPropsCollection *__fastcall idPropsCollection::idPropsCollection(idPropsCollection *this)
{
  this->props.granularity = 0;
  this->props.memTag = 82;
  this->props.listStatic = 0;
  this->props.list = nullptr;
  this->props.size = 0;
  this->props.num = 0;
  return this;
}


// ========================================================================
// ??1idPropsCollection@@QAA@XZ
// EA  : 0x8285C308
// RVA : 0x0085C308
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idPropsCollection::~idPropsCollection(idPropsCollection *this)
{
  char *list; // r3

  if ( this->props.listStatic == 0 || this->props.listStatic == 2 )
  {
    list = (char *)this->props.list;
    if ( this->props.list != nullptr )
      idListArrayDelete<idPropInfo>(ptr: list, num: this->props.size);
    this->props.list = nullptr;
    this->props.size = 0;
  }
  this->props.num = 0;
  if ( this->props.listStatic == 0 || this->props.listStatic == 2 )
  {
    if ( this->props.list != nullptr )
      idListArrayDelete<idPropInfo>(ptr: (char *)this->props.list, num: this->props.size);
    this->props.list = nullptr;
    this->props.size = 0;
  }
  this->props.num = 0;
}


// ========================================================================
// __unwind$222496
// EA  : 0x8285C394
// RVA : 0x0085C394
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_222496()
{
  int v0; // r12

  idList<idPropInfo,82>::Clear(this: *(idList<idPropInfo,82> **)(v0 - 112 + 132));
}


// ========================================================================
// ?DuplicateInherited@idPropsCollection@@QAAXPBV1@@Z
// EA  : 0x8285C3C0
// RVA : 0x0085C3C0
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void __fastcall idPropsCollection::DuplicateInherited(idPropsCollection *this, const idPropsCollection *other)
{
  int v4; // r23
  int v5; // r26
  idPropInfo *v6; // r31
  const idPropInfo *Prop; // r3
  idList<idTagInfo,82> *v8; // r29
  int v9; // r27
  int num; // r28
  int v11; // r30
  int v12; // r10
  int v13; // r11

  v4 = 0;
  if ( other->props.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &other->props.list[v5];
      Prop = idPropsCollection::FindProp(this, propName: v6->propName.data);
      v8 = (idList<idTagInfo,82> *)Prop;
      if ( Prop != nullptr )
      {
        v9 = 0;
        num = Prop->tags.num;
        if ( v6->tags.num > 0 )
        {
          v11 = 0;
          do
          {
            v12 = 0;
            if ( num > 0 )
            {
              v13 = 0;
              do
              {
                if ( v6->tags.list[v11].tagName.str == v8[18].list[v13].tagName.str )
                  break;
                ++v12;
                ++v13;
              }
              while ( v12 < num );
            }
            if ( v12 == num )
              idList<idTagInfo,82>::Append(this: v8 + 18, obj: &v6->tags.list[v11]);
            ++v9;
            ++v11;
          }
          while ( v9 < v6->tags.num );
        }
      }
      else
      {
        idList<idPropInfo,82>::Append(this: &this->props, obj: v6);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < other->props.num );
  }
}


// ========================================================================
// ?Parse@idPropsCollection@@QAAHAAVidParser@@PBVidDeclMD6@@@Z
// EA  : 0x8285C4B8
// RVA : 0x0085C4B8
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

int __fastcall idPropsCollection::Parse(idPropsCollection *this, idParser *src, const idDeclMD6 *decl)
{
  int v6; // r27
  signed int UnsignedIntValue; // r4
  int num; // r11
  int size; // r10
  idPropInfo *list; // r9
  idToken v12[2]; // [sp+50h] [-90h] BYREF

  v12[0].len = 0;
  v12[0].allocedAndFlag = 20;
  v12[0].floatvalue = -3.4028235e38;
  v6 = 0;
  v12[0].data = v12[0].baseBuffer;
  v12[0].baseBuffer[0] = 0;
  v12[0].intvalue = 0;
  v12[0].whiteSpaceStart_p = nullptr;
  v12[0].whiteSpaceEnd_p = nullptr;
  v12[0].next = nullptr;
  if ( idParser::CheckTokenType(this: src, type: 3, subtype: 0, token: v12) != 0 )
  {
    UnsignedIntValue = idToken::GetUnsignedIntValue(this: v12);
    if ( UnsignedIntValue > this->props.size )
      idList<idPropInfo,82>::Resize(this: &this->props, newsize: UnsignedIntValue);
  }
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v12);
  while ( idParser::ReadToken(this: src, token: v12) )
  {
    if ( v12[0].type == 5 && v12[0].subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v12[0].data, s2: "prop") != 0 )
    {
      idParser::Error(
        this: src,
        str: "Unknown token '%s' while loading props collection for modeldef '%s'",
        v12[0].data,
        decl->name.str);
    }
    else
    {
      idList<idPropInfo,82>::PreAllocateWithGranularity(this: &this->props, newSize: this->props.num + 1);
      num = this->props.num;
      size = this->props.size;
      list = this->props.list;
      if ( num >= size )
      {
        v6 += idPropInfo::Parse(this: &list[size - 1], src, decl);
      }
      else
      {
        this->props.num = num + 1;
        v6 += idPropInfo::Parse(this: &list[num], src, decl);
      }
    }
  }
  idList<idPropInfo,82>::Resize(this: &this->props, newsize: this->props.num);
  idStr::FreeData(this: &v12[0]);
  return v6;
}


// ========================================================================
// __unwind$222610
// EA  : 0x8285C668
// RVA : 0x0085C668
// PDB : w:\tech5\engine\models\skeletalanimation\taginfo.cpp
// ========================================================================

void _unwind_222610()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}

