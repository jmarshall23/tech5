
// ========================================================================
// ??0eventEntity@@QAA@XZ
// EA  : 0x82D5F0E0
// RVA : 0x00D5F0E0
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventEntity *__fastcall eventEntity::eventEntity(eventEntity *this)
{
  this->value = nullptr;
  idProgram::ReturnEntity(this: &gameLocal->program, ent: nullptr);
  idSuperScriptSystem::ReturnInteger(this: &gameLocal->superScript, value: 0);
  return this;
}


// ========================================================================
// ??0eventDecl@@QAA@XZ
// EA  : 0x82D5F148
// RVA : 0x00D5F148
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventDecl *__fastcall eventDecl::eventDecl(eventDecl *this)
{
  this->value = nullptr;
  idProgram::ReturnDecl(this: &gameLocal->program, decl: nullptr);
  return this;
}


// ========================================================================
// ??0eventDecl@@QAA@PBVidDecl@@@Z
// EA  : 0x82D5F198
// RVA : 0x00D5F198
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventDecl *__fastcall eventDecl::eventDecl(eventDecl *this, const idDecl *decl)
{
  this->value = decl;
  idProgram::ReturnDecl(this: &gameLocal->program, decl);
  return this;
}


// ========================================================================
// ??0ssEntity@@QAA@H@Z
// EA  : 0x82D5F1E0
// RVA : 0x00D5F1E0
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

XGRAPHICS::VRegTable *__fastcall ssEntity::ssEntity(XGRAPHICS::VRegTable *this, XGRAPHICS::Compiler *context)
{
  this->context = context;
  return this;
}


// ========================================================================
// ??0idEventArg@@QAA@PBVidEntity@@@Z
// EA  : 0x82D5F1E8
// RVA : 0x00D5F1E8
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

idEventArg *__fastcall idEventArg::idEventArg(idEventArg *this, const idEntity *data)
{
  char v4; // [sp+50h] [-20h] BYREF

  this->type = 101;
  this->value.i = idGameLocal::GetSpawnId(this: (idGameLocal *)&v4, result: (idSpawnId *)gameLocal, ent: data)->value;
  return this;
}


// ========================================================================
// ??0idEventArg@@QAA@ABVidSpawnId@@@Z
// EA  : 0x82D5F238
// RVA : 0x00D5F238
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

idEventArg *__fastcall idEventArg::idEventArg(idEventArg *this, const idSpawnId *data)
{
  this->type = 101;
  this->value.i = data->value;
  return this;
}


// ========================================================================
// ??0eventBool@@QAA@_N@Z
// EA  : 0x82D5F250
// RVA : 0x00D5F250
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventBool *__fastcall eventBool::eventBool(eventBool *this, const bool b)
{
  this->value = b;
  *gameLocal->program.returnDef->value.value.ip = b;
  idSuperScriptSystem::ReturnInteger(this: &gameLocal->superScript, value: b);
  return this;
}


// ========================================================================
// ??0eventInt@@QAA@H@Z
// EA  : 0x82D5F2B0
// RVA : 0x00D5F2B0
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventInt *__fastcall eventInt::eventInt(eventInt *this, int i)
{
  this->value = i;
  *gameLocal->program.returnDef->value.value.ip = i;
  idSuperScriptSystem::ReturnInteger(this: &gameLocal->superScript, value: i);
  return this;
}


// ========================================================================
// ??0eventFloat@@QAA@M@Z
// EA  : 0x82D5F310
// RVA : 0x00D5F310
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventFloat *__fastcall eventFloat::eventFloat(eventFloat *this, double f)
{
  idSuperScriptSystem *p_superScript; // r3

  this->value = f;
  p_superScript = &gameLocal->superScript;
  *gameLocal->program.returnDef->value.value.fp = f;
  idSuperScriptSystem::ReturnFloat(this: p_superScript, value: f);
  return this;
}


