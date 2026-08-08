
// ========================================================================
// ?WriteSolverConstants@idDeclAF@@ABAXPAVidFile@@ABUsolverConstants_t@1@PBD2@Z
// EA  : 0x8260D110
// RVA : 0x0060D110
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF::WriteSolverConstants(
        idDeclAF *this,
        idFile *f,
        const idDeclAF::solverConstants_t *c,
        const char *name,
        const char *indent)
{
  f->WriteFloatString(this: f, a2: "%s%s {\n", indent);
  f->WriteFloatString(
    this: f,
    a2: "\t%serrorReduction %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->errorReduction));
  f->WriteFloatString(
    this: f,
    a2: "\t%serrorReductionMax %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->errorReductionMax));
  f->WriteFloatString(this: f, a2: "\t%slcpEpsilon %f\n", indent, (unsigned int)COERCE_UNSIGNED_INT64(c->lcpEpsilon));
  f->WriteFloatString(
    this: f,
    a2: "\t%slimitErrorReduction %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->limitErrorReduction));
  f->WriteFloatString(
    this: f,
    a2: "\t%slimitErrorReductionMax %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->limitErrorReductionMax));
  f->WriteFloatString(
    this: f,
    a2: "\t%slimitLcpEpsilon %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->limitLcpEpsilon));
  f->WriteFloatString(
    this: f,
    a2: "\t%scontactErrorReduction %f\n",
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(c->contactErrorReduction)),
    (unsigned int)COERCE_UNSIGNED_INT64(c->contactErrorReduction));
  f->WriteFloatString(
    this: f,
    a2: "\t%scontactErrorReductionMax %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->contactErrorReductionMax));
  f->WriteFloatString(
    this: f,
    a2: "\t%scontactLcpEpsilon %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->contactLcpEpsilon));
  f->WriteFloatString(
    this: f,
    a2: "\t%suniversalErrorReduction %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->universalErrorReduction));
  f->WriteFloatString(
    this: f,
    a2: "\t%suniversalErrorReductionMax %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->universalErrorReductionMax));
  f->WriteFloatString(
    this: f,
    a2: "\t%suniversalTorsionLcpEpsilon %f\n",
    indent,
    (unsigned int)COERCE_UNSIGNED_INT64(c->universalTorsionLcpEpsilon));
  f->WriteFloatString(this: f, a2: "%s}\n", indent);
}


// ========================================================================
// ?JointModFromString@idDeclAF@@SA?AW4declAFJointMod_t@@PBD@Z
// EA  : 0x8260D380
// RVA : 0x0060D380
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

declAFJointMod_t __fastcall idDeclAF::JointModFromString(const char *str)
{
  declAFJointMod_t result; // r3

  result = idStr::Icmp(s1: str, s2: "orientation");
  if ( result != DECLAF_JOINTMOD_AXIS )
  {
    if ( idStr::Icmp(s1: str, s2: "position") != 0 )
      return idStr::Icmp(s1: str, s2: "both") != 0 ? 0 : 2;
    else
      return DECLAF_JOINTMOD_ORIGIN;
  }
  return result;
}


// ========================================================================
// ?DefaultDefinition@idDeclAF@@UBAPBDXZ
// EA  : 0x8260D420
// RVA : 0x0060D420
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

const char *__fastcall idDeclAF::DefaultDefinition(idDeclAF *this)
{
  return "{\n"
         "\tsettings {\n"
         "\t\tmodel \"\"\n"
         "\t\tskin \"\"\n"
         "\t\tdefaultBouncyness 0.3\n"
         "\t\tdefaultLinearFriction 0.01\n"
         "\t\tdefaultAngularFriction 0.01\n"
         "\t\tdefaultContactFriction 0.8\n"
         "\t\tdefaultConstraintFriction 0.5\n"
         "\t\tsuspendSpeed 20, 30, 40, 60\n"
         "\t\tnoMoveTime 1\n"
         "\t\tnoMoveTranslation 10\n"
         "\t\tnoMoveRotation 10\n"
         "\t\tminMoveTime -1\n"
         "\t\tmaxMoveTime -1\n"
         "\t\tcontents corpse\n"
         "\t\tclipMask solid, corpse\n"
         "\t\tselfCollision 1\n"
         "\t\tbase \"origin\"\n"
         "\t}\n"
         "\tbody \"body\" {\n"
         "\t\tjoint \"origin\"\n"
         "\t\tmod orientation\n"
         "\t\tmodel box( ( -10, -10, -10 ), ( 10, 10, 10 ) )\n"
         "\t\torigin ( 0, 0, 0 )\n"
         "\t\tdensity 0.2\n"
         "\t\tcontents corpse\n"
         "\t\tclipMask solid, corpse\n"
         "\t\tselfCollision 1\n"
         "\t\tcontainedJoints \"*origin\"\n"
         "\t\tnoSyncCollide 0\n"
         "\t\tclearClipMaskInSolid 0\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ?Finish@idAFVector@@QBA_NPBDQ6A_NPAXPBVidJointMat@@0AAVidVec3@@AAVidMat3@@@Z21@Z
// EA  : 0x8260D508
// RVA : 0x0060D508
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idAFVector::Finish(
        idAFVector *this,
        const char *fileName,
        bool (__fastcall *const GetJointTransform)(void *, const idJointMat *, const char *, idVec3 *, idMat3 *),
        const idJointMat *frame,
        void *model)
{
  idAFVector::afVectorType_t type; // r11
  idVec3 *p_vec; // r30
  double v12; // fp31
  double v13; // fp0
  double v14; // fp13
  double v15; // fp8
  double v16; // fp7
  bool v17; // r3
  double v18; // fp31
  double v19; // fp0
  double v20; // fp13
  double v21; // fp8
  double v22; // fp7
  int result; // r3
  double v24; // fp10
  double v25; // fp9
  float v26; // [sp+50h] [-90h] BYREF
  float v27; // [sp+54h] [-8Ch]
  float v28; // [sp+58h] [-88h]
  float v29; // [sp+60h] [-80h] BYREF
  float v30; // [sp+64h] [-7Ch]
  float v31; // [sp+68h] [-78h]
  idMat3 v32; // [sp+70h] [-70h] BYREF

  type = this->type;
  if ( this->type > (unsigned int)VEC_BONEDIR )
  {
    this->vec.z = 0.0;
    this->vec.y = 0.0;
    this->vec.x = 0.0;
  }
  else if ( type != VEC_COORDS )
  {
    if ( type == VEC_JOINT )
    {
      p_vec = &this->vec;
      if ( !GetJointTransform(a1: model, a2: frame, a3: this->joint1.str, a4: &this->vec, a5: &v32) )
      {
        idLib::Warning(fmt: "invalid joint %s in joint() in '%s'", this->joint1.str, fileName);
        this->vec.z = 0.0;
        this->vec.y = 0.0;
        p_vec->x = 0.0;
      }
    }
    else if ( type == VEC_BONECENTER )
    {
      v12 = 0.0;
      if ( !GetJointTransform(a1: model, a2: frame, a3: this->joint1.str, a4: (idVec3 *)&v26, a5: &v32) )
      {
        idLib::Warning(fmt: "invalid joint %s in bonecenter() in '%s'", this->joint1.str, fileName);
        v28 = 0.0;
        v27 = 0.0;
        v26 = 0.0;
      }
      if ( GetJointTransform(a1: model, a2: frame, a3: this->joint2.str, a4: (idVec3 *)&v29, a5: &v32) )
      {
        v13 = v31;
        v14 = v30;
        v12 = v29;
      }
      else
      {
        idLib::Warning(fmt: "invalid joint %s in bonecenter() in '%s'", this->joint2.str, fileName);
        v13 = 0.0;
        v14 = 0.0;
      }
      v15 = (float)((float)v14 + v27);
      v16 = (float)((float)v13 + v28);
      this->vec.x = (float)((float)v12 + v26) * (float)0.5;
      this->vec.y = (float)v15 * (float)0.5;
      this->vec.z = (float)v16 * (float)0.5;
    }
    else
    {
      v17 = GetJointTransform(a1: model, a2: frame, a3: this->joint1.str, a4: (idVec3 *)&v26, a5: &v32);
      v18 = 0.0;
      if ( !v17 )
      {
        idLib::Warning(fmt: "invalid joint %s in bonedir() in '%s'", this->joint1.str, fileName);
        v28 = 0.0;
        v27 = 0.0;
        v26 = 0.0;
      }
      if ( GetJointTransform(a1: model, a2: frame, a3: this->joint2.str, a4: (idVec3 *)&v29, a5: &v32) )
      {
        v19 = v31;
        v20 = v30;
        v18 = v29;
      }
      else
      {
        idLib::Warning(fmt: "invalid joint %s in bonedir() in '%s'", this->joint2.str, fileName);
        v19 = 0.0;
        v20 = 0.0;
      }
      v21 = (float)((float)v20 - v27);
      v22 = (float)((float)v19 - v28);
      this->vec.x = (float)v18 - v26;
      this->vec.y = v21;
      this->vec.z = v22;
    }
  }
  result = 1;
  if ( this->negate )
  {
    v24 = -this->vec.y;
    v25 = -this->vec.z;
    this->vec.x = -this->vec.x;
    this->vec.y = v24;
    this->vec.z = v25;
  }
  return result;
}


// ========================================================================
// ?Write@idAFVector@@QBA_NPAVidFile@@@Z
// EA  : 0x8260D7B0
// RVA : 0x0060D7B0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idAFVector::Write(idAFVector *this, idFile *f)
{
  idAFVector::afVectorType_t type; // r11
  const char *v5; // r4

  if ( this->negate )
    f->WriteFloatString(this: f, a2: "-");
  type = this->type;
  if ( this->type <= (unsigned int)VEC_BONEDIR )
  {
    if ( type != VEC_JOINT )
    {
      if ( type == VEC_BONECENTER )
      {
        v5 = "bonecenter( \"%s\", \"%s\" )";
      }
      else
      {
        if ( type == VEC_COORDS )
        {
          f->WriteFloatString(
            this: f,
            a2: "( %f, %f, %f )",
            (unsigned int)COERCE_UNSIGNED_INT64(this->vec.x),
            (unsigned int)COERCE_UNSIGNED_INT64(this->vec.y),
            (unsigned int)COERCE_UNSIGNED_INT64(this->vec.z));
          return 1;
        }
        v5 = "bonedir( \"%s\", \"%s\" )";
      }
      f->WriteFloatString(this: f, a2: v5, this->joint1.str, this->joint2.str);
      return 1;
    }
    f->WriteFloatString(this: f, a2: "joint( \"%s\" )", this->joint1.str);
  }
  return 1;
}


// ========================================================================
// ?SetDefault@idDeclAF_Body@@QAAXPBVidDeclAF@@@Z
// EA  : 0x8260D8C8
// RVA : 0x0060D8C8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF_Body::SetDefault(idDeclAF_Body *this, const idDeclAF *file)
{
  idAtomicString::Set(this: &this->name, str_: "noname");
  this->modelType = 1;
  idAtomicString::Set(this: &this->modelName, str_: &byte_8200D768);
  this->v1.type = VEC_COORDS;
  this->v2.type = VEC_COORDS;
  this->numSides = 3;
  this->v2.vec.z = 10.0;
  this->v2.vec.y = 10.0;
  this->v2.vec.x = 10.0;
  this->v1.vec.z = -10.0;
  this->v1.vec.y = -10.0;
  this->v1.vec.x = -10.0;
  this->origin.vec.z = 0.0;
  this->origin.vec.y = 0.0;
  this->origin.vec.x = 0.0;
  this->angles.roll = 0.0;
  this->angles.yaw = 0.0;
  this->angles.pitch = 0.0;
  this->density = 0.0020000001;
  this->inertiaScale.mat[2].z = 1.0;
  this->inertiaScale.mat[1].y = 1.0;
  this->inertiaScale.mat[0].x = 1.0;
  this->inertiaScale.mat[1].z = 0.0;
  this->inertiaScale.mat[0].z = 0.0;
  this->inertiaScale.mat[0].y = 0.0;
  this->inertiaScale.mat[2].y = 0.0;
  this->inertiaScale.mat[2].x = 0.0;
  this->inertiaScale.mat[1].x = 0.0;
  this->bouncyness = file->defaultBouncyness;
  this->linearFriction = file->defaultLinearFriction;
  this->angularFriction = file->defaultAngularFriction;
  this->contactFriction = file->defaultContactFriction;
  this->contents = file->contents;
  this->clipMask = file->clipMask;
  this->selfCollision = file->selfCollision;
  this->noSyncCollide = false;
  this->clearClipMaskInSolid = false;
  this->frictionDirection.vec.z = 0.0;
  this->frictionDirection.vec.y = 0.0;
  this->frictionDirection.vec.x = 0.0;
  this->contactMotorDirection.vec.z = 0.0;
  this->contactMotorDirection.vec.y = 0.0;
  this->contactMotorDirection.vec.x = 0.0;
  this->jointName.str = file->base.str;
  this->jointMod = DECLAF_JOINTMOD_AXIS;
  idAtomicString::Set(this: &this->containedJoints, str_: "*origin");
}


// ========================================================================
// ?SetDefault@idDeclAF_Constraint@@QAAXPBVidDeclAF@@@Z
// EA  : 0x8260DA28
// RVA : 0x0060DA28
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF_Constraint::SetDefault(idDeclAF_Constraint *this, const idDeclAF *file)
{
  idAtomicString::Set(this: &this->name, str_: "noname");
  this->type = DECLAF_CONSTRAINT_UNIVERSALJOINT;
  if ( file->bodies.num != 0 )
    this->body1.str = **(const char ***)file->bodies.list;
  else
    idAtomicString::Set(this: &this->body1, str_: "world");
  idAtomicString::Set(this: &this->body2, str_: "world");
  this->friction = file->defaultConstraintFriction;
  this->anchor.vec.z = 0.0;
  this->anchor.vec.y = 0.0;
  this->anchor.vec.x = 0.0;
  this->anchor2.vec.z = 0.0;
  this->anchor2.vec.y = 0.0;
  this->anchor2.vec.x = 0.0;
  this->axis.vec.x = 1.0;
  this->axis.vec.y = 0.0;
  this->axis.vec.z = 0.0;
  this->shaft[0].vec.x = 0.0;
  this->shaft[0].vec.y = 0.0;
  this->shaft[0].vec.z = -1.0;
  this->shaft[1].vec.x = 0.0;
  this->shaft[1].vec.y = 0.0;
  this->shaft[1].vec.z = 1.0;
  this->limit = LIMIT_NONE;
  this->limitAngles[2] = 0.0;
  this->limitAngles[1] = 0.0;
  this->limitAngles[0] = 0.0;
  this->limitAxis.vec.x = 0.0;
  this->limitAxis.vec.y = 0.0;
  this->limitAxis.vec.z = -1.0;
  this->syncConstraint = false;
}


// ========================================================================
// ?WriteFixed@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260DB20
// RVA : 0x0060DB20
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteFixed(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  f->WriteFloatString(this: f, a2: "\nfixed \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?WriteBallAndSocketJoint@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260DBD8
// RVA : 0x0060DBD8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteBallAndSocketJoint(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  idDeclAF_Constraint::afConstraintLimit_t limit; // r11

  f->WriteFloatString(this: f, a2: "\nballAndSocketJoint \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "\tanchor ");
  idAFVector::Write(this: &c->anchor, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tfriction %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->friction));
  limit = c->limit;
  if ( limit != LIMIT_CONE )
  {
    if ( limit == LIMIT_PYRAMID )
    {
      f->WriteFloatString(this: f, a2: "\tpyramidLimit ");
      idAFVector::Write(this: &c->limitAxis, f);
      f->WriteFloatString(
        this: f,
        a2: ", %f, %f, %f, ",
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[0]),
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[1]),
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[2]));
      idAFVector::Write(this: c->shaft, f);
      f->WriteFloatString(this: f, a2: "\n");
    }
  }
  else
  {
    f->WriteFloatString(this: f, a2: "\tconeLimit ");
    idAFVector::Write(this: &c->limitAxis, f);
    f->WriteFloatString(this: f, a2: ", %f, ", (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[0]));
    idAFVector::Write(this: c->shaft, f);
    f->WriteFloatString(this: f, a2: "\n");
  }
  f->WriteFloatString(this: f, a2: "\tsyncConstraint %d\n", c->syncConstraint);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?WriteUniversalJoint@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260DE18
// RVA : 0x0060DE18
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteUniversalJoint(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  idDeclAF_Constraint::afConstraintLimit_t limit; // r11

  f->WriteFloatString(this: f, a2: "\nuniversalJoint \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "\tanchor ");
  idAFVector::Write(this: &c->anchor, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tshafts ");
  idAFVector::Write(this: c->shaft, f);
  f->WriteFloatString(this: f, a2: ", ");
  idAFVector::Write(this: &c->shaft[1], f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tfriction %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->friction));
  limit = c->limit;
  if ( limit != LIMIT_CONE )
  {
    if ( limit == LIMIT_PYRAMID )
    {
      f->WriteFloatString(this: f, a2: "\tpyramidLimit ");
      idAFVector::Write(this: &c->limitAxis, f);
      f->WriteFloatString(
        this: f,
        a2: ", %f, %f, %f\n",
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[0]),
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[1]),
        (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[2]));
    }
  }
  else
  {
    f->WriteFloatString(this: f, a2: "\tconeLimit ");
    idAFVector::Write(this: &c->limitAxis, f);
    f->WriteFloatString(this: f, a2: ", %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[0]));
  }
  f->WriteFloatString(this: f, a2: "\tsyncConstraint %d\n", c->syncConstraint);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?WriteHinge@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260E088
// RVA : 0x0060E088
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteHinge(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  idAFVector *p_axis; // r3

  f->WriteFloatString(this: f, a2: "\nhinge \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "\tanchor ");
  idAFVector::Write(this: &c->anchor, f);
  f->WriteFloatString(this: f, a2: "\n");
  if ( c->shaft[0].type == VEC_BONEDIR && c->shaft[1].type == VEC_BONEDIR )
  {
    f->WriteFloatString(this: f, a2: "\tshafts ");
    idAFVector::Write(this: c->shaft, f);
    f->WriteFloatString(this: f, a2: ", ");
    p_axis = &c->shaft[1];
  }
  else
  {
    f->WriteFloatString(this: f, a2: "\taxis ");
    p_axis = &c->axis;
  }
  idAFVector::Write(this: p_axis, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tfriction %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->friction));
  if ( c->limit == LIMIT_CONE )
  {
    f->WriteFloatString(this: f, a2: "\tlimit ");
    f->WriteFloatString(
      this: f,
      a2: "%f, %f, %f",
      (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[0]),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(c->limitAngles[2])),
      (unsigned int)COERCE_UNSIGNED_INT64(c->limitAngles[2]));
    f->WriteFloatString(this: f, a2: "\n");
  }
  f->WriteFloatString(this: f, a2: "\tsyncConstraint %d\n", c->syncConstraint);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?WriteSlider@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260E2E8
// RVA : 0x0060E2E8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteSlider(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  f->WriteFloatString(this: f, a2: "\nslider \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "\taxis ");
  idAFVector::Write(this: &c->axis, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tfriction %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->friction));
  f->WriteFloatString(this: f, a2: "\tsyncConstraint %d\n", c->syncConstraint);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?WriteSpring@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Constraint@@@Z
// EA  : 0x8260E430
// RVA : 0x0060E430
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteSpring(idDeclAF *this, idFile *f, const idDeclAF_Constraint *c)
{
  f->WriteFloatString(this: f, a2: "\nspring \"%s\" {\n", c->name.str);
  f->WriteFloatString(this: f, a2: "\tbody1 \"%s\"\n", c->body1.str);
  f->WriteFloatString(this: f, a2: "\tbody2 \"%s\"\n", c->body2.str);
  f->WriteFloatString(this: f, a2: "\tanchor1 ");
  idAFVector::Write(this: &c->anchor, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tanchor2 ");
  idAFVector::Write(this: &c->anchor2, f);
  f->WriteFloatString(this: f, a2: "\n");
  f->WriteFloatString(this: f, a2: "\tfriction %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->friction));
  f->WriteFloatString(this: f, a2: "\tstretch %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->stretch));
  f->WriteFloatString(this: f, a2: "\tcompress %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->compress));
  f->WriteFloatString(this: f, a2: "\tdamping %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->damping));
  f->WriteFloatString(this: f, a2: "\trestLength %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->restLength));
  f->WriteFloatString(this: f, a2: "\tminLength %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->minLength));
  f->WriteFloatString(this: f, a2: "\tmaxLength %f\n", (unsigned int)COERCE_UNSIGNED_INT64(c->maxLength));
  f->WriteFloatString(this: f, a2: "\tsyncConstraint %d\n", c->syncConstraint);
  f->WriteFloatString(this: f, a2: "}\n");
  return 1;
}


// ========================================================================
// ?Finish@idDeclAF@@UBAXQ6A_NPAXPBVidJointMat@@PBDAAVidVec3@@AAVidMat3@@@Z10@Z
// EA  : 0x8260E7B0
// RVA : 0x0060E7B0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF::Finish(
        idDeclAF *this,
        bool (__fastcall *const GetJointTransform)(void *, const idJointMat *, const char *, idVec3 *, idMat3 *),
        const idJointMat *frame,
        void *model)
{
  const char *str; // r28
  int v9; // r25
  int v10; // r24
  idDeclAF_Body *v11; // r27
  int v12; // r24
  int v13; // r25
  idDeclAF_Constraint *v14; // r27

  str = this->name.str;
  v9 = 0;
  if ( this->bodies.num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = this->bodies.list[v10];
      idAFVector::Finish(this: &v11->v1, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v11->v2, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v11->origin, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v11->frictionDirection, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v11->contactMotorDirection, fileName: str, GetJointTransform, frame, model);
      ++v9;
      ++v10;
    }
    while ( v9 < this->bodies.num );
  }
  v12 = 0;
  if ( this->constraints.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = this->constraints.list[v13];
      idAFVector::Finish(this: &v14->anchor, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v14->anchor2, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: v14->shaft, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v14->shaft[1], fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v14->axis, fileName: str, GetJointTransform, frame, model);
      idAFVector::Finish(this: &v14->limitAxis, fileName: str, GetJointTransform, frame, model);
      ++v12;
      ++v13;
    }
    while ( v12 < this->constraints.num );
  }
}


// ========================================================================
// ?Parse@idAFVector@@QAA_NAAVidParser@@@Z
// EA  : 0x8260E948
// RVA : 0x0060E948
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idAFVector::Parse(idAFVector *this, idParser *src)
{
  idAFVector::afVectorType_t v4; // r11
  idToken v6; // [sp+50h] [-180h] BYREF
  char v7; // [sp+98h] [-138h] BYREF

  v6.baseBuffer[0] = 0;
  v6.floatvalue = -3.4028235e38;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  v7 = 0;
  v6.data = &v7;
  v6.len = 0;
  v6.allocedAndFlag = -2147483392;
  if ( !idParser::ReadToken(this: src, token: &v6) )
    goto LABEL_17;
  if ( idStr::Cmp(s1: v6.data, s2: "-") != 0 )
  {
    this->negate = false;
  }
  else
  {
    this->negate = true;
    if ( !idParser::ReadToken(this: src, token: &v6) )
      goto LABEL_17;
  }
  if ( idStr::Cmp(s1: v6.data, s2: "(") == 0 )
  {
    this->type = VEC_COORDS;
    this->vec.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
    idParser::ExpectTokenString(this: src, string: ",");
    this->vec.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
    idParser::ExpectTokenString(this: src, string: ",");
    this->vec.z = idParser::ParseFloat(this: src, errorFlag: nullptr);
LABEL_15:
    idParser::ExpectTokenString(this: src, string: ")");
    idStr::FreeData(this: &v6);
    return 1;
  }
  if ( idStr::Cmp(s1: v6.data, s2: "joint") == 0 )
  {
    this->type = VEC_JOINT;
    idParser::ExpectTokenString(this: src, string: "(");
    idParser::ReadToken(this: src, token: &v6);
    idStr::ToLower(this: &v6);
    idAtomicString::Set(this: &this->joint1, str_: v6.data);
    goto LABEL_15;
  }
  if ( idStr::Cmp(s1: v6.data, s2: "bonecenter") == 0 )
  {
    v4 = VEC_BONECENTER;
LABEL_14:
    this->type = v4;
    idParser::ExpectTokenString(this: src, string: "(");
    idParser::ReadToken(this: src, token: &v6);
    idStr::ToLower(this: &v6);
    idAtomicString::Set(this: &this->joint1, str_: v6.data);
    idParser::ExpectTokenString(this: src, string: ",");
    idParser::ReadToken(this: src, token: &v6);
    idStr::ToLower(this: &v6);
    idAtomicString::Set(this: &this->joint2, str_: v6.data);
    goto LABEL_15;
  }
  if ( idStr::Cmp(s1: v6.data, s2: "bonedir") == 0 )
  {
    v4 = VEC_BONEDIR;
    goto LABEL_14;
  }
  idParser::Error(this: src, str: "unknown token %s in vector", v6.data);
LABEL_17:
  idStr::FreeData(this: &v6);
  return 0;
}


// ========================================================================
// __unwind$223135
// EA  : 0x8260EBB0
// RVA : 0x0060EBB0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223135()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?ContentsFromString@idDeclAF@@SAHPBD@Z
// EA  : 0x8260EBE0
// RVA : 0x0060EBE0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ContentsFromString(const char *str)
{
  unsigned int v2; // r5
  int v3; // r30
  idToken v5; // [sp+50h] [-240h] BYREF
  char v6; // [sp+98h] [-1F8h] BYREF
  idLexer v7; // [sp+1A0h] [-F0h] BYREF

  v5.baseBuffer[0] = 0;
  v5.floatvalue = -3.4028235e38;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  v6 = 0;
  v5.len = 0;
  v5.data = &v6;
  v5.allocedAndFlag = -2147483392;
  idLexer::idLexer(this: &v7, flags_: 0);
  v2 = 0;
  if ( *str != 0 )
  {
    do
      ++v2;
    while ( str[v2] != 0 );
  }
  idLexer::LoadMemory(this: &v7, ptr: str, length_: v2, name: "idDeclAF::ContentsFromString");
LABEL_4:
  v3 = 0;
  while ( idLexer::ReadToken(this: &v7, token: &v5) )
  {
    if ( idStr::Icmp(s1: v5.data, s2: "none") == 0 )
      goto LABEL_4;
    if ( idStr::Icmp(s1: v5.data, s2: "solid") != 0 )
    {
      if ( idStr::Icmp(s1: v5.data, s2: "ikclip") != 0 )
      {
        if ( idStr::Icmp(s1: v5.data, s2: "ai") != 0 )
        {
          if ( idStr::Icmp(s1: v5.data, s2: "corpse") != 0 )
          {
            if ( idStr::Icmp(s1: v5.data, s2: "player") != 0 )
            {
              if ( idStr::Icmp(s1: v5.data, s2: "playerclip") != 0 )
              {
                if ( idStr::Icmp(s1: v5.data, s2: "monsterclip") != 0 )
                {
                  if ( idStr::Cmp(s1: v5.data, s2: ",") != 0 )
                    break;
                }
                else
                {
                  v3 |= 0x10u;
                }
              }
              else
              {
                v3 |= 8u;
              }
            }
            else
            {
              v3 |= 0x8000u;
            }
          }
          else
          {
            v3 |= 0x1000u;
          }
        }
        else
        {
          v3 |= 0x400u;
        }
      }
      else
      {
        v3 |= 0x100u;
      }
    }
    else
    {
      v3 |= 1u;
    }
  }
  idLexer::~idLexer(this: &v7);
  idStr::FreeData(this: &v5);
  return v3;
}


// ========================================================================
// __unwind$223426
// EA  : 0x8260EDEC
// RVA : 0x0060EDEC
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223426()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 80));
}


// ========================================================================
// __unwind$223427
// EA  : 0x8260EE14
// RVA : 0x0060EE14
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223427()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 656 + 416));
}


// ========================================================================
// ?ParseSolverConstants@idDeclAF@@AAA_NAAVidParser@@AAUsolverConstants_t@1@@Z
// EA  : 0x8260EE48
// RVA : 0x0060EE48
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseSolverConstants(idDeclAF *this, idParser *src, idDeclAF::solverConstants_t *c)
{
  idToken v6; // [sp+50h] [-1D0h] BYREF
  char v7; // [sp+98h] [-188h] BYREF

  v6.baseBuffer[0] = 0;
  v6.floatvalue = -3.4028235e38;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  v7 = 0;
  v6.data = &v7;
  v6.len = 0;
  v6.allocedAndFlag = -2147483392;
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v6);
  if ( idParser::ReadToken(this: src, token: &v6) )
  {
    while ( v6.type != 5 || v6.subtype != 47 )
    {
      if ( idStr::Icmp(s1: v6.data, s2: "errorReduction") != 0 )
      {
        if ( idStr::Icmp(s1: v6.data, s2: "errorReductionMax") != 0 )
        {
          if ( idStr::Icmp(s1: v6.data, s2: "lcpEpsilon") != 0 )
          {
            if ( idStr::Icmp(s1: v6.data, s2: "limitErrorReduction") != 0 )
            {
              if ( idStr::Icmp(s1: v6.data, s2: "limitErrorReductionMax") != 0 )
              {
                if ( idStr::Icmp(s1: v6.data, s2: "limitLcpEpsilon") != 0 )
                {
                  if ( idStr::Icmp(s1: v6.data, s2: "contactErrorReduction") != 0 )
                  {
                    if ( idStr::Icmp(s1: v6.data, s2: "contactErrorReductionMax") != 0 )
                    {
                      if ( idStr::Icmp(s1: v6.data, s2: "contactLcpEpsilon") != 0 )
                      {
                        if ( idStr::Icmp(s1: v6.data, s2: "universalErrorReduction") != 0 )
                        {
                          if ( idStr::Icmp(s1: v6.data, s2: "universalErrorReductionMax") != 0 )
                          {
                            if ( idStr::Icmp(s1: v6.data, s2: "universalTorsionLcpEpsilon") != 0 )
                            {
                              idParser::Error(this: src, str: "unknown token in solver constants: %s", v6.data);
                              idStr::FreeData(this: &v6);
                              return 0;
                            }
                            c->universalTorsionLcpEpsilon = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                          else
                          {
                            c->universalErrorReductionMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          c->universalErrorReduction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        c->contactLcpEpsilon = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      c->contactErrorReductionMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    c->contactErrorReduction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  c->limitLcpEpsilon = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                c->limitErrorReductionMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              c->limitErrorReduction = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            c->lcpEpsilon = idParser::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          c->errorReductionMax = idParser::ParseFloat(this: src, errorFlag: nullptr);
        }
      }
      else
      {
        c->errorReduction = idParser::ParseFloat(this: src, errorFlag: nullptr);
      }
      if ( !idParser::ReadToken(this: src, token: &v6) )
        break;
    }
  }
  idStr::FreeData(this: &v6);
  return 1;
}


// ========================================================================
// __unwind$223596
// EA  : 0x8260F16C
// RVA : 0x0060F16C
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 80));
}


// ========================================================================
// ?ContentsToString@idDeclAF@@SAPBDHAAVidStr@@@Z
// EA  : 0x8260F238
// RVA : 0x0060F238
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

char *__fastcall idDeclAF::ContentsToString(__int16 contents, idStr *str)
{
  idStr::operator=(this: str, text: &byte_8200D768);
  if ( (contents & 1) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "solid");
  }
  if ( (contents & 0x100) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "ikclip");
  }
  if ( (contents & 0x400) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "ai");
  }
  if ( (contents & 0x1000) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "corpse");
  }
  if ( (contents & 8) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "playerclip");
  }
  if ( (contents & 0x10) != 0 )
  {
    if ( str->len != 0 )
      idStr::Append(this: str, text: ", ");
    idStr::Append(this: str, text: "monsterclip");
  }
  if ( *str->data == 0 )
    idStr::operator=(this: str, text: "none");
  return str->data;
}


// ========================================================================
// ?ParseContents@idDeclAF@@ABA_NAAVidParser@@AAH@Z
// EA  : 0x8260F3D0
// RVA : 0x0060F3D0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseContents(idDeclAF *this, idParser *src, int *c)
{
  idStr v6; // [sp+50h] [-190h] BYREF
  idToken v7; // [sp+70h] [-170h] BYREF
  char v8; // [sp+B8h] [-128h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  while ( idParser::ReadToken(this: src, token: &v7) )
  {
    idStr::Append(this: &v6, text: &v7);
    if ( idParser::CheckTokenString(this: src, string: ",") == 0 )
      break;
    idStr::Append(this: &v6, text: ",");
  }
  *c = idDeclAF::ContentsFromString(str: v6.data);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: &v7);
  return 1;
}


// ========================================================================
// __unwind$223983
// EA  : 0x8260F4CC
// RVA : 0x0060F4CC
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223983()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 112));
}


// ========================================================================
// __unwind$223984
// EA  : 0x8260F4F4
// RVA : 0x0060F4F4
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_223984()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// ?ParseSettings@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x8260F670
// RVA : 0x0060F670
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseSettings(idDeclAF *this, idParser *src)
{
  char *data; // r10
  const idDeclMD6 *v4; // r3
  const idMaterial *v5; // r3
  idToken v7; // [sp+80h] [-1E0h] BYREF
  char v8; // [sp+C8h] [-198h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  if ( idParser::ExpectTokenString(this: src, string: "{") )
  {
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "mesh") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "anim") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "model") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "clipMaterial") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "skin") != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: "defaultBouncyness") != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: "defaultLinearFriction") != 0 )
                    {
                      if ( idStr::Icmp(s1: v7.data, s2: "defaultAngularFriction") != 0 )
                      {
                        if ( idStr::Icmp(s1: v7.data, s2: "defaultContactFriction") != 0 )
                        {
                          if ( idStr::Icmp(s1: v7.data, s2: "defaultConstraintFriction") != 0 )
                          {
                            if ( idStr::Icmp(s1: v7.data, s2: "suspendSpeed") != 0 )
                            {
                              if ( idStr::Icmp(s1: v7.data, s2: "noMoveTime") != 0 )
                              {
                                if ( idStr::Icmp(s1: v7.data, s2: "noMoveTranslation") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v7.data, s2: "noMoveRotation") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v7.data, s2: "minMoveTime") != 0 )
                                    {
                                      if ( idStr::Icmp(s1: v7.data, s2: "maxMoveTime") != 0 )
                                      {
                                        if ( idStr::Icmp(s1: v7.data, s2: "contents") != 0 )
                                        {
                                          if ( idStr::Icmp(s1: v7.data, s2: "clipMask") != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v7.data, s2: "selfCollision") != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v7.data, s2: "base") != 0 )
                                              {
                                                if ( idStr::Cmp(s1: v7.data, s2: "solverConstants") != 0 )
                                                {
                                                  if ( idStr::Cmp(s1: v7.data, s2: "syncSolverConstants") != 0 )
                                                  {
                                                    idParser::Error(
                                                      this: src,
                                                      str: "unknown token %s in settings",
                                                      v7.data);
                                                    idStr::FreeData(this: &v7);
                                                    return 0;
                                                  }
                                                  if ( (unsigned __int8)idDeclAF::ParseSolverConstants(
                                                                          this,
                                                                          src,
                                                                          c: &this->syncSolverConstants) == 0 )
                                                    goto LABEL_63;
                                                }
                                                else if ( (unsigned __int8)idDeclAF::ParseSolverConstants(
                                                                             this,
                                                                             src,
                                                                             c: &this->solverConstants) == 0 )
                                                {
                                                  goto LABEL_63;
                                                }
                                              }
                                              else
                                              {
                                                idParser::ReadToken(this: src, token: &v7);
                                                idStr::ToLower(this: &v7);
                                                idAtomicString::Set(this: &this->base, str_: v7.data);
                                              }
                                            }
                                            else
                                            {
                                              this->selfCollision = idParser::ParseBool(this: src);
                                            }
                                          }
                                          else
                                          {
                                            idDeclAF::ParseContents(this, src, c: &this->clipMask);
                                          }
                                        }
                                        else
                                        {
                                          idDeclAF::ParseContents(this, src, c: &this->contents);
                                        }
                                      }
                                      else
                                      {
                                        this->maxMoveTime = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                      }
                                    }
                                    else
                                    {
                                      this->minMoveTime = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                    }
                                  }
                                  else
                                  {
                                    this->noMoveRotation = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                  }
                                }
                                else
                                {
                                  this->noMoveTranslation = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                }
                              }
                              else
                              {
                                this->noMoveTime = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              this->suspendVelocity.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              if ( !idParser::ExpectTokenString(this: src, string: ",") )
                                goto LABEL_63;
                              this->suspendVelocity.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              if ( !idParser::ExpectTokenString(this: src, string: ",") )
                                goto LABEL_63;
                              this->suspendAcceleration.x = idParser::ParseFloat(this: src, errorFlag: nullptr);
                              if ( !idParser::ExpectTokenString(this: src, string: ",") )
                                goto LABEL_63;
                              this->suspendAcceleration.y = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            }
                          }
                          else
                          {
                            this->defaultConstraintFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          this->defaultContactFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        this->defaultAngularFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      this->defaultLinearFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    this->defaultBouncyness = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) == 0 )
                    goto LABEL_63;
                  idAtomicString::Set(this: &this->skin, str_: v7.data);
                }
              }
              else
              {
                if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) == 0 )
                  goto LABEL_63;
                if ( v7.data != nullptr )
                  v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                             this: &idMaterial::resourceList,
                                             name: v7.data,
                                             makeDefault: false);
                else
                  v5 = nullptr;
                this->clipMaterial = v5;
                if ( v5 == nullptr )
                  break;
              }
            }
            else
            {
              if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) == 0 )
                goto LABEL_63;
              data = v7.data;
              if ( v7.data != nullptr )
              {
                v4 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                          this: &idDeclMD6::resourceList,
                                          name: v7.data,
                                          makeDefault: true);
                data = v7.data;
              }
              else
              {
                v4 = nullptr;
              }
              this->modelDef = v4;
              if ( v4 == nullptr )
                idLib::Warning(fmt: "AF '%s' references an invalid model '%s'.", this->name.str, data);
            }
          }
          else if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) == 0 )
          {
            goto LABEL_63;
          }
        }
        else if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) == 0 )
        {
          goto LABEL_63;
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
LABEL_63:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$224310
// EA  : 0x8260FE0C
// RVA : 0x0060FE0C
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_224310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 128));
}


