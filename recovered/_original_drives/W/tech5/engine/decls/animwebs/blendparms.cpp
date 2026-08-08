
// ========================================================================
// ?GetDuration@blendParms_t@@QBAFXZ
// EA  : 0x825FDCE0
// RVA : 0x005FDCE0
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

int __fastcall blendParms_t::GetDuration(blendParms_t *this)
{
  return (unsigned __int16)this->parms.destDuration;
}


// ========================================================================
// ?GetDurationMS@blendParms_t@@QBAFXZ
// EA  : 0x825FDCE8
// RVA : 0x005FDCE8
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

int __fastcall blendParms_t::GetDurationMS(blendParms_t *this, int a2, int a3, __int64 a4)
{
  LODWORD(a4) = this->parms.destDuration;
  return (unsigned __int16)(int)(float)((float)((float)a4 * (float)1000.0) * (float)0.033333335);
}


// ========================================================================
// ??0blendParms_t@@QAA@XZ
// EA  : 0x825FDD40
// RVA : 0x005FDD40
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

blendParms_t *__fastcall blendParms_t::blendParms_t(blendParms_t *this)
{
  this->parms.srcAnim = nullptr;
  this->parms.destAnim = nullptr;
  *(_DWORD *)&this->parms.sourceStartFrame = 0x7FFF;
  this->parms.destStartFrame = 0;
  this->parms.destDuration = 0;
  this->parms.flags = 0;
  this->parms.originBlend = 0;
  this->parms.blendType = 0;
  return this;
}


