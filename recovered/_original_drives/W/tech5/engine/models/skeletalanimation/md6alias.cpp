
// ========================================================================
// ?Write@idMD6Alias@@QBAXPBVidDecl@@AAVidFile_String@@PBD@Z
// EA  : 0x82826648
// RVA : 0x00826648
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

void __fastcall idMD6Alias::Write(idMD6Alias *this, const idDecl *decl, __int64 indent, __int64 a4, __int64 a5)
{
  idFile_String *v6; // r28
  int v7; // r27
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r6
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  va *v20; // r3
  va *v21; // r3
  int v22; // r29
  int v23; // r31
  __int64 v24; // r6
  va *v25; // r3
  unsigned int i; // r5
  va *v27; // r3
  unsigned int j; // r5
  int v29; // [sp+8h] [-1088h]
  int v30; // [sp+8h] [-1088h]
  int v31; // [sp+8h] [-1088h]
  int v32; // [sp+8h] [-1088h]
  int v33; // [sp+Ch] [-1084h]
  int v34; // [sp+Ch] [-1084h]
  int v35; // [sp+Ch] [-1084h]
  int v36; // [sp+Ch] [-1084h]
  int v37; // [sp+10h] [-1080h]
  int v38; // [sp+10h] [-1080h]
  int v39; // [sp+10h] [-1080h]
  int v40; // [sp+10h] [-1080h]
  int v41; // [sp+14h] [-107Ch]
  int v42; // [sp+14h] [-107Ch]
  int v43; // [sp+14h] [-107Ch]
  int v44; // [sp+14h] [-107Ch]
  int v45; // [sp+18h] [-1078h]
  int v46; // [sp+18h] [-1078h]
  int v47; // [sp+18h] [-1078h]
  int v48; // [sp+18h] [-1078h]
  int v49; // [sp+1Ch] [-1074h]
  int v50; // [sp+1Ch] [-1074h]
  int v51; // [sp+1Ch] [-1074h]
  int v52; // [sp+1Ch] [-1074h]
  va v53; // [sp+50h] [-1040h] BYREF

  v6 = (idFile_String *)HIDWORD(indent);
  HIDWORD(indent) = indent;
  v7 = indent;
  v8 = va::va(
         this: &v53,
         fmt: "%salias {\n",
         a3: indent,
         a4,
         a5,
         a6: v29,
         a7: v33,
         a8: v37,
         a9: v41,
         a10: v45,
         a11: v49);
  idFile_String::operator+=(this: v6, str: v8->buffer);
  LODWORD(v9) = &unk_82210000;
  HIDWORD(v10) = v7;
  LODWORD(v10) = this->name.str;
  v12 = va::va(
          this: &v53,
          fmt: "%s\tname \"%s\"\n",
          a3: v10,
          a4: v11,
          a5: v9,
          a6: v30,
          a7: v34,
          a8: v38,
          a9: v42,
          a10: v46,
          a11: v50);
  idFile_String::operator+=(this: v6, str: v12->buffer);
  HIDWORD(v14) = this->flags;
  LODWORD(v15) = BYTE3(v14) & 1;
  if ( (v14 & 0x100000000LL) != 0 )
  {
    HIDWORD(v13) = v7;
    v16 = va::va(
            this: &v53,
            fmt: "%s\tflags {\n",
            a3: v13,
            a4: v15,
            a5: v14,
            a6: v31,
            a7: v35,
            a8: v39,
            a9: v43,
            a10: v47,
            a11: v51);
    idFile_String::operator+=(this: v6, str: v16->buffer);
    LODWORD(v19) = this->flags;
    HIDWORD(v19) = v19 & 1;
    if ( (v19 & 1) != 0 )
    {
      HIDWORD(v18) = v7;
      v20 = va::va(
              this: &v53,
              fmt: "%s\t\tforceLoad\n",
              a3: v18,
              a4: v17,
              a5: v19,
              a6: v32,
              a7: v36,
              a8: v40,
              a9: v44,
              a10: v48,
              a11: v52);
      idFile_String::operator+=(this: v6, str: v20->buffer);
    }
    HIDWORD(v18) = v7;
    v21 = va::va(
            this: &v53,
            fmt: "%s\t}\n",
            a3: v18,
            a4: v17,
            a5: v19,
            a6: v32,
            a7: v36,
            a8: v40,
            a9: v44,
            a10: v48,
            a11: v52);
    idFile_String::operator+=(this: v6, str: v21->buffer);
  }
  v22 = 0;
  if ( this->animRefs.num > 0 )
  {
    v23 = 0;
    do
    {
      HIDWORD(v24) = v7;
      LODWORD(v24) = this->animRefs.list[v23].str;
      v25 = va::va(
              this: &v53,
              fmt: "%s\tanim \"%s\"\n",
              a3: v24,
              a4: v15,
              a5: v14,
              a6: v31,
              a7: v35,
              a8: v39,
              a9: v43,
              a10: v47,
              a11: v51);
      for ( i = 0; v25->buffer[i] != 0; ++i )
        ;
      v6->Write(this: v6, a2: v25, a3: i);
      HIDWORD(v14) = this->animRefs.num;
      ++v22;
      ++v23;
    }
    while ( v22 < SHIDWORD(v14) );
  }
  HIDWORD(v13) = v7;
  v27 = va::va(
          this: &v53,
          fmt: "%s}\n",
          a3: v13,
          a4: v15,
          a5: v14,
          a6: v31,
          a7: v35,
          a8: v39,
          a9: v43,
          a10: v47,
          a11: v51);
  for ( j = 0; v27->buffer[j] != 0; ++j )
    ;
  v6->Write(this: v6, a2: v27, a3: j);
}