// ========================================================================
// ?WriteBody@idDeclAF@@ABA_NPAVidFile@@ABVidDeclAF_Body@@@Z
// EA  : 0x8260FE40
// RVA : 0x0060FE40
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteBody(idDeclAF *this, idFile *f, const idDeclAF_Body *body)
{
  declAFJointMod_t jointMod; // r11
  const char *v6; // r5
  char v7; // r11
  double linearFriction; // fp1
  double angularFriction; // fp1
  double contactFriction; // fp1
  idFile_vtbl *v11; // r28
  char *v12; // r3
  idFile_vtbl *v13; // r28
  char *v14; // r3
  double x; // fp0
  double v16; // fp12
  double y; // fp13
  char v18; // r11
  char v19; // r11
  double z; // [sp+48h] [-98h]
  idStr v22; // [sp+80h] [-60h] BYREF

  v22.len = 0;
  v22.allocedAndFlag = 20;
  v22.data = v22.baseBuffer;
  v22.baseBuffer[0] = 0;
  f->WriteFloatString(this: f, a2: "\nbody \"%s\" {\n", body->name.str);
  f->WriteFloatString(this: f, a2: "\tjoint \"%s\"\n", body->jointName.str);
  jointMod = body->jointMod;
  if ( jointMod != DECLAF_JOINTMOD_AXIS )
  {
    if ( jointMod == DECLAF_JOINTMOD_ORIGIN )
    {
      v6 = "position";
      goto LABEL_7;
    }
    if ( (unsigned int)jointMod < (DECLAF_JOINTMOD_BOTH|DECLAF_JOINTMOD_ORIGIN) )
    {
      v6 = "both";
      goto LABEL_7;
    }
  }
  v6 = "orientation";
LABEL_7:
  f->WriteFloatString(this: f, a2: "\tmod %s\n", v6);
  if ( (unsigned int)(body->modelType - 1) <= 8 )
  {
    if ( body->modelType == 2 )
    {
      f->WriteFloatString(this: f, a2: "\tmodel octahedron( ");
LABEL_23:
      idAFVector::Write(this: &body->v1, f);
      f->WriteFloatString(this: f, a2: ", ");
      idAFVector::Write(this: &body->v2, f);
      f->WriteFloatString(this: f, a2: " )\n");
      goto LABEL_24;
    }
    if ( body->modelType == 3 )
    {
      f->WriteFloatString(this: f, a2: "\tmodel dodecahedron( ");
      goto LABEL_23;
    }
    if ( body->modelType == 4 )
    {
      f->WriteFloatString(this: f, a2: "\tmodel cylinder( ");
      idAFVector::Write(this: &body->v1, f);
      f->WriteFloatString(this: f, a2: ", ");
      idAFVector::Write(this: &body->v2, f);
      f->WriteFloatString(this: f, a2: ", %d )\n", body->numSides);
    }
    else if ( body->modelType == 5 )
    {
      f->WriteFloatString(this: f, a2: "\tmodel cone( ");
      idAFVector::Write(this: &body->v1, f);
      f->WriteFloatString(this: f, a2: ", ");
      idAFVector::Write(this: &body->v2, f);
      f->WriteFloatString(this: f, a2: ", %d )\n", body->numSides);
    }
    else if ( body->modelType == 6 )
    {
      f->WriteFloatString(this: f, a2: "\tmodel bone( ");
      idAFVector::Write(this: &body->v1, f);
      f->WriteFloatString(this: f, a2: ", ");
      idAFVector::Write(this: &body->v2, f);
      f->WriteFloatString(this: f, a2: ", %f )\n", (unsigned int)COERCE_UNSIGNED_INT64(body->width));
    }
    else if ( body->modelType != 7 && body->modelType != 8 )
    {
      if ( body->modelType == 1 )
        f->WriteFloatString(this: f, a2: "\tmodel box( ");
      else
        f->WriteFloatString(this: f, a2: "\tmodel custom( \"%s\", ", body->modelName.str);
      goto LABEL_23;
    }
  }
LABEL_24:
  f->WriteFloatString(this: f, a2: "\torigin ");
  idAFVector::Write(this: &body->origin, f);
  f->WriteFloatString(this: f, a2: "\n");
  if ( ang_zero.pitch != body->angles.pitch
    || ang_zero.yaw != body->angles.yaw
    || (v7 = 1, ang_zero.roll != body->angles.roll) )
  {
    v7 = 0;
  }
  if ( v7 == 0 )
    f->WriteFloatString(
      this: f,
      a2: "\tangles ( %f, %f, %f )\n",
      (unsigned int)COERCE_UNSIGNED_INT64(body->angles.pitch),
      (unsigned int)COERCE_UNSIGNED_INT64(body->angles.yaw),
      (unsigned int)COERCE_UNSIGNED_INT64(body->angles.roll));
  f->WriteFloatString(this: f, a2: "\tdensity %f\n", (unsigned int)COERCE_UNSIGNED_INT64(body->density));
  if ( (unsigned __int8)idMat3::Compare(this: &body->inertiaScale, a: &mat3_identity) == 0 )
  {
    z = body->inertiaScale.mat[1].z;
    ((void (__fastcall *)(idFile *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))HIDWORD(z))(
      a1: f,
      a2: HIDWORD(COERCE_UNSIGNED_INT64(body->inertiaScale.mat[0].x)),
      a3: HIDWORD(COERCE_UNSIGNED_INT64(body->inertiaScale.mat[0].y)),
      a4: COERCE_UNSIGNED_INT64(body->inertiaScale.mat[0].y),
      a5: HIDWORD(COERCE_UNSIGNED_INT64(body->inertiaScale.mat[1].x)),
      a6: COERCE_UNSIGNED_INT64(body->inertiaScale.mat[1].x),
      a7: COERCE_UNSIGNED_INT64(body->inertiaScale.mat[1].y),
      a8: LODWORD(z));
  }
  linearFriction = body->linearFriction;
  if ( linearFriction != -1.0 )
    f->WriteFloatString(this: f, a2: "\tlinearFriction %f\n", LODWORD(linearFriction));
  angularFriction = body->angularFriction;
  if ( angularFriction != -1.0 )
    f->WriteFloatString(this: f, a2: (const char *)HIDWORD(angularFriction), LODWORD(angularFriction));
  contactFriction = body->contactFriction;
  if ( contactFriction != -1.0 )
    f->WriteFloatString(this: f, a2: (const char *)HIDWORD(contactFriction), LODWORD(contactFriction));
  v11 = f->__vftable;
  v12 = idDeclAF::ContentsToString(contents: body->contents, str: &v22);
  v11->WriteFloatString(this: f, a2: "\tcontents %s\n", v12);
  v13 = f->__vftable;
  v14 = idDeclAF::ContentsToString(contents: body->clipMask, str: &v22);
  v13->WriteFloatString(this: f, a2: "\tclipMask %s\n", v14);
  f->WriteFloatString(this: f, a2: "\tselfCollision %d\n", body->selfCollision);
  f->WriteFloatString(this: f, a2: "\tnoSyncCollide %d\n", body->noSyncCollide);
  f->WriteFloatString(this: f, a2: "\tclearClipMaskInSolid %d\n", body->clearClipMaskInSolid);
  f->WriteFloatString(this: f, a2: "\tbouncyness %f\n", (unsigned int)COERCE_UNSIGNED_INT64(body->bouncyness));
  x = vec3_origin.x;
  v16 = vec3_origin.z;
  y = vec3_origin.y;
  if ( body->frictionDirection.vec.x != vec3_origin.x
    || body->frictionDirection.vec.y != y
    || (v18 = 1, body->frictionDirection.vec.z != v16) )
  {
    v18 = 0;
  }
  if ( v18 == 0 )
  {
    f->WriteFloatString(this: f, a2: "\tfrictionDirection ");
    idAFVector::Write(this: &body->frictionDirection, f);
    f->WriteFloatString(this: f, a2: "\n");
    v16 = vec3_origin.z;
    y = vec3_origin.y;
    x = vec3_origin.x;
  }
  if ( body->contactMotorDirection.vec.x != x
    || body->contactMotorDirection.vec.y != y
    || (v19 = 1, body->contactMotorDirection.vec.z != v16) )
  {
    v19 = 0;
  }
  if ( v19 == 0 )
  {
    f->WriteFloatString(this: f, a2: "\tcontactMotorDirection ");
    idAFVector::Write(this: &body->contactMotorDirection, f);
    f->WriteFloatString(this: f, a2: "\n");
  }
  f->WriteFloatString(this: f, a2: "\tcontainedJoints \"%s\"\n", body->containedJoints.str);
  f->WriteFloatString(this: f, a2: "}\n");
  idStr::FreeData(this: &v22);
  return 1;
}


