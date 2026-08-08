
// ========================================================================
// ?NumCoordinateDimensions@idModelInfo@idDeclAnimWebNode@@QBAHXZ
// EA  : 0x82582E40
// RVA : 0x00582E40
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

int __fastcall idDeclAnimWebNode::idModelInfo::NumCoordinateDimensions(idDeclAnimWebNode::idModelInfo *this)
{
  idList<float,32> *coordinates; // r11
  char v2; // r10
  int num; // r10
  signed int v4; // r9

  coordinates = this->coordinates;
  if ( coordinates == nullptr || coordinates->num <= 0 || (v2 = 1, this->animProps.num <= 0) )
    v2 = 0;
  if ( v2 == 0 )
    return 0;
  num = coordinates->num;
  v4 = this->animProps.num;
  __twllei(v4, 0);
  __twlgei(v4 & ~(__ROL4__(num, 1) - 1), 0xFFFFFFFF);
  return num / v4;
}


// ========================================================================
// ??1idModelInfo@idDeclAnimWebNode@@QAA@XZ
// EA  : 0x825920B8
// RVA : 0x005920B8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::~idModelInfo(idDeclAnimWebNode::idModelInfo *this)
{
  idDeclAnimWebNode::idModelInfo::SetNumCoordinateDimensions(this, numDimensions: 0);
  idDeclAnimWebNode::idModelInfo::UpdateTagGroupsList(this, numTagGroups: 0);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animProps);
}


// ========================================================================
// __unwind$688315
// EA  : 0x8259210C
// RVA : 0x0059210C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

void _unwind_688315()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ??4idModelInfo@idDeclAnimWebNode@@QAAABV01@ABV01@@Z
// EA  : 0x82592138
// RVA : 0x00592138
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

const idDeclAnimWebNode::idModelInfo *__fastcall idDeclAnimWebNode::idModelInfo::operator=(
        idDeclAnimWebNode::idModelInfo *this,
        idDeclAnimWebNode::idModelInfo *other)
{
  int v4; // r29

  if ( other != this )
  {
    this->blendEq.str = other->blendEq.str;
    this->blendEqFixed.str = other->blendEqFixed.str;
    idList<idMD6AnimProps,32>::operator=(this: &this->animProps, other: &other->animProps);
    this->modelIndex.value = other->modelIndex.value;
    v4 = idDeclAnimWebNode::idModelInfo::NumCoordinateDimensions(this: other);
    idDeclAnimWebNode::idModelInfo::SetNumCoordinateDimensions(this, numDimensions: v4);
    if ( v4 > 0 )
      idList<float,32>::operator=(this: this->coordinates, other: other->coordinates);
    idDeclAnimWebNode::idModelInfo::CopyTagGroups(this, other);
  }
  return this;
}


// ========================================================================
// ?NumTagGroups@idModelInfo@idDeclAnimWebNode@@QBAHXZ
// EA  : 0x825F8E38
// RVA : 0x005F8E38
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

int __fastcall idDeclAnimWebNode::idModelInfo::NumTagGroups(idDeclAnimWebNode::idModelInfo *this)
{
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r11

  tagGroups = this->tagGroups;
  if ( tagGroups != nullptr )
    return tagGroups->num;
  else
    return 0;
}


// ========================================================================
// ?SetCoordinate@idModelInfo@idDeclAnimWebNode@@QAAXHABV?$idList@M$04@@@Z
// EA  : 0x82606428
// RVA : 0x00606428
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.h
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::SetCoordinate(
        idDeclAnimWebNode::idModelInfo *this,
        const int propIndex,
        const idList<float,5> *value)
{
  idList<float,32> *coordinates; // r11
  char v4; // r11
  int num; // r29
  int v6; // r11
  int v7; // r28
  int v8; // r10
  int v9; // r9
  int v10; // r27
  int v11; // r26
  float *v12; // r7
  int v13; // r11
  int v14; // r10
  int v15; // ctr

  coordinates = this->coordinates;
  if ( coordinates == nullptr || coordinates->num <= 0 || (v4 = 1, this->animProps.num <= 0) )
    v4 = 0;
  if ( v4 != 0 )
  {
    num = value->num;
    v6 = 0;
    v7 = num * propIndex;
    if ( num >= 4 )
    {
      v8 = 0;
      v9 = v7;
      do
      {
        v10 = v7 + 2 + v6;
        v11 = v7 + 3 + v6;
        v6 += 4;
        this->coordinates->list[v9] = value->list[v8];
        v12 = &this->coordinates->list[v9];
        v9 += 4;
        v12[1] = value->list[v8 + 1];
        this->coordinates->list[v10] = value->list[v8 + 2];
        this->coordinates->list[v11] = value->list[v8 + 3];
        v8 += 4;
      }
      while ( v6 < num - 3 );
    }
    if ( v6 < num )
    {
      v14 = v6 + v7;
      v15 = num - v6;
      v13 = v6;
      do
      {
        this->coordinates->list[v14++] = value->list[v13++];
        --v15;
      }
      while ( v15 != 0 );
    }
  }
}

