
// ========================================================================
// ?GetJointGroup@idJointGroupCollection@@QAAPAVidJointGroup@@ABV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@@Z
// EA  : 0x82823F90
// RVA : 0x00823F90
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

const idJointGroup *__fastcall idJointGroupCollection::GetJointGroup(
        idJointGroupCollection *this,
        const idHandle<int,enum invalidJointGroupHandle,0> *handle)
{
  int num; // r7
  int v3; // r10
  idJointGroup **list; // r9
  int i; // r11

  num = this->jointGroups.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->jointGroups.list;
  for ( i = 0; list[i]->handle.value != handle->value; ++i )
  {
    if ( ++v3 >= num )
      return nullptr;
  }
  return list[v3];
}


// ========================================================================
// ?GetJointGroupForName@idJointGroupCollection@@QAAPAVidJointGroup@@W4jointGroup_t@2@PBD@Z
// EA  : 0x82823FE0
// RVA : 0x00823FE0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroup *__fastcall idJointGroupCollection::GetJointGroupForName(
        idJointGroupCollection *this,
        int type,
        const char *name)
{
  char v4; // r11
  int v5; // r28
  idList<idJointGroup *,30> *v6; // r31
  int i; // r30
  idJointGroup *v8; // r29

  if ( type >= 12 || (v4 = 1, type < 0) )
    v4 = 0;
  if ( v4 == 0 )
    return nullptr;
  v5 = 0;
  v6 = &this->jointGroupsByType[type];
  if ( v6->num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v8 = v6->list[i];
    if ( idStr::Icmp(s1: v8->groupName.str, s2: name) == 0 )
      break;
    if ( ++v5 >= v6->num )
      return nullptr;
  }
  return v8;
}


// ========================================================================
// ?GetJointGroupIndex@idJointGroupCollection@@QBAHW4jointGroup_t@idJointGroup@@PBD@Z
// EA  : 0x82824080
// RVA : 0x00824080
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

int __fastcall idJointGroupCollection::GetJointGroupIndex(idJointGroupCollection *this, int type, const char *name)
{
  char v4; // r11
  int v5; // r29
  idList<idJointGroup *,30> *v6; // r31
  int i; // r30

  if ( type >= 12 || (v4 = 1, type < 0) )
    v4 = 0;
  if ( v4 == 0 )
    return -1;
  v5 = 0;
  v6 = &this->jointGroupsByType[type];
  if ( v6->num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: v6->list[i]->groupName.str, s2: name) != 0; ++i )
  {
    if ( ++v5 >= v6->num )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?NumJointGroupsForType@idJointGroupCollection@@QBAHW4jointGroup_t@idJointGroup@@@Z
// EA  : 0x82824120
// RVA : 0x00824120
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

int __fastcall idJointGroupCollection::NumJointGroupsForType(idJointGroupCollection *this, int type)
{
  char v2; // r11

  if ( type >= 12 || (v2 = 1, type < 0) )
    v2 = 0;
  if ( v2 != 0 )
    return this->jointGroupsByType[type].num;
  else
    return 0;
}


// ========================================================================
// ?GetJointGroupForIndex@idJointGroupCollection@@QBAPBVidJointGroup@@W4jointGroup_t@2@H@Z
// EA  : 0x82824160
// RVA : 0x00824160
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

const idJointGroup *__fastcall idJointGroupCollection::GetJointGroupForIndex(
        idJointGroupCollection *this,
        int type,
        int index)
{
  char v3; // r11
  idList<idJointGroup *,30> *v5; // r11
  char v6; // r10

  if ( type >= 12 || (v3 = 1, type < 0) )
    v3 = 0;
  if ( v3 == 0 )
    return nullptr;
  v5 = &this->jointGroupsByType[type];
  if ( index >= v5->num || (v6 = 1, index < 0) )
    v6 = 0;
  if ( v6 != 0 )
    return v5->list[index];
  else
    return nullptr;
}


// ========================================================================
// ?ParseSurfType@idJointGroup@@AAAXAAVidParser@@PBVidDeclMD6@@AAH@Z
// EA  : 0x82824310
// RVA : 0x00824310
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::ParseSurfType(idJointGroup *this, idParser *src, const idDeclMD6 *decl, int *loadErrors)
{
  int v4; // r30
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v9; // r28
  const enumValueInfo_t *values; // r11
  int v11; // r29
  idStr v12; // [sp+50h] [-C0h] BYREF
  idToken v13[2]; // [sp+70h] [-A0h] BYREF

  v4 = 0;
  v13[0].len = 0;
  v13[0].allocedAndFlag = 20;
  v13[0].floatvalue = -3.4028235e38;
  v13[0].data = v13[0].baseBuffer;
  v13[0].baseBuffer[0] = 0;
  v13[0].intvalue = 0;
  v13[0].whiteSpaceStart_p = nullptr;
  v13[0].whiteSpaceEnd_p = nullptr;
  v13[0].next = nullptr;
  idParser::ReadToken(this: src, token: v13);
  EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "surfTypes_t");
  v9 = EnumInfo;
  if ( EnumInfo != nullptr && (values = EnumInfo->values, v11 = 0, values->name != nullptr) )
  {
    while ( 1 )
    {
      idStr::idStr(this: &v12, text: values[v4].name);
      idStr::StripLeading(this: &v12, string: "SURFTYPE_");
      idStr::Replace(this: &v12, old: "_", nw: &byte_8200D768);
      if ( idStr::Icmp(s1: v12.data, s2: v13[0].data) == 0 )
        break;
      idStr::FreeData(this: &v12);
      ++v11;
      values = v9->values;
      v4 = v11;
      if ( values[v11].name == nullptr )
        goto LABEL_5;
    }
    this->args.surfType = v9->values[v4].value;
    idStr::FreeData(this: &v12);
  }
  else
  {
LABEL_5:
    idParser::Warning(this: src, str: "Unknown surface type %s", v13[0].data);
    ++*loadErrors;
  }
  idStr::FreeData(this: &v13[0]);
}


// ========================================================================
// __unwind$221642_0
// EA  : 0x82824464
// RVA : 0x00824464
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_221642_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$221643
// EA  : 0x8282448C
// RVA : 0x0082448C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_221643()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// ?ParseArgs@idJointGroup@@AAAXAAVidParser@@PBVidDeclMD6@@AAH@Z
// EA  : 0x828244C0
// RVA : 0x008244C0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::ParseArgs(idJointGroup *this, idParser *src, const idDeclMD6 *decl, int *loadErrors)
{
  idToken v8[2]; // [sp+50h] [-90h] BYREF

  v8[0].len = 0;
  v8[0].allocedAndFlag = 20;
  v8[0].floatvalue = -3.4028235e38;
  v8[0].data = v8[0].baseBuffer;
  v8[0].baseBuffer[0] = 0;
  v8[0].intvalue = 0;
  v8[0].whiteSpaceStart_p = nullptr;
  v8[0].whiteSpaceEnd_p = nullptr;
  v8[0].next = nullptr;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v8);
  while ( idParser::ReadToken(this: src, token: v8) )
  {
    if ( v8[0].type == 5 && v8[0].subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v8[0].data, s2: "vec3") != 0 )
    {
      if ( idStr::Cmp(s1: v8[0].data, s2: "surfType") != 0 )
      {
        idParser::Warning(
          this: src,
          str: "Unknown token '%s' while parsing args for joint group '%s' in decl '%s'",
          v8[0].data,
          this->groupName.str,
          decl->name.str);
        ++*loadErrors;
      }
      else
      {
        idJointGroup::ParseSurfType(this, src, decl, loadErrors);
      }
    }
    else
    {
      idParser::Parse1DMatrix(this: src, x: 3, m: &this->groupOffset.x);
    }
  }
  idStr::FreeData(this: &v8[0]);
}


