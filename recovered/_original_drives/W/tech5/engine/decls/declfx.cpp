
// ========================================================================
// ?FXActionTypeToName@idDeclFX@@SAPBDW4fxActionType_t@@@Z
// EA  : 0x8261B808
// RVA : 0x0061B808
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

const char *__fastcall idDeclFX::FXActionTypeToName(unsigned int type)
{
  if ( ((((type & 0x80000000) == 0) + (type >= 0x10)) & 1) != 0 )
    return fxActionTypeDesc[type];
  else
    return "FX_MAX (invalid?)";
}


// ========================================================================
// ?FXConditionToName@idDeclFX@@SAPBDW4fxCondition_t@@@Z
// EA  : 0x8261B848
// RVA : 0x0061B848
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

const char *__fastcall idDeclFX::FXConditionToName(int condition)
{
  if ( typeInfoTools != nullptr )
    return idTypeInfoTools::FindEnumValueInfo(
             this: typeInfoTools,
             enumName: "fxCondition_t",
             value: condition,
             defaultIfNotFound: true)->name;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?DefaultDefinition@idDeclFX@@UBAPBDXZ
// EA  : 0x8261B8A8
// RVA : 0x0061B8A8
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

const char *__fastcall idDeclFX::DefaultDefinition(idDeclFX *this)
{
  return "{\n\t{\n\t\tduration\t2\n\t}\n}\n";
}


// ========================================================================
// ?WriteSingleFXAction@idDeclFX@@AAAXPAVidFile@@AAVidFXSingleAction@@@Z
// EA  : 0x8261B8B8
// RVA : 0x0061B8B8
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idDeclFX::WriteSingleFXAction(idDeclFX *this, idFile *f, idFXSingleAction *fxAction)
{
  char v5; // r11
  char *str; // r5
  char v7; // r11
  double x; // fp1
  double fadeInTime; // fp1
  double fadeOutTime; // fp1
  double size; // fp1
  fxRotationType_t rotationType; // r11
  const idDeclTable *rotateTablePitch; // r11
  const idDeclTable *rotateTableYaw; // r11
  const idDeclTable *rotateTableRoll; // r11
  double v16; // fp1
  double v17; // fp1
  double v18; // fp1
  char *v19; // r5
  char v20; // r11
  idFile_vtbl *v21; // r29
  const enumValueInfo_t *EnumValueInfo; // r3
  fxOriginType_t originType; // r5
  idFile_vtbl *v24; // r29
  const enumValueInfo_t *v25; // r3
  fxRotationType_t v26; // r5
  idFile_vtbl *v27; // r29
  const enumValueInfo_t *v28; // r3
  int v29; // r29
  int v30; // r28
  int v31; // r29
  int v32; // r28
  idFile_vtbl *v33; // r27
  const enumValueInfo_t *v34; // r3
  int v35; // r29
  int v36; // r28
  idFile_vtbl *v37; // r27
  const enumValueInfo_t *v38; // r3
  int v39; // r29
  int v40; // r28
  idFile_vtbl *v41; // r27
  const enumValueInfo_t *v42; // r3
  const idDeclTable *colorTableRGB; // r11
  const idDeclTable *colorTableA; // r11
  const idDeclRenderParm *customRenderParm; // r11
  const idDeclTable *customTable1; // r11
  const idDeclTable *customTable2; // r11
  unsigned int (*WriteFloatString)(idFile *, const char *, ...); // ctr
  double z; // r8
  double v50; // r10
  const idDeclParticle *declPrt; // r11
  char *v52; // r5
  const idMaterial *customMaterial; // r11
  const idSoundShader *sound; // r11
  unsigned int (*v55)(idFile *, const char *, ...); // ctr
  double roll; // r9
  double magnitude; // r5
  int v58; // r27
  int v59; // r29
  _DWORD *v60; // r9
  float *p_w; // r10
  int i; // ctr
  idFile_vtbl *v63; // r28
  int v64; // r25
  const char *v65; // r3
  const idDeclRibbon *declRibbon; // r11
  const idDeclRenderParm *declRenderParm; // r11
  double v68; // [sp+28h] [-A8h]
  double distance; // [sp+28h] [-A8h]
  double y; // [sp+30h] [-A0h]
  double pitch; // [sp+30h] [-A0h]
  double v72; // [sp+48h] [-88h]
  double intensity; // [sp+58h] [-78h] BYREF
  int v74; // [sp+60h] [-70h]
  idQuat v75; // [sp+64h] [-6Ch] BYREF

  if ( !fxAction->implicit )
  {
    f->WriteFloatString(this: f, a2: "\t{\n");
    if ( fxAction->name.str == &byte_8200D768 || (v5 = 0, *fxAction->name.str == 0) )
      v5 = 1;
    if ( v5 == 0 )
      f->WriteFloatString(this: f, a2: "\t\tname\t\t\t\"%s\"\n");
    str = (char *)fxAction->group.str;
    if ( str == &byte_8200D768 || (v7 = 0, *str == 0) )
      v7 = 1;
    if ( v7 == 0 )
      f->WriteFloatString(this: f, a2: "\t\tgroup\t\t\t\"%s\"\n");
    x = fxAction->delay.x;
    if ( x != 0.0 || fxAction->delay.y != 0.0 )
      f->WriteFloatString(
        this: f,
        a2: "\t\tdelay\t\t\t%.3f, %.3f\n",
        LODWORD(x),
        (unsigned int)COERCE_UNSIGNED_INT64(fxAction->delay.y));
    if ( fxAction->type != FX_SOUND )
      f->WriteFloatString(
        this: f,
        a2: "\t\tduration\t\t\t%.3f\n",
        (unsigned int)COERCE_UNSIGNED_INT64(fxAction->duration));
    fadeInTime = fxAction->fadeInTime;
    if ( fadeInTime != 0.0 )
      f->WriteFloatString(this: f, a2: "\t\tfadeIn\t\t\t%.3f\n", LODWORD(fadeInTime));
    fadeOutTime = fxAction->fadeOutTime;
    if ( fadeOutTime != 0.0 )
      f->WriteFloatString(this: f, a2: (const char *)HIDWORD(fadeOutTime), LODWORD(fadeOutTime));
    if ( fxAction->restart )
      f->WriteFloatString(this: f, a2: "\t\trestart\t\t\t1\n");
    if ( fxAction->looping && fxAction->type != FX_SOUND )
      f->WriteFloatString(this: f, a2: "\t\tlooping\t\t\t1\n");
    if ( !fxAction->noshadows )
      f->WriteFloatString(this: f, a2: "\t\tnoshadows\t\t\t0\n");
    if ( ((LODWORD(fxAction->offset.z) | LODWORD(fxAction->offset.y) | LODWORD(fxAction->offset.x)) & 0x7FFFFFFF) != 0 )
      f->WriteFloatString(
        this: f,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->offset.x)),
        COERCE_UNSIGNED_INT64(fxAction->offset.x),
        COERCE_UNSIGNED_INT64(fxAction->offset.y),
        COERCE_UNSIGNED_INT64(fxAction->offset.z));
    if ( ((LODWORD(fxAction->rotOffsetAngles.roll)
         | LODWORD(fxAction->rotOffsetAngles.yaw)
         | LODWORD(fxAction->rotOffsetAngles.pitch))
        & 0x7FFFFFFF) != 0 )
      f->WriteFloatString(
        this: f,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->rotOffsetAngles.pitch)),
        COERCE_UNSIGNED_INT64(fxAction->rotOffsetAngles.pitch),
        COERCE_UNSIGNED_INT64(fxAction->rotOffsetAngles.yaw),
        COERCE_UNSIGNED_INT64(fxAction->rotOffsetAngles.roll));
    size = fxAction->size;
    if ( size != 1.0 )
      f->WriteFloatString(this: f, a2: "\t\tsize\t\t\t%.3f\n", LODWORD(size));
    rotationType = fxAction->rotationType;
    if ( rotationType == FX_ROT_EXPLICIT_ANGLES )
    {
      f->WriteFloatString(
        this: f,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->explicitAngles.pitch)),
        COERCE_UNSIGNED_INT64(fxAction->explicitAngles.pitch),
        HIDWORD(COERCE_UNSIGNED_INT64(fxAction->explicitAngles.roll)),
        COERCE_UNSIGNED_INT64(fxAction->explicitAngles.roll));
    }
    else if ( rotationType == FX_ROT_EXPLICIT_TABLES || rotationType == FX_ROT_EXPLICIT_TABLES_LOCAL )
    {
      rotateTablePitch = fxAction->rotateTablePitch;
      if ( rotateTablePitch != nullptr )
        f->WriteFloatString(this: f, a2: "\t\trotateTablePitch\t\t\t\t\"%s\"\n", rotateTablePitch->name.str);
      rotateTableYaw = fxAction->rotateTableYaw;
      if ( rotateTableYaw != nullptr )
        f->WriteFloatString(this: f, a2: "\t\trotateTableYaw\t\t\t\t\"%s\"\n", rotateTableYaw->name.str);
      rotateTableRoll = fxAction->rotateTableRoll;
      if ( rotateTableRoll != nullptr )
        f->WriteFloatString(this: f, a2: "\t\trotateTableRoll\t\t\t\t\"%s\"\n", rotateTableRoll->name.str);
    }
    v16 = fxAction->rndRotX.x;
    if ( v16 != 0.0 || fxAction->rndRotX.y != 0.0 )
      f->WriteFloatString(
        this: f,
        a2: (const char *)HIDWORD(v16),
        HIDWORD(COERCE_UNSIGNED_INT64(fxAction->rndRotX.y)),
        COERCE_UNSIGNED_INT64(fxAction->rndRotX.y));
    v17 = fxAction->rndRotY.x;
    if ( v17 != 0.0 || fxAction->rndRotY.y != 0.0 )
      f->WriteFloatString(
        this: f,
        a2: (const char *)HIDWORD(v17),
        LODWORD(v17),
        COERCE_UNSIGNED_INT64(fxAction->rndRotY.y));
    v18 = fxAction->rndRotZ.x;
    if ( v18 != 0.0 || fxAction->rndRotZ.y != 0.0 )
      f->WriteFloatString(
        this: f,
        a2: (const char *)HIDWORD(v18),
        LODWORD(v18),
        COERCE_UNSIGNED_INT64(fxAction->rndRotZ.y));
    v19 = (char *)fxAction->fire.str;
    if ( v19 == &byte_8200D768 || (v20 = 0, *v19 == 0) )
      v20 = 1;
    if ( v20 == 0 )
      f->WriteFloatString(this: f, a2: "\t\tfire\t\t\t\"%s\"\n");
    if ( fxAction->tagNames.num > 0 )
    {
      v21 = f->__vftable;
      EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                        this: typeInfoTools,
                        enumName: "fxMultiTagUseType_t",
                        value: fxAction->multiTagUseType,
                        defaultIfNotFound: true);
      v21->WriteFloatString(this: f, a2: "\t\tmultiTagUseType\t\t\t%s\n", EnumValueInfo->name);
    }
    originType = fxAction->originType;
    if ( originType != FX_ORG_START_POS )
    {
      v24 = f->__vftable;
      v25 = idTypeInfoTools::FindEnumValueInfo(
              this: typeInfoTools,
              enumName: "fxOriginType_t",
              value: originType,
              defaultIfNotFound: true);
      v24->WriteFloatString(this: f, a2: "\t\toriginType\t\t\t%s\n", v25->name);
    }
    v26 = fxAction->rotationType;
    if ( v26 != FX_ROT_START_AXIS )
    {
      v27 = f->__vftable;
      v28 = idTypeInfoTools::FindEnumValueInfo(
              this: typeInfoTools,
              enumName: "fxRotationType_t",
              value: v26,
              defaultIfNotFound: true);
      v27->WriteFloatString(this: f, a2: "\t\trotationType\t\t\t%s\n", v28->name);
    }
    if ( fxAction->tagNames.num > 0 )
    {
      f->WriteFloatString(this: f, a2: "\t\ttagName\t\t\t");
      v29 = 0;
      if ( fxAction->tagNames.num > 0 )
      {
        v30 = 0;
        do
        {
          f->WriteFloatString(this: f, a2: "\"%s\"", fxAction->tagNames.list[v30].str);
          ++v29;
          ++v30;
        }
        while ( v29 < fxAction->tagNames.num );
      }
      f->WriteFloatString(this: f, a2: "\n");
    }
    if ( fxAction->startCondition.num > 0 )
    {
      f->WriteFloatString(this: f, a2: "\t\tstartCondition\t\t\t");
      v31 = 0;
      if ( fxAction->startCondition.num > 0 )
      {
        v32 = 0;
        do
        {
          v33 = f->__vftable;
          v34 = idTypeInfoTools::FindEnumValueInfo(
                  this: typeInfoTools,
                  enumName: "fxCondition_t",
                  value: fxAction->startCondition.list[v32],
                  defaultIfNotFound: true);
          v33->WriteFloatString(this: f, a2: "%s ", v34->name);
          ++v31;
          ++v32;
        }
        while ( v31 < fxAction->startCondition.num );
      }
      f->WriteFloatString(this: f, a2: "\n");
    }
    if ( fxAction->stopCondition.num > 0 )
    {
      f->WriteFloatString(this: f, a2: "\t\tstopCondition\t\t\t");
      v35 = 0;
      if ( fxAction->stopCondition.num > 0 )
      {
        v36 = 0;
        do
        {
          v37 = f->__vftable;
          v38 = idTypeInfoTools::FindEnumValueInfo(
                  this: typeInfoTools,
                  enumName: "fxCondition_t",
                  value: fxAction->stopCondition.list[v36],
                  defaultIfNotFound: true);
          v37->WriteFloatString(this: f, a2: "%s ", v38->name);
          ++v35;
          ++v36;
        }
        while ( v35 < fxAction->stopCondition.num );
      }
      f->WriteFloatString(this: f, a2: "\n");
    }
    if ( fxAction->extraCondition.num > 0 )
    {
      f->WriteFloatString(this: f, a2: "\t\textraCondition\t\t\t");
      v39 = 0;
      if ( fxAction->extraCondition.num > 0 )
      {
        v40 = 0;
        do
        {
          v41 = f->__vftable;
          v42 = idTypeInfoTools::FindEnumValueInfo(
                  this: typeInfoTools,
                  enumName: "fxExtraCondition_t",
                  value: fxAction->extraCondition.list[v40],
                  defaultIfNotFound: true);
          v41->WriteFloatString(this: f, a2: "%s ", v42->name);
          ++v39;
          ++v40;
        }
        while ( v39 < fxAction->extraCondition.num );
      }
      f->WriteFloatString(this: f, a2: "\n");
    }
    colorTableRGB = fxAction->colorTableRGB;
    if ( colorTableRGB != nullptr )
      f->WriteFloatString(this: f, a2: "\t\tcolorTableRGB\t\t\t\t\"%s\"\n", colorTableRGB->name.str);
    colorTableA = fxAction->colorTableA;
    if ( colorTableA != nullptr )
      f->WriteFloatString(this: f, a2: "\t\tcolorTableAlpha\t\t\t\t\"%s\"\n", colorTableA->name.str);
    customRenderParm = fxAction->customRenderParm;
    if ( customRenderParm != nullptr )
      f->WriteFloatString(this: f, a2: "\t\tcustomRenderParm\t\t\t\t\"%s\"\n", customRenderParm->name.str);
    customTable1 = fxAction->customTable1;
    if ( customTable1 != nullptr )
      f->WriteFloatString(this: f, a2: "\t\tcustomTable1\t\t\t\t\"%s\"\n", customTable1->name.str);
    customTable2 = fxAction->customTable2;
    if ( customTable2 != nullptr )
      f->WriteFloatString(this: f, a2: "\t\tcustomTable2\t\t\t\t\"%s\"\n", customTable2->name.str);
    switch ( fxAction->type )
    {
      case FX_LIGHT:
        v68 = fxAction->color.x;
        y = fxAction->color.y;
        WriteFloatString = f->WriteFloatString;
        z = fxAction->color.z;
        v50 = fxAction->lightParms.radius.y;
        intensity = fxAction->lightParms.intensity;
        WriteFloatString(
          this: f,
          a2: "\t\tlight\t\t\t\"%s\", %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f\n",
          HIDWORD(v68),
          HIDWORD(y),
          z,
          v50);
        break;
      case FX_PARTICLE:
        declPrt = fxAction->particleParms.declPrt;
        if ( declPrt != nullptr )
          v52 = (char *)declPrt->name.str;
        else
          v52 = &byte_8200D768;
        f->WriteFloatString(this: f, a2: "\t\tparticle\t\t\t\t\"%s\"\n", v52);
        if ( fxAction->particleParms.useSmokeSystem )
        {
          f->WriteFloatString(this: f, a2: "\t\tuseSmokeSystem\t\t\t\t1\n");
          f->WriteFloatString(this: f, a2: "\t\tsmokeSystemRate\t\t\t\t%d\n", fxAction->particleParms.smokeSystemRate);
          f->WriteFloatString(
            this: f,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->particleParms.trailSpacing)),
            COERCE_UNSIGNED_INT64(fxAction->particleParms.trailSpacing));
        }
        if ( fxAction->particleParms.trackVelocity )
        {
          f->WriteFloatString(this: f, a2: "\t\tparticleTrackVelocity\n");
          f->WriteFloatString(
            this: f,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->particleParms.velocityScale)),
            COERCE_UNSIGNED_INT64(fxAction->particleParms.velocityScale));
          f->WriteFloatString(
            this: f,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->particleParms.minVelocity)),
            COERCE_UNSIGNED_INT64(fxAction->particleParms.minVelocity));
        }
        if ( fxAction->particleParms.isScreenPrt )
        {
          f->WriteFloatString(this: f, a2: "\t\tisScreenPrt\t\t\t\t1\n");
          f->WriteFloatString(
            this: f,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->particleParms.screenPrtExcludeAngle)),
            COERCE_UNSIGNED_INT64(fxAction->particleParms.screenPrtExcludeAngle));
          f->WriteFloatString(
            this: f,
            a2: "\t\tdistance\t\t\t\t%.3f\n",
            (unsigned int)COERCE_UNSIGNED_INT64(fxAction->distance));
        }
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.x)),
          COERCE_UNSIGNED_INT64(fxAction->color.x),
          HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.z)),
          HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.w)),
          COERCE_UNSIGNED_INT64(fxAction->color.w));
        break;
      case FX_DECAL:
        f->WriteFloatString(
          this: f,
          a2: "\t\tdecal\t\t\t\t\"%s\", %.3f, %.3f\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->decalParms.angle)),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->decalParms.angle),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->decalParms.depth));
        break;
      case FX_DECAL2:
        f->WriteFloatString(
          this: f,
          a2: "\t\tdecal2\t\t\t\t\"%s\", %.3f\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->decalParms.depth)),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->decalParms.depth));
        break;
      case FX_MODEL:
        f->WriteFloatString(this: f, a2: "\t\tmodel\t\t\t\t\"%s\"\n", fxAction->modelParms.modelName.str);
        customMaterial = fxAction->modelParms.customMaterial;
        if ( customMaterial != nullptr )
          f->WriteFloatString(this: f, a2: "\t\tcustomMaterial\t\t\t\t\"%s\"\n", customMaterial->name.str);
        f->WriteFloatString(
          this: f,
          a2: "\t\tcolor\t\t\t%.3f, %.3f, %.3f, %.3f\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.y)),
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.z)),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->color.z),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->color.w));
        break;
      case FX_SOUND:
        sound = fxAction->soundParms.sound;
        if ( sound != nullptr )
          f->WriteFloatString(this: f, a2: "\t\tsound\t\t\t\t\"%s\"\n", sound->name.str);
        break;
      case FX_SCREEN_SHAKE:
        v72 = fxAction->screenShakeParms.maxOffset.x;
        v55 = f->WriteFloatString;
        roll = fxAction->screenShakeParms.maxAngles.roll;
        pitch = fxAction->screenShakeParms.maxAngles.pitch;
        distance = fxAction->distance;
        magnitude = fxAction->screenShakeParms.magnitude;
        intensity = fxAction->screenShakeParms.maxOffset.z;
        v55(
          this: f,
          a2: (const char *)HIDWORD(magnitude),
          LODWORD(magnitude),
          LODWORD(distance),
          LODWORD(pitch),
          HIDWORD(roll),
          LODWORD(roll),
          LODWORD(v72));
        break;
      case FX_CONTROLLER_SHAKE:
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->controllerShakeParms.highMag)),
          COERCE_UNSIGNED_INT64(fxAction->controllerShakeParms.highMag),
          COERCE_UNSIGNED_INT64(fxAction->controllerShakeParms.lowMag),
          COERCE_UNSIGNED_INT64(fxAction->controllerShakeParms.highDuration),
          COERCE_UNSIGNED_INT64(fxAction->controllerShakeParms.lowDuration));
        break;
      case FX_WIND:
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->windParms.angle)),
          COERCE_UNSIGNED_INT64(fxAction->windParms.angle),
          COERCE_UNSIGNED_INT64(fxAction->windParms.multiplier),
          COERCE_UNSIGNED_INT64(fxAction->windParms.strength.x),
          COERCE_UNSIGNED_INT64(fxAction->windParms.strength.y),
          COERCE_UNSIGNED_INT64(fxAction->distance));
        break;
      case FX_RENDERPARM:
        declRenderParm = fxAction->renderParmParms.declRenderParm;
        if ( declRenderParm != nullptr )
          f->WriteFloatString(this: f, a2: "\t\trenderParm\t\t\t\t\"%s\"\n", declRenderParm->name.str);
        f->WriteFloatString(
          this: f,
          a2: "\t\tcolor\t\t\t%.3f, %.3f, %.3f, %.3f\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.y)),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->color.y),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->color.z),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->color.w));
        break;
      case FX_ENV_OVERRIDE:
        if ( fxAction->envParms.declEnv != nullptr )
          f->WriteFloatString(
            this: f,
            a2: "\t\tenvironment\t\t\t\t\"%s\", %.3f\n",
            (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->distance)),
            (unsigned int)COERCE_UNSIGNED_INT64(fxAction->distance));
        break;
      case FX_ENV_CHANGE:
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->distance)),
          COERCE_UNSIGNED_INT64(fxAction->distance));
        v58 = 0;
        if ( fxAction->envParms.envRenderParm.num > 0 )
        {
          v59 = 0;
          do
          {
            v60 = (_DWORD *)&intensity + 1;
            p_w = &fxAction->envParms.envRenderParm.list[v59 - 1].value.w;
            for ( i = 5; i != 0; --i )
              *++v60 = *(_DWORD *)++p_w;
            v63 = f->__vftable;
            v64 = *(_DWORD *)(v74 + 8);
            v65 = idQuat::ToString(this: &v75, precision: 2);
            v63->WriteFloatString(this: f, a2: " \"%s\" \"%s\"", v64, v65);
            ++v58;
            ++v59;
          }
          while ( v58 < fxAction->envParms.envRenderParm.num );
        }
        f->WriteFloatString(this: f, a2: "\n");
        break;
      case FX_FLARE:
        f->WriteFloatString(
          this: f,
          a2: "\t\tflare\t\t\t\t\"%s\", %.3f, %.3f, %.3f, %d, %.3f, %.3f\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->flareParms.position.x)),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->flareParms.position.x),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->flareParms.position.y),
          (unsigned int)COERCE_UNSIGNED_INT64(fxAction->flareParms.position.z),
          fxAction->fadeStartDistance);
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->color.x)),
          COERCE_UNSIGNED_INT64(fxAction->color.x),
          COERCE_UNSIGNED_INT64(fxAction->color.y),
          COERCE_UNSIGNED_INT64(fxAction->color.z),
          COERCE_UNSIGNED_INT64(fxAction->color.w));
        break;
      case FX_RADIAL_BLUR:
        f->WriteFloatString(
          this: f,
          a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(fxAction->distance)),
          COERCE_UNSIGNED_INT64(fxAction->distance),
          COERCE_UNSIGNED_INT64(fxAction->radialBlurParms.maxScale));
        break;
      case FX_RIBBON:
        declRibbon = fxAction->ribbonParms.declRibbon;
        if ( declRibbon != nullptr )
          f->WriteFloatString(this: f, a2: "\t\tribbon\t\t\t\t\"%s\"\n", declRibbon->name.str);
        break;
      case FX_FADE_PARENT:
        f->WriteFloatString(this: f, a2: "\t\tfadeParent\n");
        break;
      default:
        break;
    }
    f->WriteFloatString(this: f, a2: "\t}\n");
  }
}


