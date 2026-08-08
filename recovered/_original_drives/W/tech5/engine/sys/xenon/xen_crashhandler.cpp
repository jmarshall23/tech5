
// ========================================================================
// ?SetCrashHandler@idCrashHandler@@QAAXP6AJPAU_EXCEPTION_POINTERS@@@Z@Z
// EA  : 0x829D1610
// RVA : 0x009D1610
// PDB : w:\tech5\engine\sys\xenon\xen_crashhandler.cpp
// ========================================================================

void __fastcall idCrashHandler::SetCrashHandler(
        idCrashHandler *this,
        int (__fastcall *newHandler)(_EXCEPTION_POINTERS *))
{
  int (__fastcall *originalHandler)(_EXCEPTION_POINTERS *); // r3
  int (__fastcall *v4)(_EXCEPTION_POINTERS *); // r3

  if ( newHandler != nullptr )
  {
    v4 = SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: newHandler);
    if ( this->originalHandler == nullptr )
      this->originalHandler = v4;
  }
  else
  {
    originalHandler = this->originalHandler;
    if ( originalHandler != nullptr )
    {
      SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: originalHandler);
      this->originalHandler = nullptr;
    }
  }
}


// ========================================================================
// ??1idCrashHandler@@QAA@XZ
// EA  : 0x829D1688
// RVA : 0x009D1688
// PDB : w:\tech5\engine\sys\xenon\xen_crashhandler.cpp
// ========================================================================

void __fastcall idCrashHandler::~idCrashHandler(idCrashHandler *this)
{
  int (__fastcall *originalHandler)(_EXCEPTION_POINTERS *); // r3

  originalHandler = this->originalHandler;
  if ( originalHandler != nullptr )
  {
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: originalHandler);
    this->originalHandler = nullptr;
  }
}


// ========================================================================
// ?idUnhandledExceptionFilterProc@idCrashHandler@@SAJPAU_EXCEPTION_POINTERS@@@Z
// EA  : 0x829D16C8
// RVA : 0x009D16C8
// PDB : w:\tech5\engine\sys\xenon\xen_crashhandler.cpp
// ========================================================================

int __fastcall idCrashHandler::idUnhandledExceptionFilterProc(_EXCEPTION_POINTERS *pExPtrs)
{
  idCrashHandler *crashHandler; // r31
  int (__fastcall *originalHandler)(_EXCEPTION_POINTERS *); // r3

  if ( com_enableCrashHandler.valueInteger != 0 )
  {
    idLib::Printf(fmt: "CrashHandler: Writing Hansoft report.\n");
    idHansoftReport::Write360Report(this: &hansoftReport, pExPtrs_: (unsigned int **)pExPtrs);
  }
  else
  {
    idLib::Printf(fmt: "CrashHandler: Aborting, as com_enableCrashHandler is not set.\n");
    crashHandler = xen.crashHandler;
    originalHandler = xen.crashHandler->originalHandler;
    if ( originalHandler != nullptr )
    {
      SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: originalHandler);
      crashHandler->originalHandler = nullptr;
    }
  }
  return 0;
}


// ========================================================================
// ??0idCrashHandler@@QAA@XZ
// EA  : 0x829D1758
// RVA : 0x009D1758
// PDB : w:\tech5\engine\sys\xenon\xen_crashhandler.cpp
// ========================================================================

idCrashHandler *__fastcall idCrashHandler::idCrashHandler(idCrashHandler *this)
{
  this->originalHandler = nullptr;
  idCrashHandler::SetCrashHandler(this, newHandler: idCrashHandler::idUnhandledExceptionFilterProc);
  return this;
}


// ========================================================================
// `dynamic initializer for 'com_enableCrashHandler''
// EA  : 0x83363B18
// RVA : 0x01363B18
// PDB : w:\tech5\engine\sys\xenon\xen_crashhandler.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_enableCrashHandler__()
{
  idCVar::idCVar(
    this: &com_enableCrashHandler,
    name: "com_enableCrashHandler",
    value: "1",
    flags: 1,
    description: "enable the crash exception handler",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_enableCrashHandler__);
}

