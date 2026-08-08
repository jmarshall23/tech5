
// ========================================================================
// ??1idDeclAnimWebEdge@@UAA@XZ
// EA  : 0x82605AB0
// RVA : 0x00605AB0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void __fastcall idDeclAnimWebEdge::~idDeclAnimWebEdge(idDeclAnimWebEdge *this)
{
  this->__vftable = (idDeclAnimWebEdge_vtbl *)&idDeclAnimWebEdge::`vftable';
}


// ========================================================================
// ??0idDeclAnimWebEdge@@QAA@XZ
// EA  : 0x82605AC0
// RVA : 0x00605AC0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

idDeclAnimWebEdge *__fastcall idDeclAnimWebEdge::idDeclAnimWebEdge(idDeclAnimWebEdge *this)
{
  this->__vftable = (idDeclAnimWebEdge_vtbl *)&idDeclAnimWebEdge::`vftable';
  this->destSubWebIndex.value = -1;
  blendParms_t::blendParms_t(this: &this->blendParms);
  this->customFlags = 0;
  return this;
}


// ========================================================================
// ?Parse@idDeclAnimWebEdge@@QAAXPAVidDeclAnimWeb@@PAVidDeclAnimWebNode@@PAVidEdgeCache@2@AAVidParser@@@Z
// EA  : 0x82605B18
// RVA : 0x00605B18
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void __fastcall idDeclAnimWebEdge::Parse(
        idDeclAnimWebEdge *this,
        idDeclAnimWeb *decl,
        idDeclAnimWebNode *node,
        idDeclAnimWeb::idEdgeCache *edgeCache,
        idParser *src)
{
  const char *SubWebName; // r3
  unsigned __int8 v11; // r23
  int len; // r22
  unsigned __int8 v13; // r11
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v15; // r27
  const enumValueInfo_t *EnumValueInfo; // r3
  char *data; // r5
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v18; // [sp+50h] [-190h] BYREF
  __int16 v19; // [sp+52h] [-18Eh] BYREF
  idStr v20; // [sp+60h] [-180h] BYREF
  int v22; // [sp+84h] [-15Ch]
  idToken v23; // [sp+90h] [-150h] BYREF
  idToken v24; // [sp+E0h] [-100h] BYREF
  idToken v25; // [sp+130h] [-B0h] BYREF

  v23.len = 0;
  v23.allocedAndFlag = 20;
  v23.floatvalue = -3.4028235e38;
  v23.data = v23.baseBuffer;
  v23.baseBuffer[0] = 0;
  v23.intvalue = 0;
  memset(&v23.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v23);
  SubWebName = idDeclAnimWeb::GetSubWebName(
                 this: decl,
                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)node->subWebIndex.value);
  idStr::idStr(this: &v20, text: SubWebName);
  v25.floatvalue = -3.4028235e38;
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  v25.len = 0;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenString(this: src, string: "toState");
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v25);
  v11 = edgeCache->flags & 0xFE;
  if ( idParser::CheckTokenString(this: src, string: "toSubWeb") != 0 )
  {
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v23);
    len = v23.len;
    idStr::EnsureAlloced(this: &v20, amount: v23.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v20.data, Src: v23.data, Size: len);
    v20.data[len] = 0;
    v20.len = len;
  }
  if ( idParser::CheckTokenString(this: src, string: "weightScale") != 0 )
  {
    v22 = (int)(float)(idParser::ParseFloat(this: src, errorFlag: nullptr) * (float)16.0);
    v13 = v22;
    if ( v22 >= 0 )
    {
      if ( v22 > 255 )
        v13 = -1;
    }
    else
    {
      v13 = 0;
    }
    edgeCache->weightScale = v13;
  }
  if ( idParser::CheckTokenString(this: src, string: "randomizeWeight") != 0 )
    v11 |= idParser::ParseBool(this: src);
  if ( idParser::CheckTokenString(this: src, string: "blendParms") != 0 )
    blendParms_t::Parse(this: &this->blendParms, decl, node, toSubWebName: v20.data, toStateName: v25.data, src);
  if ( idParser::CheckTokenString(this: src, string: "customFlags") != 0 )
  {
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "animWebEdgeCustomFlag_t");
    v24.allocedAndFlag = 20;
    v24.floatvalue = -3.4028235e38;
    v15 = EnumInfo;
    v24.data = v24.baseBuffer;
    v24.len = 0;
    v24.baseBuffer[0] = 0;
    v24.intvalue = 0;
    memset(&v24.whiteSpaceStart_p, 0, 12);
    while ( idParser::ReadTokenOnLine(this: src, token: &v24) != 0 )
    {
      if ( v15 != nullptr )
      {
        EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                          this: typeInfoTools,
                          enumInfo: v15,
                          name: v24.data,
                          defaultIfNotFound: false);
        if ( EnumValueInfo != nullptr )
          this->customFlags |= EnumValueInfo->value;
        else
          idLib::Warning(fmt: "unrecognized custom flag '%s'", v24.data);
      }
    }
    idStr::FreeData(this: &v24);
  }
  if ( v25.len != 0 )
  {
    v18.value = -1;
    idDeclAnimWeb::AddNode(
      this: decl,
      subWebName: v20.data,
      stateName: v25.data,
      nodeIndex: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)edgeCache,
      subWebIndex: &this->destSubWebIndex,
      stateIndex: &v18);
  }
  else if ( v20.len != 0 )
  {
    data = v20.data;
    edgeCache->destNodeIndex.value = -1;
    this->destSubWebIndex.value = HIWORD(idDeclAnimWeb::AddSubWeb(
                                           this: (idDeclAnimWeb *)&v19,
                                           result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)decl,
                                           subWebName: data)->__vftable);
  }
  else
  {
    idParser::Error(this: src, str: "idDeclAnimWebEdge: sub-web name cannot be empty.");
  }
  edgeCache->flags = v11;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v23);
  idStr::FreeData(this: &v25);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v23);
}