// ========================================================================
// ?RebuildTextSource@idDeclFX@@UAA_NXZ
// EA  : 0x8261CA98
// RVA : 0x0061CA98
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

int __fastcall idDeclFX::RebuildTextSource(idDeclFX *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  va *v5; // r3
  int v6; // r29
  int v7; // r28
  int v9; // [sp+8h] [-11C8h]
  int v10; // [sp+Ch] [-11C4h]
  int v11; // [sp+10h] [-11C0h]
  int v12; // [sp+14h] [-11BCh]
  int v13; // [sp+18h] [-11B8h]
  int v14; // [sp+1Ch] [-11B4h]
  idFile_Memory v15; // [sp+50h] [-1180h] BYREF
  va v16; // [sp+1A0h] [-1030h] BYREF

  idFile_Memory::idFile_Memory(this: &v15);
  idFile::WriteFloatString(this: &v15, fmt: "{\n");
  idFile::WriteFloatString(this: &v15, fmt: "\t");
  HIDWORD(v2) = &consoleFont[21088];
  LODWORD(v3) = &unk_821C0000;
  LODWORD(v4) = 1;
  HIDWORD(v4) = FX_TEXT_VERSION_STRING;
  v5 = va::va(this: &v16, fmt: "%s %d", a3: v4, a4: v3, a5: v2, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
  idFile::WriteFloatString(this: &v15, fmt: v5->buffer);
  idFile::WriteFloatString(this: &v15, fmt: "\n\n");
  v6 = 0;
  if ( this->editEvents.num > 0 )
  {
    v7 = 0;
    do
    {
      idDeclFX::WriteSingleFXAction(this, f: &v15, fxAction: &this->editEvents.list[v7]);
      ++v6;
      ++v7;
    }
    while ( v6 < this->editEvents.num );
  }
  idFile::WriteFloatString(this: &v15, fmt: "}");
  idDecl::SetText(this: &this->idDecl, text: v15.filePtr, length: 0);
  idFile_Memory::~idFile_Memory(this: &v15);
  return 1;
}


// ========================================================================
// __unwind$222316
// EA  : 0x8261CB80
// RVA : 0x0061CB80
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_222316()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 4560 + 80));
}