// ========================================================================
// ?IsInherited@idMD6Alias@@QBA_NABV1@@Z
// EA  : 0x82826800
// RVA : 0x00826800
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

BOOL __fastcall idMD6Alias::IsInherited(idMD6Alias *this, const idMD6Alias *other)
{
  int num; // r11
  int v6; // r29
  int i; // r31

  num = this->animRefs.num;
  if ( num != other->animRefs.num )
    return false;
  v6 = 0;
  if ( num > 0 )
  {
    for ( i = 0; idStr::Icmp(s1: this->animRefs.list[i].str, s2: other->animRefs.list[i].str) == 0; ++i )
    {
      if ( ++v6 >= this->animRefs.num )
        return (_cntlzw(idStr::Icmp(s1: other->name.str, s2: this->name.str)) & 0x20) != 0;
    }
    return false;
  }
  return (_cntlzw(idStr::Icmp(s1: other->name.str, s2: this->name.str)) & 0x20) != 0;
}


// ========================================================================
// ?LoadAnims@idMD6Alias@@QBAXPBVidDeclMD6@@@Z
// EA  : 0x82826890
// RVA : 0x00826890
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

void __fastcall idMD6Alias::LoadAnims(idMD6Alias *this, const idDeclMD6 *decl)
{
  int v4; // r29
  int num; // r10
  int v6; // r30

  if ( decl != nullptr && decl->model != nullptr )
  {
    v4 = 0;
    num = this->animRefs.num;
    this->flags |= 2u;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        if ( idResourceList::Load(
               this: &idMD6Anim::resourceList,
               name: (char *)this->animRefs.list[v6].str,
               makeDefault: true,
               skipStaleCheck: false) == nullptr )
          idLib::Warning(
            fmt: "Failed to load anim '%s' for alias '%s', model '%s'",
            this->animRefs.list[v6].str,
            this->name.str,
            decl->model->name.str);
        ++v4;
        ++v6;
      }
      while ( v4 < this->animRefs.num );
    }
  }
}