// ========================================================================
// __unwind$221754
// EA  : 0x82824614
// RVA : 0x00824614
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_221754()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?WriteArgs@idJointGroup@@ABAXAAVidFile_String@@PBD@Z
// EA  : 0x82824648
// RVA : 0x00824648
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::WriteArgs(idJointGroup *this, idFile_String *file, const char *indent)
{
  int v6; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v11; // r26
  const enumValueInfo_t *values; // r11
  char *v13; // r11
  va *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r8
  va *v21; // r3
  int v22; // [sp+8h] [-10B8h]
  int v23; // [sp+8h] [-10B8h]
  int v24; // [sp+8h] [-10B8h]
  int v25; // [sp+Ch] [-10B4h]
  int v26; // [sp+Ch] [-10B4h]
  int v27; // [sp+Ch] [-10B4h]
  int v28; // [sp+10h] [-10B0h]
  int v29; // [sp+10h] [-10B0h]
  int v30; // [sp+10h] [-10B0h]
  int v31; // [sp+14h] [-10ACh]
  int v32; // [sp+14h] [-10ACh]
  int v33; // [sp+14h] [-10ACh]
  int v34; // [sp+18h] [-10A8h]
  int v35; // [sp+18h] [-10A8h]
  int v36; // [sp+18h] [-10A8h]
  int v37; // [sp+1Ch] [-10A4h]
  int v38; // [sp+1Ch] [-10A4h]
  int v39; // [sp+1Ch] [-10A4h]
  idStr v40; // [sp+50h] [-1070h] BYREF
  va v41; // [sp+70h] [-1050h] BYREF

  if ( this->type == JOINTGROUP_HITTEST && this->args.surfType != 3 )
  {
    v6 = 0;
    v40.len = 0;
    v40.allocedAndFlag = 20;
    v40.data = v40.baseBuffer;
    v40.baseBuffer[0] = 0;
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "surfTypes_t");
    v11 = EnumInfo;
    if ( EnumInfo != nullptr )
    {
      values = EnumInfo->values;
      LODWORD(v7) = values->name;
      if ( values->name != nullptr )
      {
        LODWORD(v8) = &off_82010000;
        HIDWORD(v8) = &unk_821F0000;
        LODWORD(v7) = 0;
        do
        {
          v13 = (char *)values + v7;
          if ( *((_DWORD *)v13 + 1) == this->args.surfType )
          {
            idStr::operator=(this: &v40, text: *(const char **)v13);
            idStr::StripLeading(this: &v40, string: "SURFTYPE_");
            idStr::ReplaceChar(this: &v40, oldChar: 95, newChar: 32);
            idStr::ToWordCase(this: &v40);
            idStr::Replace(this: &v40, old: " ", nw: &byte_8200D768);
          }
          ++v6;
          values = v11->values;
          LODWORD(v7) = 8 * v6;
          HIDWORD(v7) = values[v6].name;
        }
        while ( HIDWORD(v7) != 0 );
      }
    }
    HIDWORD(v9) = indent;
    v14 = va::va(
            this: &v41,
            fmt: "%s\targs {\n",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v22,
            a7: v25,
            a8: v28,
            a9: v31,
            a10: v34,
            a11: v37);
    idFile_String::operator+=(this: file, str: v14->buffer);
    LODWORD(v15) = &unk_82210000;
    v17 = va::va(
            this: &v41,
            fmt: "%s\t\tsurfType %s\n",
            a3: __SPAIR64__((unsigned int)indent, (unsigned int)v40.data),
            a4: v16,
            a5: v15,
            a6: v23,
            a7: v26,
            a8: v29,
            a9: v32,
            a10: v35,
            a11: v38);
    idFile_String::operator+=(this: file, str: v17->buffer);
    HIDWORD(v18) = byte_821B0000;
    HIDWORD(v19) = indent;
    v21 = va::va(
            this: &v41,
            fmt: "%s\t}\n",
            a3: v19,
            a4: v20,
            a5: v18,
            a6: v24,
            a7: v27,
            a8: v30,
            a9: v33,
            a10: v36,
            a11: v39);
    idFile_String::operator+=(this: file, str: v21->buffer);
    idStr::FreeData(this: &v40);
  }
}


