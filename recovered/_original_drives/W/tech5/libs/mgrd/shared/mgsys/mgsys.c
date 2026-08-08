
// ========================================================================
// mgthread_create
// EA  : 0x83233718
// RVA : 0x01233718
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgsys.c
// ========================================================================

int __fastcall mgthread_create(MGTHREAD *thread, unsigned int (__fastcall *func)(void *), void *param)
{
  void *v4; // r3

  v4 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: func,
         lpParameter: param,
         dwCreationFlags: 0,
         lpThreadId: nullptr);
  *(_DWORD *)thread->data = v4;
  return (v4 != nullptr) - 1;
}


// ========================================================================
// mgthread_sleep
// EA  : 0x83233768
// RVA : 0x01233768
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgsys.c
// ========================================================================

// attributes: thunk
void __fastcall mgthread_sleep(unsigned int ms)
{
  Sleep(dwMilliseconds: ms);
}


// ========================================================================
// mgthread_getid
// EA  : 0x83233770
// RVA : 0x01233770
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgsys.c
// ========================================================================

// attributes: thunk
unsigned int __fastcall mgthread_getid(int a1)
{
  return GetCurrentThreadId();
}


// ========================================================================
// mgtimestamp_now
// EA  : 0x83233778
// RVA : 0x01233778
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgsys.c
// ========================================================================

unsigned int mgtimestamp_now()
{
  _LARGE_INTEGER v1; // [sp+50h] [-10h] BYREF

  QueryPerformanceCounter(lpPerformanceCount: &v1);
  return v1.LowPart;
}


// ========================================================================
// mgtimestamp_frequency
// EA  : 0x832337A0
// RVA : 0x012337A0
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgsys.c
// ========================================================================

unsigned int mgtimestamp_frequency()
{
  _LARGE_INTEGER v1; // [sp+50h] [-10h] BYREF

  QueryPerformanceFrequency(lpFrequency: &v1);
  return v1.LowPart;
}

