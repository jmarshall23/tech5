
// ========================================================================
// ??0idVersionInfo@@QAA@XZ
// EA  : 0x82642400
// RVA : 0x00642400
// PDB : w:\tech5\engine\framework\buildversion.cpp
// ========================================================================

idVersionInfo *__fastcall idVersionInfo::idVersionInfo(idVersionInfo *this)
{
  const char *v3; // [sp+8h] [-88h]
  const char *v4; // [sp+Ch] [-84h]
  const char *v5; // [sp+10h] [-80h]
  const char *v6; // [sp+14h] [-7Ch]

  idStr::snPrintf(
    dest: this->fullVersion,
    size: 128,
    fmt: "%s.%d.%d%s %s %s %s %s %s",
    "Tungsten",
    1683,
    2952,
    &byte_8200D768,
    "xbox360",
    v3,
    v4,
    v5,
    v6);
  idStr::snPrintf(dest: this->netVersion, size: 128, fmt: "%s.%d.%d%s", "Tungsten", 1683, 2952, &byte_8200D768);
  return this;
}


// ========================================================================
// `dynamic initializer for 'versionInfo''
// EA  : 0x83337768
// RVA : 0x01337768
// PDB : w:\tech5\engine\framework\buildversion.cpp
// ========================================================================

idVersionInfo *_dynamic_initializer_for__versionInfo__()
{
  return idVersionInfo::idVersionInfo(this: &versionInfo);
}


// ========================================================================
// `dynamic initializer for 'com_version''
// EA  : 0x83337778
// RVA : 0x01337778
// PDB : w:\tech5\engine\framework\buildversion.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_version__()
{
  idCVar::idCVar(
    this: &com_version,
    name: "com_version",
    value: versionInfo.fullVersion,
    flags: 0,
    description: "engine version",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_version__);
}


// ========================================================================
// `dynamic initializer for 'net_version''
// EA  : 0x833377D0
// RVA : 0x013377D0
// PDB : w:\tech5\engine\framework\buildversion.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_version__()
{
  idCVar::idCVar(
    this: &net_version,
    name: "net_version",
    value: versionInfo.netVersion,
    flags: 0,
    description: "network version",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_version__);
}

