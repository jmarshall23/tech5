
// ========================================================================
// ?PushEntity@idInterpreter@@QAAXPBVidEntity@@@Z
// EA  : 0x82C41C18
// RVA : 0x00C41C18
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushEntity(idInterpreter *this, const idEntity *ent)
{
  int v3; // r30

  if ( ent != nullptr )
    v3 = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    v3 = 0x1FFF;
  if ( (unsigned int)(this->localstack.stackUsed + 4) > 0x1800 )
    idInterpreter::Error(this, fmt: "Push: locals stack overflow\n");
  *(_DWORD *)&this->localstack.stack[this->localstack.stackUsed] = v3;
  this->localstack.stackUsed += 4;
}


// ========================================================================
// ?FloatToString@idInterpreter@@IBAPBDM@Z
// EA  : 0x82E92A28
// RVA : 0x00E92A28
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

char *__fastcall idInterpreter::FloatToString(idInterpreter *this, double value)
{
  __int64 v2; // r11

  LODWORD(v2) = (int)value;
  if ( value == (float)v2 )
    sprintf_0(string: `idInterpreter::FloatToString'::`2'::text, format: "%d", (int)value);
  else
    sprintf_0(string: `idInterpreter::FloatToString'::`2'::text, format: "%f", value);
  return `idInterpreter::FloatToString'::`2'::text;
}


// ========================================================================
// ?GetVariable@idInterpreter@@IAA?AUvarEval_t@@PAVidVarDef@@@Z
// EA  : 0x82E92AA8
// RVA : 0x00E92AA8
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

varEval_t *__fastcall idInterpreter::GetVariable(varEval_t *__return_ptr retstr, idInterpreter *this, idVarDef *def)
{
  idVarDef::initialized_t initialized; // r9
  float *fp; // r11
  int stackBase; // r10
  bool *v6; // r11

  initialized = def->initialized;
  fp = def->value.value.fp;
  if ( initialized >= stackVariable )
  {
    stackBase = this->localstack.stackBase;
    fp = (float *)&this->localstack.stack[(_DWORD)fp + stackBase];
    if ( initialized == reference )
    {
      v6 = &this->doneProcessing + (int)*fp + stackBase;
      def->initialized = stackVariable;
      retstr->value.i = (int)(v6 + 800);
      return retstr;
    }
    if ( initialized == globalReference )
      fp = *(float **)fp;
    def->initialized = stackVariable;
  }
  retstr->value.i = (int)fp;
  return retstr;
}


// ========================================================================
// ?PushString@idInterpreter@@QAAXPBD@Z
// EA  : 0x82E93138
// RVA : 0x00E93138
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushString(idInterpreter *this, const char *string, __int64 a3, __int64 a4, __int64 a5)
{
  int stackUsed; // r11
  int v7; // [sp+8h] [-68h]
  int v8; // [sp+Ch] [-64h]
  int v9; // [sp+10h] [-60h]
  int v10; // [sp+14h] [-5Ch]
  int v11; // [sp+18h] [-58h]
  int v12; // [sp+1Ch] [-54h]

  stackUsed = this->localstack.stackUsed;
  if ( stackUsed + 256 > 6144 )
  {
    LODWORD(a5) = stackUsed + 256;
    idInterpreter::Error(
      this,
      fmt: "PushString: locals stack overflow\n",
      a3,
      a4,
      a5,
      a6: v7,
      a7: v8,
      a8: v9,
      a9: v10,
      a10: v11,
      a11: v12);
  }
  idStr::Copynz(dest: (char *)&this->localstack.stack[stackUsed], src: string, destsize: 256);
  this->localstack.stackUsed += 256;
}


// ========================================================================
// ?PushInt@idInterpreter@@QAAXH@Z
// EA  : 0x82E93198
// RVA : 0x00E93198
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushInt(idInterpreter *this, int value, __int64 a3, __int64 a4, __int64 a5)
{
  int stackUsed; // r11
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]

  stackUsed = this->localstack.stackUsed;
  if ( (unsigned int)(stackUsed + 4) > 0x1800 )
  {
    LODWORD(a5) = stackUsed + 4;
    idInterpreter::Error(
      this,
      fmt: "PushInt: locals stack overflow\n",
      a3,
      a4,
      a5,
      a6: v6,
      a7: v7,
      a8: v8,
      a9: v9,
      a10: v10,
      a11: v11);
  }
  *(_DWORD *)&this->localstack.stack[stackUsed] = value;
  this->localstack.stackUsed += 4;
}


// ========================================================================
// ?PushFloat@idInterpreter@@QAAXM@Z
// EA  : 0x82E931E8
// RVA : 0x00E931E8
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushFloat(idInterpreter *this, double value, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  int stackUsed; // r11
  int v7; // [sp+8h] [-68h]
  int v8; // [sp+Ch] [-64h]
  int v9; // [sp+10h] [-60h]
  int v10; // [sp+14h] [-5Ch]
  int v11; // [sp+18h] [-58h]
  int v12; // [sp+1Ch] [-54h]

  stackUsed = this->localstack.stackUsed;
  if ( (unsigned int)(stackUsed + 4) > 0x1800 )
  {
    LODWORD(a6) = stackUsed + 4;
    idInterpreter::Error(
      this,
      fmt: "PushFloat: locals stack overflow\n",
      a3: a4,
      a4: a5,
      a5: a6,
      a6: v7,
      a7: v8,
      a8: v9,
      a9: v10,
      a10: v11,
      a11: v12,
      value);
  }
  *(float *)&this->localstack.stack[stackUsed] = value;
  this->localstack.stackUsed += 4;
}


// ========================================================================
// ?PushVec3@idInterpreter@@QAAXVidVec3@@@Z
// EA  : 0x82E93238
// RVA : 0x00E93238
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idInterpreter::PushVec3(idInterpreter *this, idVec3 *value, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r11
  idInterpreter *v7; // r3
  int v8; // r3
  int v9; // r11
  int v10; // [sp+8h] [-78h]
  int v11; // [sp+Ch] [-74h]
  int v12; // [sp+10h] [-70h]
  int v13; // [sp+14h] [-6Ch]
  int v14; // [sp+18h] [-68h]
  int v15; // [sp+1Ch] [-64h]
  __int64 v16; // [sp+A0h] [+20h]

  v6 = *(_DWORD *)(v5 + 6948);
  v16 = *(_QWORD *)&value;
  if ( (unsigned int)(v6 + 12) > 0x1800 )
  {
    LODWORD(a5) = v6 + 12;
    idInterpreter::Error(
      this: v7,
      fmt: "PushVec3: locals stack overflow\n",
      a3,
      a4,
      a5,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15);
  }
  v9 = v6 + v8;
  *(_QWORD *)(v9 + 800) = v16;
  *(float *)(v9 + 808) = *(float *)&value;
  *(_DWORD *)(v8 + 6948) += 12;
}


// ========================================================================
// ?PushEntityPtr@idInterpreter@@QAAXABV?$idEntityPtr@VidEntity@@@@@Z
// EA  : 0x82E932A8
// RVA : 0x00E932A8
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushEntityPtr(
        idInterpreter *this,
        const idEntityPtr<idEntity> *entityPtr,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int stackUsed; // r11
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]

  stackUsed = this->localstack.stackUsed;
  if ( (unsigned int)(stackUsed + 4) > 0x1800 )
  {
    LODWORD(a5) = stackUsed + 4;
    idInterpreter::Error(
      this,
      fmt: "Push: locals stack overflow\n",
      a3,
      a4,
      a5,
      a6: v6,
      a7: v7,
      a8: v8,
      a9: v9,
      a10: v10,
      a11: v11);
  }
  *(idEntityPtr<idEntity> *)&this->localstack.stack[stackUsed] = (idEntityPtr<idEntity>)entityPtr->spawnId.value;
  this->localstack.stackUsed += 4;
}