// ========================================================================
// ?Write@blendParms_t@@QBAXAAVidFile_String@@PBD@Z
// EA  : 0x825FDD70
// RVA : 0x005FDD70
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void __fastcall blendParms_t::Write(blendParms_t *this, idFile_String *str, __int64 indent, __int64 a4, __int64 a5)
{
  int v7; // r30
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  const idMD6Anim *destAnim; // r11
  __int64 v16; // r6
  va *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r8
  va *v21; // r3
  __int64 v22; // r8
  __int64 v23; // r6
  __int64 v24; // r10
  va *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r6
  __int64 v32; // r8
  va *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r6
  __int64 v36; // r8
  int v37; // r11
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  va *v41; // r3
  int blendType; // r11
  __int64 v43; // r10
  __int64 v44; // r8
  __int64 v45; // r6
  va *v46; // r3
  va *v47; // r3
  va *v48; // r3
  va *v49; // r3
  int v50; // [sp+8h] [-1078h]
  int v51; // [sp+8h] [-1078h]
  int v52; // [sp+8h] [-1078h]
  int v53; // [sp+8h] [-1078h]
  int v54; // [sp+8h] [-1078h]
  int v55; // [sp+8h] [-1078h]
  int v56; // [sp+8h] [-1078h]
  int v57; // [sp+8h] [-1078h]
  int v58; // [sp+Ch] [-1074h]
  int v59; // [sp+Ch] [-1074h]
  int v60; // [sp+Ch] [-1074h]
  int v61; // [sp+Ch] [-1074h]
  int v62; // [sp+Ch] [-1074h]
  int v63; // [sp+Ch] [-1074h]
  int v64; // [sp+Ch] [-1074h]
  int v65; // [sp+Ch] [-1074h]
  int v66; // [sp+10h] [-1070h]
  int v67; // [sp+10h] [-1070h]
  int v68; // [sp+10h] [-1070h]
  int v69; // [sp+10h] [-1070h]
  int v70; // [sp+10h] [-1070h]
  int v71; // [sp+10h] [-1070h]
  int v72; // [sp+10h] [-1070h]
  int v73; // [sp+10h] [-1070h]
  int v74; // [sp+14h] [-106Ch]
  int v75; // [sp+14h] [-106Ch]
  int v76; // [sp+14h] [-106Ch]
  int v77; // [sp+14h] [-106Ch]
  int v78; // [sp+14h] [-106Ch]
  int v79; // [sp+14h] [-106Ch]
  int v80; // [sp+14h] [-106Ch]
  int v81; // [sp+14h] [-106Ch]
  int v82; // [sp+18h] [-1068h]
  int v83; // [sp+18h] [-1068h]
  int v84; // [sp+18h] [-1068h]
  int v85; // [sp+18h] [-1068h]
  int v86; // [sp+18h] [-1068h]
  int v87; // [sp+18h] [-1068h]
  int v88; // [sp+18h] [-1068h]
  int v89; // [sp+18h] [-1068h]
  int v90; // [sp+1Ch] [-1064h]
  int v91; // [sp+1Ch] [-1064h]
  int v92; // [sp+1Ch] [-1064h]
  int v93; // [sp+1Ch] [-1064h]
  int v94; // [sp+1Ch] [-1064h]
  int v95; // [sp+1Ch] [-1064h]
  int v96; // [sp+1Ch] [-1064h]
  int v97; // [sp+1Ch] [-1064h]
  va v98; // [sp+50h] [-1030h] BYREF

  v7 = HIDWORD(indent);
  v8 = va::va(
         this: &v98,
         fmt: "%sblendParms {\n",
         a3: indent,
         a4,
         a5,
         a6: v50,
         a7: v58,
         a8: v66,
         a9: v74,
         a10: v82,
         a11: v90);
  idFile_String::operator+=(this: str, str: v8->buffer);
  if ( this->parms.srcAnim != nullptr )
    LODWORD(v11) = this->parms.srcAnim->name.str;
  else
    LODWORD(v11) = &byte_8200D768;
  HIDWORD(v11) = v7;
  v12 = va::va(
          this: &v98,
          fmt: "%s\tsrcAnim \"%s\"\n",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v51,
          a7: v59,
          a8: v67,
          a9: v75,
          a10: v83,
          a11: v91);
  idFile_String::operator+=(this: str, str: v12->buffer);
  destAnim = this->parms.destAnim;
  if ( destAnim != nullptr )
    LODWORD(v16) = destAnim->name.str;
  else
    LODWORD(v16) = &byte_8200D768;
  HIDWORD(v16) = v7;
  v17 = va::va(
          this: &v98,
          fmt: "%s\tdestAnim \"%s\"\n",
          a3: v16,
          a4: v14,
          a5: v13,
          a6: v52,
          a7: v60,
          a8: v68,
          a9: v76,
          a10: v84,
          a11: v92);
  idFile_String::operator+=(this: str, str: v17->buffer);
  HIDWORD(v18) = (unsigned __int16)this->parms.sourceStartFrame;
  LODWORD(v18) = &unk_821B0000;
  HIDWORD(v19) = v7;
  LODWORD(v19) = SWORD1(v18);
  v21 = va::va(
          this: &v98,
          fmt: "%s\tsourceStartFrame %d\n",
          a3: v19,
          a4: v20,
          a5: v18,
          a6: v53,
          a7: v61,
          a8: v69,
          a9: v77,
          a10: v85,
          a11: v93);
  idFile_String::operator+=(this: str, str: v21->buffer);
  HIDWORD(v22) = (unsigned __int16)this->parms.sourceDuration;
  LODWORD(v22) = &unk_821B0000;
  HIDWORD(v23) = v7;
  LODWORD(v23) = SWORD1(v22);
  v25 = va::va(
          this: &v98,
          fmt: "%s\tsourceDuration %d\n",
          a3: v23,
          a4: v22,
          a5: v24,
          a6: v54,
          a7: v62,
          a8: v70,
          a9: v78,
          a10: v86,
          a11: v94);
  idFile_String::operator+=(this: str, str: v25->buffer);
  HIDWORD(v26) = v7;
  LODWORD(v26) = this->parms.destStartFrame;
  v29 = va::va(
          this: &v98,
          fmt: "%s\tdestStartFrame %d\n",
          a3: v26,
          a4: v28,
          a5: v27,
          a6: v55,
          a7: v63,
          a8: v71,
          a9: v79,
          a10: v87,
          a11: v95);
  idFile_String::operator+=(this: str, str: v29->buffer);
  HIDWORD(v30) = (unsigned __int16)this->parms.destDuration;
  LODWORD(v30) = &unk_821B0000;
  HIDWORD(v31) = v7;
  LODWORD(v31) = SWORD1(v30);
  v33 = va::va(
          this: &v98,
          fmt: "%s\tdestDuration %d\n",
          a3: v31,
          a4: v32,
          a5: v30,
          a6: v56,
          a7: v64,
          a8: v72,
          a9: v80,
          a10: v88,
          a11: v96);
  idFile_String::operator+=(this: str, str: v33->buffer);
  LODWORD(v36) = (unsigned __int8)this->parms.originBlend;
  v37 = (char)v36;
  if ( (_BYTE)v36 != 0 )
  {
    LODWORD(v38) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
    HIDWORD(v38) = 4 * (char)v36;
    LODWORD(v39) = idMD6Blend::originBlendNames;
    HIDWORD(v39) = &unk_821B0000;
    HIDWORD(v40) = v7;
    LODWORD(v40) = idMD6Blend::originBlendNames[v37];
    v41 = va::va(
            this: &v98,
            fmt: "%s\toriginBlend \"%s\"\n",
            a3: v40,
            a4: v39,
            a5: v38,
            a6: v57,
            a7: v65,
            a8: v73,
            a9: v81,
            a10: v89,
            a11: v97);
    idFile_String::operator+=(this: str, str: v41->buffer);
  }
  blendType = this->parms.blendType;
  if ( this->parms.blendType != 0 )
  {
    LODWORD(v43) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
    HIDWORD(v43) = 4 * blendType;
    LODWORD(v44) = idMD6Branch::blendTypeNames;
    HIDWORD(v44) = &unk_821B0000;
    HIDWORD(v45) = v7;
    LODWORD(v45) = idMD6Branch::blendTypeNames[blendType];
    v46 = va::va(
            this: &v98,
            fmt: "%s\tblendType \"%s\"\n",
            a3: v45,
            a4: v44,
            a5: v43,
            a6: v57,
            a7: v65,
            a8: v73,
            a9: v81,
            a10: v89,
            a11: v97);
    idFile_String::operator+=(this: str, str: v46->buffer);
  }
  if ( (this->parms.flags & 1) != 0 )
  {
    HIDWORD(v35) = v7;
    LODWORD(v34) = this->parms.flags & 1;
    v47 = va::va(
            this: &v98,
            fmt: "%s\tsourceEndRelative\n",
            a3: v35,
            a4: v36,
            a5: v34,
            a6: v57,
            a7: v65,
            a8: v73,
            a9: v81,
            a10: v89,
            a11: v97);
    idFile_String::operator+=(this: str, str: v47->buffer);
  }
  LODWORD(v34) = this->parms.flags & 2;
  if ( (this->parms.flags & 2) != 0 )
  {
    HIDWORD(v35) = v7;
    v48 = va::va(
            this: &v98,
            fmt: "%s\tdestEndRelative\n",
            a3: v35,
            a4: v36,
            a5: v34,
            a6: v57,
            a7: v65,
            a8: v73,
            a9: v81,
            a10: v89,
            a11: v97);
    idFile_String::operator+=(this: str, str: v48->buffer);
  }
  HIDWORD(v35) = v7;
  v49 = va::va(
          this: &v98,
          fmt: "%s}\n",
          a3: v35,
          a4: v36,
          a5: v34,
          a6: v57,
          a7: v65,
          a8: v73,
          a9: v81,
          a10: v89,
          a11: v97);
  idFile_String::operator+=(this: str, str: v49->buffer);
}