// ========================================================================
// __unwind$221847
// EA  : 0x828247C8
// RVA : 0x008247C8
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_221847()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?Write@idJointGroup@@QBAXPBVidDeclMD6@@AAVidFile_String@@PBD@Z
// EA  : 0x828247F0
// RVA : 0x008247F0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idJointGroup::Write(idJointGroup *this, const idDeclMD6 *decl, idFile_String *file, const char *indent)
{
  __int64 v4; // r10
  __int64 v6; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r28
  int v16; // r26
  int v17; // r27
  int v18; // r25
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  char v22; // r11
  va *v23; // r3
  unsigned int i; // r5
  __int64 v25; // r8 OVERLAPPED
  __int64 v26; // r6
  __int64 v27; // r10
  idVec3 *v28; // r11
  __int64 v29; // r8
  va *v30; // r3
  __int64 v31; // r6
  va *v32; // r3
  va *v33; // r3
  va *v34; // r4
  unsigned int j; // r5
  va *v36; // r3
  va *v37; // r3
  unsigned int k; // r5
  int v39; // [sp+8h] [-10C8h]
  int v40; // [sp+8h] [-10C8h]
  int v41; // [sp+8h] [-10C8h]
  int v42; // [sp+Ch] [-10C4h]
  int v43; // [sp+Ch] [-10C4h]
  int v44; // [sp+Ch] [-10C4h]
  int v45; // [sp+10h] [-10C0h]
  int v46; // [sp+10h] [-10C0h]
  int v47; // [sp+10h] [-10C0h]
  int v48; // [sp+14h] [-10BCh]
  int v49; // [sp+14h] [-10BCh]
  int v50; // [sp+14h] [-10BCh]
  int v51; // [sp+18h] [-10B8h]
  int v52; // [sp+18h] [-10B8h]
  int v53; // [sp+18h] [-10B8h]
  int v54; // [sp+1Ch] [-10B4h]
  int v55; // [sp+1Ch] [-10B4h]
  int v56; // [sp+1Ch] [-10B4h]
  double y; // [sp+30h] [-10A0h]
  double z; // [sp+38h] [-1098h]
  va v59; // [sp+50h] [-1080h] BYREF

  LODWORD(v4) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  HIDWORD(v6) = this->groupName.str;
  LODWORD(v6) = idJointGroup::jointGroupNames;
  HIDWORD(v4) = &unk_821C0000;
  HIDWORD(v10) = indent;
  LODWORD(v10) = idJointGroup::jointGroupNames[this->type];
  v11 = va::va(
          this: &v59,
          fmt: "%s%s \"%s\" {\n",
          a3: v10,
          a4: v6,
          a5: v4,
          a6: v39,
          a7: v42,
          a8: v45,
          a9: v48,
          a10: v51,
          a11: v54);
  idFile_String::operator+=(this: file, str: v11->buffer);
  idJointGroup::WriteArgs(this, file, indent);
  v15 = 0;
  if ( this->joints.num > 0 )
  {
    v16 = 0;
    v17 = 0;
    v18 = 0;
    do
    {
      LODWORD(v21) = idDeclMD6::GetJointName(
                       this: decl,
                       idx: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->joints.list[v18].value);
      if ( this->jointOffsets.num > 0 || (v22 = 0, this->jointScalars.num > 0) )
        v22 = 1;
      HIDWORD(v21) = indent;
      if ( v22 != 0 )
      {
        v23 = va::va(
                this: &v59,
                fmt: "%s\t%s {\n",
                a3: v21,
                a4: v20,
                a5: v19,
                a6: v40,
                a7: v43,
                a8: v46,
                a9: v49,
                a10: v52,
                a11: v55);
        for ( i = 0; v23->buffer[i] != 0; ++i )
          ;
        file->Write(this: file, a2: v23, a3: i);
        HIDWORD(v27) = this->jointOffsets.num;
        if ( v15 < SHIDWORD(v27) )
        {
          v28 = &this->jointOffsets.list[v17];
          z = v28->z;
          LODWORD(v29) = LODWORD(z);
          y = v28->y;
          HIDWORD(v29) = LODWORD(y);
          v30 = va::va(
                  this: &v59,
                  fmt: "%s\t\toffset ( %.6f %.6f %.6f )\n",
                  a3: COERCE__INT64(v28->x),
                  a4: v29,
                  a5: v27,
                  a6: v41,
                  a7: v44,
                  a8: v47,
                  a9: v50,
                  a10: v53,
                  a11: v56);
          idFile_String::operator+=(this: file, str: v30->buffer);
        }
        if ( v15 < this->jointScalars.num )
        {
          LODWORD(v27) = 4 * this->type;
          LODWORD(v26) = *(const char **)((char *)idJointGroup::jointGroupScalarNames + v27);
          HIDWORD(v27) = *(unsigned __int8 *)v26;
          if ( *(_BYTE *)v26 != 0 )
          {
            HIDWORD(v31) = indent;
            *(double *)((char *)&v25 + 4) = this->jointScalars.list[v16];
            v32 = va::va(
                    this: &v59,
                    fmt: "%s\t\t%s %.6f\n",
                    a3: v31,
                    a4: v25,
                    a5: v27,
                    a6: v41,
                    a7: v44,
                    a8: v47,
                    a9: v50,
                    a10: v53,
                    a11: v56);
            idFile_String::operator+=(this: file, str: v32->buffer);
          }
        }
        HIDWORD(v26) = indent;
        v33 = va::va(
                this: &v59,
                fmt: "%s\t}\n",
                a3: v26,
                a4: v25,
                a5: v27,
                a6: v41,
                a7: v44,
                a8: v47,
                a9: v50,
                a10: v53,
                a11: v56);
        v34 = v33;
        for ( j = 0; v33->buffer[j] != 0; ++j )
          ;
      }
      else
      {
        v36 = va::va(
                this: &v59,
                fmt: "%s\t%s\n",
                a3: v21,
                a4: v20,
                a5: v19,
                a6: v40,
                a7: v43,
                a8: v46,
                a9: v49,
                a10: v52,
                a11: v55);
        v34 = v36;
        for ( j = 0; v36->buffer[j] != 0; ++j )
          ;
      }
      file->Write(this: file, a2: v34, a3: j);
      ++v15;
      ++v18;
      ++v17;
      ++v16;
    }
    while ( v15 < this->joints.num );
  }
  HIDWORD(v14) = indent;
  v37 = va::va(
          this: &v59,
          fmt: "%s}\n",
          a3: v14,
          a4: v13,
          a5: v12,
          a6: v40,
          a7: v43,
          a8: v46,
          a9: v49,
          a10: v52,
          a11: v55);
  for ( k = 0; v37->buffer[k] != 0; ++k )
    ;
  file->Write(this: file, a2: v37, a3: k);
}


// ========================================================================
// ?GetJointGroupForJoint@idJointGroupCollection@@QBAPBVidJointGroup@@W4jointGroup_t@2@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82824AB8
// RVA : 0x00824AB8
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