// ========================================================================
// ??0eventVector@@QAA@ABVidVec3@@@Z
// EA  : 0x82D5F368
// RVA : 0x00D5F368
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventVector *__fastcall eventVector::eventVector(eventVector *this, eventVector *v)
{
  idSuperScriptSystem *p_superScript; // r3

  *this = *v;
  p_superScript = &gameLocal->superScript;
  *gameLocal->program.returnDef->value.value.vp = v->value;
  idSuperScriptSystem::ReturnVector(this: p_superScript, vec: &v->value);
  return this;
}


// ========================================================================
// ??0eventString@@QAA@XZ
// EA  : 0x82D5F3E8
// RVA : 0x00D5F3E8
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventString *__fastcall eventString::eventString(eventString *this)
{
  const char *v2; // r4

  this->value = eventString::defaultValue;
  v2 = eventString::defaultValue;
  if ( eventString::defaultValue == nullptr )
    v2 = &byte_8200D768;
  idStr::Copynz(dest: gameLocal->program.returnStringDef->value.value.cp, src: v2, destsize: 256);
  idSuperScriptSystem::ReturnString(this: &gameLocal->superScript, string: eventString::defaultValue);
  return this;
}


// ========================================================================
// ??0eventString@@QAA@PBD@Z
// EA  : 0x82D5F458
// RVA : 0x00D5F458
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventString *__fastcall eventString::eventString(eventString *this, const char *s)
{
  const char *v3; // r31

  this->value = s;
  v3 = s;
  if ( s == nullptr )
    s = &byte_8200D768;
  idStr::Copynz(dest: gameLocal->program.returnStringDef->value.value.cp, src: s, destsize: 256);
  idSuperScriptSystem::ReturnString(this: &gameLocal->superScript, string: v3);
  return this;
}


// ========================================================================
// ??0eventEntity@@QAA@PAVidEntity@@@Z
// EA  : 0x82D5F4C8
// RVA : 0x00D5F4C8
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

eventEntity *__fastcall eventEntity::eventEntity(eventEntity *this, idEntity *e)
{
  idSpawnId *SpawnId; // r3
  char v6; // [sp+50h] [-30h] BYREF

  this->value = e;
  idProgram::ReturnEntity(this: &gameLocal->program, ent: e);
  SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v6, result: (idSpawnId *)gameLocal, ent: e);
  idSuperScriptSystem::ReturnInteger(this: &gameLocal->superScript, value: SpawnId->value);
  return this;
}


// ========================================================================
// ??0idEventArgs@@QAA@XZ
// EA  : 0x82D5F528
// RVA : 0x00D5F528
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

