
// ========================================================================
// ?LinkTo@?$idScriptVariableBase@M$03M@@QAAXAAVidScriptObject@@PBD@Z
// EA  : 0x82C39978
// RVA : 0x00C39978
// PDB : w:\tech5\tungsten\game\script\program.h
// ========================================================================

void __fastcall idScriptVariableBase<float,4,float>::LinkTo(
        idScriptVariableBase<float,4,float> *this,
        idScriptObject *obj,
        const char *name)
{
  int VariableOffsetFromName; // r3
  const char *TypeName; // r3
  const char *v8; // r3
  int v9; // [sp+50h] [-30h] BYREF

  this->object = obj;
  VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(this: obj, name, etype: (etype_t *)&v9);
  this->offset = VariableOffsetFromName;
  if ( VariableOffsetFromName == -1 )
  {
    TypeName = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Missing '%s' field in script object '%s'", name, TypeName);
  }
  if ( v9 != 4 )
  {
    v8 = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Incorrect type for field '%s' in script object '%s'", name, v8);
  }
}


// ========================================================================
// ?LinkTo@?$idScriptVariableBase@H$04H@@QAAXAAVidScriptObject@@PBD@Z
// EA  : 0x82C39A00
// RVA : 0x00C39A00
// PDB : w:\tech5\tungsten\game\script\program.h
// ========================================================================

void __fastcall idScriptVariableBase<int,5,int>::LinkTo(
        idScriptVariableBase<int,5,int> *this,
        idScriptObject *obj,
        const char *name)
{
  int VariableOffsetFromName; // r3
  const char *TypeName; // r3
  const char *v8; // r3
  int v9; // [sp+50h] [-30h] BYREF

  this->object = obj;
  VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(this: obj, name, etype: (etype_t *)&v9);
  this->offset = VariableOffsetFromName;
  if ( VariableOffsetFromName == -1 )
  {
    TypeName = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Missing '%s' field in script object '%s'", name, TypeName);
  }
  if ( v9 != 5 )
  {
    v8 = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Incorrect type for field '%s' in script object '%s'", name, v8);
  }
}


// ========================================================================
// ?LinkTo@?$idScriptVariableBase@PBD$02PBD@@QAAXAAVidScriptObject@@PBD@Z
// EA  : 0x82C39A88
// RVA : 0x00C39A88
// PDB : w:\tech5\tungsten\game\script\program.h
// ========================================================================

void __fastcall idScriptVariableBase<char const *,3,char const *>::LinkTo(
        idScriptVariableBase<char const *,3,char const *> *this,
        idScriptObject *obj,
        const char *name)
{
  int VariableOffsetFromName; // r3
  const char *TypeName; // r3
  const char *v8; // r3
  int v9; // [sp+50h] [-30h] BYREF

  this->object = obj;
  VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(this: obj, name, etype: (etype_t *)&v9);
  this->offset = VariableOffsetFromName;
  if ( VariableOffsetFromName == -1 )
  {
    TypeName = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Missing '%s' field in script object '%s'", name, TypeName);
  }
  if ( v9 != 3 )
  {
    v8 = idScriptObject::GetTypeName(this: obj);
    idLib::Error(fmt: "Incorrect type for field '%s' in script object '%s'", name, v8);
  }
}


// ========================================================================
// ?GetEntity@varEval_t@@QBAPAVidEntity@@XZ
// EA  : 0x82E930E8
// RVA : 0x00E930E8
// PDB : w:\tech5\tungsten\game\script\program.h
// ========================================================================

idEntity *__fastcall varEval_t::GetEntity(varEval_t *this)
{
  int v1; // r9
  idEntity *v2; // r3

  v1 = *this->value.ip;
  if ( gameLocal->spawnIds.ptr[v1 & 0x1FFF] == v1 >> 13 && (v2 = gameLocal->entities.ptr[v1 & 0x1FFF]) != nullptr )
    return idEntity::CastTo(c: v2);
  else
    return nullptr;
}