// ========================================================================
// ?Default@idFXSingleAction@@AAAXXZ
// EA  : 0x8261CBA8
// RVA : 0x0061CBA8
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idFXSingleAction::Default(idFXSingleAction *this)
{
  this->type = FX_MAX;
  idAtomicString::Set(this: &this->name, str_: "<none>");
  this->implicit = false;
  this->multiTagUseType = FX_MULTI_TAG_USE_RND;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tagNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startCondition);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stopCondition);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->extraCondition);
  this->delay.x = 0.0;
  this->delay.y = 0.0;
  this->restart = false;
  this->looping = false;
  this->duration = 2.0;
  this->noshadows = true;
  this->fadeInTime = 0.0;
  this->originType = FX_ORG_START_POS;
  this->fadeOutTime = 0.0;
  this->rotationType = FX_ROT_START_AXIS;
  this->offset = vec3_origin;
  this->rndRotX.x = 0.0;
  this->rndRotX.y = 0.0;
  this->rndRotY.x = 0.0;
  this->rndRotY.y = 0.0;
  this->rndRotZ.x = 0.0;
  this->rndRotZ.y = 0.0;
  this->rotOffsetAngles = ang_zero;
  this->explicitAngles = ang_zero;
  this->fadeStartDistance = 0.0;
  this->distance = -1.0;
  this->size = 1.0;
  this->color.x = 1.0;
  this->color.y = 1.0;
  this->color.z = 1.0;
  this->color.w = 1.0;
  this->customTable1 = nullptr;
  this->customTable2 = nullptr;
  this->screenShakeParms.magnitude = 0.0;
  this->customRenderParm = nullptr;
  this->screenShakeParms.maxAngles.pitch = 0.2;
  this->screenShakeParms.maxAngles.yaw = 0.2;
  this->screenShakeParms.maxAngles.roll = 0.2;
  this->screenShakeParms.maxOffset.x = 0.2;
  this->screenShakeParms.maxOffset.y = 0.2;
  this->screenShakeParms.maxOffset.z = 0.2;
  this->particleParms.smokeSystemRate = 1;
  this->particleParms.declPrt = nullptr;
  this->particleParms.trackVelocity = false;
  this->particleParms.useSmokeSystem = false;
  this->controllerShakeParms.highDuration = 200.0;
  this->particleParms.isScreenPrt = false;
  this->controllerShakeParms.lowDuration = 100.0;
  this->particleParms.minVelocity = 0.0;
  this->particleParms.trailSpacing = 0.0;
  this->particleParms.screenPrtExcludeAngle = -1.0;
  this->controllerShakeParms.highMag = 0.5;
  this->controllerShakeParms.lowMag = 1.0;
  this->particleParms.velocityScale = 1.0;
  this->lightParms.radius = vec3_origin;
  this->lightParms.intensity = 1.0;
  this->flareParms.position.z = 0.0;
  this->flareParms.position.y = 0.0;
  this->flareParms.position.x = 0.0;
  this->flareParms.isAutosprited = false;
  this->decalParms.angle = 0.0;
  this->rotateTableYaw = nullptr;
  this->windParms.angle = 0.0;
  this->rotateTableRoll = nullptr;
  this->soundParms.channel = SND_CHANNEL_ANY;
  this->windParms.multiplier = 0.1;
  this->rotateTablePitch = nullptr;
  this->windParms.strength.x = 10.0;
  this->windParms.strength.y = 30.0;
  this->radialBlurParms.maxScale = 0.30000001;
  this->decalParms.depth = 8.0;
  this->axis = mat3_identity;
  this->rotOffset = mat3_identity;
  this->soundParms.sound = nullptr;
  this->decalParms.decalMtr = nullptr;
  this->lightParms.lightMtr = nullptr;
  this->flareParms.declFlare = nullptr;
  this->envParms.declEnv = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->envParms.envRenderParm);
  this->renderParmParms.declRenderParm = nullptr;
  this->modelParms.customMaterial = nullptr;
  this->ribbonParms.declRibbon = nullptr;
  this->triggered = false;
  this->colorTableRGB = nullptr;
  this->colorTableA = nullptr;
}


// ========================================================================
// ?GetMaxDuration@idDeclFX@@QBA?BHW4fxCondition_t@@@Z
// EA  : 0x8261CEA8
// RVA : 0x0061CEA8
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

int __fastcall idDeclFX::GetMaxDuration(idDeclFX *this, fxCondition_t startCondition)
{
  int num; // r11
  int result; // r3
  int v5; // ctr
  idFXSingleAction *list; // r7
  idList<enum fxCondition_t,109> *p_startCondition; // r6
  int v8; // r8
  int v9; // r10
  fxCondition_t *v10; // r9
  int v11; // r11
  int maxSystemDuration; // r10
  const idDeclParticle *declPrt; // r11
  double v14; // fp12

  num = this->events.num;
  result = 0;
  if ( num > 0 )
  {
    v5 = num;
    list = this->events.list;
    p_startCondition = &list->startCondition;
    do
    {
      if ( startCondition == FX_NONE )
        goto LABEL_11;
      v8 = p_startCondition->num;
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = p_startCondition->list;
        v11 = 0;
        while ( v10[v11] != startCondition )
        {
          ++v9;
          ++v11;
          if ( v9 >= v8 )
            goto LABEL_17;
        }
        if ( v9 >= 0 && &v10[v9] != nullptr )
        {
LABEL_11:
          maxSystemDuration = (int)(float)(list->duration * (float)1000.0);
          if ( maxSystemDuration <= 0 && list->type == FX_PARTICLE )
          {
            declPrt = list->particleParms.declPrt;
            if ( declPrt != nullptr )
              maxSystemDuration = declPrt->maxSystemDuration;
          }
          v14 = (float)(list->delay.y * (float)1000.0);
          if ( (int)v14 + maxSystemDuration > result )
            result = (int)v14 + maxSystemDuration;
        }
      }
LABEL_17:
      ++list;
      p_startCondition += 52;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetMaxFadeOutTime@idDeclFX@@QBA?BHW4fxCondition_t@@@Z
// EA  : 0x8261CF98
// RVA : 0x0061CF98
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

int __fastcall idDeclFX::GetMaxFadeOutTime(idDeclFX *this, fxCondition_t startCondition)
{
  int num; // r11
  int result; // r3
  int v5; // ctr
  idFXSingleAction *list; // r6
  idList<enum fxCondition_t,109> *p_startCondition; // r7
  int v8; // r8
  int v9; // r10
  fxCondition_t *v10; // r9
  int v11; // r11
  double v12; // fp12

  num = this->events.num;
  result = 0;
  if ( num > 0 )
  {
    v5 = num;
    list = this->events.list;
    p_startCondition = &list->startCondition;
    do
    {
      if ( startCondition == FX_NONE )
        goto LABEL_11;
      v8 = p_startCondition->num;
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = p_startCondition->list;
        v11 = 0;
        while ( v10[v11] != startCondition )
        {
          ++v9;
          ++v11;
          if ( v9 >= v8 )
            goto LABEL_13;
        }
        if ( v9 >= 0 && &v10[v9] != nullptr )
        {
LABEL_11:
          v12 = (float)(list->fadeOutTime * (float)1000.0);
          if ( (int)v12 > result )
            result = (int)v12;
        }
      }
LABEL_13:
      ++list;
      p_startCondition += 52;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}


// ========================================================================
// ??0idFXSingleAction@@QAA@XZ
// EA  : 0x8261D530
// RVA : 0x0061D530
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

idFXSingleAction *__fastcall idFXSingleAction::idFXSingleAction(idFXSingleAction *this)
{
  this->name.str = &byte_8200D768;
  this->group.str = &byte_8200D768;
  this->fire.str = &byte_8200D768;
  this->tagNames.list = nullptr;
  this->tagNames.granularity = 0;
  this->tagNames.memTag = 109;
  this->tagNames.listStatic = 0;
  this->tagNames.size = 0;
  this->tagNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tagNames);
  this->startCondition.list = nullptr;
  this->startCondition.granularity = 0;
  this->startCondition.memTag = 109;
  this->startCondition.listStatic = 0;
  this->startCondition.size = 0;
  this->startCondition.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startCondition);
  this->stopCondition.list = nullptr;
  this->stopCondition.granularity = 0;
  this->stopCondition.memTag = 109;
  this->stopCondition.listStatic = 0;
  this->stopCondition.size = 0;
  this->stopCondition.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stopCondition);
  this->extraCondition.list = nullptr;
  this->extraCondition.granularity = 0;
  this->extraCondition.memTag = 109;
  this->extraCondition.listStatic = 0;
  this->extraCondition.size = 0;
  this->extraCondition.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->extraCondition);
  this->modelParms.modelName.str = &byte_8200D768;
  idStaticList<idFXRenderParm,16>::idStaticList<idFXRenderParm,16>(this: &this->envParms.envRenderParm);
  idFXSingleAction::Default(this);
  return this;
}


