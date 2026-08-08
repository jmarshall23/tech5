
// ========================================================================
// `dynamic initializer for 'gamedate''
// EA  : 0x833810C0
// RVA : 0x013810C0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gamedate__()
{
  idCVar::idCVar(
    this: &gamedate,
    name: "gamedate",
    value: "Aug 29 2012",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gamedate__);
}


// ========================================================================
// `dynamic initializer for 'g_bloodEffects''
// EA  : 0x83381118
// RVA : 0x01381118
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_bloodEffects__()
{
  idCVar::idCVar(
    this: &g_bloodEffects,
    name: "g_bloodEffects",
    value: "1",
    flags: 1,
    description: "show blood splats, sprays and gibs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_bloodEffects__);
}


// ========================================================================
// `dynamic initializer for 'view_damageBlur''
// EA  : 0x83381170
// RVA : 0x01381170
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damageBlur__()
{
  idCVar::idCVar(
    this: &view_damageBlur,
    name: "view_damageBlur",
    value: "1",
    flags: 1,
    description: "show blur when taking damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damageBlur__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVision''
// EA  : 0x833811C8
// RVA : 0x013811C8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVision__()
{
  idCVar::idCVar(
    this: &view_doubleVision,
    name: "view_doubleVision",
    value: "1",
    flags: 1,
    description: "show double vision when taking damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVision__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponkick''
// EA  : 0x83381220
// RVA : 0x01381220
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponkick__()
{
  idCVar::idCVar(
    this: &g_weaponkick,
    name: "g_weaponkick",
    value: "1",
    flags: 1,
    description: "apply first person weapon kick",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponkick__);
}


// ========================================================================
// `dynamic initializer for 'g_knockback''
// EA  : 0x83381278
// RVA : 0x01381278
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_knockback__()
{
  idCVar::idCVar(
    this: &g_knockback,
    name: "g_knockback",
    value: "50",
    flags: 2,
    description: "control how much the player gets knocked back when damaged",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_knockback__);
}


// ========================================================================
// `dynamic initializer for 'g_gameDifficulty''
// EA  : 0x833812D0
// RVA : 0x013812D0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_gameDifficulty__()
{
  idCVar::idCVar(
    this: &g_gameDifficulty,
    name: "g_gameDifficulty",
    value: "-1",
    flags: 2,
    description: "the difficulty setting for the game, if -1 will not use the cvar but the var in gameLocal currentGameDifficulty ( 0 "
    "is easy and 3 is nightmare )",
    valueMin: -1.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_gameDifficulty__);
}


// ========================================================================
// `dynamic initializer for 'g_gravity''
// EA  : 0x83381338
// RVA : 0x01381338
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_gravity__()
{
  idCVar::idCVar(
    this: &g_gravity,
    name: "g_gravity",
    value: "1066",
    flags: 4,
    description: "control the force of gravity on physics objects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_gravity__);
}


// ========================================================================
// `dynamic initializer for 'g_damageSave''
// EA  : 0x83381390
// RVA : 0x01381390
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageSave__()
{
  idCVar::idCVar(
    this: &g_damageSave,
    name: "g_damageSave",
    value: "0",
    flags: 1,
    description: "reduces damage taken based on percentage of health vs maxhealth",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageSave__);
}


// ========================================================================
// `dynamic initializer for 'g_ignoreSaveGame''
// EA  : 0x833813E8
// RVA : 0x013813E8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_ignoreSaveGame__()
{
  idCVar::idCVar(
    this: &g_ignoreSaveGame,
    name: "g_ignoreSaveGame",
    value: "0",
    flags: 1,
    description: "disables all savegames from triggers and useables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_ignoreSaveGame__);
}


// ========================================================================
// `dynamic initializer for 'g_useGaussianWeaponSpread''
// EA  : 0x83381440
// RVA : 0x01381440
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_useGaussianWeaponSpread__()
{
  idCVar::idCVar(
    this: &g_useGaussianWeaponSpread,
    name: "g_useGaussianAimSpread",
    value: "1",
    flags: 1,
    description: "Player weapons use approximated gaussian spread (0 uses uniform linear spread)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_useGaussianWeaponSpread__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponSpreadScale''
// EA  : 0x83381498
// RVA : 0x01381498
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponSpreadScale__()
{
  idCVar::idCVar(
    this: &g_weaponSpreadScale,
    name: "g_weaponSpreadScale",
    value: "1.0",
    flags: 4,
    description: "Global player weapon spread scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponSpreadScale__);
}


// ========================================================================
// `dynamic initializer for 'g_disasm''
// EA  : 0x833814F0
// RVA : 0x013814F0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_disasm__()
{
  idCVar::idCVar(
    this: &g_disasm,
    name: "g_disasm",
    value: "0",
    flags: 1,
    description: "disassemble script into base/script/disasm.txt on the local drive when script is compiled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_disasm__);
}


// ========================================================================
// `dynamic initializer for 'g_debugAnim''
// EA  : 0x83381548
// RVA : 0x01381548
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugAnim__()
{
  idCVar::idCVar(
    this: &g_debugAnim,
    name: "g_debugAnim",
    value: "-1",
    flags: 2,
    description: "displays information on which animations are playing on the specified entity number.  set to -1 to disable.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugAnim__);
}


// ========================================================================
// `dynamic initializer for 'g_debugMove''
// EA  : 0x833815A0
// RVA : 0x013815A0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMove__()
{
  idCVar::idCVar(
    this: &g_debugMove,
    name: "g_debugMove",
    value: "0",
    flags: 1,
    description: "print debug information about player movement (sets idPhysics_Player::debugLevel)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMove__);
}


// ========================================================================
// `dynamic initializer for 'g_debugDamage''
// EA  : 0x833815F8
// RVA : 0x013815F8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugDamage__()
{
  idCVar::idCVar(
    this: &g_debugDamage,
    name: "g_debugDamage",
    value: "0",
    flags: 1,
    description: "print debug information about damage taken (armor / health / location)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugDamage__);
}


// ========================================================================
// `dynamic initializer for 'g_debugWeapon''
// EA  : 0x83381650
// RVA : 0x01381650
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugWeapon__()
{
  idCVar::idCVar(
    this: &g_debugWeapon,
    name: "g_debugWeapon",
    value: "0",
    flags: 1,
    description: "print debug information about weapon states, also draws lines when monsters are alerted and shows melee range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugWeapon__);
}


// ========================================================================
// `dynamic initializer for 'g_debugImpactEffect''
// EA  : 0x833816A8
// RVA : 0x013816A8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugImpactEffect__()
{
  idCVar::idCVar(
    this: &g_debugImpactEffect,
    name: "g_debugImpactEffect",
    value: "0",
    flags: 1,
    description: "print debug information about projectile impact effects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugImpactEffect__);
}


// ========================================================================
// `dynamic initializer for 'g_debugFootStepEffect''
// EA  : 0x83381700
// RVA : 0x01381700
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugFootStepEffect__()
{
  idCVar::idCVar(
    this: &g_debugFootStepEffect,
    name: "g_debugFootStepEffect",
    value: "0",
    flags: 1,
    description: "print debug information about footstep impact effects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugFootStepEffect__);
}


// ========================================================================
// `dynamic initializer for 'g_debugScript''
// EA  : 0x83381758
// RVA : 0x01381758
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugScript__()
{
  idCVar::idCVar(
    this: &g_debugScript,
    name: "g_debugScript",
    value: "0",
    flags: 1,
    description: "print debug information about threads being created and destroyed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugScript__);
}


// ========================================================================
// `dynamic initializer for 'g_debugMover''
// EA  : 0x833817B0
// RVA : 0x013817B0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMover__()
{
  idCVar::idCVar(
    this: &g_debugMover,
    name: "g_debugMover",
    value: "0",
    flags: 1,
    description: "print debug information about movers moving",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMover__);
}


// ========================================================================
// `dynamic initializer for 'g_debugTriggers''
// EA  : 0x83381808
// RVA : 0x01381808
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugTriggers__()
{
  idCVar::idCVar(
    this: &g_debugTriggers,
    name: "g_debugTriggers",
    value: "0",
    flags: 1,
    description: "print 'x activated by y' when a trigger activates something",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugTriggers__);
}


// ========================================================================
// `dynamic initializer for 'g_debugCounts''
// EA  : 0x83381860
// RVA : 0x01381860
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugCounts__()
{
  idCVar::idCVar(
    this: &g_debugCounts,
    name: "g_debugCounts",
    value: "0",
    flags: 1,
    description: "print debug information about entity counts and calls to expensive functions",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugCounts__);
}


// ========================================================================
// `dynamic initializer for 'g_showSpread''
// EA  : 0x833818B8
// RVA : 0x013818B8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showSpread__()
{
  idCVar::idCVar(
    this: &g_showSpread,
    name: "g_showSpread",
    value: "0",
    flags: 2,
    description: "draws a debug circle to show the spread on the weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showSpread__);
}


// ========================================================================
// `dynamic initializer for 'g_spread_returnDelay''
// EA  : 0x83381910
// RVA : 0x01381910
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spread_returnDelay__()
{
  idCVar::idCVar(
    this: &g_spread_returnDelay,
    name: "g_spread_returnDelay",
    value: "100",
    flags: 4,
    description: "(Doom4) How long before the weapon spread starts to return to 0 after firing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spread_returnDelay__);
}


// ========================================================================
// `dynamic initializer for 'g_spread_returnTime''
// EA  : 0x83381968
// RVA : 0x01381968
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spread_returnTime__()
{
  idCVar::idCVar(
    this: &g_spread_returnTime,
    name: "g_spread_returnTime",
    value: "250",
    flags: 4,
    description: "(Doom4) How long it takes for the weapon spread to return to 0 after firing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spread_returnTime__);
}


// ========================================================================
// `dynamic initializer for 'g_debugLayers''
// EA  : 0x833819C0
// RVA : 0x013819C0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugLayers__()
{
  idCVar::idCVar(
    this: &g_debugLayers,
    name: "g_debugLayers",
    value: "0",
    flags: 2,
    description: "print information about layer changes during play",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugLayers__);
}


// ========================================================================
// `dynamic initializer for 'g_stopTime''
// EA  : 0x83381A18
// RVA : 0x01381A18
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_stopTime__()
{
  idCVar::idCVar(
    this: &g_stopTime,
    name: "g_stopTime",
    value: "0",
    flags: 1,
    description: "stops all entity updating, but the player can still run around",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_stopTime__);
}


// ========================================================================
// `dynamic initializer for 'g_runFrames''
// EA  : 0x83381A70
// RVA : 0x01381A70
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_runFrames__()
{
  idCVar::idCVar(
    this: &g_runFrames,
    name: "g_runFrames",
    value: "0",
    flags: 2,
    description: "you can set g_runFrames while g_stopTime is set to have the game run that many frames, then stop again",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_runFrames__);
}


// ========================================================================
// `dynamic initializer for 'g_damageScale''
// EA  : 0x83381AC8
// RVA : 0x01381AC8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageScale__()
{
  idCVar::idCVar(
    this: &g_damageScale,
    name: "g_damageScale",
    value: "1",
    flags: 4,
    description: "scale final damage on player by this factor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageScale__);
}


// ========================================================================
// `dynamic initializer for 'g_showTargets''
// EA  : 0x83381B20
// RVA : 0x01381B20
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showTargets__()
{
  idCVar::idCVar(
    this: &g_showTargets,
    name: "g_showTargets",
    value: "0",
    flags: 1,
    description: "draws entities and their targets.  hidden entities are drawn gray.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showTargets__);
}


// ========================================================================
// `dynamic initializer for 'g_showTriggers''
// EA  : 0x83381B78
// RVA : 0x01381B78
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showTriggers__()
{
  idCVar::idCVar(
    this: &g_showTriggers,
    name: "g_showTriggers",
    value: "0",
    flags: 1,
    description: "draws trigger entities (orange) and thier targets (green).  disabled triggers are drawn grey.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showTriggers__);
}


// ========================================================================
// `dynamic initializer for 'g_showDoorBounds''
// EA  : 0x83381BD0
// RVA : 0x01381BD0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showDoorBounds__()
{
  idCVar::idCVar(
    this: &g_showDoorBounds,
    name: "g_showDoorBounds",
    value: "0",
    flags: 1,
    description: "draws door bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showDoorBounds__);
}


// ========================================================================
// `dynamic initializer for 'g_showStatics''
// EA  : 0x83381C28
// RVA : 0x01381C28
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showStatics__()
{
  idCVar::idCVar(
    this: &g_showStatics,
    name: "g_showStatics",
    value: "0",
    flags: 1,
    description: "draws boxes around func/static entities.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showStatics__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionWorld''
// EA  : 0x83381C80
// RVA : 0x01381C80
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionWorld__()
{
  idCVar::idCVar(
    this: &g_showCollisionWorld,
    name: "g_showCollisionWorld",
    value: "0",
    flags: 1,
    description: "draws the collision geometry for the world (bsp geometry)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionWorld__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionModels''
// EA  : 0x83381CD8
// RVA : 0x01381CD8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionModels__()
{
  idCVar::idCVar(
    this: &g_showCollisionModels,
    name: "g_showCollisionModels",
    value: "0",
    flags: 2,
    description: "draws the collision geometry for models",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionModels__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionTraces''
// EA  : 0x83381D40
// RVA : 0x01381D40
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionTraces__()
{
  idCVar::idCVar(
    this: &g_showCollisionTraces,
    name: "g_showCollisionTraces",
    value: "0",
    flags: 1,
    description: "print statistics from the collision system every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionTraces__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionDistance''
// EA  : 0x83381D98
// RVA : 0x01381D98
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionDistance__()
{
  idCVar::idCVar(
    this: &g_showCollisionDistance,
    name: "g_showCollisionDistance",
    value: "256",
    flags: 4,
    description: "maximum distance collision geometry will draw when g_showCollisionWorld or g_showCollisionModels is used",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionDistance__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionSubModels''
// EA  : 0x83381DF0
// RVA : 0x01381DF0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionSubModels__()
{
  idCVar::idCVar(
    this: &g_showCollisionSubModels,
    name: "g_showCollisionSubModels",
    value: "0",
    flags: 1,
    description: "show complete sub models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionSubModels__);
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionSurfaces''
// EA  : 0x83381E48
// RVA : 0x01381E48
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionSurfaces__()
{
  idCVar::idCVar(
    this: &g_showCollisionSurfaces,
    name: "g_showCollisionSurfaces",
    value: "0",
    flags: 2,
    description: "show collision surface info, 1 = for all content types, 2 = for only content shotclip",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'g_showEntityInfo''
// EA  : 0x83381EA0
// RVA : 0x01381EA0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEntityInfo__()
{
  idCVar::idCVar(
    this: &g_showEntityInfo,
    name: "g_showEntityInfo",
    value: "0",
    flags: 1,
    description: "draws boxes around all entities.  cyan for actors, orange for triggers, green for solid, grey for everything else.  "
    "also prints the entity name and number in the box",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEntityInfo__);
}


// ========================================================================
// `dynamic initializer for 'g_playerHealthRegenDelay''
// EA  : 0x83381EF8
// RVA : 0x01381EF8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerHealthRegenDelay__()
{
  idCVar::idCVar(
    this: &g_playerHealthRegenDelay,
    name: "g_playerHealthRegenDelay",
    value: "3",
    flags: 4,
    description: "seconds we wait after last damage to give health back to player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerHealthRegenDelay__);
}


// ========================================================================
// `dynamic initializer for 'g_playerHealthRegenSteps''
// EA  : 0x83381F50
// RVA : 0x01381F50
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerHealthRegenSteps__()
{
  idCVar::idCVar(
    this: &g_playerHealthRegenSteps,
    name: "g_playerHealthRegenSteps",
    value: "20",
    flags: 4,
    description: "in what intervals the players health regens",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerHealthRegenSteps__);
}


// ========================================================================
// `dynamic initializer for 'g_playerHealthRegenSpeed''
// EA  : 0x83381FA8
// RVA : 0x01381FA8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerHealthRegenSpeed__()
{
  idCVar::idCVar(
    this: &g_playerHealthRegenSpeed,
    name: "g_playerHealthRegenSpeed",
    value: "3",
    flags: 4,
    description: "what speed the player health regenerates in. hp/s",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerHealthRegenSpeed__);
}


// ========================================================================
// `dynamic initializer for 'g_playerHealthDecaySpeed''
// EA  : 0x83382000
// RVA : 0x01382000
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerHealthDecaySpeed__()
{
  idCVar::idCVar(
    this: &g_playerHealthDecaySpeed,
    name: "g_playerHealthDecaySpeed",
    value: "2",
    flags: 4,
    description: "what speed the player health decays in. hp/s",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerHealthDecaySpeed__);
}


// ========================================================================
// `dynamic initializer for 'g_showCloth''
// EA  : 0x83382058
// RVA : 0x01382058
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCloth__()
{
  idCVar::idCVar(
    this: &g_showCloth,
    name: "g_showCloth",
    value: "0",
    flags: 2,
    description: "shows cloth springs and points. 1 = show points, 2 = show springs, 3 = show collisions, 4 = show all",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCloth__);
}


// ========================================================================
// `dynamic initializer for 'g_skipCloth''
// EA  : 0x833820B0
// RVA : 0x013820B0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_skipCloth__()
{
  idCVar::idCVar(
    this: &g_skipCloth,
    name: "g_skipCloth",
    value: "0",
    flags: 2,
    description: "skips cloth simulation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_skipCloth__);
}


// ========================================================================
// `dynamic initializer for 'g_timeentities''
// EA  : 0x83382108
// RVA : 0x01382108
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_timeentities__()
{
  idCVar::idCVar(
    this: &g_timeentities,
    name: "g_timeEntities",
    value: "0",
    flags: 4,
    description: "when non-zero, shows entities whose think functions exceeded the # of milliseconds specified",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_timeentities__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugScript''
// EA  : 0x83382160
// RVA : 0x01382160
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugScript__()
{
  idCVar::idCVar(
    this: &ai_debugScript,
    name: "ai_debugScript",
    value: "-1",
    flags: 2,
    description: "displays script calls for the specified monster entity number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugScript__);
}


// ========================================================================
// `dynamic initializer for 'ai_showObstacleAvoidance''
// EA  : 0x833821B8
// RVA : 0x013821B8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &ai_showObstacleAvoidance,
    name: "ai_showObstacleAvoidance",
    value: "0",
    flags: 2,
    description: "draws obstacle avoidance information. 2,4 = draw obstacles for player, 3,4 = top-down view",
    valueMin: 0.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"WriteBoundedFloatBase",
    a9: (int)&loc_82B40000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,4>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugCam''
// EA  : 0x83382220
// RVA : 0x01382220
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugCam__()
{
  idCVar::idCVar(
    this: &ai_debugCam,
    name: "ai_debugCam",
    value: "0",
    flags: 1,
    description: "enable debug camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugCam__);
}


// ========================================================================
// `dynamic initializer for 'g_freeCam''
// EA  : 0x83382278
// RVA : 0x01382278
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_freeCam__()
{
  idCVar::idCVar(
    this: &g_freeCam,
    name: "g_freeCam",
    value: "0",
    flags: 2,
    description: "enable debug camera (free move) 0 = disable/normal, 1 = enable, 2 = lock camera completely)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_freeCam__);
}


// ========================================================================
// `dynamic initializer for 'g_kickTime''
// EA  : 0x833822D0
// RVA : 0x013822D0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_kickTime__()
{
  idCVar::idCVar(
    this: &g_kickTime,
    name: "g_kickTime",
    value: "1",
    flags: 4,
    description: "scale how long a damage kick to the view angles lasts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_kickTime__);
}


// ========================================================================
// `dynamic initializer for 'g_kickAmplitude''
// EA  : 0x83382328
// RVA : 0x01382328
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_kickAmplitude__()
{
  idCVar::idCVar(
    this: &g_kickAmplitude,
    name: "g_kickAmplitude",
    value: "1",
    flags: 4,
    description: "scale how far a damage kick to the view angles moves",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_kickAmplitude__);
}


// ========================================================================
// `dynamic initializer for 'g_editEntityMode''
// EA  : 0x83382380
// RVA : 0x01382380
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_editEntityMode__()
{
  idCVar::idCVar(
    this: &g_editEntityMode,
    name: "g_editEntityMode",
    value: "0",
    flags: 2,
    description: "0 = off\n"
    "1 = lights\n"
    "2 = sounds\n"
    "3 = articulated figures\n"
    "4 = particle systems\n"
    "5 = monsters\n"
    "6 = entity names\n"
    "7 = entity models\n"
    "8 = fx\n"
    "9 = entity properties",
    valueMin: 0.0,
    valueMax: 9.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"WriteBoundedFloatBase",
    a9: (int)&loc_82D70000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,9>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_editEntityMode__);
}


// ========================================================================
// `dynamic initializer for 'g_editEntityGridSize''
// EA  : 0x833823E8
// RVA : 0x013823E8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_editEntityGridSize__()
{
  idCVar::idCVar(
    this: &g_editEntityGridSize,
    name: "g_editEntityGridSize",
    value: "0",
    flags: 2,
    description: "snap to grid for entity dragging, default = 0",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_editEntityGridSize__);
}


// ========================================================================
// `dynamic initializer for 'g_editEntityCloneDist''
// EA  : 0x83382440
// RVA : 0x01382440
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_editEntityCloneDist__()
{
  idCVar::idCVar(
    this: &g_editEntityCloneDist,
    name: "g_editEntityCloneDist",
    value: "128",
    flags: 4,
    description: "how far from the camera the newly cloned entity is placed, default = 128",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_editEntityCloneDist__);
}


// ========================================================================
// `dynamic initializer for 'g_editEntityMouseDrag''
// EA  : 0x83382498
// RVA : 0x01382498
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_editEntityMouseDrag__()
{
  idCVar::idCVar(
    this: &g_editEntityMouseDrag,
    name: "g_editEntityMouseDrag",
    value: "0",
    flags: 2,
    description: "0 = use bound keys + LMB to drag entity around, 1 = use LMB + drag to move entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_editEntityMouseDrag__);
}


// ========================================================================
// `dynamic initializer for 'g_showLightEntities''
// EA  : 0x833824F0
// RVA : 0x013824F0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showLightEntities__()
{
  idCVar::idCVar(
    this: &g_showLightEntities,
    name: "g_showLightEntities",
    value: "0",
    flags: 1,
    description: "includes light entities when editing sounds ( g_editEntityMode == 2 )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showLightEntities__);
}


// ========================================================================
// `dynamic initializer for 'g_showEditEntityInfo''
// EA  : 0x83382548
// RVA : 0x01382548
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEditEntityInfo__()
{
  idCVar::idCVar(
    this: &g_showEditEntityInfo,
    name: "g_showEditEntityInfo",
    value: "0",
    flags: 1,
    description: "draws debug info when editing entities with g_editEntityMode > 0",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEditEntityInfo__);
}


// ========================================================================
// `dynamic initializer for 'g_showEditEntityDistance''
// EA  : 0x833825A0
// RVA : 0x013825A0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEditEntityDistance__()
{
  idCVar::idCVar(
    this: &g_showEditEntityDistance,
    name: "g_showEditEntityDistance",
    value: "512",
    flags: 2,
    description: "set the distance at which the edit entities show up (default=512)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEditEntityDistance__);
}


// ========================================================================
// `dynamic initializer for 'g_showEditLayerNames''
// EA  : 0x833825F8
// RVA : 0x013825F8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEditLayerNames__()
{
  idCVar::idCVar(
    this: &g_showEditLayerNames,
    name: "g_showEditLayerNames",
    value: "0",
    flags: 1,
    description: "draws the layer names when g_editEntityMode is enabled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEditLayerNames__);
}


// ========================================================================
// `dynamic initializer for 'g_showEditEntityLocalAxes''
// EA  : 0x83382650
// RVA : 0x01382650
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEditEntityLocalAxes__()
{
  idCVar::idCVar(
    this: &g_showEditEntityLocalAxes,
    name: "g_showEditEntityLocalAxes",
    value: "0",
    flags: 1,
    description: "draws the local axes of the selected entity instead of world axes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEditEntityLocalAxes__);
}


// ========================================================================
// `dynamic initializer for 'g_showEditEntityDepthTested''
// EA  : 0x833826A8
// RVA : 0x013826A8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEditEntityDepthTested__()
{
  idCVar::idCVar(
    this: &g_showEditEntityDepthTested,
    name: "g_showEditEntityDepthTested",
    value: "0",
    flags: 1,
    description: "draws the debug bounds in edit mode with depth testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEditEntityDepthTested__);
}


// ========================================================================
// `dynamic initializer for 'g_dragEntity''
// EA  : 0x83382700
// RVA : 0x01382700
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_dragEntity__()
{
  idCVar::idCVar(
    this: &g_dragEntity,
    name: "g_dragEntity",
    value: "0",
    flags: 1,
    description: "allows dragging physics objects around by placing the crosshair over them and holding the fire button",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_dragEntity__);
}


// ========================================================================
// `dynamic initializer for 'g_dragDamping''
// EA  : 0x83382758
// RVA : 0x01382758
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_dragDamping__()
{
  idCVar::idCVar(
    this: &g_dragDamping,
    name: "g_dragDamping",
    value: "0.5",
    flags: 4,
    description: "set the damping force for g_dragEntity (0 makes object 'snap' to the cursor, 1 makes it more springy)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_dragDamping__);
}


// ========================================================================
// `dynamic initializer for 'g_dragShowSelection''
// EA  : 0x833827B0
// RVA : 0x013827B0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_dragShowSelection__()
{
  idCVar::idCVar(
    this: &g_dragShowSelection,
    name: "g_dragShowSelection",
    value: "0",
    flags: 1,
    description: "draw the bounding box of the selected entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_dragShowSelection__);
}


// ========================================================================
// `dynamic initializer for 'pm_jumpheight''
// EA  : 0x83382808
// RVA : 0x01382808
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_jumpheight__()
{
  idCVar::idCVar(
    this: &pm_jumpheight,
    name: "pm_jumpheight",
    value: "60",
    flags: 4,
    description: "approximate hieght the player can jump",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_jumpheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_stepsize''
// EA  : 0x83382860
// RVA : 0x01382860
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_stepsize__()
{
  idCVar::idCVar(
    this: &pm_stepsize,
    name: "pm_stepsize",
    value: "16",
    flags: 4,
    description: "maximum height the player can step up without jumping",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_stepsize__);
}


// ========================================================================
// `dynamic initializer for 'pm_crouchspeed''
// EA  : 0x833828B8
// RVA : 0x013828B8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_crouchspeed__()
{
  idCVar::idCVar(
    this: &pm_crouchspeed,
    name: "pm_crouchspeed",
    value: "160",
    flags: 4,
    description: "speed the player can move while crouched",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_crouchspeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_walkspeed''
// EA  : 0x83382910
// RVA : 0x01382910
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_walkspeed__()
{
  idCVar::idCVar(
    this: &pm_walkspeed,
    name: "pm_walkspeed",
    value: "160",
    flags: 4,
    description: "speed the player can move while walking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_walkspeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_runspeed''
// EA  : 0x83382968
// RVA : 0x01382968
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_runspeed__()
{
  idCVar::idCVar(
    this: &pm_runspeed,
    name: "pm_runspeed",
    value: "280",
    flags: 4,
    description: "speed the player can move while running",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_runspeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintspeed''
// EA  : 0x833829C0
// RVA : 0x013829C0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintspeed__()
{
  idCVar::idCVar(
    this: &pm_sprintspeed,
    name: "pm_sprintspeed",
    value: "450",
    flags: 4,
    description: "speed the player can move while sprinting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintspeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_backSpeedRatio''
// EA  : 0x83382A18
// RVA : 0x01382A18
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_backSpeedRatio__()
{
  idCVar::idCVar(
    this: &pm_backSpeedRatio,
    name: "pm_backSpeedRatio",
    value: "0.75",
    flags: 4,
    description: "ratio of player max backward speed to forward speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_backSpeedRatio__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintBackSpeedRatio''
// EA  : 0x83382A70
// RVA : 0x01382A70
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintBackSpeedRatio__()
{
  idCVar::idCVar(
    this: &pm_sprintBackSpeedRatio,
    name: "pm_sprintBackSpeedRatio",
    value: "0.50",
    flags: 4,
    description: "ratio of player max sprint backward speed to forward speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintBackSpeedRatio__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintMaxTime''
// EA  : 0x83382AC8
// RVA : 0x01382AC8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintMaxTime__()
{
  idCVar::idCVar(
    this: &pm_sprintMaxTime,
    name: "pm_sprintMaxTime",
    value: "3500",
    flags: 4,
    description: "how many ms the player can sprint",
    valueMin: 1.0,
    valueMax: 1.0e30,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_82200000,
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintMaxTime__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintChargeTime''
// EA  : 0x83382B30
// RVA : 0x01382B30
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintChargeTime__()
{
  idCVar::idCVar(
    this: &pm_sprintChargeTime,
    name: "pm_sprintChargeTime",
    value: "5000",
    flags: 4,
    description: "how many ms to fully recharge sprint",
    valueMin: 1.0,
    valueMax: 1.0e30,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"DE_LEFT",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintChargeTime__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintScaleOutsideInstance''
// EA  : 0x83382B98
// RVA : 0x01382B98
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintScaleOutsideInstance__()
{
  idCVar::idCVar(
    this: &pm_sprintScaleOutsideInstance,
    name: "pm_sprintScaleOutsideInstance",
    value: "4",
    flags: 4,
    description: "how much longer you can sprint when your not in an instance",
    valueMin: 1.0,
    valueMax: 1.0e30,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintScaleOutsideInstance__);
}


// ========================================================================
// `dynamic initializer for 'pm_togglesprint''
// EA  : 0x83382C00
// RVA : 0x01382C00
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_togglesprint__()
{
  idCVar::idCVar(
    this: &pm_togglesprint,
    name: "pm_togglesprint",
    value: "0",
    flags: 1,
    description: "if true will use the toggle sprint on PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_togglesprint__);
}


// ========================================================================
// `dynamic initializer for 'pm_walkthreshold''
// EA  : 0x83382C58
// RVA : 0x01382C58
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_walkthreshold__()
{
  idCVar::idCVar(
    this: &pm_walkthreshold,
    name: "pm_walkthreshold",
    value: "100",
    flags: 2,
    description: "user command threshold where we transition from walking / sneaking to running.",
    valueMin: 0.0,
    valueMax: 127.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_walkthreshold__);
}


// ========================================================================
// `dynamic initializer for 'pm_noclipspeed''
// EA  : 0x83382CC0
// RVA : 0x01382CC0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_noclipspeed__()
{
  idCVar::idCVar(
    this: &pm_noclipspeed,
    name: "pm_noclipspeed",
    value: "400",
    flags: 4,
    description: "speed the player can move while in noclip",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_noclipspeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_minviewpitch''
// EA  : 0x83382D18
// RVA : 0x01382D18
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_minviewpitch__()
{
  idCVar::idCVar(
    this: &pm_minviewpitch,
    name: "pm_minviewpitch",
    value: "-89",
    flags: 4,
    description: "amount player's view can look up (negative values are up)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_minviewpitch__);
}


// ========================================================================
// `dynamic initializer for 'pm_maxviewpitch''
// EA  : 0x83382D70
// RVA : 0x01382D70
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_maxviewpitch__()
{
  idCVar::idCVar(
    this: &pm_maxviewpitch,
    name: "pm_maxviewpitch",
    value: "89",
    flags: 4,
    description: "amount player's view can look down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_maxviewpitch__);
}


// ========================================================================
// `dynamic initializer for 'pm_crouchviewheight''
// EA  : 0x83382DC8
// RVA : 0x01382DC8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_crouchviewheight__()
{
  idCVar::idCVar(
    this: &pm_crouchviewheight,
    name: "pm_crouchviewheight",
    value: "46",
    flags: 4,
    description: "height of player's view while crouched",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_crouchviewheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_normalviewheight''
// EA  : 0x83382E20
// RVA : 0x01382E20
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_normalviewheight__()
{
  idCVar::idCVar(
    this: &pm_normalviewheight,
    name: "pm_normalviewheight",
    value: "87",
    flags: 4,
    description: "height of player's view while standing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_normalviewheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPersonRange''
// EA  : 0x83382E78
// RVA : 0x01382E78
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPersonRange__()
{
  idCVar::idCVar(
    this: &pm_thirdPersonRange,
    name: "pm_thirdPersonRange",
    value: "140",
    flags: 4,
    description: "camera distance from player in 3rd person",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPersonRange__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPersonHeight''
// EA  : 0x83382ED0
// RVA : 0x01382ED0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPersonHeight__()
{
  idCVar::idCVar(
    this: &pm_thirdPersonHeight,
    name: "pm_thirdPersonHeight",
    value: "0",
    flags: 4,
    description: "height of camera from normal view height in 3rd person",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPersonHeight__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPersonAngle''
// EA  : 0x83382F28
// RVA : 0x01382F28
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPersonAngle__()
{
  idCVar::idCVar(
    this: &pm_thirdPersonAngle,
    name: "pm_thirdPersonAngle",
    value: "0",
    flags: 4,
    description: "direction of camera from player in 3rd person in degrees (0 = behind player, 180 = in front)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPersonAngle__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPersonFocusJoint''
// EA  : 0x83382F80
// RVA : 0x01382F80
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPersonFocusJoint__()
{
  idCVar::idCVar(
    this: &pm_thirdPersonFocusJoint,
    name: "pm_thirdPersonFocusJoint",
    value: "head",
    flags: 0,
    description: "focus joint of the third person camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPersonFocusJoint__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPersonClip''
// EA  : 0x83382FD8
// RVA : 0x01382FD8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPersonClip__()
{
  idCVar::idCVar(
    this: &pm_thirdPersonClip,
    name: "pm_thirdPersonClip",
    value: "1",
    flags: 1,
    description: "clip third person view into world space",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPersonClip__);
}


// ========================================================================
// `dynamic initializer for 'pm_thirdPerson''
// EA  : 0x83383030
// RVA : 0x01383030
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_thirdPerson__()
{
  idCVar::idCVar(
    this: &pm_thirdPerson,
    name: "pm_thirdPerson",
    value: "0",
    flags: 1,
    description: "enables third person view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_thirdPerson__);
}


// ========================================================================
// `dynamic initializer for 'pm_vehicleFreeCam''
// EA  : 0x83383088
// RVA : 0x01383088
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_vehicleFreeCam__()
{
  idCVar::idCVar(
    this: &pm_vehicleFreeCam,
    name: "pm_vehicleFreeCam",
    value: "0",
    flags: 1,
    description: "set to true for a free vehicle camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_vehicleFreeCam__);
}


// ========================================================================
// `dynamic initializer for 'pm_fatalFallDist''
// EA  : 0x833830E0
// RVA : 0x013830E0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_fatalFallDist__()
{
  idCVar::idCVar(
    this: &pm_fatalFallDist,
    name: "pm_fatalFallDist",
    value: "384",
    flags: 4,
    description: "falling any distance greater than this will kill the player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_fatalFallDist__);
}


// ========================================================================
// `dynamic initializer for 'pm_minFallDist''
// EA  : 0x83383138
// RVA : 0x01383138
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_minFallDist__()
{
  idCVar::idCVar(
    this: &pm_minFallDist,
    name: "pm_minFallDist",
    value: "45",
    flags: 4,
    description: "falls any distance less than this are ignored",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_minFallDist__);
}


// ========================================================================
// `dynamic initializer for 'pm_noBob''
// EA  : 0x83383190
// RVA : 0x01383190
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_noBob__()
{
  idCVar::idCVar(
    this: &pm_noBob,
    name: "pm_noBob",
    value: "0",
    flags: 1,
    description: "turns off view bob and weapon sway",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_noBob__);
}


// ========================================================================
// `dynamic initializer for 'pm_doom4BobCycle''
// EA  : 0x833831E8
// RVA : 0x013831E8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_doom4BobCycle__()
{
  idCVar::idCVar(
    this: &pm_doom4BobCycle,
    name: "pm_doom4BobCycle",
    value: "0",
    flags: 1,
    description: "use the Doom4 additive animated bob cycle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_doom4BobCycle__);
}


// ========================================================================
// `dynamic initializer for 'g_showPlayerShadow''
// EA  : 0x83383240
// RVA : 0x01383240
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showPlayerShadow__()
{
  idCVar::idCVar(
    this: &g_showPlayerShadow,
    name: "g_showPlayerShadow",
    value: "0",
    flags: 1,
    description: "enables shadow of player model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showPlayerShadow__);
}


// ========================================================================
// `dynamic initializer for 'g_showHud''
// EA  : 0x83383298
// RVA : 0x01383298
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showHud__()
{
  idCVar::idCVar(
    this: &g_showHud,
    name: "g_showHud",
    value: "1",
    flags: 1,
    description: "enables drawing of HUD elements",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showHud__);
}


// ========================================================================
// `dynamic initializer for 'g_showPlayerInfo''
// EA  : 0x833832F0
// RVA : 0x013832F0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showPlayerInfo__()
{
  idCVar::idCVar(
    this: &g_showPlayerInfo,
    name: "g_showPlayerInfo",
    value: "1",
    flags: 1,
    description: "enables drawing of Player Information elements in the HUD (e.g. name and health).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showPlayerInfo__);
}


// ========================================================================
// `dynamic initializer for 'g_showAllPlayerInfo''
// EA  : 0x83383348
// RVA : 0x01383348
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showAllPlayerInfo__()
{
  idCVar::idCVar(
    this: &g_showAllPlayerInfo,
    name: "g_showAllPlayerInfo",
    value: "0",
    flags: 1,
    description: "shows player information for All players.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showAllPlayerInfo__);
}


// ========================================================================
// `dynamic initializer for 'g_showPoiInfo''
// EA  : 0x833833A0
// RVA : 0x013833A0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showPoiInfo__()
{
  idCVar::idCVar(
    this: &g_showPoiInfo,
    name: "g_showPoiInfo",
    value: "1",
    flags: 1,
    description: "enables drawing of Poi Information elements in the HUD (e.g. leader, base, flag).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showPoiInfo__);
}


// ========================================================================
// `dynamic initializer for 'g_showGuis''
// EA  : 0x833833F8
// RVA : 0x013833F8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showGuis__()
{
  idCVar::idCVar(
    this: &g_showGuis,
    name: "g_showGuis",
    value: "1",
    flags: 1,
    description: "enables drawing of GUI elements other then HUD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showGuis__);
}


// ========================================================================
// `dynamic initializer for 'g_viewNodalX''
// EA  : 0x83383450
// RVA : 0x01383450
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_viewNodalX__()
{
  idCVar::idCVar(
    this: &g_viewNodalX,
    name: "g_viewNodalX",
    value: "0",
    flags: 4,
    description: "eye distance from the neck in the x direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_viewNodalX__);
}


// ========================================================================
// `dynamic initializer for 'g_viewNodalZ''
// EA  : 0x833834A8
// RVA : 0x013834A8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_viewNodalZ__()
{
  idCVar::idCVar(
    this: &g_viewNodalZ,
    name: "g_viewNodalZ",
    value: "0",
    flags: 4,
    description: "eye distance from the neck in the z direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_viewNodalZ__);
}


// ========================================================================
// `dynamic initializer for 'g_fov''
// EA  : 0x83383500
// RVA : 0x01383500
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_fov__()
{
  idCVar::idCVar(
    this: &g_fov,
    name: "g_fov",
    value: "80",
    flags: 18,
    description: "camera field of view",
    valueMin: 10.0,
    valueMax: 120.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_fov__);
}


// ========================================================================
// `dynamic initializer for 'g_skipViewEffects''
// EA  : 0x83383568
// RVA : 0x01383568
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_skipViewEffects__()
{
  idCVar::idCVar(
    this: &g_skipViewEffects,
    name: "g_skipViewEffects",
    value: "0",
    flags: 1,
    description: "skip damage and other view effects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_skipViewEffects__);
}


// ========================================================================
// `dynamic initializer for 'g_testPostProcess''
// EA  : 0x833835C0
// RVA : 0x013835C0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testPostProcess__()
{
  idCVar::idCVar(
    this: &g_testPostProcess,
    name: "g_testPostProcess",
    value: &byte_8200D768,
    flags: 0,
    description: "name of material to draw over screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testPostProcess__);
}


// ========================================================================
// `dynamic initializer for 'g_testDeath''
// EA  : 0x83383618
// RVA : 0x01383618
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testDeath__()
{
  idCVar::idCVar(
    this: &g_testDeath,
    name: "g_testDeath",
    value: "0",
    flags: 1,
    description: "disable fading and respawning when you die so you can see what happens when you die",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testDeath__);
}


// ========================================================================
// `dynamic initializer for 'aas_subdivisionSize''
// EA  : 0x83383670
// RVA : 0x01383670
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_subdivisionSize__()
{
  idCVar::idCVar(
    this: &aas_subdivisionSize,
    name: "aas_subdivisionSize",
    value: "64",
    flags: 2,
    description: "the size of subdivisions to use for debug drawing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_subdivisionSize__);
}


// ========================================================================
// `dynamic initializer for 'g_drawBob''
// EA  : 0x833836C8
// RVA : 0x013836C8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawBob__()
{
  idCVar::idCVar(
    this: &g_drawBob,
    name: "g_drawBob",
    value: "0",
    flags: 2,
    description: "draw a graph of view bob ( angle and offset )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawBob__);
}


// ========================================================================
// `dynamic initializer for 'g_drawSway''
// EA  : 0x83383720
// RVA : 0x01383720
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawSway__()
{
  idCVar::idCVar(
    this: &g_drawSway,
    name: "g_drawSway",
    value: "0",
    flags: 1,
    description: "draw a graph of hands sway",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawSway__);
}


// ========================================================================
// `dynamic initializer for 'g_drawCrouch''
// EA  : 0x83383778
// RVA : 0x01383778
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawCrouch__()
{
  idCVar::idCVar(
    this: &g_drawCrouch,
    name: "g_drawCrouch",
    value: "0",
    flags: 1,
    description: "draw a graph of crouch correction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawCrouch__);
}


// ========================================================================
// `dynamic initializer for 'g_AimAssist_Disable_All''
// EA  : 0x833837D0
// RVA : 0x013837D0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_AimAssist_Disable_All__()
{
  idCVar::idCVar(
    this: &g_AimAssist_Disable_All,
    name: "g_AimAssist_Disable_All",
    value: "0",
    flags: 1,
    description: "disable all the aim assist code (killburst, zooming, shooting) ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_AimAssist_Disable_All__);
}


// ========================================================================
// `dynamic initializer for 'g_AimAssist_Disable_Shooting''
// EA  : 0x83383828
// RVA : 0x01383828
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_AimAssist_Disable_Shooting__()
{
  idCVar::idCVar(
    this: &g_AimAssist_Disable_Shooting,
    name: "g_AimAssist_Disable_Shooting",
    value: "0",
    flags: 1,
    description: "disable the aim assist code for shooting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_AimAssist_Disable_Shooting__);
}


// ========================================================================
// `dynamic initializer for 'g_AimAssist_Disable_Adhesion''
// EA  : 0x83383880
// RVA : 0x01383880
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_AimAssist_Disable_Adhesion__()
{
  idCVar::idCVar(
    this: &g_AimAssist_Disable_Adhesion,
    name: "g_AimAssist_Disable_Adhesion",
    value: "0",
    flags: 1,
    description: "disable the aim assist code for adhesion",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_AimAssist_Disable_Adhesion__);
}


// ========================================================================
// `dynamic initializer for 'g_AimAssist_Adhesion_While_Still''
// EA  : 0x833838D8
// RVA : 0x013838D8
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_AimAssist_Adhesion_While_Still__()
{
  idCVar::idCVar(
    this: &g_AimAssist_Adhesion_While_Still,
    name: "g_AimAssist_Adhesion_While_Still",
    value: "0",
    flags: 1,
    description: "Enables Target Adhesion While Standing Still",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_AimAssist_Adhesion_While_Still__);
}


// ========================================================================
// `dynamic initializer for 'jobDebug_ShowHidden''
// EA  : 0x83383930
// RVA : 0x01383930
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobDebug_ShowHidden__()
{
  idCVar::idCVar(
    this: &jobDebug_ShowHidden,
    name: "jobDebug_ShowHidden",
    value: "0",
    flags: 1,
    description: "show hidden jobs in the job list",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobDebug_ShowHidden__);
}


// ========================================================================
// `dynamic initializer for 'job_alwaysShow''
// EA  : 0x83383988
// RVA : 0x01383988
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__job_alwaysShow__()
{
  idCVar::idCVar(
    this: &job_alwaysShow,
    name: "job_alwaysShow",
    value: "0",
    flags: 1,
    description: "if true always keep a job note up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__job_alwaysShow__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnMPEnemyAI''
// EA  : 0x833839E0
// RVA : 0x013839E0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnMPEnemyAI__()
{
  idCVar::idCVar(
    this: &g_spawnMPEnemyAI,
    name: "g_spawnMPEnemyAI",
    value: "0",
    flags: 2,
    description: "1 = any AI spawned in with the 'spawnMP' command, are made enemies of the player, for debugging MP AI. 2 = Same as 1"
    ", but AI spawns randomly in the map, and is removed after its first attack. 3 = Same as 2, but not removed after attacking.",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnMPEnemyAI__);
}


// ========================================================================
// `dynamic initializer for 'bot_minClients''
// EA  : 0x83383A48
// RVA : 0x01383A48
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_minClients__()
{
  idCVar::idCVar(
    this: &bot_minClients,
    name: "bot_minClients",
    value: "-1",
    flags: 2,
    description: "Keep a minimum number of clients on the server with bots and humans. -1 to disable. 0 = remove any bots on server. >"
    " 1 = Num clients to always keep in game.",
    valueMin: -1.0,
    valueMax: 6.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_minClients__);
}


// ========================================================================
// `dynamic initializer for 'g_showCrosshairInfo''
// EA  : 0x83383AB0
// RVA : 0x01383AB0
// PDB : w:\tech5\tungsten\game\gamesys\syscvar.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCrosshairInfo__()
{
  idCVar::idCVar(
    this: &g_showCrosshairInfo,
    name: "g_showCrosshairInfo",
    value: "0",
    flags: 2,
    description: "1 = Show dist to entity we have our crosshair over. 2 = Show dist to whatever colliding surface we have our crosshair over.",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"WriteBoundedFloatBase",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCrosshairInfo__);
}