idEventArgs *__fastcall idEventArgs::idEventArgs(idEventArgs *this)
{
  this->args.ptr[0].type = 0;
  this->args.ptr[0].value.i = 0;
  this->args.ptr[1].type = 0;
  this->args.ptr[1].value.i = 0;
  this->args.ptr[2].type = 0;
  this->args.ptr[2].value.i = 0;
  this->args.ptr[3].type = 0;
  this->args.ptr[3].value.i = 0;
  this->args.ptr[4].type = 0;
  this->args.ptr[4].value.i = 0;
  this->args.ptr[5].type = 0;
  this->args.ptr[5].value.i = 0;
  this->args.ptr[6].type = 0;
  this->args.ptr[6].value.i = 0;
  this->args.ptr[7].type = 0;
  this->args.ptr[7].value.i = 0;
  `eh vector constructor iterator'(
    ptr: &this->strings,
    size: 0x20u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->argsNumber = 0;
  return this;
}


// ========================================================================
// ?AddArg@idEventArgs@@QAAXABVidEventArg@@@Z
// EA  : 0x82D5F5C8
// RVA : 0x00D5F5C8
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

void __fastcall idEventArgs::AddArg(idEventArgs *this, const idEventArg *arg)
{
  int type; // r11
  char v5; // r11
  bool v6; // zf
  int argsNumber; // r11
  _DWORD *v8; // r8
  int v9; // ctr
  int v10; // r11
  _DWORD *v11; // r11
  _DWORD *v12; // r9
  int v13; // ctr
  _DWORD *v14; // r11
  _DWORD v15[7]; // [sp+4Ch] [-34h] BYREF

  type = arg->type;
  if ( type == 115 || type == 49 || type == 50 || (v6 = type != 53, v5 = 0, !v6) )
    v5 = 1;
  v6 = v5 == 0;
  argsNumber = this->argsNumber;
  if ( v6 )
  {
    v12 = (_DWORD *)&arg[-1].value.q[3];
    v13 = 5;
    v14 = (_DWORD *)&this->args.ptr[argsNumber - 1].value.q[3];
    do
    {
      *++v14 = *++v12;
      --v13;
    }
    while ( v13 != 0 );
  }
  else
  {
    idStr::operator=(this: &this->strings.ptr[argsNumber], text: arg->value.s);
    v8 = v15;
    HIBYTE(v15[1]) = 115;
    v9 = 5;
    v10 = this->argsNumber;
    v15[2] = this->strings.ptr[v10].data;
    v11 = (_DWORD *)&this->args.ptr[v10 - 1].value.q[3];
    do
    {
      *++v11 = *++v8;
      --v9;
    }
    while ( v9 != 0 );
    this->args.ptr[this->argsNumber].type = arg->type;
  }
  ++this->argsNumber;
}


// ========================================================================
// ?GetEntitySpawnId@idEventArg@@QBA?AVidSpawnId@@XZ
// EA  : 0x82D5F6F0
// RVA : 0x00D5F6F0
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

idEventArg *__fastcall idEventArg::GetEntitySpawnId(idEventArg *this, idSpawnId *result)
{
  *(idSpawnId *)&this->type = result[1];
  return this;
}


// ========================================================================
// ??0idEventArgs@@QAA@HPBVidEventArg@@@Z
// EA  : 0x82D5F708
// RVA : 0x00D5F708
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

idEventArgs *__fastcall idEventArgs::idEventArgs(idEventArgs *this, int numberOfParams, const idEventArg *params)
{
  int i; // r29

  this->args.ptr[0].type = 0;
  this->args.ptr[0].value.i = 0;
  this->args.ptr[1].type = 0;
  this->args.ptr[1].value.i = 0;
  this->args.ptr[2].type = 0;
  this->args.ptr[2].value.i = 0;
  this->args.ptr[3].type = 0;
  this->args.ptr[3].value.i = 0;
  this->args.ptr[4].type = 0;
  this->args.ptr[4].value.i = 0;
  this->args.ptr[5].type = 0;
  this->args.ptr[5].value.i = 0;
  this->args.ptr[6].type = 0;
  this->args.ptr[6].value.i = 0;
  this->args.ptr[7].type = 0;
  this->args.ptr[7].value.i = 0;
  `eh vector constructor iterator'(
    ptr: &this->strings,
    size: 0x20u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->argsNumber = 0;
  if ( numberOfParams > 0 )
  {
    for ( i = numberOfParams; i != 0; --i )
      idEventArgs::AddArg(this, arg: params++);
  }
  return this;
}


// ========================================================================
// __unwind$487888_0
// EA  : 0x82D5F7C4
// RVA : 0x00D5F7C4
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

void _unwind_487888_0()
{
  int v0; // r12

  idArray<idStr,8>::~idArray<idStr,8>(this: (idArray<idStr,8> *)(*(_DWORD *)(v0 - 128 + 148) + 160));
}


// ========================================================================
// ??4idEventArgs@@QAAXABV0@@Z
// EA  : 0x82D5F7F0
// RVA : 0x00D5F7F0
// PDB : w:\tech5\tungsten\game\gamesys\eventarg.cpp
// ========================================================================

void __fastcall idEventArgs::operator=(idEventArgs *this, const idEventArgs *other)
{
  int v2; // r31
  const idEventArgs *v5; // r30

  v2 = 0;
  this->argsNumber = 0;
  if ( other->argsNumber > 0 )
  {
    v5 = other;
    do
    {
      idEventArgs::AddArg(this, arg: v5->args.ptr);
      ++v2;
      v5 = (const idEventArgs *)((char *)v5 + 20);
    }
    while ( v2 < other->argsNumber );
  }
}