// ========================================================================
// ?GetRelativeFrames@blendParms_t@@ABA_NPBVidMD6Anim@@_NABF2AAF3@Z
// EA  : 0x825FDFC8
// RVA : 0x005FDFC8
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

int __fastcall blendParms_t::GetRelativeFrames(
        blendParms_t *this,
        const idMD6Anim *anim,
        const bool endRelative,
        __int16 *inFirstFrame,
        const __int16 *inDuration,
        __int16 *outFirstRelativeFrame,
        __int16 *outLastRelativeFrame)
{
  idMD6AnimData *animData; // r11
  int v9; // r11

  if ( endRelative )
  {
    if ( anim == nullptr )
      return 0;
    animData = anim->animData;
    if ( animData != nullptr )
      LOWORD(animData) = animData->numFrames;
    *outFirstRelativeFrame = (_WORD)animData - *inFirstFrame - 1;
  }
  else
  {
    *outFirstRelativeFrame = *inFirstFrame;
  }
  v9 = *inDuration + *outFirstRelativeFrame;
  if ( v9 >= 0 )
  {
    if ( v9 > 0x7FFF )
      LOWORD(v9) = 0x7FFF;
    *outLastRelativeFrame = v9;
    return 1;
  }
  else
  {
    *outLastRelativeFrame = 0;
    return 1;
  }
}