// ========================================================================
// __unwind$223736
// EA  : 0x8261D62C
// RVA : 0x0061D62C
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223736()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 76));
}


// ========================================================================
// __unwind$223737
// EA  : 0x8261D658
// RVA : 0x0061D658
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223737()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}


// ========================================================================
// __unwind$223738
// EA  : 0x8261D684
// RVA : 0x0061D684
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223738()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 108));
}


// ========================================================================
// __unwind$223739
// EA  : 0x8261D6B0
// RVA : 0x0061D6B0
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223739()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 124));
}


// ========================================================================
// __unwind$223740
// EA  : 0x8261D6DC
// RVA : 0x0061D6DC
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223740()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 388));
}


// ========================================================================
// ?ParseSingleFXAction@idDeclFX@@AAAXAAVidParser@@AAVidFXSingleAction@@@Z
// EA  : 0x8261D710
// RVA : 0x0061D710
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idDeclFX::ParseSingleFXAction(idDeclFX *this, idParser *src, idFXSingleAction *FXAction)
{
  __int64 v3; // r30
  __int64 v4; // r22
  idDeclInfo *v5; // r26
  idDeclInfo *v6; // r27
  double v7; // fp1
  const enumTypeInfo_t *v8; // r4
  const enumValueInfo_t *v9; // r3
  char *data; // r26
  idAtomicString *v11; // r3
  const char *v12; // r27
  const enumTypeInfo_t *v13; // r4
  const enumValueInfo_t *v14; // r3
  const char *v15; // r27
  const enumTypeInfo_t *v16; // r4
  const enumValueInfo_t *v17; // r3
  const enumTypeInfo_t *v18; // r4
  const enumValueInfo_t *v19; // r3
  const enumTypeInfo_t *v20; // r4
  const enumValueInfo_t *v21; // r3
  const enumTypeInfo_t *v22; // r4
  const enumValueInfo_t *v23; // r3
  idMat3 *v24; // r3
  idMat3 *v25; // r3
  const idDecl *v26; // r3
  const char *v27; // r4
  const idDecl *v28; // r3
  const idDecl *v29; // r3
  const idDecl *v30; // r3
  const idDecl *v31; // r3
  const idDeclRenderParm *v32; // r3
  int v33; // r5
  const enumTypeInfo_t *EnumInfo; // r4
  const enumValueInfo_t *EnumValueInfo; // r3
  const char *value; // [sp+50h] [-550h] BYREF
  const char *v37; // [sp+54h] [-54Ch]
  const char *v38; // [sp+58h] [-548h]
  int v39; // [sp+5Ch] [-544h]
  idDeclInfo *v40; // [sp+60h] [-540h]
  const char *v41; // [sp+64h] [-53Ch]
  const char *v42; // [sp+68h] [-538h]
  int v43; // [sp+6Ch] [-534h]
  idToken v44; // [sp+70h] [-530h] BYREF
  const char *v45; // [sp+B8h] [-4E8h]
  const char *v46; // [sp+BCh] [-4E4h]
  const char *v47; // [sp+C0h] [-4E0h]
  const char *v48; // [sp+C4h] [-4DCh]
  const char *v49; // [sp+C8h] [-4D8h]
  const char *v50; // [sp+CCh] [-4D4h]
  const char *v51; // [sp+D0h] [-4D0h]
  const char *v52; // [sp+D4h] [-4CCh]
  const char *v53; // [sp+D8h] [-4C8h]
  const char *v54; // [sp+DCh] [-4C4h]
  const char *v55; // [sp+E0h] [-4C0h]
  const char *v56; // [sp+E4h] [-4BCh]
  const char *v57; // [sp+E8h] [-4B8h]
  const char *v58; // [sp+ECh] [-4B4h]
  const char *v59; // [sp+F0h] [-4B0h]
  const char *v60; // [sp+F4h] [-4ACh]
  const char *v61; // [sp+F8h] [-4A8h]
  const char *v62; // [sp+FCh] [-4A4h]
  const char *v63; // [sp+100h] [-4A0h]
  const char *v64; // [sp+104h] [-49Ch]
  const char *v65; // [sp+108h] [-498h]
  const char *v66; // [sp+10Ch] [-494h]
  idDeclInfo *v67; // [sp+110h] [-490h]
  const char *v68; // [sp+114h] [-48Ch]
  const char *v69; // [sp+118h] [-488h]
  const char *v70; // [sp+11Ch] [-484h]
  const char *v71; // [sp+120h] [-480h]
  const char *v72; // [sp+124h] [-47Ch]
  const char *v73; // [sp+128h] [-478h]
  idDeclInfo *v74; // [sp+12Ch] [-474h]
  const char *v75; // [sp+130h] [-470h]
  const char *v76; // [sp+134h] [-46Ch]
  const char *v77; // [sp+138h] [-468h]
  const char *v78; // [sp+13Ch] [-464h]
  const char *v79; // [sp+140h] [-460h]
  const char *v80; // [sp+144h] [-45Ch]
  const char *v81; // [sp+148h] [-458h]
  idDeclInfoTemplate<idDeclFlare> *v82; // [sp+14Ch] [-454h]
  idDeclInfo *v83; // [sp+150h] [-450h]
  const char *v84; // [sp+158h] [-448h]
  int v85; // [sp+15Ch] [-444h]
  const char *v86; // [sp+160h] [-440h]
  idDeclInfoTemplate<idDeclRibbon> *v87; // [sp+168h] [-438h]
  int v88; // [sp+16Ch] [-434h]
  const char *v89; // [sp+170h] [-430h]
  const char *v90; // [sp+174h] [-42Ch]
  const char *v91; // [sp+178h] [-428h]
  const char *v92; // [sp+17Ch] [-424h]
  const char *v93; // [sp+180h] [-420h]
  const char *v94; // [sp+184h] [-41Ch]
  const char *v95; // [sp+188h] [-418h]
  const char *v96; // [sp+18Ch] [-414h]
  const char *v97; // [sp+190h] [-410h]
  const char *v98; // [sp+194h] [-40Ch]
  const char *v99; // [sp+198h] [-408h]
  const char *v100; // [sp+19Ch] [-404h]
  const char *v101; // [sp+1A0h] [-400h]
  const char *v102; // [sp+1A8h] [-3F8h]
  int v103; // [sp+1ACh] [-3F4h]
  const char *v104; // [sp+1B0h] [-3F0h]
  const char *v105; // [sp+1B8h] [-3E8h]
  int v106; // [sp+1BCh] [-3E4h]
  const char *v107; // [sp+1C0h] [-3E0h]
  const char *v108; // [sp+1C4h] [-3DCh]
  const char *v109; // [sp+1C8h] [-3D8h]
  const char *v110; // [sp+1CCh] [-3D4h]
  const char *v111; // [sp+1D0h] [-3D0h]
  idFXRenderParm v112; // [sp+1E0h] [-3C0h] BYREF
  __int64 v113; // [sp+1F8h] [-3A8h]
  __int64 v114; // [sp+200h] [-3A0h]
  unsigned __int64 v115; // [sp+208h] [-398h]
  idAngles v116[4]; // [sp+210h] [-390h] BYREF
  idParser v117; // [sp+240h] [-360h] BYREF

  v44.len = 0;
  LODWORD(v3) = src;
  v44.allocedAndFlag = 20;
  v44.data = v44.baseBuffer;
  v44.floatvalue = -3.4028235e38;
  v44.baseBuffer[0] = 0;
  v44.intvalue = 0;
  memset(&v44.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v44) )
  {
    v114 = v3;
    v93 = (const char *)-2113338092;
    v101 = "FX File: bad token";
    v99 = (const char *)-2113537604;
    v91 = (const char *)-2112116764;
    v97 = (const char *)-2113338192;
    v95 = (const char *)-2113338176;
    v88 = -2113536000;
    v85 = -2113339392;
    v106 = -2090532864;
    v103 = -2090532864;
    v65 = (const char *)-2113453320;
    v89 = (const char *)-2113598304;
    v71 = (const char *)-2112116856;
    v69 = (const char *)-2112116784;
    v67 = (idDeclInfo *)-2090528236;
    v84 = "colorTableAlpha";
    v100 = "colorTableRGB";
    v82 = &idDeclFlare::resourceList;
    v86 = (const char *)-2113586780;
    v83 = (idDeclInfo *)-2089035556;
    v81 = (const char *)-2113603160;
    v79 = (const char *)-2113613260;
    v77 = (const char *)-2113340980;
    v75 = (const char *)-2112116808;
    v73 = (const char *)-2112116840;
    v63 = (const char *)-2113384796;
    v90 = "decal2";
    v102 = "decal";
    v87 = &idDeclRibbon::resourceList;
    v105 = "ribbon";
    v98 = "screenPrtExcludeAngle";
    v39 = -2090543972;
    v74 = (idDeclInfo *)-2090539476;
    v72 = (const char *)-2113338532;
    v76 = "trailSpacing";
    v62 = "inePathParams.tautFraction";
    v111 = "smokeSystemRate";
    v78 = "isScreenPrt";
    HIDWORD(v4) = "-------- FX_SOUND specific parms ------------------------ FX_SOUND parms";
    LODWORD(v4) = -2113339392;
    v107 = (const char *)-2090529856;
    v94 = "customTable2";
    v43 = -2090529360;
    v104 = "flare";
    v80 = "distance";
    v70 = (const char *)-2113338392;
    v110 = (const char *)-2113505964;
    v68 = (const char *)-2113586636;
    v40 = (idDeclInfo *)-2090540600;
    v113 = v4;
    v66 = (const char *)-2113231780;
    v64 = (const char *)-2113522832;
    v115 = 0x8206755482090000uLL;
    v109 = (const char *)-2113609908;
    value = "name";
    v92 = (const char *)-2112116892;
    v108 = (const char *)-2113340648;
    v59 = "noshadows";
    v61 = "fadeparent";
    v37 = (const char *)-2113844384;
    v49 = (const char *)-2113605664;
    v48 = (const char *)-2113608140;
    v96 = (const char *)-2113858856;
    v47 = (const char *)-2113336180;
    v45 = (const char *)-2113337976;
    v46 = (const char *)-2113337968;
    v38 = (const char *)-2113337876;
    v41 = "stopCondition";
    v42 = "startCondition";
    v51 = "tagName";
    v58 = "group";
    v5 = (idDeclInfo *)-2090543972;
    v56 = "name";
    v6 = (idDeclInfo *)-2090529360;
    v54 = "multiTagUseType";
    v52 = "noshadows";
    v60 = "fire";
    v55 = "controllershake";
    v57 = "shake";
    v50 = "}";
    v53 = "fadeparent";
    while ( 1 )
    {
      if ( idStr::Icmp(s1: v44.data, s2: v50) == 0 )
        goto LABEL_212;
      if ( idStr::Icmp(s1: v44.data, s2: v57) != 0 )
      {
        if ( idStr::Icmp(s1: v44.data, s2: v55) != 0 )
        {
          if ( idStr::Icmp(s1: v44.data, s2: v53) != 0 )
          {
            if ( idStr::Icmp(s1: v44.data, s2: v52) != 0 )
            {
              if ( idStr::Icmp(s1: v44.data, s2: v56) != 0 )
              {
                if ( idStr::Icmp(s1: v44.data, s2: v58) != 0 )
                {
                  if ( idStr::Icmp(s1: v44.data, s2: v60) != 0 )
                  {
                    if ( idStr::Icmp(s1: v44.data, s2: v54) != 0 )
                    {
                      if ( idStr::Icmp(s1: v44.data, s2: v51) != 0 )
                      {
                        if ( idStr::Icmp(s1: v44.data, s2: v42) != 0 )
                        {
                          if ( idStr::Icmp(s1: v44.data, s2: v41) != 0 )
                          {
                            if ( idStr::Icmp(s1: v44.data, s2: "extraCondition") != 0 )
                            {
                              if ( idStr::Icmp(s1: v44.data, s2: "delay") != 0 )
                              {
                                if ( idStr::Icmp(s1: v44.data, s2: "duration") != 0 )
                                {
                                  if ( idStr::Icmp(s1: v44.data, s2: "originType") != 0 )
                                  {
                                    if ( idStr::Icmp(s1: v44.data, s2: "rotationType") != 0 )
                                    {
                                      if ( idStr::Icmp(s1: v44.data, s2: v38) != 0 )
                                      {
                                        if ( idStr::Icmp(s1: v44.data, s2: v46) != 0 )
                                        {
                                          if ( idStr::Icmp(s1: v44.data, s2: v45) != 0 )
                                          {
                                            if ( idStr::Icmp(s1: v44.data, s2: v47) != 0 )
                                            {
                                              if ( idStr::Icmp(s1: v44.data, s2: v48) != 0 )
                                              {
                                                if ( idStr::Icmp(s1: v44.data, s2: v49) != 0 )
                                                {
                                                  if ( idStr::Icmp(s1: v44.data, s2: v37) != 0 )
                                                  {
                                                    if ( idStr::Icmp(s1: v44.data, s2: v96) != 0 )
                                                    {
                                                      if ( idStr::Icmp(s1: v44.data, s2: v109) != 0 )
                                                      {
                                                        if ( idStr::Icmp(s1: v44.data, s2: v64) != 0 )
                                                        {
                                                          if ( idStr::Icmp(s1: v44.data, s2: v108) != 0 )
                                                          {
                                                            if ( idStr::Icmp(s1: v44.data, s2: v66) != 0 )
                                                            {
                                                              if ( idStr::Icmp(s1: v44.data, s2: v92) != 0 )
                                                              {
                                                                if ( idStr::Icmp(s1: v44.data, s2: v68) != 0 )
                                                                {
                                                                  if ( idStr::Icmp(s1: v44.data, s2: v110) != 0 )
                                                                  {
                                                                    if ( idStr::Icmp(s1: v44.data, s2: v70) != 0 )
                                                                    {
                                                                      if ( idStr::Icmp(s1: v44.data, s2: v94) != 0 )
                                                                      {
                                                                        if ( idStr::Icmp(s1: v44.data, s2: v72) != 0 )
                                                                        {
                                                                          if ( idStr::Icmp(s1: v44.data, s2: v107) != 0 )
                                                                          {
                                                                            if ( idStr::Icmp(s1: v44.data, s2: v62) != 0 )
                                                                            {
                                                                              if ( idStr::Icmp(s1: v44.data, s2: v76) != 0 )
                                                                              {
                                                                                if ( idStr::Icmp(s1: v44.data, s2: v111) != 0 )
                                                                                {
                                                                                  if ( idStr::Icmp(
                                                                                         s1: v44.data,
                                                                                         s2: v78) != 0 )
                                                                                  {
                                                                                    if ( idStr::Icmp(
                                                                                           s1: v44.data,
                                                                                           s2: v98) != 0 )
                                                                                    {
                                                                                      if ( idStr::Icmp(
                                                                                             s1: v44.data,
                                                                                             s2: v80) != 0 )
                                                                                      {
                                                                                        if ( idStr::Icmp(
                                                                                               s1: v44.data,
                                                                                               s2: v104) != 0 )
                                                                                        {
                                                                                          if ( idStr::Icmp(
                                                                                                 s1: v44.data,
                                                                                                 s2: v100) != 0 )
                                                                                          {
                                                                                            if ( idStr::Icmp(
                                                                                                   s1: v44.data,
                                                                                                   s2: v84) != 0 )
                                                                                            {
                                                                                              if ( idStr::Icmp(
                                                                                                     s1: v44.data,
                                                                                                     s2: v105) != 0 )
                                                                                              {
                                                                                                if ( idStr::Icmp(s1: v44.data, s2: v102) != 0 )
                                                                                                {
                                                                                                  if ( idStr::Icmp(s1: v44.data, s2: v90) != 0 )
                                                                                                  {
                                                                                                    if ( idStr::Icmp(s1: v44.data, s2: v63) != 0 )
                                                                                                    {
                                                                                                      if ( idStr::Icmp(s1: v44.data, s2: v65) != 0 )
                                                                                                      {
                                                                                                        if ( idStr::Icmp(s1: v44.data, s2: v69) != 0 )
                                                                                                        {
                                                                                                          if ( idStr::Icmp(s1: v44.data, s2: v73) != 0 )
                                                                                                          {
                                                                                                            if ( idStr::Icmp(s1: v44.data, s2: v75) != 0 )
                                                                                                            {
                                                                                                              if ( idStr::Icmp(s1: v44.data, s2: v77) != 0 )
                                                                                                              {
                                                                                                                if ( idStr::Icmp(s1: v44.data, s2: v79) != 0 )
                                                                                                                {
                                                                                                                  if ( idStr::Icmp(s1: v44.data, s2: v81) != 0 )
                                                                                                                  {
                                                                                                                    if ( idStr::Icmp(s1: v44.data, s2: v86) != 0 )
                                                                                                                    {
                                                                                                                      if ( idStr::Icmp(s1: v44.data, s2: v93) != 0 )
                                                                                                                      {
                                                                                                                        if ( idStr::Icmp(s1: v44.data, s2: v95) != 0 )
                                                                                                                        {
                                                                                                                          if ( idStr::Icmp(s1: v44.data, s2: v97) != 0 )
                                                                                                                          {
                                                                                                                            if ( idStr::Icmp(s1: v44.data, s2: v99) != 0 )
                                                                                                                            {
                                                                                                                              idParser::Warning(this: (idParser *)v3, str: v101);
                                                                                                                            }
                                                                                                                            else
                                                                                                                            {
                                                                                                                              idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                              if ( v44.data != nullptr )
                                                                                                                                *(_DWORD *)(HIDWORD(v3) + 384) = idDeclInfo::FindWithInheritance(this: v5, name: v44.data, makeDefault: true);
                                                                                                                              else
                                                                                                                                *(_DWORD *)(HIDWORD(v3) + 384) = 0;
                                                                                                                              *(_DWORD *)(HIDWORD(v3) + 8) = 9;
                                                                                                                            }
                                                                                                                          }
                                                                                                                          else
                                                                                                                          {
                                                                                                                            idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                            if ( v44.data != nullptr )
                                                                                                                              *(_DWORD *)(HIDWORD(v3) + 216) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                                                                            else
                                                                                                                              *(_DWORD *)(HIDWORD(v3) + 216) = 0;
                                                                                                                          }
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                          idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                          if ( v44.data != nullptr )
                                                                                                                            *(_DWORD *)(HIDWORD(v3) + 212) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                                                                          else
                                                                                                                            *(_DWORD *)(HIDWORD(v3) + 212) = 0;
                                                                                                                        }
                                                                                                                      }
                                                                                                                      else
                                                                                                                      {
                                                                                                                        idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                        if ( v44.data != nullptr )
                                                                                                                          *(_DWORD *)(HIDWORD(v3) + 208) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                                                                        else
                                                                                                                          *(_DWORD *)(HIDWORD(v3) + 208) = 0;
                                                                                                                      }
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                      idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                      EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: v89);
                                                                                                                      if ( EnumInfo != nullptr && (EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this: typeInfoTools, enumInfo: EnumInfo, name: v44.data, defaultIfNotFound: false)) != nullptr )
                                                                                                                        *(_DWORD *)(HIDWORD(v3) + 316) = EnumValueInfo->value;
                                                                                                                      else
                                                                                                                        idLib::Warning(fmt: v91, this->name.str, v44.data);
                                                                                                                    }
                                                                                                                  }
                                                                                                                  else
                                                                                                                  {
                                                                                                                    idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                                    if ( v44.data != nullptr )
                                                                                                                      *(_DWORD *)(HIDWORD(v3) + 320) = idDeclInfo::FindWithInheritance(this: v83, name: v44.data, makeDefault: true);
                                                                                                                    else
                                                                                                                      *(_DWORD *)(HIDWORD(v3) + 320) = 0;
                                                                                                                    *(_DWORD *)(HIDWORD(v3) + 8) = 5;
                                                                                                                  }
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                  *(float *)(HIDWORD(v3) + 264) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                                }
                                                                                                              }
                                                                                                              else
                                                                                                              {
                                                                                                                *(float *)(HIDWORD(v3) + 268) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                              }
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                              *(_BYTE *)(HIDWORD(v3) + 260) = 1;
                                                                                                            }
                                                                                                          }
                                                                                                          else
                                                                                                          {
                                                                                                            *(_DWORD *)(HIDWORD(v3) + 8) = 13;
                                                                                                            *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                            idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                            *(float *)(HIDWORD(v3) + 728) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                          }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                          *(_DWORD *)(HIDWORD(v3) + 8) = 11;
                                                                                                          *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                          while ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 )
                                                                                                          {
                                                                                                            v112.value.w = 0.0;
                                                                                                            v112.value.z = 0.0;
                                                                                                            v112.parm = nullptr;
                                                                                                            v112.value.y = 0.0;
                                                                                                            v112.value.x = 0.0;
                                                                                                            if ( v44.data != nullptr )
                                                                                                              v32 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(this: v5, name: v44.data, makeDefault: true);
                                                                                                            else
                                                                                                              v32 = nullptr;
                                                                                                            v112.parm = v32;
                                                                                                            idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                            idParser::idParser(this: &v117, flags: 0);
                                                                                                            v33 = 0;
                                                                                                            if ( *v44.data != 0 )
                                                                                                            {
                                                                                                              do
                                                                                                                ++v33;
                                                                                                              while ( v44.data[v33] != 0 );
                                                                                                            }
                                                                                                            idParser::LoadMemory(this: &v117, ptr: v44.data, length: v33, name: v71);
                                                                                                            idDeclRenderParm::ParseVectorConstant(src: &v117, vec: &v112.value.x);
                                                                                                            idList<idFXRenderParm,5>::Append(this: (idList<idFXRenderParm,5> *)(HIDWORD(v3) + 392), obj: &v112);
                                                                                                            idParser::~idParser(this: &v117);
                                                                                                          }
                                                                                                        }
                                                                                                      }
                                                                                                      else
                                                                                                      {
                                                                                                        idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                        if ( v44.data != nullptr )
                                                                                                          v31 = idDeclInfo::FindWithInheritance(this: v67, name: v44.data, makeDefault: true);
                                                                                                        else
                                                                                                          v31 = nullptr;
                                                                                                        *(_DWORD *)(HIDWORD(v3) + 388) = v31;
                                                                                                        idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                        *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                        *(_DWORD *)(HIDWORD(v3) + 8) = 10;
                                                                                                      }
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                      *(float *)(HIDWORD(v3) + 368) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                      *(float *)(HIDWORD(v3) + 372) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                      *(float *)(HIDWORD(v3) + 376) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                      *(float *)(HIDWORD(v3) + 380) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                      *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                      *(_DWORD *)(HIDWORD(v3) + 8) = 8;
                                                                                                    }
                                                                                                  }
                                                                                                  else
                                                                                                  {
                                                                                                    idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                                                    if ( v44.data != nullptr )
                                                                                                      v30 = idDeclInfo::FindWithInheritance(this: v40, name: v44.data, makeDefault: true);
                                                                                                    else
                                                                                                      v30 = nullptr;
                                                                                                    *(_DWORD *)(HIDWORD(v3) + 304) = v30;
                                                                                                    idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                                                                    *(float *)(HIDWORD(v3) + 300) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                    *(_DWORD *)(HIDWORD(v3) + 8) = 3;
                                                                                                  }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                  idParser::ReadToken(
                                                                                                    this: (idParser *)v3,
                                                                                                    token: &v44);
                                                                                                  if ( v44.data != nullptr )
                                                                                                    v29 = idDeclInfo::FindWithInheritance(this: v40, name: v44.data, makeDefault: true);
                                                                                                  else
                                                                                                    v29 = nullptr;
                                                                                                  *(_DWORD *)(HIDWORD(v3) + 304) = v29;
                                                                                                  idParser::ExpectTokenString(
                                                                                                    this: (idParser *)v3,
                                                                                                    string: ",");
                                                                                                  *(float *)(HIDWORD(v3) + 296) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                  idParser::ExpectTokenString(
                                                                                                    this: (idParser *)v3,
                                                                                                    string: ",");
                                                                                                  *(float *)(HIDWORD(v3) + 300) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                                  *(_DWORD *)(HIDWORD(v3) + 8) = 2;
                                                                                                }
                                                                                              }
                                                                                              else
                                                                                              {
                                                                                                idParser::ReadToken(
                                                                                                  this: (idParser *)v3,
                                                                                                  token: &v44);
                                                                                                if ( v44.data != nullptr )
                                                                                                  *(_DWORD *)(HIDWORD(v3) + 752) = idDeclInfo::FindWithInheritance(this: v87, name: v44.data, makeDefault: true);
                                                                                                else
                                                                                                  *(_DWORD *)(HIDWORD(v3) + 752) = 0;
                                                                                                *(_DWORD *)(HIDWORD(v3) + 8) = 14;
                                                                                              }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                              idParser::ReadToken(
                                                                                                this: (idParser *)v3,
                                                                                                token: &v44);
                                                                                              if ( v44.data != nullptr )
                                                                                                *(_DWORD *)(HIDWORD(v3) + 224) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                                              else
                                                                                                *(_DWORD *)(HIDWORD(v3) + 224) = 0;
                                                                                            }
                                                                                          }
                                                                                          else
                                                                                          {
                                                                                            idParser::ReadToken(
                                                                                              this: (idParser *)v3,
                                                                                              token: &v44);
                                                                                            if ( v44.data != nullptr )
                                                                                              *(_DWORD *)(HIDWORD(v3) + 220) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                                            else
                                                                                              *(_DWORD *)(HIDWORD(v3) + 220) = 0;
                                                                                          }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                          idParser::ReadToken(
                                                                                            this: (idParser *)v3,
                                                                                            token: &v44);
                                                                                          if ( v44.data != nullptr )
                                                                                            v28 = idDeclInfo::FindWithInheritance(
                                                                                                    this: v82,
                                                                                                    name: v44.data,
                                                                                                    makeDefault: true);
                                                                                          else
                                                                                            v28 = nullptr;
                                                                                          *(_DWORD *)(HIDWORD(v3) + 748) = v28;
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(float *)(HIDWORD(v3) + 732) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(float *)(HIDWORD(v3) + 736) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(float *)(HIDWORD(v3) + 740) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(_BYTE *)(HIDWORD(v3) + 744) = idParser::ParseBool(this: (idParser *)v3);
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(float *)(HIDWORD(v3) + 36) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                          idParser::ExpectTokenString(
                                                                                            this: (idParser *)v3,
                                                                                            string: ",");
                                                                                          *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                          *(_DWORD *)(HIDWORD(v3) + 8) = 12;
                                                                                        }
                                                                                      }
                                                                                      else
                                                                                      {
                                                                                        *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                      }
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                      *(float *)(HIDWORD(v3) + 288) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                                    }
                                                                                  }
                                                                                  else
                                                                                  {
                                                                                    *(_BYTE *)(HIDWORD(v3) + 284) = idParser::ParseBool(this: (idParser *)v3);
                                                                                  }
                                                                                }
                                                                                else
                                                                                {
                                                                                  *(_DWORD *)(HIDWORD(v3) + 276) = idParser::ParseInt(this: (idParser *)v3);
                                                                                }
                                                                              }
                                                                              else
                                                                              {
                                                                                *(float *)(HIDWORD(v3) + 280) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
                                                                              }
                                                                            }
                                                                            else
                                                                            {
                                                                              *(_BYTE *)(HIDWORD(v3) + 272) = idParser::ParseBool(this: (idParser *)v3);
                                                                            }
                                                                          }
                                                                          else
                                                                          {
                                                                            idParser::ReadToken(
                                                                              this: (idParser *)v3,
                                                                              token: &v44);
                                                                            if ( v44.data != nullptr )
                                                                              *(_DWORD *)(HIDWORD(v3) + 292) = idDeclInfo::FindWithInheritance(this: v74, name: v44.data, makeDefault: true);
                                                                            else
                                                                              *(_DWORD *)(HIDWORD(v3) + 292) = 0;
                                                                            *(_DWORD *)(HIDWORD(v3) + 8) = 1;
                                                                          }
                                                                        }
                                                                        else
                                                                        {
                                                                          idParser::ReadToken(
                                                                            this: (idParser *)v3,
                                                                            token: &v44);
                                                                          if ( v44.data != nullptr )
                                                                            *(_DWORD *)(HIDWORD(v3) + 236) = idDeclInfo::FindWithInheritance(this: v5, name: v44.data, makeDefault: true);
                                                                          else
                                                                            *(_DWORD *)(HIDWORD(v3) + 236) = 0;
                                                                        }
                                                                      }
                                                                      else
                                                                      {
                                                                        idParser::ReadToken(
                                                                          this: (idParser *)v3,
                                                                          token: &v44);
                                                                        if ( v44.data != nullptr )
                                                                          *(_DWORD *)(HIDWORD(v3) + 232) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                        else
                                                                          *(_DWORD *)(HIDWORD(v3) + 232) = 0;
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      idParser::ReadToken(
                                                                        this: (idParser *)v3,
                                                                        token: &v44);
                                                                      if ( v44.data != nullptr )
                                                                        *(_DWORD *)(HIDWORD(v3) + 228) = idDeclInfo::FindWithInheritance(this: v6, name: v44.data, makeDefault: true);
                                                                      else
                                                                        *(_DWORD *)(HIDWORD(v3) + 228) = 0;
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    idParser::ReadToken(
                                                                      this: (idParser *)v3,
                                                                      token: &v44);
                                                                    if ( v44.data != nullptr )
                                                                      *(_DWORD *)(HIDWORD(v3) + 312) = idDeclInfo::FindWithInheritance(this: v40, name: v44.data, makeDefault: true);
                                                                    else
                                                                      *(_DWORD *)(HIDWORD(v3) + 312) = 0;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                  value = (const char *)(HIDWORD(v3) + 308);
                                                                  idAtomicString::Set(
                                                                    this: (idAtomicString *)(HIDWORD(v3) + 308),
                                                                    str_: v44.data);
                                                                  v27 = *(const char **)(HIDWORD(v3) + 308);
                                                                  *(_DWORD *)(HIDWORD(v3) + 8) = 4;
                                                                  staticModelManager->FindStaticModel(
                                                                    this: staticModelManager,
                                                                    a2: v27,
                                                                    a3: true);
                                                                }
                                                              }
                                                              else
                                                              {
                                                                idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                                                if ( v44.data != nullptr )
                                                                  v26 = idDeclInfo::FindWithInheritance(
                                                                          this: v40,
                                                                          name: v44.data,
                                                                          makeDefault: true);
                                                                else
                                                                  v26 = nullptr;
                                                                *(_DWORD *)(HIDWORD(v3) + 256) = v26;
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 48) = idParser::ParseFloat(
                                                                                                 this: (idParser *)v3,
                                                                                                 errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 52) = idParser::ParseFloat(
                                                                                                 this: (idParser *)v3,
                                                                                                 errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 56) = idParser::ParseFloat(
                                                                                                 this: (idParser *)v3,
                                                                                                 errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 240) = idParser::ParseFloat(
                                                                                                  this: (idParser *)v3,
                                                                                                  errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 244) = idParser::ParseFloat(
                                                                                                  this: (idParser *)v3,
                                                                                                  errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 248) = idParser::ParseFloat(
                                                                                                  this: (idParser *)v3,
                                                                                                  errorFlag: nullptr);
                                                                idParser::ExpectTokenString(
                                                                  this: (idParser *)v3,
                                                                  string: ",");
                                                                *(float *)(HIDWORD(v3) + 252) = idParser::ParseFloat(
                                                                                                  this: (idParser *)v3,
                                                                                                  errorFlag: nullptr);
                                                                *(_DWORD *)(HIDWORD(v3) + 8) = 0;
                                                                *(float *)(HIDWORD(v3) + 60) = 1.0;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              *(float *)(HIDWORD(v3) + 196) = idParser::ParseFloat(
                                                                                                this: (idParser *)v3,
                                                                                                errorFlag: nullptr);
                                                              idParser::ExpectTokenString(
                                                                this: (idParser *)v3,
                                                                string: ",");
                                                              *(float *)(HIDWORD(v3) + 200) = idParser::ParseFloat(
                                                                                                this: (idParser *)v3,
                                                                                                errorFlag: nullptr);
                                                              idParser::ExpectTokenString(
                                                                this: (idParser *)v3,
                                                                string: ",");
                                                              *(float *)(HIDWORD(v3) + 204) = idParser::ParseFloat(
                                                                                                this: (idParser *)v3,
                                                                                                errorFlag: nullptr);
                                                              v25 = idAngles::ToMat3(
                                                                      this: v116,
                                                                      result: (idMat3 *)(HIDWORD(v3) + 196));
                                                              *(float *)(HIDWORD(v3) + 756) = v25->mat[0].x;
                                                              *(float *)(HIDWORD(v3) + 760) = v25->mat[0].y;
                                                              *(float *)(HIDWORD(v3) + 764) = v25->mat[0].z;
                                                              value = (const char *)&v25->mat[1];
                                                              *(float *)(HIDWORD(v3) + 768) = v25->mat[1].x;
                                                              value = (const char *)(HIDWORD(v3) + 768);
                                                              *(float *)(HIDWORD(v3) + 772) = v25->mat[1].y;
                                                              value = (const char *)(HIDWORD(v3) + 780);
                                                              *(float *)(HIDWORD(v3) + 776) = v25->mat[1].z;
                                                              *(idVec3 *)(HIDWORD(v3) + 780) = v25->mat[2];
                                                            }
                                                          }
                                                          else
                                                          {
                                                            *(float *)(HIDWORD(v3) + 160) = idParser::ParseFloat(
                                                                                              this: (idParser *)v3,
                                                                                              errorFlag: nullptr);
                                                            idParser::ExpectTokenString(
                                                              this: (idParser *)v3,
                                                              string: ",");
                                                            *(float *)(HIDWORD(v3) + 164) = idParser::ParseFloat(
                                                                                              this: (idParser *)v3,
                                                                                              errorFlag: nullptr);
                                                            idParser::ExpectTokenString(
                                                              this: (idParser *)v3,
                                                              string: ",");
                                                            *(float *)(HIDWORD(v3) + 168) = idParser::ParseFloat(
                                                                                              this: (idParser *)v3,
                                                                                              errorFlag: nullptr);
                                                            v24 = idAngles::ToMat3(
                                                                    this: v116,
                                                                    result: (idMat3 *)(HIDWORD(v3) + 160));
                                                            *(float *)(HIDWORD(v3) + 792) = v24->mat[0].x;
                                                            *(float *)(HIDWORD(v3) + 796) = v24->mat[0].y;
                                                            *(float *)(HIDWORD(v3) + 800) = v24->mat[0].z;
                                                            value = (const char *)&v24->mat[1];
                                                            *(float *)(HIDWORD(v3) + 804) = v24->mat[1].x;
                                                            value = (const char *)(HIDWORD(v3) + 804);
                                                            *(float *)(HIDWORD(v3) + 808) = v24->mat[1].y;
                                                            value = (const char *)(HIDWORD(v3) + 816);
                                                            *(float *)(HIDWORD(v3) + 812) = v24->mat[1].z;
                                                            *(idVec3 *)(HIDWORD(v3) + 816) = v24->mat[2];
                                                          }
                                                        }
                                                        else
                                                        {
                                                          *(float *)(HIDWORD(v3) + 144) = idParser::ParseFloat(
                                                                                            this: (idParser *)v3,
                                                                                            errorFlag: nullptr);
                                                          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                          *(float *)(HIDWORD(v3) + 148) = idParser::ParseFloat(
                                                                                            this: (idParser *)v3,
                                                                                            errorFlag: nullptr);
                                                          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                          *(float *)(HIDWORD(v3) + 152) = idParser::ParseFloat(
                                                                                            this: (idParser *)v3,
                                                                                            errorFlag: nullptr);
                                                        }
                                                      }
                                                      else
                                                      {
                                                        *(float *)(HIDWORD(v3) + 48) = idParser::ParseFloat(
                                                                                         this: (idParser *)v3,
                                                                                         errorFlag: nullptr);
                                                        idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                        *(float *)(HIDWORD(v3) + 52) = idParser::ParseFloat(
                                                                                         this: (idParser *)v3,
                                                                                         errorFlag: nullptr);
                                                        idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                        *(float *)(HIDWORD(v3) + 56) = idParser::ParseFloat(
                                                                                         this: (idParser *)v3,
                                                                                         errorFlag: nullptr);
                                                        idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                                        *(float *)(HIDWORD(v3) + 60) = idParser::ParseFloat(
                                                                                         this: (idParser *)v3,
                                                                                         errorFlag: nullptr);
                                                      }
                                                    }
                                                    else
                                                    {
                                                      *(float *)(HIDWORD(v3) + 44) = idParser::ParseFloat(
                                                                                       this: (idParser *)v3,
                                                                                       errorFlag: nullptr);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    *(float *)(HIDWORD(v3) + 32) = idParser::ParseFloat(
                                                                                     this: (idParser *)v3,
                                                                                     errorFlag: nullptr);
                                                  }
                                                }
                                                else
                                                {
                                                  *(float *)(HIDWORD(v3) + 28) = idParser::ParseFloat(
                                                                                   this: (idParser *)v3,
                                                                                   errorFlag: nullptr);
                                                }
                                              }
                                              else
                                              {
                                                *(_BYTE *)(HIDWORD(v3) + 25) = idParser::ParseBool(this: (idParser *)v3);
                                              }
                                            }
                                            else
                                            {
                                              *(_BYTE *)(HIDWORD(v3) + 24) = idParser::ParseBool(this: (idParser *)v3);
                                            }
                                          }
                                          else
                                          {
                                            *(float *)(HIDWORD(v3) + 188) = idParser::ParseFloat(
                                                                              this: (idParser *)v3,
                                                                              errorFlag: nullptr);
                                            idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                            *(float *)(HIDWORD(v3) + 192) = idParser::ParseFloat(
                                                                              this: (idParser *)v3,
                                                                              errorFlag: nullptr);
                                          }
                                        }
                                        else
                                        {
                                          *(float *)(HIDWORD(v3) + 180) = idParser::ParseFloat(
                                                                            this: (idParser *)v3,
                                                                            errorFlag: nullptr);
                                          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                          *(float *)(HIDWORD(v3) + 184) = idParser::ParseFloat(
                                                                            this: (idParser *)v3,
                                                                            errorFlag: nullptr);
                                        }
                                      }
                                      else
                                      {
                                        *(float *)(HIDWORD(v3) + 172) = idParser::ParseFloat(
                                                                          this: (idParser *)v3,
                                                                          errorFlag: nullptr);
                                        idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                        *(float *)(HIDWORD(v3) + 176) = idParser::ParseFloat(
                                                                          this: (idParser *)v3,
                                                                          errorFlag: nullptr);
                                      }
                                    }
                                    else
                                    {
                                      idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                      v22 = idTypeInfoTools::FindEnumInfo(
                                              this: typeInfoTools,
                                              typeName: "fxRotationType_t");
                                      if ( v22 != nullptr )
                                      {
                                        v23 = idTypeInfoTools::FindEnumValueInfo(
                                                this: typeInfoTools,
                                                enumInfo: v22,
                                                name: v44.data,
                                                defaultIfNotFound: false);
                                        if ( v23 != nullptr )
                                          *(_DWORD *)(HIDWORD(v3) + 156) = v23->value;
                                      }
                                    }
                                  }
                                  else
                                  {
                                    idParser::ReadToken(this: (idParser *)v3, token: &v44);
                                    v20 = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxOriginType_t");
                                    if ( v20 != nullptr )
                                    {
                                      v21 = idTypeInfoTools::FindEnumValueInfo(
                                              this: typeInfoTools,
                                              enumInfo: v20,
                                              name: v44.data,
                                              defaultIfNotFound: false);
                                      if ( v21 != nullptr )
                                        *(_DWORD *)(HIDWORD(v3) + 140) = v21->value;
                                    }
                                  }
                                }
                                else
                                {
                                  *(float *)(HIDWORD(v3) + 12) = idParser::ParseFloat(
                                                                   this: (idParser *)v3,
                                                                   errorFlag: nullptr);
                                }
                              }
                              else
                              {
                                *(float *)(HIDWORD(v3) + 16) = idParser::ParseFloat(
                                                                 this: (idParser *)v3,
                                                                 errorFlag: nullptr);
                                idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
                                *(float *)(HIDWORD(v3) + 20) = idParser::ParseFloat(
                                                                 this: (idParser *)v3,
                                                                 errorFlag: nullptr);
                              }
                            }
                            else
                            {
                              while ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 )
                              {
                                v18 = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxExtraCondition_t");
                                if ( v18 != nullptr )
                                {
                                  v19 = idTypeInfoTools::FindEnumValueInfo(
                                          this: typeInfoTools,
                                          enumInfo: v18,
                                          name: v44.data,
                                          defaultIfNotFound: false);
                                  if ( v19 != nullptr )
                                  {
                                    value = (const char *)v19->value;
                                    idList<int,46>::AddUnique(
                                      this: (idList<int,5> *)(HIDWORD(v3) + 124),
                                      obj: (const int *)&value);
                                  }
                                }
                              }
                            }
                          }
                          else if ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 )
                          {
                            do
                            {
                              v15 = nullptr;
                              v16 = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxCondition_t");
                              if ( v16 != nullptr )
                              {
                                v17 = idTypeInfoTools::FindEnumValueInfo(
                                        this: typeInfoTools,
                                        enumInfo: v16,
                                        name: v44.data,
                                        defaultIfNotFound: false);
                                if ( v17 != nullptr )
                                  v15 = (const char *)v17->value;
                              }
                              value = v15;
                              idList<idAnimWebBlendTree *,5>::Append(
                                this: (idList<enum encounterGroupRole_t,5> *)(HIDWORD(v3) + 108),
                                obj: (const encounterGroupRole_t *)&value);
                            }
                            while ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 );
                            v6 = (idDeclInfo *)v43;
                            v5 = (idDeclInfo *)v39;
                          }
                        }
                        else if ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 )
                        {
                          do
                          {
                            v12 = nullptr;
                            v13 = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxCondition_t");
                            if ( v13 != nullptr )
                            {
                              v14 = idTypeInfoTools::FindEnumValueInfo(
                                      this: typeInfoTools,
                                      enumInfo: v13,
                                      name: v44.data,
                                      defaultIfNotFound: false);
                              if ( v14 != nullptr )
                                v12 = (const char *)v14->value;
                            }
                            value = v12;
                            idList<idAnimWebBlendTree *,5>::Append(
                              this: (idList<enum encounterGroupRole_t,5> *)(HIDWORD(v3) + 92),
                              obj: (const encounterGroupRole_t *)&value);
                          }
                          while ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 );
                          v6 = (idDeclInfo *)v43;
                          v5 = (idDeclInfo *)v39;
                        }
                      }
                      else if ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 )
                      {
                        do
                        {
                          data = v44.data;
                          v11 = idList<idAtomicString,32>::Alloc(this: (idList<idAtomicString,32> *)(HIDWORD(v3) + 76));
                          idAtomicString::Set(this: v11, str_: data);
                        }
                        while ( idParser::ReadTokenOnLine(this: (idParser *)v3, token: &v44) != 0 );
                        v5 = (idDeclInfo *)v39;
                      }
                    }
                    else
                    {
                      idParser::ReadToken(this: (idParser *)v3, token: &v44);
                      v8 = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxMultiTagUseType_t");
                      if ( v8 != nullptr )
                      {
                        v9 = idTypeInfoTools::FindEnumValueInfo(
                               this: typeInfoTools,
                               enumInfo: v8,
                               name: v44.data,
                               defaultIfNotFound: false);
                        if ( v9 != nullptr )
                          *(_DWORD *)(HIDWORD(v3) + 72) = v9->value;
                      }
                    }
                  }
                  else
                  {
                    idParser::ReadToken(this: (idParser *)v3, token: &v44);
                    idAtomicString::Set(this: (idAtomicString *)(HIDWORD(v3) + 68), str_: v44.data);
                  }
                }
                else
                {
                  idParser::ReadToken(this: (idParser *)v3, token: &v44);
                  idAtomicString::Set(this: (idAtomicString *)(HIDWORD(v3) + 4), str_: v44.data);
                }
              }
              else
              {
                idParser::ReadToken(this: (idParser *)v3, token: &v44);
                idAtomicString::Set(this: (idAtomicString *)HIDWORD(v3), str_: v44.data);
              }
            }
            else
            {
              *(_BYTE *)(HIDWORD(v3) + 64) = idParser::ParseBool(this: (idParser *)v3);
            }
          }
          else
          {
            *(_DWORD *)(HIDWORD(v3) + 8) = 15;
          }
        }
        else
        {
          *(_DWORD *)(HIDWORD(v3) + 8) = 7;
          *(float *)(HIDWORD(v3) + 352) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
          *(float *)(HIDWORD(v3) + 356) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
          *(float *)(HIDWORD(v3) + 360) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
          idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
          *(float *)(HIDWORD(v3) + 364) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
        }
        goto LABEL_211;
      }
      *(_DWORD *)(HIDWORD(v3) + 8) = 6;
      v7 = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      if ( v7 == 50.0 )
        break;
      if ( v7 == 150.0 )
      {
        v7 = 0.5;
      }
      else if ( v7 > 1.0 )
      {
        v7 = (float)((float)v7 * (float)0.0040000002);
        if ( v7 >= 0.0 )
        {
          if ( v7 > 1.0 )
            break;
        }
        else
        {
          v7 = 0.0;
        }
      }
