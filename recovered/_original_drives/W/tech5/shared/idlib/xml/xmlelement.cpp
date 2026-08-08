
// ========================================================================
// ?FormatStrings_R@idXMLElement@@AAAXPAV1@@Z
// EA  : 0x82FA3F58
// RVA : 0x00FA3F58
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void __fastcall idXMLElement::FormatStrings_R(idXMLElement *this, idXMLElement *element)
{
  int v4; // r30
  int v5; // r29
  int v6; // r22
  int v7; // r30
  idXMLAttribute *v8; // r29
  idStr *p_value; // r29

  v4 = 0;
  if ( element->children.num > 0 )
  {
    v5 = 0;
    do
    {
      idXMLElement::FormatStrings_R(this, element: element->children.list[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < element->children.num );
  }
  idStr::Replace(this: &element->name, old: "&amp;", nw: "&");
  idStr::Replace(this: &element->name, old: "&lt;", nw: "<");
  idStr::Replace(this: &element->name, old: "&gt;", nw: ">");
  idStr::Replace(this: &element->value, old: "&amp;", nw: "&");
  idStr::Replace(this: &element->value, old: "&lt;", nw: "<");
  idStr::Replace(this: &element->value, old: "&gt;", nw: ">");
  v6 = 0;
  if ( element->attributes.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &element->attributes.list[v7];
      idStr::Replace(this: &v8->name, old: "&amp;", nw: "&");
      idStr::Replace(this: &v8->name, old: "&lt;", nw: "<");
      idStr::Replace(this: &v8->name, old: "&gt;", nw: ">");
      p_value = &element->attributes.list[v7].value;
      idStr::Replace(this: p_value, old: "&amp;", nw: "&");
      idStr::Replace(this: p_value, old: "&lt;", nw: "<");
      idStr::Replace(this: p_value, old: "&gt;", nw: ">");
      ++v6;
      ++v7;
    }
    while ( v6 < element->attributes.num );
  }
}


// ========================================================================
// ??0idXMLElement@@QAA@QBD@Z
// EA  : 0x82FA40E8
// RVA : 0x00FA40E8
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

idXMLElement *__fastcall idXMLElement::idXMLElement(idXMLElement *this, char *name)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->value.allocedAndFlag = 20;
  this->value.len = 0;
  this->value.data = this->value.baseBuffer;
  this->value.baseBuffer[0] = 0;
  this->attributes.granularity = 0;
  this->attributes.listStatic = 0;
  this->attributes.memTag = 44;
  this->attributes.list = nullptr;
  this->attributes.size = 0;
  this->attributes.num = 0;
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 44;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  idStr::operator=(this: &this->name, text: name);
  return this;
}


// ========================================================================
// __unwind$111459
// EA  : 0x82FA4194
// RVA : 0x00FA4194
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111459()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$111460
// EA  : 0x82FA41BC
// RVA : 0x00FA41BC
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$111461
// EA  : 0x82FA41E8
// RVA : 0x00FA41E8
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111461()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$111462
// EA  : 0x82FA4214
// RVA : 0x00FA4214
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111462()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// ??0idXMLElement@@QAA@QBD0@Z
// EA  : 0x82FA4248
// RVA : 0x00FA4248
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

idXMLElement *__fastcall idXMLElement::idXMLElement(idXMLElement *this, char *name, char *value)
{
  idStr *p_value; // r29

  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  p_value = &this->value;
  this->value.allocedAndFlag = 20;
  this->value.len = 0;
  this->value.data = this->value.baseBuffer;
  this->value.baseBuffer[0] = 0;
  this->attributes.granularity = 0;
  this->attributes.listStatic = 0;
  this->attributes.memTag = 44;
  this->attributes.list = nullptr;
  this->attributes.size = 0;
  this->attributes.num = 0;
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 44;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  idStr::operator=(this: &this->name, text: name);
  idStr::operator=(this: p_value, text: value);
  return this;
}


// ========================================================================
// __unwind$111561_0
// EA  : 0x82FA4308
// RVA : 0x00FA4308
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111561_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$111562
// EA  : 0x82FA4330
// RVA : 0x00FA4330
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111562()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 32));
}


// ========================================================================
// __unwind$111563
// EA  : 0x82FA435C
// RVA : 0x00FA435C
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111563()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// __unwind$111564_0
// EA  : 0x82FA4388
// RVA : 0x00FA4388
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111564_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 80));
}


// ========================================================================
// ??1idXMLElement@@QAA@XZ
// EA  : 0x82FA43C0
// RVA : 0x00FA43C0
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void __fastcall idXMLElement::~idXMLElement(idXMLElement *this)
{
  int v2; // r27
  int v3; // r28
  idXMLElement **list; // r11
  idXMLElement *v5; // r29
  idXMLElement **v6; // r4
  idXMLAttribute *v7; // r3

  v2 = 0;
  if ( this->children.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->children.list;
      v5 = list[v3];
      if ( v5 != nullptr )
      {
        idXMLElement::~idXMLElement(this: list[v3]);
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->children.num );
  }
  if ( this->children.listStatic == 0 || this->children.listStatic == 2 )
  {
    v6 = this->children.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->children.list = nullptr;
    this->children.size = 0;
  }
  this->children.num = 0;
  if ( this->attributes.listStatic == 0 || this->attributes.listStatic == 2 )
  {
    v7 = this->attributes.list;
    if ( v7 != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &v7->name, num: this->attributes.size);
    this->attributes.list = nullptr;
    this->attributes.size = 0;
  }
  this->attributes.num = 0;
  idStr::FreeData(this: &this->value);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$111670
// EA  : 0x82FA44BC
// RVA : 0x00FA44BC
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111670()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$111671
// EA  : 0x82FA44E4
// RVA : 0x00FA44E4
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111671()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 32));
}


// ========================================================================
// __unwind$111672
// EA  : 0x82FA4510
// RVA : 0x00FA4510
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111672()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(*(_DWORD *)(v0 - 160 + 180) + 64));
}


// ========================================================================
// __unwind$111673
// EA  : 0x82FA453C
// RVA : 0x00FA453C
// PDB : w:\tech5\shared\idlib\xml\xmlelement.cpp
// ========================================================================

void _unwind_111673()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 80));
}