// ========================================================================
// ?PushScriptType@idInterpreter@@QAAXH@Z
// EA  : 0x82E932F8
// RVA : 0x00E932F8
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

void __fastcall idInterpreter::PushScriptType(
        idInterpreter *this,
        int scriptTypeID,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int stackUsed; // r11
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]

  stackUsed = this->localstack.stackUsed;
  if ( (unsigned int)(stackUsed + 4) > 0x1800 )
  {
    LODWORD(a5) = stackUsed + 4;
    idInterpreter::Error(
      this,
      fmt: "Push: locals stack overflow\n",
      a3,
      a4,
      a5,
      a6: v6,
      a7: v7,
      a8: v8,
      a9: v9,
      a10: v10,
      a11: v11);
  }
  *(_DWORD *)&this->localstack.stack[stackUsed] = scriptTypeID;
  this->localstack.stackUsed += 4;
}


// ========================================================================
// ?GetScriptObject@idInterpreter@@IAAPAVidScriptObject@@PAVidVarDef@@@Z
// EA  : 0x82E93348
// RVA : 0x00E93348
// PDB : w:\tech5\tungsten\game\script\interpreter.h
// ========================================================================

bfx::Planner3D *__fastcall idInterpreter::GetScriptObject(idInterpreter *this, idVarDef *varDef)
{
  idVarDef::initialized_t initialized; // r9
  float *fp; // r11
  int stackBase; // r10
  int v6; // r11
  int v7; // r8
  idEntity *v8; // r3
  idEntity *v9; // r3
  bfx::Planner3D *v10; // r31
  idTypeDef *typeDef; // r30
  idTypeDef *v12; // r3

  initialized = varDef->initialized;
  fp = varDef->value.value.fp;
  if ( initialized >= stackVariable )
  {
    stackBase = this->localstack.stackBase;
    fp = (float *)&this->localstack.stack[(_DWORD)fp + stackBase];
    if ( initialized == reference )
    {
      fp = (float *)&this->localstack.stack[(int)*fp + stackBase];
    }
    else if ( initialized == globalReference )
    {
      fp = *(float **)fp;
    }
    varDef->initialized = stackVariable;
  }
  v7 = *(int *)fp >> 13;
  v6 = *(_DWORD *)fp & 0x1FFF;
  if ( gameLocal->spawnIds.ptr[v6] == v7
    && (v8 = gameLocal->entities.ptr[v6]) != nullptr
    && (v9 = idEntity::CastTo(c: v8)) != nullptr
    && ((v10 = (bfx::Planner3D *)v9->GetScriptObject_2(this: v9)) != nullptr
     && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)varDef->typeDef) == (bfx::Space *)8
     || (typeDef = varDef->typeDef,
         v12 = (idTypeDef *)idScriptObject::GetTypeDef(this: v10),
         idTypeDef::Inherits(this: v12, basetype: typeDef))) )
  {
    return v10;
  }
  else
  {
    return nullptr;
  }
}