LABEL_13:
      *(float *)(HIDWORD(v3) + 324) = v7;
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 40) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 328) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 332) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 336) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 340) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 344) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
      idParser::ExpectTokenString(this: (idParser *)v3, string: ",");
      *(float *)(HIDWORD(v3) + 348) = idParser::ParseFloat(this: (idParser *)v3, errorFlag: nullptr);
LABEL_211:
      if ( !idParser::ReadToken(this: (idParser *)v3, token: &v44) )
        goto LABEL_212;
    }
    v7 = 1.0;
    goto LABEL_13;
  }
LABEL_212:
  idStr::FreeData(this: &v44);
}


// ========================================================================
// __unwind$223859
// EA  : 0x8261F33C
// RVA : 0x0061F33C
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1440 + 112));
}


// ========================================================================
// __unwind$223860
// EA  : 0x8261F364
// RVA : 0x0061F364
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_223860()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1440 + 576));
}


// ========================================================================
// ?FreeData@idDeclFX@@UAAXXZ
// EA  : 0x8261F800
// RVA : 0x0061F800
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idDeclFX::FreeData(idDeclFX *this)
{
  idFXSingleAction *list; // r3
  idFXSingleAction *v3; // r3

  if ( this->editEvents.listStatic == 0 || this->editEvents.listStatic == 2 )
  {
    list = this->editEvents.list;
    if ( list != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: list, num: this->editEvents.size);
    this->editEvents.list = nullptr;
    this->editEvents.size = 0;
  }
  this->editEvents.num = 0;
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    v3 = this->events.list;
    if ( v3 != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: v3, num: this->events.size);
    this->events.list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
}