const idJointGroup *__fastcall idJointGroupCollection::GetJointGroupForJoint(
        idJointGroupCollection *this,
        int type,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  char v3; // r11
  int v4; // r4
  __int32 v5; // r11
  int *v6; // r11
  int v7; // r31
  int i; // r6
  const idJointGroup *result; // r3
  int v10; // r10
  int v11; // r7
  int v12; // r11

  if ( type >= 12 || (v3 = 1, type < 0) )
    v3 = 0;
  if ( v3 == 0 )
    return nullptr;
  v5 = 16 * (type + 1);
  v4 = 0;
  v6 = (int *)((char *)this + v5);
  v7 = v6[1];
  if ( v7 <= 0 )
    return nullptr;
  for ( i = *v6; ; i += 4 )
  {
    result = *(const idJointGroup **)i;
    v10 = 0;
    v11 = *(_DWORD *)(*(_DWORD *)i + 12);
    if ( v11 > 0 )
    {
      v12 = 0;
      while ( result->joints.list[v12].value != (__int16)jointIndex )
      {
        ++v10;
        ++v12;
        if ( v10 >= v11 )
          goto LABEL_13;
      }
      if ( v10 >= 0 )
        break;
    }
LABEL_13:
    if ( ++v4 >= v7 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetJointGroupHandle@idJointGroupCollection@@QBA?AV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@W4jointGroup_t@idJointGroup@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82824B70
// RVA : 0x00824B70
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroupCollection *__fastcall idJointGroupCollection::GetJointGroupHandle(
        idJointGroupCollection *this,
        idJointGroupCollection *result,
        int type,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  const idJointGroup *JointGroupForJoint; // r3
  idJointGroup **value; // r11

  JointGroupForJoint = idJointGroupCollection::GetJointGroupForJoint(this: result, type, jointIndex);
  if ( JointGroupForJoint != nullptr )
    value = (idJointGroup **)JointGroupForJoint->handle.value;
  else
    value = (idJointGroup **)NULL_JOINT_GROUP.value;
  this->jointGroups.list = value;
  return this;
}


// ========================================================================
// ??0idJointGroup@@AAA@W4jointGroup_t@0@@Z
// EA  : 0x82824C90
// RVA : 0x00824C90
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroup *__fastcall idJointGroup::idJointGroup(idJointGroup *this, idJointGroup::jointGroup_t type_)
{
  this->type = type_;
  this->groupName.str = &byte_8200D768;
  this->joints.list = nullptr;
  this->joints.granularity = 0;
  this->joints.memTag = 30;
  this->joints.listStatic = 0;
  this->joints.size = 0;
  this->joints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  this->jointOffsets.list = nullptr;
  this->jointOffsets.granularity = 0;
  this->jointOffsets.memTag = 30;
  this->jointOffsets.listStatic = 0;
  this->jointOffsets.size = 0;
  this->jointOffsets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointOffsets);
  this->jointScalars.list = nullptr;
  this->jointScalars.granularity = 0;
  this->jointScalars.memTag = 30;
  this->jointScalars.listStatic = 0;
  this->jointScalars.size = 0;
  this->jointScalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointScalars);
  this->handle.value = 0;
  this->args.surfType = 3;
  this->args.active = true;
  this->groupOffset.z = 0.0;
  this->groupOffset.y = 0.0;
  this->groupOffset.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$222386
// EA  : 0x82824D6C
// RVA : 0x00824D6C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222386()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$222387
// EA  : 0x82824D98
// RVA : 0x00824D98
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222387()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// ??0idJointGroup@@AAA@PBDW4jointGroup_t@0@ABV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@@Z
// EA  : 0x82824DD0
// RVA : 0x00824DD0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroup *__fastcall idJointGroup::idJointGroup(
        idJointGroup *this,
        const char *groupName_,
        idJointGroup::jointGroup_t type_,
        const idHandle<int,enum invalidJointGroupHandle,0> *handle_)
{
  int value; // r7

  this->type = type_;
  idAtomicString::Set(this: &this->groupName, str_: groupName_);
  this->joints.list = nullptr;
  this->joints.granularity = 0;
  this->joints.memTag = 30;
  this->joints.listStatic = 0;
  this->joints.size = 0;
  this->joints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  this->jointOffsets.list = nullptr;
  this->jointOffsets.granularity = 0;
  this->jointOffsets.memTag = 30;
  this->jointOffsets.listStatic = 0;
  this->jointOffsets.size = 0;
  this->jointOffsets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointOffsets);
  this->jointScalars.list = nullptr;
  this->jointScalars.granularity = 0;
  this->jointScalars.memTag = 30;
  this->jointScalars.listStatic = 0;
  this->jointScalars.size = 0;
  this->jointScalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointScalars);
  value = handle_->value;
  this->args.surfType = 3;
  this->args.active = true;
  this->handle.value = value;
  this->groupOffset.z = 0.0;
  this->groupOffset.y = 0.0;
  this->groupOffset.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$222437
// EA  : 0x82824EA0
// RVA : 0x00824EA0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222437()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 8));
}


// ========================================================================
// __unwind$222438
// EA  : 0x82824ECC
// RVA : 0x00824ECC
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222438()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// ??0idJointGroup@@AAA@ABV0@ABV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@@Z
// EA  : 0x82824F00
// RVA : 0x00824F00
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroup *__fastcall idJointGroup::idJointGroup(
        idJointGroup *this,
        const idJointGroup *other,
        const idHandle<int,enum invalidJointGroupHandle,0> *handle_)
{
  idList<idIndex<short,enum invalidJointIndex_t>,30> *p_joints; // r27

  p_joints = &this->joints;
  this->groupName.str = &byte_8200D768;
  this->joints.list = nullptr;
  this->joints.granularity = 0;
  this->joints.memTag = 30;
  this->joints.listStatic = 0;
  this->joints.size = 0;
  this->joints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  this->jointOffsets.list = nullptr;
  this->jointOffsets.granularity = 0;
  this->jointOffsets.memTag = 30;
  this->jointOffsets.listStatic = 0;
  this->jointOffsets.size = 0;
  this->jointOffsets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointOffsets);
  this->jointScalars.memTag = 30;
  this->jointScalars.list = nullptr;
  this->jointScalars.granularity = 0;
  this->jointScalars.listStatic = 0;
  this->jointScalars.size = 0;
  this->jointScalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointScalars);
  this->handle = (idHandle<int,enum invalidJointGroupHandle,0>)handle_->value;
  this->type = other->type;
  this->groupName.str = other->groupName.str;
  this->args = other->args;
  idList<idIndex<short,enum invalidJointIndex_t>,30>::operator=(this: p_joints, other: &other->joints);
  idList<idVec3,30>::operator=(
    this: (idList<idVec3,59> *)&this->jointOffsets,
    other: (const idList<idVec3,59> *)&other->jointOffsets);
  idList<float,32>::operator=(
    this: (idList<float,32> *)&this->jointScalars,
    other: (const idList<float,32> *)&other->jointScalars);
  return this;
}


// ========================================================================
// __unwind$222484
// EA  : 0x8282500C
// RVA : 0x0082500C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222484()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 8));
}


// ========================================================================
// __unwind$222485
// EA  : 0x82825038
// RVA : 0x00825038
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222485()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 24));
}


// ========================================================================
// __unwind$222486
// EA  : 0x82825064
// RVA : 0x00825064
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222486()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 40));
}


// ========================================================================
// ?Equal@idJointGroup@@QBA_NPBVidDeclMD6@@ABV1@0@Z
// EA  : 0x82825090
// RVA : 0x00825090
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