// ========================================================================
// __unwind$224875
// EA  : 0x826105F0
// RVA : 0x006105F0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_224875()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?WriteSettings@idDeclAF@@ABA_NPAVidFile@@@Z
// EA  : 0x82610620
// RVA : 0x00610620
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::WriteSettings(idDeclAF *this, idFile *f)
{
  const idDeclMD6 *modelDef; // r11
  char *str; // r5
  const idMaterial *clipMaterial; // r11
  idFile_vtbl *v7; // r28
  char *v8; // r3
  idFile_vtbl *v9; // r28
  char *v10; // r3
  idStr v12[2]; // [sp+50h] [-50h] BYREF

  v12[0].len = 0;
  v12[0].allocedAndFlag = 20;
  v12[0].data = v12[0].baseBuffer;
  v12[0].baseBuffer[0] = 0;
  f->WriteFloatString(this: f, a2: "\nsettings {\n");
  modelDef = this->modelDef;
  if ( modelDef != nullptr )
    str = (char *)modelDef->name.str;
  else
    str = &byte_8200D768;
  f->WriteFloatString(this: f, a2: "\tmodel \"%s\"\n", str);
  f->WriteFloatString(this: f, a2: "\tskin \"%s\"\n", this->skin.str);
  clipMaterial = this->clipMaterial;
  if ( clipMaterial != nullptr )
    f->WriteFloatString(this: f, a2: "\tclipMaterial \"%s\"\n", clipMaterial->name.str);
  f->WriteFloatString(
    this: f,
    a2: "\tdefaultBouncyness %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->defaultBouncyness));
  f->WriteFloatString(
    this: f,
    a2: "\tdefaultLinearFriction %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->defaultLinearFriction));
  f->WriteFloatString(
    this: f,
    a2: "\tdefaultAngularFriction %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->defaultAngularFriction));
  f->WriteFloatString(
    this: f,
    a2: "\tdefaultContactFriction %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->defaultContactFriction));
  f->WriteFloatString(
    this: f,
    a2: "\tdefaultConstraintFriction %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->defaultConstraintFriction));
  f->WriteFloatString(
    this: f,
    a2: "\tsuspendSpeed %f, %f, %f, %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->suspendVelocity.x),
    (unsigned int)COERCE_UNSIGNED_INT64(this->suspendVelocity.y),
    (unsigned int)COERCE_UNSIGNED_INT64(this->suspendAcceleration.x),
    (unsigned int)COERCE_UNSIGNED_INT64(this->suspendAcceleration.y));
  f->WriteFloatString(this: f, a2: "\tnoMoveTime %f\n", (unsigned int)COERCE_UNSIGNED_INT64(this->noMoveTime));
  f->WriteFloatString(
    this: f,
    a2: "\tnoMoveTranslation %f\n",
    (unsigned int)COERCE_UNSIGNED_INT64(this->noMoveTranslation));
  f->WriteFloatString(this: f, a2: "\tnoMoveRotation %f\n", (unsigned int)COERCE_UNSIGNED_INT64(this->noMoveRotation));
  f->WriteFloatString(this: f, a2: "\tminMoveTime %f\n", (unsigned int)COERCE_UNSIGNED_INT64(this->minMoveTime));
  f->WriteFloatString(this: f, a2: "\tmaxMoveTime %f\n", (unsigned int)COERCE_UNSIGNED_INT64(this->maxMoveTime));
  v7 = f->__vftable;
  v8 = idDeclAF::ContentsToString(contents: this->contents, str: v12);
  v7->WriteFloatString(this: f, a2: "\tcontents %s\n", v8);
  v9 = f->__vftable;
  v10 = idDeclAF::ContentsToString(contents: this->clipMask, str: v12);
  v9->WriteFloatString(this: f, a2: "\tclipMask %s\n", v10);
  f->WriteFloatString(this: f, a2: "\tselfCollision %d\n", this->selfCollision);
  idDeclAF::WriteSolverConstants(this, f, c: &this->solverConstants, name: "solverConstants", indent: "\t");
  idDeclAF::WriteSolverConstants(this, f, c: &this->syncSolverConstants, name: "syncSolverConstants", indent: "\t");
  f->WriteFloatString(this: f, a2: "}\n");
  idStr::FreeData(this: v12);
  return 1;
}


// ========================================================================
// __unwind$225109
// EA  : 0x826109B8
// RVA : 0x006109B8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_225109()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?RebuildTextSource@idDeclAF@@UAA_NXZ
// EA  : 0x826109E8
// RVA : 0x006109E8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::RebuildTextSource(idDeclAF *this)
{
  int v2; // r28
  int v3; // r29
  int v4; // r28
  int v5; // r29
  idDeclAF_Constraint *v6; // r5
  char v7; // r3
  idFile_Memory v9; // [sp+50h] [-180h] BYREF

  idFile_Memory::idFile_Memory(this: &v9);
  idFile::WriteFloatString(this: &v9, fmt: "{\n");
  if ( (unsigned __int8)idDeclAF::WriteSettings(this, f: &v9) != 0 )
  {
    v2 = 0;
    if ( this->bodies.num <= 0 )
    {
LABEL_6:
      v4 = 0;
      if ( this->constraints.num <= 0 )
      {
LABEL_24:
        idFile::WriteFloatString(this: &v9, fmt: "\n}");
        idDecl::SetText(this: &this->idDecl, text: v9.filePtr, length: 0);
        idFile_Memory::~idFile_Memory(this: &v9);
        return 1;
      }
      v5 = 0;
      while ( 1 )
      {
        v6 = this->constraints.list[v5];
        if ( (unsigned int)(v6->type - 1) > 5 )
        {
          v7 = 0;
        }
        else
        {
          switch ( v6->type )
          {
            case DECLAF_CONSTRAINT_FIXED:
              v7 = idDeclAF::WriteFixed(this, f: &v9, c: v6);
              break;
            case DECLAF_CONSTRAINT_BALLANDSOCKETJOINT:
              v7 = idDeclAF::WriteBallAndSocketJoint(this, f: &v9, c: v6);
              break;
            case DECLAF_CONSTRAINT_UNIVERSALJOINT:
              v7 = idDeclAF::WriteUniversalJoint(this, f: &v9, c: v6);
              break;
            case DECLAF_CONSTRAINT_HINGE:
              v7 = idDeclAF::WriteHinge(this, f: &v9, c: v6);
              break;
            default:
              v7 = v6->type == DECLAF_CONSTRAINT_SLIDER
                 ? idDeclAF::WriteSlider(this, f: &v9, c: v6)
                 : idDeclAF::WriteSpring(this, f: &v9, c: v6);
              break;
          }
        }
        if ( v7 == 0 )
          break;
        ++v4;
        ++v5;
        if ( v4 >= this->constraints.num )
          goto LABEL_24;
      }
    }
    else
    {
      v3 = 0;
      while ( (unsigned __int8)idDeclAF::WriteBody(this, f: &v9, body: this->bodies.list[v3]) != 0 )
      {
        ++v2;
        ++v3;
        if ( v2 >= this->bodies.num )
          goto LABEL_6;
      }
    }
  }
  idFile_Memory::~idFile_Memory(this: &v9);
  return 0;
}


// ========================================================================
// __unwind$225214
// EA  : 0x82610BA8
// RVA : 0x00610BA8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_225214()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 464 + 80));
}


// ========================================================================
// ?ParseBody@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82610CC0
// RVA : 0x00610CC0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseBody(idDeclAF *this, idParser *src)
{
  idDeclAF_Body *v2; // r29
  idDeclAF_Body *v5; // r3
  double y; // fp0
  double z; // fp13
  idDeclMD6 *modelDef; // r3
  char v10; // [sp+50h] [-250h]
  idDeclAF_Body *v11; // [sp+5Ch] [-244h]
  idAFVector v12; // [sp+A0h] [-200h] BYREF
  idToken v13; // [sp+C0h] [-1E0h] BYREF
  char v14; // [sp+108h] [-198h] BYREF

  v2 = nullptr;
  v13.baseBuffer[0] = 0;
  v13.floatvalue = -3.4028235e38;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  v10 = 0;
  v14 = 0;
  v13.data = &v14;
  v13.len = 0;
  v13.allocedAndFlag = -2147483392;
  v12.type = VEC_COORDS;
  v12.negate = false;
  v12.vec.z = 0.0;
  v12.vec.y = 0.0;
  v12.vec.x = 0.0;
  v12.joint1.str = &byte_8200D768;
  v12.joint2.str = &byte_8200D768;
  v5 = (idDeclAF_Body *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x10Cu,
                          tag: TAG_AF,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v2 = idDeclAF_Body::idDeclAF_Body(this: v5);
  v11 = v2;
  *idList<unsigned char *,5>::Alloc(this: (idList<idDeclAF_Constraint *,71> *)&this->bodies) = (idDeclAF_Constraint *)v2;
  idDeclAF_Body::SetDefault(this: v2, file: this);
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    idAtomicString::Set(this: &v2->name, str_: v13.data);
    if ( idStr::Icmp(s1: v2->name.str, s2: "origin") != 0 && idStr::Icmp(s1: v2->name.str, s2: "world") != 0 )
    {
      while ( idParser::ReadToken(this: src, token: &v13) )
      {
        if ( v13.type == 5 )
        {
          if ( v13.subtype == 47 )
            break;
          v2 = v11;
        }
        if ( idStr::Icmp(s1: v13.data, s2: "model") != 0 )
        {
          if ( idStr::Icmp(s1: v13.data, s2: "origin") != 0 )
          {
            if ( idStr::Icmp(s1: v13.data, s2: "angles") != 0 )
            {
              if ( idStr::Icmp(s1: v13.data, s2: "joint") != 0 )
              {
                if ( idStr::Icmp(s1: v13.data, s2: "mod") != 0 )
                {
                  if ( idStr::Icmp(s1: v13.data, s2: "density") != 0 )
                  {
                    if ( idStr::Icmp(s1: v13.data, s2: "inertiaScale") != 0 )
                    {
                      if ( idStr::Icmp(s1: v13.data, s2: "linearFriction") != 0 )
                      {
                        if ( idStr::Icmp(s1: v13.data, s2: "angularFriction") != 0 )
                        {
                          if ( idStr::Icmp(s1: v13.data, s2: "contactFriction") != 0 )
                          {
                            if ( idStr::Icmp(s1: v13.data, s2: "contents") != 0 )
                            {
                              if ( idStr::Icmp(s1: v13.data, s2: "clipMask") != 0 )
                              {
                                if ( idStr::Icmp(s1: v13.data, s2: "selfCollision") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v13.data, s2: "bouncyness") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v13.data, s2: "noSyncCollide") != 0 )
                                    {
                                      if ( idStr::Icmp(s1: v13.data, s2: "clearClipMaskInSolid") != 0 )
                                      {
                                        if ( idStr::Icmp(s1: v13.data, s2: "containedjoints") != 0 )
                                        {
                                          if ( idStr::Icmp(s1: v13.data, s2: "frictionDirection") != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v13.data, s2: "contactMotorDirection") != 0 )
                                            {
                                              idParser::Error(this: src, str: "unknown token %s in body", v13.data);
                                              goto _M226269;
                                            }
                                            if ( (unsigned __int8)idAFVector::Parse(
                                                                    this: &v2->contactMotorDirection,
                                                                    src) == 0 )
                                              goto _M226269;
                                          }
                                          else if ( (unsigned __int8)idAFVector::Parse(
                                                                       this: &v2->frictionDirection,
                                                                       src) == 0 )
                                          {
                                            goto _M226269;
                                          }
                                        }
                                        else
                                        {
                                          if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13) == 0 )
                                            goto _M226269;
                                          idAtomicString::Set(this: &v2->containedJoints, str_: v13.data);
                                          modelDef = this->modelDef;
                                          if ( modelDef != nullptr )
                                            idDeclMD6::GetJointList(
                                              this: modelDef,
                                              joints: v2->containedJoints.str,
                                              jointList: (idList<idIndex<short,enum invalidJointIndex_t>,5> *)&v2->containedJointIndices);
                                        }
                                      }
                                      else
                                      {
                                        v2->clearClipMaskInSolid = idParser::ParseBool(this: src);
                                      }
                                    }
                                    else
                                    {
                                      v2->noSyncCollide = idParser::ParseBool(this: src);
                                    }
                                  }
                                  else
                                  {
                                    v2->bouncyness = idParser::ParseFloat(this: src, errorFlag: nullptr);
                                  }
                                }
                                else
                                {
                                  v2->selfCollision = idParser::ParseBool(this: src);
                                }
                              }
                              else
                              {
                                idDeclAF::ParseContents(this, src, c: &v2->clipMask);
                              }
                            }
                            else
                            {
                              idDeclAF::ParseContents(this, src, c: &v2->contents);
                            }
                          }
                          else
                          {
                            v2->contactFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          v2->angularFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        v2->linearFriction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      idParser::Parse1DMatrix(this: src, x: 9, m: (float *)&v2->inertiaScale);
                    }
                  }
                  else
                  {
                    v2->density = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  if ( idParser::ExpectAnyToken(this: src, token: &v13) == 0 )
                    goto _M226269;
                  v2->jointMod = idDeclAF::JointModFromString(str: v13.data);
                }
              }
              else
              {
                if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13) == 0 )
                  goto _M226269;
                idStr::ToLower(this: &v13);
                idAtomicString::Set(this: &v2->jointName, str_: v13.data);
                v10 = 1;
              }
            }
            else
            {
              if ( (unsigned __int8)idAFVector::Parse(this: &v12, src) == 0 )
                goto _M226269;
              y = v12.vec.y;
              z = v12.vec.z;
              v2->angles.pitch = v12.vec.x;
              v2->angles.yaw = y;
              v2->angles.roll = z;
            }
          }
          else if ( (unsigned __int8)idAFVector::Parse(this: &v2->origin, src) == 0 )
          {
            goto _M226269;
          }
        }
        else
        {
          if ( idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v13) == 0 )
            goto _M226269;
          if ( idStr::Icmp(s1: v13.data, s2: "box") != 0 )
          {
            if ( idStr::Icmp(s1: v13.data, s2: "octahedron") != 0 )
            {
              if ( idStr::Icmp(s1: v13.data, s2: "dodecahedron") != 0 )
              {
                if ( idStr::Icmp(s1: v13.data, s2: "cylinder") != 0 )
                {
                  if ( idStr::Icmp(s1: v13.data, s2: "cone") != 0 )
                  {
                    if ( idStr::Icmp(s1: v13.data, s2: "bone") != 0 )
                    {
                      if ( idStr::Icmp(s1: v13.data, s2: "custom") != 0 )
                      {
                        idParser::Error(this: src, str: "unknown model type %s", v13.data);
                        goto _M226269;
                      }
                      v2->modelType = 9;
                      if ( !idParser::ExpectTokenString(this: src, string: "(") )
                        goto _M226269;
                      if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v13) == 0 )
                        goto _M226269;
                      idAtomicString::Set(this: &v2->modelName, str_: v13.data);
                      if ( !idParser::ExpectTokenString(this: src, string: ",")
                        || (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0
                        || !idParser::ExpectTokenString(this: src, string: ",")
                        || (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0
                        || !idParser::ExpectTokenString(this: src, string: ")") )
                      {
                        goto _M226269;
                      }
                    }
                    else
                    {
                      v2->modelType = 6;
                      if ( !idParser::ExpectTokenString(this: src, string: "(") )
                        goto _M226269;
                      if ( (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0 )
                        goto _M226269;
                      if ( !idParser::ExpectTokenString(this: src, string: ",") )
                        goto _M226269;
                      if ( (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0 )
                        goto _M226269;
                      if ( !idParser::ExpectTokenString(this: src, string: ",") )
                        goto _M226269;
                      v2->width = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      if ( !idParser::ExpectTokenString(this: src, string: ")") )
                        goto _M226269;
                    }
                  }
                  else
                  {
                    v2->modelType = 5;
                    if ( !idParser::ExpectTokenString(this: src, string: "(") )
                      goto _M226269;
                    if ( (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0 )
                      goto _M226269;
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M226269;
                    if ( (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0 )
                      goto _M226269;
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M226269;
                    v2->numSides = idParser::ParseInt(this: src);
                    if ( !idParser::ExpectTokenString(this: src, string: ")") )
                      goto _M226269;
                  }
                }
                else
                {
                  v2->modelType = 4;
                  if ( !idParser::ExpectTokenString(this: src, string: "(") )
                    goto _M226269;
                  if ( (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0 )
                    goto _M226269;
                  if ( !idParser::ExpectTokenString(this: src, string: ",") )
                    goto _M226269;
                  if ( (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0 )
                    goto _M226269;
                  if ( !idParser::ExpectTokenString(this: src, string: ",") )
                    goto _M226269;
                  v2->numSides = idParser::ParseInt(this: src);
                  if ( !idParser::ExpectTokenString(this: src, string: ")") )
                    goto _M226269;
                }
              }
              else
              {
                v2->modelType = 3;
                if ( !idParser::ExpectTokenString(this: src, string: "(")
                  || (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0
                  || !idParser::ExpectTokenString(this: src, string: ",")
                  || (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0
                  || !idParser::ExpectTokenString(this: src, string: ")") )
                {
                  goto _M226269;
                }
              }
            }
            else
            {
              v2->modelType = 2;
              if ( !idParser::ExpectTokenString(this: src, string: "(")
                || (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0
                || !idParser::ExpectTokenString(this: src, string: ",")
                || (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0
                || !idParser::ExpectTokenString(this: src, string: ")") )
              {
                goto _M226269;
              }
            }
          }
          else
          {
            v2->modelType = 1;
            if ( !idParser::ExpectTokenString(this: src, string: "(")
              || (unsigned __int8)idAFVector::Parse(this: &v2->v1, src) == 0
              || !idParser::ExpectTokenString(this: src, string: ",")
              || (unsigned __int8)idAFVector::Parse(this: &v2->v2, src) == 0
              || !idParser::ExpectTokenString(this: src, string: ")") )
            {
              goto _M226269;
            }
          }
        }
      }
      if ( v11->modelType == 0 )
      {
        idParser::Error(this: src, str: "no model set for body");
        goto _M226269;
      }
      if ( v10 != 0 )
      {
        v11->clipMask |= 0x40u;
        idStr::FreeData(this: &v13);
        return 1;
      }
      idParser::Error(this: src, str: "no joint set for body");
    }
    else
    {
      idParser::Error(this: src, str: "a body may not be named \"origin\" or \"world\"");
    }
  }
_M226269:
  idStr::FreeData(this: &v13);
  return 0;
}


// ========================================================================
// __unwind$225505
// EA  : 0x8261192C
// RVA : 0x0061192C
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_225505()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 192));
}


// ========================================================================
// __unwind$225506
// EA  : 0x82611954
// RVA : 0x00611954
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_225506()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 672 + 100), tag: TAG_AF);
}


// ========================================================================
// ?ParseFixed@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82611988
// RVA : 0x00611988
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseFixed(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v2; // r30
  idDeclAF_Constraint *v5; // r3
  idToken v7; // [sp+50h] [-180h] BYREF
  char v8; // [sp+98h] [-138h] BYREF

  v2 = nullptr;
  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v5 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v2 = idDeclAF_Constraint::idDeclAF_Constraint(this: v5);
  idDeclAF_Constraint::SetDefault(this: v2, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v2;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v2->type = DECLAF_CONSTRAINT_FIXED;
    idAtomicString::Set(this: &v2->name, str_: v7.data);
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
            {
              idParser::Error(this: src, str: "unknown token %s in ball and socket joint", v7.data);
              goto _M226465;
            }
            v2->syncConstraint = idParser::ParseBool(this: src);
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v2->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v2->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M226465:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$226294
// EA  : 0x82611BAC
// RVA : 0x00611BAC
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_226294()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?ParseBallAndSocketJoint@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82611BE0
// RVA : 0x00611BE0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseBallAndSocketJoint(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v4; // r3
  idDeclAF_Constraint *v5; // r29
  idToken v7; // [sp+60h] [-1C0h] BYREF
  char v8; // [sp+A8h] [-178h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v4 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idDeclAF_Constraint::idDeclAF_Constraint(this: v4);
  else
    v5 = nullptr;
  idDeclAF_Constraint::SetDefault(this: v5, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v5;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v5->type = DECLAF_CONSTRAINT_BALLANDSOCKETJOINT;
    v5->limit = LIMIT_NONE;
    idAtomicString::Set(this: &v5->name, str_: v7.data);
    v5->friction = 0.5;
    v5->anchor.vec.z = 0.0;
    v5->anchor.vec.y = 0.0;
    v5->anchor.vec.x = 0.0;
    v5->shaft[0].vec.z = 0.0;
    v5->shaft[0].vec.y = 0.0;
    v5->shaft[0].vec.x = 0.0;
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "anchor") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "conelimit") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "pyramidlimit") != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: "friction") != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
                    {
                      idParser::Error(this: src, str: "unknown token %s in ball and socket joint", v7.data);
                      goto _M226821;
                    }
                    v5->syncConstraint = idParser::ParseBool(this: src);
                  }
                  else
                  {
                    v5->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  if ( (unsigned __int8)idAFVector::Parse(this: &v5->limitAxis, src) == 0 )
                    goto _M226821;
                  if ( !idParser::ExpectTokenString(this: src, string: ",") )
                    goto _M226821;
                  v5->limitAngles[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  if ( !idParser::ExpectTokenString(this: src, string: ",") )
                    goto _M226821;
                  v5->limitAngles[1] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  if ( !idParser::ExpectTokenString(this: src, string: ",") )
                    goto _M226821;
                  v5->limitAngles[2] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  if ( !idParser::ExpectTokenString(this: src, string: ",")
                    || (unsigned __int8)idAFVector::Parse(this: v5->shaft, src) == 0 )
                  {
                    goto _M226821;
                  }
                  v5->limit = LIMIT_PYRAMID;
                }
              }
              else
              {
                if ( (unsigned __int8)idAFVector::Parse(this: &v5->limitAxis, src) == 0 )
                  goto _M226821;
                if ( !idParser::ExpectTokenString(this: src, string: ",") )
                  goto _M226821;
                v5->limitAngles[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                if ( !idParser::ExpectTokenString(this: src, string: ",")
                  || (unsigned __int8)idAFVector::Parse(this: v5->shaft, src) == 0 )
                {
                  goto _M226821;
                }
                v5->limit = LIMIT_CONE;
              }
            }
            else if ( (unsigned __int8)idAFVector::Parse(this: &v5->anchor, src) == 0 )
            {
              goto _M226821;
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v5->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v5->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M226821:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$226493
// EA  : 0x8261205C
// RVA : 0x0061205C
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_226493()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 96));
}