// ========================================================================
// ?GetSourceFrames@blendParms_t@@QBA_NPBVidMD6Anim@@AAF1@Z
// EA  : 0x825FE058
// RVA : 0x005FE058
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

int __fastcall blendParms_t::GetSourceFrames(
        blendParms_t *this,
        const idMD6Anim *anim,
        __int16 *firstFrame,
        __int16 *lastFrame)
{
  return blendParms_t::GetRelativeFrames(
           this,
           anim,
           endRelative: this->parms.flags & 1,
           inFirstFrame: &this->parms.sourceStartFrame,
           inDuration: &this->parms.sourceDuration,
           outFirstRelativeFrame: firstFrame,
           outLastRelativeFrame: lastFrame);
}


// ========================================================================
// ?GetDestFrames@blendParms_t@@QBA_NPBVidMD6Anim@@AAF1@Z
// EA  : 0x825FE078
// RVA : 0x005FE078
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

int __fastcall blendParms_t::GetDestFrames(
        blendParms_t *this,
        const idMD6Anim *anim,
        __int16 *firstFrame,
        __int16 *duration_)
{
  __int16 v5[4]; // [sp+50h] [-10h] BYREF

  *duration_ = this->parms.destDuration;
  return blendParms_t::GetRelativeFrames(
           this,
           anim,
           endRelative: (this->parms.flags & 2) != 0,
           inFirstFrame: &this->parms.destStartFrame,
           inDuration: &this->parms.destDuration,
           outFirstRelativeFrame: firstFrame,
           outLastRelativeFrame: v5);
}


// ========================================================================
// ?SetDestStartFrame@blendParms_t@@QAAXH@Z
// EA  : 0x825FE0C0
// RVA : 0x005FE0C0
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void __fastcall blendParms_t::SetDestStartFrame(blendParms_t *this, int frame)
{
  if ( frame >= -32767 )
  {
    if ( frame <= 0x7FFF )
      this->parms.destStartFrame = frame;
    else
      this->parms.destStartFrame = 0x7FFF;
  }
  else
  {
    this->parms.destStartFrame = -32767;
  }
}


// ========================================================================
// ?SetDuration@blendParms_t@@QAAXH@Z
// EA  : 0x825FE0F0
// RVA : 0x005FE0F0
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void __fastcall blendParms_t::SetDuration(blendParms_t *this, int frame)
{
  if ( frame >= -32767 )
  {
    if ( frame <= 0x7FFF )
      this->parms.destDuration = frame;
    else
      this->parms.destDuration = 0x7FFF;
  }
  else
  {
    this->parms.destDuration = -32767;
  }
}


// ========================================================================
// ?SetDurationMS@blendParms_t@@QAAXH@Z
// EA  : 0x825FE120
// RVA : 0x005FE120
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void __fastcall blendParms_t::SetDurationMS(blendParms_t *this, unsigned int ms)
{
  int v2; // r11

  v2 = (int)(float)((float)((float)__SPAIR64__(&unk_821B0000, ms) * (float)30.0) * (float)0.001);
  if ( v2 >= -32767 )
  {
    if ( v2 > 0x7FFF )
      LOWORD(v2) = 0x7FFF;
    this->parms.destDuration = v2;
  }
  else
  {
    this->parms.destDuration = -32767;
  }
}


