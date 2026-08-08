
// ========================================================================
// ?GetChar@eventQueue_t@@QAADXZ
// EA  : 0x829EA4E8
// RVA : 0x009EA4E8
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

int __fastcall eventQueue_t::GetChar(eventQueue_t *this)
{
  int last; // r10
  int result; // r3
  bool v4; // zf

  last = this->last;
  v4 = this->curr != (last + 1000) % 1000;
  result = 0;
  if ( v4 )
  {
    result = (unsigned __int8)this->data[last];
    this->last = (last + 1) % 1000;
  }
  return result;
}


// ========================================================================
// ?SetName@idRegressionLocal@@UAAXPBD@Z
// EA  : 0x829EB960
// RVA : 0x009EB960
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

void __fastcall idRegressionLocal::SetName(idRegressionLocal *this, const char *string)
{
  idStr::operator=(this: &this->regressionName, text: string);
}


// ========================================================================
// ?SetTestInProgress@idRegressionLocal@@UAAX_N@Z
// EA  : 0x829EB968
// RVA : 0x009EB968
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

void __fastcall idRegressionLocal::SetTestInProgress(idRegressionLocal *this, bool inProgress)
{
  this->testInProgress = inProgress;
}


// ========================================================================
// ?GetTestInProgress@idRegressionLocal@@UBA_NXZ
// EA  : 0x829EB970
// RVA : 0x009EB970
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

BOOL __fastcall idRegressionLocal::GetTestInProgress(idRegressionLocal *this)
{
  return this->testInProgress;
}


// ========================================================================
// ?SetForceIgnoreNextTestCommands@idRegressionLocal@@EAAX_N@Z
// EA  : 0x829EB978
// RVA : 0x009EB978
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

void __fastcall idRegressionLocal::SetForceIgnoreNextTestCommands(idRegressionLocal *this, bool ignoreNextTest_)
{
  this->ignoreNextTest = ignoreNextTest_;
}


// ========================================================================
// ?GetTestReport@idRegressionLocal@@UAAPAVidTestReport@@XZ
// EA  : 0x829EB980
// RVA : 0x009EB980
// PDB : w:\tech5\engine\test\regressionlocal.h
// ========================================================================

idTestReport *__fastcall idRegressionLocal::GetTestReport(idRegressionLocal *this)
{
  return this->testReports.list[this->currentTestReport];
}