// ========================================================================
// ??0idDeclFX@@QAA@XZ
// EA  : 0x8261F968
// RVA : 0x0061F968
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

idDeclFX *__fastcall idDeclFX::idDeclFX(idDeclFX *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclFX_vtbl *)&idDeclFX::`vftable';
  this->editEvents.granularity = 0;
  this->editEvents.memTag = 109;
  this->editEvents.listStatic = 0;
  this->editEvents.list = nullptr;
  this->editEvents.size = 0;
  this->editEvents.num = 0;
  this->events.granularity = 0;
  this->events.memTag = 109;
  this->events.listStatic = 0;
  this->events.list = nullptr;
  this->events.size = 0;
  this->events.num = 0;
  this->changeId = -1;
  idDeclFX::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$225572
// EA  : 0x8261FA0C
// RVA : 0x0061FA0C
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225572()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$225573
// EA  : 0x8261FA34
// RVA : 0x0061FA34
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225573()
{
  int v0; // r12

  idList<idFXSingleAction,109>::~idList<idFXSingleAction,109>(this: (idList<idFXSingleAction,109> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$225574
// EA  : 0x8261FA60
// RVA : 0x0061FA60
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225574()
{
  int v0; // r12

  idList<idFXSingleAction,109>::~idList<idFXSingleAction,109>(this: (idList<idFXSingleAction,109> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ??1idDeclFX@@UAA@XZ
// EA  : 0x8261FAA8
// RVA : 0x0061FAA8
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idDeclFX::~idDeclFX(idDeclFX *this)
{
  idFXSingleAction *list; // r3
  idFXSingleAction *v3; // r3

  this->__vftable = (idDeclFX_vtbl *)&idDeclFX::`vftable';
  idDeclFX::FreeData(this);
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    list = this->events.list;
    if ( list != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: list, num: this->events.size);
    this->events.list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
  if ( this->editEvents.listStatic == 0 || this->editEvents.listStatic == 2 )
  {
    v3 = this->editEvents.list;
    if ( v3 != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: v3, num: this->editEvents.size);
    this->editEvents.list = nullptr;
    this->editEvents.size = 0;
  }
  this->editEvents.num = 0;
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$225632
// EA  : 0x8261FB4C
// RVA : 0x0061FB4C
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225632()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$225633
// EA  : 0x8261FB74
// RVA : 0x0061FB74
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225633()
{
  int v0; // r12

  idList<idFXSingleAction,109>::~idList<idFXSingleAction,109>(this: (idList<idFXSingleAction,109> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$225634
// EA  : 0x8261FBA0
// RVA : 0x0061FBA0
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225634()
{
  int v0; // r12

  idList<idFXSingleAction,109>::~idList<idFXSingleAction,109>(this: (idList<idFXSingleAction,109> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?Parse@idDeclFX@@UAAXAAVidParser@@@Z
// EA  : 0x8261FDB0
// RVA : 0x0061FDB0
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void __fastcall idDeclFX::Parse(idDeclFX *this, idParser *src)
{
  idList<idFXSingleAction,109> *p_editEvents; // r18
  int v5; // r27
  idList<idFXSingleAction,109> *p_events; // r22
  int changeId; // r11
  int len; // r30
  int v9; // r23
  int v10; // r25
  idFXSingleAction *v11; // r28
  idSoundShader *sound; // r3
  char v13; // r11
  __int64 v14; // r11
  idAtomicString *list; // r26
  const idAtomicString *v16; // r29
  int v17; // r30
  int i; // r28
  int v19; // r29
  int v20; // r30
  idFXSingleAction *v21; // r10
  const char *v22; // r3
  encounterGroupRole_t v23[4]; // [sp+50h] [-450h] BYREF
  idList<idAtomicString,109> v24; // [sp+60h] [-440h] BYREF
  idStr v25; // [sp+70h] [-430h] BYREF
  idToken v26; // [sp+90h] [-410h] BYREF
  __int64 v27; // [sp+D8h] [-3C8h]
  idFXSingleAction v28; // [sp+E0h] [-3C0h] BYREF

  p_editEvents = &this->editEvents;
  v5 = 0;
  if ( this->editEvents.listStatic == 0 || this->editEvents.listStatic == 2 )
  {
    if ( p_editEvents->list != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: this->editEvents.list, num: this->editEvents.size);
    p_editEvents->list = nullptr;
    p_editEvents->size = 0;
  }
  p_editEvents->num = 0;
  p_events = &this->events;
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    if ( p_events->list != nullptr )
      idListArrayDelete<idFXSingleAction>(ptr: p_events->list, num: this->events.size);
    p_events->list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
  changeId = this->changeId;
  v26.len = 0;
  v26.allocedAndFlag = 20;
  v26.data = v26.baseBuffer;
  v26.floatvalue = -3.4028235e38;
  v26.baseBuffer[0] = 0;
  v26.intvalue = 0;
  memset(&v26.whiteSpaceStart_p, 0, 12);
  this->changeId = changeId + 1;
  idParser::ReadToken(this: src, token: &v26);
  if ( idStr::Cmp(s1: v26.data, s2: FX_TEXT_VERSION_STRING) != 0 )
    idParser::UnreadToken(this: src, token: &v26);
  else
    idParser::ParseInt(this: src);
  while ( idParser::ReadToken(this: src, token: &v26) )
  {
    if ( idStr::Cmp(s1: v26.data, s2: "}") == 0 )
      break;
    v25.allocedAndFlag = 20;
    v25.len = 0;
    v25.data = v25.baseBuffer;
    v25.baseBuffer[0] = 0;
    if ( v26.type == 1 )
    {
      len = v26.len;
      if ( v26.len + 1 > 20 )
        idStr::ReAllocate(this: &v25, amount: v26.len + 1, keepold: false);
      memcpy(Dst: v25.data, Src: v26.data, Size: len);
      v25.data[len] = 0;
      v25.len = len;
      idParser::ReadToken(this: src, token: &v26);
    }
    if ( idStr::Icmp(s1: v26.data, s2: "{") == 0 )
    {
      idFXSingleAction::idFXSingleAction(this: &v28);
      idDeclFX::ParseSingleFXAction(this, src, FXAction: &v28);
      idList<idFXSingleAction,109>::Append(this: p_editEvents, obj: &v28);
      idFXSingleAction::~idFXSingleAction(this: &v28);
    }
    idStr::FreeData(this: &v25);
  }
  v9 = 0;
  if ( this->editEvents.num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = &p_editEvents->list[v10];
      if ( v11->startCondition.num == 0 )
      {
        v23[0] = ROLE_NONE;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v11->startCondition,
          obj: v23);
      }
      if ( v11->stopCondition.num == 0 )
      {
        v23[0] = ROLE_NONE;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v11->stopCondition,
          obj: v23);
      }
      if ( v11->type == FX_SOUND )
      {
        sound = v11->soundParms.sound;
        if ( sound != nullptr )
        {
          v13 = _cntlzw(idSoundShader::GetMaxLength(this: sound));
          v11->looping = (v13 & 0x20) != 0;
          if ( (v13 & 0x20) == 0 )
          {
            LODWORD(v14) = idSoundShader::GetMaxLength(this: v11->soundParms.sound);
            v27 = v14;
            v11->duration = (float)v14 * (float)0.001;
          }
          v11->soundParms.channel = v11->soundParms.sound->parms.soundChannel;
        }
      }
      idList<idFXSingleAction,109>::Append(this: &this->events, obj: v11);
      if ( v11->multiTagUseType == FX_MULTI_TAG_USE_ALL && v11->tagNames.num > 1 )
      {
        v24.list = nullptr;
        v24.listStatic = 0;
        idList<idAtomicString,109>::operator=(this: &v24, other: &v11->tagNames);
        list = v24.list;
        if ( v24.num > 1 )
        {
          v16 = v24.list + 1;
          v17 = v24.num - 1;
          do
          {
            idFXSingleAction::idFXSingleAction(this: &v28, __that: v11);
            if ( v28.tagNames.listStatic == 0 || v28.tagNames.listStatic == 2 )
            {
              if ( v28.tagNames.list != nullptr )
                idMem::Free(this: &mem, ptr: v28.tagNames.list, align: ALIGN_16);
              v28.tagNames.list = nullptr;
              v28.tagNames.size = 0;
            }
            v28.tagNames.num = 0;
            idList<idAtomicString,109>::Append(this: (idList<idAtomicString,5> *)&v28.tagNames, obj: v16);
            v28.implicit = true;
            idList<idFXSingleAction,109>::Append(this: &this->events, obj: &v28);
            idFXSingleAction::~idFXSingleAction(this: &v28);
            --v17;
            ++v16;
          }
          while ( v17 != 0 );
        }
        if ( v24.listStatic == 0 || v24.listStatic == 2 )
        {
          if ( list != nullptr )
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          v24.list = nullptr;
          v24.size = 0;
        }
        v24.num = 0;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->editEvents.num );
  }
  for ( i = 0; i < this->events.num; ++v5 )
  {
    v19 = i;
    if ( i < this->events.num )
    {
      v20 = v5 * 832;
      do
      {
        v21 = &p_events->list[v5];
        v22 = *(const char **)((char *)&p_events->list->name.str + v20);
        v23[0] = (encounterGroupRole_t)((char *)p_events->list + v20);
        if ( idStr::Icmp(s1: v22, s2: v21->fire.str) == 0 )
          *(&p_events->list->triggered + v20) = true;
        ++v19;
        v20 += 832;
      }
      while ( v19 < this->events.num );
    }
    ++i;
  }
  idStr::FreeData(this: &v26);
}


// ========================================================================
// __unwind$225713
// EA  : 0x82620220
// RVA : 0x00620220
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1184 + 144));
}


// ========================================================================
// __unwind$225714
// EA  : 0x82620248
// RVA : 0x00620248
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1184 + 112));
}


// ========================================================================
// __unwind$225715
// EA  : 0x82620270
// RVA : 0x00620270
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225715()
{
  int v0; // r12

  idFXSingleAction::~idFXSingleAction(this: (idFXSingleAction *)(v0 - 1184 + 224));
}


// ========================================================================
// __unwind$225716
// EA  : 0x82620298
// RVA : 0x00620298
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225716()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1184 + 96));
}


// ========================================================================
// __unwind$225717
// EA  : 0x826202C0
// RVA : 0x006202C0
// PDB : w:\tech5\engine\decls\declfx.cpp
// ========================================================================

void _unwind_225717()
{
  int v0; // r12

  idFXSingleAction::~idFXSingleAction(this: (idFXSingleAction *)(v0 - 1184 + 224));
}

