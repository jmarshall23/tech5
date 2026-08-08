
// ========================================================================
// ??0idScopedConsoleTimeRange@@QAA@W4rangeId_t@@ABVidColor@@@Z
// EA  : 0x82651338
// RVA : 0x00651338
// PDB : w:\tech5\engine\framework\console.h
// ========================================================================

idScopedConsoleTimeRange *__fastcall idScopedConsoleTimeRange::idScopedConsoleTimeRange(
        idScopedConsoleTimeRange *this,
        __int32 id_,
        const idColor *color)
{
  ((void (__fastcall *)(idScopedConsoleTimeRange *))console->GetTimeRangeColor)(a1: this);
  this->id = id_;
  console->BeginTimeRange(this: console, a2: (const rangeId_t)id_, a3: color);
  return this;
}


// ========================================================================
// ??1idScopedConsoleTimeRange@@QAA@XZ
// EA  : 0x82651398
// RVA : 0x00651398
// PDB : w:\tech5\engine\framework\console.h
// ========================================================================

void __fastcall idScopedConsoleTimeRange::~idScopedConsoleTimeRange(idScopedConsoleTimeRange *this)
{
  console->BeginTimeRange(this: console, a2: this->id, a3: (const idColor *)this);
}


// ========================================================================
// ??1idConsole@@UAA@XZ
// EA  : 0x82663C80
// RVA : 0x00663C80
// PDB : w:\tech5\engine\framework\console.h
// ========================================================================

void __fastcall idConsole::~idConsole(idConsole *this)
{
  this->__vftable = (idConsole_vtbl *)&idConsole::`vftable';
}