// ========================================================================
// __unwind$219544
// EA  : 0x82605EA8
// RVA : 0x00605EA8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void _unwind_219544()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$219545
// EA  : 0x82605ED0
// RVA : 0x00605ED0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void _unwind_219545()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 96));
}


// ========================================================================
// __unwind$219546
// EA  : 0x82605EF8
// RVA : 0x00605EF8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void _unwind_219546()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 304));
}


// ========================================================================
// __unwind$219547
// EA  : 0x82605F20
// RVA : 0x00605F20
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void _unwind_219547()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 224));
}


// ========================================================================
// ?Write@idDeclAnimWebEdge@@QBAXPBVidDeclAnimWeb@@PBVidDeclAnimWebNode@@PBVidEdgeCache@2@AAVidFile_String@@PBD@Z
// EA  : 0x82605F50
// RVA : 0x00605F50
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void __fastcall idDeclAnimWebEdge::Write(
        idDeclAnimWebEdge *this,
        const idDeclAnimWeb *decl,
        __int64 edgeCache,
        __int64 indent,
        __int64 a5)
{
  int v7; // r26
  __int16 *v8; // r25
  idFile_String *v9; // r30
  unsigned int v10; // r29
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r3
  const char *StateName; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r8
  __int64 v20; // r6
  const char *SubWebName; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  __int64 v25; // r10
  double v26; // fp0
  va *v27; // r3
  va *v28; // r3
  va *v29; // r3
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r10
  __int64 v34; // r6
  __int64 v35; // r8
  va *v36; // r3
  int v37; // [sp+8h] [-20B8h]
  int v38; // [sp+8h] [-20B8h]
  int v39; // [sp+8h] [-20B8h]
  int v40; // [sp+8h] [-20B8h]
  int v41; // [sp+Ch] [-20B4h]
  int v42; // [sp+Ch] [-20B4h]
  int v43; // [sp+Ch] [-20B4h]
  int v44; // [sp+Ch] [-20B4h]
  int v45; // [sp+10h] [-20B0h]
  int v46; // [sp+10h] [-20B0h]
  int v47; // [sp+10h] [-20B0h]
  int v48; // [sp+10h] [-20B0h]
  int v49; // [sp+14h] [-20ACh]
  int v50; // [sp+14h] [-20ACh]
  int v51; // [sp+14h] [-20ACh]
  int v52; // [sp+14h] [-20ACh]
  int v53; // [sp+18h] [-20A8h]
  int v54; // [sp+18h] [-20A8h]
  int v55; // [sp+18h] [-20A8h]
  int v56; // [sp+18h] [-20A8h]
  int v57; // [sp+1Ch] [-20A4h]
  int v58; // [sp+1Ch] [-20A4h]
  int v59; // [sp+1Ch] [-20A4h]
  int v60; // [sp+1Ch] [-20A4h]
  __int16 v61; // [sp+50h] [-2070h]
  idStr v62; // [sp+60h] [-2060h] BYREF
  va v63; // [sp+80h] [-2040h] BYREF
  va v64; // [sp+1080h] [-1040h] BYREF

  v7 = HIDWORD(edgeCache);
  HIDWORD(edgeCache) = indent;
  v8 = (__int16 *)edgeCache;
  v9 = (idFile_String *)HIDWORD(indent);
  v10 = indent;
  v11 = va::va(
          this: &v63,
          fmt: "%sedge {\n",
          a3: edgeCache,
          a4: indent,
          a5,
          a6: v37,
          a7: v41,
          a8: v45,
          a9: v49,
          a10: v53,
          a11: v57);
  idFile_String::operator+=(this: v9, str: v11->buffer);
  v61 = *v8;
  if ( *v8 == -1 )
  {
    LODWORD(v12) = 0;
  }
  else
  {
    HIDWORD(v12) = decl->nodes.list;
    LODWORD(v13) = 4 * v61;
    LODWORD(v12) = *(_DWORD *)(v13 + HIDWORD(v12));
  }
  if ( v61 >= 0 )
  {
    StateName = idDeclAnimWeb::GetStateName(
                  this: decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)*(unsigned __int16 *)(v12 + 4));
    v15 = va::va(
            this: &v63,
            fmt: "%s\ttoState \"%s\"\n",
            a3: __SPAIR64__(v10, (unsigned int)StateName),
            a4: v18,
            a5: v17,
            a6: v38,
            a7: v42,
            a8: v46,
            a9: v50,
            a10: v54,
            a11: v58);
  }
  else
  {
    HIDWORD(v14) = v10;
    v15 = va::va(
            this: &v63,
            fmt: "%s\ttoState \"\"\n",
            a3: v14,
            a4: v13,
            a5: v12,
            a6: v38,
            a7: v42,
            a8: v46,
            a9: v50,
            a10: v54,
            a11: v58);
  }
  idFile_String::operator+=(this: v9, str: v15->buffer);
  if ( this->destSubWebIndex.value != *(__int16 *)(v7 + 2) )
  {
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: decl,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value);
    v24 = va::va(
            this: &v63,
            fmt: "%s\ttoSubWeb \"%s\"\n",
            a3: __SPAIR64__(v10, (unsigned int)SubWebName),
            a4: v23,
            a5: v22,
            a6: v39,
            a7: v43,
            a8: v47,
            a9: v51,
            a10: v55,
            a11: v59);
    idFile_String::operator+=(this: v9, str: v24->buffer);
  }
  LODWORD(v19) = *((unsigned __int8 *)v8 + 2);
  LODWORD(v25) = &unk_821B0000;
  HIDWORD(v25) = 0x82000000;
  v26 = (float)((float)v19 * (float)0.0625);
  if ( v26 != 1.0 )
  {
    v27 = va::va(
            this: &v63,
            fmt: "%s\tweightScale %g\n",
            a3: __SPAIR64__(v10, LODWORD(v26)),
            a4: v19,
            a5: v25,
            a6: v39,
            a7: v43,
            a8: v47,
            a9: v51,
            a10: v55,
            a11: v59,
            v26);
    idFile_String::operator+=(this: v9, str: v27->buffer);
  }
  LODWORD(v25) = *((_BYTE *)v8 + 3) & 1;
  if ( (*((_BYTE *)v8 + 3) & 1) != 0 )
  {
    HIDWORD(v20) = v10;
    v28 = va::va(
            this: &v63,
            fmt: "%s\trandomizeWeight 1\n",
            a3: v20,
            a4: v19,
            a5: v25,
            a6: v39,
            a7: v43,
            a8: v47,
            a9: v51,
            a10: v55,
            a11: v59);
    idFile_String::operator+=(this: v9, str: v28->buffer);
  }
  HIDWORD(v20) = v10;
  v29 = va::va(
          this: &v63,
          fmt: "%s\t",
          a3: v20,
          a4: v19,
          a5: v25,
          a6: v39,
          a7: v43,
          a8: v47,
          a9: v51,
          a10: v55,
          a11: v59);
  idStr::idStr(this: &v62, text: v29);
  HIDWORD(v30) = v62.data;
  blendParms_t::Write(this: &this->blendParms, str: v9, indent: v30, a4: v32, a5: v31);
  LODWORD(v33) = &unk_821B0000;
  HIDWORD(v34) = v10;
  v36 = va::va(
          this: &v64,
          fmt: "%s}\n",
          a3: v34,
          a4: v35,
          a5: v33,
          a6: v40,
          a7: v44,
          a8: v48,
          a9: v52,
          a10: v56,
          a11: v60);
  idFile_String::operator+=(this: v9, str: v36->buffer);
  idStr::FreeData(this: &v62);
}


// ========================================================================
// __unwind$219837
// EA  : 0x82606154
// RVA : 0x00606154
// PDB : w:\tech5\engine\decls\animwebs\declanimwebedge.cpp
// ========================================================================

void _unwind_219837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8384 + 96));
}