int __fastcall idJointGroup::Equal(
        idJointGroup *this,
        const idDeclMD6 *myDecl,
        const idJointGroup *other,
        const idDeclMD6 *otherDecl)
{
  int num; // r31
  int v9; // r28
  int i; // r31
  idMD6Skel v12; // [sp+50h] [-40h] BYREF

  if ( this->type == other->type && idStr::Cmp(s1: this->groupName.str, s2: other->groupName.str) == 0 )
  {
    num = this->joints.num;
    if ( num == other->joints.num
      && (unsigned __int8)idList<idVec3,30>::operator==(this: &this->jointOffsets, other: &other->jointOffsets) != 0
      && (unsigned __int8)idList<float,30>::operator==(this: &this->jointScalars, other: &other->jointScalars) != 0
      && this->args.surfType == other->args.surfType )
    {
      v9 = 0;
      if ( num <= 0 )
        return 1;
      for ( i = 0; ; ++i )
      {
        idMD6Skel::GetJointHandle(
          this: (idMD6Skel *)((char *)&v12.__vftable + 2),
          result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)otherDecl->model->skeleton,
          jointIdx: other->joints.list[i].value);
        idMD6Skel::GetJointHandle(
          this: &v12,
          result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)myDecl->model->skeleton,
          jointIdx: this->joints.list[i].value);
        if ( LOWORD(v12.__vftable) != HIWORD(v12.__vftable) )
          break;
        if ( ++v9 >= this->joints.num )
          return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// ??0idJointGroupCollection@@QAA@XZ
// EA  : 0x828251B0
// RVA : 0x008251B0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroupCollection *__fastcall idJointGroupCollection::idJointGroupCollection(idJointGroupCollection *this)
{
  this->jointGroups.list = nullptr;
  this->jointGroups.granularity = 0;
  this->jointGroups.memTag = 30;
  this->jointGroups.listStatic = 0;
  this->jointGroups.size = 0;
  this->jointGroups.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  `eh vector constructor iterator'(
    ptr: this->jointGroupsByType,
    size: 0x10u,
    count: 12,
    pCtor: (void (__fastcall *)(void *))idList<idMD6Blend::jointMod_t,30>::idList<idMD6Blend::jointMod_t,30>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$222623
// EA  : 0x82825230
// RVA : 0x00825230
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222623()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Copy@idJointGroup@@QAAXPBVidDeclMD6@@0ABV1@@Z
// EA  : 0x82825540
// RVA : 0x00825540
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::Copy(
        idJointGroup *this,
        const idDeclMD6 *myDecl,
        const idDeclMD6 *otherDecl,
        const idJointGroup *other)
{
  int v8; // r26
  idList<idIndex<short,enum invalidJointIndex_t>,30> *p_joints; // r23
  int v10; // r28
  const char *JointName; // r3
  const idMD6Model *model; // r11
  const char *v13; // r30
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r4
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  __int16 v16; // [sp+50h] [-60h] BYREF
  idIndex<short,enum invalidUserChannelIndex_t> v17; // [sp+52h] [-5Eh] BYREF
  idMD6Skel v18; // [sp+54h] [-5Ch] BYREF

  v8 = 0;
  this->type = other->type;
  this->groupName.str = other->groupName.str;
  this->args = other->args;
  if ( other->joints.num > 0 )
  {
    p_joints = &this->joints;
    v10 = 0;
    do
    {
      JointName = idDeclMD6::GetJointName(
                    this: otherDecl,
                    idx: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)other->joints.list[v10].value);
      model = myDecl->model;
      v13 = JointName;
      if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
      {
        JointIndex = idMD6Skel::GetJointIndex(this: &v18, result: skeleton, name: JointName);
      }
      else
      {
        JointIndex = (idIndex<short,enum invalidJointIndex_t> *)&v16;
        v16 = -1;
      }
      v17.value = JointIndex->value;
      if ( v17.value < 0 )
        idLib::Warning(
          fmt: "Model '%s' inherits joint group '%s' from model '%s', but joints '%s' is not in child.",
          this->groupName.str,
          other->groupName.str,
          otherDecl->name.str,
          v13);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)p_joints,
        obj: &v17);
      ++v8;
      ++v10;
    }
    while ( v8 < other->joints.num );
  }
  idList<idVec3,30>::operator=(
    this: (idList<idVec3,59> *)&this->jointOffsets,
    other: (const idList<idVec3,59> *)&other->jointOffsets);
  idList<float,32>::operator=(
    this: (idList<float,32> *)&this->jointScalars,
    other: (const idList<float,32> *)&other->jointScalars);
}


// ========================================================================
// ?Free@idJointGroupCollection@@QAAXXZ
// EA  : 0x82825650
// RVA : 0x00825650
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroupCollection::Free(idJointGroupCollection *this)
{
  int *p_num; // r31
  int i; // r30
  void *v4; // r4

  p_num = &this->jointGroups.num;
  for ( i = 12; i != 0; --i )
  {
    if ( *((_BYTE *)p_num + 27) == 0 || *((_BYTE *)p_num + 27) == 2 )
    {
      v4 = (void *)p_num[3];
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      p_num[3] = 0;
      p_num[5] = 0;
    }
    p_num += 4;
    *p_num = 0;
  }
  idList<idJointGroup *,30>::DeleteContents(this: &this->jointGroups);
}


// ========================================================================
// ?Write@idJointGroupCollection@@QBAXAAVidFile_String@@PBVidDeclMD6@@PBD@Z
// EA  : 0x828256D0
// RVA : 0x008256D0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroupCollection::Write(
        idJointGroupCollection *this,
        idFile_String *file,
        __int64 indent,
        __int64 a4,
        __int64 a5)
{
  const char *v6; // r4
  const idDeclMD6 *v8; // r26
  const char *v9; // r20
  const idDeclMD6 *v10; // r23
  idJointGroupCollection *p_jointGroupCollection; // r24
  va *v12; // r3
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  int *p_num; // r27
  int v17; // r21
  int v18; // r25
  int *v19; // r28
  int v20; // r29
  idJointGroup *v21; // r30
  idJointGroup *JointGroupForName; // r3
  va *v23; // r3
  unsigned int i; // r5
  int v25; // [sp+8h] [-10D8h]
  int v26; // [sp+8h] [-10D8h]
  int v27; // [sp+Ch] [-10D4h]
  int v28; // [sp+Ch] [-10D4h]
  int v29; // [sp+10h] [-10D0h]
  int v30; // [sp+10h] [-10D0h]
  int v31; // [sp+14h] [-10CCh]
  int v32; // [sp+14h] [-10CCh]
  int v33; // [sp+18h] [-10C8h]
  int v34; // [sp+18h] [-10C8h]
  int v35; // [sp+1Ch] [-10C4h]
  int v36; // [sp+1Ch] [-10C4h]
  idStr v37; // [sp+50h] [-1090h] BYREF
  va v38; // [sp+70h] [-1070h] BYREF

  v6 = *(const char **)(HIDWORD(indent) + 68);
  v8 = (const idDeclMD6 *)HIDWORD(indent);
  v9 = (const char *)indent;
  if ( v6 == nullptr )
  {
    v10 = nullptr;
    goto LABEL_3;
  }
  v10 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: v6, makeDefault: false);
  p_jointGroupCollection = &v10->jointGroupCollection;
  if ( v10 == nullptr )
LABEL_3:
    p_jointGroupCollection = nullptr;
  HIDWORD(indent) = v9;
  v12 = va::va(
          this: &v38,
          fmt: "%sjointGroups {\n",
          a3: indent,
          a4,
          a5,
          a6: v25,
          a7: v27,
          a8: v29,
          a9: v31,
          a10: v33,
          a11: v35);
  idFile_String::operator+=(this: file, str: v12->buffer);
  idStr::idStr(this: &v37, text: v9);
  idStr::EnsureAlloced(this: &v37, amount: v37.len + 2, keepold: true, geometricGrowth: true);
  HIDWORD(v15) = v37.len;
  LODWORD(v13) = v37.data;
  HIDWORD(v14) = 9;
  LODWORD(v15) = 0;
  p_num = &this->jointGroupsByType[0].num;
  v17 = 12;
  v37.data[v37.len++] = 9;
  v37.data[v37.len] = 0;
  do
  {
    v18 = 0;
    if ( *p_num > 0 )
    {
      v19 = p_num - 5;
      v20 = 0;
      do
      {
        v21 = *(idJointGroup **)(v20 + v19[4]);
        if ( p_jointGroupCollection != nullptr )
        {
          JointGroupForName = idJointGroupCollection::GetJointGroupForName(
                                this: p_jointGroupCollection,
                                type: v21->type,
                                name: v21->groupName.str);
          if ( JointGroupForName != nullptr )
            LOBYTE(JointGroupForName) = idJointGroup::Equal(
                                          this: v21,
                                          myDecl: v8,
                                          other: JointGroupForName,
                                          otherDecl: v10);
        }
        else
        {
          LOBYTE(JointGroupForName) = 0;
        }
        if ( (_BYTE)JointGroupForName == 0 )
          idJointGroup::Write(this: *(idJointGroup **)(v20 + v19[4]), decl: v8, file, indent: v37.data);
        ++v18;
        v20 += 4;
      }
      while ( v18 < *p_num );
    }
    --v17;
    p_num += 4;
  }
  while ( v17 != 0 );
  HIDWORD(v13) = v9;
  v23 = va::va(
          this: &v38,
          fmt: "%s}\n",
          a3: v13,
          a4: v15,
          a5: v14,
          a6: v26,
          a7: v28,
          a8: v30,
          a9: v32,
          a10: v34,
          a11: v36);
  for ( i = 0; v23->buffer[i] != 0; ++i )
    ;
  file->Write(this: file, a2: v23, a3: i);
  idStr::FreeData(this: &v37);
}


// ========================================================================
// __unwind$222942
// EA  : 0x8282589C
// RVA : 0x0082589C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_222942()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 80));
}


// ========================================================================
// ?Condense@idJointGroupCollection@@QAAXXZ
// EA  : 0x828258C8
// RVA : 0x008258C8
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroupCollection::Condense(idJointGroupCollection *this)
{
  idList<idSpawnArea::GeneratedPosition *,5> *jointGroupsByType; // r31
  int i; // r30

  jointGroupsByType = (idList<idSpawnArea::GeneratedPosition *,5> *)this->jointGroupsByType;
  idList<idNavSpline *,5>::Resize((idList<idSpawnArea::GeneratedPosition *,5> *)this, newsize: this->jointGroups.num);
  for ( i = 12; i != 0; --i )
  {
    idList<idNavSpline *,5>::Resize(this: jointGroupsByType, newsize: jointGroupsByType->num);
    ++jointGroupsByType;
  }
}


// ========================================================================
// ?AddJointGroup@idJointGroupCollection@@AAA_NABVidJointGroup@@@Z
// EA  : 0x82825928
// RVA : 0x00825928
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

int __fastcall idJointGroupCollection::AddJointGroup(idJointGroupCollection *this, const idJointGroup *jg)
{
  bool v5; // cr34
  idJointGroup *v6; // r3
  idJointGroup *v7; // r30
  idHandle<int,enum invalidJointGroupHandle,0> v8[12]; // [sp+50h] [-30h] BYREF

  if ( idJointGroupCollection::GetJointGroupForName(this, type: jg->type, name: jg->groupName.str) != nullptr )
    return 0;
  v5 = idJointGroupCollection::curHandle == -1;
  v8[0].value = idJointGroupCollection::curHandle++;
  if ( v5 )
    idJointGroupCollection::curHandle = 1;
  v6 = (idJointGroup *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x50u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v8[1].value = (int)v6;
  if ( v6 != nullptr )
    v7 = idJointGroup::idJointGroup(this: v6, other: jg, handle_: v8);
  else
    v7 = nullptr;
  v8[0].value = (int)v7;
  idList<idAnimWebBlendTree *,5>::Append(
    (idList<enum encounterGroupRole_t,5> *)this,
    obj: (const encounterGroupRole_t *)v8);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->jointGroupsByType[v7->type],
    obj: (const encounterGroupRole_t *)v8);
  return 1;
}


// ========================================================================
// __unwind$223106
// EA  : 0x82825A00
// RVA : 0x00825A00
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall _unwind_223106(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 84), tag: a2);
}


// ========================================================================
// ?AddJointGroup@idJointGroupCollection@@QAAPAVidJointGroup@@PBDW4jointGroup_t@2@@Z
// EA  : 0x82825A30
// RVA : 0x00825A30
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

idJointGroup *__fastcall idJointGroupCollection::AddJointGroup(
        idJointGroupCollection *this,
        const char *groupName,
        __int32 type)
{
  idJointGroup *result; // r3
  bool v7; // cr34
  idJointGroup *v8; // r3
  idJointGroup *v9; // r30
  idHandle<int,enum invalidJointGroupHandle,0> v10[12]; // [sp+50h] [-30h] BYREF

  result = idJointGroupCollection::GetJointGroupForName(this, type, name: groupName);
  if ( result == nullptr )
  {
    v7 = idJointGroupCollection::curHandle == -1;
    v10[0].value = idJointGroupCollection::curHandle++;
    if ( v7 )
      idJointGroupCollection::curHandle = 1;
    v8 = (idJointGroup *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x50u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v10[1].value = (int)v8;
    if ( v8 != nullptr )
      v9 = idJointGroup::idJointGroup(
             this: v8,
             groupName_: groupName,
             type_: (idJointGroup::jointGroup_t)type,
             handle_: v10);
    else
      v9 = nullptr;
    v10[0].value = (int)v9;
    idList<idAnimWebBlendTree *,5>::Append(
      (idList<enum encounterGroupRole_t,5> *)this,
      obj: (const encounterGroupRole_t *)v10);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->jointGroupsByType[v9->type],
      obj: (const encounterGroupRole_t *)v10);
    return v9;
  }
  return result;
}


// ========================================================================
// __unwind$223150
// EA  : 0x82825B08
// RVA : 0x00825B08
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall _unwind_223150(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 84), tag: a2);
}


// ========================================================================
// ?DuplicateInherited@idJointGroupCollection@@QAAXPBVidDecl@@0PBV1@@Z
// EA  : 0x82825B30
// RVA : 0x00825B30
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroupCollection::DuplicateInherited(
        idJointGroupCollection *this,
        const idDeclMD6 *myDecl,
        const idDeclMD6 *parentDecl,
        const idJointGroupCollection *parentCollection)
{
  int v8; // r22
  int v9; // r25
  char v10; // r27
  int v11; // r29
  idJointGroup *v12; // r31
  int v13; // r30
  idJointGroup *v14; // r11
  idJointGroup *v15; // r30

  if ( parentCollection != nullptr )
  {
    v8 = 0;
    if ( parentCollection->jointGroups.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = 0;
        v11 = 0;
        v12 = parentCollection->jointGroups.list[v9];
        if ( this->jointGroups.num > 0 )
        {
          v13 = 0;
          while ( 1 )
          {
            v14 = this->jointGroups.list[v13];
            if ( v14->type == v12->type && idStr::Icmp(s1: v14->groupName.str, s2: v12->groupName.str) == 0 )
              break;
            ++v11;
            ++v13;
            if ( v11 >= this->jointGroups.num )
              goto LABEL_11;
          }
          v10 = 1;
        }
LABEL_11:
        if ( v10 == 0 )
        {
          v15 = idJointGroupCollection::AddJointGroup(this, groupName: v12->groupName.str, type: v12->type);
          if ( myDecl->GetDeclInfo(this: myDecl) == &idDeclMD6::resourceList )
            idJointGroup::Copy(this: v15, myDecl, otherDecl: parentDecl, other: v12);
        }
        ++v8;
        ++v9;
      }
      while ( v8 < parentCollection->jointGroups.num );
    }
  }
}


// ========================================================================
// ?ParseInfo@idJointGroup@@AAAXAAVidParser@@HPBVidDeclMD6@@AAH@Z
// EA  : 0x82825CE0
// RVA : 0x00825CE0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::ParseInfo(
        idJointGroup *this,
        idParser *src,
        int index,
        const idDeclMD6 *decl,
        int *loadErrors)
{
  double v10; // fp1
  int v11; // r11
  double v12; // fp31
  int num; // r4
  double v14; // fp13
  double v15; // fp12
  idVec3 *v16; // r11
  float v17; // [sp+50h] [-F0h] BYREF
  float v18; // [sp+58h] [-E8h] BYREF
  float v19; // [sp+5Ch] [-E4h]
  float v20; // [sp+60h] [-E0h]
  float v21; // [sp+68h] [-D8h]
  float v22; // [sp+6Ch] [-D4h]
  float v23; // [sp+70h] [-D0h]
  idToken v24; // [sp+80h] [-C0h] BYREF

  v24.len = 0;
  v24.allocedAndFlag = 20;
  v24.floatvalue = -3.4028235e38;
  v24.data = v24.baseBuffer;
  v24.baseBuffer[0] = 0;
  v24.intvalue = 0;
  memset(&v24.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v24);
  while ( idParser::ReadToken(this: src, token: &v24) )
  {
    if ( v24.type == 5 && v24.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v24.data, s2: idJointGroup::jointGroupScalarNames[this->type]) != 0 )
    {
      if ( idStr::Cmp(s1: v24.data, s2: "offset") != 0 )
      {
        if ( idStr::Cmp(s1: v24.data, s2: "surfType") != 0 )
        {
          idParser::Warning(
            this: src,
            str: "Unknown token '%s' while parsing joint scalar for joint group '%s', in decl '%s'",
            v24.data,
            this->groupName.str,
            decl->name.str);
          ++*loadErrors;
        }
        else
        {
          idJointGroup::ParseSurfType(this, src, decl, loadErrors);
        }
      }
      else
      {
        v18 = 0.0;
        v19 = 0.0;
        v20 = 0.0;
        idParser::Parse1DMatrix(this: src, x: 3, m: &v18);
        num = this->jointOffsets.num;
        v21 = v18;
        v22 = v19;
        v23 = v20;
        if ( index + 1 > num )
          num = index + 1;
        idList<idVec3,30>::SetNum(this: &this->jointOffsets, newNum: num, initValue: &vec3_origin);
        v14 = v22;
        v15 = v23;
        v16 = &this->jointOffsets.list[index];
        v16->x = v21;
        v16->y = v14;
        v16->z = v15;
      }
    }
    else
    {
      v10 = idParser::ParseFloat(this: src, errorFlag: nullptr);
      v11 = this->jointScalars.num;
      v17 = 1.0;
      v12 = v10;
      if ( index + 1 > v11 )
        v11 = index + 1;
      idList<float,17>::SetNum(this: (idList<float,32> *)&this->jointScalars, newNum: v11, initValue: &v17);
      this->jointScalars.list[index] = v12;
    }
  }
  idStr::FreeData(this: &v24);
}


// ========================================================================
// __unwind$223338
// EA  : 0x82825F44
// RVA : 0x00825F44
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223338()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?Parse@idJointGroup@@QAAXAAVidParser@@PBVidDeclMD6@@AAH@Z
// EA  : 0x82825F78
// RVA : 0x00825F78
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroup::Parse(idJointGroup *this, idParser *src, const idDeclMD6 *decl, int *loadErrors)
{
  idAtomicString *p_groupName; // r24
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  __int16 value; // r27
  int num; // r11
  int size; // r10
  idIndex<short,enum invalidJointIndex_t> *list; // r9
  idIndex<short,enum invalidJointIndex_t> *v15; // r11
  float z; // r10
  __int128 v17; // r6
  __int16 v18; // [sp+50h] [-130h] BYREF
  idIndex<short,enum invalidJointIndex_t> *skeleton; // [sp+54h] [-12Ch]
  idMD6Skel v20; // [sp+58h] [-128h] BYREF
  int v21; // [sp+94h] [-ECh]
  float v22; // [sp+98h] [-E8h]
  int v23; // [sp+9Ch] [-E4h]
  int v24; // [sp+A0h] [-E0h]
  int v25; // [sp+A4h] [-DCh]
  idStr v26; // [sp+B0h] [-D0h] BYREF
  idToken v27[2]; // [sp+D0h] [-B0h] BYREF

  v20.name.str = nullptr;
  v20.resourceListPtr = (idResourceList *)20;
  v22 = -3.4028235e38;
  v20.nextOnHashChain = (idResource *)&v20.resourceError;
  HIBYTE(v20.resourceError) = 0;
  v21 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v27[0].floatvalue = -3.4028235e38;
  v27[0].allocedAndFlag = 20;
  v27[0].data = v27[0].baseBuffer;
  v27[0].len = 0;
  v27[0].baseBuffer[0] = 0;
  v27[0].intvalue = 0;
  v27[0].whiteSpaceStart_p = nullptr;
  v27[0].whiteSpaceEnd_p = nullptr;
  v27[0].next = nullptr;
  p_groupName = &this->groupName;
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v20.name);
  idAtomicString::Set(this: &this->groupName, str_: (const char *const)v20.nextOnHashChain);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v20.name);
  while ( idParser::ReadToken(this: src, token: (idToken *)&v20.name) )
  {
    if ( v20.data == (idMD6SkelData *)5 && v20.timestamp == 47 )
      break;
    if ( idStr::Cmp(s1: (const char *)v20.nextOnHashChain, s2: "args") != 0
      || idParser::PeekTokenType(this: src, type: 5, subtype: 46, token: v27) == 0 )
    {
      idStr::idStr(this: &v26, text: (const idStr *)&v20.name);
      idStr::ToLower(this: &v26);
      model = decl->model;
      if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
      {
        JointIndex = idMD6Skel::GetJointIndex(this: &v20, result: skeleton, name: v26.data);
      }
      else
      {
        JointIndex = (idIndex<short,enum invalidJointIndex_t> *)&v18;
        v18 = -1;
      }
      value = JointIndex->value;
      if ( JointIndex->value >= 0 )
      {
        idList<idIndex<short,enum invalidJointIndex_t>,30>::PreAllocateWithGranularity(
          this: &this->joints,
          newSize: this->joints.num + 1);
        num = this->joints.num;
        size = this->joints.size;
        list = this->joints.list;
        if ( num >= size )
        {
          v15 = &list[size - 1];
        }
        else
        {
          this->joints.num = num + 1;
          v15 = &list[num];
        }
        v15->value = value;
        z = this->groupOffset.z;
        if ( ((LODWORD(z) | LODWORD(this->groupOffset.y) | LODWORD(this->groupOffset.x)) & 0x7FFFFFFF) != 0 )
        {
          *(_QWORD *)((char *)&v17 + 4) = *(_QWORD *)&this->groupOffset.x;
          LODWORD(v17) = __ROL4__(LODWORD(z), 32);
          idJointGroup::SetJointOffset(this, o: v17);
        }
        if ( idParser::PeekTokenType(this: src, type: 5, subtype: 46, token: v27) != 0 )
          idJointGroup::ParseInfo(this, src, index: this->joints.num - 1, decl, loadErrors);
      }
      else
      {
        idLib::Warning(
          fmt: "Invalid joint name '%s' in joint group '%s' for decl '%s'",
          v26.data,
          p_groupName->str,
          decl->name.str);
        if ( idParser::CheckTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v20.name) != 0 )
          idParser::SkipBracedSection(this: src, parseFirstBrace: false);
        ++*loadErrors;
      }
      idStr::FreeData(this: &v26);
    }
    else
    {
      idJointGroup::ParseArgs(this, src, decl, loadErrors);
    }
  }
  idStr::FreeData(this: &v27[0]);
  idStr::FreeData(this: (idStr *)&v20.name);
}


// ========================================================================
// __unwind$223495_0
// EA  : 0x8282625C
// RVA : 0x0082625C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223495_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$223496_0
// EA  : 0x82826284
// RVA : 0x00826284
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223496_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 208));
}


// ========================================================================
// __unwind$223497_0
// EA  : 0x828262AC
// RVA : 0x008262AC
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223497_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 176));
}


// ========================================================================
// ??1idJointGroupCollection@@QAA@XZ
// EA  : 0x828262E0
// RVA : 0x008262E0
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void __fastcall idJointGroupCollection::~idJointGroupCollection(idJointGroupCollection *this)
{
  idJointGroupCollection::Free(this);
  `eh vector destructor iterator'(
    ptr: this->jointGroupsByType,
    size: 0x10u,
    count: 12,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$223713
// EA  : 0x8282633C
// RVA : 0x0082633C
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223713()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$223714
// EA  : 0x82826364
// RVA : 0x00826364
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223714()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 16),
    size: 0x10u,
    count: 12,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?Parse@idJointGroupCollection@@QAAHAAVidParser@@PBVidDeclMD6@@@Z
// EA  : 0x828263A8
// RVA : 0x008263A8
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

int __fastcall idJointGroupCollection::Parse(idJointGroupCollection *this, idParser *src, const idDeclMD6 *decl)
{
  bool v6; // r4
  idJointGroup::jointGroup_t v7; // r30
  char v8; // r29
  idJointGroup::jointGroup_t v9; // r11
  int v11; // [sp+50h] [-140h] BYREF
  idToken v12; // [sp+60h] [-130h] BYREF
  idJointGroup v13[2]; // [sp+B0h] [-E0h] BYREF

  v12.len = 0;
  v12.allocedAndFlag = 20;
  v12.floatvalue = -3.4028235e38;
  v12.data = v12.baseBuffer;
  v12.baseBuffer[0] = 0;
  v11 = 0;
  v12.intvalue = 0;
  memset(&v12.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v12);
  if ( idParser::ReadToken(this: src, token: &v12) )
  {
    while ( 1 )
    {
      if ( v12.type == 5 )
      {
        if ( v12.subtype == 47 )
          goto LABEL_24;
        if ( v12.subtype == 46 )
          break;
      }
      if ( idStr::Cmp(s1: v12.data, s2: "jointGroup") == 0 )
        goto LABEL_23;
      v7 = JOINTGROUP_DAMAGE;
      v8 = 0;
      v9 = JOINTGROUP_DAMAGE;
      while ( idStr::Icmp(s1: v12.data, s2: idJointGroup::jointGroupNames[v9]) != 0
           && (v7 != JOINTGROUP_EYES || idStr::Icmp(s1: v12.data, s2: "misc") != 0) )
      {
        v9 = ++v7;
        if ( v7 >= JOINTGROUP_MAX )
          goto LABEL_14;
      }
      v8 = 1;
      idJointGroup::idJointGroup(this: v13, type_: v7);
      idJointGroup::Parse(this: v13, src, decl, loadErrors: &v11);
      idJointGroupCollection::AddJointGroup(this, jg: v13);
      idProgressionEntity::idProgressionParms::~idProgressionParms(this: (idProgressionEntity::idProgressionParms *)v13);
LABEL_14:
      if ( v8 == 0 )
      {
        if ( idStr::Cmp(s1: v12.data, s2: "radiusDamageGroup") == 0
          || idStr::Cmp(s1: v12.data, s2: "headTrackingIKGroup") == 0
          || idStr::Cmp(s1: v12.data, s2: "reparentGroup") == 0
          || idStr::Cmp(s1: v12.data, s2: "upgradeGroup") == 0
          || idStr::Cmp(s1: v12.data, s2: "autoblendGroup") == 0 )
        {
          v6 = true;
          goto LABEL_22;
        }
        idParser::Warning(
          this: src,
          str: "Unknown token '%s' while parsing joint group collection for modeldef '%s'",
          v12.data,
          decl->name.str);
      }
LABEL_23:
      if ( !idParser::ReadToken(this: src, token: &v12) )
        goto LABEL_24;
    }
    v6 = false;
LABEL_22:
    idParser::SkipBracedSection(this: src, parseFirstBrace: v6);
    goto LABEL_23;
  }
LABEL_24:
  idStr::FreeData(this: &v12);
  return v11;
}


// ========================================================================
// __unwind$223740_0
// EA  : 0x828265F8
// RVA : 0x008265F8
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223740_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$223741
// EA  : 0x82826620
// RVA : 0x00826620
// PDB : w:\tech5\engine\models\skeletalanimation\jointgroup.cpp
// ========================================================================

void _unwind_223741()
{
  int v0; // r12

  idProgressionEntity::idProgressionParms::~idProgressionParms(this: (idProgressionEntity::idProgressionParms *)(v0 - 400 + 176));
}