// ========================================================================
// ?Parse@blendParms_t@@QAAXPAVidDeclAnimWeb@@PAVidDeclAnimWebNode@@PBD2AAVidParser@@@Z
// EA  : 0x825FE188
// RVA : 0x005FE188
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void __fastcall blendParms_t::Parse(
        blendParms_t *this,
        idDeclAnimWeb *decl,
        idDeclAnimWebNode *node,
        const char *toSubWebName,
        const char *toStateName,
        idParser *src)
{
  idDeclAnimWeb *v7; // r29
  idDeclAnimWebNode *v8; // r28
  int v10; // r3
  __int16 v11; // r11
  int v12; // r3
  __int16 v13; // r11
  int v14; // r3
  __int16 v15; // r11
  int v16; // r3
  __int16 v17; // r11
  __int64 v18; // r11
  long double v19; // fp2
  long double v20; // fp2
  __int16 v21; // r3
  char v22; // r9
  int v23; // r3
  char v24; // r9
  int v25; // r3
  char v26; // r8
  int v27; // r3
  char flags; // r9
  const char **v29; // r30
  char v30; // r29
  const char **v31; // r30
  char v32; // r29
  char v33; // [sp+50h] [-130h]
  idToken v34; // [sp+90h] [-F0h] BYREF

  v34.len = 0;
  v34.allocedAndFlag = 20;
  v7 = decl;
  v34.floatvalue = -3.4028235e38;
  v8 = node;
  v34.data = v34.baseBuffer;
  v34.baseBuffer[0] = 0;
  v34.intvalue = 0;
  memset(&v34.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v34);
  v33 = 0;
  if ( idParser::ReadToken(this: src, token: &v34) )
  {
    do
    {
      if ( v34.type == 5 && v34.subtype == 47 )
        break;
      if ( idStr::Cmp(s1: v34.data, s2: "srcAnim") != 0 )
      {
        if ( idStr::Cmp(s1: v34.data, s2: "destAnim") != 0 )
        {
          if ( idStr::Cmp(s1: v34.data, s2: "sourceStartFrame") != 0 )
          {
            if ( idStr::Cmp(s1: v34.data, s2: "sourceDuration") != 0 )
            {
              if ( idStr::Cmp(s1: v34.data, s2: "destStartFrame") != 0 )
              {
                if ( idStr::Cmp(s1: v34.data, s2: "destDuration") != 0 )
                {
                  if ( idStr::Cmp(s1: v34.data, s2: "duration") != 0 )
                  {
                    if ( idStr::Cmp(s1: v34.data, s2: "durationf") != 0 )
                    {
                      if ( idStr::Cmp(s1: v34.data, s2: "srcFirstFrame") != 0 )
                      {
                        if ( idStr::Cmp(s1: v34.data, s2: "srcLastFrame") != 0 )
                        {
                          if ( idStr::Cmp(s1: v34.data, s2: "destFrame") != 0 )
                          {
                            if ( idStr::Cmp(s1: v34.data, s2: "originBlend") != 0 )
                            {
                              if ( idStr::Cmp(s1: v34.data, s2: "blendType") != 0 )
                              {
                                if ( idStr::Cmp(s1: v34.data, s2: "sourceEndRelative") != 0 )
                                {
                                  if ( idStr::Cmp(s1: v34.data, s2: "destEndRelative") != 0 )
                                    idParser::Error(this: src, str: "Unknown blendParms parameter '%s'", v34.data);
                                  else
                                    this->parms.flags |= 2u;
                                }
                                else
                                {
                                  this->parms.flags |= 1u;
                                }
                              }
                              else
                              {
                                this->parms.blendType = 4;
                                idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v34);
                                v31 = idMD6Branch::blendTypeNames;
                                v32 = 0;
                                while ( idStr::Cmp(s1: v34.data, s2: *v31) != 0 )
                                {
                                  ++v31;
                                  ++v32;
                                  if ( (int)v31 >= (int)&dword_835BFC0C )
                                    goto LABEL_66;
                                }
                                this->parms.blendType = v32;
LABEL_66:
                                if ( this->parms.blendType == 4 )
                                  idParser::Error(this: src, str: "Unknown blend type '%s'", v34.data);
                              }
                            }
                            else
                            {
                              this->parms.originBlend = 3;
                              idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v34);
                              v29 = idMD6Blend::originBlendNames;
                              v30 = 0;
                              while ( idStr::Cmp(s1: v34.data, s2: *v29) != 0 )
                              {
                                ++v29;
                                ++v30;
                                if ( (int)v29 >= (int)&unk_835BFAF4 )
                                  goto LABEL_58;
                              }
                              this->parms.originBlend = v30;
LABEL_58:
                              if ( this->parms.originBlend == 3 )
                                idParser::Error(this: src, str: "Unknown origin blend type '%s'", v34.data);
                            }
                          }
                          else
                          {
                            v27 = idParser::ParseInt(this: src);
                            if ( v27 > 0x7FFF )
                              LOWORD(v27) = 0x7FFF;
                            flags = this->parms.flags;
                            this->parms.destStartFrame = v27;
                            this->parms.flags = flags | 8;
                          }
                        }
                        else
                        {
                          v25 = idParser::ParseInt(this: src);
                          if ( v25 > 0x7FFF )
                            LOWORD(v25) = 0x7FFF;
                          v26 = this->parms.flags;
                          this->parms.sourceDuration = v25;
                          v33 = 1;
                          this->parms.flags = v26 | 8;
                        }
                      }
                      else
                      {
                        v23 = idParser::ParseInt(this: src);
                        if ( v23 > 0x7FFF )
                          LOWORD(v23) = 0x7FFF;
                        v24 = this->parms.flags;
                        this->parms.sourceStartFrame = v23;
                        this->parms.flags = v24 | 4;
                      }
                    }
                    else
                    {
                      v21 = idParser::ParseInt(this: src);
                      v22 = this->parms.flags;
                      this->parms.destDuration = v21;
                      this->parms.flags = v22 | 8;
                    }
                  }
                  else
                  {
                    LODWORD(v18) = idParser::ParseInt(this: src);
                    *(double *)&v19 = (float)((float)((float)v18 * (float)0.001) * (float)30.0);
                    v20 = ceil(x: v19);
                    this->parms.flags |= 8u;
                    this->parms.destDuration = (int)(float)*(double *)&v20;
                  }
                }
                else
                {
                  v16 = idParser::ParseInt(this: src);
                  v17 = v16;
                  if ( v16 >= -32767 )
                  {
                    if ( v16 > 0x7FFF )
                      v17 = 0x7FFF;
                    this->parms.destDuration = v17;
                  }
                  else
                  {
                    this->parms.destDuration = -32767;
                  }
                }
              }
              else
              {
                v14 = idParser::ParseInt(this: src);
                v15 = v14;
                if ( v14 >= -32767 )
                {
                  if ( v14 > 0x7FFF )
                    v15 = 0x7FFF;
                  this->parms.destStartFrame = v15;
                }
                else
                {
                  this->parms.destStartFrame = -32767;
                }
              }
            }
            else
            {
              v12 = idParser::ParseInt(this: src);
              v13 = v12;
              if ( v12 >= -32767 )
              {
                if ( v12 > 0x7FFF )
                  v13 = 0x7FFF;
                this->parms.sourceDuration = v13;
              }
              else
              {
                this->parms.sourceDuration = -32767;
              }
            }
          }
          else
          {
            v10 = idParser::ParseInt(this: src);
            v11 = v10;
            if ( v10 >= -32767 )
            {
              if ( v10 > 0x7FFF )
                v11 = 0x7FFF;
              this->parms.sourceStartFrame = v11;
            }
            else
            {
              this->parms.sourceStartFrame = -32767;
            }
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v34);
          this->parms.destAnim = v34.len != 0
                               ? (const idMD6Anim *)idResourceList::Load(
                                                      this: &idMD6Anim::resourceList,
                                                      name: v34.data,
                                                      makeDefault: true,
                                                      skipStaleCheck: false)
                               : nullptr;
        }
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v34);
        this->parms.srcAnim = v34.len != 0
                            ? (const idMD6Anim *)idResourceList::Load(
                                                   this: &idMD6Anim::resourceList,
                                                   name: v34.data,
                                                   makeDefault: true,
                                                   skipStaleCheck: false)
                            : nullptr;
      }
    }
    while ( idParser::ReadToken(this: src, token: &v34) );
    v8 = node;
    v7 = decl;
  }
  if ( v33 != 0 )
    this->parms.sourceDuration -= this->parms.sourceStartFrame;
  idDeclAnimWeb::GetSubWebName(
    this: v7,
    index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v8->subWebIndex.value);
  idDeclAnimWeb::GetStateName(
    this: v7,
    index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8->states.stateIndex[0].value);
  idStr::FreeData(this: &v34);
}


// ========================================================================
// __unwind$219794
// EA  : 0x825FE7F0
// RVA : 0x005FE7F0
// PDB : w:\tech5\engine\decls\animwebs\blendparms.cpp
// ========================================================================

void _unwind_219794()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 144));
}