// ========================================================================
// ?ParseUniversalJoint@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82612090
// RVA : 0x00612090
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseUniversalJoint(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v4; // r3
  idDeclAF_Constraint *v5; // r30
  idToken v7; // [sp+60h] [-1C0h] BYREF
  char v8; // [sp+A8h] [-178h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v4 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idDeclAF_Constraint::idDeclAF_Constraint(this: v4);
  else
    v5 = nullptr;
  idDeclAF_Constraint::SetDefault(this: v5, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v5;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v5->type = DECLAF_CONSTRAINT_UNIVERSALJOINT;
    v5->limit = LIMIT_NONE;
    idAtomicString::Set(this: &v5->name, str_: v7.data);
    v5->friction = 0.5;
    v5->anchor.vec.z = 0.0;
    v5->anchor.vec.y = 0.0;
    v5->anchor.vec.x = 0.0;
    v5->shaft[0].vec.z = 0.0;
    v5->shaft[0].vec.y = 0.0;
    v5->shaft[0].vec.x = 0.0;
    v5->shaft[1].vec.z = 0.0;
    v5->shaft[1].vec.y = 0.0;
    v5->shaft[1].vec.x = 0.0;
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "anchor") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "shafts") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "conelimit") != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: "pyramidlimit") != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: "friction") != 0 )
                    {
                      if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
                      {
                        idParser::Error(this: src, str: "unknown token %s in universal joint", v7.data);
                        goto _M227170;
                      }
                      v5->syncConstraint = idParser::ParseBool(this: src);
                    }
                    else
                    {
                      v5->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    if ( (unsigned __int8)idAFVector::Parse(this: &v5->limitAxis, src) == 0 )
                      goto _M227170;
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M227170;
                    v5->limitAngles[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M227170;
                    v5->limitAngles[1] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M227170;
                    v5->limitAngles[2] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    v5->limit = LIMIT_PYRAMID;
                  }
                }
                else
                {
                  if ( (unsigned __int8)idAFVector::Parse(this: &v5->limitAxis, src) == 0
                    || !idParser::ExpectTokenString(this: src, string: ",") )
                  {
                    goto _M227170;
                  }
                  v5->limitAngles[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  v5->limit = LIMIT_CONE;
                }
              }
              else if ( (unsigned __int8)idAFVector::Parse(this: v5->shaft, src) == 0
                     || !idParser::ExpectTokenString(this: src, string: ",")
                     || (unsigned __int8)idAFVector::Parse(this: &v5->shaft[1], src) == 0 )
              {
                goto _M227170;
              }
            }
            else if ( (unsigned __int8)idAFVector::Parse(this: &v5->anchor, src) == 0 )
            {
              goto _M227170;
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v5->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v5->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M227170:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$226848_0
// EA  : 0x82612520
// RVA : 0x00612520
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_226848_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 96));
}


