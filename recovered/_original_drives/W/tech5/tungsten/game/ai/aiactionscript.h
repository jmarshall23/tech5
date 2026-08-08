
// ========================================================================
// ?Clear@idAIActionParm@@QAAXXZ
// EA  : 0x82A3B9C8
// RVA : 0x00A3B9C8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Clear(idAIActionParm *this)
{
  this->intVal = 0;
  this->floatVal = vec3_origin;
  this->declVal = nullptr;
  idStr::EnsureAlloced(this: &this->strVal, amount: 1, keepold: true, geometricGrowth: false);
  *this->strVal.data = 0;
  this->strVal.len = 0;
  this->type = 0;
  this->subType = 45;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXH@Z
// EA  : 0x82A3BA50
// RVA : 0x00A3BA50
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 0;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAX_N@Z
// EA  : 0x82A3BAA0
// RVA : 0x00A3BAA0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const bool in)
{
  idAIActionParm::Clear(this);
  this->type = 1;
  this->subType = 1;
  this->intVal = in;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXM@Z
// EA  : 0x82A3BAF8
// RVA : 0x00A3BAF8
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, double in)
{
  idAIActionParm::Clear(this);
  this->type = 2;
  this->subType = 17;
  this->floatVal.x = in;
  this->floatVal.y = in;
  this->floatVal.z = in;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXABVidVec3@@@Z
// EA  : 0x82A3BB50
// RVA : 0x00A3BB50
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idVec3 *in)
{
  idAIActionParm::Clear(this);
  this->type = 2;
  this->subType = 18;
  this->floatVal = *in;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXABVidAngles@@@Z
// EA  : 0x82A3BBB0
// RVA : 0x00A3BBB0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idAngles *in)
{
  double roll; // fp0
  double yaw; // fp13

  idAIActionParm::Clear(this);
  this->type = 2;
  this->subType = 18;
  roll = in->roll;
  yaw = in->yaw;
  this->floatVal.x = in->pitch;
  this->floatVal.y = yaw;
  this->floatVal.z = roll;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXPBVidDeclVoiceOver@@@Z
// EA  : 0x82A3BC10
// RVA : 0x00A3BC10
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idDeclVoiceOver *vo)
{
  idAIActionParm::Clear(this);
  this->declVal = vo;
  this->type = 4;
  this->subType = 24;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXPBVidSoundShader@@@Z
// EA  : 0x82A3BC60
// RVA : 0x00A3BC60
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idSoundShader *ss)
{
  idAIActionParm::Clear(this);
  this->declVal = ss;
  this->type = 4;
  this->subType = 25;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXPBVidDeclAmmo@@@Z
// EA  : 0x82A3BCB0
// RVA : 0x00A3BCB0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idDeclAmmo *decl)
{
  idAIActionParm::Clear(this);
  this->declVal = decl;
  this->type = 4;
  this->subType = 26;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXPBVidDeclWeapon@@@Z
// EA  : 0x82A3BD00
// RVA : 0x00A3BD00
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, const idDeclWeapon *decl)
{
  idAIActionParm::Clear(this);
  this->declVal = decl;
  this->type = 4;
  this->subType = 27;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiArrivalAction_t@@@Z
// EA  : 0x82A3BD50
// RVA : 0x00A3BD50
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 2;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4posture_t@@@Z
// EA  : 0x82A3BDA0
// RVA : 0x00A3BDA0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 3;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4coverAction_t@@@Z
// EA  : 0x82A3BDF0
// RVA : 0x00A3BDF0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 4;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4equipSlot_t@@@Z
// EA  : 0x82A3BE40
// RVA : 0x00A3BE40
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 5;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4alertCycle_t@@@Z
// EA  : 0x82A3BE90
// RVA : 0x00A3BE90
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 6;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiFireMode_t@@@Z
// EA  : 0x82A3BEE0
// RVA : 0x00A3BEE0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 7;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aimPoint_t@@@Z
// EA  : 0x82A3BF30
// RVA : 0x00A3BF30
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 8;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4walkState_t@@@Z
// EA  : 0x82A3BF80
// RVA : 0x00A3BF80
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 9;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiPlayer_t@@@Z
// EA  : 0x82A3BFD0
// RVA : 0x00A3BFD0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 10;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4overrideAnim_t@@@Z
// EA  : 0x82A3C020
// RVA : 0x00A3C020
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 11;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4painType_t@@@Z
// EA  : 0x82A3C070
// RVA : 0x00A3C070
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 12;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiDirection_t@@@Z
// EA  : 0x82A3C0C0
// RVA : 0x00A3C0C0
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 13;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiDodgeDir_t@@@Z
// EA  : 0x82A3C110
// RVA : 0x00A3C110
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 14;
}


// ========================================================================
// ?Set@idAIActionParm@@QAAXW4aiSubWeb_t@@@Z
// EA  : 0x82A3C160
// RVA : 0x00A3C160
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Set(idAIActionParm *this, int in)
{
  idAIActionParm::Clear(this);
  this->intVal = in;
  this->type = 1;
  this->subType = 15;
}


// ========================================================================
// ?Get@idAIActionParm@@QBAXAAVidStr@@W4subParm_t@1@@Z
// EA  : 0x82BB8A88
// RVA : 0x00BB8A88
// PDB : w:\tech5\tungsten\game\ai\aiactionscript.h
// ========================================================================

void __fastcall idAIActionParm::Get(idAIActionParm *this, idStr *out, const idAIActionParm::subParm_t subType_)
{
  int len; // r31

  len = this->strVal.len;
  idStr::EnsureAlloced(this: out, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: out->data, Src: this->strVal.data, Size: len);
  out->data[len] = 0;
  out->len = len;
}