// ========================================================================
// ??0idMD6Alias@@QAA@XZ
// EA  : 0x82826940
// RVA : 0x00826940
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

idMD6Alias *__fastcall idMD6Alias::idMD6Alias(idMD6Alias *this)
{
  this->name.str = &byte_8200D768;
  this->aliasHandle.value = -1;
  this->animRefs.list = nullptr;
  this->animRefs.granularity = 0;
  this->animRefs.memTag = 19;
  this->animRefs.listStatic = 0;
  this->animRefs.size = 0;
  this->animRefs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animRefs);
  return this;
}


// ========================================================================
// ?Parse@idMD6Alias@@QAAXPBVidDecl@@AAVidParser@@AAH@Z
// EA  : 0x828269B0
// RVA : 0x008269B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

void __fastcall idMD6Alias::Parse(idMD6Alias *this, const idDecl *decl, idParser *src, int *loadErrors)
{
  int v4; // r30
  idList<idAtomicStringT<enum md6AnimAtomicString_t>,19> *p_animRefs; // r27
  int i; // r26
  idAtomicString v11[4]; // [sp+50h] [-C0h] BYREF
  idToken v12[2]; // [sp+60h] [-B0h] BYREF

  v4 = 0;
  v12[0].len = 0;
  v12[0].allocedAndFlag = 20;
  v12[0].floatvalue = -3.4028235e38;
  v12[0].data = v12[0].baseBuffer;
  v12[0].baseBuffer[0] = 0;
  v12[0].intvalue = 0;
  v12[0].whiteSpaceStart_p = nullptr;
  v12[0].whiteSpaceEnd_p = nullptr;
  v12[0].next = nullptr;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v12);
  idParser::ExpectTokenString(this: src, string: "name");
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: v12);
  idAtomicString::Set(this: &this->name, str_: v12[0].data);
  this->flags = 0;
  p_animRefs = &this->animRefs;
  if ( this->animRefs.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animRefs);
  this->animRefs.num = __CFADD__(-this->animRefs.size, this->animRefs.size ^ 0x80000000) ? 0 : this->animRefs.size;
  while ( idParser::ReadToken(this: src, token: v12) )
  {
    if ( v12[0].type == 5 && v12[0].subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v12[0].data, s2: "anim") != 0 )
    {
      if ( idStr::Cmp(s1: v12[0].data, s2: "flags") != 0 )
      {
        idParser::Error(this: src, str: "Unknown token '%s'", v12[0].data);
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: v12);
        while ( idParser::ReadToken(this: src, token: v12) )
        {
          if ( v12[0].type == 5 && v12[0].subtype == 47 )
            break;
          if ( idStr::Icmp(s1: v12[0].data, s2: "forceLoad") == 0 )
            this->flags |= 1u;
        }
      }
    }
    else
    {
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: v12);
      idAtomicString::Set(this: v11, str_: v12[0].data);
      idList<idAtomicString,109>::Append(this: (idList<idAtomicString,5> *)&this->animRefs, obj: v11);
    }
  }
  if ( (this->flags & 1) != 0 )
  {
    for ( i = 0; i < this->animRefs.num; ++v4 )
    {
      if ( idResourceList::Load(
             this: &idMD6Anim::resourceList,
             name: (char *)p_animRefs->list[v4].str,
             makeDefault: true,
             skipStaleCheck: false) == nullptr )
      {
        ++*loadErrors;
        idLib::Warning(
          fmt: "Failed to load animation '%s' for alias '%s' while parsing aliases for '%s'.",
          p_animRefs->list[v4].str,
          this->name.str,
          decl->name.str);
      }
      ++i;
    }
  }
  idStr::FreeData(this: &v12[0]);
}


// ========================================================================
// __unwind$219991_0
// EA  : 0x82826C68
// RVA : 0x00826C68
// PDB : w:\tech5\engine\models\skeletalanimation\md6alias.cpp
// ========================================================================

void _unwind_219991_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}