// ========================================================================
// ?ParseHinge@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82612550
// RVA : 0x00612550
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseHinge(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v4; // r3
  idDeclAF_Constraint *v5; // r30
  idToken v7; // [sp+60h] [-1C0h] BYREF
  char v8; // [sp+A8h] [-178h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v4 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idDeclAF_Constraint::idDeclAF_Constraint(this: v4);
  else
    v5 = nullptr;
  idDeclAF_Constraint::SetDefault(this: v5, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v5;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v5->type = DECLAF_CONSTRAINT_HINGE;
    v5->limit = LIMIT_NONE;
    idAtomicString::Set(this: &v5->name, str_: v7.data);
    v5->friction = 0.5;
    v5->anchor.vec.z = 0.0;
    v5->anchor.vec.y = 0.0;
    v5->anchor.vec.x = 0.0;
    v5->axis.vec.z = 0.0;
    v5->axis.vec.y = 0.0;
    v5->axis.vec.x = 0.0;
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "anchor") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "axis") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "shafts") != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: "limit") != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: "friction") != 0 )
                    {
                      if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
                      {
                        idParser::Error(this: src, str: "unknown token %s in hinge", v7.data);
                        goto _M227493;
                      }
                      v5->syncConstraint = idParser::ParseBool(this: src);
                    }
                    else
                    {
                      v5->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    v5->limitAngles[0] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M227493;
                    v5->limitAngles[1] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    if ( !idParser::ExpectTokenString(this: src, string: ",") )
                      goto _M227493;
                    v5->limitAngles[2] = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    v5->limit = LIMIT_CONE;
                  }
                }
                else if ( (unsigned __int8)idAFVector::Parse(this: v5->shaft, src) == 0
                       || !idParser::ExpectTokenString(this: src, string: ",")
                       || (unsigned __int8)idAFVector::Parse(this: &v5->shaft[1], src) == 0 )
                {
                  goto _M227493;
                }
              }
              else if ( (unsigned __int8)idAFVector::Parse(this: &v5->axis, src) == 0 )
              {
                goto _M227493;
              }
            }
            else if ( (unsigned __int8)idAFVector::Parse(this: &v5->anchor, src) == 0 )
            {
              goto _M227493;
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v5->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v5->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M227493:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$227196
// EA  : 0x82612964
// RVA : 0x00612964
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_227196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 96));
}


