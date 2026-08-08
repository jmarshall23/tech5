
// ========================================================================
// ??0idInfoAmbient@@QAA@XZ
// EA  : 0x82518110
// RVA : 0x00518110
// PDB : w:\tech5\tungsten\game\entities\info.h
// ========================================================================

idInfoAmbient *__fastcall idInfoAmbient::idInfoAmbient(idInfoAmbient *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInfoAmbient_vtbl *)&idInfoAmbient::`vftable';
  this->ambientOverrideColors.editorEast.a = -1.0;
  this->ambientOverrideColors.editorEast.b = -1.0;
  this->ambientOverrideColors.editorEast.g = -1.0;
  this->ambientOverrideColors.editorEast.r = -1.0;
  this->ambientOverrideColors.editorWest.a = -1.0;
  this->ambientOverrideColors.editorWest.b = -1.0;
  this->ambientOverrideColors.editorWest.g = -1.0;
  this->ambientOverrideColors.editorWest.r = -1.0;
  this->ambientOverrideColors.editorNorth.a = -1.0;
  this->ambientOverrideColors.editorNorth.b = -1.0;
  this->ambientOverrideColors.editorNorth.g = -1.0;
  this->ambientOverrideColors.editorNorth.r = -1.0;
  this->ambientOverrideColors.editorSouth.a = -1.0;
  this->ambientOverrideColors.editorSouth.b = -1.0;
  this->ambientOverrideColors.editorSouth.g = -1.0;
  this->ambientOverrideColors.editorSouth.r = -1.0;
  this->ambientOverrideColors.editorUp.a = -1.0;
  this->ambientOverrideColors.editorUp.b = -1.0;
  this->ambientOverrideColors.editorUp.g = -1.0;
  this->ambientOverrideColors.editorUp.r = -1.0;
  this->ambientOverrideColors.editorDown.a = -1.0;
  this->ambientOverrideColors.editorDown.b = -1.0;
  this->ambientOverrideColors.editorDown.g = -1.0;
  this->ambientOverrideColors.editorDown.r = -1.0;
  this->ambientOverrideColors.editorEast.a = 1.0;
  this->ambientOverrideColors.editorWest.a = 1.0;
  this->ambientOverrideColors.editorNorth.a = 1.0;
  this->ambientOverrideColors.editorSouth.a = 1.0;
  this->ambientOverrideColors.editorUp.a = 1.0;
  this->ambientOverrideColors.editorDown.a = 1.0;
  return this;
}


// ========================================================================
// ??0idInfoDevComment@@QAA@XZ
// EA  : 0x82536780
// RVA : 0x00536780
// PDB : w:\tech5\tungsten\game\entities\info.h
// ========================================================================

idInfoDevComment *__fastcall idInfoDevComment::idInfoDevComment(idInfoDevComment *this)
{
  float a; // r11

  idEntity::idEntity(this);
  this->__vftable = (idInfoDevComment_vtbl *)&idInfoDevComment::`vftable';
  idStr::idStr(this: &this->comment, text: &byte_8200D768);
  this->textColor.r = idColor::colorDefault.r;
  this->textColor.g = idColor::colorDefault.g;
  this->textColor.b = idColor::colorDefault.b;
  a = idColor::colorDefault.a;
  this->showAlways = true;
  this->textColor.a = a;
  return this;
}


// ========================================================================
// __unwind$570048
// EA  : 0x8253680C
// RVA : 0x0053680C
// PDB : w:\tech5\tungsten\game\entities\info.h
// ========================================================================

void _unwind_570048()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}

