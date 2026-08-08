
// ========================================================================
// `dynamic initializer for 'com_filterWarnings''
// EA  : 0x833954D0
// RVA : 0x013954D0
// PDB : w:\tech5\shared\idlib\filter\warningsfilter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_filterWarnings__()
{
  idCVar::idCVar(
    this: &com_filterWarnings,
    name: "com_filterWarnings",
    value: "1",
    flags: 1,
    description: "Enable warnings filter system.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_filterWarnings__);
}


// ========================================================================
// `dynamic initializer for 'warningsFilter''
// EA  : 0x83395528
// RVA : 0x01395528
// PDB : w:\tech5\shared\idlib\filter\warningsfilter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__warningsFilter__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__warningsFilter__);
}