// ========================================================================
// ?ParseSlider@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82612998
// RVA : 0x00612998
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseSlider(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v2; // r30
  idDeclAF_Constraint *v5; // r3
  idToken v7; // [sp+50h] [-190h] BYREF
  char v8; // [sp+98h] [-148h] BYREF

  v2 = nullptr;
  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v5 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v2 = idDeclAF_Constraint::idDeclAF_Constraint(this: v5);
  idDeclAF_Constraint::SetDefault(this: v2, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v2;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v2->type = DECLAF_CONSTRAINT_SLIDER;
    v2->limit = LIMIT_NONE;
    idAtomicString::Set(this: &v2->name, str_: v7.data);
    v2->friction = 0.5;
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "axis") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "friction") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
                {
                  idParser::Error(this: src, str: "unknown token %s in slider", v7.data);
                  goto _M227712;
                }
                v2->syncConstraint = idParser::ParseBool(this: src);
              }
              else
              {
                v2->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else if ( (unsigned __int8)idAFVector::Parse(this: &v2->axis, src) == 0 )
            {
              goto _M227712;
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v2->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v2->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M227712:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$227515
// EA  : 0x82612C40
// RVA : 0x00612C40
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_227515()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// ?ParseSpring@idDeclAF@@AAA_NAAVidParser@@@Z
// EA  : 0x82612C70
// RVA : 0x00612C70
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

int __fastcall idDeclAF::ParseSpring(idDeclAF *this, idParser *src)
{
  idDeclAF_Constraint *v4; // r3
  idDeclAF_Constraint *v5; // r27
  idToken v7; // [sp+50h] [-1D0h] BYREF
  char v8; // [sp+98h] [-188h] BYREF

  v7.baseBuffer[0] = 0;
  v7.floatvalue = -3.4028235e38;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  v8 = 0;
  v7.data = &v8;
  v7.len = 0;
  v7.allocedAndFlag = -2147483392;
  v4 = (idDeclAF_Constraint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xE8u,
                                tag: TAG_AF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idDeclAF_Constraint::idDeclAF_Constraint(this: v4);
  else
    v5 = nullptr;
  idDeclAF_Constraint::SetDefault(this: v5, file: this);
  *idList<unsigned char *,5>::Alloc(this: &this->constraints) = v5;
  if ( idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7) != 0
    && idParser::ExpectTokenString(this: src, string: "{") )
  {
    v5->type = DECLAF_CONSTRAINT_SPRING;
    v5->limit = LIMIT_NONE;
    idAtomicString::Set(this: &v5->name, str_: v7.data);
    v5->friction = 0.5;
    if ( idParser::ReadToken(this: src, token: &v7) )
    {
      while ( v7.type != 5 || v7.subtype != 47 )
      {
        if ( idStr::Icmp(s1: v7.data, s2: "body1") != 0 )
        {
          if ( idStr::Icmp(s1: v7.data, s2: "body2") != 0 )
          {
            if ( idStr::Icmp(s1: v7.data, s2: "anchor1") != 0 )
            {
              if ( idStr::Icmp(s1: v7.data, s2: "anchor2") != 0 )
              {
                if ( idStr::Icmp(s1: v7.data, s2: "friction") != 0 )
                {
                  if ( idStr::Icmp(s1: v7.data, s2: "stretch") != 0 )
                  {
                    if ( idStr::Icmp(s1: v7.data, s2: "compress") != 0 )
                    {
                      if ( idStr::Icmp(s1: v7.data, s2: "damping") != 0 )
                      {
                        if ( idStr::Icmp(s1: v7.data, s2: "restLength") != 0 )
                        {
                          if ( idStr::Icmp(s1: v7.data, s2: "minLength") != 0 )
                          {
                            if ( idStr::Icmp(s1: v7.data, s2: "maxLength") != 0 )
                            {
                              if ( idStr::Icmp(s1: v7.data, s2: "syncConstraint") != 0 )
                              {
                                idParser::Error(this: src, str: "unknown token %s in spring", v7.data);
                                goto _M227974;
                              }
                              v5->syncConstraint = idParser::ParseBool(this: src);
                            }
                            else
                            {
                              v5->maxLength = idParser::ParseFloat(this: src, errorFlag: nullptr);
                            }
                          }
                          else
                          {
                            v5->minLength = idParser::ParseFloat(this: src, errorFlag: nullptr);
                          }
                        }
                        else
                        {
                          v5->restLength = idParser::ParseFloat(this: src, errorFlag: nullptr);
                        }
                      }
                      else
                      {
                        v5->damping = idParser::ParseFloat(this: src, errorFlag: nullptr);
                      }
                    }
                    else
                    {
                      v5->compress = idParser::ParseFloat(this: src, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    v5->stretch = idParser::ParseFloat(this: src, errorFlag: nullptr);
                  }
                }
                else
                {
                  v5->friction = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else if ( (unsigned __int8)idAFVector::Parse(this: &v5->anchor2, src) == 0 )
              {
                goto _M227974;
              }
            }
            else if ( (unsigned __int8)idAFVector::Parse(this: &v5->anchor, src) == 0 )
            {
              goto _M227974;
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
            idAtomicString::Set(this: &v5->body2, str_: v7.data);
          }
        }
        else
        {
          idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
          idAtomicString::Set(this: &v5->body1, str_: v7.data);
        }
        if ( !idParser::ReadToken(this: src, token: &v7) )
          break;
      }
    }
    idStr::FreeData(this: &v7);
    return 1;
  }
  else
  {
_M227974:
    idStr::FreeData(this: &v7);
    return 0;
  }
}


// ========================================================================
// __unwind$227735
// EA  : 0x82613078
// RVA : 0x00613078
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_227735()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 80));
}


// ========================================================================
// ?Parse@idDeclAF@@UAAXAAVidParser@@@Z
// EA  : 0x826130A8
// RVA : 0x006130A8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF::Parse(idDeclAF *this, idParser *src)
{
  int num; // r11
  int v5; // r28
  int v6; // r26
  int v7; // r27
  int v8; // r29
  idDeclAF_Body **list; // r11
  int v10; // r11
  int v11; // r28
  int v12; // r26
  int v13; // r27
  int v14; // r29
  idDeclAF_Constraint **v15; // r11
  idDeclAF_Constraint *v16; // r11
  char *str; // r10
  char v18; // r10
  bool v19; // zf
  idDeclAF_Constraint *v20; // r11
  char *v21; // r10
  char v22; // r10
  int v23; // r10
  int v24; // r11
  idDeclAF_Body **v25; // r11
  int v26; // r10
  idDeclAF_Body *v27; // r8
  int v28; // [sp+50h] [-1C0h]
  idToken v29; // [sp+60h] [-1B0h] BYREF
  char v30; // [sp+A8h] [-168h] BYREF

  v29.baseBuffer[0] = 0;
  v29.floatvalue = -3.4028235e38;
  v29.intvalue = 0;
  memset(&v29.whiteSpaceStart_p, 0, 12);
  v30 = 0;
  v29.data = &v30;
  v29.len = 0;
  v29.allocedAndFlag = -2147483392;
  if ( !idParser::ReadToken(this: src, token: &v29) )
    goto LABEL_26;
  while ( idStr::Icmp(s1: v29.data, s2: "settings") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseSettings(this, src) == 0 )
      goto LABEL_62;
LABEL_25:
    if ( !idParser::ReadToken(this: src, token: &v29) )
      goto LABEL_26;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "body") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseBody(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "fixed") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseFixed(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "ballAndSocketJoint") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseBallAndSocketJoint(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "universalJoint") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseUniversalJoint(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "hinge") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseHinge(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "slider") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseSlider(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v29.data, s2: "spring") == 0 )
  {
    if ( (unsigned __int8)idDeclAF::ParseSpring(this, src) == 0 )
      goto LABEL_62;
    goto LABEL_25;
  }
  if ( idStr::Cmp(s1: v29.data, s2: "}") != 0 )
  {
    idParser::Error(this: src, str: "unknown keyword %s", v29.data);
    goto LABEL_62;
  }
LABEL_26:
  num = this->bodies.num;
  if ( num > 0 )
  {
    v5 = 0;
    v6 = 1;
    do
    {
      v7 = v6;
      if ( v6 < num )
      {
        v8 = v5 * 4 + 4;
        do
        {
          list = this->bodies.list;
          if ( list[v5]->name.str == (*(idDeclAF_Body **)((char *)list + v8))->name.str )
            idParser::Error(this: src, str: "two bodies with the same name \"%s\"", list[v5]->name.str);
          ++v7;
          v8 += 4;
          num = this->bodies.num;
        }
        while ( v7 < num );
      }
      ++v6;
      ++v5;
    }
    while ( v6 - 1 < num );
  }
  v10 = this->constraints.num;
  if ( v10 > 0 )
  {
    v11 = 0;
    v12 = 1;
    do
    {
      v13 = v12;
      if ( v12 < v10 )
      {
        v14 = v11 * 4 + 4;
        do
        {
          v15 = this->constraints.list;
          if ( v15[v11]->name.str == (*(idDeclAF_Constraint **)((char *)v15 + v14))->name.str )
            idParser::Error(this: src, str: "two constraints with the same name \"%s\"", v15[v11]->name.str);
          ++v13;
          v14 += 4;
        }
        while ( v13 < this->constraints.num );
      }
      v16 = this->constraints.list[v11];
      str = (char *)v16->body1.str;
      if ( str == &byte_8200D768 || (v19 = *str != 0, v18 = 0, !v19) )
        v18 = 1;
      if ( v18 != 0 )
        idParser::Error(this: src, str: "no valid body1 specified for constraint '%s'", v16->name.str);
      v20 = this->constraints.list[v11];
      v21 = (char *)v20->body2.str;
      if ( v21 == &byte_8200D768 || (v19 = *v21 != 0, v22 = 0, !v19) )
        v22 = 1;
      if ( v22 != 0 )
        idParser::Error(this: src, str: "no valid body2 specified for constraint '%s'", v20->name.str);
      ++v12;
      ++v11;
      v10 = this->constraints.num;
    }
    while ( v12 - 1 < v10 );
  }
  v23 = 0;
  v28 = this->bodies.num;
  if ( v28 > 0 )
  {
    v24 = 0;
    while ( this->bodies.list[v24]->jointName.str != this->base.str )
    {
      ++v23;
      ++v24;
      if ( v23 >= v28 )
        goto LABEL_62;
    }
    if ( v23 != 0 )
    {
      v25 = this->bodies.list;
      v26 = v23;
      v27 = *v25;
      *v25 = v25[v26];
      this->bodies.list[v26] = v27;
    }
  }
LABEL_62:
  idStr::FreeData(this: &v29);
}


// ========================================================================
// __unwind$227988
// EA  : 0x826135A0
// RVA : 0x006135A0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_227988()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 96));
}


// ========================================================================
// ?FreeData@idDeclAF@@UAAXXZ
// EA  : 0x826135C8
// RVA : 0x006135C8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF::FreeData(idDeclAF *this)
{
  this->defaultBouncyness = 0.30000001;
  this->defaultLinearFriction = 0.0099999998;
  this->defaultAngularFriction = 0.0099999998;
  this->modified = false;
  this->defaultContactFriction = 0.80000001;
  this->defaultConstraintFriction = 0.5;
  this->suspendVelocity.x = 20.0;
  this->suspendVelocity.y = 30.0;
  this->suspendAcceleration.x = 40.0;
  this->suspendAcceleration.y = 60.0;
  this->selfCollision = true;
  this->contents = 4096;
  this->clipMask = 4097;
  this->noMoveTime = 1.0;
  this->noMoveTranslation = 10.0;
  this->noMoveRotation = 10.0;
  this->minMoveTime = -1.0;
  this->maxMoveTime = -1.0;
  idList<idDeclAF_Body *,71>::DeleteContents(this: &this->bodies);
  idList<idDeclAF_Constraint *,71>::DeleteContents(this: &this->constraints);
  idAtomicString::Set(this: &this->base, str_: "origin");
  this->clipMaterial = nullptr;
}


// ========================================================================
// ??0idDeclAF@@QAA@XZ
// EA  : 0x826136D8
// RVA : 0x006136D8
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

idDeclAF *__fastcall idDeclAF::idDeclAF(idDeclAF *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->modelDef = nullptr;
  this->__vftable = (idDeclAF_vtbl *)&idDeclAF::`vftable';
  this->solverConstants.errorReduction = 0.5;
  this->solverConstants.errorReductionMax = 256.0;
  this->solverConstants.lcpEpsilon = 0.0000099999997;
  this->solverConstants.limitErrorReduction = 0.30000001;
  this->solverConstants.limitErrorReductionMax = 256.0;
  this->solverConstants.limitLcpEpsilon = 0.000099999997;
  this->solverConstants.contactErrorReduction = 0.2;
  this->solverConstants.contactErrorReductionMax = 256.0;
  this->solverConstants.contactLcpEpsilon = 0.000001;
  this->solverConstants.universalErrorReduction = 0.5;
  this->solverConstants.universalErrorReductionMax = 256.0;
  this->solverConstants.universalTorsionLcpEpsilon = 0.1;
  this->syncSolverConstants.errorReduction = 0.5;
  this->syncSolverConstants.errorReductionMax = 256.0;
  this->syncSolverConstants.lcpEpsilon = 0.0000099999997;
  this->syncSolverConstants.limitErrorReduction = 0.30000001;
  this->syncSolverConstants.limitErrorReductionMax = 256.0;
  this->skin.str = &byte_8200D768;
  this->syncSolverConstants.limitLcpEpsilon = 0.000099999997;
  this->syncSolverConstants.contactErrorReduction = 0.2;
  this->base.str = &byte_8200D768;
  this->syncSolverConstants.contactErrorReductionMax = 256.0;
  this->syncSolverConstants.contactLcpEpsilon = 0.000001;
  this->syncSolverConstants.universalErrorReduction = 0.5;
  this->syncSolverConstants.universalErrorReductionMax = 256.0;
  this->syncSolverConstants.universalTorsionLcpEpsilon = 0.1;
  this->bodies.list = nullptr;
  this->bodies.granularity = 0;
  this->bodies.memTag = 71;
  this->bodies.listStatic = 0;
  this->bodies.size = 0;
  this->bodies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bodies);
  this->constraints.list = nullptr;
  this->constraints.granularity = 0;
  this->constraints.memTag = 71;
  this->constraints.listStatic = 0;
  this->constraints.size = 0;
  this->constraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  this->syncSolverConstants.errorReduction = 0.5;
  this->syncSolverConstants.limitErrorReduction = 0.1;
  this->syncSolverConstants.limitLcpEpsilon = 0.000001;
  this->syncSolverConstants.universalErrorReduction = 0.5;
  this->syncSolverConstants.errorReductionMax = 512.0;
  this->syncSolverConstants.lcpEpsilon = 0.001;
  this->syncSolverConstants.limitErrorReductionMax = 128.0;
  this->syncSolverConstants.universalErrorReductionMax = 512.0;
  this->syncSolverConstants.universalTorsionLcpEpsilon = 0.1;
  idDeclAF::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$228618
// EA  : 0x82613888
// RVA : 0x00613888
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228618()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$228619
// EA  : 0x826138B0
// RVA : 0x006138B0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228619()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 240));
}


// ========================================================================
// __unwind$228620
// EA  : 0x826138DC
// RVA : 0x006138DC
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228620()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 256));
}


// ========================================================================
// ??1idDeclAF@@UAA@XZ
// EA  : 0x82613920
// RVA : 0x00613920
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void __fastcall idDeclAF::~idDeclAF(idDeclAF *this)
{
  idList<idDeclAF_Body *,71> *p_bodies; // r29

  this->__vftable = (idDeclAF_vtbl *)&idDeclAF::`vftable';
  p_bodies = &this->bodies;
  idList<idDeclAF_Body *,71>::DeleteContents(this: &this->bodies);
  idList<idDeclAF_Constraint *,71>::DeleteContents(this: &this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_bodies);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$228687
// EA  : 0x8261397C
// RVA : 0x0061397C
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228687()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$228688
// EA  : 0x826139A4
// RVA : 0x006139A4
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228688()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 240));
}


// ========================================================================
// __unwind$228689
// EA  : 0x826139D0
// RVA : 0x006139D0
// PDB : w:\tech5\engine\decls\declaf.cpp
// ========================================================================

void _unwind_228689()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 256));
}

